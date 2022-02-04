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

TEMPLATE = app

equals(QT_MAJOR_VERSION, 4){
    CONFIG += gcc
}

include($$PWD/TTKExample.pri)
include($$PWD/../TTKWidgetTools.pri)
include($$PWD/../TTKUi/TTKUi.pri)

TARGET = TTKWidgetTools
LIBS += -L$$DESTDIR -lTTKCore

INCLUDEPATH += \
    $$PWD \
    $$PWD/../ \
    $$PWD/../TTKModule/Button/checkButtonWidget \
    $$PWD/../TTKModule/Button/colorButtonWidget \
    $$PWD/../TTKModule/Button/flatButtonWidget \
    $$PWD/../TTKModule/Button/radioButtonWidget \
    $$PWD/../TTKModule/Button/toggleWidget \
    $$PWD/../TTKModule/Button/toolMenuWidget \
    $$PWD/../TTKModule/Label/circleClickLabel \
    $$PWD/../TTKModule/Label/codeAreaLabel \
    $$PWD/../TTKModule/Label/ledPageLabel \
    $$PWD/../TTKModule/Label/marqueeLabel \
    $$PWD/../TTKModule/Label/roundAnimationLabel \
    $$PWD/../TTKModule/Label/splitItemLabel \
    $$PWD/../TTKModule/Label/toastLabel \
    $$PWD/../TTKModule/Label/transitionAnimationLabel \
    $$PWD/../TTKModule/Label/cloudPanelLabel \
    $$PWD/../TTKModule/Label/barRulerLabel \
    $$PWD/../TTKModule/Label/batteryLabel \
    $$PWD/../TTKModule/Label/cpuMemoryLabel \
    $$PWD/../TTKModule/Label/antLineLabel \
    $$PWD/../TTKModule/Label/tileBackgroundLabel \
    $$PWD/../TTKModule/Label/lightPointLabel \
    $$PWD/../TTKModule/Label/scanLabel \
    $$PWD/../TTKModule/Label/crossLineLabel \
    $$PWD/../TTKModule/Label/netTrafficLabel \
    $$PWD/../TTKModule/Label/heatMapLabel \
    $$PWD/../TTKModule/LineEdit/lineEditWidget \
    $$PWD/../TTKModule/LineEdit/ipEditWidget \
    $$PWD/../TTKModule/Meter/speedMeterWidget \
    $$PWD/../TTKModule/Meter/timeMeterWidget \
    $$PWD/../TTKModule/Meter/paintMeterWidget \
    $$PWD/../TTKModule/Meter/radarMeterWidget \
    $$PWD/../TTKModule/Meter/carMeterWidget \
    $$PWD/../TTKModule/Meter/speedRingMeterWidget \
    $$PWD/../TTKModule/Meter/dialMeterWidget \
    $$PWD/../TTKModule/Meter/compassMeterWidget \
    $$PWD/../TTKModule/Meter/progressMeterWidget \
    $$PWD/../TTKModule/Meter/percentMeterWidget \
    $$PWD/../TTKModule/Meter/arcMeterWidget \
    $$PWD/../TTKModule/Meter/panelMeterWidget \
    $$PWD/../TTKModule/Meter/miniMeterWidget \
    $$PWD/../TTKModule/Meter/roundMeterWidget \
    $$PWD/../TTKModule/Meter/clockMeterWidget \
    $$PWD/../TTKModule/Meter/temperatureMeterWidget \
    $$PWD/../TTKModule/Progress/animationProgressWidget \
    $$PWD/../TTKModule/Progress/circularProgressWidget \
    $$PWD/../TTKModule/Progress/gifProgressWidget \
    $$PWD/../TTKModule/Progress/circleProgressWidget \
    $$PWD/../TTKModule/Progress/progressWidget \
    $$PWD/../TTKModule/Progress/radiusProgressWidget \
    $$PWD/../TTKModule/Progress/ringsMapProgressWidget \
    $$PWD/../TTKModule/Progress/ringProgressWidget \
    $$PWD/../TTKModule/Progress/ringsProgressWidget \
    $$PWD/../TTKModule/Progress/roundProgressWidget \
    $$PWD/../TTKModule/Progress/loadingProgressWidget \
    $$PWD/../TTKModule/Progress/waveProgressWidget \
    $$PWD/../TTKModule/Slider/movingLabelSlider \
    $$PWD/../TTKModule/Slider/shiningSlider \
    $$PWD/../TTKModule/Slider/styleSlider \
    $$PWD/../TTKModule/Title/functionAnimationWidget \
    $$PWD/../TTKModule/Title/functionListHWidget \
    $$PWD/../TTKModule/Title/functionListVWidget \
    $$PWD/../TTKModule/Title/functionNavigationWidget \
    $$PWD/../TTKModule/Title/functionNormalWidget \
    $$PWD/../TTKModule/Title/functionToolboxWidget \
    $$PWD/../TTKModule/Widget/colorTableWidget \
    $$PWD/../TTKModule/Widget/layoutAnimationWidget \
    $$PWD/../TTKModule/Widget/pictureBannerWidget \
    $$PWD/../TTKModule/Widget/pictureFlowWidget \
    $$PWD/../TTKModule/Widget/smoothMovingTableWidget \
    $$PWD/../TTKModule/Widget/animationStackedWidget \
    $$PWD/../TTKModule/Widget/animation2StackedWidget \
    $$PWD/../TTKModule/Widget/grabItemWidget \
    $$PWD/../TTKModule/Widget/customPieWidget \
    $$PWD/../TTKModule/Widget/customRingWidget \
    $$PWD/../TTKModule/Widget/calendarWidget \
    $$PWD/../TTKModule/Widget/puzzleWidget \
    $$PWD/../TTKModule/Window/colorDialog \
    $$PWD/../TTKModule/Window/moveDialog \
    $$PWD/../TTKModule/Window/moveWidget \
    $$PWD/../TTKModule/Window/moveResizeWidget \
    $$PWD/../TTKModule/Window/splashScreen \
    $$PWD/../TTKModule/Window/anSplashScreen \
    $$PWD/../TTKModule/Window/notifyWindow

win32:msvc{
    equals(QT_MAJOR_VERSION, 6):equals(QT_MINOR_VERSION, 0){
        message(Qt6.0.x not support state machine)
    }else{
        HEADERS += \
            $$PWD/../TTKModule/Button/checkButtonWidget/ttkcheckbuttonwidget.h \
            $$PWD/../TTKModule/Button/radioButtonWidget/ttkcheckable.h \
            $$PWD/../TTKModule/Button/radioButtonWidget/ttkradiobuttonwidget.h \
            $$PWD/../TTKModule/Button/toggleWidget/ttktogglewidget.h
    }
}

win32:msvc{
HEADERS += \
    $$PWD/../TTKModule/Button/colorButtonWidget/ttkcolorbuttonwidget.h \
    $$PWD/../TTKModule/Button/flatButtonWidget/ttkflatbuttonwidget.h \
    $$PWD/../TTKModule/Button/toolMenuWidget/ttktoolmenuwidget.h \
    $$PWD/../TTKModule/Label/circleClickLabel/ttkcircleclicklabel.h \
    $$PWD/../TTKModule/Label/codeAreaLabel/ttkcodearealabel.h \
    $$PWD/../TTKModule/Label/ledPageLabel/ttkledpagelabel.h \
    $$PWD/../TTKModule/Label/marqueeLabel/ttkmarqueelabel.h \
    $$PWD/../TTKModule/Label/roundAnimationLabel/ttkroundanimationlabel.h \
    $$PWD/../TTKModule/Label/splitItemLabel/ttksplititemlabel.h \
    $$PWD/../TTKModule/Label/toastLabel/ttktoastlabel.h \
    $$PWD/../TTKModule/Label/transitionAnimationLabel/ttktransitionanimationlabel.h \
    $$PWD/../TTKModule/Label/cloudPanelLabel/ttkcloudpanellabel.h \
    $$PWD/../TTKModule/Label/barRulerLabel/ttkbarrulerlabel.h \
    $$PWD/../TTKModule/Label/batteryLabel/ttkbatterylabel.h \
    $$PWD/../TTKModule/Label/cpuMemoryLabel/ttkcpumemorylabel.h \
    $$PWD/../TTKModule/Label/antLineLabel/ttkantlinelabel.h \
    $$PWD/../TTKModule/Label/tileBackgroundLabel/ttktilebackgroundlabel.h \
    $$PWD/../TTKModule/Label/lightPointLabel/ttklightpointlabel.h \
    $$PWD/../TTKModule/Label/scanLabel/ttkscanlabel.h \
    $$PWD/../TTKModule/Label/crossLineLabel/ttkcrosslinelabel.h \
    $$PWD/../TTKModule/Label/netTrafficLabel/ttknettrafficlabel.h \
    $$PWD/../TTKModule/Label/heatMapLabel/ttkheatmaplabel.h \
    $$PWD/../TTKModule/LineEdit/lineEditWidget/ttklineeditwidget.h \
    $$PWD/../TTKModule/LineEdit/ipEditWidget/ttkipeditwidget.h \
    $$PWD/../TTKModule/Meter/speedMeterWidget/ttkspeedmeterwidget.h \
    $$PWD/../TTKModule/Meter/timeMeterWidget/ttktimemeterwidget.h \
    $$PWD/../TTKModule/Meter/paintMeterWidget/ttkpaintmeterwidget.h \
    $$PWD/../TTKModule/Meter/radarMeterWidget/ttkradarmeterwidget.h \
    $$PWD/../TTKModule/Meter/carMeterWidget/ttkcarmeterwidget.h \
    $$PWD/../TTKModule/Meter/speedRingMeterWidget/ttkspeedringmeterwidget.h \
    $$PWD/../TTKModule/Meter/dialMeterWidget/ttkdialmeterwidget.h \
    $$PWD/../TTKModule/Meter/compassMeterWidget/ttkcompassmeterwidget.h \
    $$PWD/../TTKModule/Meter/progressMeterWidget/ttkprogressmeterwidget.h \
    $$PWD/../TTKModule/Meter/percentMeterWidget/ttkpercentmeterwidget.h \
    $$PWD/../TTKModule/Meter/arcMeterWidget/ttkarcmeterwidget.h \
    $$PWD/../TTKModule/Meter/panelMeterWidget/ttkpanelmeterwidget.h \
    $$PWD/../TTKModule/Meter/miniMeterWidget/ttkminimeterwidget.h \
    $$PWD/../TTKModule/Meter/roundMeterWidget/ttkroundmeterwidget.h \
    $$PWD/../TTKModule/Meter/clockMeterWidget/ttkclockmeterwidget.h \
    $$PWD/../TTKModule/Meter/temperatureMeterWidget/ttktemperaturemeterwidget.h \
    $$PWD/../TTKModule/Progress/animationProgressWidget/ttkanimationprogresswidget.h \
    $$PWD/../TTKModule/Progress/circularProgressWidget/ttkcircularprogresswidget.h \
    $$PWD/../TTKModule/Progress/gifProgressWidget/ttkgifprogresswidget.h \
    $$PWD/../TTKModule/Progress/circleProgressWidget/ttkcircleprogresswidget.h \
    $$PWD/../TTKModule/Progress/progressWidget/ttkprogresswidget.h \
    $$PWD/../TTKModule/Progress/radiusProgressWidget/ttkradiusprogresswidget.h \
    $$PWD/../TTKModule/Progress/ringsMapProgressWidget/ttkringsmapprogresswidget.h \
    $$PWD/../TTKModule/Progress/ringProgressWidget/ttkringprogresswidget.h \
    $$PWD/../TTKModule/Progress/ringsProgressWidget/ttkringsprogresswidget.h \
    $$PWD/../TTKModule/Progress/roundProgressWidget/ttkroundprogresswidget.h \
    $$PWD/../TTKModule/Progress/loadingProgressWidget/ttkloadingprogresswidget.h \
    $$PWD/../TTKModule/Progress/waveProgressWidget/ttkwaveprogresswidget.h \
    $$PWD/../TTKModule/Slider/movingLabelSlider/ttkclickedslider.h \
    $$PWD/../TTKModule/Slider/movingLabelSlider/ttkmovinglabelslider.h \
    $$PWD/../TTKModule/Slider/shiningSlider/ttkshiningslider.h \
    $$PWD/../TTKModule/Slider/styleSlider/ttkstyleslider.h \
    $$PWD/../TTKModule/Title/functionAnimationWidget/ttkfunctionanimationwidget.h \
    $$PWD/../TTKModule/Title/functionListHWidget/ttkfunctionlisthwidget.h \
    $$PWD/../TTKModule/Title/functionListVWidget/ttkfunctionlistvwidget.h \
    $$PWD/../TTKModule/Title/functionNavigationWidget/ttkfunctionnavigationwidget.h \
    $$PWD/../TTKModule/Title/functionNormalWidget/ttkfunctionnormalwidget.h \
    $$PWD/../TTKModule/Title/functionToolboxWidget/ttkfunctiontoolboxwidget.h \
    $$PWD/../TTKModule/Widget/colorTableWidget/ttkcolortablewidget.h \
    $$PWD/../TTKModule/Widget/layoutAnimationWidget/ttklayoutanimationwidget.h \
    $$PWD/../TTKModule/Widget/pictureBannerWidget/ttkpicturebannerwidget.h \
    $$PWD/../TTKModule/Widget/pictureFlowWidget/ttkpictureflowwidget.h \
    $$PWD/../TTKModule/Widget/smoothMovingTableWidget/ttksmoothmovingtablewidget.h \
    $$PWD/../TTKModule/Widget/animationStackedWidget/ttkanimationstackedwidget.h \
    $$PWD/../TTKModule/Widget/animation2StackedWidget/ttkanimation2stackedwidget.h \
    $$PWD/../TTKModule/Widget/grabItemWidget/ttkgrabitemwidget.h \
    $$PWD/../TTKModule/Widget/customPieWidget/ttkcustompiewidget.h \
    $$PWD/../TTKModule/Widget/customRingWidget/ttkcustomringwidget.h \
    $$PWD/../TTKModule/Widget/calendarWidget/ttkcalendarwidget.h \
    $$PWD/../TTKModule/Widget/puzzleWidget/ttkpuzzlewidget.h \
    $$PWD/../TTKModule/Window/colorDialog/ttkcolordialog.h \
    $$PWD/../TTKModule/Window/moveDialog/ttkmovedialog.h \
    $$PWD/../TTKModule/Window/moveWidget/ttkmovewidget.h \
    $$PWD/../TTKModule/Window/moveResizeWidget/ttkmoveresizewidget.h \
    $$PWD/../TTKModule/Window/splashScreen/ttksplashscreen.h \
    $$PWD/../TTKModule/Window/anSplashScreen/ttkansplashscreen.h \
    $$PWD/../TTKModule/Window/notifyWindow/ttknotifywindow.h
}

HEADERS += \
    $$PWD/ttkwidgetproperty.h \
    $$PWD/ttkpropertycontainwidget.h \
    $$PWD/ttkfunctionitem.h \
    $$PWD/ttkbackgroundcontainer.h \
    $$PWD/ttkbackgroundwidget.h \
    $$PWD/ttktoolsapplication.h \
    $$PWD/../TTKCommon/ttkglobaldefine.h

SOURCES += \
    $$PWD/ttkwidgetproperty.cpp \
    $$PWD/ttkpropertycontainwidget.cpp \
    $$PWD/ttkfunctionitem.cpp \
    $$PWD/ttkbackgroundcontainer.cpp \
    $$PWD/ttkbackgroundwidget.cpp \
    $$PWD/ttktoolsapplication.cpp \
    $$PWD/main.cpp

FORMS += $$PWD/ttktoolsapplication.ui

RESOURCES += $$PWD/TTKExample.qrc

win32:RC_FILE = $$PWD/TTKExample.rc
