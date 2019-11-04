#ifndef TTKCALENDARWIDGET_H
#define TTKCALENDARWIDGET_H

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
#include <QPushButton>
#include <QCalendarWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCalendarWidget)
public:
    explicit TTKCalendarWidget(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override;

private Q_SLOTS:
    void buttonClicked();
    void setDataLabelTimeText(int year, int month);

protected:
    virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;

private:
    void initControl();
    void initTopWidget();
    void initBottomWidget();

private:
    QPushButton *m_leftYearButton, *m_leftMonthButton;
    QPushButton *m_rightYearButton, *m_rightMonthButton;
    QLabel *m_dataLabel;
};

#endif // TTKCALENDARWIDGET_H
