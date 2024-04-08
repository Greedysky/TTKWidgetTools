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

    m_timer->setInterval(TTK_DN_S2MS);
    //
    m_item = new TTKLedPageLabel(this);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKLedPageLabel*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *backgroundColorItem = m_colorManager->addProperty("BackgroundColor");
    m_colorManager->setValue(backgroundColorItem, QColor(255, 85, 85));
    objectItem->addSubProperty(backgroundColorItem);
    //
    QtProperty *lineColorItem = m_colorManager->addProperty("LineColor");
    m_colorManager->setValue(lineColorItem, QColor(250, 250, 250));
    objectItem->addSubProperty(lineColorItem);
    //
    QtProperty *foregroundColorItem = m_colorManager->addProperty("ForegroundColor");
    m_colorManager->setValue(foregroundColorItem, QColor(50, 50, 50));
    objectItem->addSubProperty(foregroundColorItem);
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
    TTKLedPageLabel *widget = TTKObjectCast(TTKLedPageLabel*, m_item);
    if(property->propertyName() == "BackgroundColor")
    {
        widget->setBackgroundColor(value);
    }
    else if(property->propertyName() == "LineColor")
    {
        widget->setLineColor(value);
    }
    else if(property->propertyName() == "ForegroundColor")
    {
        widget->setForegroundColor(value);
    }
}

void TTKLedPageLabelProperty::updateRender()
{
    TTKLedPageLabel *widget = TTKObjectCast(TTKLedPageLabel*, m_item);
    widget->setText(QString::number(random(100) + 1));
}
