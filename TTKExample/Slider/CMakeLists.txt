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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_SLIDER_INCLUDE_FILES
  ${TTK_MODULE_SLIDER_DIR}/movingLabelSlider
  ${TTK_MODULE_SLIDER_DIR}/shiningSlider
  ${TTK_MODULE_SLIDER_DIR}/styleSlider
  ${TTK_EXAMPLE_SLIDER_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_SLIDER_HEADER_FILES
  ${TTK_EXAMPLE_SLIDER_DIR}/movingLabelSlider/ttkmovinglabelsliderproperty.h
  ${TTK_EXAMPLE_SLIDER_DIR}/shiningSlider/ttkshiningsliderproperty.h
  ${TTK_EXAMPLE_SLIDER_DIR}/styleSlider/ttkstylesliderproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_SLIDER_SOURCE_FILES
  ${TTK_EXAMPLE_SLIDER_DIR}/movingLabelSlider/ttkmovinglabelsliderproperty.cpp
  ${TTK_EXAMPLE_SLIDER_DIR}/shiningSlider/ttkshiningsliderproperty.cpp
  ${TTK_EXAMPLE_SLIDER_DIR}/styleSlider/ttkstylesliderproperty.cpp
)
