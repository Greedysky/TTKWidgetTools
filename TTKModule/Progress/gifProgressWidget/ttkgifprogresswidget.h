#ifndef TTKGIFPROGRESSWIDGET_H
#define TTKGIFPROGRESSWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

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

#include <QLabel>
#include "ttkmoduleexport.h"

class QTimer;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKGifProgressWidget : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKGifProgressWidget)
public:
    enum class Module
    {
        BallonWhite,
        CicleBlue,
        RiceFontWhite,
        RiceFontBlack,
        RiceFontBlackBig,
        HourglassWhite,
        RadioBlue,
        CheckBlue,
        Recordred,
        CloseWhite
    };

    explicit TTKGifProgressWidget(QWidget *parent = nullptr);
    explicit TTKGifProgressWidget(Module type, QWidget *parent = nullptr);
    ~TTKGifProgressWidget();

    void setType(Module type);
    void setInterval(int value);
    void setInfinited(bool s);

    void run(bool run);

    void start();
    void stop();

    inline bool isRunning() const { return m_isRunning; }

public Q_SLOTS:
    void updateRender();

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    bool infinitedModeCheck();

    int m_index;
    Module m_type;
    QTimer *m_timer;
    QPixmap m_renderer;
    bool m_isRunning, m_infinited;

};

#endif // TTKGIFPROGRESSWIDGET_H
