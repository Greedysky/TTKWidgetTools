#ifndef TTKPICTUREBANNERWIDGET_H
#define TTKPICTUREBANNERWIDGET_H

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

class QHBoxLayout;
class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 *          maminjie <canpool@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureBannerArrowWidget : public QWidget
{
    Q_OBJECT
public:
    enum ArrowType
    {
        Left,
        Right
    };

    explicit TTKPictureBannerArrowWidget(ArrowType type, QWidget *parent = nullptr);

Q_SIGNALS:
    void clicked();

protected:
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
    bool m_bMouseHover, m_bMousePress;
    ArrowType m_type;

};



/*!
 * @author Greedysky <greedysky@163.com>
 *          maminjie <canpool@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureBannerIndicator : public QWidget
{
    Q_OBJECT
public:
    explicit TTKPictureBannerIndicator(QWidget *parent = nullptr);

    void select(bool selected);

Q_SIGNALS:
    void entered();

protected:
#if TTK_QT_VERSION_CHECK(6,0,0)
    virtual void enterEvent(QEnterEvent *event) override final;
#else
    virtual void enterEvent(QEvent *event) override final;
#endif
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    bool m_selected;

};



/*!
 * @author Greedysky <greedysky@163.com>
 *          maminjie <canpool@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureBannerPage : public QLabel
{
    Q_OBJECT
public:
    explicit TTKPictureBannerPage(QWidget *parent = nullptr);

    void setActive(bool active);

Q_SIGNALS:
    void clicked();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

private:
    bool m_bActive;

};



/*!
 * @author Greedysky <greedysky@163.com>
 *          maminjie <canpool@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureBannerView : public QWidget
{
    Q_OBJECT
public:
    explicit TTKPictureBannerView(QWidget *parent = nullptr);
    ~TTKPictureBannerView();

    void setLeftPixmap(const QPixmap &pixmap);
    void setCenterPixmap(const QPixmap &pixmap);
    void setRightPixmap(const QPixmap &pixmap);

    void startAnimation(int direction);

Q_SIGNALS:
    void clicked(int flag);

private Q_SLOTS:
    void slotPageClicked();
    void slotArrowClicked();

protected:
#if TTK_QT_VERSION_CHECK(6,0,0)
    virtual void enterEvent(QEnterEvent *event) override final;
#else
    virtual void enterEvent(QEvent *event) override final;
#endif
    virtual void leaveEvent(QEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

    void setPagePixmap(TTKPictureBannerPage *page, const QPixmap &pixmap);
    void setArrowHidden(bool hidden);

    QSize m_size;
    TTKPictureBannerPage *m_leftPage,*m_centerPage, *m_rightPage;
    TTKPictureBannerArrowWidget *m_leftArrow,*m_rightArrow;
    QPropertyAnimation *m_leftAnimation, *m_centerAnimation, *m_rightAnimation;

};



/*!
 * @author Greedysky <greedysky@163.com>
 *          maminjie <canpool@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureBannerWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPictureBannerWidget)
public:
    explicit TTKPictureBannerWidget(QWidget *parent = nullptr);

    void addPage(const QPixmap &pixmap);
    void addPages(const QList<QPixmap> &pixmaps);

    void startAutoPlay();
    void stopAutoPlay();

    void setDelayTime(int msec, bool start = false);

    virtual QSize sizeHint() const override final;

Q_SIGNALS:
    void currentClicked(int index);

public Q_SLOTS:
    void switchIndicator();
    void switchPage(int flag);
    void updateRender();

protected:
    virtual void paintEvent(QPaintEvent *event) override final;

    void initialize();
    void play(int index);

    TTKPictureBannerView *m_view;
    QHBoxLayout *m_indLayout;
    QList<QPixmap> m_pixmaps;
    QList<TTKPictureBannerIndicator*> m_indicators;
    int m_currentIndex, m_interval;
    QTimer *m_timer;

};

#endif // TTKPICTUREBANNERWIDGET_H
