// redcuba.c                             Copyright 2014 Kostas N. Oikonomou

// A C-coded library that can be accessed using the CSL-Reduce foreign
// function interface and that passes requests to the Cuba numerical
// integration library. Note that Cuba is subject to LGPL 3 and so
// while this code is unencumbered, any binary created from it that is
// linked with Cuba may be subject to LGPL 3, and so proper care should
// be taken in any binary distribution. The rules there come from LGPL3
// and details can be found in the Cuba source tree not directly here.
// 



/**************************************************************************
 * Copyright (C) 2014.                             Kostas N. Oikonomou    *
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



// Functions called using the Reduce Foreign Function Interface must be
// defined with exactly the type signature that is used at the Reduce end.
// The only pointer type there is for string - all other pointers will
// be transmitted as an int64_t (even on a 32-bit machine where the top
// 32 bits will be irrelevant).  Hence, for 32-bit support we need casts here.
// The cast from integer to pointer goes via intptr_t to get the width correct.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <cuba.h>
#include <assert.h>
// The "procedural" interface from C to Reduce/CSL.
#include "C_call_CSL.h"


// activate by setting to 1 or 2
int DEBUG = 0;

// These static variables serve as storage that allows us to eliminate some
// of the arguments that would otherwise need to be passed from Reduce to C
// functions via the foreign interface which can handle at most 3 arguments.
// The selected algorithm:
static char *alg_name;
// The name (string) of the Reduce algebraic procedure computing the integrand:
static char *intg_name;
// The results returned by cuba_int(...)
static double result[6];


// We set all parameters to the values used in demo/demo-c.c in the Cuba
// distribution tree.

// Common parameters
static int32_t vegas_flags, suave_flags, divonne_flags, cuhre_flags = 0;

static int ndim, // Dimension of integrand
  ncomp = 1,     // In general, the integrand can be a vector fn.
                 // Here it's scalar.
  nvec  = 1,     // 1 unless SIMD is used, see manual
  seed  = 0,     // Use Sobol random number generator, see manual
  mineval = 0, maxeval = 50000;
static double epsrel = 1e-3, epsabs = 1e-12;
static char *statefile;
// Vegas-specific
static int nstart = 1000, nincrease = 500, nbatch = 1000, gridno = 0;
// Suave-specific
static int nnew = 1000;
static int nmin = 2;
static double flatness = 25.0;
// Divonne-specific:
static int key1 = 47, key2 = 1, key3 = 1;
static int maxpass = 5;
static double border = 0.0, maxchisq = 10.0, mindeviation = 0.25;
static int ngiven = 0, ldxgiven = 0;
static int nextra = 0;
// Cuhre-specific
static int key = 0;

// The "userdata" structure
typedef struct {
  char   *iname;      // name (string) of Reduce function implementing 
                      // the integrand
  double *lbounds;    // array of lower bounds
  double *ubounds;    // array of upper bounds
} userdata;


// =======================================================================
// Setting parameters
// =======================================================================

// Applicable to all algorithms

void cuba_set_flags_bit(char* alg, int32_t i) {
  if (i < 0 || i > 31) return;
  if (strcmp(alg,"Vegas") == 0)
    vegas_flags = (vegas_flags | 1 << i);
  else if (strcmp(alg,"Suave") == 0)
    suave_flags = (suave_flags | 1 << i);
  else if (strcmp(alg,"Divonne") == 0)
    divonne_flags = (divonne_flags | 1 << i);
  else if (strcmp(alg,"Cuhre") == 0)
    cuhre_flags = (cuhre_flags | 1 << i);
  else
    fprintf(stderr, "Unknown algorithm!\n");
}

void cuba_clear_flags_bit(char* alg, int32_t i) {
  if (i < 0 || i > 31) return;
  if (strcmp(alg,"Vegas") == 0)
    vegas_flags = (vegas_flags & ~(1 << i));
  else if (strcmp(alg,"Suave") == 0)
    suave_flags = (suave_flags & ~(1 << i));
  else if (strcmp(alg,"Divonne") == 0)
    divonne_flags = (divonne_flags & ~(1 << i));
  else if (strcmp(alg,"Cuhre") == 0)
    cuhre_flags = (cuhre_flags & ~(1 << i));
  else
    fprintf(stderr, "Unknown algorithm!\n");
}


void cuba_verbosity(int32_t v) {
  // Level 0 does not print any output, level 1 prints reasonable information
  // on the progress of the integration, level 2 also echoes the input 
  // parameters, and level 3 further prints the subregion results, if applicable.
  if (0 <= v && v <= 3) {
    vegas_flags   = (vegas_flags | v);
    suave_flags   = (suave_flags | v);
    divonne_flags = (divonne_flags | v);
    cuhre_flags   = (cuhre_flags | v);
  }
}


void cuba_gen_par(char *pname, const double val) {
  if (strcmp(pname,"ndim") == 0)
    ndim = (int) val;
  else if (strcmp(pname,"ncomp") == 0)
    fprintf(stderr, "Only the default ncomp=1 is supported at present!\n");
  else if (strcmp(pname,"nvec") == 0)
    fprintf(stderr, "Only the default nvec=1 is supported at present!\n");
  else if (strcmp(pname,"seed") == 0)
    seed = (int) val;
  else if (strcmp(pname,"mineval") == 0)
    mineval = (int) val;
  else if (strcmp(pname,"maxeval") == 0)
    maxeval = (int) val;
  else if (strcmp(pname,"epsrel") == 0)
    epsrel = val; 
  else if (strcmp(pname,"epsabs") == 0)
    epsabs = val;
  else
    fprintf(stderr, "Unknown parameter!\n");
}

void cuba_statefile(char *fname) {
  statefile = malloc(strlen(fname)*sizeof(char)+1);
  assert(statefile != NULL);
  strcpy(statefile,fname);
};


void set_alg(char *name) {
  alg_name = malloc(strlen(name)*sizeof(char)+1);
  assert(alg_name != NULL);
  strcpy(alg_name,name);
}

void set_integrand(char *name) {
  intg_name = malloc(strlen(name)*sizeof(char)+1);
  assert(intg_name != NULL);
  strcpy(intg_name,name);
}


// Vegas-specific
void cuba_vegas_par(char *pname, const int val) {
  if (strcmp(pname,"nstart") == 0)
    nstart = val;
  else if (strcmp(pname,"nincrease") == 0)
    nincrease = val;
  else if (strcmp(pname,"nbatch") == 0)
    nbatch = val;
  else if (strcmp(pname,"gridno") == 0)
    gridno = val;
  else
    fprintf(stderr, "Unknown Vegas parameter!\n");
}

// Suave-specific
void cuba_suave_par(char *pname, const double val) {
  if (strcmp(pname,"nnew") == 0)
    nnew = (int) val;
  if (strcmp(pname,"nmin") == 0)
    nmin = (int) val;
  else if (strcmp(pname,"flatness") == 0)
    flatness = val;
  else
    fprintf(stderr, "Unknown Suave parameter!\n");
}

// Divonne-specific
void cuba_divonne_par(char *pname, const double val) {
  fprintf(stderr, "Not implemented yet!\n");
  //  fprintf(stderr, "Unknown parameter!\n");
}

// Cuhre-specific
void cuba_cuhre_par(char *pname, const int val) {
  if (strcmp(pname,"key") == 0) {
    key = val;
  }
  else
    fprintf(stderr, "Unknown Cuhre parameter!\n");
}


// ===========================================================================
// Functions *internal* to the interface for dealing with arrays of doubles
// To understand what's going on see the comments in nlopt_set_lower_bounds()
// in nlopt.red.
// ===========================================================================
int64_t newDoubleArray(int32_t len) {
  double *a;
  a = (double *) malloc(len*sizeof(double));
  assert(a != NULL);
  return (int64_t)(intptr_t)a;
}
void setDoubleArray(int64_t a, int32_t i, double x) {
  ((double *)(intptr_t)a)[i] = x;
}
void freeDoubleArray(int64_t a) {
  free((void *)(intptr_t)a);
}
// This internal function turns a C array of doubles into a Lisp list and 
// leaves it at the top of the stack.  The "stack" is used by the "procedural"
// interface to Reduce, see file "C_call_CSL.h".
void C_darray_to_Lisp_list(int32_t n, const double x[]) {
  // Push the x[i] on the stack.
  int i;
  for (i = 0; i < n; i++) PROC_push_floating(x[i]);
  // Make a list out of the x[i]; it is left at the top of the stack.
  PROC_make_function_call("list", n);
  // Now having put the 'list on the front, get rid of it.
  // This perhaps shows that that ACN should really extend the procedural
  // interface to make this slightly nicer. But with luck this will suffice
  // for now.
  PROC_lisp_eval();
}



// ===============================================================================
// Wrapper function, internal to the interface (static).
// Given a point x in the ndim-dimensional unit hypercube, the integrand 
// function receives a transformed ndim-dimensional point y, and returns
// the value of the integrand in element 0 of the array f.
// (This assumes that ncomp 1. The present interface doesn't allow changing 
// ncomp from 1.)
// The Lisp code is highly non-trivial!
// ================================================================================

static int cuba_integrand(const int *nd, const double *x, const int *ncomp, 
			  double *f, void *udata) {
  userdata *ud = (userdata *) udata;
  char *red_integrand = ud->iname;
  double *lbounds = ud->lbounds;
  double *ubounds = ud->ubounds;
  double c = 1.0;
  // y is a linear transformation of x, x being a point in the unit hypercube:
  double y[*nd];
  int i;
  for (i = 0; i < *nd; i++) {
    y[i] = lbounds[i] + (ubounds[i] - lbounds[i])*x[i];
    c = c * (ubounds[i] - lbounds[i]);
  }
  // Convert the string to a symbol, push it on the stack, and wrap it in
  // a call to quote:
  PROC_push_symbol(red_integrand);
  PROC_make_function_call("quote", 1);
  // Turn the array y into a Lisp list and leave it at the top of the "stack":
  C_darray_to_Lisp_list(*nd,y);
  // Wrap it in quote:
  PROC_make_function_call("quote", 1);
  if (DEBUG > 1)
     fprintf(stderr, "cuba_integrand: calling '%s'\n", red_integrand);
  // Evaluate a Reduce call to a function that takes a list of reals
  // and returns another list of reals.
  // What is on the stack at the start is something like
  //   (call_alg_fn_list2list 'red_integrand '(1.111 2.222 3.333)),
  // which is Lisp-speak for a call to the function, where the uses of quote
  // ensure that both arguments are treated as data, not as further code. This
  // is evaluated by lisp_eval, which will cause call_alg_fn_list2list to be
  // invoked with 2 arguments, one being the symbol red_integrand and the
  // other the list (1.111 2.222 3.333).  Note that when I say "list" here
  // I mean a Lisp data structure not a Reduce algebraic-mode list.
  int32_t r = PROC_make_function_call("call_alg_fn_list2list", 2);
  PROC_lisp_eval();
  f[0] = c * PROC_floating_value(PROC_get_value());
  if (DEBUG > 1) {
    int i;
    fprintf(stderr, "  x = ");
    for (i=0; i<ndim; i++) fprintf(stderr, "%.6g ", x[i]);
    fprintf(stderr, "\n");
    fprintf(stderr, "  y = ");
    for (i=0; i<ndim; i++) fprintf(stderr, "%.6g ", y[i]);
    fprintf(stderr, "\n");
    fprintf(stderr, "  c = %.6g\n", c);
    fprintf(stderr, "  f = %.8g\n", f[0]);
  }
  return 0;
}


// =======================================================================
// Single interface to the algorithms, like the Fortran Cuba.F
// =======================================================================

void cuba_int(int64_t lbounds, int64_t ubounds) {
  // Note that the CSL foreign function interface supports passing 32 or
  // 64-bit integers but it does not have a separate logical type corresponding
  // to intptr_t and it does not have a type for "void *". So when a pointer
  // is to be passed it will be transmitted as an int64_t and on receipt if you
  // are on a 32-bit machine it will need narrowing to 32-bits before use.
  double integral[ncomp], error[ncomp], prob[ncomp];
  int nregions, neval, fail;
  userdata *ud = malloc(sizeof(userdata));
  assert(ud != NULL);
  ud->iname = intg_name;
  ud->lbounds = (double *)(intptr_t)lbounds;
  ud->ubounds = (double *)(intptr_t)ubounds;
  if (strcmp(alg_name,"Vegas") == 0) {
    if (maxeval < nstart) {
      fprintf(stderr, "Vegas: must have maxeval > nstart!\n");
      result[5] = -2.0;
      return;
    };
    Vegas(ndim, ncomp,
	  cuba_integrand, ud, 
	  nvec, epsrel, epsabs,
	  vegas_flags, seed,
	  mineval, maxeval, 
	  nstart, nincrease, nbatch,
	  gridno, statefile, NULL,
	  &neval, &fail, 
	  integral, error, prob
	  );
    nregions = 1;
  }
  else if (strcmp(alg_name,"Suave") == 0) {
    if (flatness == 0) {
      fprintf(stderr, "Suave: flatness can't be 0!\n");
      result[5] = -2.0;
      return;
    }
    Suave(ndim, ncomp,
	  cuba_integrand, ud,
	  nvec, epsrel, epsabs,
	  suave_flags, seed,
	  mineval, maxeval,
	  nnew, nmin, flatness,
	  statefile, NULL,
	  &nregions, &neval, &fail,
	  integral, error, prob
	  );
  }
  else if (strcmp(alg_name,"Divonne") == 0) {
    if (ldxgiven == 0) ldxgiven = ndim;
    Divonne(ndim, ncomp,
	    cuba_integrand, ud,
	    nvec, epsrel, epsabs, 
	    divonne_flags, seed,
	    mineval, maxeval,
	    key1, key2, key3,
	    maxpass, border, maxchisq, mindeviation,
	    ngiven, ldxgiven, NULL, nextra, NULL,
	    statefile, NULL,
	    &nregions, &neval, &fail,
	    integral, error, prob);
  }
  else if (strcmp(alg_name,"Cuhre") == 0) {
    Cuhre(ndim, ncomp,
	  cuba_integrand, ud,
	  nvec, epsrel, epsabs,
	  cuhre_flags, 
	  mineval, maxeval, 
	  key,
	  statefile, NULL,
	  &nregions, &neval, &fail,
	  integral, error, prob
	  );
  }
  else {
     // Should never happen
  }
  free(ud);
  if (DEBUG > 0) {
    printf("%s: %d\n", alg_name, fail);
    printf("  nregions=%d, neval=%d\n", nregions, neval);
    // can't handle comp > 1.
    printf("  %.8f +- %.8f @ p = %.3f\n", integral[0], error[0], prob[0]);
  };
  // value, error, prob, num regions, num eval, return code
  result[0] = integral[0];   // can't handle comp > 1
  result[1] = error[0];   result[2] = prob[0];
  result[3] = (double) nregions;   result[4] = (double) neval;
  result[5] = (double) fail;
  return;
}


double get_result(int32_t i) {
  return result[i];
}
