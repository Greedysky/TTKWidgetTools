#ifndef TTKGRABITEMWIDGET_H
#define TTKGRABITEMWIDGET_H

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

#include <QLabel>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKGrabItemWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKGrabItemWidget)
public:
    enum Direction
    {
        Direction_No = 0,
        Direction_Left = 1,
        Direction_Top = 2,
        Direction_Right = 4,
        Direction_Bottom = 8,
        Direction_LeftTop = Direction_Left + Direction_Top,
        Direction_LeftBottom = Direction_Left + Direction_Bottom,
        Direction_RightTop = Direction_Right + Direction_Top,
        Direction_RightBottom = Direction_Right + Direction_Bottom
    };

    explicit TTKGrabItemWidget(QWidget *parent = nullptr);

    inline void setCrossStretch(bool c) { m_crossStretch = c;}
    inline bool gettCrossStretch() const { return m_crossStretch;}

    virtual QSize sizeHint() const override;

Q_SIGNALS:
    void rectChanged();

protected Q_SLOTS:
    virtual void onMouseChange(int x,int y);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    Direction getRegion(const QPoint &cursor);

    bool m_isPressed;
    bool m_crossStretch;
    Direction m_direction;
    QPoint m_movePos;
    QPolygon m_listMarker;
    QRect m_originRect, m_currentRect;

};

#endif // TTKGRABITEMWIDGET_H
