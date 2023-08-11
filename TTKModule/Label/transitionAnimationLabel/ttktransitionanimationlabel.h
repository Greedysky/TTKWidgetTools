#ifndef TTKTRANSITIONANIMATIONLABEL_H
#define TTKTRANSITIONANIMATIONLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

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

#include <QLabel>
#include "ttkmoduleexport.h"

class QPropertyAnimation;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKTransitionAnimationLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTransitionAnimationLabel)
public:
    explicit TTKTransitionAnimationLabel(QWidget *parent = nullptr);
    ~TTKTransitionAnimationLabel();

    void start();
    void stop();

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void setPixmap(const QPixmap &pix);

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    bool m_isAnimating;
    int m_currentValue;
    bool m_noAnimationSet;
    QPixmap m_rendererPixmap;
    QPixmap m_currentPixmap, m_previousPixmap;
    QPropertyAnimation *m_animation;

};

#endif // TTKTRANSITIONANIMATIONLABEL_H
