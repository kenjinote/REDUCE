/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   Copyright (c) 2008-2009 Thomas Sturm
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <reduce.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define REDUCE to the absolute path of your reduce binary
//                here this is done in the Makefile

int main(int argc,char **argv,char **envp) {
  char input[4096];
  RedProc process;
  RedAns output;

  process = RedProc_new(REDUCE);

  fprintf(stderr,"lrtest: after initialization\n");
  fflush(stderr);

  while (1) {
    printf("Input:  ");
    gets(input);
    if (strcmp(input,"simsalabim") == 0)
      break;
    output = RedAns_new(process,input);
    if (output->error)
      RedProc_error(process,input,output);
    printf("Output: %s\n",output->result);
    RedAns_delete(output);
  }
  RedProc_delete(process);

  fprintf(stderr,"lrtest: sleeping 1 sec to verify signal handling\n");
  fflush(stderr);

  sleep(1);

  fprintf(stderr,"lrtest: exiting normally\n");
  fflush(stderr);

  exit(0);
}
