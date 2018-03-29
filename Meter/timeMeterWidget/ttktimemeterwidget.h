#ifndef TTKTIMEMETERWIDGET_H
#define TTKTIMEMETERWIDGET_H

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
class TTK_EXTRAS_EXPORT TTKTimeMeterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKTimeMeterWidget(QWidget *parent = 0);

    void setValue(qreal value);
    qreal value() const { return m_value;}

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    void drawCrown(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);

    bool m_numericIndicatorEnabled;
    QColor m_foreground, m_background;
    QString m_units, m_title;
    int m_scaleMajor, m_scaleMinor;
    int m_maxValue, m_minValue;
    int m_startAngle,m_endAngle;
    double m_value;
    int m_precision;

};

#endif // TTKTIMEMETERWIDGET_H
