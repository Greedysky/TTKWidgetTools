#ifndef TTKLIGHTPOINTLABEL_H
#define TTKLIGHTPOINTLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2026 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKLightPointLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKLightPointLabel)
public:
    explicit TTKLightPointLabel(QWidget *parent = nullptr);
    ~TTKLightPointLabel();

    void setStep(int step);
    void setInterval(int msec);
    void setBackgroundColor(const QColor &backgroundColor);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawBackground(QPainter *painter);

    int m_step;
    int m_interval;
    QColor m_backgroundColor;

    int m_offset;
    bool m_add;
    QTimer *m_timer;

};

#endif // TTKLIGHTPOINTLABEL_H
