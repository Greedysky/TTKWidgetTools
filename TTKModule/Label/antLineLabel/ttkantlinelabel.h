#ifndef TTKANTLINELABEL_H
#define TTKANTLINELABEL_H

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
class TTK_CORE_EXPORT TTKAntLineLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAntLineLabel)
public:
    enum LineStyle
    {
        LineStyleRect = 0,
        LineStyleRoundedRect = 1,
        LineStyleEllipse = 2,
        LineStyleCircle = 3
    };

    explicit TTKAntLineLabel(QWidget *parent = nullptr);
    ~TTKAntLineLabel();

    void setLineLen(int lineLen);
    void setLineWidth(int lineWidth);
    void setLineStep(int lineStep);
    void setLineSpeed(int lineSpeed);
    void setLineColor(const QColor &lineColor);
    void setLineStyle(const LineStyle &lineStyle);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void updateValue();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    int m_lineLen;
    int m_lineWidth;
    int m_lineStep;
    int m_lineSpeed;

    QColor m_lineColor;
    LineStyle m_lineStyle;

    int m_dashes;
    int m_spaces;
    QVector<double> m_dashPattern;
    QTimer *m_timer;

};

#endif // TTKANTLINELABEL_H
