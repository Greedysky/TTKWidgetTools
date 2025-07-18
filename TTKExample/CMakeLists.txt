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

project(TTKWidgetTools)

add_subdirectory(Button)
add_subdirectory(Label)
add_subdirectory(LineEdit)
add_subdirectory(Meter)
add_subdirectory(Progress)
add_subdirectory(Slider)
add_subdirectory(Title)
add_subdirectory(Widget)
add_subdirectory(Window)


get_property(TTK_EXAMPLE_BUTTON_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_BUTTON_INCLUDE_FILES")
get_property(TTK_EXAMPLE_LABEL_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LABEL_INCLUDE_FILES")
get_property(TTK_EXAMPLE_LINEEDIT_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LINEEDIT_INCLUDE_FILES")
get_property(TTK_EXAMPLE_METER_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_METER_INCLUDE_FILES")
get_property(TTK_EXAMPLE_PROGRESS_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_PROGRESS_INCLUDE_FILES")
get_property(TTK_EXAMPLE_SLIDER_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_SLIDER_INCLUDE_FILES")
get_property(TTK_EXAMPLE_TITLE_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_TITLE_INCLUDE_FILES")
get_property(TTK_EXAMPLE_WIDGET_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WIDGET_INCLUDE_FILES")
get_property(TTK_EXAMPLE_WINDOW_INCLUDE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WINDOW_INCLUDE_FILES")

include_directories(
  ${TTK_EXAMPLE_BUTTON_INCLUDE_FILES}
  ${TTK_EXAMPLE_LABEL_INCLUDE_FILES}
  ${TTK_EXAMPLE_LINEEDIT_INCLUDE_FILES}
  ${TTK_EXAMPLE_METER_INCLUDE_FILES}
  ${TTK_EXAMPLE_PROGRESS_INCLUDE_FILES}
  ${TTK_EXAMPLE_SLIDER_INCLUDE_FILES}
  ${TTK_EXAMPLE_TITLE_INCLUDE_FILES}
  ${TTK_EXAMPLE_WIDGET_INCLUDE_FILES}
  ${TTK_EXAMPLE_WINDOW_INCLUDE_FILES}
)

get_property(TTK_EXAMPLE_BUTTON_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_BUTTON_HEADER_FILES")
get_property(TTK_EXAMPLE_LABEL_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LABEL_HEADER_FILES")
get_property(TTK_EXAMPLE_LINEEDIT_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LINEEDIT_HEADER_FILES")
get_property(TTK_EXAMPLE_METER_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_METER_HEADER_FILES")
get_property(TTK_EXAMPLE_PROGRESS_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_PROGRESS_HEADER_FILES")
get_property(TTK_EXAMPLE_SLIDER_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_SLIDER_HEADER_FILES")
get_property(TTK_EXAMPLE_TITLE_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_TITLE_HEADER_FILES")
get_property(TTK_EXAMPLE_WIDGET_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WIDGET_HEADER_FILES")
get_property(TTK_EXAMPLE_WINDOW_HEADER_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WINDOW_HEADER_FILES")

set(TTK_EXAMPLE_HEADER_FILES
  ${TTK_EXAMPLE_BUTTON_HEADER_FILES}
  ${TTK_EXAMPLE_LABEL_HEADER_FILES}
  ${TTK_EXAMPLE_LINEEDIT_HEADER_FILES}
  ${TTK_EXAMPLE_METER_HEADER_FILES}
  ${TTK_EXAMPLE_PROGRESS_HEADER_FILES}
  ${TTK_EXAMPLE_SLIDER_HEADER_FILES}
  ${TTK_EXAMPLE_TITLE_HEADER_FILES}
  ${TTK_EXAMPLE_WIDGET_HEADER_FILES}
  ${TTK_EXAMPLE_WINDOW_HEADER_FILES}
)

get_property(TTK_EXAMPLE_BUTTON_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_BUTTON_SOURCE_FILES")
get_property(TTK_EXAMPLE_LABEL_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LABEL_SOURCE_FILES")
get_property(TTK_EXAMPLE_LINEEDIT_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_LINEEDIT_SOURCE_FILES")
get_property(TTK_EXAMPLE_METER_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_METER_SOURCE_FILES")
get_property(TTK_EXAMPLE_PROGRESS_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_PROGRESS_SOURCE_FILES")
get_property(TTK_EXAMPLE_SLIDER_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_SLIDER_SOURCE_FILES")
get_property(TTK_EXAMPLE_TITLE_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_TITLE_SOURCE_FILES")
get_property(TTK_EXAMPLE_WIDGET_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WIDGET_SOURCE_FILES")
get_property(TTK_EXAMPLE_WINDOW_SOURCE_FILES GLOBAL PROPERTY "TTK_EXAMPLE_WINDOW_SOURCE_FILES")

set(TTK_EXAMPLE_SOURCE_FILES
  ${TTK_EXAMPLE_BUTTON_SOURCE_FILES}
  ${TTK_EXAMPLE_LABEL_SOURCE_FILES}
  ${TTK_EXAMPLE_LINEEDIT_SOURCE_FILES}
  ${TTK_EXAMPLE_METER_SOURCE_FILES}
  ${TTK_EXAMPLE_PROGRESS_SOURCE_FILES}
  ${TTK_EXAMPLE_SLIDER_SOURCE_FILES}
  ${TTK_EXAMPLE_TITLE_SOURCE_FILES}
  ${TTK_EXAMPLE_WIDGET_SOURCE_FILES}
  ${TTK_EXAMPLE_WINDOW_SOURCE_FILES}
)


include_directories(${TTK_COMMON_APP_DIR})

set(TTKAPPLICATION_HEADER_FILES
  ${TTK_COMMON_APP_DIR}/ttklocalpeer.h
  ${TTK_COMMON_APP_DIR}/ttkapplication.h
)

set(TTKAPPLICATION_SOURCE_FILES
  ${TTK_COMMON_APP_DIR}/ttklocalpeer.cpp
  ${TTK_COMMON_APP_DIR}/ttkapplication.cpp
)


include_directories(
  ${TTK_THIRDPARTY_DIR}
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser
)

set(TTK_THIRDPARTY_HEADER_FILES
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertybrowser.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertymanager.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qteditorfactory.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtvariantproperty.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qttreepropertybrowser.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtbuttonpropertybrowser.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtgroupboxpropertybrowser.h
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertybrowserutils_p.h
)

set(TTK_THIRDPARTY_SOURCE_FILES
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertybrowser.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertymanager.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qteditorfactory.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtvariantproperty.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qttreepropertybrowser.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtbuttonpropertybrowser.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtgroupboxpropertybrowser.cpp
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertybrowserutils.cpp
)

set(TTK_THIRDPARTY_QRC_FILES
  ${TTK_THIRDPARTY_DIR}/qtpropertybrowser/qtpropertybrowser.qrc
)


set(HEADER_FILES
  ${TTK_EXAMPLE_HEADER_FILES}
  ${TTKAPPLICATION_HEADER_FILES}
  ${TTK_THIRDPARTY_HEADER_FILES}
  ttkbackgroundcontainer.h
  ttkbackgroundwidget.h
  ttkfunctionitem.h
  ttkpropertycontainwidget.h
  ttktoolsapplication.h
  ttkbackgroundcontainer.h
  ttkwidgetproperty.h
)

set(SOURCE_FILES
  ${TTK_EXAMPLE_SOURCE_FILES}
  ${TTKAPPLICATION_SOURCE_FILES}
  ${TTK_THIRDPARTY_SOURCE_FILES}
  ttkbackgroundcontainer.cpp
  ttkbackgroundwidget.cpp
  ttkfunctionitem.cpp
  ttkpropertycontainwidget.cpp
  ttktoolsapplication.cpp
  ttkbackgroundcontainer.cpp
  ttkwidgetproperty.cpp
  main.cpp
)

set(UI_FILES
  ttktoolsapplication.ui
)

set(QRC_FILES
  ${TTK_THIRDPARTY_QRC_FILES}
  ${TTK_UI_DIR}/TTKModule.qrc
  TTKExample.qrc
)

set(CMAKE_AUTOMOC ON)

if(WIN32)
  list(APPEND SOURCE_FILES TTKExample.rc)
endif()

set(QT_LINK_LIBS TTKCore)

if(TTK_QT_VERSION VERSION_EQUAL "4")
  qt4_wrap_ui(UIC_FILES ${UI_FILES})
  qt4_add_resources(RCC_FILES ${QRC_FILES})

  list(APPEND QT_LINK_LIBS ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
elseif(TTK_QT_VERSION VERSION_EQUAL "5")
  qt5_wrap_ui(UIC_FILES ${UI_FILES})
  qt5_add_resources(RCC_FILES ${QRC_FILES})

  list(APPEND QT_LINK_LIBS Qt5::Core Qt5::Gui Qt5::Widgets)
elseif(TTK_QT_VERSION VERSION_EQUAL "6")
  qt6_wrap_ui(UIC_FILES ${UI_FILES})
  qt6_add_resources(RCC_FILES ${QRC_FILES})

  list(APPEND QT_LINK_LIBS Qt6::Core Qt6::Gui Qt6::Widgets)
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${UIC_FILES} ${RCC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_LINK_LIBS})
