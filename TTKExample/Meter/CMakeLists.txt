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

set_property(GLOBAL PROPERTY TTK_EXAMPLE_METER_INCLUDE_FILES
  ${TTK_MODULE_METER_DIR}/arcMeterWidget
  ${TTK_MODULE_METER_DIR}/carMeterWidget
  ${TTK_MODULE_METER_DIR}/clockMeterWidget
  ${TTK_MODULE_METER_DIR}/compassMeterWidget
  ${TTK_MODULE_METER_DIR}/dialMeterWidget
  ${TTK_MODULE_METER_DIR}/miniMeterWidget
  ${TTK_MODULE_METER_DIR}/paintMeterWidget
  ${TTK_MODULE_METER_DIR}/panelMeterWidget
  ${TTK_MODULE_METER_DIR}/percentMeterWidget
  ${TTK_MODULE_METER_DIR}/progressMeterWidget
  ${TTK_MODULE_METER_DIR}/radarMeterWidget
  ${TTK_MODULE_METER_DIR}/roundMeterWidget
  ${TTK_MODULE_METER_DIR}/speedMeterWidget
  ${TTK_MODULE_METER_DIR}/speedRingMeterWidget
  ${TTK_MODULE_METER_DIR}/temperatureMeterWidget
  ${TTK_MODULE_METER_DIR}/timeMeterWidget
  ${TTK_EXAMPLE_METER_DIR}
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_METER_HEADER_FILES
  ${TTK_EXAMPLE_METER_DIR}/arcMeterWidget/ttkarcmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/carMeterWidget/ttkcarmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/clockMeterWidget/ttkclockmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/compassMeterWidget/ttkcompassmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/dialMeterWidget/ttkdialmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/miniMeterWidget/ttkminimeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/paintMeterWidget/ttkpaintmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/panelMeterWidget/ttkpanelmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/percentMeterWidget/ttkpercentmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/progressMeterWidget/ttkprogressmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/radarMeterWidget/ttkradarmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/roundMeterWidget/ttkroundmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/speedMeterWidget/ttkspeedmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/speedRingMeterWidget/ttkspeedringmeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/temperatureMeterWidget/ttktemperaturemeterwidgetproperty.h
  ${TTK_EXAMPLE_METER_DIR}/timeMeterWidget/ttktimemeterwidgetproperty.h
)

set_property(GLOBAL PROPERTY TTK_EXAMPLE_METER_SOURCE_FILES
  ${TTK_EXAMPLE_METER_DIR}/arcMeterWidget/ttkarcmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/carMeterWidget/ttkcarmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/clockMeterWidget/ttkclockmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/compassMeterWidget/ttkcompassmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/dialMeterWidget/ttkdialmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/miniMeterWidget/ttkminimeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/paintMeterWidget/ttkpaintmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/panelMeterWidget/ttkpanelmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/percentMeterWidget/ttkpercentmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/progressMeterWidget/ttkprogressmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/radarMeterWidget/ttkradarmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/roundMeterWidget/ttkroundmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/speedMeterWidget/ttkspeedmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/speedRingMeterWidget/ttkspeedringmeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/temperatureMeterWidget/ttktemperaturemeterwidgetproperty.cpp
  ${TTK_EXAMPLE_METER_DIR}/timeMeterWidget/ttktimemeterwidgetproperty.cpp
)
