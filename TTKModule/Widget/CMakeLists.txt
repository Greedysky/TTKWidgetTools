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

set_property(GLOBAL PROPERTY TTK_MODULE_WIDGET_HEADER_FILES
  ${TTK_MODULE_WIDGET_DIR}/animation2StackedWidget/ttkanimation2stackedwidget.h
  ${TTK_MODULE_WIDGET_DIR}/animationStackedWidget/ttkanimationstackedwidget.h
  ${TTK_MODULE_WIDGET_DIR}/calendarWidget/ttkcalendarwidget.h
  ${TTK_MODULE_WIDGET_DIR}/colorTableWidget/ttkcolortablewidget.h
  ${TTK_MODULE_WIDGET_DIR}/customPieWidget/ttkcustompiewidget.h
  ${TTK_MODULE_WIDGET_DIR}/customRingWidget/ttkcustomringwidget.h
  ${TTK_MODULE_WIDGET_DIR}/grabItemWidget/ttkgrabitemwidget.h
  ${TTK_MODULE_WIDGET_DIR}/layoutAnimationWidget/ttklayoutanimationwidget.h
  ${TTK_MODULE_WIDGET_DIR}/pictureBannerWidget/ttkpicturebannerwidget.h
  ${TTK_MODULE_WIDGET_DIR}/pictureFlowWidget/ttkpictureflowwidget.h
  ${TTK_MODULE_WIDGET_DIR}/puzzleWidget/ttkpuzzlewidget.h
  ${TTK_MODULE_WIDGET_DIR}/smoothMovingTableWidget/ttksmoothmovingtablewidget.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_WIDGET_SOURCE_FILES
  ${TTK_MODULE_WIDGET_DIR}/animation2StackedWidget/ttkanimation2stackedwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/animationStackedWidget/ttkanimationstackedwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/calendarWidget/ttkcalendarwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/colorTableWidget/ttkcolortablewidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/customPieWidget/ttkcustompiewidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/customRingWidget/ttkcustomringwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/grabItemWidget/ttkgrabitemwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/layoutAnimationWidget/ttklayoutanimationwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/pictureBannerWidget/ttkpicturebannerwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/pictureFlowWidget/ttkpictureflowwidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/puzzleWidget/ttkpuzzlewidget.cpp
  ${TTK_MODULE_WIDGET_DIR}/smoothMovingTableWidget/ttksmoothmovingtablewidget.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_WIDGET_QRC_FILES
  ${TTK_MODULE_WIDGET_DIR}/colorTableWidget/ColorTableWidget.qrc
)
