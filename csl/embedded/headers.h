/* headers.h                       Copyright (C) 2005-2010 Codemist Ltd */

#ifndef header_headers_h
#define header_headers_h 1



/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 2903263c 16-Aug-2010 */

/*
 * #include the majority of the header files needed by CSL code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/*
 * I will check a number of things before I try to use sigaltstack()
 */
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifndef UNDER_CE
/*
 * The test for UNDER_CE is a little odd here, but when I once compiled a
 * version of this to run under Windows CE on an Ipaq I could not have
 * signal handling there hence this. One mighht have expected me to say
 * #ifdef HAVE_SIGNAL_H but maybe the file existed in the world where I
 * cross-built for CE and that led to pain? I now forget.
 */
#include <signal.h>
#endif

#ifndef __cplusplus
#include <setjmp.h>
#endif

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "syscsl.h"
#include "arith.h"
#include "entries.h"
#include "proc.h"
#include "stream.h"
#include "cslread.h"

#ifdef HAVE_FWIN
#include "fwin.h"
#endif

#endif /* this header included already */

/* end of headers.h */

