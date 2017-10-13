#ifndef ANIMATIONSTACKEDWIDGET_H
#define ANIMATIONSTACKEDWIDGET_H

/* =================================================
 * This file is part of the TTK StackedWidget project
 * Copyright (C) 2015 - 2017 Greedysky Studio

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

#include <QPainter>
#include <QVariant>
#include <QStackedWidget>
#include <QPropertyAnimation>

class AnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    enum AnimationType
    {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft
    };

    explicit AnimationStackedWidget(QWidget *parent = 0);
    virtual ~AnimationStackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);

    void setDuration(int duration);
    int getDuration() const;

private slots:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event);
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

};

#endif // ANIMATIONSTACKEDWIDGET_H
