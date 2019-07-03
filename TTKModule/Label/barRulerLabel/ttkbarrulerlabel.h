#ifndef TTKBARRULERLABEL_H
#define TTKBARRULERLABEL_H

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
class TTK_CORE_EXPORT TTKBarRulerLabel : public QWidget
{
    Q_OBJECT    
    TTK_DECLARE_MODULE(TTKBarRulerLabel)
public:
    explicit TTKBarRulerLabel(QWidget *parent = nullptr);
    virtual ~TTKBarRulerLabel();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);

    void setLongStep(int longStep);
    void setShortStep(int shortStep);

    void setSpace(int space);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    void setLineColor(const QColor &lineColor);

    void setBarBgColor(const QColor &barBgColor);
    void setBarColor(const QColor &barColor);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawBg(QPainter *painter);
    void drawRuler(QPainter *painter);
    void drawBarBg(QPainter *painter);
    void drawBar(QPainter *painter);

private:
    double m_maxValue;
    double m_minValue;
    double m_value;
    int m_precision;

    int m_longStep;
    int m_shortStep;
    int m_space;

    bool m_animation;
    double m_animationStep;

    QColor m_bgColorStart;
    QColor m_bgColorEnd;
    QColor m_lineColor;
    QColor m_barBgColor;
    QColor m_barColor;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;
    QRectF m_barRect;

};

#endif // TTKBARRULERLABEL_H
