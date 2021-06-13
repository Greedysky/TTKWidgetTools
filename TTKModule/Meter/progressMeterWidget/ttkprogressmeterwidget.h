#ifndef TTKPROGRESSMETERWIDGET_H
#define TTKPROGRESSMETERWIDGET_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKProgressMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKProgressMeterWidget)
public:
    enum PointerStyle
    {
        PointerStyleCircle = 0,
        PointerStyleIndicator = 1,
        PointerStyleIndicatorR = 2,
        PointerStyleTriangle = 3
    };

    explicit TTKProgressMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKProgressMeterWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);
    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setBgColor(const QColor &bgColor);
    void setProgressColor(const QColor &progressColor);
    void setProgressBgColor(const QColor &progressBgColor);

    void setCircleColorStart(const QColor &circleColorStart);
    void setCircleColorEnd(const QColor &circleColorEnd);

    void setShowPointer(bool showPointer);
    void setShowValue(bool showValue);

    void setTextColor(const QColor &textColor);
    void setPointerStyle(const PointerStyle &pointerStyle);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawBg(QPainter *painter);
    void drawColorPie(QPainter *painter);
    void drawCoverCircle(QPainter *painter);
    void drawCircle(QPainter *painter);
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
    int m_startAngle;
    int m_endAngle;

    QColor m_bgColor;
    QColor m_progressColor;
    QColor m_progressBgColor;
    QColor m_circleColorStart;
    QColor m_circleColorEnd;
    QColor m_textColor;

    bool m_showPointer;
    bool m_showValue;
    PointerStyle m_pointerStyle;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;

};

#endif // TTKPROGRESSMETERWIDGET_H
