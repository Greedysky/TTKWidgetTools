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

set_property(GLOBAL PROPERTY TTK_MODULE_METER_HEADER_FILES
  ${TTK_MODULE_METER_DIR}/arcMeterWidget/ttkarcmeterwidget.h
  ${TTK_MODULE_METER_DIR}/carMeterWidget/ttkcarmeterwidget.h
  ${TTK_MODULE_METER_DIR}/clockMeterWidget/ttkclockmeterwidget.h
  ${TTK_MODULE_METER_DIR}/compassMeterWidget/ttkcompassmeterwidget.h
  ${TTK_MODULE_METER_DIR}/dialMeterWidget/ttkdialmeterwidget.h
  ${TTK_MODULE_METER_DIR}/miniMeterWidget/ttkminimeterwidget.h
  ${TTK_MODULE_METER_DIR}/paintMeterWidget/ttkpaintmeterwidget.h
  ${TTK_MODULE_METER_DIR}/panelMeterWidget/ttkpanelmeterwidget.h
  ${TTK_MODULE_METER_DIR}/percentMeterWidget/ttkpercentmeterwidget.h
  ${TTK_MODULE_METER_DIR}/progressMeterWidget/ttkprogressmeterwidget.h
  ${TTK_MODULE_METER_DIR}/radarMeterWidget/ttkradarmeterwidget.h
  ${TTK_MODULE_METER_DIR}/roundMeterWidget/ttkroundmeterwidget.h
  ${TTK_MODULE_METER_DIR}/speedMeterWidget/ttkspeedmeterwidget.h
  ${TTK_MODULE_METER_DIR}/speedRingMeterWidget/ttkspeedringmeterwidget.h
  ${TTK_MODULE_METER_DIR}/temperatureMeterWidget/ttktemperaturemeterwidget.h
  ${TTK_MODULE_METER_DIR}/timeMeterWidget/ttktimemeterwidget.h
)

set_property(GLOBAL PROPERTY TTK_MODULE_METER_SOURCE_FILES
  ${TTK_MODULE_METER_DIR}/arcMeterWidget/ttkarcmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/carMeterWidget/ttkcarmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/clockMeterWidget/ttkclockmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/compassMeterWidget/ttkcompassmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/dialMeterWidget/ttkdialmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/miniMeterWidget/ttkminimeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/paintMeterWidget/ttkpaintmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/panelMeterWidget/ttkpanelmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/percentMeterWidget/ttkpercentmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/progressMeterWidget/ttkprogressmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/radarMeterWidget/ttkradarmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/roundMeterWidget/ttkroundmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/speedMeterWidget/ttkspeedmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/speedRingMeterWidget/ttkspeedringmeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/temperatureMeterWidget/ttktemperaturemeterwidget.cpp
  ${TTK_MODULE_METER_DIR}/timeMeterWidget/ttktimemeterwidget.cpp
)
