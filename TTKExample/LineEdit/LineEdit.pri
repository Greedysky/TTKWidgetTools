# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2026 Greedysky Studio
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

include($$PWD/lineEditWidget/LineEditWidget.pri)
include($$PWD/ipEditWidget/IpEditWidget.pri)

INCLUDEPATH += \
    $$PWD \
    $$PWD/.. \
    $$PWD/../../TTKModule/LineEdit/ipEditWidget \
    $$PWD/../../TTKModule/LineEdit/lineEditWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/LineEdit/ipEditWidget/ttkipeditwidget.h \
    $$PWD/../../TTKModule/LineEdit/lineEditWidget/ttklineeditwidget.h
}

HEADERS += $$PWD/ttklineeditinclude.h
