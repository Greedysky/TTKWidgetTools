#ifndef TTKMOVINGLABELSLIDER_H
#define TTKMOVINGLABELSLIDER_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

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

#include <QLabel>
#include "ttkclickedslider.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKMovingLabelSlider : public TTKClickedSlider
{
    Q_OBJECT
public:
    explicit TTKMovingLabelSlider(QWidget *parent = 0);
    explicit TTKMovingLabelSlider(Qt::Orientation orientation, QWidget *parent = 0);
    ~TTKMovingLabelSlider();

    inline bool isMoving() const { return m_isMoving;}

    inline void setMoving(bool m) { m_isMoving = m;}

Q_SIGNALS:
    void sliderReleasedAt(int pos);

public Q_SLOTS:
    void setValue(int value);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;

    QPoint limitLableGeometry(int x, int y, int z);

    bool m_isMoving;
    QLabel *m_textLabel;
    Qt::Orientation m_orientation;

};

#endif // TTKMOVINGLABELSLIDER_H
