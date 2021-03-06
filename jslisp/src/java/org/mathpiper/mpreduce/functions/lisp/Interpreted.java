package org.mathpiper.mpreduce.functions.lisp;


//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
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


// If a symbol has an interpreted definition its
// associated function is this job, which knows how to
// extract the saved definition and activate it.

import org.mathpiper.mpreduce.Environment;
import org.mathpiper.mpreduce.LispObject;
import org.mathpiper.mpreduce.functions.builtin.Fns;

import org.mathpiper.mpreduce.datatypes.Cons;
import org.mathpiper.mpreduce.Jlisp;
import org.mathpiper.mpreduce.LispReader;
import org.mathpiper.mpreduce.Lit;
import org.mathpiper.mpreduce.exceptions.ResourceException;

public class Interpreted extends LispFunction
{
    public LispObject body;

    public void iprint() throws ResourceException
    {
        body.iprint();	
    }
    
    public void blankprint() throws ResourceException
    {
        body.blankprint();	
    }
    
    public Interpreted()
    {
    }
    
    public Interpreted(LispObject def) throws ResourceException
    {
        body = new Cons(Jlisp.lit[Lit.lambda], def);
    }
    
    public void scan()
    {
        if (LispReader.objects.contains(this)) // seen before?
	{   if (!LispReader.repeatedObjects.containsKey(this))
	    {   LispReader.repeatedObjects.put(
	            this,
	            Environment.nil); // value is junk at this stage
	    }
	}
	else 
	{   LispReader.objects.add(this);
            LispReader.stack.push(body);
        }
    }
    

    

// All interpreted function calls check that the number of arguments
// actually passed agrees with the number expected. Shallow binding is
// used for all variables.

    public LispObject op0() throws Exception
    {
        return Fns.applyInner(body, 0);
    }

    public LispObject op1(LispObject arg1) throws Exception
    {
        Fns.args[0] = arg1;
        return Fns.applyInner(body, 1);
    }

    public LispObject op2(LispObject arg1, LispObject arg2) throws Exception
    {
        Fns.args[0] = arg1;
        Fns.args[1] = arg2;
        return Fns.applyInner(body, 2);
    }

    public LispObject opn(LispObject [] actual) throws Exception
    {
        int n = actual.length;
        for (int i=0; i<n; i++) Fns.args[i] = actual[i];
        return Fns.applyInner(body, n);
    }
}

// End of Interpreted.java
