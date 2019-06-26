#ifndef TTKFUNCTIONNAVIGATIONBUTTON_H
#define TTKFUNCTIONNAVIGATIONBUTTON_H

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

#include <QPushButton>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_CORE_EXPORT TTKFunctionNavigationWidget : public QPushButton
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionNavigationWidget)
public:
    enum TextAlign
    {
        TextAlignLeft = 0x0001,
        TextAlignRight = 0x0002,
        TextAlignTop = 0x0020,
        TextAlignBottom = 0x0040,
        TextAlignCenter = 0x0004
    };

    enum TrianglePosition
    {
        TrianglePositionLeft,
        TrianglePositionRight,
        TrianglePositionTop,
        TrianglePositionBottom
    };

    enum IconPosition
    {
        IconPositionLeft,
        IconPositionRight,
        IconPositionTop,
        IconPositionBottom
    };

    enum LinePosition
    {
        LinePositionLeft,
        LinePositionRight,
        LinePositionTop,
        LinePositionBottom
    };

    explicit TTKFunctionNavigationWidget(QWidget *parent = nullptr);

    void setPaddingLeft(int paddingLeft);
    void setPaddingRight(int paddingRight);
    void setPaddingTop(int paddingTop);
    void setPaddingBottom(int paddingBottom);
    void setPadding(int padding);
    void setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom);

    void setTextAlign(TextAlign textAlign);

    void setShowTriangle(bool showTriangle);
    void setTriangleLen(int triangleLen);
    void setTrianglePosition(TrianglePosition trianglePosition);
    void setTriangleColor(const QColor &triangleColor);

    void setShowIcon(bool showIcon);
    void setIconSpace(int iconSpace);
    void setIconSize(const QSize &iconSize);
    void setIconNormal(const QPixmap &iconNormal);
    void setIconHover(const QPixmap &iconHover);
    void setIconCheck(const QPixmap &iconCheck);

    void setShowLine(bool showLine);
    void setLineSpace(int lineSpace);
    void setLineWidth(int lineWidth);
    void setLinePosition(LinePosition linePosition);
    void setLineColor(const QColor &lineColor);

    void setNormalBgColor(const QColor &normalBgColor);
    void setHoverBgColor(const QColor &hoverBgColor);
    void setCheckBgColor(const QColor &checkBgColor);

    void setNormalTextColor(const QColor &normalTextColor);
    void setHoverTextColor(const QColor &hoverTextColor);
    void setCheckTextColor(const QColor &checkTextColor);

    void setNormalBgBrush(const QBrush &normalBgBrush);
    void setHoverBgBrush(const QBrush &hoverBgBrush);
    void setCheckBgBrush(const QBrush &checkBgBrush);

    virtual QSize sizeHint() const override;

protected:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

protected:
    void drawBackground(QPainter *painter);
    void drawText(QPainter *painter);
    void drawIcon(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawTriangle(QPainter *painter);

private:
    int m_paddingLeft, m_paddingRight, m_paddingTop, m_paddingBottom;
    TextAlign m_textAlign;

    bool m_showTriangle;
    int m_triangleLen;
    TrianglePosition m_trianglePosition;
    QColor m_triangleColor;

    bool m_showIcon;
    int m_iconSpace;
    QSize m_iconSize;
    QPixmap m_iconNormal, m_iconHover, m_iconCheck;

    bool m_showLine;
    int m_lineSpace, m_lineWidth;
    LinePosition m_linePosition;
    QColor m_lineColor;

    QColor m_normalBgColor, m_hoverBgColor, m_checkBgColor;
    QColor m_normalTextColor, m_hoverTextColor, m_checkTextColor;

    QBrush m_normalBgBrush, m_hoverBgBrush, m_checkBgBrush;

    bool m_hover;
};

#endif // TTKFUNCTIONNAVIGATIONBUTTON_H
