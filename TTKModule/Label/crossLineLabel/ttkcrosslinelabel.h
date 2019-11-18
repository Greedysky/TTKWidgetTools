#ifndef TTKCROSSLINELABEL_H
#define TTKCROSSLINELABEL_H

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

#include <QWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class QProcess;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKCrossLineLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCrossLineLabel)
public:
    explicit TTKCrossLineLabel(QWidget *parent = nullptr);

    void setWidth(int w);
    void setColor(const QColor &color);

    virtual QSize sizeHint() const override;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

private:
    int m_width;
    QColor m_color;
    QPoint m_pos;

};

#endif // TTKCROSSLINELABEL_H
