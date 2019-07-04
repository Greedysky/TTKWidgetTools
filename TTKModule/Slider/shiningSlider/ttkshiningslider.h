#ifndef TTKSHININGSLIDER_H
#define TTKSHININGSLIDER_H

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

#include <QSlider>
#include <QMouseEvent>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class TTKGifProgressWidget;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKShiningSlider : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKShiningSlider)
public:
    explicit TTKShiningSlider(QWidget *parent = nullptr);
    virtual ~TTKShiningSlider();

    void setPlayState(bool state);
    void setValue(qint64 value);

    void setRange(int min, int max);
    void setMinimum(int min);
    void setMaximum(int max);

    virtual QSize sizeHint() const override;

public Q_SLOTS:
    void sliderMovedAt(int pos) const;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;

    QSlider *m_slider;
    TTKGifProgressWidget *m_label;

};

#endif // TTKSHININGSLIDER_H
