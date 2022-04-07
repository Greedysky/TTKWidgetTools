#ifndef TTKIPEDITWIDGET_H
#define TTKIPEDITWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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
 ***************************************************************************/

#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKIpEditWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKIpEditWidget)
public:
    explicit TTKIpEditWidget(QWidget *parent = nullptr);

    QString text() const;
    void setText(const QString &text);

    virtual QSize sizeHint() const override final;

protected:
    void initialize(QLineEdit *edit);
    QLineEdit *nextEdit(QLineEdit *edit);
    bool isEdit(QObject *object);

    virtual void paintEvent(QPaintEvent *event) override final;
    virtual bool eventFilter(QObject *object, QEvent *event) override final;

protected Q_SLOTS:
    void editTextChanged(const QString &text);

private:
    QBoxLayout *m_layout;
    QLineEdit *m_input_f, *m_input_s, *m_input_t, *m_input_l;
    QLabel *m_dot_f, *m_dot_s, *m_dot_t;
};

#endif // TTKIPEDITWIDGET_H
