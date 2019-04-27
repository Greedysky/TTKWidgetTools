#ifndef TTKPROPERTYWIDGET_H
#define TTKPROPERTYWIDGET_H

/* =================================================
 * This file is part of the TTK WidgetTools project
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
//
#include "qtpropertymanager.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"
#include "qtbuttonpropertybrowser.h"
#include "qtgroupboxpropertybrowser.h"

class TTK_CORE_EXPORT TTKPropertyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKPropertyWidget(QWidget *parent = nullptr);
    ~TTKPropertyWidget();

    QWidget* widget() const;

protected:
    QWidget *m_item;
    //
    QtBoolPropertyManager *m_boolManager;
    QtIntPropertyManager *m_intManager;
    QtStringPropertyManager *m_stringManager;
    QtSizePropertyManager *m_sizeManager;
    QtRectPropertyManager *m_rectManager;
    QtSizePolicyPropertyManager *m_sizePolicyManager;
    QtEnumPropertyManager *m_enumManager;
    QtColorPropertyManager *m_colorManager;
    //
    QtGroupPropertyManager *m_groupManager;
    //
    QtCheckBoxFactory *m_checkBoxFactory;
    QtSpinBoxFactory *m_spinBoxFactory;
    QtLineEditFactory *m_lineEditFactory;
    QtEnumEditorFactory *m_comboBoxFactory;
    //
    QtAbstractPropertyBrowser *m_browser;
};

#endif // TTKPROPERTYWIDGET_H
