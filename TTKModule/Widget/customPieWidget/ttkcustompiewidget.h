#ifndef TTKCUSTOMPIEWIDGET_H
#define TTKCUSTOMPIEWIDGET_H

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

#include <QListWidget>
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKCustomPieWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKCustomPieWidget)
public:
    typedef struct CustomPieData
    {
        QColor m_color;
        QString m_text;
        double m_value;
    }CustomPieData;

    explicit TTKCustomPieWidget(QWidget *parent = nullptr);

    void setExplodedAll(bool explodedAll);
    void setExplodedIndex(int index);

    void setTextColor(const QColor &textColor);
    void setBorderColor(const QColor &borderColor);

    void setDataPie(const QList<CustomPieData> &datas);

    void appendPie(const QString &label, double value, const QColor &color);

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void drawPie(QPainter *painter);

private:
    void clearPie();
    double getSumValue();
    QPoint getOffsetPoint(double angel, int offset);

private:
    bool m_explodedAll;
    int m_explodedIndex;
    bool m_showPercent;

    QColor m_textColor;
    QColor m_borderColor;
    QList<CustomPieData> m_datas;

};

#endif // TTKCUSTOMPIEWIDGET_H
