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

set_property(GLOBAL PROPERTY TTK_MODULE_LABEL_INCLUDE_FILES
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap
)

set_property(GLOBAL PROPERTY TTK_MODULE_LABEL_HEADER_FILES
  ${TTK_MODULE_LABEL_DIR}/antLineLabel/ttkantlinelabel.h
  ${TTK_MODULE_LABEL_DIR}/barRulerLabel/ttkbarrulerlabel.h
  ${TTK_MODULE_LABEL_DIR}/batteryLabel/ttkbatterylabel.h
  ${TTK_MODULE_LABEL_DIR}/circleClickLabel/ttkcircleclicklabel.h
  ${TTK_MODULE_LABEL_DIR}/cloudPanelLabel/ttkcloudpanellabel.h
  ${TTK_MODULE_LABEL_DIR}/codeAreaLabel/ttkcodearealabel.h
  ${TTK_MODULE_LABEL_DIR}/cpuMemoryLabel/ttkcpumemorylabel.h
  ${TTK_MODULE_LABEL_DIR}/crossLineLabel/ttkcrosslinelabel.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/ttkheatmaplabel.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/heatmap.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/lodepng.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Blues.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BrBG.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BuGn.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BuPu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/GnBu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Gray.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Greens.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Greys.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Oranges.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/OrRd.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PiYG.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PRGn.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuBu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuBuGn.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuOr.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuRd.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Purples.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdBu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdGy.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdPu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdYlBu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdYlGn.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Reds.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Spectral.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlGn.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlGnBu.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlOrBr.h
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlOrRd.h
  ${TTK_MODULE_LABEL_DIR}/lcdLabel/ttklcdlabel.h
  ${TTK_MODULE_LABEL_DIR}/ledPageLabel/ttkledpagelabel.h
  ${TTK_MODULE_LABEL_DIR}/lightPointLabel/ttklightpointlabel.h
  ${TTK_MODULE_LABEL_DIR}/marqueeLabel/ttkmarqueelabel.h
  ${TTK_MODULE_LABEL_DIR}/netTrafficLabel/ttknettrafficlabel.h
  ${TTK_MODULE_LABEL_DIR}/roundAnimationLabel/ttkroundanimationlabel.h
  ${TTK_MODULE_LABEL_DIR}/scanLabel/ttkscanlabel.h
  ${TTK_MODULE_LABEL_DIR}/splitItemLabel/ttksplititemlabel.h
  ${TTK_MODULE_LABEL_DIR}/tileBackgroundLabel/ttktilebackgroundlabel.h
  ${TTK_MODULE_LABEL_DIR}/toastLabel/ttktoastlabel2.h
  ${TTK_MODULE_LABEL_DIR}/transitionAnimationLabel/ttktransitionanimationlabel.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_LABEL_SOURCE_FILES
  ${TTK_MODULE_LABEL_DIR}/antLineLabel/ttkantlinelabel.cpp
  ${TTK_MODULE_LABEL_DIR}/barRulerLabel/ttkbarrulerlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/batteryLabel/ttkbatterylabel.cpp
  ${TTK_MODULE_LABEL_DIR}/circleClickLabel/ttkcircleclicklabel.cpp
  ${TTK_MODULE_LABEL_DIR}/cloudPanelLabel/ttkcloudpanellabel.cpp
  ${TTK_MODULE_LABEL_DIR}/codeAreaLabel/ttkcodearealabel.cpp
  ${TTK_MODULE_LABEL_DIR}/cpuMemoryLabel/ttkcpumemorylabel.cpp
  ${TTK_MODULE_LABEL_DIR}/crossLineLabel/ttkcrosslinelabel.cpp
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/ttkheatmaplabel.cpp
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/heatmap.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/lodepng.cpp
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Blues.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BrBG.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BuGn.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/BuPu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/GnBu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Gray.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Greens.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Greys.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Oranges.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/OrRd.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PiYG.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PRGn.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuBu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuBuGn.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuOr.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/PuRd.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Purples.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdBu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdGy.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdPu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdYlBu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/RdYlGn.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Reds.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/Spectral.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlGn.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlGnBu.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlOrBr.c
  ${TTK_MODULE_LABEL_DIR}/heatMapLabel/heatmap/colorschemes/YlOrRd.c
  ${TTK_MODULE_LABEL_DIR}/lcdLabel/ttklcdlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/ledPageLabel/ttkledpagelabel.cpp
  ${TTK_MODULE_LABEL_DIR}/lightPointLabel/ttklightpointlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/marqueeLabel/ttkmarqueelabel.cpp
  ${TTK_MODULE_LABEL_DIR}/netTrafficLabel/ttknettrafficlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/roundAnimationLabel/ttkroundanimationlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/scanLabel/ttkscanlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/splitItemLabel/ttksplititemlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/tileBackgroundLabel/ttktilebackgroundlabel.cpp
  ${TTK_MODULE_LABEL_DIR}/toastLabel/ttktoastlabel2.cpp
  ${TTK_MODULE_LABEL_DIR}/transitionAnimationLabel/ttktransitionanimationlabel.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_LABEL_QRC_FILES
  ${TTK_MODULE_LABEL_DIR}/netTrafficLabel/NetTrafficLabel.qrc
  ${TTK_MODULE_LABEL_DIR}/roundAnimationLabel/RoundAnimationLabel.qrc
  ${TTK_MODULE_LABEL_DIR}/transitionAnimationLabel/TransitionAnimationLabel.qrc
)
