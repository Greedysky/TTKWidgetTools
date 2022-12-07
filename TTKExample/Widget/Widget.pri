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

include($$PWD/colorTableWidget/ColorTableWidget.pri)
include($$PWD/layoutAnimationWidget/LayoutAnimationWidget.pri)
include($$PWD/pictureBannerWidget/PictureBannerWidget.pri)
include($$PWD/pictureFlowWidget/PictureFlowWidget.pri)
include($$PWD/smoothMovingTableWidget/SmoothMovingTableWidget.pri)
include($$PWD/animationStackedWidget/AnimationStackedWidget.pri)
include($$PWD/animation2StackedWidget/Animation2StackedWidget.pri)
include($$PWD/grabItemWidget/GrabItemWidget.pri)
include($$PWD/customPieWidget/CustomPieWidget.pri)
include($$PWD/customRingWidget/CustomRingWidget.pri)
include($$PWD/calendarWidget/CalendarWidget.pri)
include($$PWD/puzzleWidget/PuzzleWidget.pri)

INCLUDEPATH += \
    $$PWD/ \
    $$PWD/../ \
    $$PWD/../../TTKModule/Widget/colorTableWidget \
    $$PWD/../../TTKModule/Widget/layoutAnimationWidget \
    $$PWD/../../TTKModule/Widget/pictureBannerWidget \
    $$PWD/../../TTKModule/Widget/pictureFlowWidget \
    $$PWD/../../TTKModule/Widget/smoothMovingTableWidget \
    $$PWD/../../TTKModule/Widget/animationStackedWidget \
    $$PWD/../../TTKModule/Widget/animation2StackedWidget \
    $$PWD/../../TTKModule/Widget/grabItemWidget \
    $$PWD/../../TTKModule/Widget/customPieWidget \
    $$PWD/../../TTKModule/Widget/customRingWidget \
    $$PWD/../../TTKModule/Widget/calendarWidget \
    $$PWD/../../TTKModule/Widget/puzzleWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Widget/colorTableWidget/ttkcolortablewidget.h \
    $$PWD/../../TTKModule/Widget/layoutAnimationWidget/ttklayoutanimationwidget.h \
    $$PWD/../../TTKModule/Widget/pictureBannerWidget/ttkpicturebannerwidget.h \
    $$PWD/../../TTKModule/Widget/pictureFlowWidget/ttkpictureflowwidget.h \
    $$PWD/../../TTKModule/Widget/smoothMovingTableWidget/ttksmoothmovingtablewidget.h \
    $$PWD/../../TTKModule/Widget/animationStackedWidget/ttkanimationstackedwidget.h \
    $$PWD/../../TTKModule/Widget/animation2StackedWidget/ttkanimation2stackedwidget.h \
    $$PWD/../../TTKModule/Widget/grabItemWidget/ttkgrabitemwidget.h \
    $$PWD/../../TTKModule/Widget/customPieWidget/ttkcustompiewidget.h \
    $$PWD/../../TTKModule/Widget/customRingWidget/ttkcustomringwidget.h \
    $$PWD/../../TTKModule/Widget/calendarWidget/ttkcalendarwidget.h \
    $$PWD/../../TTKModule/Widget/puzzleWidget/ttkpuzzlewidget.h
}
