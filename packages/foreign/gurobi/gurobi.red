module gurobi;

revision('gurobi, "$Id: gurobi.red 5787 2021-05-11 11:53:47Z arthurcnorman $");

copyright('gurobi, "(c) 2013-2017 T. Sturm");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

#if (memq 'csl lispsystem!*)

fluid '(gurobi_libredgurobi!*);
fluid '(gurobi_redgrb!*);
fluid '(gurobi_newmodel!*);
fluid '(gurobi_addconstr!*);
fluid '(gurobi_addconstrfast!*);
fluid '(gurobi_numvars!*);
fluid '(gurobi_delconstr1!*);
fluid '(gurobi_delconstr!*);
fluid '(gurobi_negconstr1!*);
fluid '(gurobi_negconstr!*);
fluid '(gurobi_updatemodel!*);
fluid '(gurobi_write!*);
fluid '(gurobi_newdoublearray!*);
fluid '(gurobi_setdoublearray!*);
fluid '(gurobi_freedoublearray!*);
fluid '(gurobi_pushtoval!*);
fluid '(gurobi_optimize!*);
fluid '(gurobi_getsol!*);
fluid '(gurobi_freemodel!*);

gurobi_libredgurobi!* := lto_sconcat {systo_trunk(), "packages/foreign/gurobi/libredgurobi.so"};

if filep gurobi_libredgurobi!* then <<
   gurobi_redgurobi!* := open!-foreign!-library gurobi_libredgurobi!*;

   gurobi_newmodel!* := find!-foreign!-function("gurobi_newmodel", gurobi_redgurobi!*);
   gurobi_addconstr!* := find!-foreign!-function("gurobi_addconstr", gurobi_redgurobi!*);
   gurobi_addconstrfast!* := find!-foreign!-function("gurobi_addconstrFast", gurobi_redgurobi!*);
   gurobi_numvars!* := find!-foreign!-function("gurobi_numVars", gurobi_redgurobi!*);
   gurobi_negconstr1!* := find!-foreign!-function("gurobi_negconstr1", gurobi_redgurobi!*);
   gurobi_negconstr!* := find!-foreign!-function("gurobi_negconstr", gurobi_redgurobi!*);
   gurobi_delconstr1!* := find!-foreign!-function("gurobi_delconstr1", gurobi_redgurobi!*);
   gurobi_delconstr!* := find!-foreign!-function("gurobi_delconstr", gurobi_redgurobi!*);
   gurobi_updatemodel!* := find!-foreign!-function("gurobi_updatemodel", gurobi_redgurobi!*);
   gurobi_write!* := find!-foreign!-function("gurobi_write", gurobi_redgurobi!*);
   gurobi_newdoublearray!* := find!-foreign!-function("gurobi_newDoubleArray", gurobi_redgurobi!*);
   gurobi_setdoublearray!* := find!-foreign!-function("gurobi_setDoubleArray", gurobi_redgurobi!*);
   gurobi_freedoublearray!* := find!-foreign!-function("gurobi_freeDoubleArray", gurobi_redgurobi!*);
   gurobi_pushtoval!* := find!-foreign!-function("gurobi_pushToVal", gurobi_redgurobi!*);
   gurobi_optimize!* := find!-foreign!-function("gurobi_optimize", gurobi_redgurobi!*);
   gurobi_getsol!* := find!-foreign!-function("gurobi_getSol", gurobi_redgurobi!*);
   gurobi_freemodel!* := find!-foreign!-function("gurobi_freemodel", gurobi_redgurobi!*)
>>;

procedure gurobi_newmodel(n, m);
   % [n] real variables plus [m] integer variables, all unbounded from below.
   call!-foreign!-function(gurobi_newmodel!*, 'int32, n, 'int32, m);

% Several of these inline procedures cause CSL to generate complaints, so I
% will explain here why the complaints are generated and hence help to
% understand the extent to which they matter.
% An inline procedure has its definition saved for insertion where it gets called.
% If the body references a non-local variable (ie fluid or global) and that
% variable is defined where the inline procedure is defined but is not defined
% or is defined in a different way (eg global rather than fluid or vice versa)
% where the function is called the result could be bad. So a minimum expectation
% for any sort of safety is that all local variables mentioned within the body
% of any inline procedure must be declared both where that function is defined
% and in EVERY place where it is used. The message "Use of free variable in
% smacro/inline body" is there to alert programmers to need for special care.
% Perhaps especially because once a function is defined inline it could be used
% from ANYWHERE in the Reduce source. If (perhaps because of violation of the
% above) some code  ends up referring to a variable that is neither bound nor
% declared (global or fluid) you get a diagnostic "xxx declared fluid" where xxx
% is the name of the variable. At present this patches things up by forcing the
% variable to have fluid status, but use of undeclared variables is not tidy and in
% a future world where fluid and global are handled differently from one another
% it could cause real pain.

% The following used all to be defined as "inline". When the inline functions
% were expanded that left a reference to the fluid variable at the point of
% call and in places the fluids had not been declated properly. Since these
% do calls external to Reduce any overhead in having these is utterly minor
% compared against use of the foreign function interface and the potential
% costs within the external package - and so I have put these back to being
% ordinary fubnctions which leave the code cleaner and safer. ACN May 2021.

procedure gurobi_newdoublearray(n);
   call!-foreign!-function(gurobi_newdoublearray!*, 'int32, n, 'int64);

procedure gurobi_setdoublearray(a, i, x);
   call!-foreign!-function(gurobi_setdoublearray!*, 'int64, a, 'int32, i, 'double, x);

procedure gurobi_freedoublearray(a);
   call!-foreign!-function(gurobi_freedoublearray!*, 'int64, a);

procedure gurobi_pushtoval(x);
   call!-foreign!-function(gurobi_pushtoval!*, 'double, x);

procedure gurobi_addconstr(relstr, val, c);
   call!-foreign!-function(gurobi_addconstr!*, 'string, relstr, 'int64, val, 'double, c);

procedure gurobi_addconstrfast(relstr, c);
   call!-foreign!-function(gurobi_addconstrfast!*, 'string, relstr, 'double, c);

procedure gurobi_numvars();
   call!-foreign!-function(gurobi_numvars!*, 'int32);

procedure gurobi_negconstr1();
   call!-foreign!-function gurobi_negconstr1!*;

procedure gurobi_negconstr(n);
   call!-foreign!-function(gurobi_negconstr!*, 'int32, n);

procedure gurobi_delconstr1();
   call!-foreign!-function gurobi_delconstr1!*;

procedure gurobi_delconstr(n);
   call!-foreign!-function(gurobi_delconstr!*, 'int32, n);

procedure gurobi_updatemodel();
   call!-foreign!-function gurobi_updatemodel!*;

procedure gurobi_write(fn);
   call!-foreign!-function(gurobi_write!*, 'string, fn);

procedure gurobi_getsol(i);
   call!-foreign!-function(gurobi_getsol!*, 'int32, i, 'double);

procedure gurobi_freemodel();
   call!-foreign!-function(gurobi_freemodel!*);

procedure gurobi_optimize();
   begin scalar w, sol;
      w := call!-foreign!-function(gurobi_optimize!*, 'string);
      w := intern compress reversip cdr reverse cdr explode w;
      if w neq 'optimal then
	 return w;
      sol := for i := 1 : gurobi_numvars() collect
	 gurobi_getsol i;
      return sol
   end;

procedure gurobi_addconstraint(rel, cl, c);
   begin scalar val, relstr; integer len;
      len := length cl;
      val := gurobi_newdoublearray len;
      for i := 0:len-1 do
	 gurobi_setdoublearray(val, i, pop cl);
      relstr := if rel eq 'equal then
 	 "="
      else if rel eq 'leq then
 	 "<"
      else if rel eq 'geq then
 	 ">"
      else
	 rederr {"illegal relation", rel};
      gurobi_addconstr(relstr, val, c);
      gurobi_freedoublearray val
   end;

procedure gurobi_addconstraintfast(rel, cl, c);
   begin scalar relstr; integer len;
      len := length cl;
      for i := 0:len-1 do
	 gurobi_pushtoval pop cl;
      relstr := if rel eq 'equal then
 	 "="
      else if rel eq 'leq then
 	 "<"
      else if rel eq 'geq then
 	 ">"
      else
	 rederr {"illegal relation", rel};
      gurobi_addconstrfast(relstr, c)
   end;

procedure gurobi_dumpmodel();
   <<
      gurobi_write("/tmp/lpdump.lp");
      system("cat /tmp/lpdump.lp");
      system("rm -f /tmp/lpdump.lp")
   >>;

#endif

endmodule;  % gurobi

end;  % of file
