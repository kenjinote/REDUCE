package uk.co.codemist.jlisp.core;

//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2015.
//

// Fns2.java

/**************************************************************************
 * Copyright (C) 1998-2015, Codemist Ltd.                A C Norman       *
 *                            also contributions from Vijay Chauhan, 2002 *
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
// This is a whole load of support for the numeric data-types

// To do:  iplus etc
//         modular-plus etc
//         fix/float/round/ceiling
//         hyperbolic functions

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

class Fns2
{
    Object [][] builtins = 
    {
        {"abs",                         new AbsFn()},
        {"acos",                        new AcosFn()},
        {"acosd",                       new AcosdFn()},
        {"acosh",                       new AcoshFn()},
        {"acot",                        new AcotFn()},
        {"acotd",                       new AcotdFn()},
        {"acoth",                       new AcothFn()},
        {"acsc",                        new AcscFn()},
        {"acscd",                       new AcscdFn()},
        {"acsch",                       new AcschFn()},
        {"add1",                        new Add1Fn()},
        {"asec",                        new AsecFn()},
        {"asecd",                       new AsecdFn()},
        {"asech",                       new AsechFn()},
        {"ash",                         new AshFn()},
        {"ash1",                        new Ash1Fn()},
        {"asin",                        new AsinFn()},
        {"asind",                       new AsindFn()},
        {"asinh",                       new AsinhFn()},
        {"atan",                        new AtanFn()},
        {"atan2",                       new Atan2Fn()},
        {"atan2d",                      new Atan2dFn()},
        {"atand",                       new AtandFn()},
        {"atanh",                       new AtanhFn()},
        {"ceiling",                     new CeilingFn()},
        {"cos",                         new CosFn()},
        {"cosd",                        new CosdFn()},
        {"cosh",                        new CoshFn()},
        {"cot",                         new CotFn()},
        {"cotd",                        new CotdFn()},
        {"coth",                        new CothFn()},
        {"csc",                         new CscFn()},
        {"cscd",                        new CscdFn()},
        {"csch",                        new CschFn()},
        {"difference",                  new DifferenceFn()},
        {"divide",                      new DivideFn()},
        {"eq-safe",                     new EqSafeFn()},
        {"eqn",                         new EqnFn()},
        {"evenp",                       new EvenpFn()},
        {"exp",                         new ExpFn()},
        {"expt",                        new ExptFn()},
        {"find-gnuplot",                new FindGnuplotFn()},
        {"fix",                         new FixFn()},
        {"fixp",                        new FixpFn()},
        {"float",                       new FloatFn()},
        {"floatp",                      new FloatpFn()},
        {"floor",                       new FloorFn()},
        {"frexp",                       new FrexpFn()},
        {"gcdn",                        new GcdnFn()},
        {"geq",                         new GeqFn()},
        {"greaterp",                    new GreaterpFn()},
        {"hypot",                       new HypotFn()},
        {"iadd1",                       new Iadd1Fn()},
        {"id2string",                   new Id2stringFn()},
        {"idifference",                 new IdifferenceFn()},
        {"igeq",                        new IgeqFn()},
        {"igreaterp",                   new IgreaterpFn()},
        {"ileq",                        new IleqFn()},
        {"ilessp",                      new IlesspFn()},
        {"ilogand",                     new IlogandFn()},
        {"ilogor",                      new IlogorFn()},
        {"ilogxor",                     new IlogxorFn()},
        {"imax",                        new ImaxFn()},
        {"imin",                        new IminFn()},
        {"iminus",                      new IminusFn()},
        {"iminusp",                     new IminuspFn()},
        {"integerp",                    new IntegerpFn()},
        {"ionep",                       new IonepFn()},
        {"iplus",                       new IplusFn()},
        {"iplus2",                      new Iplus2Fn()},
        {"iquotient",                   new IquotientFn()},
        {"iremainder",                  new IremainderFn()},
        {"ashift",                      new AshiftFn()},
        {"lshift",                      new LshiftFn()},
        {"irightshift",                 new IrightshiftFn()},
        {"is-spid",                     new Is_spidFn()},
        {"spid-to-nil",                 new Spid_to_nilFn()},
        {"isub1",                       new Isub1Fn()},
        {"itimes",                      new ItimesFn()},
        {"itimes2",                     new Itimes2Fn()},
        {"izerop",                      new IzeropFn()},
        {"lcm",                         new LcmnFn()},
        {"lcmn",                        new LcmnFn()},
        {"leq",                         new LeqFn()},
        {"lessp",                       new LesspFn()},
        {"ln",                          new LnFn()},
        {"log",                         new LogFn()},
        {"log10",                       new Log10Fn()},
        {"land",                        new LogandFn()},
        {"logand",                      new LogandFn()},
        {"logb",                        new LogbFn()},
        {"logeqv",                      new LogeqvFn()},
        {"lognot",                      new LognotFn()},
        {"lor",                         new LogorFn()},
        {"logor",                       new LogorFn()},
        {"logxor",                      new LogxorFn()},
        {"lose-precision",              new Lose_precisionFn()},
        {"lsd",                         new LsdFn()},
        {"max",                         new MaxFn()},
        {"max2",                        new Max2Fn()},
        {"min",                         new MinFn()},
        {"min2",                        new Min2Fn()},
        {"minus",                       new MinusFn()},
        {"minusp",                      new MinuspFn()},
        {"mod",                         new ModFn()},
        {"modular-difference",          new Modular_differenceFn()},
        {"modular-expt",                new Modular_exptFn()},
        {"modular-minus",               new Modular_minusFn()},
        {"modular-number",              new Modular_numberFn()},
        {"modular-plus",                new Modular_plusFn()},
        {"modular-quotient",            new Modular_quotientFn()},
        {"modular-reciprocal",          new Modular_reciprocalFn()},
        {"safe-modular-reciprocal",     new Safe_modular_reciprocalFn()},
        {"modular-times",               new Modular_timesFn()},
        {"msd",                         new MsdFn()},
        {"mv-list",                     new MvListFn()},
        {"numberp",                     new NumberpFn()},
        {"oddp",                        new OddpFn()},
        {"onep",                        new OnepFn()},
        {"plus",                        new PlusFn()},
        {"plus2",                       new Plus2Fn()},
        {"plusp",                       new PluspFn()},
        {"quotient",                    new QuotientFn()},
        {"random-fixnum",               new Random_fixnumFn()},
        {"random",                      new Random_numberFn()},
        {"random-number",               new Random_numberFn()},
        {"rational",                    new RationalFn()},
        {"remainder",                   new RemainderFn()},
        {"round",                       new RoundFn()},
        {"sec",                         new SecFn()},
        {"secd",                        new SecdFn()},
        {"sech",                        new SechFn()},
        {"set-small-modulus",           new Set_small_modulusFn()},
        {"sin",                         new SinFn()},
        {"sind",                        new SindFn()},
        {"sinh",                        new SinhFn()},
        {"sqrt",                        new SqrtFn()},
        {"sub1",                        new Sub1Fn()},
        {"tan",                         new TanFn()},
        {"tand",                        new TandFn()},
        {"tanh",                        new TanhFn()},
        {"times",                       new TimesFn()},
        {"times2",                      new Times2Fn()},
        {"truncate",                    new TruncateFn()},
        {"zerop",                       new ZeropFn()}
    };



class Plus2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.add(arg2);
    }
}



class PlusFn extends BuiltinFunction
{
    public LispObject op0() { return LispInteger.valueOf(0); }
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.add(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.add(args[i]);
        return r;
    }
}

class Times2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.multiply(arg2);
    }
}



class TimesFn extends BuiltinFunction
{
    public LispObject op0() { return LispInteger.valueOf(1); }
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.multiply(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.multiply(args[i]);
        return r;
    }
}

class Max2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.max(arg2);
    }
}



class MaxFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.max(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.max(args[i]);
        return r;
    }
}

class Min2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.min(arg2);
    }
}



class MinFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.min(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.min(args[i]);
        return r;
    }
}

class AbsFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.abs();
    }
}

class AcosFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > 1.0 || a < -1.0) return error("bad arg for acos");
        a = Math.acos(a);
        return new LispFloat(a);
    }
}

class AcosdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > 1.0 || a < -1.0) return error("bad arg for acosd");
        a = 180.0*Math.acos(a)/Math.PI;
        return new LispFloat(a);
    }
}

class AcoshFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a < 1.0) return error("bad arg for acosh");
        a = MyMath.acosh(a);
        return new LispFloat(a);
    }
}

class AcotFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.PI/2.0 - Math.atan(a);
        return new LispFloat(a);
    }
}

class AcotdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 90.0 - 180.0*Math.atan(a)/Math.PI;
        return new LispFloat(a);
    }
}

class AcothFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > -1.0 && a < 1.0) return error("bad arg for acoth");
        a = MyMath.acoth(a);
        return new LispFloat(a);
    }
}

class AcscFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > -1.0 && a < 1.0) return error("bad arg for acsc");
        a = Math.asin(1.0/a);
        return new LispFloat(a);
    }
}

class AcscdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > -1.0 && a < 1.0) return error("bad arg for acscd");
        a = 180.0*Math.asin(1.0/a)/Math.PI;
        return new LispFloat(a);
    }
}

class AcschFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.acsch(a);
        return new LispFloat(a);
    }
}

class Add1Fn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.add1();
    }
}

class AsecFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > -1.0 && a < 1.0) return error("bad arg for asec");
        a = Math.acos(1.0/a);
        return new LispFloat(a);
    }
}

class AsecdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > -1.0 && a < 1.0) return error("bad arg for asecd");
        a = 180.0*Math.acos(1.0/a)/Math.PI;
        return new LispFloat(a);
    }
}

class AsechFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a < 0.0 || a > 1.0) return error("bad arg for asech");
        a = MyMath.asech(a);
        return new LispFloat(a);
    }
}

class AshFn extends BuiltinFunction
{
// Shift - thinking of things as twos-complement binary numbers 
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.ash(((LispSmallInteger)arg2).value);
    }
}

class Ash1Fn extends BuiltinFunction
{
// Shift - thinking of things as sign-and-magnitude numbers 
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.ash1(((LispSmallInteger)arg2).value);
    }
}

class AsinFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a < -1.0 || a > 1.0) return error("bad arg for asin");
        a = Math.asin(a);
        return new LispFloat(a);
    }
}

class AsindFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a < -1.0 || a > 1.0) return error("bad arg for asind");
        a = 180.0*Math.asin(a)/Math.PI;
        return new LispFloat(a);
    }
}

class AsinhFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.asinh(a);
        return new LispFloat(a);
    }
}


class CeilingFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.ceiling();
    }
}

class AtanFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.atan(a);
        return new LispFloat(a);
    }
}

class Atan2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a = arg1.doubleValue();
        double b = arg2.doubleValue();
        a = Math.atan2(a, b);
        return new LispFloat(a);
    }
}

class Atan2dFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a = arg1.doubleValue();
        double b = arg2.doubleValue();
        a = 180.0*Math.atan2(a, b)/Math.PI;
        return new LispFloat(a);
    }
}

class AtandFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 180.0*Math.atan(a)/Math.PI;
        return new LispFloat(a);
    }
}

class AtanhFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a > 1.0 || a < -1.0) return error("bad arg for atanh");
        a = MyMath.atanh(a);
        return new LispFloat(a);
    }
}

class CosFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.cos(a);
        return new LispFloat(a);
    }
}

class CosdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.cos(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class CoshFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.cosh(a);
        return new LispFloat(a);
    }
}

class CotFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.tan(a);
        return new LispFloat(a);
    }

}

class CotdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.tan(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class CothFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.coth(a);
        return new LispFloat(a);
    }
}

class CscFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.sin(a);
        return new LispFloat(a);
    }
}

class CscdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.sin(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class CschFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.csch(a);
        return new LispFloat(a);
    }
}

class DifferenceFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.subtract(arg2);
    }
}

class DivideFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.quotientAndRemainder(arg2);
    }
}

class EvenpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.evenp();
    }
}

class ExpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.exp(a);
        return new LispFloat(a);
    }
}

class ExptFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.expt(arg2);
    }
}

class FindGnuplotFn extends BuiltinFunction
{
    public LispObject op0(LispObject arg1) throws Exception
    {
        return new LispString("gnuplot");
    }
}


class FixFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.fix();
    }
}


class EqSafeFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
// I have made Jlisp's version of EQ test small integers in an expensive
// way so I can report as I do here. This is for better compatibility
// with CSL and PSL despite a performance hit.
        if (arg1 instanceof Symbol ||
            arg1 instanceof LispSmallInteger) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class FixpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.fixp();
    }
}

class FloatFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.jfloat();
    }
}

class FloatpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.floatp();
    }
}

class FloorFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.floor();
    }
}

class FrexpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double d = ((LispFloat)arg1).value;
        if (d == 0.0) return new Cons(LispInteger.valueOf(0), arg1);
	long l = Double.doubleToLongBits(d);
	long x = (l >> 52) & 0x7ff;
// NaN and infinity do not normalise a lot
        if (x == 0x7ff) return new Cons(LispInteger.valueOf(0), arg1);
        if (x == 0) // a denormalised number
        {   long s = l & 0x8000000000000000L;
            while ((l & 0x0010000000000000L) == 0)
            {   x--;
                l = l << 1;
            }
            l = s | (l & 0x000fffffffffffffL);
        }
        x = x - 0x3fe;
	l = (l & 0x800fffffffffffffL) | 0x3fe0000000000000L;
	return new Cons(LispInteger.valueOf((int)x),
	                new LispFloat(Double.longBitsToDouble(l)));
    }
}

class GcdnFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(0); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.gcd(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.gcd(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class GeqFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.geq(arg2) ? Jlisp.lispTrue : Jlisp.nil;
    }
}

class EqnFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.eqn(arg2) ? Jlisp.lispTrue : Jlisp.nil;
    }
}


class GreaterpFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.ge(arg2) ? Jlisp.lispTrue : Jlisp.nil;
    }
}

class HypotFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a = arg1.doubleValue();
        double b = arg2.doubleValue();
        double d = Math.sqrt(a*a + b*b);
        return new LispFloat(d);
    }
}

class Iadd1Fn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.add1();
    }
}

class Id2stringFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        if (!(arg1 instanceof Symbol)) return error("not an identifier for id2string");
        ((Symbol)arg1).completeName();
        return new LispString(((Symbol)arg1).pname);
    }
}

class IdifferenceFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.subtract(arg2);
    }
}

class IgeqFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        if (arg1.geq(arg2)) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class IgreaterpFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        if (arg1.ge(arg2)) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class IleqFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        if (arg1.leq(arg2)) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class IlesspFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        if (arg1.le(arg2)) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class IlogandFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(-1); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.and(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.and(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class IlogorFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(0); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.or(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.or(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class IlogxorFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(0); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.xor(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.xor(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class ImaxFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.max(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.max(args[i]);
        return r;
    }
}

class IminFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.min(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.min(args[i]);
        return r;
    }
}

class IminusFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.negate();
    }
}

class IminuspFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.minusp();
    }
}

class IntegerpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.integerp();
    }
}

class IonepFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.onep();
    }
}

class IplusFn extends BuiltinFunction
{
    public LispObject op0() { return LispInteger.valueOf(0); }
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.add(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.add(args[i]);
        return r;
    }
}

class Iplus2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.add(arg2);
    }    
}

class IquotientFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.divide(arg2);
    }    
}

class IremainderFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.remainder(arg2);
    }    
}

class AshiftFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        int n = ((LispSmallInteger)arg2).value;
        if (n < 0) return arg1.rightshift(-n);
        else return arg1.leftshift(n);
    }
}

class LshiftFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        int n = ((LispSmallInteger)arg2).value;
        if (n < 0) return arg1.rightshift(-n);
        else return arg1.leftshift(n);
    }
}

class IrightshiftFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.rightshift(((LispSmallInteger)arg2).value);
    }
}

class Isub1Fn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.sub1();
    }
}

class ItimesFn extends BuiltinFunction
{
    public LispObject op0() { return LispInteger.valueOf(1); }
    public LispObject op1(LispObject arg1) { return arg1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.multiply(arg2);
    }    
    public LispObject opn(LispObject [] args) throws Exception
    {
        LispObject r = args[0];
        for (int i=1; i<args.length; i++)
            r = r.multiply(args[i]);
        return r;
    }
}

class Itimes2Fn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.multiply(arg2);
    }    
}

class IzeropFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.zerop();
    }
}

class LcmnFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(1); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.lcm(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = LispBigInteger.biglcm(r, args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class LeqFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.leq(arg2) ? Jlisp.lispTrue : Jlisp.nil;
    }
}

class LesspFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.le(arg2) ? Jlisp.lispTrue : Jlisp.nil;
    }
}

class LnFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a <= 0.0) return error("bad arg for ln");
        a = Math.log(a);
        return new LispFloat(a);
    }
}

class LogFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a <= 0.0) return error("bad arg for log");
        a = Math.log(a);
        return new LispFloat(a);
    }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a1 = arg1.doubleValue();
        double a2 = arg2.doubleValue();
	if (a1 <= 0.0 || a2 <= 0.0) return error("bad arg for log");
        a1 = Math.log(a1)/Math.log(a2);
        return new LispFloat(a1);
    }
}

class Log10Fn extends BuiltinFunction
{
    final double log10 = Math.log(10.0);
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a <= 0.0) return error("bad arg for log10");
        a = Math.log(a)/log10;
        return new LispFloat(a);
    }
}

class LogandFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(-1); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.and(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.and(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class LogbFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a1 = arg1.doubleValue();
        double a2 = arg2.doubleValue();
	if (a1 <= 0.0 || a2 <= 0.0) return error("bad arg for logb");
        a1 = Math.log(a1)/Math.log(a2);
        return new LispFloat(a1);
    }
}

class LogeqvFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(-1); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.xor(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.xor(args[i].bigIntValue()).not();
        return LispInteger.valueOf(r);
    }

}

class LognotFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.not();
    }
}

class LogorFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(0); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.or(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.or(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class LogxorFn extends BuiltinFunction
{
    public LispObject op0()
    { return LispInteger.valueOf(0); }
    public LispObject op1(LispInteger a1)
    { return a1; }
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.xor(arg2);
    }
    public LispObject opn(LispObject [] args) throws Exception
    {
        BigInteger r = args[0].bigIntValue();
        for (int i=2; i<args.length; i++)
            r = r.xor(args[i].bigIntValue());
        return LispInteger.valueOf(r);
    }
}

class Lose_precisionFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return error(name + " not yet implemented");
    }
}

class LsdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.lsd();
    }
}

class MinusFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.negate();
    }
}

class MinuspFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.minusp();
    }
}

class ModFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.mod(arg2);
    }
}

class Modular_differenceFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.modSubtract(arg2);
    }
}

class Modular_exptFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.modExpt(arg2.intValue());
    }
}

class Modular_minusFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.modMinus();
    }
}

class Modular_numberFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.reduceMod();
    }
}

class Modular_plusFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.modAdd(arg2);
    }
}

class Modular_quotientFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.modDivide(arg2);
    }
}

class Modular_reciprocalFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.modRecip();
    }
}

class Safe_modular_reciprocalFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.safeModRecip();
    }
}

class Modular_timesFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.modMultiply(arg2);
    }
}

class QuotientFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.divide(arg2);
    }
}

class MsdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.msd();
    }
}

class MvListFn extends BuiltinFunction
{
// In Common Lisp "mv-list" might be used to save multiple values, eg
// across unwind-protect. In Standard Lisp there are no multiple values so
// this has degenerate behaviour.
    public LispObject op1(LispObject arg1) throws Exception
    {
        return new Cons(arg1, Jlisp.nil);
    }
}

class NumberpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1)
    {
        if (arg1 instanceof LispNumber) return Jlisp.lispTrue;
        else return Jlisp.nil;
    }
}

class OddpFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.oddp();
    }
}

class OnepFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.onep();
    }
}

class PluspFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.plusp();
    }
}

class Random_fixnumFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
// Valus a positive number that would be a fixnum in CSL!
        int w = Jlisp.random.nextInt() & 0x07ffffff;
        return LispInteger.valueOf(w);
    }
}

class Random_numberFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
// Argument should be a positive integer or float...
        if (arg1 instanceof LispFloat)
            return new LispFloat(Jlisp.random.nextDouble()*
                                 ((LispFloat)arg1).value);
        BigInteger b = arg1.bigIntValue();
//@@@@ Unfinished work @@@@
        return error(name + " not yet implemented");
    }
}

class RationalFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return error(name + " not yet implemented");
    }
}

class RemainderFn extends BuiltinFunction
{
    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        return arg1.remainder(arg2);
    }
}

class RoundFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.round();
    }
}

class SecFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.cos(a);
        return new LispFloat(a);
    }
}

class SecdFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = 1.0/Math.cos(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class SechFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.sech(a);
        return new LispFloat(a);
    }
}

class Set_small_modulusFn extends BuiltinFunction
{
// For full CSL compatibility I need to allow the modulus to be either
// large or small here.
    public LispObject op1(LispObject arg1) throws Exception
    {
        BigInteger old = Jlisp.bigModulus;
        if (arg1 instanceof LispSmallInteger)
        {   int n = ((LispSmallInteger)arg1).value;
            if (n <= 0) 
                 return error("set-small-modulus needs a positive argument");
            Jlisp.modulus = n;
            Jlisp.bigModulus = BigInteger.valueOf(n);
            Jlisp.modulusIsBig = false;
        }
        else if (arg1 instanceof LispBigInteger)
        {   BigInteger n = ((LispBigInteger)arg1).value;
            if (n.signum() < 0)
                 return error("set-small-modulus needs a positive argument");
            Jlisp.modulus = 0;   // Invalid here!
            Jlisp.bigModulus = n;
            Jlisp.modulusIsBig = true;
        }
        else return error("arg of set-small-modulus is not an integer");
        return LispInteger.valueOf(old);
    }
}

class SinFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.sin(a);
        return new LispFloat(a);
    }
}

class SindFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.sin(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class SinhFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.sinh(a);
        return new LispFloat(a);
    }
}

class SqrtFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
	if (a < 0.0) return error("bad arg for sqrt");
        a = Math.sqrt(a);
        return new LispFloat(a);
    }
}

class Sub1Fn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.sub1();
    }
}

class TanFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.tan(a);
        return new LispFloat(a);
    }
}

class TandFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = Math.tan(Math.PI*a/180.0);
        return new LispFloat(a);
    }
}

class TanhFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        double a = arg1.doubleValue();
        a = MyMath.tanh(a);
        return new LispFloat(a);
    }
}

class TruncateFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.truncate();
    }

    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        double a1, a2;
        if (arg1 instanceof LispInteger)
	{   if (arg2 instanceof LispInteger)
                return arg1.divide(arg2);
	    else a1 = arg1.doubleValue(); // overflow?
        }
        else a1 = ((LispFloat)arg1).value;
        a2 = arg2.doubleValue();
// There is worry here with overflow etc. But maybe nobody ever calls this!
        return LispInteger.valueOf((long)(a1 / a2));
    }
}

class ZeropFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1.zerop();
    }
}

// The next two are used in compiled code when handling &OPT optional
// arguments.

class Is_spidFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1 instanceof Spid ? Jlisp.lispTrue : Jlisp.nil;
    }
}

class Spid_to_nilFn extends BuiltinFunction
{
    public LispObject op1(LispObject arg1) throws Exception
    {
        return arg1 instanceof Spid ? Jlisp.lispTrue : arg1;
    }
}

}

// End of Fns2.java

