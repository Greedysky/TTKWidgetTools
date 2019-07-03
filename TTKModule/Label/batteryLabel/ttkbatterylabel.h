#ifndef TTKBATTERYLABEL_H
#define TTKBATTERYLABEL_H

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
class TTK_CORE_EXPORT TTKBatteryLabel : public QWidget
{
    Q_OBJECT    
    TTK_DECLARE_MODULE(TTKBatteryLabel)
public:
    explicit TTKBatteryLabel(QWidget *parent = nullptr);
    virtual ~TTKBatteryLabel();

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setAlarmValue(double alarmValue);

    void setStep(double step);

    void setBorderColorStart(const QColor &borderColorStart);
    void setBorderColorEnd(const QColor &borderColorEnd);

    void setAlarmColorStart(const QColor &alarmColorStart);
    void setAlarmColorEnd(const QColor &alarmColorEnd);

    void setNormalColorStart(const QColor &normalColorStart);
    void setNormalColorEnd(const QColor &normalColorEnd);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawBorder(QPainter *painter);
    void drawBg(QPainter *painter);

private:    
    double m_minValue;
    double m_maxValue;
    double m_value;
    double m_alarmValue;
    double m_step;

    QColor m_borderColorStart;
    QColor m_borderColorEnd;

    QColor m_alarmColorStart;
    QColor m_alarmColorEnd;

    QColor m_normalColorStart;
    QColor m_normalColorEnd;

    bool m_isForward;
    double m_currentValue;
    QRectF m_batteryRect;
    QTimer *m_timer;

};

#endif // TTKBATTERYLABEL_H
