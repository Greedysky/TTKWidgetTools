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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_LABEL_INCLUDE_FILES
  ${TTK_MODULE_LABEL_DIR}/antLineLabel
  ${TTK_MODULE_LABEL_DIR}/barRulerLabel
  ${TTK_MODULE_LABEL_DIR}/batteryLabel
  ${TTK_MODULE_LABEL_DIR}/circleClickLabel
  ${TTK_MODULE_LABEL_DIR}/cloudPanelLabel
  ${TTK_MODULE_LABEL_DIR}/codeAreaLabel
  ${TTK_MODULE_LABEL_DIR}/cpuMemoryLabel
  ${TTK_MODULE_LABEL_DIR}/crossLineLabel
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel
  ${TTK_MODULE_LABEL_DIR}/lcdLabel
  ${TTK_MODULE_LABEL_DIR}/ledPageLabel
  ${TTK_MODULE_LABEL_DIR}/lightPointLabel
  ${TTK_MODULE_LABEL_DIR}/marqueeLabel
  ${TTK_MODULE_LABEL_DIR}/netTrafficLabel
  ${TTK_MODULE_LABEL_DIR}/roundAnimationLabel
  ${TTK_MODULE_LABEL_DIR}/scanLabel
  ${TTK_MODULE_LABEL_DIR}/splitItemLabel
  ${TTK_MODULE_LABEL_DIR}/tileBackgroundLabel
  ${TTK_MODULE_LABEL_DIR}/toastLabel
  ${TTK_MODULE_LABEL_DIR}/transitionAnimationLabel
  ${TTK_EXAMPLE_LABEL_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_LABEL_HEADER_FILES
  ${TTK_EXAMPLE_LABEL_DIR}/antLineLabel/ttkantlinelabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/barRulerLabel/ttkbarrulerlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/batteryLabel/ttkbatterylabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/circleClickLabel/ttkcircleclicklabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/cloudPanelLabel/ttkcloudpanellabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/codeAreaLabel/ttkcodearealabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/cpuMemoryLabel/ttkcpumemorylabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/crossLineLabel/ttkcrosslinelabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/heatMapLabel/ttkheatmaplabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/lcdLabel/ttklcdlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/ledPageLabel/ttkledpagelabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/lightPointLabel/ttklightpointlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/marqueeLabel/ttkmarqueelabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/netTrafficLabel/ttknettrafficlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/roundAnimationLabel/ttkroundanimationlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/scanLabel/ttkscanlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/splitItemLabel/ttksplititemlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/tileBackgroundLabel/ttktilebackgroundlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/toastLabel/ttktoastlabelproperty.h
  ${TTK_EXAMPLE_LABEL_DIR}/transitionAnimationLabel/ttktransitionanimationlabelproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_LABEL_SOURCE_FILES
  ${TTK_EXAMPLE_LABEL_DIR}/antLineLabel/ttkantlinelabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/barRulerLabel/ttkbarrulerlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/batteryLabel/ttkbatterylabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/circleClickLabel/ttkcircleclicklabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/cloudPanelLabel/ttkcloudpanellabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/codeAreaLabel/ttkcodearealabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/cpuMemoryLabel/ttkcpumemorylabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/crossLineLabel/ttkcrosslinelabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/heatMapLabel/ttkheatmaplabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/lcdLabel/ttklcdlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/ledPageLabel/ttkledpagelabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/lightPointLabel/ttklightpointlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/marqueeLabel/ttkmarqueelabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/netTrafficLabel/ttknettrafficlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/roundAnimationLabel/ttkroundanimationlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/scanLabel/ttkscanlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/splitItemLabel/ttksplititemlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/tileBackgroundLabel/ttktilebackgroundlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/toastLabel/ttktoastlabelproperty.cpp
  ${TTK_EXAMPLE_LABEL_DIR}/transitionAnimationLabel/ttktransitionanimationlabelproperty.cpp
)
