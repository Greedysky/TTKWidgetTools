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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_BUTTON_INCLUDE_FILES
  ${TTK_MODULE_BUTTON_DIR}/checkButtonWidget
  ${TTK_MODULE_BUTTON_DIR}/colorButtonWidget
  ${TTK_MODULE_BUTTON_DIR}/flatButtonWidget
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget
  ${TTK_MODULE_BUTTON_DIR}/radioButtonWidget
  ${TTK_MODULE_BUTTON_DIR}/toggleWidget
  ${TTK_MODULE_BUTTON_DIR}/toolMenuWidget
  ${TTK_EXAMPLE_BUTTON_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_BUTTON_HEADER_FILES
  ${TTK_EXAMPLE_BUTTON_DIR}/checkButtonWidget/ttkcheckbuttonwidgetproperty.h
  ${TTK_EXAMPLE_BUTTON_DIR}/colorButtonWidget/ttkcolorbuttonwidgetproperty.h
  ${TTK_EXAMPLE_BUTTON_DIR}/flatButtonWidget/ttkflatbuttonwidgetproperty.h
  ${TTK_EXAMPLE_BUTTON_DIR}/radioButtonWidget/ttkradiobuttonwidgetproperty.h
  ${TTK_EXAMPLE_BUTTON_DIR}/toggleWidget/ttktogglewidgetproperty.h
  ${TTK_EXAMPLE_BUTTON_DIR}/toolMenuWidget/ttktoolmenuwidgetproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_BUTTON_SOURCE_FILES
  ${TTK_EXAMPLE_BUTTON_DIR}/checkButtonWidget/ttkcheckbuttonwidgetproperty.cpp
  ${TTK_EXAMPLE_BUTTON_DIR}/colorButtonWidget/ttkcolorbuttonwidgetproperty.cpp
  ${TTK_EXAMPLE_BUTTON_DIR}/flatButtonWidget/ttkflatbuttonwidgetproperty.cpp
  ${TTK_EXAMPLE_BUTTON_DIR}/radioButtonWidget/ttkradiobuttonwidgetproperty.cpp
  ${TTK_EXAMPLE_BUTTON_DIR}/toggleWidget/ttktogglewidgetproperty.cpp
  ${TTK_EXAMPLE_BUTTON_DIR}/toolMenuWidget/ttktoolmenuwidgetproperty.cpp
)
