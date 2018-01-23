#ifndef TTKFUNTIONANIMATIONWIDGET_H
#define TTKFUNTIONANIMATIONWIDGET_H

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

#include <QWidget>
#include "ttkglobaldefine.h"

class QButtonGroup;
class QPropertyAnimation;

class TTK_EXTRAS_EXPORT TTKBaseAnimationHWidget : public QWidget
{
    Q_OBJECT
public:
    enum Alignment
    {
        Top,
        Bottom
    };
    explicit TTKBaseAnimationHWidget(QWidget *parent = 0);
    ~TTKBaseAnimationHWidget();

    void setAlignment(Alignment alignment);

Q_SIGNALS:
    void buttonClicked(int index);

public Q_SLOTS:
    virtual void switchToSelectedItemStyle(int index);
    void animationChanged(const QVariant &value);
    void finished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    QPixmap m_pix;
    int m_curIndex, m_preIndex, m_x, m_perWidth;
    bool m_isAnimation, m_showLine;

    Alignment m_alignment;
    QPropertyAnimation *m_animation;
    QList<QWidget*> m_container;
    QButtonGroup *m_group;

};


class TTK_EXTRAS_EXPORT TTKOptionAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKOptionAnimationHWidget(QWidget *parent = 0);

};


class TTK_EXTRAS_EXPORT TTKTableAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKTableAnimationHWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


class TTK_EXTRAS_EXPORT TTKSkinAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKSkinAnimationHWidget(QWidget *parent = 0);

    void setAlignment(Alignment alignment);

};

#endif // TTKFUNTIONANIMATIONWIDGET_H
