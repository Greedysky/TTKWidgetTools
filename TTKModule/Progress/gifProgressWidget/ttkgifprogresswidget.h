#ifndef TTKGIFPROGRESSWIDGET_H
#define TTKGIFPROGRESSWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
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
        RecordRed,
        CloseWhite
    };

    explicit TTKGifProgressWidget(QWidget *parent = nullptr);
    explicit TTKGifProgressWidget(Module type, QWidget *parent = nullptr);
    ~TTKGifProgressWidget();

    /*!
     * Set the gif type.
     */
    void setType(Module type);
    /*!
     * Get the gif type.
     */
    Module type() const;

    /*!
     * Set the gif interval.
     */
    void setInterval(int msec);
    /*!
     * Get the gif interval.
     */
    int interval() const;

    /*!
     * Set the gif infinited mode.
     */
    void setInfinited(bool s);
    /*!
     * Get the gif infinited mode.
     */
    bool infinited() const;

    /*!
     * Execute the gif.
     */
    void execute(bool run);
    /*!
     * Get current running state.
     */
    inline bool isRunning() const { return m_isRunning; }

    /*!
     * Start the gif.
     */
    void start();
    /*!
     * Stop the gif.
     */
    void stop();

public Q_SLOTS:
    /*!
     * Change the current gif index.
     */
    void updateRender();

private:
    /*!
     * Override the widget event.
     */
    virtual void paintEvent(QPaintEvent *event) override final;
    /*!
     * Infinited mode check.
     */
    bool infinitedModeCheck();

    int m_index;
    Module m_type;
    QTimer *m_timer;
    QPixmap m_renderer;
    bool m_isRunning, m_infinited;

};

#endif // TTKGIFPROGRESSWIDGET_H
