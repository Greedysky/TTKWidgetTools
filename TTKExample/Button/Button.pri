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

equals(QT_MAJOR_VERSION, 6):equals(QT_MINOR_VERSION, 0){
    message(Qt6.0.x not support state machine)
}else{
    include($$PWD/checkButtonWidget/CheckButtonWidget.pri)
    include($$PWD/radioButtonWidget/RadioButtonWidget.pri)
    include($$PWD/toggleWidget/ToggleWidget.pri)
}

include($$PWD/colorButtonWidget/ColorButtonWidget.pri)
include($$PWD/flatButtonWidget/FlatButtonWidget.pri)
include($$PWD/toolMenuWidget/ToolMenuWidget.pri)

INCLUDEPATH += \
    $$PWD \
    $$PWD/../ \
    $$PWD/../../TTKModule/Button/checkButtonWidget \
    $$PWD/../../TTKModule/Button/colorButtonWidget \
    $$PWD/../../TTKModule/Button/flatButtonWidget \
    $$PWD/../../TTKModule/Button/radioButtonWidget \
    $$PWD/../../TTKModule/Button/toggleWidget \
    $$PWD/../../TTKModule/Button/toolMenuWidget

win32:msvc{
    equals(QT_MAJOR_VERSION, 6):equals(QT_MINOR_VERSION, 0){
        message(Qt6.0.x not support state machine)
    }else{
        HEADERS += \
            $$PWD/../../TTKModule/Button/checkButtonWidget/ttkcheckbuttonwidget.h \
            $$PWD/../../TTKModule/Button/radioButtonWidget/ttkcheckable.h \
            $$PWD/../../TTKModule/Button/radioButtonWidget/ttkradiobuttonwidget.h \
            $$PWD/../../TTKModule/Button/toggleWidget/ttktogglewidget.h
    }
}

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Button/colorButtonWidget/ttkcolorbuttonwidget.h \
    $$PWD/../../TTKModule/Button/flatButtonWidget/ttkflatbuttonwidget.h \
    $$PWD/../../TTKModule/Button/toolMenuWidget/ttktoolmenuwidget.h
}

HEADERS += $$PWD/ttkbuttoninclude.h
