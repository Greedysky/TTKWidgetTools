#include "ttkcolorbuttonwidget.h"

TTKColorButtonWidget::TTKColorButtonWidget(QWidget *parent)
    : QWidget(parent)
{
    m_colors << "#FEFEFE" << "#EEEEEF" << "#DCDDDD" << "#C9CACA" << "#B6B6B7" << "#A1A1A1" << "#8B8B8C" << "#757475" << "#5F5D5D" << "#474443" << "#303030";
    m_colors << "#00A2E9" << "#009B4C" << "#FFF000" << "#E62129" << "#E40082" << "#B04B87" << "#F08519" << "#F4B3B3" << "#897870" << "#D2CDE6" << "#A79CCB";
    m_colors << "#758FC8" << "#7C6FB0" << "#9288B1" << "#566892" << "#5E5872" << "#7789A4" << "#008FD7" << "#A0D9F6" << "#B8CEDA" << "#98AAB4" << "#75838A";
    m_colors << "#50585D" << "#5B7877" << "#4B8D7F" << "#769C9B" << "#5BA997" << "#5FA776" << "#62C3D0" << "#56AAB7" << "#B9CCBC" << "#D5EAD8" << "#A6D4AE";
    m_colors << "#99A99C" << "#9AA780" << "#BCC774" << "#BBC99A" << "#ACCE22" << "#D9E483" << "#5F5C50" << "#8B8979" << "#B6B49E" << "#B6B281" << "#DED572";
    m_colors << "#FFF582" << "#FFF9B1" << "#FFFCDB" << "#B39B77" << "#D59961" << "#DAB96B" << "#EF8641" << "#F6AE45" << "#F5B06E" << "#FDD100" << "#FBD7A3";
    m_colors << "#89765B" << "#AC6249" << "#D0753B" << "#EF8762" << "#F5B193" << "#FADAC9" << "#AF8283" << "#CF7771" << "#FF696B" << "#CF788A" << "#E61D4C";
    m_colors << "#EF8781" << "#E95A6F" << "#D49D9E" << "#876474" << "#AC6484" << "#F4B5D0" << "#D49EB6" << "#B39FA8" << "#D8C0CB" << "#B3719D" << "#CA5599";
    m_colors << "#CD81B3" << "#B593B3" << "#D0A9CD" << "#745E73" << "#977B95" << "#A878B1" << "#A72185" << "#934787" << "#804E9A" << "#7B5882" << "#714588";

    m_space = 2;
    m_columnCount = 11;
    m_borderRadius = 0;
    m_borderWidth = 2;
    m_borderColor = QColor("#C0392B");

    m_gridLayout = new QGridLayout;
    m_gridLayout->setSpacing(m_space);
    m_gridLayout->setMargin(0);

    setLayout(m_gridLayout);
    initStyle();
    initBtn();
}

QSize TTKColorButtonWidget::sizeHint() const
{
    return QSize(400, 300);
}

void TTKColorButtonWidget::setColors(const QStringList &colors)
{
    if(m_colors != colors)
    {
        m_colors = colors;
        initBtn();
    }
}

void TTKColorButtonWidget::setSpace(int space)
{
    if(m_space != space)
    {
        m_space = space;
        m_gridLayout->setSpacing(space);
    }
}

void TTKColorButtonWidget::setColumnCount(int columnCount)
{
    if(m_columnCount != columnCount)
    {
        m_columnCount = columnCount;
        initBtn();
    }
}

void TTKColorButtonWidget::setBorderRadius(int borderRadius)
{
    if(m_borderRadius != borderRadius)
    {
        m_borderRadius = borderRadius;
        initStyle();
    }
}

void TTKColorButtonWidget::setBorderWidth(int borderWidth)
{
    if(m_borderWidth != borderWidth)
    {
        m_borderWidth = borderWidth;
        initStyle();
    }
}

void TTKColorButtonWidget::setBorderColor(const QColor &borderColor)
{
    if(m_borderColor != borderColor)
    {
        m_borderColor = borderColor;
        initStyle();
    }
}

void TTKColorButtonWidget::btnClicked()
{
    QPushButton *btn = (QPushButton *)sender();
    const QString &objName = btn->objectName();
    emit colorChanged(QColor(objName.right(7)));
}

void TTKColorButtonWidget::initStyle()
{
    const QString &qss = QString("QPushButton{border:none; border-radius:%1px;}"
                                 "QPushButton:hover{border:%2px solid %3;}")
                         .arg(m_borderRadius).arg(m_borderWidth).arg(m_borderColor.name());
    setStyleSheet(qss);
}

void TTKColorButtonWidget::initBtn()
{
    qDeleteAll(m_btns);
    m_btns.clear();

    int count = m_colors.count();
    int row = 0;
    int column = 0;
    int index = 0;

    for(int i = 0; i < count; i++)
    {
        QPushButton *btn = new QPushButton;
        connect(btn, SIGNAL(pressed()), this, SLOT(btnClicked()));
        btn->setObjectName("btn" + m_colors.at(i));
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btn->setStyleSheet(QString("QPushButton{background:%1;}").arg(m_colors.at(i)));
        m_gridLayout->addWidget(btn, row, column);

        column++;
        index++;

        if(index % m_columnCount == 0)
        {
            row++;
            column = 0;
        }
        m_btns.append(btn);
    }
}
