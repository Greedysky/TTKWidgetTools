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

set_property(GLOBAL PROPERTY TTK_MODULE_PROGRESS_INCLUDE_FILES
  ${TTK_MODULE_PROGRESS_DIR}/gifProgressWidget
)

set_property(GLOBAL PROPERTY TTK_MODULE_PROGRESS_HEADER_FILES
  ${TTK_MODULE_PROGRESS_DIR}/animationProgressWidget/ttkanimationprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/circleProgressWidget/ttkcircleprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/circleWaitProgressWidget/ttkcirclewaitprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/circularProgressWidget/ttkcircularprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/donutWaitProgressWidget/ttkdonutwaitprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/gifProgressWidget/ttkgifprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/lineWaitProgressWidget/ttklinewaitprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/loadingProgressWidget/ttkloadingprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/pieWaitProgressWidget/ttkpiewaitprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/progressWidget/ttkprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/radiusProgressWidget/ttkradiusprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/ringProgressWidget/ttkringprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/ringsMapProgressWidget/ttkringsmapprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/ringsProgressWidget/ttkringsprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/roundProgressWidget/ttkroundprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/waveProgressWidget/ttkwaveprogresswidget.h
  ${TTK_MODULE_PROGRESS_DIR}/zoomWaitProgressWidget/ttkzoomwaitprogresswidget.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_PROGRESS_SOURCE_FILES
  ${TTK_MODULE_PROGRESS_DIR}/animationProgressWidget/ttkanimationprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/circleProgressWidget/ttkcircleprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/circleWaitProgressWidget/ttkcirclewaitprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/circularProgressWidget/ttkcircularprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/donutWaitProgressWidget/ttkdonutwaitprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/gifProgressWidget/ttkgifprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/lineWaitProgressWidget/ttklinewaitprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/loadingProgressWidget/ttkloadingprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/pieWaitProgressWidget/ttkpiewaitprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/progressWidget/ttkprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/radiusProgressWidget/ttkradiusprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/ringProgressWidget/ttkringprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/ringsMapProgressWidget/ttkringsmapprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/ringsProgressWidget/ttkringsprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/roundProgressWidget/ttkroundprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/waveProgressWidget/ttkwaveprogresswidget.cpp
  ${TTK_MODULE_PROGRESS_DIR}/zoomWaitProgressWidget/ttkzoomwaitprogresswidget.cpp
)

set_property(GLOBAL PROPERTY TTK_MODULE_PROGRESS_QRC_FILES
  ${TTK_MODULE_PROGRESS_DIR}/animationProgressWidget/AnimationProgressWidget.qrc
  ${TTK_MODULE_PROGRESS_DIR}/gifProgressWidget/GifProgressWidget.qrc
  ${TTK_MODULE_PROGRESS_DIR}/radiusProgressWidget/RadiusProgressWidget.qrc
  ${TTK_MODULE_PROGRESS_DIR}/ringsMapProgressWidget/RingsMapProgressWidget.qrc
)
