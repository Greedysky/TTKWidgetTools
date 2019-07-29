#ifndef TTKPANELMETERWIDGET_H
#define TTKPANELMETERWIDGET_H

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
class TTK_CORE_EXPORT TTKPanelMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPanelMeterWidget)
public:
    explicit TTKPanelMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKPanelMeterWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);
    void setScaleMajor(int scaleMajor);
    void setScaleMinor(int scaleMinor);
    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setRingWidth(int ringWidth);
    void setRingColor(const QColor &ringColor);

    void setScaleColor(const QColor &scaleColor);
    void setPointerColor(const QColor &pointerColor);
    void setBgColor(const QColor &bgColor);
    void setTextColor(const QColor &textColor);
    void setUnit(const QString &unit);
    void setText(const QString &text);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawRing(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;
    int m_scaleMajor;
    int m_scaleMinor;
    int m_startAngle;
    int m_endAngle;
    bool m_animation;
    double m_animationStep;

    int m_ringWidth;
    QColor m_ringColor;
    QColor m_scaleColor;
    QColor m_pointerColor;
    QColor m_bgColor;
    QColor m_textColor;
    QString m_unit;
    QString m_text;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;

};

#endif // TTKPANELMETERWIDGET_H
