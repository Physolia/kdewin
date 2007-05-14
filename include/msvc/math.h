/*
   This file is part of the KDE libraries
   Copyright (C) 2005 Christian ehrlicher <ch.ehrlicher@gmx.de>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef KDEWIN_MATH_H
#define KDEWIN_MATH_H

// include everywhere
#include <sys/types.h>

/* regular header from msvc includes */
#define _USE_MATH_DEFINES
#include <../include/math.h>

#include <../include/float.h>

#include <errno.h>
#include <limits.h>

#define isnan _isnan
#define finite _finite

// some functions which aren't available with msvc
// float rintf( float x )
// double rint( double x )
// long double rintl( long double x )

// long lroundf ( float x )
// long lround ( double x )
// long lroundl ( long double x )

// float roundf ( float x )
// double round ( double x )
// long double roundl ( long double x )

// float nearbyintf(float x)
// double nearbyint(double x)
// long double nearbyintl(long double x)

// this is easy
__inline float rintf( float x )
{
    __asm {
        fld x
        frndint
    }
}

__inline double rint( double x )
{
    __asm {
        fld x
        frndint
    }
}

__inline long double rintl( long double x )
{
    __asm {
        fld x
        frndint
    }
}

__inline long lroundf ( float x )
{
  /* Add +/- 0.5, then round towards zero.  */
  float tmp = floorf ( x );
  if (isnan (tmp)
      || tmp > (float)LONG_MAX
      || tmp < (float)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0F ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

__inline long lround ( double x )
{
  /* Add +/- 0.5 then then round towards zero.  */
  double tmp = floor ( x );
  if (isnan (tmp)
      || tmp > (double)LONG_MAX
      || tmp < (double)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0 ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

__inline long lroundl ( long double x )
{
  /* Add +/- 0.5, then round towards zero.  */
  long double tmp = floorl ( x );
  if (isnan (tmp)
      || tmp > (long double)LONG_MAX
      || tmp < (long double)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0L ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

__inline float roundf ( float x )
{
  return (float)lroundf( x );
}

__inline double round ( double x )
{
  return (double)lround( x );
}

__inline long double roundl ( long double x )
{
  return (long double)lroundl( x );
}

// this is a little bit more complicated - don't raise an exception
// -> set fpu control word bit 5 so it won't generate one
__inline float nearbyintf(float x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

__inline double nearbyint(double x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

__inline long double nearbyintl(long double x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

#ifdef __cplusplus
// convenience function to avoid useless casts from int to whatever
__inline long double log(int x)
{
    return logl((long double)x);	
}

__inline long double floor(int x)
{
    return floor((long double)x);	
}
#endif

#endif /* KDEWIN_MATH_H */
