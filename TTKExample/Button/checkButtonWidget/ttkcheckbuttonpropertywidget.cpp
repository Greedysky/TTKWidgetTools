#include "ttkcheckbuttonpropertywidget.h"
#include "ttkcheckbuttonwidget.h"

#include <QIcon>

TTKCheckButtonPropertyWidget::TTKCheckButtonPropertyWidget(QWidget *parent)
    : TTKPropertyWidget(parent)
{
    m_item = new TTKCheckButtonWidget(this);
    //
    QtProperty *item0 = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    item0->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, static_cast<TTKCheckButtonWidget*>(m_item)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);

    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    item0->addSubProperty(activityItem);

    QtProperty *item3 = m_rectManager->addProperty("geometry");
    item0->addSubProperty(item3);

    QtProperty *item8 = m_enumManager->addProperty("direction");
    QStringList enumNames;
    enumNames << "Up" << "Right" << "Down" << "Left";
    m_enumManager->setEnumNames(item8, enumNames);
    QMap<int, QIcon> enumIcons;
    enumIcons[0] = QIcon(":/demo/images/up.png");
    enumIcons[1] = QIcon(":/demo/images/right.png");
    enumIcons[2] = QIcon(":/demo/images/down.png");
    enumIcons[3] = QIcon(":/demo/images/left.png");
    m_enumManager->setEnumIcons(item8, enumIcons);
    item0->addSubProperty(item8);

    QtProperty *item9 = m_intManager->addProperty("value");
    m_intManager->setRange(item9, -100, 100);
    item0->addSubProperty(item9);

    m_browser->addProperty(item0);


//    ui->widget->setDisabledColor(QColor(0, 0, 0));
//    ui->widget->setCheckedColor(QColor(255, 0, 0));
//    ui->widget->setText("Hello World");

//    ui->widget_2->setDisabledColor(QColor(0, 0, 0));
//    ui->widget_2->setCheckedColor(QColor(255, 0, 0));
//    ui->widget_2->setText("Hello World");

//    ui->widget_3->setLabelPosition(TTKCheckable::LabelPositionLeft);
//    ui->widget_3->setDisabledColor(QColor(0, 0, 0));
//    ui->widget_3->setCheckedColor(QColor(255, 0, 0));
//    ui->widget_3->setText("Hello World");

//    ui->widget_4->setLabelPosition(TTKCheckable::LabelPositionLeft);
//    ui->widget_4->setDisabledColor(QColor(0, 0, 0));
//    ui->widget_4->setCheckedColor(QColor(255, 0, 0));
//    ui->widget_4->setText("Hello World");
}

TTKCheckButtonPropertyWidget::~TTKCheckButtonPropertyWidget()
{

}
