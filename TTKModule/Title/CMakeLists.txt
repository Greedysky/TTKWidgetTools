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

cmake_minimum_required(VERSION 3.0.0)

set_property(GLOBAL PROPERTY TTK_MODULE_TITLE_INCLUDE_FILES
  ${TTK_MODULE_TITLE_DIR}/functionListHWidget
)

set_property(GLOBAL PROPERTY TTK_MODULE_TITLE_HEADER_FILES
  ${TTK_MODULE_TITLE_DIR}/functionAnimationWidget/ttkfunctionanimationwidget.h
  ${TTK_MODULE_TITLE_DIR}/functionListHWidget/ttkfunctionlisthwidget.h
  ${TTK_MODULE_TITLE_DIR}/functionListVWidget/ttkfunctionlistvwidget.h
  ${TTK_MODULE_TITLE_DIR}/functionNavigationWidget/ttkfunctionnavigationwidget.h
  ${TTK_MODULE_TITLE_DIR}/functionNormalWidget/ttkfunctionnormalwidget.h
  ${TTK_MODULE_TITLE_DIR}/functionToolboxWidget/ttkfunctiontoolboxwidget.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_TITLE_SOURCE_FILES
  ${TTK_MODULE_TITLE_DIR}/functionAnimationWidget/ttkfunctionanimationwidget.cpp
  ${TTK_MODULE_TITLE_DIR}/functionListHWidget/ttkfunctionlisthwidget.cpp
  ${TTK_MODULE_TITLE_DIR}/functionListVWidget/ttkfunctionlistvwidget.cpp
  ${TTK_MODULE_TITLE_DIR}/functionNavigationWidget/ttkfunctionnavigationwidget.cpp
  ${TTK_MODULE_TITLE_DIR}/functionNormalWidget/ttkfunctionnormalwidget.cpp
  ${TTK_MODULE_TITLE_DIR}/functionToolboxWidget/ttkfunctiontoolboxwidget.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_TITLE_QRC_FILES
  ${TTK_MODULE_TITLE_DIR}/functionAnimationWidget/FunctionAnimationWidget.qrc
  ${TTK_MODULE_TITLE_DIR}/functionToolboxWidget/FunctionToolboxWidget.qrc
)
