#
#	Test file to inspect the machine code for querying the floating point
#       status of the processor as generated by the compiler.
#       Compile to a .s file and then to an executable, inspect result.
#       
##############################################################################
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the relevant copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
##############################################################################

#include <fenv.h>

int
fegetexceptflag (fexcept_t *flagp, int excepts)
{
  fexcept_t temp;
  unsigned int mxscr;

  /* Get the current exceptions for the x87 FPU and SSE unit.  */
  __asm__ ("fnstsw %0\n"
       "stmxcsr %1" : "=m" (*&temp), "=m" (*&mxscr));

  *flagp = (temp | mxscr) & FE_ALL_EXCEPT & excepts;

  /* Success.  */
  return 0;
}

int
feclearexcept (int excepts)
{
  fenv_t temp;
  unsigned int mxcsr;

  /* Mask out unsupported bits/exceptions.  */
  excepts &= FE_ALL_EXCEPT;

  /* Bah, we have to clear selected exceptions.  Since there is no
     `fldsw' instruction we have to do it the hard way.  */
  __asm__ ("fnstenv %0" : "=m" (*&temp));

  /* Clear the relevant bits.  */
  temp.__status_word &= excepts ^ FE_ALL_EXCEPT;

  /* Put the new data in effect.  */
  __asm__ ("fldenv %0" : : "m" (*&temp));

  /* And the same procedure for SSE.  */
  __asm__ ("stmxcsr %0" : "=m" (*&mxcsr));

  /* Clear the relevant bits.  */
  mxcsr &= ~excepts;

  /* And put them into effect.  */
  __asm__ ("ldmxcsr %0" : : "m" (*&mxcsr));

  /* Success.  */
  return 0;
}
