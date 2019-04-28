# =================================================
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2019 Greedysky Studio
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
# =================================================

QT       += core gui
equals(QT_MAJOR_VERSION, 4){
CONFIG   += gcc
}
equals(QT_MAJOR_VERSION, 5){
QT       += widgets
}

UI_DIR = ./.build/ui
MOC_DIR = ./.build/moc
OBJECTS_DIR = ./.build/obj
RCC_DIR = ./.build/rcc

include(TTKVersion.pri)

win32{
    equals(QT_MAJOR_VERSION, 5){
        msvc{
            CONFIG +=c++11
            !contains(QMAKE_TARGET.arch, x86_64){
                 #support on windows XP
                 QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
                 QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01
            }
        }

        gcc{
            QMAKE_CXXFLAGS += -std=c++11
            QMAKE_CXXFLAGS += -Wunused-function
            QMAKE_CXXFLAGS += -Wswitch
        }
    }

    equals(QT_MAJOR_VERSION, 4){
        gcc{
            QMAKE_CXXFLAGS += -std=c++11
            QMAKE_CXXFLAGS += -Wunused-function
            QMAKE_CXXFLAGS += -Wswitch
        }
    }
}

unix:!mac{
    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_CXXFLAGS += -Wunused-function
    QMAKE_CXXFLAGS += -Wswitch
}

DEFINES += TTK_LIBRARY

#########################################
HEADERS += $$PWD/ttkglobal.h
HEADERS += $$PWD/ttkglobaldefine.h
INCLUDEPATH += $$PWD
#########################################
include(TTKModule/TTKModule.pri)
