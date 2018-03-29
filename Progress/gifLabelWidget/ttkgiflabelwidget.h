#ifndef TTKGifLabelWidget_H
#define TTKGifLabelWidget_H

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

#include <QLabel>
#include "ttkglobaldefine.h"

class QTimer;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_EXTRAS_EXPORT TTKGifLabelWidget : public QLabel
{
    Q_OBJECT
public:
    enum Type
    {
        Gif_Ballon_White,
        Gif_Cicle_Blue,
        Gif_Rice_Font_White,
        Gif_Rice_Font_Black,
        Gif_Rice_Font_Black_Big,
        Gif_Hourglass_White,
        Gif_Radio_Blue,
        Gif_Check_Blue,
        Gif_Record_red,
        Gif_Close_White
    };

    explicit TTKGifLabelWidget(QWidget *parent = 0);
    explicit TTKGifLabelWidget(Type type, QWidget *parent = 0);

    ~TTKGifLabelWidget();

    void setType(Type type);
    Type getType() const;

    void setInterval(int value);
    int getInterval() const;

    void setInfinited(bool s);
    bool getInfinited() const;

    void run(bool run);

    void start();
    void stop();

    inline bool isRunning() const { return m_isRunning; }

public Q_SLOTS:
    void timeout();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    bool infinitedModeCheck();

    int m_index;
    Type m_type;
    QTimer *m_timer;
    QPixmap m_renderer;
    bool m_isRunning, m_infinited;

};

#endif // TTKGifLabelWidget_H
