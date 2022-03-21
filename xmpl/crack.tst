off echo;
%*******************************************************************%
%                                                                   %
%                       C R A C K . T S T                           %
%                       -----------------                           %
%  crack.tst contains test examples for the program crack.red.      %
%                                                                   %
%  Author of this file: Thomas Wolf                                 %
%  Date:  11. Sep 1998, 6. May 2003                                 %
%                                                                   %
%  Details about the syntax of crack.red are given in crack.tex.    %
%                                                                   %
%  To run this demo you need to load crack through:                 %
%     load crack$                                                   %
%  and to read in this file as                                      %
%     in "crack.tst";                                               %
%  If you got the source code of a newer version of crack then      %
%  either read it in through                                        %
%     in "crack.red"$                                               %
%  (with the appropriate directory name in front of crack.red)      %
%  or, to speed up the calculation, you compile before with         %
%     faslout "crack"$                                              %
%     in "crack.red"$                                               %
%     faslend$                                                      %
%  and then load it with                                            %
%     load crack$                                                   %
%                                                                   %
%*******************************************************************%

lisp(depl!*:=nil)$           % clearing of all dependencies
lisp(print_:=nil)$           % to suppress printing the computation
lisp(initial_proc_list_ :=   % initial_proc_list_ is saved for an 
     proc_list_)$            % application at the end
on dfprint$                  % to print partial deriv. as indices
COMMENT 
-------------------------------------------------------

                     Modules in CRACK 

The following examples illustrate the operation of various
modules of CRACK. These examples are not typical applications
but are chosen to demonstrate individual CRACK modules. 
To see typical applications of CRACK run LIEPDE.TST,
CONLAW.TST or APPLYSYM.TST instead.

The extra assignments in this run that involve proc_list_ 
are to disable all other modules and to demonstrate better 
the action of the individual module. 

-------------------------------------------------------

             Format of the return of CRACK

CRACK returns a list {sol_1,...} of one or more solutions
where each solution is a list:
{ list_of_remaining_unsolved_equations,
  list_of_computed_values_of_functions_or_constants,
  list_of_free_functions_or_constants,
  list_of_inequalities_valid_for_this_solution }
Empty lists are {}.

============================================================;

write"        Integration: Integrating exact PDEs "$COMMENT

An important part of CRACK are integration routines 
which  employ a number of different techniques which 
are demonstrated next. At first an example for the
integration of exact PDE;

depend f,x,y$
depend g,x$

de:=2*df(f,y)*df(g,x) + 2*df(f,x,y)*g + g*df(g,x)**3 + 
    x*df(g,x)**4 + 3*x*g*df(g,x)**2*df(g,x,2);

lisp(proc_list_ := '(to_do integration))$

crack({de},{},{f,g},{});

fdep third first ws$

write"======================================================="$

write"  Integration: Integration of an exact PDE + terms "$
write"               which are not exact (are not a total "$
write"               derivative) but which only involve "$
write"               unknown functions of fewer variables"$ COMMENT

The price of integrating non-exact expressions will be 
the introduction of extra conditions but in fewer variables 
than the integrated PDE has. A special algorithm minimizes
the number of new functions of fewer variables to be   
introduced. The bracket below is a polynomial in the   
integration variable x, as a consequence the algorithm 
is applicable such that only one extra function has to be 
introduced. $

de:=de + g^2*(y^2 + x*sin y + x^2*exp y);

crack({de},{},{f,g},{});

fdep third first ws$
nodependlist {f,g}$

write"======================================================="$

write"          Integration: Integrating Factors"$ COMMENT

Heuristics for the determination of integrating factors
in CRACK are not rigorous but often useful. $

depend f,x,y$

g:=df(f,x)/e**x+df(f,y)/x**2$
de:=num(df(g,x));
crack({de},{},{f},{});
fdep third first ws$

clear g,de$
nodependlist {f}$

write"======================================================="$

write"     Integration: Recognizing a 2-dim divergence"$ COMMENT

Being able to recognize a structure 0=df(a,x)+df(b,y)
where a,b are differential expressions is of benefit
if a,b can both be solved for a unknown function as
in the following example. $

lisp(proc_list_ := '(to_do subst_level_4 integration))$

depend f,x,y$
depend g,x,y$
depend h,x,y$

a:=x*f+y*df(g,y)$
b:=df(g,x,y)*sin(x)+h/y$
de:=df(a,x)+df(b,y);

crack({de},{},{f,g,h},{});

fdep third first ws$
nodependlist {f,g,h}$
clear a,b,de$

write"======================================================="$

write"      Integration: Solving ODEs for partial derivatives"$ COMMENT

In CRACK ODEs and PDEs which are ODEs for a single partial
derivative are investigated by the program ODESOLVE by
MacCallum/Wright. In the following example this technique
together with a previous one are successful. $

depend f,x,y$
lisp(proc_list_ := '(to_do subst_level_4 integration))$

de:=x**2*df(f,x,2,y)-2*x*df(f,x,y)-df(f,y)+x**3/y**2;
crack({de},{},{f},{});

fdep third first ws$
nodependlist {f}$
clear de$

write"======================================================="$

write"       Separation: Direct separation of PDEs"$ COMMENT

Another important group of modules concerns separations.
In this example z is an extra independent variable on which
f and g do not depend (therefore z is in the 4th argument 
to crack). There is furthermore a function h=h(z) which
is assumed to be given and is not to be calculated as it
is not element of the third argument to CRACK, i.e. the 
question is to find expressions for f,g for arbitrary h. 
In the computation below, h is treated as being linear 
independent from z because h is declared as arbitrary. 
If h would be added to the list {f,g} then h would have 
to be computed and direct separation would not be possible 
but only indirect separation (see next example). $

depend f,x$
depend g,y$
depend h,z$
fdep {f,g,h}$
de:=z*f + h*y*g;
lisp(proc_list_ := '(to_do subst_level_4 separation))$
crack({de},{},{f,g},{z});
nodependlist {f,g,h}$
write"======================================================="$

write"       Separation: Indirect separation of PDEs"$
write"                   (combined with integration)"$ COMMENT

This example is the same as before, only now h is not assumed
to be given but to be calculated. In this example there is no 
variable turning up only explicitly to allow a direct separation. 
But there is also no function which depends on all variables 
and this allows the use of an indirect separation method. This 
example also demonstrates factorization and the splitting 
into subcases to do substitutions in non-linear problems.  
Three solutions result, 
1. f=h=0, g arbitrary, 
2. f,g,h given in terms of two constants, both non-vanishing
3. f=g=0, h arbitrary, h non-vanishing. $

depend f,y$
depend g,x$
depend h,z$
fdep {f,g,h}$
de:=z*f + h*y*g;
lisp(proc_list_ := '(to_do subst_level_3 separation 
                     factorize_any gen_separation))$
de:=crack({de},{},{f,g,h},{});
de;

fdep append(third first ws,third second ws,third third ws)$
nodependlist {f,g,h}$

write"======================================================="$

write"    Combination: Pseudo Differential Groebner Basis"$ COMMENT

Another group of modules tries to take advantage of 
combining equations or their derivatives. The main tool
in this respect computes a Pseudo Differential Groebner
Basis. In interactive mode (off batch_mode) it is possible
to choose between different orderings of derivatives which
is not demonstrated here. (The origin of the following 
example is described at the end of this file.) ;

depend xi ,x,y$
depend eta,x,y$
lisp(proc_list_ := '(to_do separation decoupling))$ 

de:=2*df(eta,x,y)*x**5*y1
       + df(eta,x,2)*x**5 - df(eta,x)*x**4 
       - 2*df(eta,x)*x**2*y + df(eta,y,2)*x**5*y1**2 
       - 4*df(eta,y)*x*y**2 - 2*df(xi,x,y)*x**5*y1**2
       - df(xi,x,2)*x**5*y1 - df(xi,x)*x**4*y1
       - 2*df(xi,x)*x**2*y*y1 
       + 8*df(xi,x)*x*y**2 - df(xi,y,2)*x**5*y1**3 
       - 2*df(xi,y)*x**4*y1**2 - 4*df(xi,y)*x**2*y*y1**2 
       + 12*df(xi,y)*x*y**2*y1 - 2*eta*x**2*y1 + 8*eta*x*y 
       + x**3*xi*y1 + 6*x*xi*y*y1 - 16*xi*y**2;
crack({de},{},{eta,xi},{x,y,y1});

nodependlist {xi,eta}$
clear de$

write"======================================================="$

write"      Combination: Shortening linear PDE systems"$ COMMENT

To reduce memory requirements now and for further
computations with a system of equations it is advisable
to find length reducing linear combinations. The shorther
equations become, the more useful they are to shorten
other equations and the more likely they are integrable.;

depend f,x,y$
de1:=sin(x)*y+7*x+3*df(f,x);
de2:=de1 * (3*x*y**2+sin(x)*y-4) + df(f,y)*y+f*x+x*y**2;
lisp(proc_list_ := '(to_do alg_length_reduction))$
crack({de1,de2},{},{f},{});
clear de1,de2$
nodependlist {f}$
write"======================================================="$

write"  Parametric solution of linear underdetermined ODEs"$ COMMENT

The following example demonstrates an algorithm for the
parametric solution of underdetermined linear ODEs with
arbitrary non-constant cefficients. The rule trig1_ is
defined in crinit.red in procedure ini_let_rules().
It makse sin^2 --> 1-cos**2 .$

depend f,x$
depend g,x$
de:=cos(x)*df(f,x,2) - df(g,x,2);
lisp(proc_list_ := '(to_do subst_level_4 undetlinode))$
let trig1_$
crack({de},{},{f,g},{});
fdep third first ws$
clearrules trig1_$

nodependlist {f,g}$

write"======================================================="$

write" Application: Investigating point symmetries of an ODE"$ COMMENT

Finally a  small real life example that demonstrates
the interplay of different modules to solve completely
an overdetermined system which is generated when  
investigating the point symmetries of the ODE 6.97
in Kamke's book using the following CRACK input:  $

% depend y,x$
% load_package crack,liepde$
% liepde({{df(y,x,2)*x**4-df(y,x)*(2*x*y+x**3)+4*y**2},{y},{x}},
%        {"point"},{})$ 

COMMENT 
(and renaming xi_x --> xi, eta_y --> eta, y!`1 --> y1
which is only done to ease reading). Instead of just 
doing this liepde-call which would take care of 
everything, we call crack below explicitly for 
demonstration. Two arbitrary constants in the solution 
stand for two symmetries. $

depend xi ,x,y$
depend eta,x,y$
lisp(proc_list_ := initial_proc_list_)$   % this was saved at the start

de:=2*df(eta,x,y)*x**5*y1
       + df(eta,x,2)*x**5 - df(eta,x)*x**4 
       - 2*df(eta,x)*x**2*y + df(eta,y,2)*x**5*y1**2 
       - 4*df(eta,y)*x*y**2 - 2*df(xi,x,y)*x**5*y1**2
       - df(xi,x,2)*x**5*y1 - df(xi,x)*x**4*y1
       - 2*df(xi,x)*x**2*y*y1 
       + 8*df(xi,x)*x*y**2 - df(xi,y,2)*x**5*y1**3 
       - 2*df(xi,y)*x**4*y1**2 - 4*df(xi,y)*x**2*y*y1**2 
       + 12*df(xi,y)*x*y**2*y1 - 2*eta*x**2*y1 + 8*eta*x*y 
       + x**3*xi*y1 + 6*x*xi*y*y1 - 16*xi*y**2;

crack({de},{},{xi,eta},{x,y,y1});

fdep third first ws$
nodependlist {xi,eta}$

write"======================================================="$

write"  Integration: Solving a linear 1st order PDE"$ COMMENT

If the computation of a differential Groebner Basis is getting
bigger and bigger and normal integration is not successful and
also no functions of fewer variables are present then trying
the solution of a 1st order linear PDE is recommended. $

lisp(proc_list_ := '(to_do subst_level_4 full_integration 
                     gen_separation find_trafo))$
depend f,x,y$

de:=df(f,x)-x*y*df(f,y)+x;

crack({de},{},{f},{});

fdep third first ws$
write "The list of transformations done (here only one): ",
      lisp done_trafo;

nodependlist {f}$
clear de$

write"======================================================="$

write"  Integration: Integration enabled through a syzygy"$COMMENT

A side product of a differential Groebner basis computation
is the computation of syzygies, i.e. identities between
differential equations. In
Wolf, T.: "The integration of systems of linear PDEs using conservation
laws of syzygies", J. Symb. Comp. 35, no 5 (2003), 499-526
and arXiv: cs.SC/0301028
it is shown how the knowledge of syzygies of a linear PDE system
can be used to integrate two equations at once;

depend f,x,y,z$
a:=z**2*df(f,x,y)+x*sin(y)*df(f,y)-3*f+x**2*z$
de:={df(a,x),df(a,y)};

lisp(proc_list_ := '(to_do del_redundant_de idty_integration decoupling))$  
lisp(record_hist:=t)$

crack(de,{},{f},{});
fdep third first ws$
nodependlist {f}$

write"======================================================="$

lisp(depl!*:=nil)$ % to delete all dependencies of functions on variables

end$
