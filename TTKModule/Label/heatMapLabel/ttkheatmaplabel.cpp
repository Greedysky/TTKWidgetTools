#include "ttkheatmaplabel.h"

#include <heatmap/lodepng.h>
#include <heatmap/heatmap.h>
///
#include <heatmap/colorschemes/YlOrRd.h>
#include <heatmap/colorschemes/YlOrBr.h>
#include <heatmap/colorschemes/YlGnBu.h>
#include <heatmap/colorschemes/YlGn.h>
#include <heatmap/colorschemes/Spectral.h>
#include <heatmap/colorschemes/Reds.h>
#include <heatmap/colorschemes/RdYlGn.h>
#include <heatmap/colorschemes/RdYlBu.h>
#include <heatmap/colorschemes/RdPu.h>
#include <heatmap/colorschemes/RdGy.h>
#include <heatmap/colorschemes/RdBu.h>
#include <heatmap/colorschemes/Purples.h>
#include <heatmap/colorschemes/PuRd.h>
#include <heatmap/colorschemes/PuOr.h>
#include <heatmap/colorschemes/PuBuGn.h>
#include <heatmap/colorschemes/PuBu.h>
#include <heatmap/colorschemes/PRGn.h>
#include <heatmap/colorschemes/PiYG.h>
#include <heatmap/colorschemes/OrRd.h>
#include <heatmap/colorschemes/Oranges.h>
#include <heatmap/colorschemes/Greys.h>
#include <heatmap/colorschemes/Greens.h>
#include <heatmap/colorschemes/Gray.h>
#include <heatmap/colorschemes/GnBu.h>
#include <heatmap/colorschemes/BuPu.h>
#include <heatmap/colorschemes/BuGn.h>
#include <heatmap/colorschemes/BrBG.h>
#include <heatmap/colorschemes/Blues.h>

static const heatmap_colorscheme_t * MappingColorScheme(HeatMapper::ColorScheme scheme)
{
  switch(scheme)
  {
  case HeatMapper::ColorScheme::YlOrRdDiscrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::ColorScheme::YlOrRdSoft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::ColorScheme::YlOrRdMixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::ColorScheme::YlOrRdMixedExp: return heatmap_cs_YlOrRd_mixed_exp;
  ///
  case HeatMapper::ColorScheme::YlOrBrDiscrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::ColorScheme::YlOrBrSoft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::ColorScheme::YlOrBrMixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::ColorScheme::YlOrBrMixedExp: return heatmap_cs_YlOrBr_mixed_exp;
  ///
  case HeatMapper::ColorScheme::YlGnBuDiscrete: return heatmap_cs_YlGnBu_discrete;
  case HeatMapper::ColorScheme::YlGnBuSoft: return heatmap_cs_YlGnBu_soft;
  case HeatMapper::ColorScheme::YlGnBuMixed: return heatmap_cs_YlGnBu_mixed;
  case HeatMapper::ColorScheme::YlGnBuMixedExp: return heatmap_cs_YlGnBu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::YlGnDiscrete: return heatmap_cs_YlGn_discrete;
  case HeatMapper::ColorScheme::YlGnSoft: return heatmap_cs_YlGn_soft;
  case HeatMapper::ColorScheme::YlGnMixed: return heatmap_cs_YlGn_mixed;
  case HeatMapper::ColorScheme::YlGnMixedExp: return heatmap_cs_YlGn_mixed_exp;
  ///
  case HeatMapper::ColorScheme::SpectralDiscrete: return heatmap_cs_Spectral_discrete;
  case HeatMapper::ColorScheme::SpectralSoft: return heatmap_cs_Spectral_soft;
  case HeatMapper::ColorScheme::SpectralMixed: return heatmap_cs_Spectral_mixed;
  case HeatMapper::ColorScheme::SpectralMixedExp: return heatmap_cs_Spectral_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RedsDiscrete: return heatmap_cs_Reds_discrete;
  case HeatMapper::ColorScheme::RedsSoft: return heatmap_cs_Reds_soft;
  case HeatMapper::ColorScheme::RedsMixed: return heatmap_cs_Reds_mixed;
  case HeatMapper::ColorScheme::RedsMixedExp: return heatmap_cs_Reds_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RdYlGnDiscrete: return heatmap_cs_RdYlGn_discrete;
  case HeatMapper::ColorScheme::RdYlGnSoft: return heatmap_cs_RdYlGn_soft;
  case HeatMapper::ColorScheme::RdYlGnMixed: return heatmap_cs_RdYlGn_mixed;
  case HeatMapper::ColorScheme::RdYlGnMixedExp: return heatmap_cs_RdYlGn_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RdYlBuDiscrete: return heatmap_cs_RdYlBu_discrete;
  case HeatMapper::ColorScheme::RdYlBuSoft: return heatmap_cs_RdYlBu_soft;
  case HeatMapper::ColorScheme::RdYlBuMixed: return heatmap_cs_RdYlBu_mixed;
  case HeatMapper::ColorScheme::RdYlBuMixedExp: return heatmap_cs_RdYlBu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RdPuDiscrete: return heatmap_cs_RdPu_discrete;
  case HeatMapper::ColorScheme::RdPuSoft: return heatmap_cs_RdPu_soft;
  case HeatMapper::ColorScheme::RdPuMixed: return heatmap_cs_RdPu_mixed;
  case HeatMapper::ColorScheme::RdPuMixedExp: return heatmap_cs_RdPu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RdGyDiscrete: return heatmap_cs_RdGy_discrete;
  case HeatMapper::ColorScheme::RdGySoft: return heatmap_cs_RdGy_soft;
  case HeatMapper::ColorScheme::RdGyMixed: return heatmap_cs_RdGy_mixed;
  case HeatMapper::ColorScheme::RdGyMixedExp: return heatmap_cs_RdGy_mixed_exp;
  ///
  case HeatMapper::ColorScheme::RdBuDiscrete: return heatmap_cs_RdBu_discrete;
  case HeatMapper::ColorScheme::RdBuSoft: return heatmap_cs_RdBu_soft;
  case HeatMapper::ColorScheme::RdBuMixed: return heatmap_cs_RdBu_mixed;
  case HeatMapper::ColorScheme::RdBuMixedExp: return heatmap_cs_RdBu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PurplesDiscrete: return heatmap_cs_Purples_discrete;
  case HeatMapper::ColorScheme::PurplesSoft: return heatmap_cs_Purples_soft;
  case HeatMapper::ColorScheme::PurplesMixed: return heatmap_cs_Purples_mixed;
  case HeatMapper::ColorScheme::PurplesMixedExp: return heatmap_cs_Purples_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PuRdDiscrete: return heatmap_cs_PuRd_discrete;
  case HeatMapper::ColorScheme::PuRdSoft: return heatmap_cs_PuRd_soft;
  case HeatMapper::ColorScheme::PuRdMixed: return heatmap_cs_PuRd_mixed;
  case HeatMapper::ColorScheme::PuRdMixedExp: return heatmap_cs_PuRd_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PuOrDiscrete: return heatmap_cs_PuOr_discrete;
  case HeatMapper::ColorScheme::PuOrSoft: return heatmap_cs_PuOr_soft;
  case HeatMapper::ColorScheme::PuOrMixed: return heatmap_cs_PuOr_mixed;
  case HeatMapper::ColorScheme::PuOrMixedExp: return heatmap_cs_PuOr_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PuBuGnDiscrete: return heatmap_cs_PuBuGn_discrete;
  case HeatMapper::ColorScheme::PuBuGnSoft: return heatmap_cs_PuBuGn_soft;
  case HeatMapper::ColorScheme::PuBuGnMixed: return heatmap_cs_PuBuGn_mixed;
  case HeatMapper::ColorScheme::PuBuGnMixedExp: return heatmap_cs_PuBuGn_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PuBuDiscrete: return heatmap_cs_PuBu_discrete;
  case HeatMapper::ColorScheme::PuBuSoft: return heatmap_cs_PuBu_soft;
  case HeatMapper::ColorScheme::PuBuMixed: return heatmap_cs_PuBu_mixed;
  case HeatMapper::ColorScheme::PuBuMixedExp: return heatmap_cs_PuBu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PRGnDiscrete: return heatmap_cs_PRGn_discrete;
  case HeatMapper::ColorScheme::PRGnSoft: return heatmap_cs_PRGn_soft;
  case HeatMapper::ColorScheme::PRGnMixed: return heatmap_cs_PRGn_mixed;
  case HeatMapper::ColorScheme::PRGnMixedExp: return heatmap_cs_PRGn_mixed_exp;
  ///
  case HeatMapper::ColorScheme::PiYGDiscrete: return heatmap_cs_PiYG_discrete;
  case HeatMapper::ColorScheme::PiYGSoft: return heatmap_cs_PiYG_soft;
  case HeatMapper::ColorScheme::PiYGMixed: return heatmap_cs_PiYG_mixed;
  case HeatMapper::ColorScheme::PiYGMixedExp: return heatmap_cs_PiYG_mixed_exp;
  ///
  case HeatMapper::ColorScheme::OrRdDiscrete: return heatmap_cs_OrRd_discrete;
  case HeatMapper::ColorScheme::OrRdSoft: return heatmap_cs_OrRd_soft;
  case HeatMapper::ColorScheme::OrRdMixed: return heatmap_cs_OrRd_mixed;
  case HeatMapper::ColorScheme::OrRdMixedExp: return heatmap_cs_OrRd_mixed_exp;
  ///
  case HeatMapper::ColorScheme::OrangesDiscrete: return heatmap_cs_Oranges_discrete;
  case HeatMapper::ColorScheme::OrangesSoft: return heatmap_cs_Oranges_soft;
  case HeatMapper::ColorScheme::OrangesMixed: return heatmap_cs_Oranges_mixed;
  case HeatMapper::ColorScheme::OrangesMixedExp: return heatmap_cs_Oranges_mixed_exp;
  ///
  case HeatMapper::ColorScheme::GreysDiscrete: return heatmap_cs_Greys_discrete;
  case HeatMapper::ColorScheme::GreysSoft: return heatmap_cs_Greys_soft;
  case HeatMapper::ColorScheme::GreysMixed: return heatmap_cs_Greys_mixed;
  case HeatMapper::ColorScheme::GreysMixedExp: return heatmap_cs_Greys_mixed_exp;
  ///
  case HeatMapper::ColorScheme::GreensDiscrete: return heatmap_cs_Greens_discrete;
  case HeatMapper::ColorScheme::GreensSoft: return heatmap_cs_Greens_soft;
  case HeatMapper::ColorScheme::GreensMixed: return heatmap_cs_Greens_mixed;
  case HeatMapper::ColorScheme::GreensMixedExp: return heatmap_cs_Greens_mixed_exp;
  ///
  case HeatMapper::ColorScheme::B2w: return heatmap_cs_b2w;
  case HeatMapper::ColorScheme::B2wOpaque: return heatmap_cs_b2w_opaque;
  case HeatMapper::ColorScheme::W2b: return heatmap_cs_w2b;
  case HeatMapper::ColorScheme::W2bOpaque: return heatmap_cs_w2b_opaque;
  ///
  case HeatMapper::ColorScheme::GnBuDiscrete: return heatmap_cs_GnBu_discrete;
  case HeatMapper::ColorScheme::GnBuSoft: return heatmap_cs_GnBu_soft;
  case HeatMapper::ColorScheme::GnBuMixed: return heatmap_cs_GnBu_mixed;
  case HeatMapper::ColorScheme::GnBuMixedExp: return heatmap_cs_GnBu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::BuPuDiscrete: return heatmap_cs_BuPu_discrete;
  case HeatMapper::ColorScheme::BuPuSoft: return heatmap_cs_BuPu_soft;
  case HeatMapper::ColorScheme::BuPuMixed: return heatmap_cs_BuPu_mixed;
  case HeatMapper::ColorScheme::BuPuMixedExp: return heatmap_cs_BuPu_mixed_exp;
  ///
  case HeatMapper::ColorScheme::BuGnDiscrete: return heatmap_cs_BuGn_discrete;
  case HeatMapper::ColorScheme::BuGnSoft: return heatmap_cs_BuGn_soft;
  case HeatMapper::ColorScheme::BuGnMixed: return heatmap_cs_BuGn_mixed;
  case HeatMapper::ColorScheme::BuGnMixedExp: return heatmap_cs_BuGn_mixed_exp;
  ///
  case HeatMapper::ColorScheme::BrBGDiscrete: return heatmap_cs_BrBG_discrete;
  case HeatMapper::ColorScheme::BrBGSoft: return heatmap_cs_BrBG_soft;
  case HeatMapper::ColorScheme::BrBGMixed: return heatmap_cs_BrBG_mixed;
  case HeatMapper::ColorScheme::BrBGMixedExp: return heatmap_cs_BrBG_mixed_exp;
  ///
  case HeatMapper::ColorScheme::BluesDiscrete: return heatmap_cs_Blues_discrete;
  case HeatMapper::ColorScheme::BluesSoft: return heatmap_cs_Blues_soft;
  case HeatMapper::ColorScheme::BluesMixed: return heatmap_cs_Blues_mixed;
  case HeatMapper::ColorScheme::BluesMixedExp: return heatmap_cs_Blues_mixed_exp;
  default: return heatmap_cs_default;
  }
}
///
#include <QPainter>

#define DEFAULT_OPACITY 255

HeatMapper::HeatMapper(const QSize &size)
    : HeatMapper(size, 128)
{
}

HeatMapper::HeatMapper(const QSize &size, int radius)
    : HeatMapper(size.width(), size.height(), radius)
{
}

HeatMapper::HeatMapper(int width, int height)
    : HeatMapper(width, height, 128)
{
}

HeatMapper::HeatMapper(int width, int height, int radius)
    : m_opacity(DEFAULT_OPACITY),
      m_stamp(nullptr),
      m_scheme(ColorScheme::Default)
{
    m_heatmap = heatmap_new(width, height);
    setRadius(radius);
}

HeatMapper::~HeatMapper()
{
    if(m_stamp)
    {
        heatmap_stamp_free(m_stamp);
    }
    heatmap_free(m_heatmap);
}

void HeatMapper::setRadius(int radius)
{
    if(m_stamp)
    {
        heatmap_stamp_free(m_stamp);
    }
    m_stamp = heatmap_stamp_gen(radius);
}

void HeatMapper::setOpacity(int opacity)
{
    m_opacity = qBound(0, opacity, DEFAULT_OPACITY);
}

void HeatMapper::setColorScheme(ColorScheme scheme)
{
    m_scheme = scheme;
}

void HeatMapper::addPoint(int x, int y)
{
    heatmap_add_point_with_stamp(m_heatmap, x, y, m_stamp);
    // We're done with adding points, we don't need the stamp anymore.
}

QImage HeatMapper::render()
{
    DataRange input(m_heatmap->h * m_heatmap->w * 4);
    heatmap_render_to(m_heatmap, MappingColorScheme(m_scheme), &input[0]);

    DataRange output;
    lodepng::encode(output, input, m_heatmap->w, m_heatmap->h);

    if(output.empty())
    {
        return QImage();
    }

    QImage render(m_heatmap->w, m_heatmap->h, QImage::Format_ARGB32);
    render.loadFromData(&output[0], (int)output.size());

    if(m_opacity != DEFAULT_OPACITY)
    {
        QImage image(render.size(), QImage::Format_ARGB32);
        image.fill(Qt::transparent);

        QPainter painter(&image);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.drawImage(0, 0, render);
        painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        painter.fillRect(render.rect(), QColor(0, 0, 0, m_opacity));
        return image;
    }
    return render;
}



TTKHeatMapLabel::TTKHeatMapLabel(QWidget *parent)
    : QLabel(parent)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    m_heatMapper = new HeatMapper(sizeHint());
}

TTKHeatMapLabel::~TTKHeatMapLabel()
{
    delete m_heatMapper;
}

void TTKHeatMapLabel::setRadius(int radius)
{
    if(m_heatMapper)
    {
        m_heatMapper->setRadius(radius);
        renderImage();
    }
}

void TTKHeatMapLabel::setOpacity(int opacity)
{
    if(m_heatMapper)
    {
        m_heatMapper->setOpacity(opacity);
        renderImage();
    }
}

void TTKHeatMapLabel::setColorScheme(HeatMapper::ColorScheme scheme)
{
    if(m_heatMapper)
    {
        m_heatMapper->setColorScheme(scheme);
        renderImage();
    }
}

void TTKHeatMapLabel::addPoint(int x, int y)
{
    if(m_heatMapper)
    {
        m_heatMapper->addPoint(x, y);
    }
}

void TTKHeatMapLabel::renderImage()
{
    if(m_heatMapper)
    {
        m_image = m_heatMapper->render();
        update();
    }
}

QSize TTKHeatMapLabel::sizeHint() const
{
    return QSize(200, 200);
}

void TTKHeatMapLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    if(!m_image.isNull())
    {
        painter.drawImage(0, 0, m_image);
    }
}
