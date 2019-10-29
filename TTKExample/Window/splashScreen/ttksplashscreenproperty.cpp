#include "ttksplashscreenproperty.h"
#include "ttksplashscreen.h"

#include <QToolButton>

TTKSplashScreenProperty::TTKSplashScreenProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    TTKSplashScreen *widget = new TTKSplashScreen(this);
    m_label = widget;
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWidget->resize(300, 300);

    widget->setWidget(mainWidget);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKSplashScreen*, m_label)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *elapseTimeItem = m_intManager->addProperty("ElapseTime");
    m_intManager->setMinimum(elapseTimeItem, 0);
    m_intManager->setValue(elapseTimeItem, 1000);
    objectItem->addSubProperty(elapseTimeItem);
    //
    QtProperty *pixmapItem = m_pixmapManager->addProperty("Pixmap");
    m_pixmapManager->setValue(pixmapItem, ":/res/1");
    objectItem->addSubProperty(pixmapItem);
    //
    m_browser->addProperty(objectItem);
}

TTKSplashScreenProperty::~TTKSplashScreenProperty()
{

}

void TTKSplashScreenProperty::intPropertyChanged(QtProperty *property, int value)
{
    TTKSplashScreen *widget = MStatic_cast(TTKSplashScreen*, m_label);
    if(property->propertyName() == "ElapseTime")
    {
        widget->setElapseTime(value);
    }
}

void TTKSplashScreenProperty::pixmapPropertyChanged(QtProperty *property, const QString &value)
{
    TTKSplashScreen *widget = MStatic_cast(TTKSplashScreen*, m_label);
    if(property->propertyName() == "Pixmap")
    {
        widget->setPixmap(value);
    }
}

void TTKSplashScreenProperty::showWidget()
{
    TTKSplashScreen *widget = MStatic_cast(TTKSplashScreen*, m_label);
    if(widget->widget() && widget->widget()->isVisible())
    {
        widget->widget()->hide();
    }
    widget->start();
}
