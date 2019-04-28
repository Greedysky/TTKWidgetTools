#ifndef TTKPROPERTYWIDGET_H
#define TTKPROPERTYWIDGET_H

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

#include "ttkglobal.h"
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

    virtual void init();
    QWidget* widget() const;

private Q_SLOTS:
    virtual void boolPropertyChanged(QtProperty *property, bool value);
    virtual void intPropertyChanged(QtProperty *property, int value);
    virtual void stringPropertyChanged(QtProperty *property, const QString &value);
    virtual void sizePropertyChanged(QtProperty *property, const QSize &value);
    virtual void rectPropertyChanged(QtProperty *property, const QRect &value);
    virtual void sizePolicyPropertyChanged(QtProperty *property, const QSizePolicy &value);
    virtual void enumPropertyChanged(QtProperty *property, int value);
    virtual void colorPropertyChanged(QtProperty *property, const QColor &value);

public Q_SLOTS:
    void geometryChanged();

protected:
    QWidget *m_item, *m_containItem;
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
    QtColorEditorFactory *m_colorEditorFactory;
    //
    QtAbstractPropertyBrowser *m_browser;
};

#endif // TTKPROPERTYWIDGET_H
