#ifndef TTKLCDLABEL_H
#define TTKLCDLABEL_H

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
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKLcdLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKLcdLabel)
public:
    explicit TTKLcdLabel(QWidget *parent = nullptr);

    void setText(const QString &text);
    void setPixelSize(int size);
    void setSpacingSize(int size);

    void setTextColor(const QColor &color);
    void setPixelColor(const QColor &color);
    void setBackgroundColor(const QColor &color);

    virtual QSize sizeHint() const override final;

protected:
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    QImage generateDotMatrix(const QString &text);
    QImage generateDotMatrixImage(const QImage &source);
    QImage generateBackgroundDotMatrixImage();

private:
    QImage m_textImage;

    int m_pixelSize;
    int m_spacingSize;

    QColor m_textColor;
    QColor m_pixelColor;
    QColor m_backgroundColor;
};

#endif // TTKLCDLABEL_H
