#ifndef TTKTOASTLABEL_H
#define TTKTOASTLABEL_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

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
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_EXTRAS_EXPORT TTKToastLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TTKToastLabel(QWidget *parent = 0);
    explicit TTKToastLabel(const QString &text, QWidget *parent = 0);
    ~TTKToastLabel();

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
    void closeAnimation();

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    QTimer m_timer;
    QFont m_font;
    QPoint m_margin;

};

#endif // TTKTOASTLABEL_H
