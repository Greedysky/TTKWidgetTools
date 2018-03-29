#ifndef TTKPROCESSWIDGET_H
#define TTKPROCESSWIDGET_H

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

#include <QProgressBar>
#include "ttkglobaldefine.h"

class TTKProgressWidget;

/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKProgressDelegate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal offset WRITE setOffset READ offset)
public:
    TTKProgressDelegate(TTKProgressWidget *parent);

    void setOffset(qreal offset);
    inline qreal offset() const { return m_offset; }

private:
    TTKProgressWidget *m_progress;
    qreal m_offset;

};


/*!
 * @author Greedysky <greedysky@163.com>
 *   Heikki Johannes <hildenjohannes@gmail.com>
 */
class TTK_EXTRAS_EXPORT TTKProgressWidget : public QProgressBar
{
    Q_OBJECT
    Q_PROPERTY(QColor progressColor WRITE setProgressColor READ progressColor)
    Q_PROPERTY(QColor backgroundColor WRITE setProgressColor READ backgroundColor)
public:
    explicit TTKProgressWidget(QWidget *parent = 0);
    ~TTKProgressWidget();

    void setProgressColor(const QColor &color);
    QColor progressColor() const;

    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    TTKProgressDelegate *m_delegate;
    QColor m_progressColor, m_backgroundColor;

};


#endif // TTKPROCESSWIDGET_H
