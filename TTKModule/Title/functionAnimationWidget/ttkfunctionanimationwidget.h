#ifndef TTKFUNCTIONANIMATIONWIDGET_H
#define TTKFUNCTIONANIMATIONWIDGET_H

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

#include <QWidget>
#include <QButtonGroup>
#include "ttkmoduleexport.h"

class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAbstractAnimationWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAbstractAnimationWidget)
public:
    enum class Alignment
    {
        Top,
        Bottom,
        Left,
        Right
    };

    explicit TTKAbstractAnimationWidget(QWidget *parent = nullptr);
    ~TTKAbstractAnimationWidget();

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
    QWidgetList m_container;
    QButtonGroup *m_buttonGroup;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAbstractAnimationHWidget : public TTKAbstractAnimationWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAbstractAnimationHWidget)
public:
    explicit TTKAbstractAnimationHWidget(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override final;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKOptionAnimationHWidget : public TTKAbstractAnimationHWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKOptionAnimationHWidget)
public:
    explicit TTKOptionAnimationHWidget(QWidget *parent = nullptr);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKTableAnimationHWidget : public TTKAbstractAnimationHWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTableAnimationHWidget)
public:
    explicit TTKTableAnimationHWidget(QWidget *parent = nullptr);

private:
    virtual void paintEvent(QPaintEvent *event) override final;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKSkinAnimationHWidget : public TTKAbstractAnimationHWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSkinAnimationHWidget)
public:
    explicit TTKSkinAnimationHWidget(QWidget *parent = nullptr);

    void setAlignment(Alignment alignment);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAbstractAnimationVWidget : public TTKAbstractAnimationWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAbstractAnimationVWidget)
public:
    explicit TTKAbstractAnimationVWidget(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override final;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKOptionAnimationVWidget : public TTKAbstractAnimationVWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKOptionAnimationVWidget)
public:
    explicit TTKOptionAnimationVWidget(QWidget *parent = nullptr);

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKTableAnimationVWidget : public TTKAbstractAnimationVWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKTableAnimationVWidget)
public:
    explicit TTKTableAnimationVWidget(QWidget *parent = nullptr);

private:
    virtual void paintEvent(QPaintEvent *event) override final;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKSkinAnimationVWidget : public TTKAbstractAnimationVWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSkinAnimationVWidget)
public:
    explicit TTKSkinAnimationVWidget(QWidget *parent = nullptr);

    void setAlignment(Alignment alignment);

};

#endif // TTKFUNCTIONANIMATIONWIDGET_H
