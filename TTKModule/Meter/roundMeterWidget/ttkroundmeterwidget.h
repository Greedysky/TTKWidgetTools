#ifndef TTKROUNDMETERWIDGET_H
#define TTKROUNDMETERWIDGET_H

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
class TTK_CORE_EXPORT TTKRoundMeterWidget : public QWidget
{
	Q_OBJECT	
    TTK_DECLARE_MODULE(TTKRoundMeterWidget)
public:
    explicit TTKRoundMeterWidget(QWidget *parent = nullptr);
    virtual ~TTKRoundMeterWidget();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setAngle(double angle);

    void setPrecision(int precision);

    void setUnit(const QString &unit);

    void setUsedColor(const QColor &usedColor);
    void setFreeColor(const QColor &freeColor);

    void setRangeTextColor(const QColor &rangeTextColor);
    void setValueTextColor(const QColor &valueTextColor);

    void setValueBgColor(const QColor &valueBgColor);
    void setOutBgColor(const QColor &outBgColor);

    void setCenterBgColorStart(const QColor &centerBgColorStart);
    void setCenterBgColorEnd(const QColor &centerBgColorEnd);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawDial(QPainter *painter);
    void drawBgOut(QPainter *painter);
    void drawBgRound(QPainter *painter);
    void drawBgCenter(QPainter *painter);
    void drawText(QPainter *painter);

private:
    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;

    double m_angle;
    QString m_unit;

    QColor m_usedColor;
    QColor m_freeColor;

    QColor m_rangeTextColor;
    QColor m_valueTextColor;

    QColor m_valueBgColor;
    QColor m_outBgColor;
    QColor m_centerBgColorStart;
    QColor m_centerBgColorEnd;

    double m_currentPercent;
    double m_valuePercent;
    QTimer *m_timer;
};

#endif // TTKROUNDMETERWIDGET_H
