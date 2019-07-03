#ifndef TTKCOMPASSMETERWIDGET_H
#define TTKCOMPASSMETERWIDGET_H

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
class TTK_CORE_EXPORT TTKCompassMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCompassMeterWidget)
public:
 explicit TTKCompassMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKCompassMeterWidget();

    void setValue(double value);
    void setPrecision(int precision);

    void setAnimation(bool animation);
    void setAnimationStep(double animationStep);

    void setCrownColorStart(const QColor &crownColorStart);
    void setCrownColorEnd(const QColor &crownColorEnd);

    void setBgColorStart(const QColor &bgColorStart);
    void setBgColorEnd(const QColor &bgColorEnd);

    void setDarkColor(const QColor &darkColor);
    void setLightColor(const QColor &lightColor);

    void setForeground(const QColor &foreground);
    void setTextColor(const QColor &textColor);

    void setNorthPointerColor(const QColor &northPointerColor);
    void setSouthPointerColor(const QColor &southPointerColor);

    void setCenterColorStart(const QColor &cenerColorStart);
    void setCenterColorEnd(const QColor &cenerColorEnd);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawCrownCircle(QPainter *painter);
    void drawBgCircle(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawCoverOuterCircle(QPainter *painter);
    void drawCoverInnerCircle(QPainter *painter);
    void drawCoverCenterCircle(QPainter *painter);
    void drawPointer(QPainter *painter);
    void drawCenterCircle(QPainter *painter);
    void drawValue(QPainter *painter);

private:
    double m_value;
    int m_precision;
    bool m_animation;
    double m_animationStep;

    QColor m_crownColorStart;
    QColor m_crownColorEnd;
    QColor m_bgColorStart;
    QColor m_bgColorEnd;
    QColor m_darkColor;
    QColor m_lightColor;
    QColor m_foreground;
    QColor m_textColor;
    QColor m_northPointerColor;
    QColor m_southPointerColor;
    QColor m_centerColorStart;
    QColor m_centerColorEnd;

    bool m_reverse;
    double m_currentValue;
    QTimer *m_timer;

};

#endif  // TTKCOMPASSMETERWIDGET_H
