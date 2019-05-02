#include "ttkpropertywidget.h"
#include "ttkbackgroundcontainer.h"

#include <QBoxLayout>

TTKPropertyWidget::TTKPropertyWidget(QWidget *parent)
    : QWidget(parent),
      m_item(nullptr),
      m_containItem(nullptr)
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
    m_colorEditorFactory = new QtColorEditorFactory(this);

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
    m_browser->setFactoryForManager(m_colorManager, m_colorEditorFactory);

    //
    connect(m_boolManager, SIGNAL(valueChanged(QtProperty*,bool)), SLOT(boolPropertyChanged(QtProperty*,bool)));
    connect(m_intManager, SIGNAL(valueChanged(QtProperty*,int)), SLOT(intPropertyChanged(QtProperty*,int)));
    connect(m_stringManager, SIGNAL(valueChanged(QtProperty*,QString)), SLOT(stringPropertyChanged(QtProperty*,QString)));
    connect(m_sizeManager, SIGNAL(valueChanged(QtProperty*,QSize)), SLOT(sizePropertyChanged(QtProperty*,QSize)));
    connect(m_rectManager, SIGNAL(valueChanged(QtProperty*,QRect)), SLOT(rectPropertyChanged(QtProperty*,QRect)));
    connect(m_sizePolicyManager, SIGNAL(valueChanged(QtProperty*,QSizePolicy)), SLOT(sizePolicyPropertyChanged(QtProperty*,QSizePolicy)));
    connect(m_enumManager, SIGNAL(valueChanged(QtProperty*,int)), SLOT(enumPropertyChanged(QtProperty*,int)));
    connect(m_colorManager, SIGNAL(valueChanged(QtProperty*,QColor)), SLOT(colorPropertyChanged(QtProperty*,QColor)));
}

TTKPropertyWidget::~TTKPropertyWidget()
{

}

void TTKPropertyWidget::init()
{
    m_containItem = MStatic_cast(QWidget*, m_item->parent());
    connect(MStatic_cast(TTKBackgroundContainerItem*, m_containItem), SIGNAL(rectChanged()), SLOT(geometryChanged()));

    geometryChanged();
}

QWidget* TTKPropertyWidget::widget() const
{
    return m_item;
}

void TTKPropertyWidget::boolPropertyChanged(QtProperty *property, bool value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::intPropertyChanged(QtProperty *property, int value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::stringPropertyChanged(QtProperty *property, const QString &value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::sizePropertyChanged(QtProperty *property, const QSize &value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::rectPropertyChanged(QtProperty *property, const QRect &value)
{
    if(!m_containItem)
    {
        return;
    }

    if(property->propertyName() == "Geometry")
    {
        if(m_item->sizeHint().width() <= value.width() && m_item->sizeHint().height() <= value.height())
        {
            m_containItem->setGeometry(value);
        }
        else
        {
            m_rectManager->setValue(property, m_containItem->geometry());
        }
    }
}

void TTKPropertyWidget::sizePolicyPropertyChanged(QtProperty *property, const QSizePolicy &value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::enumPropertyChanged(QtProperty *property, int value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::colorPropertyChanged(QtProperty *property, const QColor &value)
{
    Q_UNUSED(property);
    Q_UNUSED(value);
}

void TTKPropertyWidget::geometryChanged()
{
    if(!m_containItem)
    {
        return;
    }

    foreach(QtProperty *property, m_rectManager->properties())
    {
        if(property->propertyName() == "Geometry")
        {
            m_rectManager->setValue(property, m_containItem->geometry());
        }
    }
}
