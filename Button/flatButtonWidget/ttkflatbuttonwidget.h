#ifndef TTKFLATBUTTONWIDGET_H
#define TTKFLATBUTTONWIDGET_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

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
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKFlatButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    enum IconAlignment
    {
        LeftIcon,
        RightIcon
    };

    explicit TTKFlatButtonWidget(QWidget *parent = 0);

    void setForegroundColor(const QColor &color);
    inline QColor foregroundColor() const { return m_foregroundColor; }

    void setBackgroundColor(const QColor &color);
    inline QColor backgroundColor() const { return m_backgroundColor; }

    void setFontSize(qreal size);
    inline qreal fontSize() const { return m_fontSize; }

    void setIconAlignment(IconAlignment alignment);
    inline IconAlignment iconAlignment() const { return m_iconAlignment; }

    void setCornerRadius(qreal radius);
    inline qreal cornerRadius() const { return m_cornerRadius; }

    void setTextAlignment(Qt::Alignment alignment);
    inline Qt::Alignment textAlignment() const { return m_textAlignment; }

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void paintBackground(QPainter *painter);
    void paintForeground(QPainter *painter);

    Qt::Alignment m_textAlignment;
    IconAlignment m_iconAlignment;
    QColor m_backgroundColor, m_foregroundColor;
    qreal m_cornerRadius, m_fontSize;

};


#endif // TTKFLATBUTTONWIDGET_H
