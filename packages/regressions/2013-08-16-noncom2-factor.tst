%
% Bug in noncom2 package: redefinition of ordp
% Petrov Alexander, Aug 2013
%

on intstr$

load_package noncom2;


operator a,ac;
noncom a,a;
noncom ac,ac;
noncom a,ac;

for all i let a(i)*ac(i) = 1 - ac(i)*a(i);
for all i,j such that i neq j let a(i)*ac(j) = -ac(j)*a(i);
for all i,j such that ordp(i,j) let a(i)*a(j) = -a(j)*a(i);
for all i,j such that ordp(i,j) let ac(i)*ac(j) = -ac(j)*ac(i);

operator a2,a2c;
noncom a2,a2;
noncom a2c,a2c;
noncom a2,a2c;

for all i let a2(i)*a2c(i) = 1 - a2c(i)*a2(i);
for all i,j such that i neq j let a2(i)*a2c(j) = -a2c(j)*a2(i);
for all i,j such that ordp(i,j) let a2(i)*a2(j) = -a2(j)*a2(i);
for all i,j such that ordp(i,j) let a2c(i)*a2c(j) = -a2c(j)*a2c(i);


operator !H;
!H := !J1*ac(i)*a(i+1) + !J1*ac(i+1)*a(i);

operator !U,!U!T,!V,!V!T;

sub_fermi := { a(~i) => !U(i,j1)*a2(j1) + !V(i,j1)*a2c(j1),
                 ac(~i) => !V!T(i,j2)*a2(j2) + !U!T(i,j2)*a2c(j2) };
!H2 :=  (!H where sub_fermi);
on factor;
!H2;

end;
