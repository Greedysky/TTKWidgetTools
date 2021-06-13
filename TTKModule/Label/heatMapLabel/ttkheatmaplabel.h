#ifndef TTKHEATMAPLABEL_H
#define TTKHEATMAPLABEL_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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

#include <QLabel>
#include <QTimer>
#include "ttkglobaldefine.h"

typedef struct heatmap_t DataObject;
typedef struct heatmap_stamp_t DataStamp;
///
using DataRange = std::vector<unsigned char>;
///
class TTK_MODULE_EXPORT HeatMapper
{
public:
  enum ColorScheme
  {
    Default,
    ///
    YlOrRd_discrete,
    YlOrRd_soft,
    YlOrRd_mixed,
    YlOrRd_mixed_exp,
    ///
    YlOrBr_discrete,
    YlOrBr_soft,
    YlOrBr_mixed,
    YlOrBr_mixed_exp,
    ///
    YlGnBu_discrete,
    YlGnBu_soft,
    YlGnBu_mixed,
    YlGnBu_mixed_exp,
    ///
    YlGn_discrete,
    YlGn_soft,
    YlGn_mixed,
    YlGn_mixed_exp,
    ///
    Spectral_discrete,
    Spectral_soft,
    Spectral_mixed,
    Spectral_mixed_exp,
    ///
    Reds_discrete,
    Reds_soft,
    Reds_mixed,
    Reds_mixed_exp,
    ///
    RdYlGn_discrete,
    RdYlGn_soft,
    RdYlGn_mixed,
    RdYlGn_mixed_exp,
    ///
    RdYlBu_discrete,
    RdYlBu_soft,
    RdYlBu_mixed,
    RdYlBu_mixed_exp,
    ///
    RdPu_discrete,
    RdPu_soft,
    RdPu_mixed,
    RdPu_mixed_exp,
    ///
    RdGy_discrete,
    RdGy_soft,
    RdGy_mixed,
    RdGy_mixed_exp,
    ///
    RdBu_discrete,
    RdBu_soft,
    RdBu_mixed,
    RdBu_mixed_exp,
    ///
    Purples_discrete,
    Purples_soft,
    Purples_mixed,
    Purples_mixed_exp,
    ///
    PuRd_discrete,
    PuRd_soft,
    PuRd_mixed,
    PuRd_mixed_exp,
    ///
    PuOr_discrete,
    PuOr_soft,
    PuOr_mixed,
    PuOr_mixed_exp,
    ///
    PuBuGn_discrete,
    PuBuGn_soft,
    PuBuGn_mixed,
    PuBuGn_mixed_exp,
    ///
    PuBu_discrete,
    PuBu_soft,
    PuBu_mixed,
    PuBu_mixed_exp,
    ///
    PRGn_discrete,
    PRGn_soft,
    PRGn_mixed,
    PRGn_mixed_exp,
    ///
    PiYG_discrete,
    PiYG_soft,
    PiYG_mixed,
    PiYG_mixed_exp,
    ///
    OrRd_discrete,
    OrRd_soft,
    OrRd_mixed,
    OrRd_mixed_exp,
    ///
    Oranges_discrete,
    Oranges_soft,
    Oranges_mixed,
    Oranges_mixed_exp,
    ///
    Greys_discrete,
    Greys_soft,
    Greys_mixed,
    Greys_mixed_exp,
    ///
    Greens_discrete,
    Greens_soft,
    Greens_mixed,
    Greens_mixed_exp,
    ///
    b2w,
    b2w_opaque,
    w2b,
    w2b_opaque,
    ///
    GnBu_discrete,
    GnBu_soft,
    GnBu_mixed,
    GnBu_mixed_exp,
    ///
    BuPu_discrete,
    BuPu_soft,
    BuPu_mixed,
    BuPu_mixed_exp,
    ///
    BuGn_discrete,
    BuGn_soft,
    BuGn_mixed,
    BuGn_mixed_exp,
    ///
    BrBG_discrete,
    BrBG_soft,
    BrBG_mixed,
    BrBG_mixed_exp,
    ///
    Blues_discrete,
    Blues_soft,
    Blues_mixed,
    Blues_mixed_exp
  };

  explicit HeatMapper(const QSize &size);
  HeatMapper(const QSize &size, int radius);
  HeatMapper(int width, int height);
  HeatMapper(int width, int height, int radius);
  virtual ~HeatMapper();

  void setRadius(int radius);
  void setOpacity(int opacity);
  void setColorScheme(ColorScheme scheme);

  void addPoint(int x, int y);

  QImage render();

private:
  int m_opacity;
  DataObject *m_heatmap;
  DataStamp *m_stamp;
  ColorScheme m_scheme;

};


/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKHeatMapLabel : public QLabel
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKHeatMapLabel)
public:
    explicit TTKHeatMapLabel(QWidget *parent = nullptr);
    virtual ~TTKHeatMapLabel();

    void setRadius(int radius);
    void setOpacity(int opacity);
    void setColorScheme(HeatMapper::ColorScheme scheme);

    void addPoint(int x, int y);
    void renderImage();

    virtual QSize sizeHint() const override;

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    HeatMapper *m_heatMapper;
    QImage m_image;

};

#endif // TTKHEATMAPLABEL_H
