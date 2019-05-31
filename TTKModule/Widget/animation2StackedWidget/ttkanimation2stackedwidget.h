#ifndef TTKANIMATION2STACKEDWIDGET_H
#define TTKANIMATION2STACKEDWIDGET_H

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

#include <QStackedWidget>
#include <QPropertyAnimation>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKAnimation2StackedWidget : public QStackedWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAnimation2StackedWidget)
    Q_PROPERTY(float value READ GetValue WRITE SetValue)
public:
    enum AnimationType
    {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft,
        RollInOut,
        FadeInOut,
        BlackInOut,
        SlideInOut,
        CoverInOutLeft,
        CoverInOutRight,
        FadeExchange,
        VerticalFlipRotate,
        VerticalFlipRotateOut,
        VerticalCubeRotateT2B,
        VerticalCubeRotateB2T,
        HorizontalFlipRotate
    };

    explicit TTKAnimation2StackedWidget(QWidget *parent = nullptr);
    virtual ~TTKAnimation2StackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);

    void setCurve(QEasingCurve::Type curve);
    void setRevert(bool revert);

    void setDuration(int duration);
    int getDuration() const;

    void setFadeEnable(bool enable);
    void setAnimatEnable(bool animat);

    void addWidget(QWidget *widget);

    bool isAnimating();

    float GetValue() const;
    void SetValue(const float value);

    virtual QSize sizeHint() const override;

Q_SIGNALS:
    void pageChanged(int index);

public Q_SLOTS:
    void setCurrentIndex(int index);

private Q_SLOTS:
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
    float m_rangeValue;
    float m_startValue;
    float m_endValue;

    bool m_fade;
    bool m_animat;

    QEasingCurve::Type m_curve;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

    bool m_revert;

    QPixmap m_privPixmap;
    QPixmap m_currentPixmap;
};

#endif // TTKANIMATION2STACKEDWIDGET_H
