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

class QTimer;

class TTKGifLabelWidget : public QLabel
{
    Q_OBJECT
public:
    enum Type
    {
        Gif_Ballon_White,           /*!< gif ballon white*/
        Gif_Cicle_Blue,             /*!< gif cicle blue*/
        Gif_Rice_Font_White,        /*!< gif rice font white*/
        Gif_Rice_Font_Black,        /*!< gif rice font black*/
        Gif_Rice_Font_Black_Big,    /*!< gif rice font black big*/
        Gif_Hourglass_White,        /*!< gif hourglass white*/
        Gif_Radio_Blue,             /*!< gif radio blue*/
        Gif_Check_Blue,             /*!< gif check blue*/
        Gif_Record_red,             /*!< gif record red*/
        Gif_Close_White             /*!< gif close white*/
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

    void start();
    void stop();

    inline bool isRunning() const { return m_isRunning; }

public Q_SLOTS:
    void timeout();

protected:
    bool infinitedModeCheck();

    int m_index;
    Type m_type;
    QTimer *m_timer;
    bool m_isRunning, m_infinited;

};

#endif // TTKGifLabelWidget_H
