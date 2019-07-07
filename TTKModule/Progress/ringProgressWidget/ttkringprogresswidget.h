#ifndef TTKRINGPROGRESSWIDGET_H
#define TTKRINPROGRESSWIDGET_H

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
*          feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_CORE_EXPORT TTKRingProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKRingProgressWidget)
public:
    explicit TTKRingProgressWidget(QWidget *parent = nullptr);
    virtual ~TTKRingProgressWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);

    void setClockWise(bool clockWise);
    void setShowPercent(bool showPercent);
    void setAlarmMode(bool alarmMode);
    void setStartAngle(int startAngle);

    void setRingPadding(int ringPadding);
    void setRingWidth(int ringWidth);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setBgColor(const QColor &bgColor);
    void setTextColor(const QColor &textColor);

    void setRingColor(const QColor &ringColor);
    void setRingBgColor(const QColor &ringBgColor);
    void setCircleColor(const QColor &circleColor);

    void setRingValueF(int ringValueF);
    void setRingValueS(int ringValueS);
    void setRingValueT(int ringValueT);

    void setRingColorF(const QColor &ringColorF);
    void setRingColorS(const QColor &ringColorS);
    void setRingColorT(const QColor &ringColorT);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawBg(QPainter *painter);
    void drawRing(QPainter *painter);
    void drawPadding(QPainter *painter);
    void drawCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;

    bool m_clockWise;
    bool m_showPercent;
    bool m_alarmMode;

    int m_startAngle;
    int m_ringPadding;
    int m_ringWidth;
    bool m_animation;
    double m_animationStep;

    QColor m_bgColor;
    QColor m_textColor;
    QColor m_ringColor;
    QColor m_ringBgColor;
    QColor m_circleColor;

    int m_ringValueF;
    int m_ringValueS;
    int m_ringValueT;

    QColor m_ringColorF;
    QColor m_ringColorS;
    QColor m_ringColorT;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;

};

#endif // TTKRINGPROGRESSWIDGET_H
