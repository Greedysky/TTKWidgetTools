# =================================================
# * This file is part of the TTK StackedWidget project
# * Copyright (c) 2015 - 2017 Greedysky Studio
# * All rights reserved!
# * Redistribution and use of the source code or any derivative
# * works are strictly forbiden.
# =================================================

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TTKStackedWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        animationstackedwidget.cpp

HEADERS  += mainwindow.h \
        animationstackedwidget.h

FORMS    += mainwindow.ui
