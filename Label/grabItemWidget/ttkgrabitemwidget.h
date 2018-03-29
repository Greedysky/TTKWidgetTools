#ifndef TTKGRABITEMWIDGET_H
#define TTKGRABITEMWIDGET_H

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

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_EXTRAS_EXPORT TTKGrabItemWidget : public QWidget
{
    Q_OBJECT
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

    explicit TTKGrabItemWidget(QWidget *parent = 0);

    virtual void setBorderRect(const QRect &rect);
    inline void setGeometricStretch(bool g) { m_geometricStretch = g;}
    inline bool getGeometricStretch() const { return m_geometricStretch;}
    inline void setCrossStretch(bool c) { m_crossStretch = c;}
    inline bool gettCrossStretch() const { return m_crossStretch;}

Q_SIGNALS:
    void rectChanged();

private Q_SLOTS:
    void onMouseChange(int x,int y);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void paintEvent(QPaintEvent *event);

    Direction getRegion(const QPoint &cursor);

    bool m_isPressed;
    bool m_crossStretch, m_geometricStretch;
    Direction m_direction;
    QPoint m_originPoint, m_movePos;
    QPolygon m_listMarker;
    QRect m_currentRect, m_borderRect;

};


#if QT_VERSION < QT_VERSION_CHECK(5,3,0)
inline QRect operator-(const QRect &rect, const QMargins &margins);
#endif


#endif // TTKGRABITEMWIDGET_H
