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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_PROGRESS_INCLUDE_FILES
  ${TTK_MODULE_PROGRESS_DIR}/animationProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/circleProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/circleWaitProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/circularProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/donutWaitProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/gifProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/lineWaitProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/loadingProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/pieWaitProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/progressWidget
  ${TTK_MODULE_PROGRESS_DIR}/radiusProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/ringProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/ringsMapProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/ringsProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/roundProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/waveProgressWidget
  ${TTK_MODULE_PROGRESS_DIR}/zoomWaitProgressWidget
  ${TTK_EXAMPLE_PROGRESS_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_PROGRESS_HEADER_FILES
  ${TTK_EXAMPLE_PROGRESS_DIR}/animationProgressWidget/ttkanimationprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/circleProgressWidget/ttkcircleprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/circleWaitProgressWidget/ttkcirclewaitprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/circularProgressWidget/ttkcircularprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/donutWaitProgressWidget/ttkdonutwaitprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/gifProgressWidget/ttkgifprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/lineWaitProgressWidget/ttklinewaitprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/loadingProgressWidget/ttkloadingprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/pieWaitProgressWidget/ttkpiewaitprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/progressWidget/ttkprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/radiusProgressWidget/ttkradiusprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringProgressWidget/ttkringprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringsMapProgressWidget/ttkringsmapprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringsProgressWidget/ttkringsprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/roundProgressWidget/ttkroundprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/waveProgressWidget/ttkwaveprogresswidgetproperty.h
  ${TTK_EXAMPLE_PROGRESS_DIR}/zoomWaitProgressWidget/ttkzoomwaitprogresswidgetproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_PROGRESS_SOURCE_FILES
  ${TTK_EXAMPLE_PROGRESS_DIR}/animationProgressWidget/ttkanimationprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/circleProgressWidget/ttkcircleprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/circleWaitProgressWidget/ttkcirclewaitprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/circularProgressWidget/ttkcircularprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/donutWaitProgressWidget/ttkdonutwaitprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/gifProgressWidget/ttkgifprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/lineWaitProgressWidget/ttklinewaitprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/loadingProgressWidget/ttkloadingprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/pieWaitProgressWidget/ttkpiewaitprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/progressWidget/ttkprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/radiusProgressWidget/ttkradiusprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringProgressWidget/ttkringprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringsMapProgressWidget/ttkringsmapprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/ringsProgressWidget/ttkringsprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/roundProgressWidget/ttkroundprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/waveProgressWidget/ttkwaveprogresswidgetproperty.cpp
  ${TTK_EXAMPLE_PROGRESS_DIR}/zoomWaitProgressWidget/ttkzoomwaitprogresswidgetproperty.cpp
)
