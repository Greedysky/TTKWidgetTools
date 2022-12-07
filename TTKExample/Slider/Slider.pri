# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2022 Greedysky Studio
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

include($$PWD/movingLabelSlider/MovingLabelSlider.pri)
include($$PWD/shiningSlider/ShiningSlider.pri)
include($$PWD/styleSlider/StyleSlider.pri)

INCLUDEPATH += \
    $$PWD/../ \
    $$PWD/../../TTKModule/Slider/movingLabelSlider \
    $$PWD/../../TTKModule/Slider/shiningSlider \
    $$PWD/../../TTKModule/Slider/styleSlider

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Slider/movingLabelSlider/ttkclickedslider.h \
    $$PWD/../../TTKModule/Slider/movingLabelSlider/ttkmovinglabelslider.h \
    $$PWD/../../TTKModule/Slider/shiningSlider/ttkshiningslider.h \
    $$PWD/../../TTKModule/Slider/styleSlider/ttkstyleslider.h
}
