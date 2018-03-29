#ifndef TTKLINEEDITWIDGET_H
#define TTKLINEEDITWIDGET_H

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

#include <QLineEdit>
#include "ttkglobaldefine.h"

class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKLineEditWidget : public QLineEdit
{
    Q_OBJECT
public:
    explicit TTKLineEditWidget(QWidget *parent = 0);
    ~TTKLineEditWidget();

    void setColor(const QColor &color);

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void focusInEvent(QFocusEvent *event) override;

    bool m_isAnimating;
    float m_currentValue;
    QColor m_color;
    QPropertyAnimation *m_animation;

};

#endif // TTKLINEEDITWIDGET_H
