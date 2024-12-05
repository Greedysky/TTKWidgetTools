#ifndef TTKCODEAREALABEL_H
#define TTKCODEAREALABEL_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

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
#include <QPainterPath>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKCodeAreaLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCodeAreaLabel)
public:
    explicit TTKCodeAreaLabel(QWidget *parent = nullptr);

    void renderPicture();
    void setCodeCount(int nCount);
    void setNoisyPointCount(int nCount);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawOutline(QPainter *painter);
    void drawNoisyPoint(QPainter *painter);
    void drawConversion(QPainter *painter);

    int m_noisyPointCount, m_converseRotate;
    int m_converseScale, m_codeCount;
    QString m_code;
    QStringList m_codeRange;
    QList<QPainterPath> m_codePic;
    QList<Qt::GlobalColor> m_codeColor;

};

#endif // TTKCODEAREALABEL_H
