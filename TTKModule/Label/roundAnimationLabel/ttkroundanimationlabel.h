#ifndef TTKROUNDANIMATIONLABEL_H
#define TTKROUNDANIMATIONLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

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

#include <QTimer>
#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKRoundAnimationLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKRoundAnimationLabel)
public:
    explicit TTKRoundAnimationLabel(QWidget *parent = nullptr);
    ~TTKRoundAnimationLabel();

    void setPixmap(const QPixmap &pix);
    void setInterval(int msec);

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void start();
    void stop();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    QPixmap m_pixmap;
    QTimer m_timer;
    int m_rotateAngle;

};

#endif // TTKROUNDANIMATIONLABEL_H
