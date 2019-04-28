# =================================================
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2019 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# =================================================

INCLUDEPATH += $$PWD

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0

SOURCES += \
    $$PWD/qtpropertybrowser.cpp \
    $$PWD/qtpropertymanager.cpp \
    $$PWD/qteditorfactory.cpp \
    $$PWD/qtvariantproperty.cpp \
    $$PWD/qttreepropertybrowser.cpp \
    $$PWD/qtbuttonpropertybrowser.cpp \
    $$PWD/qtgroupboxpropertybrowser.cpp \
    $$PWD/qtpropertybrowserutils.cpp

HEADERS += \
    $$PWD/qtpropertybrowser.h \
    $$PWD/qtpropertymanager.h \
    $$PWD/qteditorfactory.h \
    $$PWD/qtvariantproperty.h \
    $$PWD/qttreepropertybrowser.h \
    $$PWD/qtbuttonpropertybrowser.h \
    $$PWD/qtgroupboxpropertybrowser.h \
    $$PWD/qtpropertybrowserutils_p.h

RESOURCES += $$PWD/qtpropertybrowser.qrc
