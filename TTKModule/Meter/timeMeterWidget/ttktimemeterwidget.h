#ifndef TTKTIMEMETERWIDGET_H
#define TTKTIMEMETERWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2024 Greedysky Studio

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

#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKTimeMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTimeMeterWidget)
public:
    explicit TTKTimeMeterWidget(QWidget *parent = nullptr);

    void setValue(qreal value);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawCrown(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);

    QColor m_foregroundColor, m_backgroundColor;
    QString m_units, m_title;
    int m_scaleMajor, m_scaleMinor;
    int m_maxValue, m_minValue;
    int m_startAngle,m_endAngle;
    double m_value;
    int m_precision;

};

#endif // TTKTIMEMETERWIDGET_H
