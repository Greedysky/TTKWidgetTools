# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2024 Greedysky Studio
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

include($$PWD/colorDialog/ColorDialog.pri)
include($$PWD/moveDialog/MoveDialog.pri)
include($$PWD/moveWidget/MoveWidget.pri)
include($$PWD/moveResizeWidget/MoveResizeWidget.pri)
include($$PWD/splashScreen/SplashScreen.pri)
include($$PWD/anSplashScreen/AnSplashScreen.pri)
include($$PWD/notifyWindow/NotifyWindow.pri)

INCLUDEPATH += \
    $$PWD/ \
    $$PWD/../ \
    $$PWD/../../TTKModule/Window/colorDialog \
    $$PWD/../../TTKModule/Window/moveDialog \
    $$PWD/../../TTKModule/Window/moveWidget \
    $$PWD/../../TTKModule/Window/moveResizeWidget \
    $$PWD/../../TTKModule/Window/splashScreen \
    $$PWD/../../TTKModule/Window/anSplashScreen \
    $$PWD/../../TTKModule/Window/notifyWindow

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Window/colorDialog/ttkcolordialog.h \
    $$PWD/../../TTKModule/Window/moveDialog/ttkmovedialog.h \
    $$PWD/../../TTKModule/Window/moveWidget/ttkmovewidget.h \
    $$PWD/../../TTKModule/Window/moveResizeWidget/ttkmoveresizewidget.h \
    $$PWD/../../TTKModule/Window/splashScreen/ttksplashscreen.h \
    $$PWD/../../TTKModule/Window/anSplashScreen/ttkansplashscreen.h \
    $$PWD/../../TTKModule/Window/notifyWindow/ttknotifywindow.h
}
