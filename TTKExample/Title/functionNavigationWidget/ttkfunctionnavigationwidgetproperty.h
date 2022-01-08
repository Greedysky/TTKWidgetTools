#ifndef TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H
#define TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H

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

#include "ttkwidgetproperty.h"

class TTKFunctionNavigationWidget;
/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationWidgetProperty : public TTKWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    void buttonClicked();

protected:
    QList<TTKFunctionNavigationWidget*> m_buttons;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationAWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationAWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationBWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationBWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationCWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationCWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationDWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationDWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationEWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationEWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationFWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationFWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value) override final;
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKFunctionNavigationGWidgetProperty : public TTKFunctionNavigationWidgetProperty
{
    Q_OBJECT
public:
    explicit TTKFunctionNavigationGWidgetProperty(QWidget *parent = nullptr);

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value) override final;
    virtual void intPropertyChanged(QtProperty *property, int value) override final;
    virtual void enumPropertyChanged(QtProperty *property, int value) override final;
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value) override final;

private:
    QLinearGradient m_normal, m_hover, m_check;

};

#endif // TTKFUNCTIONNAVIGATIONWIDGETPROPERTY_H
