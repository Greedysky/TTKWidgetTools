#ifndef TTKLEDPAGELABEL_H
#define TTKLEDPAGELABEL_H

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

#include <QWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_CORE_EXPORT TTKLedPageLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKLedPageLabel)
public:
    explicit TTKLedPageLabel(QWidget *parent = nullptr);

    void setFrontColor(const QColor&);
    void setBackColor(const QColor&);
    void setLineColor(const QColor&);

    void setScale(float scale);
    void setText(const QString &text);
    void setFontSize(int size);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    void drawBack(QPainter &painter);
    void drawText(QPainter &painter);
    void drawLine(QPainter &painter);

private:
    QColor m_frontColor, m_backColor, m_lineColor;
    QString m_text;
    float m_width, m_height, m_scale;
    int m_fontSize;
};

#endif // TTKLEDPAGELABEL_H
