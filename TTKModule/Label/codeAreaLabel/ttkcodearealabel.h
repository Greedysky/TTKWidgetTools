#ifndef TTKCODEAREALABEL_H
#define TTKCODEAREALABEL_H

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
#include <QPainterPath>
#include "ttkglobaldefine.h"

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
    inline QString checkCode() const { return m_code; }

    void setCodeCount(int nCount);
    inline int codeCount() const { return m_codeCount; }

    void setNoisyPointCount(int nCount);
    inline int noisyPointCount() const { return m_noisyPointCount; }

    virtual QSize sizeHint() const override final;

protected:
    void drawOutline(QPainter &painter);
    void drawNoisyPoint(QPainter &painter);
    void drawConversion(QPainter &painter);
    virtual void paintEvent(QPaintEvent *event) override final;

    int m_noisyPointCount, m_converseRotate;
    int m_converseScale, m_codeCount;
    QString m_code;
    QStringList m_codeRange;
    QList<QPainterPath> m_codePic;
    QList<Qt::GlobalColor> m_codeColor;

};

#endif // TTKCODEAREALABEL_H
