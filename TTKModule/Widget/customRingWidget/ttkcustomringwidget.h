#ifndef TTKCUSTOMRINGWIDGET_H
#define TTKCUSTOMRINGWIDGET_H

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

#include <QListWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKCustomRingWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCustomRingWidget)
public:
    explicit TTKCustomRingWidget(QWidget *parent = nullptr);

    void setBgColor(const QColor &bgColor);
    void setOutCircleColor(const QColor &outCircleColor);
    void setMidCircleColor(const QColor &midCircleColor);
    void setInCircleColor(const QColor &inCircleColor);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawBg(QPainter *painter);
    void drawOutCircle(QPainter *painter);
    void drawMidCircle(QPainter *painter);
    void drawInCircle(QPainter *painter);

private:
    QColor m_bgColor;
    QColor m_outCircleColor;
    QColor m_midCircleColor;
    QColor m_inCircleColor;

};

#endif // TTKCUSTOMRINGWIDGET_H
