#ifndef TTKCLOUDPANELLABEL_H
#define TTKCLOUDPANELLABEL_H

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

#include <QWidget>
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKCloudPanelLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCloudPanelLabel)
public:
    enum CloudStyle
    {
        CloudStyleBlack = 0,
        CloudStyleWhite = 1,
        CloudStyleBlue = 2,
        CloudStylePurple = 3
	};

    explicit TTKCloudPanelLabel(QWidget *parent = nullptr);

    void setBgColor(const QColor &bgColor);
    void setBaseColor(const QColor &baseColor);

    void setArcColor(const QColor &arcColor);
    void setBorderColor(const QColor &borderColor);

    void setIconColor(const QColor &textColor);
    void setPressColor(const QColor &pressColor);

    void setCloudStyle(const CloudStyle cloudStyle);

Q_SIGNALS:
    void mousePressed(int position);

protected:
   virtual  void resizeEvent(QResizeEvent *event) override final;
#if TTK_QT_VERSION_CHECK(6,0,0)
    virtual void enterEvent(QEnterEvent *event) override final;
#else
    virtual void enterEvent(QEvent *event) override final;
#endif
    virtual void leaveEvent(QEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    void recalcLayout();
    bool isPointIn(const QPoint &pos, int &bp);
    void drawCircle(QPainter *painter, int radius, const QBrush &brush);
    void drawArc(QPainter *painter);
    void drawButton(QPainter *painter);

private:
    QColor m_bgColor;
    QColor m_baseColor;
    QColor m_arcColor;
    QColor m_borderColor;
    QColor m_iconColor;
    QColor m_pressColor;
    CloudStyle m_cloudStyle;

    bool m_enter;
    bool m_pressed;

    QPoint m_lastPoint;
    QRectF m_centerRect;
    QRectF m_leftRect;
    QRectF m_topRect;
    QRectF m_rightRect;
    QRectF m_bottomRect;
    QRectF m_leftTopRect;
    QRectF m_rightTopRect;
    QRectF m_leftBottomRect;
    QRectF m_rightBottomRect;
    QFont m_iconFont;

};

#endif // TTKCLOUDPANELLABEL_H
