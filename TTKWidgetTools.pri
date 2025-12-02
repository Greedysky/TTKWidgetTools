# ***************************************************************************
# * This file is part of the TTK Widget Tools project
# * Copyright (C) 2015 - 2026 Greedysky Studio
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

QT += core gui
equals(QT_MAJOR_VERSION, 4){ #Qt4
    CONFIG += gcc
}

greaterThan(QT_MAJOR_VERSION, 4){ #Qt5
    QT += widgets
}

include($$PWD/TTKVersion.pri)

DESTDIR = $$OUT_PWD/../bin/$$TTK_VERSION

win32{
    msvc{
        CONFIG += c++11
        !contains(QT_ARCH, "x86_64"){
             #support on windows XP
             QMAKE_LFLAGS_WINDOWS += /SUBSYSTEM:WINDOWS,5.01
             QMAKE_LFLAGS_CONSOLE += /SUBSYSTEM:CONSOLE,5.01
        }

        LIBS += -L$$DESTDIR -lTTKLibrary
    }

    gcc{
        equals(QT_MAJOR_VERSION, 6){ #Qt6
            QMAKE_CXXFLAGS += -std=c++17
        }else{
            QMAKE_CXXFLAGS += -std=c++11
        }

        QMAKE_CXXFLAGS += -Wunused-function -Wswitch
        LIBS += -L$$DESTDIR -lTTKLibrary
    }
}

unix:!mac{
    equals(QT_MAJOR_VERSION, 6){ #Qt6
        QMAKE_CXXFLAGS += -std=c++17
    }else{
        QMAKE_CXXFLAGS += -std=c++11
    }

    QMAKE_CXXFLAGS += -Wunused-function -Wswitch
    LIBS += -L$$DESTDIR -lTTKLibrary
}

DEFINES += TTK_LIBRARY

#########################################
include($$PWD/TTKCommon/TTKCommon.pri)
#########################################
