f :=
a**16 + 8*a**14*b**2 + 10*a**14 + 28*a**12*b**4 + 52*a**12*b**2 + 55*a**12 + 56*
a**10*b**6 + 102*a**10*b**4 - 48*a**10*b**2 + 160*a**10 + 70*a**8*b**8 + 80*a**8
*b**6 - 66*a**8*b**4 - 172*a**8*b**2 + 277*a**8 + 56*a**6*b**10 - 10*a**6*b**8 +
 236*a**6*b**6 - 614*a**6*b**4 + 172*a**6*b**2 + 160*a**6 + 28*a**4*b**12 - 60*a
**4*b**10 + 231*a**4*b**8 - 236*a**4*b**6 - 66*a**4*b**4 + 48*a**4*b**2 + 55*a**
4 + 8*a**2*b**14 - 38*a**2*b**12 + 60*a**2*b**10 - 10*a**2*b**8 - 80*a**2*b**6 +
 102*a**2*b**4 - 52*a**2*b**2 + 10*a**2 + b**16 - 8*b**14 + 28*b**12 - 56*b**10
+ 70*b**8 - 56*b**6 + 28*b**4 - 8*b**2 + 1$

g :=
a**6 + 3*a**4*b**2 - 3*a**4 + 3*a**2*b**4 + 21*a**2*b**2 + 3*a**2 + b**6 - 3*b**
4 + 3*b**2 - 1$

hu := fastresultant(f, g, a);

f :=
v**12*a**8*b**2 - v**12*a**8 + 4*v**12*a**6*b**4 - 7*v**12*a**6*b**2 + 3*v**12*a
**6 + 6*v**12*a**4*b**6 - 15*v**12*a**4*b**4 + 12*v**12*a**4*b**2 - 3*v**12*a**4
 + 4*v**12*a**2*b**8 - 13*v**12*a**2*b**6 + 15*v**12*a**2*b**4 - 7*v**12*a**2*b
**2 + v**12*a**2 + v**12*b**10 - 4*v**12*b**8 + 6*v**12*b**6 - 4*v**12*b**4 + v
**12*b**2 + 4*v**10*a**8*b**2 - 6*v**10*a**8 + 8*v**10*a**6*b**4 - 28*v**10*a**6
*b**2 + 18*v**10*a**6 - 30*v**10*a**4*b**4 + 48*v**10*a**4*b**2 - 18*v**10*a**4
- 8*v**10*a**2*b**8 + 30*v**10*a**2*b**4 - 28*v**10*a**2*b**2 + 6*v**10*a**2 - 4
*v**10*b**10 + 8*v**10*b**8 - 8*v**10*b**4 + 4*v**10*b**2 + 6*v**8*a**8*b**2 -
15*v**8*a**8 + 8*v**8*a**6*b**4 - 45*v**8*a**6*b**2 + 45*v**8*a**6 + 4*v**8*a**4
*b**6 + 3*v**8*a**4*b**4 + 51*v**8*a**4*b**2 - 45*v**8*a**4 + 8*v**8*a**2*b**8 +
 25*v**8*a**2*b**6 - 3*v**8*a**2*b**4 - 45*v**8*a**2*b**2 + 15*v**8*a**2 + 6*v**
8*b**10 - 8*v**8*b**8 + 4*v**8*b**6 - 8*v**8*b**4 + 6*v**8*b**2 + 4*v**6*a**8*b
**2 - 20*v**6*a**8 + 8*v**6*a**6*b**4 - 40*v**6*a**6*b**2 + 60*v**6*a**6 + 36*v
**6*a**4*b**4 - 36*v**6*a**4*b**2 - 60*v**6*a**4 - 8*v**6*a**2*b**8 - 36*v**6*a
**2*b**4 - 40*v**6*a**2*b**2 + 20*v**6*a**2 - 4*v**6*b**10 + 8*v**6*b**8 - 8*v**
6*b**4 + 4*v**6*b**2 + v**4*a**8*b**2 - 15*v**4*a**8 + 4*v**4*a**6*b**4 - 25*v**
4*a**6*b**2 + 45*v**4*a**6 + 6*v**4*a**4*b**6 + 15*v**4*a**4*b**4 - 114*v**4*a**
4*b**2 - 45*v**4*a**4 + 4*v**4*a**2*b**8 + 21*v**4*a**2*b**6 - 15*v**4*a**2*b**4
 - 25*v**4*a**2*b**2 + 15*v**4*a**2 + v**4*b**10 - 4*v**4*b**8 + 6*v**4*b**6 - 4
*v**4*b**4 + v**4*b**2 - 6*v**2*a**8 - 12*v**2*a**6*b**2 + 18*v**2*a**6 - 6*v**2
*a**4*b**4 - 84*v**2*a**4*b**2 - 18*v**2*a**4 + 6*v**2*a**2*b**4 - 12*v**2*a**2*
b**2 + 6*v**2*a**2 - a**8 - 3*a**6*b**2 + 3*a**6 - 3*a**4*b**4 - 21*a**4*b**2 -
3*a**4 - a**2*b**6 + 3*a**2*b**4 - 3*a**2*b**2 + a**2$

g := df(f, v)$

hu := fastresultant(f, g, v);

lisp;

form := reval '(expt (plus x (times 7 y)) 5);

off nat;

s := ioto_smaprin form;

form := ioto_sxread s;

on nat;

s := ioto_smaprin form;

prin2t s$

linelength 40;

s := ioto_smaprin form;

prin2t s$

end; % of file
