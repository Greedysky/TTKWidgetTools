#ifndef TTKANSPLASHSCREEN_H
#define TTKANSPLASHSCREEN_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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

#include "ttkglobaldefine.h"

#include <QLabel>
#include <QGridLayout>

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAnSplashScreen : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAnSplashScreen)
public:
    explicit TTKAnSplashScreen(QWidget *parent = nullptr);
    ~TTKAnSplashScreen();

    void setWidget(QWidget *main);
    QWidget *widget();

    void setLoadText(const QString &title);
    void setLoadCount(int count);
    void start();

Q_SIGNALS:
    void finish();

private Q_SLOTS:
    void countTimeout();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    void initialize();
    void closeWidget();

private:
    QGridLayout *m_gridLayout;
    QLabel *m_numLabel;
    QLabel *m_textLabel;
    QWidget *m_mainWidget;

    QPoint m_mousePos;
    QTimer *m_loadTimer, *m_countTimer;

    int m_w, m_h;
    int m_dig, m_count;

};

#endif // TTKANSPLASHSCREEN_H
