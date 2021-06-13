#ifndef TTKPUZZLEWIDGET_H
#define TTKPUZZLEWIDGET_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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

#include <QSlider>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPuzzleItemWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPuzzleItemWidget)
public:
    explicit TTKPuzzleItemWidget(QWidget *parent = nullptr);

    void setSquareWidth(int squareWidth);
    void setSquareRadius(int squareRadius);
    void setPixmap(const QString& pixmap);

public Q_SLOTS:
    void updatePixmap();
    void setValue(int value);

private:
    virtual void paintEvent(QPaintEvent *event) override;

    QString m_pixmap;
    QPoint m_offsetPoint;
    int m_value, m_squareWidth, m_squareRadius;

};



/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPuzzleWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPuzzleWidget)
public:
    explicit TTKPuzzleWidget(QWidget *parent = nullptr);

    void setSquareWidth(int squareWidth);
    void setSquareRadius(int squareRadius);
    void setPixmap(const QString& pixmap);

    virtual QSize sizeHint() const override;

private:
    QSlider *m_slider;
    TTKPuzzleItemWidget *m_item;

};

#endif // TTKPUZZLEWIDGET_H
