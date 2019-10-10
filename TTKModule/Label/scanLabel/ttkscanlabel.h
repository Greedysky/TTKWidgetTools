#ifndef TTKSCANLABEL_H
#define TTKSCANLABEL_H

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
class TTK_CORE_EXPORT TTKScanLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKScanLabel)
public:
    struct RingData 
    {
        int m_radius;
        float m_width;
        int m_alpha;
    };

    explicit TTKScanLabel(QWidget *parent = nullptr);
    ~TTKScanLabel();

    void setImage(const QPixmap &image);
    void setImageRadius(int imageRadius);
    void setImageBorderWidth(int imageBorderWidth);
    void setImageBorderColor(const QColor &imageBorderColor);

    void setScanRadius(int scanRadius);
    void setScanWidth(int scanWidth);
    void setScanColor(const QColor &scanColor);

    void setRingRadius(int ringRadius);
    void setRingWidth(int ringWidth);
    void setRingColor(const QColor &ringColor);

    virtual QSize sizeHint() const override;

protected Q_SLOTS:
    void updateRender();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    void drawScan(QPainter *painter);
    void drawRing(QPainter *painter);
    void drawImage(QPainter *painter);

private:
    QPixmap m_image;

    int m_imageRadius;
    int m_scanRadius;
    int m_scanWidth;
    int m_ringRadius;
    int m_ringWidth;
    int m_scanDeg;
    int m_imageBorderWidth;

    QColor m_imageBorderColor;
    QColor m_scanColor;
    QColor m_ringColor;

    QList<RingData> m_rings;
    QTimer *m_circleTimer;
};

#endif // TTKSCANLABEL_H
