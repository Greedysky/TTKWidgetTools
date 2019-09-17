#ifndef TTKNOTIFYWINDOW_H
#define TTKNOTIFYWINDOW_H

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
#include <QQueue>
#include <QPushButton>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKNotify : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKNotify)
public:
    explicit TTKNotify(int time, QWidget *parent = nullptr);

    void setIcon(const QString &icon);
    void setTitle(const QString &title);
    void setBody(const QString &body);
    void setUrl(const QString &url);
    void showGriant();

Q_SIGNALS:
    void disappeared();

private Q_SLOTS:
    void hideGriant();
    void showGriantChanged();
    void hideGriantChanged();

private:
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    int m_displayTime;
    QString m_icon, m_title, m_body, m_url;

    QLabel *m_backgroundLabel, *m_iconLabel;
    QLabel *m_titleLabel, *m_bodyLabel;

    QPushButton *m_closeBtn;

};


typedef struct TTK_CORE_EXPORT TTKNotifyData
{
    QString m_title;
    QString m_body;
    QString m_icon;
    QString m_url;
} TTKNotifyData;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKNotifyManager : public QObject
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKNotifyManager)
public:
    explicit TTKNotifyManager(QObject *parent = nullptr);

    void notify(const QString &title, const QString &body, const QString &icon, const QString &url);

    void setMaxCount(int count);
    void setDisplayTime(int ms);

private Q_SLOTS:
    void disappeared();
    void rearrange();
    void showNext();

private:
    int m_maxCount;
    int m_displayTime;

    QQueue<TTKNotifyData> m_dataQueue;
    QList<TTKNotify*> m_notifyList;

};


#endif // TTKNOTIFYWINDOW_H
