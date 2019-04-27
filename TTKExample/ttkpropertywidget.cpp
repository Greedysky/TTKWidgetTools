#include "ttkpropertywidget.h"

#include <QBoxLayout>

TTKPropertyWidget::TTKPropertyWidget(QWidget *parent)
    : QWidget(parent),
      m_item(nullptr)
{
    //
    m_boolManager = new QtBoolPropertyManager(this);
    m_intManager = new QtIntPropertyManager(this);
    m_stringManager = new QtStringPropertyManager(this);
    m_sizeManager = new QtSizePropertyManager(this);
    m_rectManager = new  QtRectPropertyManager(this);
    m_sizePolicyManager = new QtSizePolicyPropertyManager(this);
    m_enumManager = new QtEnumPropertyManager(this);
    m_colorManager = new QtColorPropertyManager(this);
    //
    m_groupManager = new QtGroupPropertyManager(this);
    //
    m_checkBoxFactory = new QtCheckBoxFactory(this);
    m_spinBoxFactory = new QtSpinBoxFactory(this);
    m_lineEditFactory = new QtLineEditFactory(this);
    m_comboBoxFactory = new QtEnumEditorFactory(this);
    //
    m_browser = new QtTreePropertyBrowser(this);
    //
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_browser);
    setLayout(layout);

    //
    m_browser->setFactoryForManager(m_boolManager, m_checkBoxFactory);
    m_browser->setFactoryForManager(m_intManager, m_spinBoxFactory);
    m_browser->setFactoryForManager(m_stringManager, m_lineEditFactory);
    m_browser->setFactoryForManager(m_sizeManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_rectManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_sizePolicyManager->subIntPropertyManager(), m_spinBoxFactory);
    m_browser->setFactoryForManager(m_sizePolicyManager->subEnumPropertyManager(), m_comboBoxFactory);
    m_browser->setFactoryForManager(m_enumManager, m_comboBoxFactory);
}

TTKPropertyWidget::~TTKPropertyWidget()
{

}

QWidget* TTKPropertyWidget::widget() const
{
    return m_item;
}
