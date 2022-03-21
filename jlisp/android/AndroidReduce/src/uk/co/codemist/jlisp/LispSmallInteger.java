package uk.co.codemist.jlisp;


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2011.
//

/**************************************************************************
 * Copyright (C) 1998-2011, Codemist Ltd.                A C Norman       *
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


import java.math.*;
import java.io.*;
import java.util.*;

public class LispSmallInteger extends LispInteger
{
    public int value;

// I will keep integers of up to 31 bits as "Small" integers. This means that
// the criterion I will use to notice them will be that as ints they will
// have their top two bits equal. For values in some (much) smaller range
// I will have a pre-allocated table of values and will return one of
// those when needed - thereby avoiding some heap allocation at the expense
// of extra calculation and testing.

    static final int MIN = -100;
    static final int MAX = 1000;
    static LispSmallInteger [] preAllocated = new LispSmallInteger[MAX-MIN+1];

    static void preAllocate()
    {
        for (int i=MIN; i<=MAX; i++)
            preAllocated[i-MIN] = new LispSmallInteger(i);
    }

    LispSmallInteger(int n)
    {
        value = n;
    }

    int intValue()
    {
        return value;
    }

    BigInteger bigIntValue()
    {
        return BigInteger.valueOf((long)value);
    }

    LispObject eval()
    {
        return this;
    }

    String printAs()
    {
        if ((currentFlags & (printBinary | printOctal | printHex)) == 0)   
            return Integer.toString(value);
        else if ((currentFlags & printBinary) != 0)
            return Integer.toBinaryString(value);
        else if ((currentFlags & printOctal) != 0)
            return Integer.toOctalString(value);
        else // if ((currentFlags & printHex) != 0)
            return Integer.toHexString(value);
    }

    void iprint() throws ResourceException
    {
        String s = printAs();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint() throws ResourceException
    {
        String s = printAs();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
    }

    double doubleValue()
    {
        return (double)value;
    }

    public boolean lispequals(Object b)
    {
        if (!(b instanceof LispSmallInteger)) return false;
        return value == ((LispSmallInteger)b).value;
    }
    
    public boolean equals(Object b)
    {
        if (!(b instanceof LispSmallInteger)) return false;
        return value == ((LispSmallInteger)b).value;
    }

    public int lisphashCode()
    {
        return value*696969;
    }
    
    public int hashCode()
    {
        return value*696969;
    }
    
    void scan()
    {
        Object w = new Integer(value);
        if (Jlisp.objects.contains(w)) // seen before?
	{   if (!Jlisp.repeatedObjects.containsKey(w))
	    {   Jlisp.repeatedObjects.put(
	            w,
	            Jlisp.nil); // value is junk at this stage
	    }
	}
	else Jlisp.objects.add(w);
    }
    
    void dump() throws IOException
    {
        Object d = new Integer(value);
        Object w = Jlisp.repeatedObjects.get(d);
	if (w != null &&
	    w instanceof Integer) putSharedRef(w); // processed before
	else
	{   if (w != null) // will be used again sometime
	    {   Jlisp.repeatedObjects.put(
	            d,
		    new Integer(Jlisp.sharedIndex++));
		Jlisp.odump.write(X_STORE);
            }
// Note whacky coding with sign bit in bottom bit position. The intent
// of this is that numbers that ar esmall in absolute value will be
// packed into rather few bytes.
	    putPrefix(value == 0x80000000 ? 1 :
                      value < 0 ? 1 + ((-value)<<1) :
                      value<<1,
                      X_FIXNUM);
	}
    }

    public LispObject negate() throws Exception
    {
        if (value == 0xc0000000) return new LispBigInteger(-value);
        return valueOf(-value);
    }

    public LispObject abs() throws Exception
    {
        if (value >= 0) return this;
        else if (value == 0xc0000000) return new LispBigInteger(-value);
        else return valueOf(-value);
    }

    public LispObject add1() throws Exception
    {
        if (value == 0x3fffffff) return new LispBigInteger(0x40000000);
        else return valueOf(value+1);
    }

    public LispObject sub1() throws Exception
    {
        if (value == 0xc0000000) return new LispBigInteger(0xbfffffff);
        return valueOf(value-1);
    }

    public LispObject msd() throws Exception
    {
        int r = 0, w = value;
        if (w < 0) w = -(w + 1);
        while ((w & ~0x3f) != 0)
        {   w = w >>> 6;
            r += 6;
        }
        while (w != 0)
        {   w = w >>> 1;
            r += 1;
        }
        return valueOf(r);
    }

    public LispObject lsd() throws Exception
    {
        int r = 0, w = value;
        if (w == 0) return valueOf(-1);
        while ((w & 0x3f) == 0)
        {   w = w >> 6;
            r += 6;
        }
        while ((w & 0x1) == 0)
        {   w = w >> 1;
            r += 1;
        }
        return valueOf(r);
    }

    LispObject not() throws Exception
    {
        return valueOf(~value);
    }

    LispObject modMinus() throws Exception
    {
        if (value == 0) return this;
        else return valueOf(Jlisp.modulus - value);
    }

    LispObject modRecip() throws Exception
    {
        if (value == 0) 
            return Jlisp.error("attempt to take modular recip of zero");
        int a = Jlisp.modulus, b = value, s = 0, t = 1;
        while (b != 0)
        {   int q = a/b;
            int w = a - q*b; a = b; b = w;
            w = s - q*t; s = t; t = w;
        }
        if (s < 0) s += Jlisp.modulus;
        return valueOf(s);
    }

    LispObject safeModRecip() throws Exception
    {
        if (value == 0) return Jlisp.nil;
        int a = Jlisp.modulus, b = value, s = 0, t = 1;
        while (b != 0)
        {   int q = a/b;
            int w = a - q*b; a = b; b = w;
            w = s - q*t; s = t; t = w;
        }
        if (s < 0) s += Jlisp.modulus;
        return valueOf(s);
    }

    LispObject reduceMod() throws Exception
    {
        int r = value % Jlisp.modulus;
        if (r < 0) r += Jlisp.modulus;
        return valueOf(r);
    }

    public LispObject floor() throws Exception
    {
        return this;
    }

    public LispObject ceiling() throws Exception
    {
        return this;
    }

    public LispObject round() throws Exception
    {
        return this;
    }

    LispObject truncate() throws Exception
    {
        return this;
    }

    public LispObject ash(int n) throws Exception
    {
        if (n > 0) return valueOf(BigInteger.valueOf((long)value).shiftLeft(n));
        else if (n < -31)
        {   if (value < 0) return valueOf(-1);
            else return valueOf(0);
        }
        else if (n < 0) return valueOf(value >> (-n));
        else return this;
    }

    public LispObject ash1(int n) throws Exception
    {
        if (n > 0) return valueOf(BigInteger.valueOf((long)value).shiftLeft(n));
        else if (n < -31) return valueOf(0);
        else if (n < 0)
        {   if (value >= 0)
                return valueOf(value >> (-n));
            else return valueOf(-((-value) >> (-n)));
        }
        else return this;
    }

    public LispObject rightshift(int n) throws Exception
    {
        return valueOf(value >> n);
    }

    public LispObject evenp() throws Exception
    {
        return ((value & 1) != 0) ? Jlisp.nil : Jlisp.lispTrue;
    }

    public LispObject oddp() throws Exception
    {
        return ((value & 1) != 0) ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject fix() throws Exception
    {
        return this;
    }

    public LispObject fixp() throws Exception
    {
        return Jlisp.lispTrue;
    }

    public LispObject integerp() throws Exception
    {
        return Jlisp.lispTrue;
    }

    public LispObject jfloat() throws Exception
    {
        return new LispFloat((double)value);
    }

    public LispObject floatp() throws Exception
    {
        return Jlisp.nil;
    }

    public LispObject minusp() throws Exception
    {
        return value < 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject plusp() throws Exception
    {
        return value >= 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject zerop() throws Exception
    {
        return value == 0 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject onep() throws Exception
    {
        return value == 1 ? Jlisp.lispTrue : Jlisp.nil;
    }

    public LispObject add(LispObject a) throws Exception
    {
        return a.addSmallInteger(this);
    }

    public LispObject subtract(LispObject a) throws Exception
    {
        return a.subtractSmallInteger(this);
    }

    public LispObject multiply(LispObject a) throws Exception
    {
        return a.multiplySmallInteger(this);
    }

    public LispObject expt(LispObject a) throws Exception
    {
        return a.exptSmallInteger(this);
    }

    public LispObject divide(LispObject a) throws Exception
    {
        return a.divideSmallInteger(this);
    }

    public LispObject remainder(LispObject a) throws Exception
    {
        return a.remainderSmallInteger(this);
    }

    public LispObject quotientAndRemainder(LispObject a) throws Exception
    {
        return a.quotientAndRemainderSmallInteger(this);
    }

    public LispObject mod(LispObject a) throws Exception
    {
        return a.modSmallInteger(this);
    }

    public LispObject max(LispObject a) throws Exception
    {
        return a.maxSmallInteger(this);
    }

    public LispObject min(LispObject a) throws Exception
    {
        return a.minSmallInteger(this);
    }

    public LispObject and(LispObject a) throws Exception
    {
        return a.andSmallInteger(this);
    }

    public LispObject or(LispObject a) throws Exception
    {
        return a.orSmallInteger(this);
    }

    LispObject xor(LispObject a) throws Exception
    {
        return a.xorSmallInteger(this);
    }

    LispObject gcd(LispObject a) throws Exception
    {
        return a.gcdSmallInteger(this);
    }

    LispObject lcm(LispObject a) throws Exception
    {
        return a.lcmSmallInteger(this);
    }

    LispObject modAdd(LispObject a) throws Exception
    {
        return a.modAddSmallInteger(this);
    }

    LispObject modSubtract(LispObject a) throws Exception
    {
        return a.modSubtractSmallInteger(this);
    }

    LispObject modMultiply(LispObject a) throws Exception
    {
        return a.modMultiplySmallInteger(this);
    }

    LispObject modDivide(LispObject a) throws Exception
    {
        return a.modDivideSmallInteger(this);
    }

    LispObject modExpt(int a) throws Exception
    {
        long r = 1;
        long w = value;
        while (a != 0)
        {   if ((a & 1) != 0) r = (r*w) % Jlisp.modulus;
            w = (w*w) % Jlisp.modulus;
            a = a >>> 1;
        }
        if (r < 0) r += Jlisp.modulus;
        return valueOf(r);
    }

    boolean eqn(LispObject a) throws Exception
    {
        return a.eqnSmallInteger(this);
    }

    boolean neqn(LispObject a) throws Exception
    {
        return a.neqnSmallInteger(this);
    }

    boolean ge(LispObject a) throws Exception
    {
        return a.geSmallInteger(this);
    }

    boolean geq(LispObject a) throws Exception
    {
        return a.geqSmallInteger(this);
    }

    boolean le(LispObject a) throws Exception
    {
        return a.leSmallInteger(this);
    }

    boolean leq(LispObject a) throws Exception
    {
        return a.leqSmallInteger(this);
    }

// Now versions that know they have one integer and one small integer.
// I am going to accept that these will be seriously slower than the
// LispSmallInteger cases and to cope with that I will suppose that
// they always return small integers if they can.

    LispObject addInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.add(BigInteger.valueOf((long)value)));
    }

    LispObject subtractInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.subtract(BigInteger.valueOf((long)value)));
    }

    LispObject multiplyInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.multiply(BigInteger.valueOf((long)value)));
    }

    LispObject divideInteger(LispBigInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return valueOf(a.value.divide(BigInteger.valueOf((long)value)));
    }

    LispObject remainderInteger(LispBigInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return valueOf(a.value.remainder(BigInteger.valueOf((long)value)));
    }

    LispObject quotientAndRemainderInteger(LispBigInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        BigInteger [] r = a.value.divideAndRemainder(BigInteger.valueOf((long)value));
        return new Cons(valueOf(r[0]), valueOf(r[1]));
    }

    LispObject modInteger(LispBigInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return valueOf(a.value.mod(BigInteger.valueOf((long)value)));
    }

    LispObject exptInteger(LispBigInteger a) throws Exception
    {
        if (value < 0) return valueOf(0);
        else if (value == 0) return valueOf(1);
        else if (value >= 0x10000)
            return Jlisp.error("integer result would be too large");
        else return valueOf(a.value.pow(value));
    }

    LispObject maxInteger(LispBigInteger a) throws Exception
    {
        if (a.value.compareTo(BigInteger.valueOf((long)value)) >= 0) return a;
        else return this;
    }

    LispObject minInteger(LispBigInteger a) throws Exception
    {
        if (a.value.compareTo(BigInteger.valueOf((long)value)) <= 0) return a;
        else return this;
    }

    LispObject andInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.and(BigInteger.valueOf((long)value)));
    }

    LispObject orInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.or(BigInteger.valueOf((long)value)));
    }

    LispObject xorInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.xor(BigInteger.valueOf((long)value)));
    }

    LispObject gcdInteger(LispBigInteger a) throws Exception
    {
        return valueOf(a.value.gcd(BigInteger.valueOf((long)value)));
    }

    LispObject lcmInteger(LispBigInteger a) throws Exception
    {
        return valueOf(LispBigInteger.biglcm(
           a.value, BigInteger.valueOf((long)value)));
    }

    boolean eqnInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) == 0);
    }

    boolean neqnInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) != 0);
    }

    boolean geInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) > 0);
    }

    boolean geqInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) >= 0);
    }

    boolean leInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) < 0);
    }

    boolean leqInteger(LispBigInteger a) throws Exception
    {
        return (a.value.compareTo(BigInteger.valueOf((long)value)) <= 0);
    }

// Finally versions that know they have 2 small integer args. Here I need
// to worry about overflow and promote to a LispBigInteger in suitable cases.

    LispObject addSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(a.value + value);
    }

    LispObject subtractSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(a.value - value);
    }

    LispObject multiplySmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf((long)a.value * (long)value);
    }

    LispObject divideSmallInteger(LispSmallInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return valueOf(a.value / value);
    }

    LispObject remainderSmallInteger(LispSmallInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return valueOf(a.value % value);
    }

    LispObject quotientAndRemainderSmallInteger(LispSmallInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        return new Cons(valueOf(a.value / value),
                        valueOf(a.value % value));
    }

    LispObject modSmallInteger(LispSmallInteger a) throws Exception
    {
        if (value == 0) return Jlisp.error("attempt to divide by zero");
        int r = a.value % value;
        if (value > 0)
        {   if (r < 0) r += value;
        }
        else if (r > 0) r += value;
        return valueOf(r);
    }

    LispObject exptSmallInteger(LispSmallInteger a) throws Exception
    {
        if (value < 0) return valueOf(0);
        else if (value == 0) return valueOf(1);
        else if (value >= 0x10000)
                 return Jlisp.error("integer result would be too large");
        else return valueOf(
                        BigInteger.valueOf((long)a.value).pow(value));
    }

    LispObject maxSmallInteger(LispSmallInteger a) throws Exception
    {
        if (a.value >= value) return a;
        else return this;
    }

    LispObject minSmallInteger(LispSmallInteger a) throws Exception
    {
        if (a.value <= value) return a;
        else return this;
    }

    LispObject andSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(a.value & value);
    }

    LispObject orSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(a.value | value);
    }

    LispObject xorSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(a.value ^ value);
    }

    LispObject gcdSmallInteger(LispSmallInteger a) throws Exception
    {
        int p = a.value;
        int q = value;
        if (p < 0) p = -p;
        if (q < 0) q = -q;
        if (p == 0) return valueOf(q);
        if (p < q)
        {   q = q % p;
        }
        while (q != 0)
        {   int r = p % q;
            p = q;
            q = r;
        }
        return valueOf(p);
    }

    LispObject lcmSmallInteger(LispSmallInteger a) throws Exception
    {
        return valueOf(
            LispBigInteger.biglcm(
                BigInteger.valueOf((long)a.value),
                BigInteger.valueOf((long)value)));
    }

    LispObject modAddSmallInteger(LispSmallInteger a) throws Exception
    {
        int n = a.value + value;
        if (n >= Jlisp.modulus) n -= Jlisp.modulus;
        return valueOf(n);
    }

    LispObject modSubtractSmallInteger(LispSmallInteger a) throws Exception
    {
        int n = a.value - value;
        if (n < 0) n += Jlisp.modulus;
        return valueOf(n);
    }

    LispObject modMultiplySmallInteger(LispSmallInteger a) throws Exception
    {
        long n = (long)a.value * (long)value;
        return valueOf(n % Jlisp.modulus);
    }

    LispObject modDivideSmallInteger(LispSmallInteger arg) throws Exception
    {
        if (value == 0) 
            return Jlisp.error("attempt to divide by (modular) zero");
        int a = Jlisp.modulus, b = value, s = 0, t = 1;
        while (b != 0)
        {   int q = a/b;
            int w = a - q*b; a = b; b = w;
            w = s - q*t; s = t; t = w;
        }
        if (s < 0) s += Jlisp.modulus;
        return valueOf(((long)s * (long)arg.value) % Jlisp.modulus);
    }

    boolean eqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value == value);
    }

    boolean neqnSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value != value);
    }

    boolean geSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value > value);
    }

    boolean geqSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value >= value);
    }

    boolean leSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value < value);
    }

    boolean leqSmallInteger(LispSmallInteger a) throws Exception
    {
        return (a.value <= value);
    }

}

// End of LispSmallInteger.java


