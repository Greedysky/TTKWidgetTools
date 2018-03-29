#ifndef TTKPICTUREFLOWWIDGET_H
#define TTKPICTUREFLOWWIDGET_H

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
struct TTK_EXTRAS_EXPORT TTKSlideInfo
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
class TTK_EXTRAS_EXPORT TTKTTKPictureFlowWidgetState
{
public:
    TTKTTKPictureFlowWidgetState();
    ~TTKTTKPictureFlowWidgetState();

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
class TTK_EXTRAS_EXPORT TTKTTKPictureFlowWidgetAnimator
{
public:
    TTKTTKPictureFlowWidgetAnimator();

    void start(int slide);
    void stop(int slide);
    void update();

    int m_target, m_step, m_frame;
    QTimer m_animateTimer;
    TTKTTKPictureFlowWidgetState *m_state;

};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKTTKPictureFlowWidgetSoftwareRenderer
{
public:
    TTKTTKPictureFlowWidgetSoftwareRenderer();
    ~TTKTTKPictureFlowWidgetSoftwareRenderer();

    void init();
    void paint();

    bool  m_dirty;
    QWidget *m_widget;
    TTKTTKPictureFlowWidgetState *m_state;

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
class TTK_EXTRAS_EXPORT TTKPictureFlowWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QSize slideSize READ slideSize WRITE setSlideSize)
    Q_PROPERTY(int slideCount READ slideCount)
    Q_PROPERTY(int centerIndex READ centerIndex WRITE setCenterIndex)
public:
    explicit TTKPictureFlowWidget(QWidget *parent = 0);
    ~TTKPictureFlowWidget();

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor& c);

    QSize slideSize() const;
    void setSlideSize(QSize size);

    int slideCount() const;
    QImage slide(int index) const;

    int centerIndex() const;

    ReflectionEffect reflectionEffect() const;
    void setReflectionEffect(ReflectionEffect effect);

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
    void updateAnimation();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    bool m_useResize;
    TTKTTKPictureFlowWidgetState *m_state;
    TTKTTKPictureFlowWidgetAnimator *m_animator;
    TTKTTKPictureFlowWidgetSoftwareRenderer *m_renderer;
    QTimer m_triggerTimer;

};

#endif // TTKPICTUREFLOWWIDGET_H
