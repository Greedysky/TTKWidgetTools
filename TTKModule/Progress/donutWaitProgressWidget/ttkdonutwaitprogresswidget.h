#ifndef TTKDONUTWAITPROGRESSWIDGET_H
#define TTKDONUTWAITPROGRESSWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2024 Greedysky Studio

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
 */
class TTK_MODULE_EXPORT TTKDonutWaitProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKDonutWaitProgressWidget)
public:
    explicit TTKDonutWaitProgressWidget(QWidget *parent = nullptr);

    void setForegroundColor(const QColor &foregroundColor);
    void setBackgroundColor(const QColor &backgroundColor);
    void setClockWise(bool clockwise);
    void setRotateDelta(int delta);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawDonutWait(QPainter *painter);

    QColor m_foregroundColor;
    QColor m_backgroundColor;
    bool m_clockWise;
    int m_rotateDelta;
    int m_rotateAngle;

    QTimer* m_timer;

};

#endif // TTKDONUTWAITPROGRESSWIDGET_H
