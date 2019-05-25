#ifndef TTKFUNCTIONANIMATIONHWIDGETPROPERTY_H
#define TTKFUNCTIONANIMATIONHWIDGETPROPERTY_H

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

#include "ttkwidgetproperty.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKOptionAnimationHWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKOptionAnimationHWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKOptionAnimationHWidgetProperty();

private Q_SLOTS:
    virtual void enumPropertyChanged(QtProperty *property, int value) override;

};



/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKTableAnimationHWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKTableAnimationHWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKTableAnimationHWidgetProperty();

private Q_SLOTS:
    virtual void enumPropertyChanged(QtProperty *property, int value) override;

};



/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKSkinAnimationHWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKSkinAnimationHWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKSkinAnimationHWidgetProperty();

private Q_SLOTS:
    virtual void enumPropertyChanged(QtProperty *property, int value) override;

};

#endif // TTKFUNCTIONANIMATIONHWIDGETPROPERTY_H
