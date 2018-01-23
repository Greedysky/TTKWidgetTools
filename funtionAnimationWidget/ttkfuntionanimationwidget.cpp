#include "ttkfuntionanimationwidget.h"

#include "qmath.h"

#include <QPainter>
#include <QBoxLayout>
#include <QToolButton>
#include <QButtonGroup>
#include <QPropertyAnimation>

TTKBaseAnimationHWidget::TTKBaseAnimationHWidget(QWidget *parent)
    : QWidget(parent)
{
    m_curIndex = 0;
    m_preIndex = 0;
    m_x = 0;
    m_perWidth = 0;
    m_isAnimation = true;
    m_showLine = true;
    m_alignment = Bottom;

    m_animation = new QPropertyAnimation(this, "");
    m_animation->setDuration(100);

    connect(m_animation, SIGNAL(valueChanged(QVariant)), SLOT(animationChanged(QVariant)));
    connect(m_animation, SIGNAL(finished()), SLOT(finished()));

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

    m_group = new QButtonGroup(this);
    connect(m_group, SIGNAL(buttonClicked(int)), SLOT(switchToSelectedItemStyle(int)));
}

TTKBaseAnimationHWidget::~TTKBaseAnimationHWidget()
{
    qDeleteAll(m_container);
    delete m_animation;
    delete m_group;
}

void TTKBaseAnimationHWidget::setAlignment(Alignment alignment)
{
    m_alignment = alignment;
}

void TTKBaseAnimationHWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    m_perWidth = m_container[0]->width() + m_container[0]->x();

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 0.1, Qt::SolidLine));

    if(m_alignment == Bottom)
    {
        int offset =  m_perWidth - (m_container[0]->width() + m_pix.width()) / 2;
        offset = m_isAnimation ? (offset + m_x) : (offset + m_curIndex * m_perWidth);
        if(m_showLine)
        {
            painter.drawLine(0, height(), offset, height());
            painter.drawLine(offset + m_pix.width(), height(), width(), height());
        }
        painter.drawPixmap(offset, height() - m_pix.height(), m_pix);
    }
    else
    {
        int offset =  m_perWidth - (m_container[0]->width() + m_pix.width()) / 2;
        offset = m_isAnimation ? (offset + m_x) : (offset + m_curIndex * m_perWidth);
        if(m_showLine)
        {
            painter.drawLine(0, 0, offset, 0);
            painter.drawLine(offset + m_pix.width(), 0, width(), 0);
        }
        painter.drawPixmap(offset, 0, m_pix);
    }
}

void TTKBaseAnimationHWidget::switchToSelectedItemStyle(int index)
{
    m_isAnimation = true;
    m_preIndex = m_curIndex;
    m_curIndex = index;
    m_animation->setStartValue(m_preIndex*m_perWidth);
    m_animation->setEndValue(index*m_perWidth);
    m_animation->start();

    emit buttonClicked(index);
}

void TTKBaseAnimationHWidget::animationChanged(const QVariant &value)
{
    m_x = value.toInt();
    update();
}

void TTKBaseAnimationHWidget::finished()
{
    m_isAnimation = false;
}



TTKOptionAnimationHWidget::TTKOptionAnimationHWidget(QWidget *parent)
    : TTKBaseAnimationHWidget(parent)
{
    m_pix = QPixmap(54, 2);
    m_pix.fill(QColor(0x80, 0xB7, 0xF1));
    m_showLine = false;

    QHBoxLayout *ly = static_cast<QHBoxLayout*>(layout());

    for(int i=0; i<6; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn);
        m_group->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}



TTKTableAnimationHWidget::TTKTableAnimationHWidget(QWidget *parent)
    : TTKBaseAnimationHWidget(parent)
{
    m_pix = QPixmap(54, 2);
    m_pix.fill(QColor(255, 64, 129));
    m_showLine = false;

    QHBoxLayout *ly = static_cast<QHBoxLayout*>(layout());

    for(int i=0; i<6; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn);
        m_group->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKTableAnimationHWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor(0, 188, 212));

    TTKBaseAnimationHWidget::paintEvent(event);
}



TTKSkinAnimationHWidget::TTKSkinAnimationHWidget(QWidget *parent)
    : TTKBaseAnimationHWidget(parent)
{
    m_pix = QPixmap(":/res/bottom");

    QHBoxLayout *ly = static_cast<QHBoxLayout*>(layout());

    for(int i=0; i<6; ++i)
    {
        QToolButton *btn = new QToolButton(this);
        btn->setText(QString::number(i));
        btn->setFixedSize(54, 23);
        ly->addWidget(btn);
        m_group->addButton(btn, i);
        m_container << btn;
    }

    switchToSelectedItemStyle(0);
}

void TTKSkinAnimationHWidget::setAlignment(Alignment alignment)
{
    TTKBaseAnimationHWidget::setAlignment(alignment);
    m_pix = QPixmap(m_alignment == Bottom ? ":/res/bottom" : ":/res/top");
}
