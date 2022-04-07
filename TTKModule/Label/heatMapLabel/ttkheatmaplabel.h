#ifndef TTKHEATMAPLABEL_H
#define TTKHEATMAPLABEL_H

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
    YlOrRdDiscrete,
    YlOrRdSoft,
    YlOrRdMixed,
    YlOrRdMixedExp,
    ///
    YlOrBrDiscrete,
    YlOrBrSoft,
    YlOrBrMixed,
    YlOrBrMixedExp,
    ///
    YlGnBuDiscrete,
    YlGnBuSoft,
    YlGnBuMixed,
    YlGnBuMixedExp,
    ///
    YlGnDiscrete,
    YlGnSoft,
    YlGnMixed,
    YlGnMixedExp,
    ///
    SpectralDiscrete,
    SpectralSoft,
    SpectralMixed,
    SpectralMixedExp,
    ///
    RedsDiscrete,
    RedsSoft,
    RedsMixed,
    RedsMixedExp,
    ///
    RdYlGnDiscrete,
    RdYlGnSoft,
    RdYlGnMixed,
    RdYlGnMixedExp,
    ///
    RdYlBuDiscrete,
    RdYlBuSoft,
    RdYlBuMixed,
    RdYlBuMixedExp,
    ///
    RdPuDiscrete,
    RdPuSoft,
    RdPuMixed,
    RdPuMixedExp,
    ///
    RdGyDiscrete,
    RdGySoft,
    RdGyMixed,
    RdGyMixedExp,
    ///
    RdBuDiscrete,
    RdBuSoft,
    RdBuMixed,
    RdBuMixedExp,
    ///
    PurplesDiscrete,
    PurplesSoft,
    PurplesMixed,
    PurplesMixedExp,
    ///
    PuRdDiscrete,
    PuRdSoft,
    PuRdMixed,
    PuRdMixedExp,
    ///
    PuOrDiscrete,
    PuOrSoft,
    PuOrMixed,
    PuOrMixedExp,
    ///
    PuBuGnDiscrete,
    PuBuGnSoft,
    PuBuGnMixed,
    PuBuGnMixedExp,
    ///
    PuBuDiscrete,
    PuBuSoft,
    PuBuMixed,
    PuBuMixedExp,
    ///
    PRGnDiscrete,
    PRGnSoft,
    PRGnMixed,
    PRGnMixedExp,
    ///
    PiYGDiscrete,
    PiYGSoft,
    PiYGMixed,
    PiYGMixedExp,
    ///
    OrRdDiscrete,
    OrRdSoft,
    OrRdMixed,
    OrRdMixedExp,
    ///
    OrangesDiscrete,
    OrangesSoft,
    OrangesMixed,
    OrangesMixedExp,
    ///
    GreysDiscrete,
    GreysSoft,
    GreysMixed,
    GreysMixedExp,
    ///
    GreensDiscrete,
    GreensSoft,
    GreensMixed,
    GreensMixedExp,
    ///
    B2w,
    B2wOpaque,
    W2b,
    W2bOpaque,
    ///
    GnBuDiscrete,
    GnBuSoft,
    GnBuMixed,
    GnBuMixedExp,
    ///
    BuPuDiscrete,
    BuPuSoft,
    BuPuMixed,
    BuPuMixedExp,
    ///
    BuGnDiscrete,
    BuGnSoft,
    BuGnMixed,
    BuGnMixedExp,
    ///
    BrBGDiscrete,
    BrBGSoft,
    BrBGMixed,
    BrBGMixedExp,
    ///
    BluesDiscrete,
    BluesSoft,
    BluesMixed,
    BluesMixedExp
  };

  explicit HeatMapper(const QSize &size);
  HeatMapper(const QSize &size, int radius);
  HeatMapper(int width, int height);
  HeatMapper(int width, int height, int radius);
  ~HeatMapper();

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
    ~TTKHeatMapLabel();

    void setRadius(int radius);
    void setOpacity(int opacity);
    void setColorScheme(HeatMapper::ColorScheme scheme);

    void addPoint(int x, int y);
    void renderImage();

    virtual QSize sizeHint() const override final;

protected:
    virtual void paintEvent(QPaintEvent *event) override final;

    HeatMapper *m_heatMapper;
    QImage m_image;

};

#endif // TTKHEATMAPLABEL_H
