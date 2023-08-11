#ifndef TTKVERSION_H
#define TTKVERSION_H

/***************************************************************************
 * This file is part of the TTK Library Module project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

//update time 2023.04.15
#define TTK_VERSION             0x02700
#define TTK_VERSION_STR         "2.7.0.0"
#define TTK_VERSION_TIME_STR    "(2023/04/15)"

#define TTK_MAJOR_VERSION 2
#define TTK_MIDLE_VERSION 7
#define TTK_MINOR_VERSION 0
#define TTK_PATCH_VERSION 0

#define TTK_RC_FILEVERSION      2,7,0,0
#define TTK_RC_PRODUCTVERSION   TTK_VERSION_STR
#define TTK_RC_COMPANY          "Greedysky Studio, Ltd."
#define TTK_RC_COPYRIGHT        "Copyright (C) 2023 Greedysky Studio"

#define TTK_VERSION_CHECK(major, middle, minor, patch) ((major<<12)|(middle<<8)|(minor<<4)|(patch))

#endif // TTKVERSION_H
