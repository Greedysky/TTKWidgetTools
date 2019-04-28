#ifndef TTKTOOLSAPPLICATION_H
#define TTKTOOLSAPPLICATION_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QLabel>
#include "ttkmoveresizewidget.h"

namespace Ui {
class TTKToolsApplication;
}

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKToolsApplication : public TTKMoveResizeWidget
{
    Q_OBJECT
public:
    explicit TTKToolsApplication(QWidget *parent = nullptr);
    ~TTKToolsApplication();

private Q_SLOTS:
    void buttonModuleChanged(int index);
    void labelModuleChanged(int index);
    void lineEditModuleChanged(int index);
    void meterModuleChanged(int index);
    void progressModuleChanged(int index);
    void sliderModuleChanged(int index);
    void titleModuleChanged(int index);
    void widgetModuleChanged(int index);
    void windowModuleChanged(int index);

private:
    void createButtonModule();
    void createLabelModule();
    void createLineEditModule();
    void createMeterModule();
    void createProgressModule();
    void createSliderModule();
    void createTitleModule();
    void createWidgetModule();
    void createWindowModule();

private:
    Ui::TTKToolsApplication *ui;

};

#endif // TTKTOOLSAPPLICATION_H
