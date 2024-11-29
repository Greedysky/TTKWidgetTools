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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WINDOW_INCLUDE_FILES
  ${TTK_MODULE_WINDOW_DIR}/anSplashScreen
  ${TTK_MODULE_WINDOW_DIR}/colorDialog
  ${TTK_MODULE_WINDOW_DIR}/moveDialog
  ${TTK_MODULE_WINDOW_DIR}/moveResizeWidget
  ${TTK_MODULE_WINDOW_DIR}/moveWidget
  ${TTK_MODULE_WINDOW_DIR}/notifyWindow
  ${TTK_MODULE_WINDOW_DIR}/splashScreen
  ${TTK_EXAMPLE_WINDOW_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WINDOW_HEADER_FILES
  ${TTK_EXAMPLE_WINDOW_DIR}/anSplashScreen/ttkansplashscreenproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/colorDialog/ttkcolordialogproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/moveDialog/ttkmovedialogproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/moveResizeWidget/ttkmoveresizewidgetproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/moveWidget/ttkmovewidgetproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/notifyWindow/ttknotifywindowproperty.h
  ${TTK_EXAMPLE_WINDOW_DIR}/splashScreen/ttksplashscreenproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WINDOW_SOURCE_FILES
  ${TTK_EXAMPLE_WINDOW_DIR}/anSplashScreen/ttkansplashscreenproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/colorDialog/ttkcolordialogproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/moveDialog/ttkmovedialogproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/moveResizeWidget/ttkmoveresizewidgetproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/moveWidget/ttkmovewidgetproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/notifyWindow/ttknotifywindowproperty.cpp
  ${TTK_EXAMPLE_WINDOW_DIR}/splashScreen/ttksplashscreenproperty.cpp
)
