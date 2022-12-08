#ifndef TTKCLOCKMETERWIDGET_H
#define TTKCLOCKMETERWIDGET_H

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

#include <QWidget>
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKClockMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKClockMeterWidget)
public:
    enum class SecondStyle
    {
        Normal = 0,
        Spring = 1,
        Continue = 2,
        Hide = 3
	};

    explicit TTKClockMeterWidget(QWidget *parent = nullptr);
    ~TTKClockMeterWidget();

    void setCrownColorStart(const QColor &crownColorStart);
    void setCrownColorEnd(const QColor &crownColorEnd);

    void setForegroundColor(const QColor &foregroundColor);
    void setBackgroundColor(const QColor &backgroundColor);

    void setPointerHourColor(const QColor &pointerHourColor);
    void setPointerMinColor(const QColor &pointerMinColor);
    void setPointerSecColor(const QColor &pointerSecColor);

    void setSecondStyle(SecondStyle secondStyle);

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void updateTime();
    void updateSpring();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawHour(QPainter *painter);
    void drawMin(QPainter *painter);
    void drawSec(QPainter *painter);
    void drawDot(QPainter *painter);

    QColor m_crownColorStart;
    QColor m_crownColorEnd;

    QColor m_foregroundColor;
    QColor m_backgroundColor;

    QColor m_pointerHourColor;
    QColor m_pointerMinColor;
    QColor m_pointerSecColor;

    SecondStyle m_secondStyle;

    QTimer *m_timer;
    int m_hour, m_min, m_sec, m_msec;

    QTimer *m_timerSpring;
    double m_angleSpring;

};

#endif // TTKCLOCKMETERWIDGET_H
