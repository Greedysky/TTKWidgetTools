#ifndef TTKGLOBALDEFINE_H
#define TTKGLOBALDEFINE_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2019 Greedysky Studio

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

#include <QObject>

///
#ifdef TTK_LIBRARY
#  define TTK_EXPORT
#endif

#define TTK_BUILD_EXAMPLE

#ifdef TTK_EXPORT
#  define TTK_CORE_EXPORT Q_DECL_EXPORT
#else
#  define TTK_CORE_IMPORT Q_DECL_IMPORT
#endif

#endif // TTKGLOBALDEFINE_H
