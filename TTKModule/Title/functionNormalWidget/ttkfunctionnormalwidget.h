#ifndef TTKFUNCTIONNORMALWIDGET_H
#define TTKFUNCTIONNORMALWIDGET_H

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
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

class QTimer;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKFunctionNormalWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionNormalWidget)
public:
    explicit TTKFunctionNormalWidget(QWidget *parent = nullptr);

    void setSize(qreal w, qreal h);
    void addItem(const QString &text);

protected Q_SLOTS:
    void updateRender();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void drawItem(QPainter *painter);
    void drawChooseItem(QPainter* painter);
    void drawListWidget(QPainter* painter);

    int m_height, m_width;
    int m_backGroundColor, m_oldChooseBackGround, m_newChooseBackGround;

    int m_itemOffset;
    int m_chooseIndex;

    QTimer* m_timer;
    QVector<QString> m_items;

};

#endif // TTKFUNCTIONNORMALWIDGET_H
