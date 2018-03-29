#ifndef TTKTOGGLEWIDGET_H
#define TTKTOGGLEWIDGET_H

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

#include <QAbstractButton>
#include "ttkglobaldefine.h"

class QState;
class QStateMachine;
class TTKToggleWidget;

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKToggleThumb : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal shift WRITE setShift READ shift)
    Q_PROPERTY(QColor thumbColor WRITE setThumbColor READ thumbColor)
public:
    explicit TTKToggleThumb(TTKToggleWidget *parent = 0);

    void setShift(qreal shift);

    inline qreal shift() const { return m_shift; }
    inline qreal offset() const { return m_offset; }

    void setThumbColor(const QColor &color);
    inline QColor thumbColor() const { return m_thumbColor; }

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    void updateOffset();

    TTKToggleWidget *m_toggle;
    QColor m_thumbColor;
    qreal m_shift, m_offset;

};


/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKToggleTrack : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor trackColor WRITE setTrackColor READ trackColor)
public:
    explicit TTKToggleTrack(TTKToggleWidget *parent = 0);

    void setTrackColor(const QColor &color);
    inline QColor trackColor() const { return m_trackColor; }

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    TTKToggleWidget *m_toggle;
    QColor m_trackColor;

};


/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKToggleWidget : public QAbstractButton
{
    Q_OBJECT
public:
    explicit TTKToggleWidget(QWidget *parent = 0);
    ~TTKToggleWidget();

    void setDisabledColor(const QColor &color);
    QColor disabledColor() const;

    void setActiveColor(const QColor &color);
    QColor activeColor() const;

    void setInactiveColor(const QColor &color);
    QColor inactiveColor() const;

    void setTrackColor(const QColor &color);
    QColor trackColor() const;

    void setOrientation(Qt::Orientation orientation);
    Qt::Orientation orientation() const;

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    void setupProperties();

    TTKToggleTrack *m_track;
    TTKToggleThumb *m_thumb;
    QStateMachine *m_stateMachine;
    QState *m_offState, *m_onState;
    Qt::Orientation m_orientation;
    QColor m_disabledColor, m_activeColor, m_inactiveColor, m_trackColor;

};

#endif // TTKTOGGLEWIDGET_H
