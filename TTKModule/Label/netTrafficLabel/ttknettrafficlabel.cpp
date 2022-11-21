#include "ttknettrafficlabel.h"

#include <QFile>
#include <QProcess>
#include <QApplication>
#ifdef Q_OS_WIN
#  ifdef Q_CC_MINGW
#    include <winsock2.h>
#  endif
#  include <qt_windows.h>
#  include <cstdio>
#  include <iphlpapi.h>
#elif defined Q_OS_UNIX
#  include <ifaddrs.h>
#  include <arpa/inet.h>
#endif

#define KB (1024)
#define MB (1024 * 1024)
#define GB (1024 * 1024 * 1024)

#define TEMP_FILE_NAME  "net_temp"

TTKNetTraffic::TTKNetTraffic(QObject *parent)
    : QThread(parent),
      m_run(true),
      m_process(nullptr)
{
#ifdef Q_OS_UNIX
    QFile openFile(":/net/res_traffic");
    if(openFile.open(QIODevice::ReadOnly))
    {
        QFile file(TEMP_FILE_NAME);
        if(file.open(QIODevice::WriteOnly))
        {
            file.write(openFile.readAll());
            file.close();
            QProcess::execute(QString("chmod +x ") + TEMP_FILE_NAME);
        }
        openFile.close();
    }
#endif
}

TTKNetTraffic::~TTKNetTraffic()
{
    QFile::remove(TEMP_FILE_NAME);
    stopAndQuitThread();
    if(m_process)
    {
        m_process->kill();
    }
    delete m_process;
}

void TTKNetTraffic::setAvailableNewtworkName(const QString &name)
{
    m_name = name;
#ifdef Q_OS_UNIX
    if(m_name.isEmpty())
    {
        return;
    }

    delete m_process;
    m_process = new QProcess(this);
    m_process->setProcessChannelMode(QProcess::MergedChannels);
    connect(m_process, SIGNAL(readyReadStandardOutput()), SLOT(outputRecieved()));
    QStringList arguments;
    arguments << name << "1";
    m_process->start(qApp->applicationDirPath() + TTK_SEPARATOR + TEMP_FILE_NAME, arguments);
#endif
}

QStringList TTKNetTraffic::newtworkNames() const
{
    QStringList names;
#ifdef Q_OS_WIN
    PMIB_IFTABLE pTable = nullptr;
    DWORD dwAdapters = 0;
    ULONG uRetCode = GetIfTable(pTable, &dwAdapters, TRUE);
    if(uRetCode == ERROR_NOT_SUPPORTED)
    {
        return names;
    }

    if(uRetCode == ERROR_INSUFFICIENT_BUFFER)
    {
        pTable = (PMIB_IFTABLE)new BYTE[65535];
    }

    GetIfTable(pTable, &dwAdapters, TRUE);
    for(UINT i = 0; i < pTable->dwNumEntries; ++i)
    {
        const MIB_IFROW Row = pTable->table[i];
        TTKString s(TTKReinterpret_cast(char const*, Row.bDescr));
        const QString &qs = QString::fromStdString(s);
        if((Row.dwType == 71 || Row.dwType == 6) && !names.contains(qs))
        {
            names << qs;
        }
    }
    delete[] pTable;
#elif defined Q_OS_UNIX
    struct ifaddrs *ifa = nullptr, *ifList;
    if(getifaddrs(&ifList) < 0)
    {
        return QStringList();
    }

    for(ifa = ifList; ifa != nullptr; ifa = ifa->ifa_next)
    {
        if(ifa->ifa_addr->sa_family == AF_INET)
        {
            names << QString(ifa->ifa_name);
        }
    }
    freeifaddrs(ifList);
#endif
    return names;
}

void TTKNetTraffic::stopAndQuitThread()
{
    if(isRunning())
    {
        m_run = false;
        wait();
    }
    quit();
}

void TTKNetTraffic::start()
{
    m_run = true;
    QThread::start();
}

void TTKNetTraffic::outputRecieved()
{
#ifdef Q_OS_UNIX
    while(m_process->canReadLine())
    {
        const QByteArray &datas = m_process->readLine();
        const QStringList &list = QString(datas).split("|");
        ulong upload = 0, download = 0;

        if(list.count() == 3)
        {
            download= list[1].trimmed().toULong();
            upload  = list[2].trimmed().toULong();
        }
        Q_EMIT networkData(upload, download);
    }
#endif
}

void TTKNetTraffic::run()
{
#ifdef Q_OS_WIN
    PMIB_IFTABLE pTable = nullptr;
    DWORD dwAdapters = 0;
    const ULONG uRetCode = GetIfTable(pTable, &dwAdapters, TRUE);

    if(uRetCode == ERROR_NOT_SUPPORTED)
    {
        return;
    }

    if(uRetCode == ERROR_INSUFFICIENT_BUFFER)
    {
        pTable = (PMIB_IFTABLE)new BYTE[65535];
    }

    DWORD dwLastIn = 0, dwLastOut = 0;
    DWORD dwBandIn = 0, dwBandOut = 0;

    while(m_run)
    {
        GetIfTable(pTable, &dwAdapters, TRUE);
        DWORD dwInOctets = 0, dwOutOctets = 0;

        for(UINT i = 0; i < pTable->dwNumEntries; ++i)
        {
            const MIB_IFROW& Row = pTable->table[i];
            const TTKString s(TTKReinterpret_cast(char const*, Row.bDescr));
            if((Row.dwType == 71 || Row.dwType == 6) && m_name == QString::fromStdString(s))
            {
                dwInOctets += Row.dwInOctets;
                dwOutOctets += Row.dwOutOctets;
            }
        }

        dwBandIn = dwInOctets - dwLastIn;
        dwBandOut = dwOutOctets - dwLastOut;

        if(dwLastIn <= 0)
        {
            dwBandIn = 0;
        }

        if(dwLastOut <= 0)
        {
            dwBandOut = 0;
        }

        dwLastIn = dwInOctets;
        dwLastOut = dwOutOctets;

        Q_EMIT networkData(dwBandOut, dwBandIn);
        sleep(1);
    }
    delete[] pTable;
#endif
}



TTKNetTrafficLabel::TTKNetTrafficLabel(QWidget *parent)
    : QLabel(parent)
{
    m_process = new TTKNetTraffic(this);
    connect(m_process, SIGNAL(networkData(ulong,ulong)), SLOT(setData(ulong,ulong)));

    m_process->setAvailableNewtworkName("wlp2s0");
}

TTKNetTrafficLabel::~TTKNetTrafficLabel()
{
    delete m_process;
}

void TTKNetTrafficLabel::setAvailableNewtworkName(const QString &name)
{
    m_process->setAvailableNewtworkName(name);
}

QStringList TTKNetTrafficLabel::newtworkNames() const
{
    return m_process->newtworkNames();
}

QSize TTKNetTrafficLabel::sizeHint() const
{
    return QSize(300, 30);
}

QString TTKNetTrafficLabel::size2Number(ulong size)
{
    if(size < KB)
    {
        return QString::number(size*1.0, 'f', 2) + "KB";
    }
    else if(KB <= size && size < MB)
    {
        return QString::number(size*1.0/KB, 'f', 2) + "MB";
    }
    else if(MB <= size && size < GB)
    {
        return QString::number(size*1.0/MB, 'f', 2) + "GB";
    }
    else
    {
        return QString("0KB");
    }
}

void TTKNetTrafficLabel::setData(ulong upload, ulong download)
{
    const QString &msg = QString("↑ %1, ↓ %2").arg(size2Number(upload)).arg(size2Number(download));
    setText(msg);
}
