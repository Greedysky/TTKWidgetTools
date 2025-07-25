# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2025 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU Lesser General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU Lesser General Public License for more details.
#
# * You should have received a copy of the GNU Lesser General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# ***************************************************************************

include($$PWD/functionAnimationHWidget/FunctionAnimationHWidget.pri)
include($$PWD/functionAnimationVWidget/FunctionAnimationVWidget.pri)
include($$PWD/functionListHWidget/FunctionListHWidget.pri)
include($$PWD/functionListVWidget/FunctionListVWidget.pri)
include($$PWD/functionNavigationWidget/FunctionNavigationWidget.pri)
include($$PWD/functionNormalWidget/FunctionNormalWidget.pri)
include($$PWD/functionToolboxWidget/FunctionToolboxWidget.pri)

INCLUDEPATH += \
    $$PWD \
    $$PWD/../ \
    $$PWD/../../TTKModule/Title/functionAnimationWidget \
    $$PWD/../../TTKModule/Title/functionListHWidget \
    $$PWD/../../TTKModule/Title/functionListVWidget \
    $$PWD/../../TTKModule/Title/functionNavigationWidget \
    $$PWD/../../TTKModule/Title/functionNormalWidget \
    $$PWD/../../TTKModule/Title/functionToolboxWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Title/functionAnimationWidget/ttkfunctionanimationwidget.h \
    $$PWD/../../TTKModule/Title/functionListHWidget/ttkfunctionlisthwidget.h \
    $$PWD/../../TTKModule/Title/functionListVWidget/ttkfunctionlistvwidget.h \
    $$PWD/../../TTKModule/Title/functionNavigationWidget/ttkfunctionnavigationwidget.h \
    $$PWD/../../TTKModule/Title/functionNormalWidget/ttkfunctionnormalwidget.h \
    $$PWD/../../TTKModule/Title/functionToolboxWidget/ttkfunctiontoolboxwidget.h
}

HEADERS += $$PWD/ttktitleinclude.h
