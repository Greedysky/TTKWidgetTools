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

const heatmap_colorscheme_t * MappingColorScheme(HeatMapper::ColorScheme scheme)
{
  switch(scheme)
  {
  case HeatMapper::YlOrRdDiscrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::YlOrRdSoft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::YlOrRdMixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::YlOrRdMixedExp: return heatmap_cs_YlOrRd_mixed_exp;
  ///
  case HeatMapper::YlOrBrDiscrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::YlOrBrSoft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::YlOrBrMixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::YlOrBrMixedExp: return heatmap_cs_YlOrBr_mixed_exp;
  ///
  case HeatMapper::YlGnBuDiscrete: return heatmap_cs_YlGnBu_discrete;
  case HeatMapper::YlGnBuSoft: return heatmap_cs_YlGnBu_soft;
  case HeatMapper::YlGnBuMixed: return heatmap_cs_YlGnBu_mixed;
  case HeatMapper::YlGnBuMixedExp: return heatmap_cs_YlGnBu_mixed_exp;
  ///
  case HeatMapper::YlGnDiscrete: return heatmap_cs_YlGn_discrete;
  case HeatMapper::YlGnSoft: return heatmap_cs_YlGn_soft;
  case HeatMapper::YlGnMixed: return heatmap_cs_YlGn_mixed;
  case HeatMapper::YlGnMixedExp: return heatmap_cs_YlGn_mixed_exp;
  ///
  case HeatMapper::SpectralDiscrete: return heatmap_cs_Spectral_discrete;
  case HeatMapper::SpectralSoft: return heatmap_cs_Spectral_soft;
  case HeatMapper::SpectralMixed: return heatmap_cs_Spectral_mixed;
  case HeatMapper::SpectralMixedExp: return heatmap_cs_Spectral_mixed_exp;
  ///
  case HeatMapper::RedsDiscrete: return heatmap_cs_Reds_discrete;
  case HeatMapper::RedsSoft: return heatmap_cs_Reds_soft;
  case HeatMapper::RedsMixed: return heatmap_cs_Reds_mixed;
  case HeatMapper::RedsMixedExp: return heatmap_cs_Reds_mixed_exp;
  ///
  case HeatMapper::RdYlGnDiscrete: return heatmap_cs_RdYlGn_discrete;
  case HeatMapper::RdYlGnSoft: return heatmap_cs_RdYlGn_soft;
  case HeatMapper::RdYlGnMixed: return heatmap_cs_RdYlGn_mixed;
  case HeatMapper::RdYlGnMixedExp: return heatmap_cs_RdYlGn_mixed_exp;
  ///
  case HeatMapper::RdYlBuDiscrete: return heatmap_cs_RdYlBu_discrete;
  case HeatMapper::RdYlBuSoft: return heatmap_cs_RdYlBu_soft;
  case HeatMapper::RdYlBuMixed: return heatmap_cs_RdYlBu_mixed;
  case HeatMapper::RdYlBuMixedExp: return heatmap_cs_RdYlBu_mixed_exp;
  ///
  case HeatMapper::RdPuDiscrete: return heatmap_cs_RdPu_discrete;
  case HeatMapper::RdPuSoft: return heatmap_cs_RdPu_soft;
  case HeatMapper::RdPuMixed: return heatmap_cs_RdPu_mixed;
  case HeatMapper::RdPuMixedExp: return heatmap_cs_RdPu_mixed_exp;
  ///
  case HeatMapper::RdGyDiscrete: return heatmap_cs_RdGy_discrete;
  case HeatMapper::RdGySoft: return heatmap_cs_RdGy_soft;
  case HeatMapper::RdGyMixed: return heatmap_cs_RdGy_mixed;
  case HeatMapper::RdGyMixedExp: return heatmap_cs_RdGy_mixed_exp;
  ///
  case HeatMapper::RdBuDiscrete: return heatmap_cs_RdBu_discrete;
  case HeatMapper::RdBuSoft: return heatmap_cs_RdBu_soft;
  case HeatMapper::RdBuMixed: return heatmap_cs_RdBu_mixed;
  case HeatMapper::RdBuMixedExp: return heatmap_cs_RdBu_mixed_exp;
  ///
  case HeatMapper::PurplesDiscrete: return heatmap_cs_Purples_discrete;
  case HeatMapper::PurplesSoft: return heatmap_cs_Purples_soft;
  case HeatMapper::PurplesMixed: return heatmap_cs_Purples_mixed;
  case HeatMapper::PurplesMixedExp: return heatmap_cs_Purples_mixed_exp;
  ///
  case HeatMapper::PuRdDiscrete: return heatmap_cs_PuRd_discrete;
  case HeatMapper::PuRdSoft: return heatmap_cs_PuRd_soft;
  case HeatMapper::PuRdMixed: return heatmap_cs_PuRd_mixed;
  case HeatMapper::PuRdMixedExp: return heatmap_cs_PuRd_mixed_exp;
  ///
  case HeatMapper::PuOrDiscrete: return heatmap_cs_PuOr_discrete;
  case HeatMapper::PuOrSoft: return heatmap_cs_PuOr_soft;
  case HeatMapper::PuOrMixed: return heatmap_cs_PuOr_mixed;
  case HeatMapper::PuOrMixedExp: return heatmap_cs_PuOr_mixed_exp;
  ///
  case HeatMapper::PuBuGnDiscrete: return heatmap_cs_PuBuGn_discrete;
  case HeatMapper::PuBuGnSoft: return heatmap_cs_PuBuGn_soft;
  case HeatMapper::PuBuGnMixed: return heatmap_cs_PuBuGn_mixed;
  case HeatMapper::PuBuGnMixedExp: return heatmap_cs_PuBuGn_mixed_exp;
  ///
  case HeatMapper::PuBuDiscrete: return heatmap_cs_PuBu_discrete;
  case HeatMapper::PuBuSoft: return heatmap_cs_PuBu_soft;
  case HeatMapper::PuBuMixed: return heatmap_cs_PuBu_mixed;
  case HeatMapper::PuBuMixedExp: return heatmap_cs_PuBu_mixed_exp;
  ///
  case HeatMapper::PRGnDiscrete: return heatmap_cs_PRGn_discrete;
  case HeatMapper::PRGnSoft: return heatmap_cs_PRGn_soft;
  case HeatMapper::PRGnMixed: return heatmap_cs_PRGn_mixed;
  case HeatMapper::PRGnMixedExp: return heatmap_cs_PRGn_mixed_exp;
  ///
  case HeatMapper::PiYGDiscrete: return heatmap_cs_PiYG_discrete;
  case HeatMapper::PiYGSoft: return heatmap_cs_PiYG_soft;
  case HeatMapper::PiYGMixed: return heatmap_cs_PiYG_mixed;
  case HeatMapper::PiYGMixedExp: return heatmap_cs_PiYG_mixed_exp;
  ///
  case HeatMapper::OrRdDiscrete: return heatmap_cs_OrRd_discrete;
  case HeatMapper::OrRdSoft: return heatmap_cs_OrRd_soft;
  case HeatMapper::OrRdMixed: return heatmap_cs_OrRd_mixed;
  case HeatMapper::OrRdMixedExp: return heatmap_cs_OrRd_mixed_exp;
  ///
  case HeatMapper::OrangesDiscrete: return heatmap_cs_Oranges_discrete;
  case HeatMapper::OrangesSoft: return heatmap_cs_Oranges_soft;
  case HeatMapper::OrangesMixed: return heatmap_cs_Oranges_mixed;
  case HeatMapper::OrangesMixedExp: return heatmap_cs_Oranges_mixed_exp;
  ///
  case HeatMapper::GreysDiscrete: return heatmap_cs_Greys_discrete;
  case HeatMapper::GreysSoft: return heatmap_cs_Greys_soft;
  case HeatMapper::GreysMixed: return heatmap_cs_Greys_mixed;
  case HeatMapper::GreysMixedExp: return heatmap_cs_Greys_mixed_exp;
  ///
  case HeatMapper::GreensDiscrete: return heatmap_cs_Greens_discrete;
  case HeatMapper::GreensSoft: return heatmap_cs_Greens_soft;
  case HeatMapper::GreensMixed: return heatmap_cs_Greens_mixed;
  case HeatMapper::GreensMixedExp: return heatmap_cs_Greens_mixed_exp;
  ///
  case HeatMapper::B2w: return heatmap_cs_b2w;
  case HeatMapper::B2wOpaque: return heatmap_cs_b2w_opaque;
  case HeatMapper::W2b: return heatmap_cs_w2b;
  case HeatMapper::W2bOpaque: return heatmap_cs_w2b_opaque;
  ///
  case HeatMapper::GnBuDiscrete: return heatmap_cs_GnBu_discrete;
  case HeatMapper::GnBuSoft: return heatmap_cs_GnBu_soft;
  case HeatMapper::GnBuMixed: return heatmap_cs_GnBu_mixed;
  case HeatMapper::GnBuMixedExp: return heatmap_cs_GnBu_mixed_exp;
  ///
  case HeatMapper::BuPuDiscrete: return heatmap_cs_BuPu_discrete;
  case HeatMapper::BuPuSoft: return heatmap_cs_BuPu_soft;
  case HeatMapper::BuPuMixed: return heatmap_cs_BuPu_mixed;
  case HeatMapper::BuPuMixedExp: return heatmap_cs_BuPu_mixed_exp;
  ///
  case HeatMapper::BuGnDiscrete: return heatmap_cs_BuGn_discrete;
  case HeatMapper::BuGnSoft: return heatmap_cs_BuGn_soft;
  case HeatMapper::BuGnMixed: return heatmap_cs_BuGn_mixed;
  case HeatMapper::BuGnMixedExp: return heatmap_cs_BuGn_mixed_exp;
  ///
  case HeatMapper::BrBGDiscrete: return heatmap_cs_BrBG_discrete;
  case HeatMapper::BrBGSoft: return heatmap_cs_BrBG_soft;
  case HeatMapper::BrBGMixed: return heatmap_cs_BrBG_mixed;
  case HeatMapper::BrBGMixedExp: return heatmap_cs_BrBG_mixed_exp;
  ///
  case HeatMapper::BluesDiscrete: return heatmap_cs_Blues_discrete;
  case HeatMapper::BluesSoft: return heatmap_cs_Blues_soft;
  case HeatMapper::BluesMixed: return heatmap_cs_Blues_mixed;
  case HeatMapper::BluesMixedExp: return heatmap_cs_Blues_mixed_exp;
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
{
  m_opacity = DEFAULT_OPACITY;
  m_heatmap = heatmap_new(width, height);
  m_stamp = nullptr;
  m_scheme = Default;
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
  render.loadFromData(&output[0], output.size());

  if(m_opacity != DEFAULT_OPACITY)
  {
    QImage image(render.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawImage(0, 0, render);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.fillRect(render.rect(), QColor(0, 0, 0, m_opacity));
    painter.end();

    return image;
  }

  return render;
}



TTKHeatMapLabel::TTKHeatMapLabel(QWidget *parent)
    : QLabel(parent)
{
    setWindowFlags( Qt::Window | Qt::FramelessWindowHint);
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
    return QSize(180, 180);
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
