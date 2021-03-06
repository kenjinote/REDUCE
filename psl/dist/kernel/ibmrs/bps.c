/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         bps.c
% Description:  Declare bps space as a static array.
% Author:       Leigh Stoller
% Created:      18-Dec-86
% Package:      
%
% (c) Copyright 1986, University of Utah.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

/* The ukernel model had the problem that bps came after the data segment
   of the ukernel. This meant that unexec could not move the text/data
   boundary over code in bps, since it would write-protect the data segment,
   making it very difficult to change ukernel variables. This file is
   now inserted between main.s and dmain.s, making it possible to extend
   text boundry. See setupbps() in bpsheap.c for more info.
 */

#ifndef BPSSIZE
#define BPSSIZE 800000  /* Minimum size in bytes */
#endif

/*char bps[BPSSIZE] = {0}; */

char bps[BPSSIZE];
