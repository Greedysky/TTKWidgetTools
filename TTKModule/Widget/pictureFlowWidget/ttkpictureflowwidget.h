#ifndef TTKPICTUREFLOWWIDGET_H
#define TTKPICTUREFLOWWIDGET_H

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

#include <QCache>
#include <QTimer>
#include <QWidget>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
enum ReflectionEffect
{
    NoReflection,
    PlainReflection,
    BlurredReflection
};

/*!
 * @author Greedysky <greedysky@163.com>
 */
struct TTK_MODULE_EXPORT TTKSlideInfo
{
    int m_slideIndex;
    int m_angle;
    long m_cx;
    long m_cy;
    int m_blend;
};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureFlowWidgetState
{
public:
    TTKPictureFlowWidgetState();
    ~TTKPictureFlowWidgetState();

    void reposition();
    void reset();

    QRgb m_backgroundColor;
    int m_slideWidth, m_slideHeight;
    ReflectionEffect m_reflectionEffect;
    QVector<QImage*> m_slideImages;

    int m_angle, m_spacing, m_centerIndex;
    long m_offsetX, m_offsetY;

    TTKSlideInfo m_centerSlide;
    QVector<TTKSlideInfo> m_leftSlides, m_rightSlides;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureFlowWidgetAnimator
{
public:
    TTKPictureFlowWidgetAnimator();

    void start(int slide);
    void stop(int slide);
    void update();

    int m_target, m_step, m_frame;
    QTimer m_animateTimer;
    TTKPictureFlowWidgetState *m_state;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureFlowWidgetSoftwareRenderer
{
public:
    TTKPictureFlowWidgetSoftwareRenderer();
    ~TTKPictureFlowWidgetSoftwareRenderer();

    void initialize();
    void paint();

    bool  m_dirty;
    QWidget *m_widget;
    TTKPictureFlowWidgetState *m_state;

private:
    void render();
    void renderSlides();
    QRect renderSlide(const TTKSlideInfo &slide, int col1 = -1, int col2 = -1);
    QImage* surface(int slideIndex);

    QSize m_size;
    QRgb m_bgcolor;
    int m_effect;
    QImage m_buffer;
    QVector<long> m_rays;
    QImage *m_blankSurface;
    QCache<int,QImage> m_surfaceCache;
    QHash<int,QImage*> m_imageHash;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKPictureFlowWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPictureFlowWidget)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QSize slideSize READ slideSize WRITE setSlideSize)
    Q_PROPERTY(int slideCount READ slideCount)
    Q_PROPERTY(int centerIndex READ centerIndex WRITE setCenterIndex)
public:
    explicit TTKPictureFlowWidget(QWidget *parent = nullptr);
    ~TTKPictureFlowWidget();

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &c);

    QSize slideSize() const;
    void setSlideSize(QSize size);

    int slideCount() const;
    QImage slide(int index) const;

    int centerIndex() const;

    ReflectionEffect reflectionEffect() const;
    void setReflectionEffect(ReflectionEffect effect);

    virtual QSize sizeHint() const override final;

Q_SIGNALS:
    void centerIndexChanged(int index);

public Q_SLOTS:
    void addSlide(const QImage &image);
    void setSlide(int index, const QImage &image);
    void setCenterIndex(int index);
    void clear();
    void showPrevious();
    void showNext();
    void showSlide(int index);
    void render();
    void triggerRender();

private Q_SLOTS:
    void updateRender();

protected:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;

    bool m_useResize;
    TTKPictureFlowWidgetState *m_state;
    TTKPictureFlowWidgetAnimator *m_animator;
    TTKPictureFlowWidgetSoftwareRenderer *m_renderer;
    QTimer m_triggerTimer;

};

#endif // TTKPICTUREFLOWWIDGET_H
