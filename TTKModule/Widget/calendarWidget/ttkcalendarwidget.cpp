#include "ttkcalendarwidget.h"

#include <QLocale>
#include <QPainter>
#include <QBoxLayout>
#include <QProxyStyle>
#include <QTextCharFormat>

class TTK_CORE_EXPORT TTKCustomStyle : public QProxyStyle
{
public:
    TTKCustomStyle(QWidget *parent)
    {
        setParent(parent);
    }

private:
    virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const override
    {
        if(element == PE_FrameFocusRect)
        {
            return;
        }
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

TTKCalendarWidget::TTKCalendarWidget(QWidget *parent)
    : QCalendarWidget(parent)
{
    initControl();
}

QSize TTKCalendarWidget::sizeHint() const
{
    return QSize(440, 275);
}

void TTKCalendarWidget::buttonClicked()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>(sender());
    if(senderButton == m_leftYearButton)
    {
        showPreviousYear();
    }
    else if(senderButton == m_leftMonthButton)
    {
        showPreviousMonth();
    }
    else if(senderButton == m_rightYearButton)
    {
        showNextYear();
    }
    else if(senderButton == m_rightMonthButton)
    {
        showNextMonth();
    }
}

void TTKCalendarWidget::setDataLabelTimeText(int year, int month)
{
    m_dataLabel->setText(QString("%1.%2").arg(year).arg(month));
}

void TTKCalendarWidget::initControl()
{
    setFixedSize(sizeHint() - QSize(10, 10));
    setLocale(QLocale(QLocale::Chinese));
    setNavigationBarVisible(false);
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    setStyle(new TTKCustomStyle(this));

    QTextCharFormat format;
    format.setForeground(QColor(160, 160, 160));
    format.setBackground(QColor(255, 255, 255));

    setHeaderTextFormat(format);
    setWeekdayTextFormat(Qt::Saturday, format);
    setWeekdayTextFormat(Qt::Sunday,   format);
    setWeekdayTextFormat(Qt::Monday,   format);
    setWeekdayTextFormat(Qt::Tuesday,  format);
    setWeekdayTextFormat(Qt::Wednesday,format);
    setWeekdayTextFormat(Qt::Thursday, format);
    setWeekdayTextFormat(Qt::Friday,   format);

    initTopWidget();
    initBottomWidget();

    connect(this, SIGNAL(currentPageChanged(int,int)), SLOT(setDataLabelTimeText(int,int)));
}

void TTKCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    if(date == selectedDate())
    {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(0, 145, 255));

        painter->drawRoundedRect(rect.x(), rect.y() + 3, rect.width(), rect.height() - 6, 3, 3);
        painter->setPen(QColor(255, 255, 255));

        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
        painter->restore();
    }
    else if(date == QDate::currentDate())
    {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(0, 161, 255));
        painter->drawRoundedRect(rect.x(), rect.y() + 3, rect.width(), rect.height() - 6, 3, 3);
        painter->setBrush(QColor(255, 255, 255));
        painter->drawRoundedRect(rect.x() + 1, rect.y() + 4, rect.width() - 2, rect.height() - 8, 2, 2);
        painter->setPen(QColor(0, 161, 255));

        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
        painter->restore();
    }
    else if(date < minimumDate() || date > maximumDate())
    {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(249, 249, 249));

        painter->drawRect(rect.x(), rect.y() + 3, rect.width(), rect.height() - 6);
        painter->setPen(QColor(220, 220, 220));

        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
        painter->restore();
    }
    else
    {
        QCalendarWidget::paintCell(painter, rect, date);
    }
}

void TTKCalendarWidget::initTopWidget()
{
    QWidget* topWidget = new QWidget(this);
    topWidget->setFixedHeight(40);
    topWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QHBoxLayout* hboxLayout = new QHBoxLayout(topWidget);
    hboxLayout->setContentsMargins(12, 0, 12, 0);
    hboxLayout->setSpacing(1);

    m_leftYearButton   = new QPushButton("<<", this);
    m_leftMonthButton  = new QPushButton("<", this);
    m_rightYearButton  = new QPushButton(">>", this);
    m_rightMonthButton = new QPushButton(">", this);
    m_dataLabel        = new QLabel(this);

    m_leftYearButton->setStyleSheet("border:none;");
    m_leftMonthButton->setStyleSheet("border:none;");
    m_rightYearButton->setStyleSheet("border:none;");
    m_rightMonthButton->setStyleSheet("border:none;");

    m_leftYearButton->setFixedSize(20, 20);
    m_leftMonthButton->setFixedSize(20, 20);
    m_rightYearButton->setFixedSize(20, 20);
    m_rightMonthButton->setFixedSize(20, 20);

    hboxLayout->addWidget(m_leftYearButton);
    hboxLayout->addWidget(m_leftMonthButton);
    hboxLayout->addStretch();
    hboxLayout->addWidget(m_dataLabel);
    hboxLayout->addStretch();
    hboxLayout->addWidget(m_rightMonthButton);
    hboxLayout->addWidget(m_rightYearButton);
    topWidget->setLayout(hboxLayout);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(layout());
    vBodyLayout->insertWidget(0, topWidget);

    connect(m_leftYearButton,   SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(m_leftMonthButton,  SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(m_rightYearButton,  SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(m_rightMonthButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setDataLabelTimeText(selectedDate().year(), selectedDate().month());
}

void TTKCalendarWidget::initBottomWidget()
{
    QWidget* bottomWidget = new QWidget(this);
    bottomWidget->setFixedHeight(20);
    bottomWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(layout());
    vBodyLayout->addWidget(bottomWidget);
}
