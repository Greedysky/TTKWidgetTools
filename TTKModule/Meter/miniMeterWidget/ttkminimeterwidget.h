#ifndef TTKMINIMETERWIDGET_H
#define TTKMINIMETERWIDGET_H

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
class TTK_CORE_EXPORT TTKMiniMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKMiniMeterWidget)
public:
    enum PointerStyle
    {
        PointerStyleCircle = 0,
        PointerStyleIndicator = 1,
        PointerStyleIndicatorR = 2,
        PointerStyleTriangle = 3
    };

    explicit TTKMiniMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKMiniMeterWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);
    void setStep(int step);

    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setBorderColor(const QColor &borderColor);
    void setBgColor(const QColor &bgColor);
    void setTextColor(const QColor &textColor);
    void setPercentColor(const QColor &percentColor);

    void setShowValue(bool showValue);
    void setPointerStyle(const PointerStyle &pointerStyle);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawScale(QPainter *painter);
    void drawBgCircle(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawPointerCircle(QPainter *painter);
    void drawPointerIndicator(QPainter *painter);
    void drawPointerIndicatorR(QPainter *painter);
    void drawPointerTriangle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;
    int m_step;
    int m_startAngle;
    int m_endAngle;

    QColor m_borderColor;
    QColor m_bgColor;
    QColor m_textColor;
    QColor m_percentColor;
    PointerStyle m_pointerStyle;

    bool m_showValue;

};

#endif // TTKMINIMETERWIDGET_H
