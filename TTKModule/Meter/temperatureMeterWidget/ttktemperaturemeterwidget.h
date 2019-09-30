#ifndef TTKTEMPERATUREMETERWIDGET_H
#define TTKTEMPERATUREMETERWIDGET_H

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

#include <QWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_CORE_EXPORT TTKTemperatureMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTemperatureMeterWidget)
public:
    explicit TTKTemperatureMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKTemperatureMeterWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setOuterCircleColor(const QColor &outerCircleColor);
    void setInnerCircleColor(const QColor &innerCircleColor);
    void setCenterCircleColor(const QColor &centerCircleColor);

    void setUsedColor(const QColor &usedColor);
    void setFreeColor(const QColor &freeColor);
    void setTextColor(const QColor &textColor);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawOuterCircle(QPainter *painter);
    void drawInnerCircle(QPainter *painter);
    void drawProgress(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawUnit(QPainter *painter);

private:
    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_startAngle;
    int m_endAngle;
    bool m_animation;
    double m_animationStep;

    QColor m_outerCircleColor;
    QColor m_innerCircleColor;
    QColor m_centerCircleColor;
    QColor m_usedColor;
    QColor m_freeColor;
    QColor m_textColor;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;

};

#endif // TTKTEMPERATUREMETERWIDGET_H
