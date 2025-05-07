#ifndef TTKVERSION_H
#define TTKVERSION_H

/***************************************************************************
 * This file is part of the TTK Library Module project
 * Copyright (C) 2015 - 2025 Greedysky Studio

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

//update time 2025.05.05
#define TTK_MAJOR_VERSION 3
#define TTK_MINOR_VERSION 1
#define TTK_PATCH_VERSION 0

#define TTK_VERSION             TTK_VERSION_CHECK(TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0)
#define TTK_VERSION_STR         TTK_VERSION_CHECK_STR(TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0)
#define TTK_VERSION_TIME_STR    "(2025/05/05)"

#define TTK_RC_FILEVERSION      TTK_MAJOR_VERSION, TTK_MINOR_VERSION, TTK_PATCH_VERSION, 0
#define TTK_RC_PRODUCTVERSION   TTK_VERSION_STR
#define TTK_RC_COMPANY          "Greedysky Studio"
#define TTK_RC_COPYRIGHT        "Copyright (C) 2025 Greedysky Studio"

#define TTK_VERSION_CHECK(major, middle, minor, patch)        ((major<<12)|(middle<<8)|(minor<<4)|(patch))
#define TTK_VERSION_CHECK_STR(major, middle, minor, patch)    TTK_VERSION_CHECK_STR_I(major, middle, minor, patch)
#define TTK_VERSION_CHECK_STR_I(major, middle, minor, patch)  #major "." #middle "." #minor "." #patch

#endif // TTKVERSION_H
