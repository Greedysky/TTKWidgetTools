#ifndef TTKROUNDPROGRESSWIDGET_H
#define TTKROUNDPROGRESSWIDGET_H

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
class TTK_CORE_EXPORT TTKRoundProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKRoundProgressWidget)
    Q_PROPERTY(float m_value READ getValue WRITE setValue)
public:
    enum SwitchFlags
    {
        Null        = 0x00000000,
        DefaultText = 0x00000001,
        LinearColor = 0x00000004,
        DecorateDot = 0x00000008,
        OutterCirle = 0x0000000E,
        Animation   = 0x00000010,
        All         = 0xFFFFFFFF
    };

    enum InnerDefaultTextStyle
    {
        Percent     = 0x00000001,
        Value       = 0x00000002,
        ValueAndMax = 0x00000004
    };

    explicit TTKRoundProgressWidget(QWidget *parent = nullptr);

    void setdefault(int startAngle, bool clockWise);
    void setOutterBarWidth(float width);
    void setInnerBarWidth(float width);

    void setRange(float min, float max);
    void setText(float value);

    void setOutterColor(const QColor &outterColor);
    void setInnerColor(const QColor &startColor, const QColor &endColor);
    void setInnerColor(const QColor &startColor);

    void setDefaultTextColor(const QColor &textColor);

    void setControlFlags(int flags);
    void setPrecision(int precision);

    inline void setInnerDefaultTextStyle(InnerDefaultTextStyle style) { m_innerDefaultTextStyle = style; }

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    void paintOutterBar(QPainter &painter);
    void paintInnerBar(QPainter &painter);
    void paintDot(QPainter &painter);
    void paintText(QPainter &painter);

private:
    void setValue(float value);
    inline float getValue() const { return m_value; }

private:
    int m_startAngle;
    bool m_clockWise;
    float m_outterBarWidth, m_innerBarWidth;
    float m_dotX, m_dotY;
    float m_min, m_max, m_value;

    QColor m_outterColor, m_startColor, m_endColor, m_textColor;
    int m_precision;
    float m_squareStart, m_squareWidth;

    quint32 m_controlFlags;
    InnerDefaultTextStyle m_innerDefaultTextStyle;

};

#endif // TTKROUNDPROGRESSWIDGET_H
