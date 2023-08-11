#ifndef TTKFLATBUTTONWIDGET_H
#define TTKFLATBUTTONWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QPushButton>
#include "ttkmoduleexport.h"

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_MODULE_EXPORT TTKFlatButtonWidget : public QPushButton
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFlatButtonWidget)
public:
    enum class IconAlignment
    {
        Left,
        Right
    };

    explicit TTKFlatButtonWidget(QWidget *parent = nullptr);

    void setForegroundColor(const QColor &foregroundColor);
    void setBackgroundColor(const QColor &backgroundColor);

    void setIconAlignment(IconAlignment alignment);
    void setCornerRadius(qreal radius);
    void setTextAlignment(Qt::Alignment alignment);

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawForeground(QPainter *painter);
    void drawBackground(QPainter *painter);

    Qt::Alignment m_textAlignment;
    IconAlignment m_iconAlignment;
    QColor m_backgroundColor, m_foregroundColor;
    qreal m_cornerRadius;

};


#endif // TTKFLATBUTTONWIDGET_H
