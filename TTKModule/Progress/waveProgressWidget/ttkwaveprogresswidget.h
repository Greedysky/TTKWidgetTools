#ifndef TTKWAVEPROGRESSWIDGET_H
#define TTKWAVEPROGRESSWIDGET_H

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
 */
class TTK_CORE_EXPORT TTKWaveProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKWaveProgressWidget)
public:
    enum PercentStyle
    {
        PercentStyleRect = 0,
        PercentStyleCircle,
        PercentStyleEllipse
    };

    explicit TTKWaveProgressWidget(QWidget *parent = nullptr);
    virtual ~TTKWaveProgressWidget();

    void setRange(int minValue, int maxValue);

    void setMinValue(int minValue);
    void setMaxValue(int maxValue);

    void setValue(int value);

    void setWaterDensity(int waterDensity);
    void setWaterHeight(double waterHeight);

    void setOffset(int offset);
    void setBorderWidth(double borderWidth);
    void setBgColor(const QColor &bgColor);

    void setPointerStyle(const PercentStyle &percentStyle);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    void drawValue(QPainter *painter);

private Q_SLOTS:
    void timeout();

private:
    int m_value;
    int m_minValue;
    int m_maxValue;
    int m_waterDensity;
    double m_waterHeight;
    double m_offset;
    int m_borderWidth;

    QColor m_bgColor;
    QTimer *m_timer;
    PercentStyle m_percentStyle;

};

#endif // TTKWAVEPROGRESSWIDGET_H
