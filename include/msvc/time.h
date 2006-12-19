/* This file is part of the KDE project
   Copyright (C) 2006 Christian Ehrlicher <ch.ehrlicher@gmx.de>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef KDEWIN32_TIME_H
#define KDEWIN32_TIME_H

// include everywhere
#include <sys/types.h>

#include <../include/time.h>

#define timezone _timezone

#ifdef __cplusplus
extern "C" {
#endif 

KDEWIN32_EXPORT struct tm *localtime_r(const time_t *clock, struct tm *result);
KDEWIN32_EXPORT struct tm *gmtime_r(const time_t *clock, struct tm *result);
KDEWIN32_EXPORT char *strptime (const char *buf, const char *format, struct tm *tm);

#ifdef __cplusplus
}
#endif 

#endif  // KDEWIN32_TIME_H
