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

include($$PWD/animationProgressWidget/AnimationProgressWidget.pri)
include($$PWD/circleProgressWidget/CircleProgressWidget.pri)
include($$PWD/circleWaitProgressWidget/CircleWaitProgressWidget.pri)
include($$PWD/circularProgressWidget/CircularProgressWidget.pri)
include($$PWD/gifProgressWidget/GifProgressWidget.pri)
include($$PWD/loadingProgressWidget/LoadingProgressWidget.pri)
include($$PWD/progressWidget/ProgressWidget.pri)
include($$PWD/radiusProgressWidget/RadiusProgressWidget.pri)
include($$PWD/ringsMapProgressWidget/RingsMapProgressWidget.pri)
include($$PWD/ringProgressWidget/RingProgressWidget.pri)
include($$PWD/ringsProgressWidget/RingsProgressWidget.pri)
include($$PWD/roundProgressWidget/RoundProgressWidget.pri)
include($$PWD/waveProgressWidget/WaveProgressWidget.pri)

INCLUDEPATH += \
    $$PWD/../ \
    $$PWD/../../TTKModule/Progress/animationProgressWidget \
    $$PWD/../../TTKModule/Progress/circleProgressWidget \
    $$PWD/../../TTKModule/Progress/circleWaitProgressWidget \
    $$PWD/../../TTKModule/Progress/circularProgressWidget \
    $$PWD/../../TTKModule/Progress/gifProgressWidget \
    $$PWD/../../TTKModule/Progress/loadingProgressWidget \
    $$PWD/../../TTKModule/Progress/progressWidget \
    $$PWD/../../TTKModule/Progress/radiusProgressWidget \
    $$PWD/../../TTKModule/Progress/ringsMapProgressWidget \
    $$PWD/../../TTKModule/Progress/ringProgressWidget \
    $$PWD/../../TTKModule/Progress/ringsProgressWidget \
    $$PWD/../../TTKModule/Progress/roundProgressWidget \
    $$PWD/../../TTKModule/Progress/waveProgressWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/Progress/animationProgressWidget/ttkanimationprogresswidget.h \
    $$PWD/../../TTKModule/Progress/circleProgressWidget/ttkcircleprogresswidget.h \
    $$PWD/../../TTKModule/Progress/circleWaitProgressWidget/ttkcirclewaitprogresswidget.h \
    $$PWD/../../TTKModule/Progress/circularProgressWidget/ttkcircularprogresswidget.h \
    $$PWD/../../TTKModule/Progress/gifProgressWidget/ttkgifprogresswidget.h \
    $$PWD/../../TTKModule/Progress/loadingProgressWidget/ttkloadingprogresswidget.h \
    $$PWD/../../TTKModule/Progress/progressWidget/ttkprogresswidget.h \
    $$PWD/../../TTKModule/Progress/radiusProgressWidget/ttkradiusprogresswidget.h \
    $$PWD/../../TTKModule/Progress/ringsMapProgressWidget/ttkringsmapprogresswidget.h \
    $$PWD/../../TTKModule/Progress/ringProgressWidget/ttkringprogresswidget.h \
    $$PWD/../../TTKModule/Progress/ringsProgressWidget/ttkringsprogresswidget.h \
    $$PWD/../../TTKModule/Progress/roundProgressWidget/ttkroundprogresswidget.h \
    $$PWD/../../TTKModule/Progress/waveProgressWidget/ttkwaveprogresswidget.h
}
