#ifndef TTKSHININGSLIDERWIDGET_H
#define TTKSHININGSLIDERWIDGET_H

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
#include <QMouseEvent>
#include "ttkglobaldefine.h"

class TTKGifLabelWidget;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKShiningSliderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKShiningSliderWidget(QWidget *parent = 0);
    ~TTKShiningSliderWidget();

    void setPlayState(bool state);
    void setValue(qint64 value) const;
    void setRange(int min, int max);

public Q_SLOTS:
    void sliderMovedAt(int pos) const;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

    QSlider *m_slider;
    TTKGifLabelWidget *m_label;

};

#endif // TTKSHININGSLIDERWIDGET_H
