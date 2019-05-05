#ifndef TTKTOASTLABEL_H
#define TTKTOASTLABEL_H

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
#include <QTimer>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKToastLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKToastLabel)
public:
    explicit TTKToastLabel(QWidget *parent = nullptr);
    explicit TTKToastLabel(const QString &text, QWidget *parent = nullptr);
    virtual ~TTKToastLabel();

    void setFontMargin(int height, int width);

    void setTimerInterval(int msecond);
    int getTimerInterval() const;

    void setFontSize(int size);
    int getFontSize() const;

    void setBold(bool bold);
    bool bold() const;

    void popup(QWidget *parent);

public Q_SLOTS:
    void setText(const QString &text);

private Q_SLOTS:
    void updateRender();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    QTimer m_timer;
    QFont m_font;
    QPoint m_margin;

};

#endif // TTKTOASTLABEL_H
