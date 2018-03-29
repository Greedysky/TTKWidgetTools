#ifndef TTKFUNCTIONANIMATIONWIDGET_H
#define TTKFUNCTIONANIMATIONWIDGET_H

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

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKBaseAnimationWidget : public QWidget
{
    Q_OBJECT
public:
    enum Alignment
    {
        Top,
        Bottom,
        Left,
        Right
    };
    explicit TTKBaseAnimationWidget(QWidget *parent = 0);
    ~TTKBaseAnimationWidget();

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
    int m_curIndex, m_preIndex, m_x, m_perValue;
    bool m_isAnimation, m_showLine;

    Alignment m_alignment;
    QPropertyAnimation *m_animation;
    QList<QWidget*> m_container;
    QButtonGroup *m_group;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKBaseAnimationHWidget : public TTKBaseAnimationWidget
{
    Q_OBJECT
public:
    explicit TTKBaseAnimationHWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKOptionAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKOptionAnimationHWidget(QWidget *parent = 0);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKTableAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKTableAnimationHWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKSkinAnimationHWidget : public TTKBaseAnimationHWidget
{
    Q_OBJECT
public:
    explicit TTKSkinAnimationHWidget(QWidget *parent = 0);

    void setAlignment(Alignment alignment);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKBaseAnimationVWidget : public TTKBaseAnimationWidget
{
    Q_OBJECT
public:
    explicit TTKBaseAnimationVWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKOptionAnimationVWidget : public TTKBaseAnimationVWidget
{
    Q_OBJECT
public:
    explicit TTKOptionAnimationVWidget(QWidget *parent = 0);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKTableAnimationVWidget : public TTKBaseAnimationVWidget
{
    Q_OBJECT
public:
    explicit TTKTableAnimationVWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKSkinAnimationVWidget : public TTKBaseAnimationVWidget
{
    Q_OBJECT
public:
    explicit TTKSkinAnimationVWidget(QWidget *parent = 0);

    void setAlignment(Alignment alignment);

};

#endif // TTKFUNCTIONANIMATIONWIDGET_H
