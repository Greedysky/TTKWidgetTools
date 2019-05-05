#ifndef TTKBACKGROUNDCONTAINER_H
#define TTKBACKGROUNDCONTAINER_H

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

#include "ttkgrabitemwidget.h"

class TTK_CORE_EXPORT TTKBackgroundContainerItem : public TTKGrabItemWidget
{
    Q_OBJECT
public:
    explicit TTKBackgroundContainerItem(QWidget *parent = nullptr);
    virtual ~TTKBackgroundContainerItem();

    void addItem(QWidget *item);

protected Q_SLOTS:
    virtual void onMouseChange(int x,int y);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    QWidget *m_item;
};


class TTK_CORE_EXPORT TTKBackgroundContainer : public QWidget
{
    Q_OBJECT
public:
    explicit TTKBackgroundContainer(QWidget *parent = nullptr);
    virtual ~TTKBackgroundContainer();

    void addItem(QWidget *item);

private:
    virtual void paintEvent(QPaintEvent *event) override;

    TTKBackgroundContainerItem *m_item;
};

#endif // TTKBACKGROUNDCONTAINER_H
