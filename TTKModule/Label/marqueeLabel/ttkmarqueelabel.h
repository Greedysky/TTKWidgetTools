#ifndef TTKMARQUEELABEL_H
#define TTKMARQUEELABEL_H

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
#include "ttkglobaldefine.h"

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKMarqueeLabel : public QWidget
{
    Q_OBJECT
    Q_ENUMS(MoveStyle)
    TTK_DECLARE_MODULE(TTKMarqueeLabel)
public:
    enum class MoveStyle
    {
        LeftAndRight = 0,
        LeftToRight = 1,
        RightToLeft = 2
    };

    explicit TTKMarqueeLabel(QWidget *parent = nullptr);
    ~TTKMarqueeLabel();

    void setText(const QString &text);
    void setStep(int step);
    void setInterval(int interval);

    void setMouseHoverStop(bool mouseHoverStop);

    void setForegroundColor(const QColor &foregroundColor);
    void setBackgroundColor(const QColor &backgroundColor);

    void setMoveStyle(MoveStyle moveStyle);

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void timeout();

private:
    virtual void resizeEvent(QResizeEvent *event) override final;
    virtual void enterEvent(QtEnterEvent *event) override final;
    virtual void leaveEvent(QEvent *event) override final;

    QString m_text;
    int m_step;
    int m_interval;
    bool m_mouseHoverStop;

    bool m_mouseHover;
    bool m_moveRight;
    int m_initX;
    int m_initY;
    QLabel *m_labText;
    QTimer *m_timer;

    QColor m_foregroundColor;
    QColor m_backgroundColor;

    MoveStyle m_moveStyle;

};

#endif // TTKMARQUEELABEL_H
