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
    enum MoveStyle
    {
        MoveStyleLeftAndRight = 0,
        MoveStyleLeftToRight = 1,
        MoveStyleRightToLeft = 2
    };

    explicit TTKMarqueeLabel(QWidget *parent = nullptr);
    ~TTKMarqueeLabel();

    void setText(const QString &text);
    void setStep(int step);
    void setInterval(int interval);

    void setMouseHoverStop(bool mouseHoverStop);

    void setForeground(const QColor &foreground);
    void setBackground(const QColor &background);

    void setMoveStyle(MoveStyle moveStyle);

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void timeout();

protected:
    virtual void resizeEvent(QResizeEvent *event) override final;
#if TTK_QT_VERSION_CHECK(6,0,0)
    virtual void enterEvent(QEnterEvent *event) override final;
#else
    virtual void enterEvent(QEvent *event) override final;
#endif
    virtual void leaveEvent(QEvent *event) override final;

private:
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

    QColor m_foreground;
    QColor m_background;

    MoveStyle m_moveStyle;

};

#endif // TTKMARQUEELABEL_H
