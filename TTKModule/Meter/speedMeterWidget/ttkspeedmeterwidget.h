#ifndef TTKSPEEDMETERWIDGET_H
#define TTKSPEEDMETERWIDGET_H

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
*/
class TTK_MODULE_EXPORT TTKSpeedMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSpeedMeterWidget)
public:
    explicit TTKSpeedMeterWidget(QWidget *parent = nullptr);

    void setValue(qreal value);
    qreal value() const { return m_value;}

    void setRatio(qreal value);
    qreal ratio() const { return m_ratio;}

    void setAnimating(bool enable);
    bool isAnimating() const { return m_bAnimating;}

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void updateRender();

protected:
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    void initialize();
    void resetVariables();
    void drawOuterCircle(QPainter *painter);
    void drawInnerCircle(QPainter *painter);
    void drawMark(QPainter *painter);
    void drawCoverCircle(QPainter *painter);
    void drawColorPie(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawCoverBall(QPainter *painter);
    void drawTextRect(QPainter *painter);

    qreal m_outerRadius, m_innerRadius;
    qreal m_coverCircleRadius, m_colorCircleRadius;
    qreal m_coverBallRadius;
    QPointF m_center;
    QString m_units;
    QRectF m_colorCircleRect;
    qreal m_value, m_ratio, m_currentValue;
    QTimer *m_updateTimer, *m_singleTimer;
    bool m_bReverse, m_bAnimating;

};

#endif // TTKSPEEDMETERWIDGET_H
