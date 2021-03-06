// arith-compare-cpp                       Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

// $Id: arith-compare.cpp 6233 2022-01-20 22:10:59Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
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

#include "headers.h"
#include "dispatch.h"

using number_dispatcher::Fixnum;
// uint64_t *
using number_dispatcher::Rat;
using number_dispatcher::Cpx;
using number_dispatcher::SFlt;
// double
using number_dispatcher::Flt;
using number_dispatcher::LFlt;

bool Eqn::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

bool Eqn::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Eqn>("eqn", a, b);
}

// fixnum == fixnum

bool Eqn::op(Fixnum a, Fixnum b)
{   return (a.intval() == b.intval());
}
// bignum == fixnum
bool Eqn::op(uint64_t *a, Fixnum b)
{   return false;
}
// rational == fixnum
bool Eqn::op(Rat a, Fixnum b)
{   return false;
}
// complex == fixnum
bool Eqn::op(Cpx a, Fixnum b)
{   return false;
}
// short float == fixnum
bool Eqn::op(SFlt a, Fixnum b)
{   return false;
}
// single float == fixnum
bool Eqn::op(Flt a, Fixnum b)
{   return false;
}
// double float == fixnum
bool Eqn::op(double a, Fixnum b)
{   return false;
}
// long float == fixnum
bool Eqn::op(LFlt a, Fixnum b)
{   return false;
}
// fixnum == bignum
bool Eqn::op(Fixnum a, uint64_t *b)
{   return false;
}
// bignum == bignum
bool Eqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}
// rational == bignum
bool Eqn::op(Rat a, uint64_t *b)
{   return false;
}
// complex == bignum
bool Eqn::op(Cpx a, uint64_t *b)
{   return false;
}
// short float == bignum
bool Eqn::op(SFlt a, uint64_t *b)
{   return false;
}
// single float == bignum
bool Eqn::op(Flt a, uint64_t *b)
{   return false;
}
// double float == bignum
bool Eqn::op(double a, uint64_t *b)
{   return false;
}
// long float == bignum
bool Eqn::op(LFlt a, uint64_t *b)
{   return false;
}
// fixnum == rational
bool Eqn::op(Fixnum a, Rat b)
{   return false;
}
// bignum == rational
bool Eqn::op(uint64_t *a, Rat b)
{   return false;
}
// rational == rational
bool Eqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Eqn::op(p1, p2) && Eqn::op(q1, q2);
}
// complex == rational
bool Eqn::op(Cpx a, Rat b)
{   return false;
}
// short float == rational
bool Eqn::op(SFlt a, Rat b)
{   return false;
}
// single float == rational
bool Eqn::op(Flt a, Rat b)
{   return false;
}
// double float == rational
bool Eqn::op(double a, Rat b)
{   return false;
}
// long float == rational
bool Eqn::op(LFlt a, Rat b)
{   return false;
}
// fixnum == complex
bool Eqn::op(Fixnum a, Cpx b)
{   return false;
}
// bignum == complex
bool Eqn::op(uint64_t *a, Cpx b)
{   return false;
}
// rational == complex
bool Eqn::op(Rat a, Cpx b)
{   return false;
}
// complex == complex
bool Eqn::op(Cpx a, Cpx b)
{   return (Eqn::op(a.real_part(), b.real_part()) &&
            Eqn::op(a.imag_part(), b.imag_part()));
}
// short float == complex
bool Eqn::op(SFlt a, Cpx b)
{   return false;
}
// single float == complex
bool Eqn::op(Flt a, Cpx b)
{   return false;
}
// double float == complex
bool Eqn::op(double a, Cpx b)
{   return false;
}
// long float == complex
bool Eqn::op(LFlt a, Cpx b)
{   return false;
}
// fixnum == short float
bool Eqn::op(Fixnum a, SFlt b)
{   return false;
}
// bignum == short float
bool Eqn::op(uint64_t *a, SFlt b)
{   return false;
}
// rational == short float
bool Eqn::op(Rat a, SFlt b)
{   return false;
}
// complex == short float
bool Eqn::op(Cpx a, SFlt b)
{   return false;
}
// short float == short float
bool Eqn::op(SFlt a, SFlt b)
{   return (a.floatval() == b.floatval());
}
// single float == short float
bool Eqn::op(Flt a, SFlt b)
{   return false;
}
// double float == short float
bool Eqn::op(double a, SFlt b)
{   return false;
}
// long float == short float
bool Eqn::op(LFlt a, SFlt b)
{   return false;
}
// fixnum == single float
bool Eqn::op(Fixnum a, Flt b)
{   return false;
}
// bignum == single float
bool Eqn::op(uint64_t *a, Flt b)
{   return false;
}
// rational == single float
bool Eqn::op(Rat a, Flt b)
{   return false;
}
// complex == single float
bool Eqn::op(Cpx a, Flt b)
{   return false;
}
// short float == single float
bool Eqn::op(SFlt a, Flt b)
{   return false;
}
// single float == single float
bool Eqn::op(Flt a, Flt b)
{   return (a.floatval() == b.floatval());
}
// double float == single float
bool Eqn::op(double a, Flt b)
{   return false;
}
// long float == single float
bool Eqn::op(LFlt a, Flt b)
{   return false;
}
// fixnum == double float
bool Eqn::op(Fixnum a, double b)
{   return false;
}
// bignum == double float
bool Eqn::op(uint64_t *a, double b)
{   return false;
}
// rational == double float
bool Eqn::op(Rat a, double b)
{   return false;
}
// complex == double float
bool Eqn::op(Cpx a, double b)
{   return false;
}
// short float == double float
bool Eqn::op(SFlt a, double b)
{   return false;
}
// single float == double float
bool Eqn::op(Flt a, double b)
{   return false;
}
// double float == double float
bool Eqn::op(double a, double b)
{   return (a == b);
}
// long float == double float
bool Eqn::op(LFlt a, double b)
{   return false;
}
// fixnum == long float
bool Eqn::op(Fixnum a, LFlt b)
{   return false;
}
// bignum == long float
bool Eqn::op(uint64_t *a, LFlt b)
{   return false;
}
// rational == long float
bool Eqn::op(Rat a, LFlt b)
{   return false;
}
// complex == long float
bool Eqn::op(Cpx a, LFlt b)
{   return false;
}
// short float == long float
bool Eqn::op(SFlt a, LFlt b)
{   return false;
}
// single float == long float
bool Eqn::op(Flt a, LFlt b)
{   return false;
}
// double float == long float
bool Eqn::op(double a, LFlt b)
{   return false;
}
// long float == long float
bool Eqn::op(LFlt a, LFlt b)
{   return f128_eq(a.floatval(), b.floatval());
}

bool CLEqn::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

bool CLEqn::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,CLEqn>("eqn", a, b);
}

// fixnum CL== fixnum

bool CLEqn::op(Fixnum a, Fixnum b)
{   return (a.intval() == b.intval());
}
// bignum CL== fixnum
bool CLEqn::op(uint64_t *a, Fixnum b)
{   return false;
}
// rational CL== fixnum
bool CLEqn::op(Rat a, Fixnum b)
{   return false;
}
// complex CL== fixnum
bool CLEqn::op(Cpx a, Fixnum b)
{   return false;
}
// short float CL== fixnum
bool CLEqn::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b.intval());
}
// single float CL== fixnum
bool CLEqn::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b.intval());
}
// double float CL== fixnum
bool CLEqn::op(double a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(a, b.intval());
}
// long float CL== fixnum
bool CLEqn::op(LFlt a, Fixnum b)
{   return arithlib_lowlevel::Eqn::op(a.floatval(), b.intval());
}
// fixnum CL== bignum
bool CLEqn::op(Fixnum a, uint64_t *b)
{   return false;
}
// bignum CL== bignum
bool CLEqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}
// rational CL== bignum
bool CLEqn::op(Rat a, uint64_t *b)
{   return false;
}
// complex CL== bignum
bool CLEqn::op(Cpx a, uint64_t *b)
{   return false;
}
// short float CL== bignum
bool CLEqn::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b);
}
// single float CL== bignum
bool CLEqn::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(static_cast<double>
                                      (a.floatval()), b);
}
// double float CL== bignum
bool CLEqn::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a, b);
}
// long float CL== bignum
bool CLEqn::op(LFlt a, uint64_t *b)
{   return arithlib_lowlevel::Eqn::op(a.floatval(), b);
}
// fixnum CL== rational
bool CLEqn::op(Fixnum a, Rat b)
{   return false;
}
// bignum CL== rational
bool CLEqn::op(uint64_t *a, Rat b)
{   return false;
}
// rational CL== rational
bool CLEqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Eqn::op(p1, p2) && Eqn::op(q1, q2);
}
// complex CL== rational
bool CLEqn::op(Cpx a, Rat b)
{   return false;
}
// short float CL== rational
bool CLEqn::op(SFlt a, Rat b)
{   return (a.floatval() == RawFloat::op(b));
}
// single float CL== rational
#pragma message ("Comparisons between floats and rationals are NOT done nicely yet")
bool CLEqn::op(Flt a, Rat b)
{   return (a.floatval() == RawFloat::op(b));
}
// double float CL== rational
bool CLEqn::op(double a, Rat b)
{   return (a == RawFloat::op(b));
}
// long float CL== rational
bool CLEqn::op(LFlt a, Rat b)
{   return f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum CL== complex
bool CLEqn::op(Fixnum a, Cpx b)
{   return false;
}
// bignum CL== complex
bool CLEqn::op(uint64_t *a, Cpx b)
{   return false;
}
// rational CL== complex
bool CLEqn::op(Rat a, Cpx b)
{   return false;
}
// complex CL== complex
bool CLEqn::op(Cpx a, Cpx b)
{   return (Eqn::op(a.real_part(), b.real_part()) &&
            Eqn::op(a.imag_part(), b.imag_part()));
}
// short float CL== complex
bool CLEqn::op(SFlt a, Cpx b)
{   return false;
}
// single float CL== complex
bool CLEqn::op(Flt a, Cpx b)
{   return false;
}
// double float CL== complex
bool CLEqn::op(double a, Cpx b)
{   return false;
}
// long float CL== complex
bool CLEqn::op(LFlt a, Cpx b)
{   return false;
}
// fixnum CL== short float
bool CLEqn::op(Fixnum a, SFlt b)
{   return Eqn::op(b, a);
}
// bignum CL== short float
bool CLEqn::op(uint64_t *a, SFlt b)
{   return Eqn::op(b, a);
}
// rational CL== short float
bool CLEqn::op(Rat a, SFlt b)
{   return Eqn::op(b, a);
}
// complex CL== short float
bool CLEqn::op(Cpx a, SFlt b)
{   return Eqn::op(b, a);
}
// short float CL== short float
bool CLEqn::op(SFlt a, SFlt b)
{   return (a.floatval() == b.floatval());
}
// single float CL== short float
bool CLEqn::op(Flt a, SFlt b)
{   return (a.floatval() == b.floatval());
}
// double float CL== short float
bool CLEqn::op(double a, SFlt b)
{   return (a == b.floatval());
}
// long float CL== short float
bool CLEqn::op(LFlt a, SFlt b)
{   return f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum CL== single float
bool CLEqn::op(Fixnum a, Flt b)
{   return Eqn::op(b, a);
}
// bignum CL== single float
bool CLEqn::op(uint64_t *a, Flt b)
{   return Eqn::op(b, a);
}
// rational CL== single float
bool CLEqn::op(Rat a, Flt b)
{   return Eqn::op(b, a);
}
// complex CL== single float
bool CLEqn::op(Cpx a, Flt b)
{   return Eqn::op(b, a);
}
// short float CL== single float
bool CLEqn::op(SFlt a, Flt b)
{   return Eqn::op(b, a);
}
// single float CL== single float
bool CLEqn::op(Flt a, Flt b)
{   return (a.floatval() == b.floatval());
}
// double float CL== single float
bool CLEqn::op(double a, Flt b)
{   return (a == b.floatval());
}
// long float CL== single float
bool CLEqn::op(LFlt a, Flt b)
{   return f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum CL== double float
bool CLEqn::op(Fixnum a, double b)
{   return Eqn::op(b, a);
}
// bignum CL== double float
bool CLEqn::op(uint64_t *a, double b)
{   return Eqn::op(b, a);
}
// rational CL== double float
bool CLEqn::op(Rat a, double b)
{   return Eqn::op(b, a);
}
// complex CL== double float
bool CLEqn::op(Cpx a, double b)
{   return false;
}
// short float CL== double float
bool CLEqn::op(SFlt a, double b)
{   return Eqn::op(b, a);
}
// single float CL== double float
bool CLEqn::op(Flt a, double b)
{   return Eqn::op(b, a);
}
// double float CL== double float
bool CLEqn::op(double a, double b)
{   return (a == b);
}
// long float CL== double float
bool CLEqn::op(LFlt a, double b)
{   return f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum CL== long float
bool CLEqn::op(Fixnum a, LFlt b)
{   return Eqn::op(b, a);
}
// bignum CL== long float
bool CLEqn::op(uint64_t *a, LFlt b)
{   return Eqn::op(b, a);
}
// rational CL== long float
bool CLEqn::op(Rat a, LFlt b)
{   return Eqn::op(b, a);
}
// complex CL== long float
bool CLEqn::op(Cpx a, LFlt b)
{   return false;
}
// short float CL== long float
bool CLEqn::op(SFlt a, LFlt b)
{   return Eqn::op(b, a);
}
// single float CL== long float
bool CLEqn::op(Flt a, LFlt b)
{   return Eqn::op(b, a);
}
// double float CL== long float
bool CLEqn::op(double a, LFlt b)
{   return Eqn::op(b, a);
}
// long float CL== long float
bool CLEqn::op(LFlt a, LFlt b)
{   return f128_eq(a.floatval(), b.floatval());
}

bool Neqn::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

bool Neqn::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Neqn>("neqn", a, b);
}

// fixnum != fixnum

// There is a sort of C++ type misery here. intval() returns an intptr_t
// value and that may be either a 32 or 64-bit integer. Many of the
// low level primitives here want a 64-bit integer as input, but automatic
// conversion does not make the adaptations I desire - hence a load of
// ugly casts. This is probably a signal that I got the type signatures in
// my code wrong, but I am not about to alter it now.

bool Neqn::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Neqn::op((int64_t)a.intval(),
                                       (int64_t)b.intval());
}
// bignum != fixnum
bool Neqn::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Neqn::op(a, (int64_t)b.intval());
}
// rational != fixnum
bool Neqn::op(Rat a, Fixnum b)
{   return true;
}
// complex != fixnum
bool Neqn::op(Cpx a, Fixnum b)
{   return true;
}
// short float != fixnum
bool Neqn::op(SFlt a, Fixnum b)
{   return (a.floatval() != static_cast<double>(b.intval()));
}
// single float != fixnum
bool Neqn::op(Flt a, Fixnum b)
{   return (a.floatval() != static_cast<double>(b.intval()));
}
// double float != fixnum
bool Neqn::op(double a, Fixnum b)
{   return (a != static_cast<double>(b.intval()));
}
// long float != fixnum
bool Neqn::op(LFlt a, Fixnum b)
{   return !f128_eq(a.floatval(), i64_to_f128(b.intval()));
}
// fixnum != bignum
bool Neqn::op(Fixnum a, uint64_t *b)
{   return Neqn::op(b, a);
}
// bignum != bignum
bool Neqn::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Neqn::op(a, b);
}
// rational != bignum
bool Neqn::op(Rat a, uint64_t *b)
{   return false;
}
// complex != bignum
bool Neqn::op(Cpx a, uint64_t *b)
{   return false;
}
// short float != bignum
bool Neqn::op(SFlt a, uint64_t *b)
{   return (a.floatval() != arithlib_lowlevel::Double::op(b));
}
// single float != bignum
bool Neqn::op(Flt a, uint64_t *b)
{   return (a.floatval() != arithlib_lowlevel::Double::op(b));
}
// double float != bignum
bool Neqn::op(double a, uint64_t *b)
{   return (a != arithlib_lowlevel::Double::op(b));
}
// long float != bignum
bool Neqn::op(LFlt a, uint64_t *b)
{   return !f128_eq(a.floatval(), arithlib_lowlevel::Float128::op(b));
}
// fixnum != rational
bool Neqn::op(Fixnum a, Rat b)
{   return true;
}
// bignum != rational
bool Neqn::op(uint64_t *a, Rat b)
{   return true;
}
// rational != rational
bool Neqn::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Neqn::op(p1, p2) || Neqn::op(q1, q2);
}
// complex != rational
bool Neqn::op(Cpx a, Rat b)
{   return true;
}
// short float != rational
bool Neqn::op(SFlt a, Rat b)
{   return (a.floatval() != RawFloat::op(b));
}
// single float != rational
bool Neqn::op(Flt a, Rat b)
{   return (a.floatval() != RawFloat::op(b));
}
// double float != rational
bool Neqn::op(double a, Rat b)
{   return (a != RawFloat::op(b));
}
// long float != rational
bool Neqn::op(LFlt a, Rat b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum != complex
bool Neqn::op(Fixnum a, Cpx b)
{   return true;
}
// bignum != complex
bool Neqn::op(uint64_t *a, Cpx b)
{   return true;
}
// rational != complex
bool Neqn::op(Rat a, Cpx b)
{   return true;
}
// complex != complex
bool Neqn::op(Cpx a, Cpx b)
{   return (Neqn::op(a.real_part(), b.real_part()) ||
            Neqn::op(a.imag_part(), b.imag_part()));
}
// short float != complex
bool Neqn::op(SFlt a, Cpx b)
{   return true;
}
// single float != complex
bool Neqn::op(Flt a, Cpx b)
{   return true;
}
// double float != complex
bool Neqn::op(double a, Cpx b)
{   return true;
}
// long float != complex
bool Neqn::op(LFlt a, Cpx b)
{   return true;
}
// fixnum != short float
bool Neqn::op(Fixnum a, SFlt b)
{   return Neqn::op(b, a);
}
// bignum != short float
bool Neqn::op(uint64_t *a, SFlt b)
{   return Neqn::op(b, a);
}
// rational != short float
bool Neqn::op(Rat a, SFlt b)
{   return Neqn::op(b, a);
}
// complex != short float
bool Neqn::op(Cpx a, SFlt b)
{   return Neqn::op(b, a);
}
// short float != short float
bool Neqn::op(SFlt a, SFlt b)
{   return (a.floatval() != b.floatval());
}
// single float != short float
bool Neqn::op(Flt a, SFlt b)
{   return (a.floatval() != b.floatval());
}
// double float != short float
bool Neqn::op(double a, SFlt b)
{   return (a != b.floatval());
}
// long float != short float
bool Neqn::op(LFlt a, SFlt b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum != single float
bool Neqn::op(Fixnum a, Flt b)
{   return Neqn::op(b, a);
}
// bignum != single float
bool Neqn::op(uint64_t *a, Flt b)
{   return Neqn::op(b, a);
}
// rational != single float
bool Neqn::op(Rat a, Flt b)
{   return Neqn::op(b, a);
}
// complex != single float
bool Neqn::op(Cpx a, Flt b)
{   return Neqn::op(b, a);
}
// short float != single float
bool Neqn::op(SFlt a, Flt b)
{   return Neqn::op(b, a);
}
// single float != single float
bool Neqn::op(Flt a, Flt b)
{   return (a.floatval() != b.floatval());
}
// double float != single float
bool Neqn::op(double a, Flt b)
{   return (a != b.floatval());
}
// long float != single float
bool Neqn::op(LFlt a, Flt b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum != double float
bool Neqn::op(Fixnum a, double b)
{   return Neqn::op(b, a);
}
// bignum != double float
bool Neqn::op(uint64_t *a, double b)
{   return Neqn::op(b, a);
}
// rational != double float
bool Neqn::op(Rat a, double b)
{   return Neqn::op(b, a);
}
// complex != double float
bool Neqn::op(Cpx a, double b)
{   return false;
}
// short float != double float
bool Neqn::op(SFlt a, double b)
{   return Neqn::op(b, a);
}
// single float != double float
bool Neqn::op(Flt a, double b)
{   return Neqn::op(b, a);
}
// double float != double float
bool Neqn::op(double a, double b)
{   return (a != b);
}
// long float != double float
bool Neqn::op(LFlt a, double b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum != long float
bool Neqn::op(Fixnum a, LFlt b)
{   return Neqn::op(b, a);
}
// bignum != long float
bool Neqn::op(uint64_t *a, LFlt b)
{   return Neqn::op(b, a);
}
// rational != long float
bool Neqn::op(Rat a, LFlt b)
{   return Neqn::op(b, a);
}
// complex != long float
bool Neqn::op(Cpx a, LFlt b)
{   return false;
}
// short float != long float
bool Neqn::op(SFlt a, LFlt b)
{   return Neqn::op(b, a);
}
// single float != long float
bool Neqn::op(Flt a, LFlt b)
{   return Neqn::op(b, a);
}
// double float != long float
bool Neqn::op(double a, LFlt b)
{   return Neqn::op(b, a);
}
// long float != long float
bool Neqn::op(LFlt a, LFlt b)
{   return !f128_eq(a.floatval(), b.floatval());
}

bool Greaterp::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Greaterp>("greaterp", a, b);
}

bool Greaterp::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

bool Greaterp::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Greaterp>("greaterp", a,
            b);
}

// fixnum > fixnum

bool Greaterp::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op((int64_t)a.intval(),
                                           (int64_t)b.intval());
}
// bignum > fixnum
bool Greaterp::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a, (int64_t)b.intval());
}
// rational > fixnum
bool Greaterp::op(Rat a, Fixnum b)
{   // p/q > b if p > q*b
    return Greaterp::op(a.numerator(), Times::op(a.denominator(), b));
}
// complex > fixnum
bool Greaterp::op(Cpx a, Fixnum b)
{   return false;
}
// short float > fixnum
bool Greaterp::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>
                                           (a.floatval()), b.intval());
}
// single float > fixnum
bool Greaterp::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>
                                           (a.floatval()), b.intval());
}
// double float > fixnum
bool Greaterp::op(double a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a, (int64_t)b.intval());
}
// long float > fixnum
bool Greaterp::op(LFlt a, Fixnum b)
{   return arithlib_lowlevel::Greaterp::op(a.floatval(),
                                           (int64_t)b.intval());
}
// fixnum > bignum
bool Greaterp::op(Fixnum a, uint64_t *b)
{   return Lessp::op(b, a);
}
// bignum > bignum
bool Greaterp::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a, b);
}
// rational > bignum
bool Greaterp::op(Rat a, uint64_t *b)
{   return Greaterp::op(a.numerator(), Times::op(a.denominator(), b));

}
// complex > bignum
bool Greaterp::op(Cpx a, uint64_t *b)
{   return false;
}
// short float > bignum
bool Greaterp::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>
                                           (a.floatval()), b);
}
// single float > bignum
bool Greaterp::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(static_cast<double>
                                           (a.floatval()), b);
}
// double float > bignum
bool Greaterp::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a, b);
}
// long float > bignum
bool Greaterp::op(LFlt a, uint64_t *b)
{   return arithlib_lowlevel::Greaterp::op(a.floatval(), b);
}
// fixnum > rational
bool Greaterp::op(Fixnum a, Rat b)
{   return Greaterp::op(Times::op(a, b.denominator()), b.numerator());
}
// bignum > rational
bool Greaterp::op(uint64_t *a, Rat b)
{   return Greaterp::op(Times::op(a, b.denominator()), b.numerator());
}
// rational > rational
bool Greaterp::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Greaterp::op(Times::op(p1, q2), Times::op(p2, q1));
}
// complex > rational
bool Greaterp::op(Cpx a, Rat b)
{   return false;
}
// short float > rational
#pragma message ("greaterp float rational not complete yet")
bool Greaterp::op(SFlt a, Rat b)
{   return (a.floatval() > RawFloat::op(b));
}
// single float > rational
bool Greaterp::op(Flt a, Rat b)
{   return (a.floatval() > RawFloat::op(b));
}
// double float > rational
bool Greaterp::op(double a, Rat b)
{   return (a > RawFloat::op(b));
}
// long float > rational
bool Greaterp::op(LFlt a, Rat b)
{   return !f128_le(a.floatval(), RawFloat128::op(b));
}
// fixnum > complex
bool Greaterp::op(Fixnum a, Cpx b)
{   return false;
}
// bignum > complex
bool Greaterp::op(uint64_t *a, Cpx b)
{   return false;
}
// rational > complex
bool Greaterp::op(Rat a, Cpx b)
{   return false;
}
// complex > complex
bool Greaterp::op(Cpx a, Cpx b)
{   return false;
}
// short float > complex
bool Greaterp::op(SFlt a, Cpx b)
{   return false;
}
// single float > complex
bool Greaterp::op(Flt a, Cpx b)
{   return false;
}
// double float > complex
bool Greaterp::op(double a, Cpx b)
{   return false;
}
// long float > complex
bool Greaterp::op(LFlt a, Cpx b)
{   return false;
}
// fixnum > short float
bool Greaterp::op(Fixnum a, SFlt b)
{   return Lessp::op(b, a);
}
// bignum > short float
bool Greaterp::op(uint64_t *a, SFlt b)
{   return Lessp::op(b, a);
}
// rational > short float
bool Greaterp::op(Rat a, SFlt b)
{   return Lessp::op(b, a);
}
// complex > short float
bool Greaterp::op(Cpx a, SFlt b)
{   return false;
}
// short float > short float
bool Greaterp::op(SFlt a, SFlt b)
{   return (a.floatval() > b.floatval());
}
// single float > short float
bool Greaterp::op(Flt a, SFlt b)
{   return (a.floatval() > b.floatval());
}
// double float > short float
bool Greaterp::op(double a, SFlt b)
{   return (a > b.floatval());
}
// long float > short float
bool Greaterp::op(LFlt a, SFlt b)
{   return f128_lt(RawFloat128::op(b), a.floatval());
}
// fixnum > single float
bool Greaterp::op(Fixnum a, Flt b)
{   return Lessp::op(b, a);
}
// bignum > single float
bool Greaterp::op(uint64_t *a, Flt b)
{   return Lessp::op(b, a);
}
// rational > single float
bool Greaterp::op(Rat a, Flt b)
{   return Lessp::op(b, a);
}
// complex > single float
bool Greaterp::op(Cpx a, Flt b)
{   return Lessp::op(b, a);
}
// short float > single float
bool Greaterp::op(SFlt a, Flt b)
{   return Lessp::op(b, a);
}
// single float > single float
bool Greaterp::op(Flt a, Flt b)
{   return (a.floatval() > b.floatval());
}
// double float > single float
bool Greaterp::op(double a, Flt b)
{   return (a > b.floatval());
}
// long float > single float
bool Greaterp::op(LFlt a, Flt b)
{   return f128_lt(RawFloat128::op(b), a.floatval());
}
// fixnum > double float
bool Greaterp::op(Fixnum a, double b)
{   return Lessp::op(b, a);
}
// bignum > double float
bool Greaterp::op(uint64_t *a, double b)
{   return Lessp::op(b, a);
}
// rational > double float
bool Greaterp::op(Rat a, double b)
{   return Lessp::op(b, a);
}
// complex > double float
bool Greaterp::op(Cpx a, double b)
{   return false;
}
// short float > double float
bool Greaterp::op(SFlt a, double b)
{   return Lessp::op(b, a);
}
// single float > double float
bool Greaterp::op(Flt a, double b)
{   return Lessp::op(b, a);
}
// double float > double float
bool Greaterp::op(double a, double b)
{   return (a > b);
}
// long float > double float
bool Greaterp::op(LFlt a, double b)
{   return f128_lt(RawFloat128::op(b), a.floatval());
}
// fixnum > long float
bool Greaterp::op(Fixnum a, LFlt b)
{   return Lessp::op(b, a);
}
// bignum > long float
bool Greaterp::op(uint64_t *a, LFlt b)
{   return Lessp::op(b, a);
}
// rational > long float
bool Greaterp::op(Rat a, LFlt b)
{   return Lessp::op(b, a);
}
// complex > long float
bool Greaterp::op(Cpx a, LFlt b)
{   return false;
}
// short float > long float
bool Greaterp::op(SFlt a, LFlt b)
{   return Lessp::op(b, a);
}
// single float > long float
bool Greaterp::op(Flt a, LFlt b)
{   return Lessp::op(b, a);
}
// double float > long float
bool Greaterp::op(double a, LFlt b)
{   return Lessp::op(b, a);
}
// long float > long float
bool Greaterp::op(LFlt a, LFlt b)
{   return f128_lt(b.floatval(), a.floatval());
}

bool Geq::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Geq>("geq", a, b);
}

bool Geq::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

bool Geq::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Geq>("geq", a, b);
}

// fixnum >= fixnum

bool Geq::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Geq::op((int64_t)a.intval(),
                                      (int64_t)b.intval());
}
// bignum >= fixnum
bool Geq::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a, (int64_t)b.intval());
}
// rational >= fixnum
bool Geq::op(Rat a, Fixnum b)
{   // p/q >= b if p >= q*b
    return Geq::op(a.numerator(), Times::op(a.denominator(), b));
}
// complex >= fixnum
bool Geq::op(Cpx a, Fixnum b)
{   return false;
}
// short float >= fixnum
bool Geq::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>
                                      (a.floatval()), (int64_t)b.intval());
}
// single float >= fixnum
bool Geq::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>
                                      (a.floatval()), (int64_t)b.intval());
}
// double float >= fixnum
bool Geq::op(double a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a, (int64_t)b.intval());
}
// long float >= fixnum
bool Geq::op(LFlt a, Fixnum b)
{   return arithlib_lowlevel::Geq::op(a.floatval(),
                                      (int64_t)b.intval());
}
// fixnum >= bignum
bool Geq::op(Fixnum a, uint64_t *b)
{   return Leq::op(b, a);
}
// bignum >= bignum
bool Geq::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a, b);
}
// rational >= bignum
bool Geq::op(Rat a, uint64_t *b)
{   return Geq::op(a.numerator(), Times::op(a.denominator(), b));

}
// complex >= bignum
bool Geq::op(Cpx a, uint64_t *b)
{   return false;
}
// short float >= bignum
bool Geq::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>
                                      (a.floatval()), b);
}
// single float >= bignum
bool Geq::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(static_cast<double>
                                      (a.floatval()), b);
}
// double float >= bignum
bool Geq::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a, b);
}
// long float >= bignum
bool Geq::op(LFlt a, uint64_t *b)
{   return arithlib_lowlevel::Geq::op(a.floatval(), b);
}
// fixnum >= rational
bool Geq::op(Fixnum a, Rat b)
{   return Geq::op(Times::op(a, b.denominator()), b.numerator());
}
// bignum >= rational
bool Geq::op(uint64_t *a, Rat b)
{   return Geq::op(Times::op(a, b.denominator()), b.numerator());
}
// rational >= rational
bool Geq::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Geq::op(Times::op(p1, q2), Times::op(p2, q1));
}
// complex >= rational
bool Geq::op(Cpx a, Rat b)
{   return false;
}
// short float >= rational
#pragma message ("Geq involving floats & rationals")
bool Geq::op(SFlt a, Rat b)
{   return (a.floatval() >= RawFloat::op(b));
}
// single float >= rational
bool Geq::op(Flt a, Rat b)
{   return (a.floatval() >= RawFloat::op(b));
}
// double float >= rational
bool Geq::op(double a, Rat b)
{   return (a >= RawFloat::op(b));
}
// long float >= rational
bool Geq::op(LFlt a, Rat b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum >= complex
bool Geq::op(Fixnum a, Cpx b)
{   return false;
}
// bignum >= complex
bool Geq::op(uint64_t *a, Cpx b)
{   return false;
}
// rational >= complex
bool Geq::op(Rat a, Cpx b)
{   return false;
}
// complex >= complex
bool Geq::op(Cpx a, Cpx b)
{   return false;
}
// short float >= complex
bool Geq::op(SFlt a, Cpx b)
{   return false;
}
// single float >= complex
bool Geq::op(Flt a, Cpx b)
{   return false;
}
// double float >= complex
bool Geq::op(double a, Cpx b)
{   return false;
}
// long float >= complex
bool Geq::op(LFlt a, Cpx b)
{   return false;
}
// fixnum >= short float
bool Geq::op(Fixnum a, SFlt b)
{   return Leq::op(b, a);
}
// bignum >= short float
bool Geq::op(uint64_t *a, SFlt b)
{   return Leq::op(b, a);
}
// rational >= short float
bool Geq::op(Rat a, SFlt b)
{   return Leq::op(b, a);
}
// complex >= short float
bool Geq::op(Cpx a, SFlt b)
{   return false;
}
// short float >= short float
bool Geq::op(SFlt a, SFlt b)
{   return (a.floatval() >= b.floatval());
}
// single float >= short float
bool Geq::op(Flt a, SFlt b)
{   return (a.floatval() >= b.floatval());
}
// double float >= short float
bool Geq::op(double a, SFlt b)
{   return (a >= b.floatval());
}
// long float >= short float
bool Geq::op(LFlt a, SFlt b)
{   return f128_le(RawFloat128::op(b), a.floatval());
}

// fixnum >= single float
bool Geq::op(Fixnum a, Flt b)
{   return Leq::op(b, a);
}
// bignum >= single float
bool Geq::op(uint64_t *a, Flt b)
{   return Leq::op(b, a);
}
// rational >= single float
bool Geq::op(Rat a, Flt b)
{   return Leq::op(b, a);
}
// complex >= single float
bool Geq::op(Cpx a, Flt b)
{   return Leq::op(b, a);
}
// short float >= single float
bool Geq::op(SFlt a, Flt b)
{   return Leq::op(b, a);
}
// single float >= single float
bool Geq::op(Flt a, Flt b)
{   return (a.floatval() >= b.floatval());
}
// double float >= single float
bool Geq::op(double a, Flt b)
{   return (a >= b.floatval());
}
// long float >= single float
bool Geq::op(LFlt a, Flt b)
{   return f128_le(RawFloat128::op(b), a.floatval());
}
// fixnum >= double float
bool Geq::op(Fixnum a, double b)
{   return Leq::op(b, a);
}
// bignum >= double float
bool Geq::op(uint64_t *a, double b)
{   return Leq::op(b, a);
}
// rational >= double float
bool Geq::op(Rat a, double b)
{   return Leq::op(b, a);
}
// complex >= double float
bool Geq::op(Cpx a, double b)
{   return false;
}
// short float >= double float
bool Geq::op(SFlt a, double b)
{   return Leq::op(b, a);
}
// single float >= double float
bool Geq::op(Flt a, double b)
{   return Leq::op(b, a);
}
// double float >= double float
bool Geq::op(double a, double b)
{   return (a >= b);
}
// long float >= double float
bool Geq::op(LFlt a, double b)
{   return f128_le(RawFloat128::op(b), a.floatval());
}
// fixnum >= long float
bool Geq::op(Fixnum a, LFlt b)
{   return Leq::op(b, a);
}
// bignum >= long float
bool Geq::op(uint64_t *a, LFlt b)
{   return Leq::op(b, a);
}
// rational >= long float
bool Geq::op(Rat a, LFlt b)
{   return Leq::op(b, a);
}
// complex >= long float
bool Geq::op(Cpx a, LFlt b)
{   return false;
}
// short float >= long float
bool Geq::op(SFlt a, LFlt b)
{   return Leq::op(b, a);
}
// single float >= long float
bool Geq::op(Flt a, LFlt b)
{   return Leq::op(b, a);
}
// double float >= long float
bool Geq::op(double a, LFlt b)
{   return Leq::op(b, a);
}
// long float >= long float
bool Geq::op(LFlt a, LFlt b)
{   return f128_le(b.floatval(), a.floatval());
}

bool Lessp::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

bool Lessp::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Lessp>("lessp", a, b);
}

// fixnum < fixnum

bool Lessp::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op((int64_t)a.intval(),
                                        (int64_t)b.intval());
}
// bignum < fixnum
bool Lessp::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a, (int64_t)b.intval());
}
// rational < fixnum
bool Lessp::op(Rat a, Fixnum b)
{   // p/q < b if p < q*b
    return Lessp::op(a.numerator(), Times::op(a.denominator(), b));
}
// complex < fixnum
bool Lessp::op(Cpx a, Fixnum b)
{   return false;
}
// short float < fixnum
bool Lessp::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), (int64_t)b.intval());
}
// single float < fixnum
bool Lessp::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), (int64_t)b.intval());
}
// double float < fixnum
bool Lessp::op(double a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a, (int64_t)b.intval());
}
// long float < fixnum
bool Lessp::op(LFlt a, Fixnum b)
{   return arithlib_lowlevel::Lessp::op(a.floatval(),
                                        (int64_t)b.intval());
}
// fixnum < bignum
bool Lessp::op(Fixnum a, uint64_t *b)
{   return Greaterp::op(b, a);
}
// bignum < bignum
bool Lessp::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a, b);
}
// rational < bignum
bool Lessp::op(Rat a, uint64_t *b)
{   return Lessp::op(a.numerator(), Times::op(a.denominator(), b));

}
// complex < bignum
bool Lessp::op(Cpx a, uint64_t *b)
{   return false;
}
// short float < bignum
bool Lessp::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), b);
}
// single float < bignum
bool Lessp::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(static_cast<double>
                                        (a.floatval()), b);
}
// double float < bignum
bool Lessp::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a, b);
}
// long float < bignum
bool Lessp::op(LFlt a, uint64_t *b)
{   return arithlib_lowlevel::Lessp::op(a.floatval(), b);
}
// fixnum < rational
bool Lessp::op(Fixnum a, Rat b)
{   return Lessp::op(Times::op(a, b.denominator()), b.numerator());
}
// bignum < rational
bool Lessp::op(uint64_t *a, Rat b)
{   return Lessp::op(Times::op(a, b.denominator()), b.numerator());
}
// rational < rational
bool Lessp::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Lessp::op(Times::op(p1, q2), Times::op(p2, q1));
}
// complex < rational
bool Lessp::op(Cpx a, Rat b)
{   return false;
}
// short float < rational
#pragma message ("lessp float rational")
bool Lessp::op(SFlt a, Rat b)
{   return (a.floatval() < RawFloat::op(b));
}
// single float < rational
bool Lessp::op(Flt a, Rat b)
{   return (a.floatval() < RawFloat::op(b));
}
// double float < rational
bool Lessp::op(double a, Rat b)
{   return (a < RawFloat::op(b));
}
// long float < rational
bool Lessp::op(LFlt a, Rat b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum < complex
bool Lessp::op(Fixnum a, Cpx b)
{   return false;
}
// bignum < complex
bool Lessp::op(uint64_t *a, Cpx b)
{   return false;
}
// rational < complex
bool Lessp::op(Rat a, Cpx b)
{   return false;
}
// complex < complex
bool Lessp::op(Cpx a, Cpx b)
{   return false;
}
// short float < complex
bool Lessp::op(SFlt a, Cpx b)
{   return false;
}
// single float < complex
bool Lessp::op(Flt a, Cpx b)
{   return false;
}
// double float < complex
bool Lessp::op(double a, Cpx b)
{   return false;
}
// long float < complex
bool Lessp::op(LFlt a, Cpx b)
{   return false;
}
// fixnum < short float
bool Lessp::op(Fixnum a, SFlt b)
{   return Greaterp::op(b, a);
}
// bignum < short float
bool Lessp::op(uint64_t *a, SFlt b)
{   return Greaterp::op(b, a);
}
// rational < short float
bool Lessp::op(Rat a, SFlt b)
{   return Greaterp::op(b, a);
}
// complex < short float
bool Lessp::op(Cpx a, SFlt b)
{   return false;
}
// short float < short float
bool Lessp::op(SFlt a, SFlt b)
{   return (a.floatval() < b.floatval());
}
// single float < short float
bool Lessp::op(Flt a, SFlt b)
{   return (a.floatval() < b.floatval());
}
// double float < short float
bool Lessp::op(double a, SFlt b)
{   return (a < b.floatval());
}
// long float < short float
bool Lessp::op(LFlt a, SFlt b)
{   return f128_lt(a.floatval(), RawFloat128::op(b));
}
// fixnum < single float
bool Lessp::op(Fixnum a, Flt b)
{   return Greaterp::op(b, a);
}
// bignum < single float
bool Lessp::op(uint64_t *a, Flt b)
{   return Greaterp::op(b, a);
}
// rational < single float
bool Lessp::op(Rat a, Flt b)
{   return Greaterp::op(b, a);
}
// complex < single float
bool Lessp::op(Cpx a, Flt b)
{   return Greaterp::op(b, a);
}
// short float < single float
bool Lessp::op(SFlt a, Flt b)
{   return Greaterp::op(b, a);
}
// single float < single float
bool Lessp::op(Flt a, Flt b)
{   return (a.floatval() < b.floatval());
}
// double float < single float
bool Lessp::op(double a, Flt b)
{   return (a < b.floatval());
}
// long float < single float
bool Lessp::op(LFlt a, Flt b)
{   return f128_lt(a.floatval(), RawFloat128::op(b));
}
// fixnum < double float
bool Lessp::op(Fixnum a, double b)
{   return Greaterp::op(b, a);
}
// bignum < double float
bool Lessp::op(uint64_t *a, double b)
{   return Greaterp::op(b, a);
}
// rational < double float
bool Lessp::op(Rat a, double b)
{   return Greaterp::op(b, a);
}
// complex < double float
bool Lessp::op(Cpx a, double b)
{   return false;
}
// short float < double float
bool Lessp::op(SFlt a, double b)
{   return Greaterp::op(b, a);
}
// single float < double float
bool Lessp::op(Flt a, double b)
{   return Greaterp::op(b, a);
}
// double float < double float
bool Lessp::op(double a, double b)
{   return (a < b);
}
// long float < double float
bool Lessp::op(LFlt a, double b)
{   return f128_lt(a.floatval(), RawFloat128::op(b));
}
// fixnum < long float
bool Lessp::op(Fixnum a, LFlt b)
{   return Greaterp::op(b, a);
}
// bignum < long float
bool Lessp::op(uint64_t *a, LFlt b)
{   return Greaterp::op(b, a);
}
// rational < long float
bool Lessp::op(Rat a, LFlt b)
{   return Greaterp::op(b, a);
}
// complex < long float
bool Lessp::op(Cpx a, LFlt b)
{   return false;
}
// short float < long float
bool Lessp::op(SFlt a, LFlt b)
{   return Greaterp::op(b, a);
}
// single float < long float
bool Lessp::op(Flt a, LFlt b)
{   return Greaterp::op(b, a);
}
// double float < long float
bool Lessp::op(double a, LFlt b)
{   return Greaterp::op(b, a);
}
// long float < long float
bool Lessp::op(LFlt a, LFlt b)
{   return f128_lt(a.floatval(), b.floatval());
}

bool Leq::op(LispObject a, LispObject b)
{   return number_dispatcher::binary<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, Fixnum b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, uint64_t *b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, Rat b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, Cpx b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, SFlt b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, Flt b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, double b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(LispObject a, LFlt b)
{   return number_dispatcher::binaryR<bool,Leq>("leq", a, b);
}

bool Leq::op(Fixnum a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(uint64_t *a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(Rat a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(Cpx a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(SFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(Flt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(double a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

bool Leq::op(LFlt a, LispObject b)
{   return number_dispatcher::binaryL<bool,Leq>("leq", a, b);
}

// fixnum <= fixnum

bool Leq::op(Fixnum a, Fixnum b)
{   return arithlib_lowlevel::Leq::op((int64_t)a.intval(),
                                      (int64_t)b.intval());
}
// bignum <= fixnum
bool Leq::op(uint64_t *a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a, (int64_t)b.intval());
}
// rational <= fixnum
bool Leq::op(Rat a, Fixnum b)
{   // p/q <= b if p <= q*b
    return Leq::op(a.numerator(), Times::op(a.denominator(), b));
}
// complex <= fixnum
bool Leq::op(Cpx a, Fixnum b)
{   return false;
}
// short float <= fixnum
bool Leq::op(SFlt a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), (int64_t)b.intval());
}
// single float <= fixnum
bool Leq::op(Flt a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), (int64_t)b.intval());
}
// double float <= fixnum
bool Leq::op(double a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a, (int64_t)b.intval());
}
// long float <= fixnum
bool Leq::op(LFlt a, Fixnum b)
{   return arithlib_lowlevel::Leq::op(a.floatval(),
                                      (int64_t)b.intval());
}
// fixnum <= bignum
bool Leq::op(Fixnum a, uint64_t *b)
{   return Geq::op(b, a);
}
// bignum <= bignum
bool Leq::op(uint64_t *a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a, b);
}
// rational <= bignum
bool Leq::op(Rat a, uint64_t *b)
{   return Leq::op(a.numerator(), Times::op(a.denominator(), b));

}
// complex <= bignum
bool Leq::op(Cpx a, uint64_t *b)
{   return false;
}
// short float <= bignum
bool Leq::op(SFlt a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), b);
}
// single float <= bignum
bool Leq::op(Flt a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(static_cast<double>
                                      (a.floatval()), b);
}
// double float <= bignum
bool Leq::op(double a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a, b);
}
// long float <= bignum
bool Leq::op(LFlt a, uint64_t *b)
{   return arithlib_lowlevel::Leq::op(a.floatval(), b);
}
// fixnum <= rational
bool Leq::op(Fixnum a, Rat b)
{   return Leq::op(Times::op(a, b.denominator()), b.numerator());
}
// bignum <= rational
bool Leq::op(uint64_t *a, Rat b)
{   return Leq::op(Times::op(a, b.denominator()), b.numerator());
}
// rational <= rational
bool Leq::op(Rat a, Rat b)
{   LispObject p1 = a.numerator(), q1 = a.denominator();
    LispObject p2 = b.numerator(), q2 = b.denominator();
    return Leq::op(Times::op(p1, q2), Times::op(p2, q1));
}
// complex <= rational
bool Leq::op(Cpx a, Rat b)
{   return false;
}
// short float <= rational
#pragma message ("leq float rational")
bool Leq::op(SFlt a, Rat b)
{   return (a.floatval() <= RawFloat::op(b));
}
// single float <= rational
bool Leq::op(Flt a, Rat b)
{   return (a.floatval() <= RawFloat::op(b));
}
// double float <= rational
bool Leq::op(double a, Rat b)
{   return (a <= RawFloat::op(b));
}
// long float <= rational
bool Leq::op(LFlt a, Rat b)
{   return !f128_eq(a.floatval(), RawFloat128::op(b));
}
// fixnum <= complex
bool Leq::op(Fixnum a, Cpx b)
{   return false;
}
// bignum <= complex
bool Leq::op(uint64_t *a, Cpx b)
{   return false;
}
// rational <= complex
bool Leq::op(Rat a, Cpx b)
{   return false;
}
// complex <= complex
bool Leq::op(Cpx a, Cpx b)
{   return false;
}
// short float <= complex
bool Leq::op(SFlt a, Cpx b)
{   return false;
}
// single float <= complex
bool Leq::op(Flt a, Cpx b)
{   return false;
}
// double float <= complex
bool Leq::op(double a, Cpx b)
{   return false;
}
// long float <= complex
bool Leq::op(LFlt a, Cpx b)
{   return false;
}
// fixnum <= short float
bool Leq::op(Fixnum a, SFlt b)
{   return Geq::op(b, a);
}
// bignum <= short float
bool Leq::op(uint64_t *a, SFlt b)
{   return Geq::op(b, a);
}
// rational <= short float
bool Leq::op(Rat a, SFlt b)
{   return Geq::op(b, a);
}
// complex <= short float
bool Leq::op(Cpx a, SFlt b)
{   return false;
}
// short float <= short float
bool Leq::op(SFlt a, SFlt b)
{   return (a.floatval() <= b.floatval());
}
// single float <= short float
bool Leq::op(Flt a, SFlt b)
{   return (a.floatval() <= b.floatval());
}
// double float <= short float
bool Leq::op(double a, SFlt b)
{   return (a <= b.floatval());
}
// long float <= short float
bool Leq::op(LFlt a, SFlt b)
{   return f128_le(a.floatval(), RawFloat128::op(b));
}
// fixnum <= single float
bool Leq::op(Fixnum a, Flt b)
{   return Geq::op(b, a);
}
// bignum <= single float
bool Leq::op(uint64_t *a, Flt b)
{   return Geq::op(b, a);
}
// rational <= single float
bool Leq::op(Rat a, Flt b)
{   return Geq::op(b, a);
}
// complex <= single float
bool Leq::op(Cpx a, Flt b)
{   return Geq::op(b, a);
}
// short float <= single float
bool Leq::op(SFlt a, Flt b)
{   return Geq::op(b, a);
}
// single float <= single float
bool Leq::op(Flt a, Flt b)
{   return (a.floatval() <= b.floatval());
}
// double float <= single float
bool Leq::op(double a, Flt b)
{   return (a <= b.floatval());
}
// long float <= single float
bool Leq::op(LFlt a, Flt b)
{   return f128_le(a.floatval(), RawFloat128::op(b));
}
// fixnum <= double float
bool Leq::op(Fixnum a, double b)
{   return Geq::op(b, a);
}
// bignum <= double float
bool Leq::op(uint64_t *a, double b)
{   return Geq::op(b, a);
}
// rational <= double float
bool Leq::op(Rat a, double b)
{   return Geq::op(b, a);
}
// complex <= double float
bool Leq::op(Cpx a, double b)
{   return false;
}
// short float <= double float
bool Leq::op(SFlt a, double b)
{   return Geq::op(b, a);
}
// single float <= double float
bool Leq::op(Flt a, double b)
{   return Geq::op(b, a);
}
// double float <= double float
bool Leq::op(double a, double b)
{   return (a <= b);
}
// long float <= double float
bool Leq::op(LFlt a, double b)
{   return f128_le(a. floatval(), RawFloat128::op(b));
}
// fixnum <= long float
bool Leq::op(Fixnum a, LFlt b)
{   return Geq::op(b, a);
}
// bignum <= long float
bool Leq::op(uint64_t *a, LFlt b)
{   return Geq::op(b, a);
}
// rational <= long float
bool Leq::op(Rat a, LFlt b)
{   return Geq::op(b, a);
}
// complex <= long float
bool Leq::op(Cpx a, LFlt b)
{   return false;
}
// short float <= long float
bool Leq::op(SFlt a, LFlt b)
{   return Geq::op(b, a);
}
// single float <= long float
bool Leq::op(Flt a, LFlt b)
{   return Geq::op(b, a);
}
// double float <= long float
bool Leq::op(double a, LFlt b)
{   return Geq::op(b, a);
}
// long float <= long float
bool Leq::op(LFlt a, LFlt b)
{   return f128_le(a.floatval(), b.floatval());
}

bool Onep::op(LispObject a)
{   return number_dispatcher::unary<bool,Onep>("onep", a);
}

bool Onep::op(Fixnum a)
{   return a.value() == fixnum_of_int(1);
}

bool Onep::op(uint64_t *a)
{   return false;
}

bool Onep::op(Rat a)
{   return Onep::op(a.numerator()) && Onep::op(a.denominator());
}

bool Onep::op(Cpx a)
{   return Onep::op(a.real_part()) && Zerop::op(a.imag_part());
}

bool Onep::op(SFlt a)
{   return a.floatval() == 1.0;
}

bool Onep::op(Flt a)
{   return a.floatval() == 1.0;
}

bool Onep::op(double a)
{   return a == 1.0;
}

bool Onep::op(LFlt a)
{   return f128_eq(a.floatval(), arithlib_lowlevel::f128_1);
}

bool MinusOnep::op(LispObject a)
{   return number_dispatcher::unary<bool,MinusOnep>("minusonep", a);
}

bool MinusOnep::op(Fixnum a)
{   return a.value() == fixnum_of_int(-1);
}

bool MinusOnep::op(uint64_t *a)
{   return false;
}

bool MinusOnep::op(Rat a)
{   return MinusOnep::op(a.numerator()) && Onep::op(a.denominator());
}

bool MinusOnep::op(Cpx a)
{   return MinusOnep::op(a.real_part()) && Zerop::op(a.imag_part());
}

bool MinusOnep::op(SFlt a)
{   return a.floatval() == -1.0;
}

bool MinusOnep::op(Flt a)
{   return a.floatval() == -1.0;
}

bool MinusOnep::op(double a)
{   return a == -1.0;
}

bool MinusOnep::op(LFlt a)
{   return f128_eq(a.floatval(), arithlib_lowlevel::f128_m1);
}

bool Zerop::op(LispObject a)
{   return number_dispatcher::unary<bool,Zerop>("zerop", a);
}

bool Zerop::op(Fixnum a)
{   return a.value() == fixnum_of_int(0);
}

bool Zerop::op(uint64_t *a)
{   return false;
}

bool Zerop::op(Rat a)
{   return Zerop::op(a.numerator());
}

bool Zerop::op(Cpx a)
{   return Zerop::op(a.real_part()) && Zerop::op(a.imag_part());
}

bool Zerop::op(SFlt a)
{   return a.floatval() == 0.0;
}

bool Zerop::op(Flt a)
{   return a.floatval() == 0.0;
}

bool Zerop::op(double a)
{   return a == 0.0;
}

bool Zerop::op(LFlt a)
{   return f128_eq(a.floatval(), arithlib_lowlevel::f128_0);
}

bool Oddp::op(LispObject a)
{   return number_dispatcher::iunary<bool,Oddp>("oddp", a);
}

bool Oddp::op(Fixnum a)
{   return (a.intval() & 1) != 0;
}

bool Oddp::op(uint64_t *a)
{   return (a[0] & 1) != 0;
}

bool Evenp::op(LispObject a)
{   return number_dispatcher::iunary<bool,Evenp>("evenp", a);
}

bool Evenp::op(Fixnum a)
{   return (a.intval() & 1) == 0;
}

bool Evenp::op(uint64_t *a)
{   return (a[0] & 1) == 0;
}

bool Minusp::op(LispObject a)
{   return number_dispatcher::unary<bool,Minusp>("minusp", a);
}

bool Minusp::op(Fixnum a)
{   return a.intval() < 0;
}

bool Minusp::op(uint64_t *a)
{   return arithlib_lowlevel::Minusp::op(a);
}

bool Minusp::op(Rat a )
{   return Minusp::op(a.numerator());
}

bool Minusp::op(Cpx a)
{   return false;
}

bool Minusp::op(SFlt a)
{   return a.floatval() < 0.0;
}

bool Minusp::op(Flt a)
{   return a.floatval() < 0.0;
}

bool Minusp::op(double a)
{   return a < 0.0;
}

bool Minusp::op(LFlt a)
{   return f128_lt(a.floatval(), arithlib_lowlevel::f128_0);
}

LispObject Abs::op(LispObject a)
{   return number_dispatcher::unary<LispObject,Abs>("abs", a);
}

LispObject Abs::op(Fixnum a)
{   if (a.intval() < 0) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(uint64_t *a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return static_cast<LispObject>((uintptr_t)a - 8 + TAG_NUMBERS);
}

LispObject Abs::op(Rat a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(Cpx a)
{   return Sqrt::op(Plus::op(Square::op(a.real_part()),
                             Square::op(a.imag_part())));
}

LispObject Abs::op(SFlt a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(Flt a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return a.value();
}

LispObject Abs::op(double a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return make_boxfloat(a);
}

LispObject Abs::op(LFlt a)
{   if (Minusp::op(a)) return Minus::op(a);
    else return a.value();
}

#endif // ARITHLIB

// end of arith-compare.cpp

