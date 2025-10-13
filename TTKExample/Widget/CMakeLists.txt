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

cmake_minimum_required(VERSION 3.18.0)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WIDGET_INCLUDE_FILES
  ${TTK_MODULE_WIDGET_DIR}/animation2StackedWidget
  ${TTK_MODULE_WIDGET_DIR}/animationStackedWidget
  ${TTK_MODULE_WIDGET_DIR}/calendarWidget
  ${TTK_MODULE_WIDGET_DIR}/colorTableWidget
  ${TTK_MODULE_WIDGET_DIR}/customPieWidget
  ${TTK_MODULE_WIDGET_DIR}/customRingWidget
  ${TTK_MODULE_WIDGET_DIR}/grabItemWidget
  ${TTK_MODULE_WIDGET_DIR}/layoutAnimationWidget
  ${TTK_MODULE_WIDGET_DIR}/pictureBannerWidget
  ${TTK_MODULE_WIDGET_DIR}/pictureFlowWidget
  ${TTK_MODULE_WIDGET_DIR}/puzzleWidget
  ${TTK_MODULE_WIDGET_DIR}/smoothMovingTableWidget
  ${TTK_EXAMPLE_WIDGET_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WIDGET_HEADER_FILES
  ${TTK_EXAMPLE_WIDGET_DIR}/animation2StackedWidget/ttkanimation2stackedwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/animationStackedWidget/ttkanimationstackedwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/calendarWidget/ttkcalendarwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/colorTableWidget/ttkcolortablewidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/customPieWidget/ttkcustompiewidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/customRingWidget/ttkcustomringwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/grabItemWidget/ttkgrabitemwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/layoutAnimationWidget/ttklayoutanimationwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/pictureBannerWidget/ttkpicturebannerwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/pictureFlowWidget/ttkpictureflowwidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/puzzleWidget/ttkpuzzlewidgetproperty.h
  ${TTK_EXAMPLE_WIDGET_DIR}/smoothMovingTableWidget/ttksmoothmovingtablewidgetproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_WIDGET_SOURCE_FILES
  ${TTK_EXAMPLE_WIDGET_DIR}/animation2StackedWidget/ttkanimation2stackedwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/animationStackedWidget/ttkanimationstackedwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/calendarWidget/ttkcalendarwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/colorTableWidget/ttkcolortablewidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/customPieWidget/ttkcustompiewidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/customRingWidget/ttkcustomringwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/grabItemWidget/ttkgrabitemwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/layoutAnimationWidget/ttklayoutanimationwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/pictureBannerWidget/ttkpicturebannerwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/pictureFlowWidget/ttkpictureflowwidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/puzzleWidget/ttkpuzzlewidgetproperty.cpp
  ${TTK_EXAMPLE_WIDGET_DIR}/smoothMovingTableWidget/ttksmoothmovingtablewidgetproperty.cpp
)
