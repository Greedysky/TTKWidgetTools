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

cmake_minimum_required(VERSION 3.0.0)

set_property(GLOBAL PROPERTY TTK_MODULE_BUTTON_INCLUDE_FILES
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget
)

set_property(GLOBAL PROPERTY TTK_MODULE_BUTTON_HEADER_FILES
  ${TTK_MODULE_BUTTON_DIR}/checkButtonWidget/ttkcheckbuttonwidget.h
  ${TTK_MODULE_BUTTON_DIR}/colorButtonWidget/ttkcolorbuttonwidget.h
  ${TTK_MODULE_BUTTON_DIR}/flatButtonWidget/ttkflatbuttonwidget.h
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget/ttkcheckable.h
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget/ttkradiobuttonwidget.h
  ${TTK_MODULE_BUTTON_DIR}/toggleWidget/ttktogglewidget.h
  ${TTK_MODULE_BUTTON_DIR}/toolMenuWidget/ttktoolmenuwidget.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_BUTTON_SOURCE_FILES
  ${TTK_MODULE_BUTTON_DIR}/checkButtonWidget/ttkcheckbuttonwidget.cpp
  ${TTK_MODULE_BUTTON_DIR}/colorButtonWidget/ttkcolorbuttonwidget.cpp
  ${TTK_MODULE_BUTTON_DIR}/flatButtonWidget/ttkflatbuttonwidget.cpp
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget/ttkcheckable.cpp
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget/ttkradiobuttonwidget.cpp
  ${TTK_MODULE_BUTTON_DIR}/toggleWidget/ttktogglewidget.cpp
  ${TTK_MODULE_BUTTON_DIR}/toolMenuWidget/ttktoolmenuwidget.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_BUTTON_QRC_FILES
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget/RadioButtonWidget.qrc
)
