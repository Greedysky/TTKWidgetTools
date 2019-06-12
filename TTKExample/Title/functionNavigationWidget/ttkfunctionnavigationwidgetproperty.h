#ifndef TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H
#define TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H

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

class TTKFunctionNavigationWidget;
/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKFunctionNavigationAWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationAWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKFunctionNavigationAWidgetProperty();

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override;
    virtual void intPropertyChanged(QtProperty *property, int value) override;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override;

private Q_SLOTS:
    void buttonClicked();

private:
    QList<TTKFunctionNavigationWidget*> buttons_;
};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKFunctionNavigationBWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationBWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKFunctionNavigationBWidgetProperty();

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override;
    virtual void intPropertyChanged(QtProperty *property, int value) override;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override;

private Q_SLOTS:
    void buttonClicked();

private:
    QList<TTKFunctionNavigationWidget*> buttons_;
};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKFunctionNavigationCWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationCWidgetProperty(QWidget *parent = nullptr);
    virtual ~TTKFunctionNavigationCWidgetProperty();

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override;
    virtual void intPropertyChanged(QtProperty *property, int value) override;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override;
    virtual void enumPropertyChanged(QtProperty *property, int value) override;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override;

private Q_SLOTS:
    void buttonClicked();

private:
    QList<TTKFunctionNavigationWidget*> buttons_;
};

#endif // TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H
