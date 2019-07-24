#ifndef TTKCOLORBUTTONWIDGET_H
#define TTKCOLORBUTTONWIDGET_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QPushButton>
#include <QGridLayout>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKColorButtonWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKColorButtonWidget)
public:
    explicit TTKColorButtonWidget(QWidget *parent = nullptr);

    void setColors(const QStringList &colors);
    void setSpace(int space);
    void setColumnCount(int columnCount);

    void setBorderRadius(int borderRadius);
    void setBorderWidth(int borderWidth);
    void setBorderColor(const QColor &borderColor);

    virtual QSize sizeHint() const override;

Q_SIGNALS:
    void colorChanged(const QColor &color);

private Q_SLOTS:
    void btnClicked();

private:
    void initStyle();
    void initBtn();

private:
    QGridLayout *m_gridLayout;
    QList<QPushButton*> m_btns;
    QStringList m_colors;

    int m_space;
    int m_columnCount;
    int m_borderRadius;
    int m_borderWidth;
    QColor m_borderColor;

};

#endif // TTKCOLORBUTTONWIDGET_H
