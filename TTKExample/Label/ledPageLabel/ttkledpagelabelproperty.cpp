#include "ttkledpagelabelproperty.h"
#include "ttkledpagelabel.h"
#if TTK_QT_VERSION_CHECK(5,10,0)
#  include <QRandomGenerator>
#endif
#include <QTimer>
#include <QDateTime>

static int random(int value)
{
#if TTK_QT_VERSION_CHECK(5,10,0)
    return QRandomGenerator::global()->bounded(value);
#else
    return qrand() % value;
#endif
}

TTKLedPageLabelProperty::TTKLedPageLabelProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
#if !TTK_QT_VERSION_CHECK(5,10,0)
    qsrand(QDateTime::currentMSecsSinceEpoch());
#endif
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(1000);
    //
    m_item = new TTKLedPageLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKStatic_cast(TTKLedPageLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *backColorItem = m_colorManager->addProperty("BackColor");
    m_colorManager->setValue(backColorItem, QColor(255, 85, 85));
    objectItem->addSubProperty(backColorItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(250, 250, 250));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *frontColorItem = m_colorManager->addProperty("FrontColor");
    m_colorManager->setValue(frontColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(frontColorItem);
    //
    m_browser->addProperty(objectItem);
}

TTKLedPageLabelProperty::~TTKLedPageLabelProperty()
{
    delete m_timer;
}

void TTKLedPageLabelProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            m_timer->start();
        }
        else
        {
            m_timer->stop();
        }
    }
}

void TTKLedPageLabelProperty::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    TTKLedPageLabel *widget = TTKStatic_cast(TTKLedPageLabel*, m_item);
    if(property->propertyName() == "BackColor")
    {
        widget->setBackColor(value);
    }
    else if(property->propertyName() == "LineColor")
    {
        widget->setLineColor(value);
    }
    else if(property->propertyName() == "FrontColor")
    {
        widget->setFrontColor(value);
    }
}

void TTKLedPageLabelProperty::updateRender()
{
    TTKLedPageLabel *widget = TTKStatic_cast(TTKLedPageLabel*, m_item);
    widget->setText(QString::number(random(100) + 1));
}
