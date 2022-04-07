#include "ttkpictureflowwidget.h"
#include <QKeyEvent>
#include <QPainter>

#define PFREAL_SHIFT 10
#define PFREAL_ONE (1 << PFREAL_SHIFT)
#define IANGLE_MAX 1024
#define IANGLE_MASK 1023

inline long fmul(long a, long b)
{
    return ((long long)(a))*((long long)(b)) >> PFREAL_SHIFT;
}

inline long fdiv(long num, long den)
{
    long long p = (long long)(num) << (PFREAL_SHIFT*2);
    long long q = p / (long long)den;
    long long r = q >> PFREAL_SHIFT;

    return r;
}

inline long fsin(int iangle)
{
    static const long tab[] = {
         3,    103,    202,    300,    394,    485,    571,    652,
       726,    793,    853,    904,    947,    980,   1004,   1019,
      1023,   1018,   1003,    978,    944,    901,    849,    789,
       721,    647,    566,    479,    388,    294,    196,     97,
        -4,   -104,   -203,   -301,   -395,   -486,   -572,   -653,
      -727,   -794,   -854,   -905,   -948,   -981,  -1005,  -1020,
     -1024,  -1019,  -1004,   -979,   -945,   -902,   -850,   -790,
      -722,   -648,   -567,   -480,   -389,   -295,   -197,    -98,
      3
    };

    while(iangle < 0)
    {
        iangle += IANGLE_MAX;
    }
    iangle &= IANGLE_MASK;

    int i = (iangle >> 4);
    long p = tab[i];
    long q = tab[(i+1)];
    long g = (q - p);
    return p + g * (iangle-i*16)/16;
}

inline long fcos(int iangle)
{
    return fsin(iangle + (IANGLE_MAX >> 2));
}

QRgb blendColor(QRgb c1, QRgb c2, int blend)
{
    int r = qRed(c1) * blend/256 + qRed(c2)*(256-blend)/256;
    int g = qGreen(c1) * blend/256 + qGreen(c2)*(256-blend)/256;
    int b = qBlue(c1) * blend/256 + qBlue(c2)*(256-blend)/256;
    return qRgb(r, g, b);
}

QImage *prepareSurface(const QImage *slideImage, int w, int h, QRgb bgcolor,
                       ReflectionEffect reflectionEffect)
{
    Qt::TransformationMode mode = Qt::SmoothTransformation;
    QImage img = slideImage->scaled(w, h, Qt::IgnoreAspectRatio, mode);

    int hs = h * 2;
    int hofs = h / 3;

    QImage *result = new QImage(hs, w, QImage::Format_RGB32);
    result->fill(bgcolor);

    for(int x = 0; x < w; ++x)
    {
        for(int y = 0; y < h; ++y)
        {
            result->setPixel(hofs + y, x, img.pixel(x, y));
        }
    }

    if(reflectionEffect != NoReflection)
    {
        int ht = hs - h - hofs;
        int hte = ht;
        for(int x = 0; x < w; ++x)
        {
            for(int y = 0; y < ht; ++y)
            {
                QRgb color = img.pixel(x, img.height()-y-1);
                result->setPixel(h+hofs+y, x, blendColor(color, bgcolor, 128*(hte-y)/hte));
            }
        }

        if(reflectionEffect == BlurredReflection)
        {
            QRect rect(hs/2, 0, hs/2, w);
            rect &= result->rect();

            int r1 = rect.top();
            int r2 = rect.bottom();
            int c1 = rect.left();
            int c2 = rect.right();

            int bpl = result->bytesPerLine();
            int rgba[4];
            unsigned char* p;

            for(int loop = 0; loop < 2; ++loop)
            {
                for(int col = c1; col <= c2; ++col)
                {
                    p = result->scanLine(r1) + col * 4;
                    for(int i = 0; i < 3; ++i)
                    {
                        rgba[i] = p[i] << 4;
                    }

                    p += bpl;
                    for(int j = r1; j < r2; ++j, p += bpl)
                    {
                        for(int i = 0; i < 3; ++i)
                        {
                            p[i] = (rgba[i] += (((p[i]<<4)-rgba[i])) >> 1) >> 4;
                        }
                    }
                }

                for(int row = r1; row <= r2; ++row)
                {
                    p = result->scanLine(row) + c1 * 4;
                    for(int i = 0; i < 3; ++i)
                    {
                        rgba[i] = p[i] << 4;
                    }

                    p += 4;
                    for(int j = c1; j < c2; ++j, p += 4)
                    {
                        for(int i = 0; i < 3; ++i)
                        {
                            p[i] = (rgba[i] += (((p[i]<<4)-rgba[i])) >> 1) >> 4;
                        }
                    }
                }

                for(int col = c1; col <= c2; ++col)
                {
                    p = result->scanLine(r2) + col * 4;
                    for(int i = 0; i < 3; ++i)
                    {
                        rgba[i] = p[i] << 4;
                    }

                    p -= bpl;
                    for(int j = r1; j < r2; ++j, p -= bpl)
                    {
                        for(int i = 0; i < 3; ++i)
                        {
                            p[i] = (rgba[i] += (((p[i]<<4)-rgba[i])) >> 1) >> 4;
                        }
                    }
                }

                for(int row = r1; row <= r2; ++row)
                {
                    p = result->scanLine(row) + c2 * 4;
                    for(int i = 0; i < 3; ++i)
                    {
                        rgba[i] = p[i] << 4;
                    }

                    p -= 4;
                    for(int j = c1; j < c2; ++j, p -= 4)
                    {
                        for(int i = 0; i < 3; ++i)
                        {
                            p[i] = (rgba[i] += (((p[i]<<4)-rgba[i])) >> 1) >> 4;
                        }
                    }
                }

                for(int x = 0; x < w; ++x)
                {
                    for(int y = 0; y < h; ++y)
                    {
                        result->setPixel(hofs + y, x, img.pixel(x, y));
                    }
                }
            }
        }
    }

    return result;
}



TTKPictureFlowWidgetState::TTKPictureFlowWidgetState()
    : m_backgroundColor(0),
      m_slideWidth(150),
      m_slideHeight(200),
      m_reflectionEffect(BlurredReflection),
      m_centerIndex(0)
{

}

TTKPictureFlowWidgetState::~TTKPictureFlowWidgetState()
{
    for(int i = 0; i < m_slideImages.count(); ++i)
    {
        delete m_slideImages[i];
    }
}

void TTKPictureFlowWidgetState::reposition()
{
    m_angle = 70 * IANGLE_MAX / 360;

    m_offsetX = m_slideWidth/2 * (PFREAL_ONE-fcos(m_angle));
    m_offsetY = m_slideWidth/2 * fsin(m_angle);
    m_offsetX += m_slideWidth * PFREAL_ONE;
    m_offsetY += m_slideWidth * PFREAL_ONE / 4;
    m_spacing = 40;
}

void TTKPictureFlowWidgetState::reset()
{
    m_centerSlide.m_angle = 0;
    m_centerSlide.m_cx = 0;
    m_centerSlide.m_cy = 0;
    m_centerSlide.m_slideIndex = m_centerIndex;
    m_centerSlide.m_blend = 256;

    m_leftSlides.resize(6);
    for(int i = 0; i < m_leftSlides.count(); ++i)
    {
        TTKSlideInfo &si = m_leftSlides[i];
        si.m_angle = m_angle;
        si.m_cx = -(m_offsetX + m_spacing*i*PFREAL_ONE);
        si.m_cy = m_offsetY;
        si.m_slideIndex = m_centerIndex-1-i;
        si.m_blend = 256;

        if(i == m_leftSlides.count()-2)
        {
            si.m_blend = 128;
        }
        if(i == m_leftSlides.count()-1)
        {
            si.m_blend = 0;
        }
    }

    m_rightSlides.resize(6);
    for(int i = 0; i < m_rightSlides.count(); ++i)
    {
        TTKSlideInfo& si = m_rightSlides[i];
        si.m_angle = -m_angle;
        si.m_cx = m_offsetX + m_spacing*i*PFREAL_ONE;
        si.m_cy = m_offsetY;
        si.m_slideIndex = m_centerIndex+1+i;
        si.m_blend = 256;

        if(i == m_rightSlides.count()-2)
        {
            si.m_blend = 128;
        }
        if(i == m_rightSlides.count()-1)
        {
            si.m_blend = 0;
        }
    }
}



TTKPictureFlowWidgetAnimator::TTKPictureFlowWidgetAnimator()
    : m_target(0),
      m_step(0),
      m_frame(0),
      m_state(nullptr)
{

}

void TTKPictureFlowWidgetAnimator::start(int slide)
{
    m_target = slide;
    if(!m_animateTimer.isActive() && m_state)
    {
        m_step = (m_target < m_state->m_centerSlide.m_slideIndex) ? -1 : 1;
        m_animateTimer.start(30);
    }
}

void TTKPictureFlowWidgetAnimator::stop(int slide)
{
    m_step = 0;
    m_target = slide;
    m_frame = slide << 16;
    m_animateTimer.stop();
}

void TTKPictureFlowWidgetAnimator::update()
{
    if(!m_animateTimer.isActive() || m_step == 0 || !m_state)
    {
        return;
    }

    int speed = 16384/4;
    const int max = 2 * 65536;

    int fi = m_frame;
    fi -= (m_target << 16);
    if(fi < 0)
    {
        fi = -fi;
    }

    fi = qMin(fi, max);
    int ia = IANGLE_MAX * (fi-max/2) / (max*2);
    speed = 512 + 16384 * (PFREAL_ONE+fsin(ia))/PFREAL_ONE;

    m_frame += speed*m_step;

    int index = m_frame >> 16;
    int pos = m_frame & 0xffff;
    int neg = 65536 - pos;
    int tick = (m_step < 0) ? neg : pos;
    long ftick = (tick * PFREAL_ONE) >> 16;

    if(m_step < 0)
    {
        index++;
    }

    if(m_state->m_centerIndex != index)
    {
        m_state->m_centerIndex = index;
        m_frame = index << 16;
        m_state->m_centerSlide.m_slideIndex = m_state->m_centerIndex;

        for(int i = 0; i < m_state->m_leftSlides.count(); ++i)
        {
            m_state->m_leftSlides[i].m_slideIndex = m_state->m_centerIndex - 1 - i;
        }

        for(int i = 0; i < m_state->m_rightSlides.count(); ++i)
        {
            m_state->m_rightSlides[i].m_slideIndex = m_state->m_centerIndex + 1 + i;
        }
    }

    m_state->m_centerSlide.m_angle = (m_step * tick * m_state->m_angle) >> 16;
    m_state->m_centerSlide.m_cx = -m_step * fmul(m_state->m_offsetX, ftick);
    m_state->m_centerSlide.m_cy = fmul(m_state->m_offsetY, ftick);

    if(m_state->m_centerIndex == m_target)
    {
        stop(m_target);
        m_state->reset();
        return;
    }

    for(int i = 0; i < m_state->m_leftSlides.count(); ++i)
    {
        TTKSlideInfo &si = m_state->m_leftSlides[i];
        si.m_angle = m_state->m_angle;
        si.m_cx = -(m_state->m_offsetX + m_state->m_spacing*i*PFREAL_ONE + m_step*m_state->m_spacing*ftick);
        si.m_cy = m_state->m_offsetY;
    }

    for(int i = 0; i < m_state->m_rightSlides.count(); ++i)
    {
        TTKSlideInfo &si = m_state->m_rightSlides[i];
        si.m_angle = -m_state->m_angle;
        si.m_cx = m_state->m_offsetX + m_state->m_spacing*i*PFREAL_ONE - m_step*m_state->m_spacing*ftick;
        si.m_cy = m_state->m_offsetY;
    }

    if(m_step > 0)
    {
        const long ftick = (neg * PFREAL_ONE) >> 16;
        m_state->m_rightSlides[0].m_angle = -(neg * m_state->m_angle) >> 16;
        m_state->m_rightSlides[0].m_cx = fmul(m_state->m_offsetX, ftick);
        m_state->m_rightSlides[0].m_cy = fmul(m_state->m_offsetY, ftick);
    }
    else
    {
        const long ftick = (pos * PFREAL_ONE) >> 16;
        m_state->m_leftSlides[0].m_angle = (pos * m_state->m_angle) >> 16;
        m_state->m_leftSlides[0].m_cx = -fmul(m_state->m_offsetX, ftick);
        m_state->m_leftSlides[0].m_cy = fmul(m_state->m_offsetY, ftick);
    }

    if(m_target < index && m_step > 0)
    {
        m_step = -1;
    }

    if(m_target > index && m_step < 0)
    {
        m_step = 1;
    }

    const int nleft = m_state->m_leftSlides.count();
    const int nright = m_state->m_rightSlides.count();
    const int fade = pos / 256;

    for(int index = 0; index < nleft; ++index)
    {
        int blend = 256;
        if(index == nleft-1)
        {
            blend = (m_step > 0) ? 0 : 128-fade/2;
        }

        if(index == nleft-2)
        {
            blend = (m_step > 0) ? 128-fade/2 : 256-fade/2;
        }

        if(index == nleft-3)
        {
            blend = (m_step > 0) ? 256-fade/2 : 256;
        }
        m_state->m_leftSlides[index].m_blend = blend;
    }

    for(int index = 0; index < nright; ++index)
    {
        int blend = (index < nright-2) ? 256 : 128;
        if(index == nright-1)
        {
            blend = (m_step > 0) ? fade/2 : 0;
        }

        if(index == nright-2)
        {
            blend = (m_step > 0) ? 128+fade/2 : fade/2;
        }

        if(index == nright-3)
        {
            blend = (m_step > 0) ? 256 : 128+fade/2;
        }
        m_state->m_rightSlides[index].m_blend = blend;
    }
}



TTKPictureFlowWidgetSoftwareRenderer::TTKPictureFlowWidgetSoftwareRenderer()
    : m_dirty(false),
      m_widget(nullptr),
      m_state(nullptr),
      m_size(0,0),
      m_bgcolor(0),
      m_effect(-1),
      m_blankSurface(nullptr)
{

}

TTKPictureFlowWidgetSoftwareRenderer::~TTKPictureFlowWidgetSoftwareRenderer()
{
    m_surfaceCache.clear();
    m_buffer = QImage();
    delete m_blankSurface;
}

void TTKPictureFlowWidgetSoftwareRenderer::paint()
{
    if(!m_widget)
    {
        return;
    }

    if(m_widget->size() != m_size)
    {
        initialize();
    }

    if(m_state->m_backgroundColor != m_bgcolor)
    {
        m_bgcolor = m_state->m_backgroundColor;
        m_surfaceCache.clear();
    }

    if((int)(m_state->m_reflectionEffect) != m_effect)
    {
        m_effect = (int)m_state->m_reflectionEffect;
        m_surfaceCache.clear();
    }

    if(m_dirty)
    {
        render();
    }

    QPainter painter(m_widget);
    painter.drawImage(QPoint(0, 0), m_buffer);
}

void TTKPictureFlowWidgetSoftwareRenderer::initialize()
{
    if(!m_widget)
    {
        return;
    }

    m_surfaceCache.clear();
    m_blankSurface = 0;

    m_size = m_widget->size();
    int ww = m_size.width();
    int wh = m_size.height();
    int w = (ww+1)/2;
    int h = (wh+1)/2;

    m_buffer = QImage(ww, wh, QImage::Format_RGB32);
    m_buffer.fill(m_bgcolor);
    m_rays.resize(w*2);

    for(int i = 0; i < w; ++i)
    {
        long gg = ((PFREAL_ONE >> 1) + i * PFREAL_ONE) / (2 * h);
        m_rays[w-i-1] = -gg;
        m_rays[w+i] = gg;
    }

    m_dirty = true;
}

QImage* TTKPictureFlowWidgetSoftwareRenderer::surface(int slideIndex)
{
    if(!m_state || slideIndex < 0 || slideIndex >= (int)m_state->m_slideImages.count())
    {
        return 0;
    }

    int key = slideIndex;

    QImage* img = m_state->m_slideImages.at(slideIndex);
    bool empty = img ? img->isNull() : true;
    if(empty)
    {
        m_surfaceCache.remove(key);
        m_imageHash.remove(slideIndex);
        if(!m_blankSurface)
        {
            int sw = m_state->m_slideWidth;
            int sh = m_state->m_slideHeight;

            QImage img = QImage(sw, sh, QImage::Format_RGB32);

            QPainter painter(&img);
            QPoint p1(sw*4/10, 0);
            QPoint p2(sw*6/10, sh);
            QLinearGradient linearGrad(p1, p2);
            linearGrad.setColorAt(0, Qt::black);
            linearGrad.setColorAt(1, Qt::white);
            painter.setBrush(linearGrad);
            painter.fillRect(0, 0, sw, sh, QBrush(linearGrad));

            painter.setPen(QPen(QColor(64,64,64), 4));
            painter.setBrush(QBrush());
            painter.drawRect(2, 2, sw-3, sh-3);
            painter.end();

            m_blankSurface = prepareSurface(&img, sw, sh, m_bgcolor, m_state->m_reflectionEffect);
        }

        return m_blankSurface;
    }

    if(m_imageHash.contains(slideIndex) && img == m_imageHash.find(slideIndex).value() && m_surfaceCache.contains(key))
    {
        return m_surfaceCache[key];
    }

    QImage *sr = prepareSurface(img, m_state->m_slideWidth, m_state->m_slideHeight, m_bgcolor, m_state->m_reflectionEffect);
    m_surfaceCache.insert(key, sr);
    m_imageHash.insert(slideIndex, img);
    return sr;
}

QRect TTKPictureFlowWidgetSoftwareRenderer::renderSlide(const TTKSlideInfo &slide, int col1, int col2)
{
    int blend = slide.m_blend;
    if(!blend)
    {
        return QRect();
    }

    QImage *src = surface(slide.m_slideIndex);
    if(!src)
    {
        return QRect();
    }

    QRect rect(0, 0, 0, 0);
    int sw = src->height();
    int sh = src->width();
    int h = m_buffer.height();
    int w = m_buffer.width();

    if(col1 > col2)
    {
        int c = col2;
        col2 = col1;
        col1 = c;
    }

    col1 = (col1 >= 0) ? col1 : 0;
    col2 = (col2 >= 0) ? col2 : w-1;
    col1 = qMin(col1, w-1);
    col2 = qMin(col2, w-1);

    int zoom = 100;
    int distance = h * 100 / zoom;
    long sdx = fcos(slide.m_angle);
    long sdy = fsin(slide.m_angle);
    long xs = slide.m_cx - m_state->m_slideWidth * sdx/2;
    long ys = slide.m_cy - m_state->m_slideWidth * sdy/2;
    long dist = distance * PFREAL_ONE;

    int xi = qMax((long)0, ((w*PFREAL_ONE/2) + fdiv(xs*h, dist+ys)) >> PFREAL_SHIFT);
    if(xi >= w)
    {
        return rect;
    }

    bool flag = false;
    rect.setLeft(xi);
    for(int x = qMax(xi, col1); x <= col2; ++x)
    {
        long hity = 0;
        long fk = m_rays[x];
        if(sdy)
        {
            fk = fk - fdiv(sdx,sdy);
            hity = -fdiv((m_rays[x]*distance - slide.m_cx + slide.m_cy*sdx/sdy), fk);
        }

        dist = distance*PFREAL_ONE + hity;
        if(dist < 0)
        {
            continue;
        }

        long hitx = fmul(dist, m_rays[x]);
        long hitdist = fdiv(hitx - slide.m_cx, sdx);

        int column = sw/2 + (hitdist >> PFREAL_SHIFT);
        if(column >= sw)
        {
            break;
        }
        if(column < 0)
        {
            continue;
        }

        rect.setRight(x);
        if(!flag)
        {
            rect.setLeft(x);
        }
        flag = true;

        int y1 = h/2;
        int y2 = y1+ 1;
        QRgb* pixel1 = (QRgb*)(m_buffer.scanLine(y1)) + x;
        QRgb* pixel2 = (QRgb*)(m_buffer.scanLine(y2)) + x;
        QRgb pixelstep = pixel2 - pixel1;

        int center = (sh/2);
        int dy = dist / h;
        int p1 = center*PFREAL_ONE - dy/2;
        int p2 = center*PFREAL_ONE + dy/2;

        const QRgb *ptr = (const QRgb*)(src->scanLine(column));
        if(blend == 256)
        {
            while(y1 >= 0 && y2 < h && p1 >= 0)
            {
                *pixel1 = ptr[p1 >> PFREAL_SHIFT];
                *pixel2 = ptr[p2 >> PFREAL_SHIFT];
                p1 -= dy;
                p2 += dy;
                y1--;
                y2++;
                pixel1 -= pixelstep;
                pixel2 += pixelstep;
            }
        }
        else
        {
            while((y1 >= 0) && (y2 < h) && (p1 >= 0))
            {
                QRgb c1 = ptr[p1 >> PFREAL_SHIFT];
                QRgb c2 = ptr[p2 >> PFREAL_SHIFT];
                *pixel1 = blendColor(c1, m_bgcolor, blend);
                *pixel2 = blendColor(c2, m_bgcolor, blend);
                p1 -= dy;
                p2 += dy;
                y1--;
                y2++;
                pixel1 -= pixelstep;
                pixel2 += pixelstep;
            }
        }
    }

    rect.setTop(0);
    rect.setBottom(h-1);
    return rect;
}

void TTKPictureFlowWidgetSoftwareRenderer::renderSlides()
{
    int nleft = m_state->m_leftSlides.count();
    int nright = m_state->m_rightSlides.count();

    QRect r = renderSlide(m_state->m_centerSlide);
    int c1 = r.left();
    int c2 = r.right();

    for(int index = 0; index < nleft; ++index)
    {
        QRect rs = renderSlide(m_state->m_leftSlides[index], 0, c1-1);
        if(!rs.isEmpty())
        {
            c1 = rs.left();
        }
    }
    for(int index = 0; index < nright; ++index)
    {
        QRect rs = renderSlide(m_state->m_rightSlides[index], c2+1, m_buffer.width());
        if(!rs.isEmpty())
        {
            c2 = rs.right();
        }
    }
}

void TTKPictureFlowWidgetSoftwareRenderer::render()
{
    m_buffer.fill(m_state->m_backgroundColor);
    renderSlides();
    m_dirty = false;
}



TTKPictureFlowWidget::TTKPictureFlowWidget(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents, true);
    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setAttribute(Qt::WA_NoSystemBackground, true);

    m_state = new TTKPictureFlowWidgetState;
    m_state->reset();
    m_state->reposition();

    m_animator = new TTKPictureFlowWidgetAnimator;
    m_animator->m_state = m_state;

    m_renderer = new TTKPictureFlowWidgetSoftwareRenderer;
    m_renderer->m_state = m_state;
    m_renderer->m_widget = this;
    m_renderer->initialize();

    m_useResize = false;

    connect(&m_animator->m_animateTimer, SIGNAL(timeout()), SLOT(updateRender()));
    connect(&m_triggerTimer, SIGNAL(timeout()), SLOT(render()));
}

TTKPictureFlowWidget::~TTKPictureFlowWidget()
{
    delete m_renderer;
    delete m_animator;
    delete m_state;
}

int TTKPictureFlowWidget::slideCount() const
{
    return m_state->m_slideImages.count();
}

QColor TTKPictureFlowWidget::backgroundColor() const
{
    return QColor(m_state->m_backgroundColor);
}

void TTKPictureFlowWidget::setBackgroundColor(const QColor &c)
{
    m_state->m_backgroundColor = c.rgb();
    triggerRender();
}

QSize TTKPictureFlowWidget::slideSize() const
{
    return QSize(m_state->m_slideWidth, m_state->m_slideHeight);
}

void TTKPictureFlowWidget::setSlideSize(QSize size)
{
    m_state->m_slideWidth = size.width();
    m_state->m_slideHeight = size.height();
    m_state->reposition();
    triggerRender();
}

ReflectionEffect TTKPictureFlowWidget::reflectionEffect() const
{
    return m_state->m_reflectionEffect;
}

void TTKPictureFlowWidget::setReflectionEffect(ReflectionEffect effect)
{
    m_state->m_reflectionEffect = effect;
    triggerRender();
}

QSize TTKPictureFlowWidget::sizeHint() const
{
    return QSize(400, 180);
}

QImage TTKPictureFlowWidget::slide(int index) const
{
    QImage *img = nullptr;
    if(index >= 0 && index < slideCount())
    {
        img = m_state->m_slideImages[index];
    }

    return img ? QImage(*img) : QImage();
}

void TTKPictureFlowWidget::addSlide(const QImage &image)
{
    int c = m_state->m_slideImages.count();
    m_state->m_slideImages.resize(c+1);
    m_state->m_slideImages[c] = new QImage(image);
    triggerRender();
}

void TTKPictureFlowWidget::setSlide(int index, const QImage &image)
{
    if(index >= 0 && index < slideCount())
    {
        QImage *img = image.isNull() ? nullptr : new QImage(image);
        delete m_state->m_slideImages[index];
        m_state->m_slideImages[index] = img;
        triggerRender();
    }
}

int TTKPictureFlowWidget::centerIndex() const
{
    return m_state->m_centerIndex;
}

void TTKPictureFlowWidget::setCenterIndex(int index)
{
    index = qMin(index, slideCount()-1);
    index = qMax(index, 0);

    m_state->m_centerIndex = index;
    m_state->reset();
    m_animator->stop(index);
    triggerRender();
}

void TTKPictureFlowWidget::clear()
{
    for(int i = 0; i < m_state->m_slideImages.count(); ++i)
    {
        delete m_state->m_slideImages[i];
    }

    m_state->m_slideImages.resize(0);
    m_state->reset();
    triggerRender();
}

void TTKPictureFlowWidget::render()
{
    m_renderer->m_dirty = true;
    update();
}

void TTKPictureFlowWidget::triggerRender()
{
    m_triggerTimer.setSingleShot(true);
    m_triggerTimer.start(0);
}

void TTKPictureFlowWidget::showPrevious()
{
    int step = m_animator->m_step;
    int center = m_state->m_centerIndex;

    if(step > 0)
    {
        m_animator->start(center);
    }
    if(step == 0 && center > 0)
    {
        m_animator->start(center - 1);
    }
    if(step < 0)
    {
        m_animator->m_target = qMax(0, center - 2);
    }
}

void TTKPictureFlowWidget::showNext()
{
    int step = m_animator->m_step;
    int center = m_state->m_centerIndex;

    if(step < 0)
    {
        m_animator->start(center);
    }
    if(step == 0 && center < slideCount()-1)
    {
        m_animator->start(center + 1);
    }
    if(step > 0)
    {
        m_animator->m_target = qMin(center + 2, slideCount()-1);
    }
}

void TTKPictureFlowWidget::showSlide(int index)
{
    index = qMax(index, 0);
    index = qMin(slideCount()-1, index);
    if(index == m_state->m_centerSlide.m_slideIndex)
    {
        return;
    }

    m_animator->start(index);
}

void TTKPictureFlowWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(event->modifiers() == Qt::ControlModifier)
        {
            showSlide(centerIndex()-10);
        }
        else
        {
            showPrevious();
        }

        event->accept();
        return;
    }

    if(event->key() == Qt::Key_Right)
    {
        if(event->modifiers() == Qt::ControlModifier)
        {
            showSlide(centerIndex()+10);
        }
        else
        {
            showNext();
        }

        event->accept();
        return;
    }

    event->ignore();
}

void TTKPictureFlowWidget::mousePressEvent(QMouseEvent *event)
{
    int x = 0;
#if TTK_QT_VERSION_CHECK(6,0,0)
    x = event->position().x();
#else
    x = event->x();
#endif
    (x > width() / 2) ? showNext() : showPrevious();
}

void TTKPictureFlowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    m_renderer->paint();
}

void TTKPictureFlowWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if(!m_useResize)
    {
        triggerRender();
    }
    else
    {
        if(slideCount() != 0)
        {
            setSlideSize(QSize(width()/slideCount(), height()/2));
        }
    }
}

void TTKPictureFlowWidget::updateRender()
{
    int center = m_state->m_centerIndex;
    m_animator->update();
    triggerRender();

    if(m_state->m_centerIndex != center)
    {
        emit centerIndexChanged(m_state->m_centerIndex);
    }
}
