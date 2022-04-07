#ifndef TTKTOOLMENUWIDGET_H
#define TTKTOOLMENUWIDGET_H

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

#include <QMenu>
#include <QToolButton>
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKToolMenu : public QMenu
{
    Q_OBJECT
public:
    explicit TTKToolMenu(QWidget *parent = nullptr);

Q_SIGNALS:
    void windowStateChanged(bool state);

protected:
    virtual void showEvent(QShowEvent *event) override final;
    virtual void hideEvent(QHideEvent *event) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKToolMenuWidget : public QToolButton
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKToolMenuWidget)
public:
    explicit TTKToolMenuWidget(QWidget *parent = nullptr);
    ~TTKToolMenuWidget();

    void setTranslucentBackground();

public Q_SLOTS:
    void popupMenu();

protected:
    void initialize();

    TTKToolMenu *m_menu;
    QWidget *m_containWidget;

};

#endif // TTKTOOLMENUWIDGET_H
