#ifndef TTKNETTRAFFICLABEL_H
#define TTKNETTRAFFICLABEL_H

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

#include <QLabel>
#include <QThread>
#include "ttkglobaldefine.h"

class QProcess;

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKNetTraffic : public QThread
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKNetTraffic)
public:
    /*!
     * Object contsructor.
     */
    explicit TTKNetTraffic(QObject *parent = nullptr);
    ~TTKNetTraffic();

    /*!
     * Set available newtwork name.
     */
    void setAvailableNewtworkName(const QString &name);
    /*!
     * Get newtwork names.
     */
    QStringList newtworkNames() const;
    /*!
     * Stop and quit current thread.
     */
    void stopAndQuitThread();
    /*!
     * Strat thread now.
     */
    void start();

Q_SIGNALS:
    /*!
     * Send current upload and download speed data.
     */
    void networkData(ulong upload, ulong download);

private Q_SLOTS:
    /*!
     * Get output recieved data on linux network.
     */
    void outputRecieved();

protected:
    /*!
     * Thread run now.
     */
    virtual void run() override;

protected:
    bool m_run;
    QString m_name;
    QProcess *m_process ;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKNetTrafficLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKNetTrafficLabel)
public:
    explicit TTKNetTrafficLabel(QWidget *parent = nullptr);
    ~TTKNetTrafficLabel();

    void setAvailableNewtworkName(const QString &name);
    QStringList newtworkNames() const;

    virtual QSize sizeHint() const override;
    QString size2Number(ulong size);

private Q_SLOTS:
    void setData(ulong upload, ulong download);

private:
    TTKNetTraffic *m_process;

};

#endif // TTKNETTRAFFICLABEL_H
