#include "ttkfunctionanimationwidget.h"

#include <QPainter>
#include <QBoxLayout>
#include <QToolButton>
#include <QPropertyAnimation>

TTKAbstractAnimationWidget::TTKAbstractAnimationWidget(QWidget *parent)
    : QWidget(parent),
      m_curIndex(0),
      m_preIndex(0),
      m_x(0),
      m_perValue(0),
      m_isAnimation(true),
      m_showLine(true)
{
    m_animation = new QPropertyAnimation(this, "");
    m_animation->setDuration(100);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(animationChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(finished()));

    m_buttonGroup = new QButtonGroup(this);
    QtButtonGroupConnect(m_buttonGroup, this, switchToSelectedItemStyle, TTK_SLOT);
}

TTKAbstractAnimationWidget::~TTKAbstractAnimationWidget()
{
    qDeleteAll(m_container);
    delete m_animation;
    delete m_buttonGroup;
}

void TTKAbstractAnimationWidget::setAlignment(Alignment alignment)
{
    m_alignment = alignment;
    update();
}

void TTKAbstractAnimationWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void TTKAbstractAnimationWidget::switchToSelectedItemStyle(int index)
{
    m_isAnimation = true;
    m_preIndex = m_curIndex;
    m_curIndex = index;
    m_animation->setStartValue(m_preIndex*m_perValue);
    m_animation->setEndValue(index*m_perValue);
    m_animation->start();

    Q_EMIT buttonClicked(index);
}

void TTKAbstractAnimationWidget::animationChanged(const QVariant &value)
{
    m_x = value.toInt();
    update();
}

void TTKAbstractAnimationWidget::finished()
{
    m_isAnimation = false;
}



TTKAbstractAnimationHWidget::TTKAbstractAnimationHWidget(QWidget *parent)
    : TTKAbstractAnimationWidget(parent)
{
    m_alignment = Alignment::Bottom;

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);
}

QSize TTKAbstractAnimationHWidget::sizeHint() const
{
    return QSize(200, 35);
}

void TTKAbstractAnimationHWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 0.1, Qt::SolidLine));

    m_perValue = m_container[0]->width() + m_container[0]->x();
    int offset = m_perValue - (m_container[0]->width() + m_pix.width()) / 2;
    offset = m_isAnimation ? (offset + m_x) : (offset + m_curIndex * m_perValue);

    if(m_alignment == Alignment::Bottom)
    {
        if(m_showLine)
        {
            painter.drawLine(0, height(), offset, height());
            painter.drawLine(offset + m_pix.width(), height(), width(), height());
        }
        painter.drawPixmap(offset, height() - m_pix.height(), m_pix);
    }
    else
    {
        if(m_showLine)
        {
            painter.drawLine(0, 0, offset, 0);
            painter.drawLine(offset + m_pix.width(), 0, width(), 0);
        }
        painter.drawPixmap(offset, 0, m_pix);
    }
}



TTKOptionAnimationHWidget::TTKOptionAnimationHWidget(QWidget *parent)
    : TTKAbstractAnimationHWidget(parent)
{
    m_pix = QPixmap(54, 2);
    m_pix.fill(QColor(0x80, 0xB7, 0xF1));
    m_showLine = false;

    QHBoxLayout *ly = TTKObjectCast(QHBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignVCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}



TTKTableAnimationHWidget::TTKTableAnimationHWidget(QWidget *parent)
    : TTKAbstractAnimationHWidget(parent)
{
    m_pix = QPixmap(54, 2);
    m_pix.fill(QColor(255, 64, 129));
    m_showLine = false;

    QHBoxLayout *ly = TTKObjectCast(QHBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignVCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKTableAnimationHWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor(0, 188, 212));

    TTKAbstractAnimationHWidget::paintEvent(event);
}



TTKSkinAnimationHWidget::TTKSkinAnimationHWidget(QWidget *parent)
    : TTKAbstractAnimationHWidget(parent)
{
    m_pix = QPixmap(":/res/bottom");

    QHBoxLayout *ly = TTKObjectCast(QHBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignVCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKSkinAnimationHWidget::setAlignment(Alignment alignment)
{
    TTKAbstractAnimationHWidget::setAlignment(alignment);
    m_pix = QPixmap(m_alignment == Alignment::Bottom ? ":/res/bottom" : ":/res/top");
}



TTKAbstractAnimationVWidget::TTKAbstractAnimationVWidget(QWidget *parent)
    : TTKAbstractAnimationWidget(parent)
{
    m_alignment = Alignment::Left;

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);
}

QSize TTKAbstractAnimationVWidget::sizeHint() const
{
    return QSize(65, 200);
}

void TTKAbstractAnimationVWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 0.1, Qt::SolidLine));

    m_perValue = m_container[0]->height() + m_container[0]->y();
    int offset = m_perValue - (m_container[0]->height() + m_pix.height()) / 2;
    offset = m_isAnimation ? (offset + m_x) : (offset + m_curIndex * m_perValue);

    if(m_alignment == Alignment::Left)
    {
        if(m_showLine)
        {
            painter.drawLine(0, 0, 0, offset);
            painter.drawLine(0, offset + m_pix.height(), 0, height());
        }
        painter.drawPixmap(0, offset, m_pix);
    }
    else
    {
        if(m_showLine)
        {
            painter.drawLine(width(), 0, width(), offset);
            painter.drawLine(width(), offset + m_pix.height(), width(), height());
        }
        painter.drawPixmap(width() - m_pix.width(), offset, m_pix);
    }
}



TTKOptionAnimationVWidget::TTKOptionAnimationVWidget(QWidget *parent)
    : TTKAbstractAnimationVWidget(parent)
{
    m_pix = QPixmap(2, 23);
    m_pix.fill(QColor(0x80, 0xB7, 0xF1));
    m_showLine = false;

    QVBoxLayout *ly = TTKObjectCast(QVBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignHCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}



TTKTableAnimationVWidget::TTKTableAnimationVWidget(QWidget *parent)
    : TTKAbstractAnimationVWidget(parent)
{
    m_pix = QPixmap(2, 23);
    m_pix.fill(QColor(255, 64, 129));
    m_showLine = false;

    QVBoxLayout *ly = TTKObjectCast(QVBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignHCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKTableAnimationVWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor(0, 188, 212));

    TTKAbstractAnimationVWidget::paintEvent(event);
}



TTKSkinAnimationVWidget::TTKSkinAnimationVWidget(QWidget *parent)
    : TTKAbstractAnimationVWidget(parent)
{
    m_pix = QPixmap(":/res/left");

    QVBoxLayout *ly = TTKObjectCast(QVBoxLayout*, layout());

    for(int i = 0; i < 3; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn, 0, Qt::AlignHCenter);
        m_buttonGroup->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKSkinAnimationVWidget::setAlignment(Alignment alignment)
{
    TTKAbstractAnimationVWidget::setAlignment(alignment);
    m_pix = QPixmap(m_alignment == Alignment::Left ? ":/res/left" : ":/res/right");
}
