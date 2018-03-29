#ifndef TTKANIMATIONSTACKEDWIDGET_H
#define TTKANIMATIONSTACKEDWIDGET_H

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

#include <QPainter>
#include <QVariant>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
	Q_PROPERTY(float afValue READ GetValue WRITE SetValue)
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

    explicit TTKAnimationStackedWidget(QWidget *parent = 0);
    virtual ~TTKAnimationStackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);

	void setCurve(QEasingCurve::Type aeCurve);
	void setRevert(bool abRevert);

    void setDuration(int duration);
    int getDuration() const;

	void setFadeEnable(bool abEnabled);
	void setAnimatEnable(bool abEnabled);

	void addWidget(QWidget *widget);

	bool isAnimating();

	float GetValue() const;
	void SetValue(const float &afValue);

Q_SIGNALS:
	void page_changed(int aiIndex);

public Q_SLOTS:
	void setCurrentIndex(int index);

private Q_SLOTS:
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event);
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
	float m_fRangeValue;
	float m_fStartValue;
	float m_fEndValue;

	bool m_bFade;
	bool m_bAnimat;
	QEasingCurve::Type	m_eCurve;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

	bool m_bRevert;

	QPixmap m_PrivPixmap;
	QPixmap m_CurrentPixmap;
	QPixmap	*m_pCoverPixmap;

};

#endif // TTKANIMATIONSTACKEDWIDGET_H
