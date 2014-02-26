/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BIONIC_LIBM_GLIBC_COMPAT_H_included
#define _BIONIC_LIBM_GLIBC_COMPAT_H_included

#define DBL_MIN_10_EXP __DBL_MIN_10_EXP__

double __kernel_standard (double,double,int);

/* Support for various different standard error handling behaviors.  */
typedef enum
{
  _IEEE_ = -1,  /* According to IEEE 754/IEEE 854.  */
  _SVID_,       /* According to System V, release 4.  */
  _XOPEN_,      /* Nowadays also Unix98.  */
  _POSIX_,
  _ISOC_        /* Actually this is ISO C99.  */
} _LIB_VERSION_TYPE;

#ifdef __cplusplus
struct __exception
#else
struct exception
#endif
{
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};

/* Types of exceptions in the `type' field.  */
# define DOMAIN         1
# define SING           2
# define OVERFLOW       3
# define UNDERFLOW      4
# define TLOSS          5
# define PLOSS          6

/* This variable can be changed at run-time to any of the values above to
   affect floating point error handling behavior (it may also be necessary
   to change the hardware FPU exception settings).  */
extern _LIB_VERSION_TYPE _LIB_VERSION;

#endif
