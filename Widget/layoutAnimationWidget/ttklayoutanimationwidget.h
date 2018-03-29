#ifndef TTKLAYOUTANIMATIONWIDGET_H
#define TTKLAYOUTANIMATIONWIDGET_H

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

#include <QWidget>
#include "ttkglobaldefine.h"

class QVBoxLayout;
class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKLayoutAnimationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKLayoutAnimationWidget(QWidget *parent = 0);
    ~TTKLayoutAnimationWidget();

    void start();
    void stop();

    void addStretch(int stretch = 0);
    void addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = 0);
    void removeWidget(QWidget *widget);

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    bool m_isAnimating;
    float m_currentValue;
    QWidget *m_mainWidget;
    QVBoxLayout *m_widgetLayout;
    QPropertyAnimation *m_animation;

};

#endif // TTKLAYOUTANIMATIONWIDGET_H
