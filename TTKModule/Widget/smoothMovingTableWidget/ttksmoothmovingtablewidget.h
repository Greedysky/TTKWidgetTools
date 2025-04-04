#ifndef TTKSMOOTHMOVINGTABLEWIDGET_H
#define TTKSMOOTHMOVINGTABLEWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

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

#include <QTableWidget>
#include "ttkmoduleexport.h"

class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKSmoothMovingTableWidget : public QTableWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSmoothMovingTableWidget)
public:
    explicit TTKSmoothMovingTableWidget(QWidget *parent = nullptr);
    ~TTKSmoothMovingTableWidget();

    void setMovedScrollBar(QScrollBar *bar);

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void timeToAnimation();
    void valueChanged(int value);

private:
    virtual void wheelEvent(QWheelEvent *event) override final;

    bool m_initialized;
    int m_previousValue, m_deltaValue;
    QScrollBar *m_scrollBar;
    QTimer *m_animationTimer;
    QPropertyAnimation *m_moveAnimation;

};

#endif // TTKSMOOTHMOVINGTABLEWIDGET_H
