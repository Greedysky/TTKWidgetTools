#ifndef TTKCPUMEMORYLABEL_H
#define TTKCPUMEMORYLABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QLabel>
#include "ttkmoduleexport.h"

class QProcess;

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKCPUMemoryLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCPUMemoryLabel)
public:
    explicit TTKCPUMemoryLabel(QWidget *parent = nullptr);
    ~TTKCPUMemoryLabel();

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void start(int interval);
    void stop();

private Q_SLOTS:
    void cpu();
    void memory();
    void readData();
    void setData();

private:
    int m_totalNew, m_idleNew, m_totalOld, m_idleOld;
    int m_cpuPercent;

    int m_memoryPercent;
    int m_memoryAll;
    int m_memoryUse;
    int m_memoryFree;

    QTimer *m_timerCPU;
    QTimer *m_timerMemory;
    QProcess *m_process;

};

#endif // TTKCPUMEMORYLABEL_H
