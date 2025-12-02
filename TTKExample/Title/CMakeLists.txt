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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_TITLE_INCLUDE_FILES
  ${TTK_MODULE_TITLE_DIR}/functionAnimationWidget
  ${TTK_MODULE_TITLE_DIR}/functionListHWidget
  ${TTK_MODULE_TITLE_DIR}/functionListVWidget
  ${TTK_MODULE_TITLE_DIR}/functionNavigationWidget
  ${TTK_MODULE_TITLE_DIR}/functionNormalWidget
  ${TTK_MODULE_TITLE_DIR}/functionToolboxWidget
  ${TTK_EXAMPLE_TITLE_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_TITLE_HEADER_FILES
  ${TTK_EXAMPLE_TITLE_DIR}/functionAnimationHWidget/ttkfunctionanimationhwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionAnimationVWidget/ttkfunctionanimationvwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionListHWidget/ttkfunctionlisthwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionListVWidget/ttkfunctionlistvwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionNavigationWidget/ttkfunctionnavigationwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionNormalWidget/ttkfunctionnormalwidgetproperty.h
  ${TTK_EXAMPLE_TITLE_DIR}/functionToolboxWidget/ttkfunctiontoolboxwidgetproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_TITLE_SOURCE_FILES
  ${TTK_EXAMPLE_TITLE_DIR}/functionAnimationHWidget/ttkfunctionanimationhwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionAnimationVWidget/ttkfunctionanimationvwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionListHWidget/ttkfunctionlisthwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionListVWidget/ttkfunctionlistvwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionNavigationWidget/ttkfunctionnavigationwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionNormalWidget/ttkfunctionnormalwidgetproperty.cpp
  ${TTK_EXAMPLE_TITLE_DIR}/functionToolboxWidget/ttkfunctiontoolboxwidgetproperty.cpp
)
