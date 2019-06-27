#include "ttkcpumemorylabel.h"

#include <QTimer>
#include <QProcess>

#ifdef Q_OS_WIN
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x502
#endif
#include "windows.h"
#endif
#define MB (1024 * 1024)
#define KB (1024)

TTKCPUMemoryLabel::TTKCPUMemoryLabel(QWidget *parent)
    : QLabel(parent)
{
    m_totalNew = m_idleNew = m_totalOld = m_idleOld = 0;
    m_cpuPercent = 0;

    m_memoryPercent = 0;
    m_memoryAll = 0;
    m_memoryUse = 0;

    m_timerCPU = new QTimer(this);
    connect(m_timerCPU, SIGNAL(timeout()), this, SLOT(getCPU()));

    m_timerMemory = new QTimer(this);
    connect(m_timerMemory, SIGNAL(timeout()), this, SLOT(getMemory()));

    m_process = new QProcess(this);
    connect(m_process, SIGNAL(readyRead()), this, SLOT(readData()));
}

TTKCPUMemoryLabel::~TTKCPUMemoryLabel()
{
    stop();
}

QSize TTKCPUMemoryLabel::sizeHint() const
{
    return QSize(300, 30);
}

void TTKCPUMemoryLabel::start(int interval)
{
    getCPU();
    getMemory();
    m_timerCPU->start(interval);
    m_timerMemory->start(interval + 200);
}

void TTKCPUMemoryLabel::stop()
{
    m_timerCPU->stop();
    m_timerMemory->stop();
}

void TTKCPUMemoryLabel::getCPU()
{
#ifdef Q_OS_WIN
    static FILETIME preidleTime;
    static FILETIME prekernelTime;
    static FILETIME preuserTime;

    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    GetSystemTimes(&idleTime, &kernelTime, &userTime);

    quint64 a, b;
    int idle, kernel, user;

    a = (preidleTime.dwHighDateTime << 31) | preidleTime.dwLowDateTime;
    b = (idleTime.dwHighDateTime << 31) | idleTime.dwLowDateTime;
    idle = b - a;

    a = (prekernelTime.dwHighDateTime << 31) | prekernelTime.dwLowDateTime;
    b = (kernelTime.dwHighDateTime << 31) | kernelTime.dwLowDateTime;
    kernel = b - a;

    a = (preuserTime.dwHighDateTime << 31) | preuserTime.dwLowDateTime;
    b = (userTime.dwHighDateTime << 31) | userTime.dwLowDateTime;
    user = b - a;

    m_cpuPercent = (kernel + user - idle) * 100 / (kernel + user);

    preidleTime = idleTime;
    prekernelTime = kernelTime;
    preuserTime = userTime ;

    setData();
#else

    if(m_process->state() == QProcess::NotRunning)
    {
        m_totalNew = m_idleNew = 0;
        m_process->start("cat /proc/stat");
    }

#endif
}

void TTKCPUMemoryLabel::getMemory()
{
#ifdef Q_OS_WIN
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    m_memoryPercent = statex.dwMemoryLoad;
    m_memoryAll = statex.ullTotalPhys / MB;
    m_memoryFree = statex.ullAvailPhys / MB;
    m_memoryUse = m_memoryAll - m_memoryFree;

    setData();
#else

    if(m_process->state() == QProcess::NotRunning)
    {
        m_process->start("cat /proc/meminfo");
    }

#endif
}

void TTKCPUMemoryLabel::readData()
{
    while(!m_process->atEnd())
    {
        QString s = QLatin1String(m_process->readLine());
        if(s.startsWith("cpu"))
        {
            QStringList list = s.split(" ");
            m_idleNew = list.at(5).toInt();

            foreach(const QString &value, list)
            {
                m_totalNew += value.toInt();
            }

            int total = m_totalNew - m_totalOld;
            int idle = m_idleNew - m_idleOld;
            m_cpuPercent = 100 * (total - idle) / total;
            m_totalOld = m_totalNew;
            m_idleOld = m_idleNew;
            break;
        }
        else if(s.startsWith("MemTotal"))
        {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_memoryAll = s.left(s.length() - 3).toInt() / KB;
        }
        else if(s.startsWith("MemFree"))
        {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_memoryFree = s.left(s.length() - 3).toInt() / KB;
        }
        else if(s.startsWith("Buffers"))
        {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_memoryFree += s.left(s.length() - 3).toInt() / KB;
        }
        else if(s.startsWith("Cached"))
        {
            s = s.replace(" ", "");
            s = s.split(":").at(1);
            m_memoryFree += s.left(s.length() - 3).toInt() / KB;
            m_memoryUse = m_memoryAll - m_memoryFree;
            m_memoryPercent = 100 * m_memoryUse / m_memoryAll;
            break;
        }
    }

    setData();
}

void TTKCPUMemoryLabel::setData()
{
    m_cpuPercent = (m_cpuPercent < 0 ? 0 : m_cpuPercent);

    const QString &msg = QString("CPU %1%  Mem %2% ( Used %3 MB / ALL %4 MB )")
                         .arg(m_cpuPercent).arg(m_memoryPercent).arg(m_memoryUse).arg(m_memoryAll);
    setText(msg);
}
