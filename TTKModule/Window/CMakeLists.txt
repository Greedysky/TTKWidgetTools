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

cmake_minimum_required(VERSION 3.18.0)

set_property(GLOBAL PROPERTY TTK_MODULE_WINDOW_HEADER_FILES
  ${TTK_MODULE_WINDOW_DIR}/anSplashScreen/ttkansplashscreen.h
  ${TTK_MODULE_WINDOW_DIR}/colorDialog/ttkcolordialog.h
  ${TTK_MODULE_WINDOW_DIR}/moveDialog/ttkmovedialog.h
  ${TTK_MODULE_WINDOW_DIR}/moveResizeWidget/ttkmoveresizewidget.h
  ${TTK_MODULE_WINDOW_DIR}/moveWidget/ttkmovewidget.h
  ${TTK_MODULE_WINDOW_DIR}/notifyWindow/ttknotifywindow.h
  ${TTK_MODULE_WINDOW_DIR}/splashScreen/ttksplashscreen.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_WINDOW_SOURCE_FILES
  ${TTK_MODULE_WINDOW_DIR}/anSplashScreen/ttkansplashscreen.cpp
  ${TTK_MODULE_WINDOW_DIR}/colorDialog/ttkcolordialog.cpp
  ${TTK_MODULE_WINDOW_DIR}/moveDialog/ttkmovedialog.cpp
  ${TTK_MODULE_WINDOW_DIR}/moveResizeWidget/ttkmoveresizewidget.cpp
  ${TTK_MODULE_WINDOW_DIR}/moveWidget/ttkmovewidget.cpp
  ${TTK_MODULE_WINDOW_DIR}/notifyWindow/ttknotifywindow.cpp
  ${TTK_MODULE_WINDOW_DIR}/splashScreen/ttksplashscreen.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_WINDOW_QRC_FILES
  ${TTK_MODULE_WINDOW_DIR}/anSplashScreen/AnSplashScreen.qrc
  ${TTK_MODULE_WINDOW_DIR}/notifyWindow/NotifyWindow.qrc
)
