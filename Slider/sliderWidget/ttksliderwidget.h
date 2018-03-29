#ifndef TTKSLIDERWIDGET_H
#define TTKSLIDERWIDGET_H

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

#include <QSlider>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKSliderWidget : public QSlider
{
    Q_OBJECT
public:
    explicit TTKSliderWidget(QWidget *parent = 0);

    void setHandleColor(const QColor &color);
    inline QColor handleColor() const { return m_handleColor; }

    void setForegroundColor(const QColor &color);
    inline QColor foregroundColor() const { return m_foregroundColor; }

    void setBackgroundColor(const QColor &color);
    inline QColor backgroundColor() const { return m_backgroundColor; }

public Q_SLOTS:
    void setOrientation(Qt::Orientation orientation);

protected:
    void setupProperties();

    QColor m_handleColor, m_backgroundColor, m_foregroundColor;

};

#endif // TTKSLIDERWIDGET_H
