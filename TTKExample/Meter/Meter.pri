# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2023 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# ***************************************************************************

include($$PWD/speedMeterWidget/SpeedMeterWidget.pri)
include($$PWD/timeMeterWidget/TimeMeterWidget.pri)
include($$PWD/paintMeterWidget/PaintMeterWidget.pri)
include($$PWD/radarMeterWidget/RadarMeterWidget.pri)
include($$PWD/carMeterWidget/CarMeterWidget.pri)
include($$PWD/speedRingMeterWidget/SpeedRingMeterWidget.pri)
include($$PWD/dialMeterWidget/DialMeterWidget.pri)
include($$PWD/compassMeterWidget/CompassMeterWidget.pri)
include($$PWD/progressMeterWidget/ProgressMeterWidget.pri)
include($$PWD/percentMeterWidget/PercentMeterWidget.pri)
include($$PWD/arcMeterWidget/ArcMeterWidget.pri)
include($$PWD/panelMeterWidget/PanelMeterWidget.pri)
include($$PWD/miniMeterWidget/MiniMeterWidget.pri)
include($$PWD/roundMeterWidget/RoundMeterWidget.pri)
include($$PWD/clockMeterWidget/ClockMeterWidget.pri)
include($$PWD/temperatureMeterWidget/TemperatureMeterWidget.pri)

INCLUDEPATH += \
    $$PWD/ \
    $$PWD/../ \
    $$PWD/../../TTKModule/Meter/speedMeterWidget \
    $$PWD/../../TTKModule/Meter/timeMeterWidget \
    $$PWD/../../TTKModule/Meter/paintMeterWidget \
    $$PWD/../../TTKModule/Meter/radarMeterWidget \
    $$PWD/../../TTKModule/Meter/carMeterWidget \
    $$PWD/../../TTKModule/Meter/speedRingMeterWidget \
    $$PWD/../../TTKModule/Meter/dialMeterWidget \
    $$PWD/../../TTKModule/Meter/compassMeterWidget \
    $$PWD/../../TTKModule/Meter/progressMeterWidget \
    $$PWD/../../TTKModule/Meter/percentMeterWidget \
    $$PWD/../../TTKModule/Meter/arcMeterWidget \
    $$PWD/../../TTKModule/Meter/panelMeterWidget \
    $$PWD/../../TTKModule/Meter/miniMeterWidget \
    $$PWD/../../TTKModule/Meter/roundMeterWidget \
    $$PWD/../../TTKModule/Meter/clockMeterWidget \
    $$PWD/../../TTKModule/Meter/temperatureMeterWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Meter/speedMeterWidget/ttkspeedmeterwidget.h \
    $$PWD/../../TTKModule/Meter/timeMeterWidget/ttktimemeterwidget.h \
    $$PWD/../../TTKModule/Meter/paintMeterWidget/ttkpaintmeterwidget.h \
    $$PWD/../../TTKModule/Meter/radarMeterWidget/ttkradarmeterwidget.h \
    $$PWD/../../TTKModule/Meter/carMeterWidget/ttkcarmeterwidget.h \
    $$PWD/../../TTKModule/Meter/speedRingMeterWidget/ttkspeedringmeterwidget.h \
    $$PWD/../../TTKModule/Meter/dialMeterWidget/ttkdialmeterwidget.h \
    $$PWD/../../TTKModule/Meter/compassMeterWidget/ttkcompassmeterwidget.h \
    $$PWD/../../TTKModule/Meter/progressMeterWidget/ttkprogressmeterwidget.h \
    $$PWD/../../TTKModule/Meter/percentMeterWidget/ttkpercentmeterwidget.h \
    $$PWD/../../TTKModule/Meter/arcMeterWidget/ttkarcmeterwidget.h \
    $$PWD/../../TTKModule/Meter/panelMeterWidget/ttkpanelmeterwidget.h \
    $$PWD/../../TTKModule/Meter/miniMeterWidget/ttkminimeterwidget.h \
    $$PWD/../../TTKModule/Meter/roundMeterWidget/ttkroundmeterwidget.h \
    $$PWD/../../TTKModule/Meter/clockMeterWidget/ttkclockmeterwidget.h \
    $$PWD/../../TTKModule/Meter/temperatureMeterWidget/ttktemperaturemeterwidget.h
}
