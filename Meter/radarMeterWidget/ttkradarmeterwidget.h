#ifndef TTKRADARMETERWIDGET_H
#define TTKRADARMETERWIDGET_H

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
*          fearlazy <fearlazy@163.com>
*/
class TTK_EXTRAS_EXPORT TTKRadarMeterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKRadarMeterWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void timerEvent(QTimerEvent *event) override;

private:
    QRect m_drawArea;
    int m_pieRotate, m_timerId, m_pointTimerId, m_nSpeed;
    QList<QPoint> m_points;
    QList<int> m_pointsAlapha;

};

#endif // TTKRADARMETERWIDGET_H
