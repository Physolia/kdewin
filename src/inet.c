/* This file is part of the KDE project
   Copyright (C) 2006 Peter K�mmel

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

#include <winposix_export.h>

#include <sys/socket.h>

KDEWIN32_EXPORT
const char *inet_ntop(int af, const void * src, char * dst, socklen_t size)
{
	//TODO
	return 0;
}

KDEWIN32_EXPORT int inet_pton(int af, const char * src, void * dst)
{
	//TODO
	return -1;
}