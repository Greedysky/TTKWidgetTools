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
  case HeatMapper::YlOrRd_discrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::YlOrRd_soft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::YlOrRd_mixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::YlOrRd_mixed_exp: return heatmap_cs_YlOrRd_mixed_exp;
  ///
  case HeatMapper::YlOrBr_discrete: return heatmap_cs_YlOrBr_discrete;
  case HeatMapper::YlOrBr_soft: return heatmap_cs_YlOrBr_soft;
  case HeatMapper::YlOrBr_mixed: return heatmap_cs_YlOrBr_mixed;
  case HeatMapper::YlOrBr_mixed_exp: return heatmap_cs_YlOrBr_mixed_exp;
  ///
  case HeatMapper::YlGnBu_discrete: return heatmap_cs_YlGnBu_discrete;
  case HeatMapper::YlGnBu_soft: return heatmap_cs_YlGnBu_soft;
  case HeatMapper::YlGnBu_mixed: return heatmap_cs_YlGnBu_mixed;
  case HeatMapper::YlGnBu_mixed_exp: return heatmap_cs_YlGnBu_mixed_exp;
  ///
  case HeatMapper::YlGn_discrete: return heatmap_cs_YlGn_discrete;
  case HeatMapper::YlGn_soft: return heatmap_cs_YlGn_soft;
  case HeatMapper::YlGn_mixed: return heatmap_cs_YlGn_mixed;
  case HeatMapper::YlGn_mixed_exp: return heatmap_cs_YlGn_mixed_exp;
  ///
  case HeatMapper::Spectral_discrete: return heatmap_cs_Spectral_discrete;
  case HeatMapper::Spectral_soft: return heatmap_cs_Spectral_soft;
  case HeatMapper::Spectral_mixed: return heatmap_cs_Spectral_mixed;
  case HeatMapper::Spectral_mixed_exp: return heatmap_cs_Spectral_mixed_exp;
  ///
  case HeatMapper::Reds_discrete: return heatmap_cs_Reds_discrete;
  case HeatMapper::Reds_soft: return heatmap_cs_Reds_soft;
  case HeatMapper::Reds_mixed: return heatmap_cs_Reds_mixed;
  case HeatMapper::Reds_mixed_exp: return heatmap_cs_Reds_mixed_exp;
  ///
  case HeatMapper::RdYlGn_discrete: return heatmap_cs_RdYlGn_discrete;
  case HeatMapper::RdYlGn_soft: return heatmap_cs_RdYlGn_soft;
  case HeatMapper::RdYlGn_mixed: return heatmap_cs_RdYlGn_mixed;
  case HeatMapper::RdYlGn_mixed_exp: return heatmap_cs_RdYlGn_mixed_exp;
  ///
  case HeatMapper::RdYlBu_discrete: return heatmap_cs_RdYlBu_discrete;
  case HeatMapper::RdYlBu_soft: return heatmap_cs_RdYlBu_soft;
  case HeatMapper::RdYlBu_mixed: return heatmap_cs_RdYlBu_mixed;
  case HeatMapper::RdYlBu_mixed_exp: return heatmap_cs_RdYlBu_mixed_exp;
  ///
  case HeatMapper::RdPu_discrete: return heatmap_cs_RdPu_discrete;
  case HeatMapper::RdPu_soft: return heatmap_cs_RdPu_soft;
  case HeatMapper::RdPu_mixed: return heatmap_cs_RdPu_mixed;
  case HeatMapper::RdPu_mixed_exp: return heatmap_cs_RdPu_mixed_exp;
  ///
  case HeatMapper::RdGy_discrete: return heatmap_cs_RdGy_discrete;
  case HeatMapper::RdGy_soft: return heatmap_cs_RdGy_soft;
  case HeatMapper::RdGy_mixed: return heatmap_cs_RdGy_mixed;
  case HeatMapper::RdGy_mixed_exp: return heatmap_cs_RdGy_mixed_exp;
  ///
  case HeatMapper::RdBu_discrete: return heatmap_cs_RdBu_discrete;
  case HeatMapper::RdBu_soft: return heatmap_cs_RdBu_soft;
  case HeatMapper::RdBu_mixed: return heatmap_cs_RdBu_mixed;
  case HeatMapper::RdBu_mixed_exp: return heatmap_cs_RdBu_mixed_exp;
  ///
  case HeatMapper::Purples_discrete: return heatmap_cs_Purples_discrete;
  case HeatMapper::Purples_soft: return heatmap_cs_Purples_soft;
  case HeatMapper::Purples_mixed: return heatmap_cs_Purples_mixed;
  case HeatMapper::Purples_mixed_exp: return heatmap_cs_Purples_mixed_exp;
  ///
  case HeatMapper::PuRd_discrete: return heatmap_cs_PuRd_discrete;
  case HeatMapper::PuRd_soft: return heatmap_cs_PuRd_soft;
  case HeatMapper::PuRd_mixed: return heatmap_cs_PuRd_mixed;
  case HeatMapper::PuRd_mixed_exp: return heatmap_cs_PuRd_mixed_exp;
  ///
  case HeatMapper::PuOr_discrete: return heatmap_cs_PuOr_discrete;
  case HeatMapper::PuOr_soft: return heatmap_cs_PuOr_soft;
  case HeatMapper::PuOr_mixed: return heatmap_cs_PuOr_mixed;
  case HeatMapper::PuOr_mixed_exp: return heatmap_cs_PuOr_mixed_exp;
  ///
  case HeatMapper::PuBuGn_discrete: return heatmap_cs_PuBuGn_discrete;
  case HeatMapper::PuBuGn_soft: return heatmap_cs_PuBuGn_soft;
  case HeatMapper::PuBuGn_mixed: return heatmap_cs_PuBuGn_mixed;
  case HeatMapper::PuBuGn_mixed_exp: return heatmap_cs_PuBuGn_mixed_exp;
  ///
  case HeatMapper::PuBu_discrete: return heatmap_cs_PuBu_discrete;
  case HeatMapper::PuBu_soft: return heatmap_cs_PuBu_soft;
  case HeatMapper::PuBu_mixed: return heatmap_cs_PuBu_mixed;
  case HeatMapper::PuBu_mixed_exp: return heatmap_cs_PuBu_mixed_exp;
  ///
  case HeatMapper::PRGn_discrete: return heatmap_cs_PRGn_discrete;
  case HeatMapper::PRGn_soft: return heatmap_cs_PRGn_soft;
  case HeatMapper::PRGn_mixed: return heatmap_cs_PRGn_mixed;
  case HeatMapper::PRGn_mixed_exp: return heatmap_cs_PRGn_mixed_exp;
  ///
  case HeatMapper::PiYG_discrete: return heatmap_cs_PiYG_discrete;
  case HeatMapper::PiYG_soft: return heatmap_cs_PiYG_soft;
  case HeatMapper::PiYG_mixed: return heatmap_cs_PiYG_mixed;
  case HeatMapper::PiYG_mixed_exp: return heatmap_cs_PiYG_mixed_exp;
  ///
  case HeatMapper::OrRd_discrete: return heatmap_cs_OrRd_discrete;
  case HeatMapper::OrRd_soft: return heatmap_cs_OrRd_soft;
  case HeatMapper::OrRd_mixed: return heatmap_cs_OrRd_mixed;
  case HeatMapper::OrRd_mixed_exp: return heatmap_cs_OrRd_mixed_exp;
  ///
  case HeatMapper::Oranges_discrete: return heatmap_cs_Oranges_discrete;
  case HeatMapper::Oranges_soft: return heatmap_cs_Oranges_soft;
  case HeatMapper::Oranges_mixed: return heatmap_cs_Oranges_mixed;
  case HeatMapper::Oranges_mixed_exp: return heatmap_cs_Oranges_mixed_exp;
  ///
  case HeatMapper::Greys_discrete: return heatmap_cs_Greys_discrete;
  case HeatMapper::Greys_soft: return heatmap_cs_Greys_soft;
  case HeatMapper::Greys_mixed: return heatmap_cs_Greys_mixed;
  case HeatMapper::Greys_mixed_exp: return heatmap_cs_Greys_mixed_exp;
  ///
  case HeatMapper::Greens_discrete: return heatmap_cs_Greens_discrete;
  case HeatMapper::Greens_soft: return heatmap_cs_Greens_soft;
  case HeatMapper::Greens_mixed: return heatmap_cs_Greens_mixed;
  case HeatMapper::Greens_mixed_exp: return heatmap_cs_Greens_mixed_exp;
  ///
  case HeatMapper::b2w: return heatmap_cs_b2w;
  case HeatMapper::b2w_opaque: return heatmap_cs_b2w_opaque;
  case HeatMapper::w2b: return heatmap_cs_w2b;
  case HeatMapper::w2b_opaque: return heatmap_cs_w2b_opaque;
  ///
  case HeatMapper::GnBu_discrete: return heatmap_cs_GnBu_discrete;
  case HeatMapper::GnBu_soft: return heatmap_cs_GnBu_soft;
  case HeatMapper::GnBu_mixed: return heatmap_cs_GnBu_mixed;
  case HeatMapper::GnBu_mixed_exp: return heatmap_cs_GnBu_mixed_exp;
  ///
  case HeatMapper::BuPu_discrete: return heatmap_cs_BuPu_discrete;
  case HeatMapper::BuPu_soft: return heatmap_cs_BuPu_soft;
  case HeatMapper::BuPu_mixed: return heatmap_cs_BuPu_mixed;
  case HeatMapper::BuPu_mixed_exp: return heatmap_cs_BuPu_mixed_exp;
  ///
  case HeatMapper::BuGn_discrete: return heatmap_cs_BuGn_discrete;
  case HeatMapper::BuGn_soft: return heatmap_cs_BuGn_soft;
  case HeatMapper::BuGn_mixed: return heatmap_cs_BuGn_mixed;
  case HeatMapper::BuGn_mixed_exp: return heatmap_cs_BuGn_mixed_exp;
  ///
  case HeatMapper::BrBG_discrete: return heatmap_cs_BrBG_discrete;
  case HeatMapper::BrBG_soft: return heatmap_cs_BrBG_soft;
  case HeatMapper::BrBG_mixed: return heatmap_cs_BrBG_mixed;
  case HeatMapper::BrBG_mixed_exp: return heatmap_cs_BrBG_mixed_exp;
  ///
  case HeatMapper::Blues_discrete: return heatmap_cs_Blues_discrete;
  case HeatMapper::Blues_soft: return heatmap_cs_Blues_soft;
  case HeatMapper::Blues_mixed: return heatmap_cs_Blues_mixed;
  case HeatMapper::Blues_mixed_exp: return heatmap_cs_Blues_mixed_exp;
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
