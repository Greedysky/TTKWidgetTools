#ifndef TTKCHECKABLE_H
#define TTKCHECKABLE_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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
 ***************************************************************************/

#include <QAbstractButton>
#include "ttkglobaldefine.h"

class QState;
class QStateMachine;
class QSignalTransition;

class TTKCheckable;

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_MODULE_EXPORT TTKCheckableIcon : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(qreal iconSize READ iconSize WRITE setIconSize)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
public:
    explicit TTKCheckableIcon(const QIcon &icon, TTKCheckable *parent = nullptr);

    virtual QSize sizeHint() const override final;

    void setIcon(const QIcon &icon);
    inline QIcon icon() const { return m_icon; }

    void setColor(const QColor &color);
    inline QColor color() const { return m_color; }

    void setIconSize(qreal size);
    inline qreal iconSize() const { return m_iconSize; }

    void setOpacity(qreal opacity);
    inline qreal opacity() const { return m_opacity; }

protected:
    virtual void paintEvent(QPaintEvent *event) override final;

    TTKCheckable *m_checkable;
    QColor m_color;
    QIcon m_icon;
    qreal m_iconSize, m_opacity;

};

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_MODULE_EXPORT TTKCheckable : public QAbstractButton
{
    Q_OBJECT
public:
    enum LabelPosition
    {
        LabelPositionLeft,
        LabelPositionRight
    };

    explicit TTKCheckable(QWidget *parent = nullptr);
    ~TTKCheckable();

    void setLabelPosition(LabelPosition placement);
    LabelPosition labelPosition() const;

    void setCheckedColor(const QColor &color);
    QColor checkedColor() const;

    void setUncheckedColor(const QColor &color);
    QColor uncheckedColor() const;

    void setTextColor(const QColor &color);
    QColor textColor() const;

    void setDisabledColor(const QColor &color);
    QColor disabledColor() const;

    void setCheckedIcon(const QIcon &icon);
    QIcon checkedIcon() const;

    void setUncheckedIcon(const QIcon &icon);
    QIcon uncheckedIcon() const;

    virtual QSize sizeHint() const override final;

protected:
    virtual bool event(QEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

    virtual void setupProperties();

    TTKCheckableIcon *m_checkedIcon, *m_uncheckedIcon;
    QStateMachine *m_stateMachine;
    QState *m_uncheckedState, *m_checkedState;
    QState *m_disabledUncheckedState, *m_disabledCheckedState;
    QSignalTransition *m_uncheckedTransition, *m_checkedTransition;
    TTKCheckable::LabelPosition  m_labelPosition;
    QColor m_checkedColor, m_uncheckedColor, m_textColor, m_disabledColor;

};

#endif // TTKCHECKABLE_H
