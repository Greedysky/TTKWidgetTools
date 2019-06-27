#ifndef TTKCIRCLEPROCESSWIDGET_H
#define TTKCIRCLEPROCESSWIDGET_H

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

#include <QWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class QPropertyAnimation;

/*!
* @author Greedysky <greedysky@163.com>
*         mofr
*/
class TTK_CORE_EXPORT TTKCircleProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCircleProgressWidget)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(qreal innerRadius READ innerRadius WRITE setInnerRadius)
    Q_PROPERTY(qreal outerRadius READ outerRadius WRITE setOuterRadius)
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(qreal infiniteAnimationValue READ infiniteAnimationValue WRITE setInfiniteAnimationValue)
    Q_PROPERTY(int visibleValue READ visibleValue WRITE setVisibleValue)
public:
    explicit TTKCircleProgressWidget(QWidget *parent = nullptr);
    virtual ~TTKCircleProgressWidget();

    int value() const;
    int maximum() const;

    qreal innerRadius() const;
    qreal outerRadius() const;
    QColor color() const;

    virtual QSize sizeHint() const override;

Q_SIGNALS:
    void valueChanged(int);
    void maximumChanged(int);

public Q_SLOTS:
    void setValue(int value);
    void setMaximum(int maximum);
    void setInnerRadius(qreal innerRadius);
    void setOuterRadius(qreal outerRadius);
    void setColor(const QColor &color);

private Q_SLOTS:
    void setInfiniteAnimationValue(qreal value);
    void setVisibleValue(int value);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    QString key() const;
    QPixmap generatePixmap() const;
    qreal infiniteAnimationValue() const;
    int visibleValue() const;

    QColor m_color;
    int m_value, m_maximum, m_visibleValue;
    qreal m_innerRadius, m_outerRadius;
    qreal m_infiniteAnimationValue;
    QPropertyAnimation *m_valueAnimation, *m_infiniteAnimation;

};

#endif // TTKCIRCLEPROCESSWIDGET_H
