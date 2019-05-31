#ifndef TTKANIMATIONSTACKEDWIDGET_H
#define TTKANIMATIONSTACKEDWIDGET_H

/* =================================================
 * This file is part of the TTK Widget Tools project
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

#include <QStackedWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class QPropertyAnimation;

class TTK_CORE_EXPORT TTKAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAnimationStackedWidget)
public:
    enum AnimationType
    {
        LeftToRight,
        RightToLeft,
        TopToBottom,
        BottomToTop

    };

    explicit TTKAnimationStackedWidget(QWidget *parent = nullptr);
    virtual ~TTKAnimationStackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);

    void setDuration(int duration);
    int getDuration() const;

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

};

#endif // TTKANIMATIONSTACKEDWIDGET_H
