#ifndef TTKGRABITEMWIDGET_H
#define TTKGRABITEMWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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
 ***************************************************************************/

#include <QLabel>
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKGrabItemWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKGrabItemWidget)
public:
    enum Direction
    {
        DirectionNo = 0,
        DirectionLeft = 1,
        DirectionTop = 2,
        DirectionRight = 4,
        DirectionBottom = 8,
        DirectionLeftTop = DirectionLeft + DirectionTop,
        DirectionLeftBottom = DirectionLeft + DirectionBottom,
        DirectionRightTop = DirectionRight + DirectionTop,
        DirectionRightBottom = DirectionRight + DirectionBottom
    };

    explicit TTKGrabItemWidget(QWidget *parent = nullptr);

    inline void setCrossStretch(bool c) { m_crossStretch = c; }
    inline bool crossStretch() const { return m_crossStretch; }

    virtual QSize sizeHint() const override final;

Q_SIGNALS:
    void rectChanged();

protected Q_SLOTS:
    virtual void onMouseChange(int x,int y);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override;

    Direction region(const QPoint &cursor);

    bool m_isPressed;
    bool m_crossStretch;
    Direction m_direction;
    QPoint m_movePos;
    QPolygon m_listMarker;
    QRect m_originRect, m_currentRect;

};

#endif // TTKGRABITEMWIDGET_H
