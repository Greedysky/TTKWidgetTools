#ifndef TTKTRANSITIONANIMATIONLABEL_H
#define TTKTRANSITIONANIMATIONLABEL_H

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
#include "ttkglobaldefine.h"

class QPropertyAnimation;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_EXTRAS_EXPORT TTKTransitionAnimationLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TTKTransitionAnimationLabel(QWidget *parent = 0);

    ~TTKTransitionAnimationLabel();

    inline void setNoAnimation(bool on) { m_noAnimationSet = on; }
    inline bool getNoAnimation() const { return m_noAnimationSet; }

    QPixmap getRendererPixmap() const;

    void stop();

public Q_SLOTS:
    void setPixmap(const QPixmap &pix);

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event);

    bool m_isAnimating;
    int m_currentValue;
    bool m_noAnimationSet;
    QPixmap m_rendererPixmap;
    QPixmap m_currentPixmap, m_previousPixmap;
    QPropertyAnimation *m_animation;

};

#endif // TTKTRANSITIONANIMATIONLABEL_H
