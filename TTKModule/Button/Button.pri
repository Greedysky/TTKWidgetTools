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

greaterThan(QT_MAJOR_VERSION, 5){
    equals(QT_MAJOR_VERSION, 6):equals(QT_MINOR_VERSION, 0){
        message(Qt6.0.x not support state machine module)
    }else{
        QT += statemachine
    }
}

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
