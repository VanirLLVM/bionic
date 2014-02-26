/* Copyright (C) 2011-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gmail.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


/*
 * wrapper exp10f(x)
 */

#define _GNU_SOURCE 1
#include <math.h>
#include <math_private.h>

float
__exp10f (float x)
{
  float z = __ieee754_exp10f (x);
  if (__builtin_expect (!__isfinitef (z) || z == 0, 0)
      && __isfinitef (x) && _LIB_VERSION != _IEEE_)
    /* exp10f overflow (146) if x > 0, underflow (147) if x < 0.  */
    return __kernel_standard_f (x, x, 146 + !!__signbitf (x));

  return z;
}
__weak_reference (__exp10f, exp10f);
__strong_reference (__exp10f, __pow10f);
__weak_reference (__pow10f, pow10f);
