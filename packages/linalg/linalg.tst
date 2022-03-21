if lisp !*rounded then rounded_was_on := t
 else rounded_was_on := nil;

mat1  := mat((1,2,3,4,5),(2,3,4,5,6),(3,4,5,6,7),(4,5,6,7,8),(5,6,7,8,9));
mat2  := mat((1,1,1,1),(2,2,2,2),(3,3,3,3),(4,4,4,4));
mat3  := mat((x),(x),(x),(x));
mat4  := mat((3,3),(4,4),(5,5),(6,6));
mat5  := mat((1,2,1,1),(1,2,3,1),(4,5,1,2),(3,4,5,6));
mat6  := mat((i+1,i+2,i+3),(4,5,2),(1,i,0));
mat7  := mat((1,1,0),(1,3,1),(0,1,1));
mat8  := mat((1,3),(-4,3));
mat9  := mat((1,2,3,4),(9,8,7,6));
mat10 := mat((1,0,0,0,2),(0,0,3,0,0),(0,0,0,0,0),(0,2,0,0,0));
poly  := x^7+x^5+4*x^4+5*x^3+12;
poly1 := x^2+x*y^3+x*y*z^3+y*x+2+y*3;

on errcont;


% Basis matrix manipulations.

add_columns(mat1,1,2,5*y);
add_rows(mat1,1,2,x);

add_to_columns(mat1,3,1000);
add_to_columns(mat1,{1,2,3},y);
add_to_rows(mat1,2,1000);
add_to_rows(mat1,{1,2,3},x);

augment_columns(mat1,2);
augment_columns(mat1,{1,2,5});
stack_rows(mat1,3);
stack_rows(mat1,{1,3,5});

char_poly(mat1,x);

column_dim(mat2);
row_dim(mat1);

copy_into(mat7,mat1,2,3);
copy_into(mat7,mat1,5,5);

diagonal(3);
% diagonal can take both a list of arguments or just the arguments.
diagonal({mat2,mat6});
diagonal(mat1,mat2,mat5);

extend(mat1,3,2,x);

find_companion(mat5,x);

get_columns(mat1,1);
get_columns(mat1,{1,2});
get_rows(mat1,3);
get_rows(mat1,{1,3});

hermitian_tp(mat6);

% matrix_augment and matrix_stack can take both a list of arguments
% or just the arguments.
matrix_augment({mat1,mat2});
matrix_augment(mat4,mat2,mat4);
matrix_stack(mat1,mat2);
matrix_stack({mat6,mat((z,z,z)),mat7});

minor(mat1,2,3);

mult_columns(mat1,3,y);
mult_columns(mat1,{2,3,4},100);
mult_rows(mat1,2,x);
mult_rows(mat1,{1,3,5},10);

pivot(mat1,3,3);
rows_pivot(mat1,3,3,{1,5});

remove_columns(mat1,3);
remove_columns(mat1,{2,3,4});
remove_rows(mat1,2);
remove_rows(mat1,{1,3});
remove_rows(mat1,{1,2,3,4,5});

swap_columns(mat1,2,4);
swap_rows(mat1,1,2);
swap_entries(mat1,{1,1},{5,5});


% Constructors - functions that create matrices.

band_matrix(x,5);
band_matrix({x,y,z},6);

block_matrix(1,2,{mat1,mat2});
block_matrix(2,3,{mat2,mat3,mat2,mat3,mat2,mat2});

char_matrix(mat1,x);

cfmat := coeff_matrix({x+y+4*z=10,y+x-z=20,x+y+4});
first cfmat * second cfmat;
third cfmat;

companion(poly,x);

hessian(poly1,{w,x,y,z});

hilbert(4,1);
hilbert(3,y+x);

% NOTE WELL. The function tested here used to be called just "jacobian"
% however us of that name was in conflict with another Reduce package so
% now it is called mat_jacobian.
mat_jacobian({x^4,x*y^2,x*y*z^3},{w,x,y,z});

jordan_block(x,5);

make_identity(11);

on rounded; % makes things a bit easier to read.
random_matrix(3,3,100);
on not_negative;
random_matrix(3,3,100);
on only_integer;
random_matrix(3,3,100);
on symmetric;
random_matrix(3,3,100);
off symmetric;
on upper_matrix;
random_matrix(3,3,100);
off upper_matrix;
on lower_matrix;
random_matrix(3,3,100);
off lower_matrix;
on imaginary;
off not_negative;
random_matrix(3,3,100);
off rounded;

% toeplitz and vandermonde can take both a list of arguments or just
% the arguments.
toeplitz({1,2,3,4,5});
toeplitz(x,y,z);

vandermonde({1,2,3,4,5});
vandermonde(x,y,z);

% kronecker_product

a1 := mat((1,2),(3,4),(5,6));
a2 := mat((1,x,1),(2,2,2),(3,3,3));

kronecker_product(a1,a2);

clear a1,a2;

% High level algorithms.

on rounded; % makes output easier to read.
ch := cholesky(mat7);
tp first ch - second ch;
tmp := first ch * second ch;
tmp - mat7;
off rounded;

gram_schmidt({1,0,0},{1,1,0},{1,1,1});
gram_schmidt({1,2},{3,4});

on rounded; % again, makes large quotients a bit more readable.
% The algorithm used for lu_decom sometimes swaps the rows of the input
% matrix so that (given matrix A, lu_decom(A) = {L,U,vec}), we find L*U
% does not equal A but a row equivalent of it. The call convert(A,vec)
% will return this row equivalent (ie: L*U = convert(A,vec)).
lu := lu_decom(mat5);
mat5;
tmp := first lu * second lu;
tmp1 := convert(mat5,third lu);
tmp - tmp1;
% and the complex case...
lu1 := lu_decom(mat6);
mat6;
tmp := first lu1 * second lu1;
tmp1 := convert(mat6,third lu1);
tmp - tmp1;

mat9inv := pseudo_inverse(mat9);
mat9 * mat9inv;

simplex(min,2*x1+14*x2+36*x3,{-2*x1+x2+4*x3>=5,-x1-2*x2-3*x3<=2});

simplex(max,10000 x1 + 1000 x2 + 100 x3 + 10 x4 + x5,{ x1 <= 1, 20 x1 +
 x2 <= 100, 200 x1 + 20 x2 + x3 <= 10000, 2000 x1 + 200 x2 + 20 x3 + x4
 <= 1000000, 20000 x1 + 2000 x2 + 200 x3 + 20 x4 + x5 <= 100000000});

simplex(max, 5 x1 + 4 x2 + 3 x3,
           { 2 x1 + 3 x2 + x3 <= 5,
             4 x1 + x2 + 2 x3 <= 11,
             3 x1 + 4 x2 + 2 x3 <= 8 });

simplex(min,3 x1 + 5 x2,{ x1 + 2 x2 >= 2, 22 x1 + x2 >= 3});

simplex(max,10x+5y+5.5z,{5x+3z<=200,0.2x+0.1y+0.5z<=12,0.1x+0.2y+0.3z<=9,
                         30x+10y+50z<=1500});

%example of extra variables (>=0) being added.
simplex(min,x-y,{x>=-3});

% unfeasible as simplex algorithm implies all x>=0.
simplex(min,x,{x<=-100});

% three error examples.
simplex(maxx,x,{x>=5});
simplex(max,x,x>=5);
simplex(max,x,{x<=y});

simplex(max, 346 x11 + 346 x12 + 248 x21 + 248 x22 + 399 x31 + 399 x32 +
             200 y11 + 200 y12 + 75 y21 + 75 y22 + 2.35 z1 + 3.5 z2,
{
 4 x11 + 4 x12 + 2 x21 + 2 x22 + x31 + x32 + 250 y11 + 250 y12 + 125 y21 +
  125 y22 <= 25000,
 x11 + x12 + x21 + x22 + x31 + x32 + 2 y11 + 2 y12 + y21 + y22 <= 300,
 20 x11 + 15 x12 + 30 y11 + 20 y21 + z1 <= 1500,
 40 x12 + 35 x22 + 50 x32 + 15 y12 + 10 y22 + z2  = 5000,
 x31  = 0,
 y11 + y12 <= 50,
 y21 + y22 <= 100
});


% from Marc van Dongen. Finding the first feasible solution for the
% solution of systems of linear diophantine inequalities.
simplex(max,0,{
  3*x259+4*x261+3*x262+2*x263+x269+2*x270+3*x271+4*x272+5*x273+x229=2,
  7*x259+11*x261+8*x262+5*x263+3*x269+6*x270+9*x271+12*x272+15*x273+x229=4,
  2*x259+5*x261+4*x262+3*x263+3*x268+4*x269+5*x270+6*x271+7*x272+8*x273=1,
  x262+2*x263+5*x268+4*x269+3*x270+2*x271+x272+2*x229=1,
  x259+x262+2*x263+4*x268+3*x269+2*x270+x271-x273+3*x229=2,
  x259+2*x261+2*x262+2*x263+3*x268+3*x269+3*x270+3*x271+3*x272+3*x273+x229=1,
  x259+x261+x262+x263+x268+x269+x270+x271+x272+x273+x229=1});


% An example with a bound section:
simplex(min, 0,
   {-n2 <= -1, -n1-n2 <= 0, 2*n1+n2 <= 0, 5*n1+2*n2 <= 0, 5*n1-n2 <= 0},
   {-infinity <= n1, -infinity <= n2 <= 2});


svd_ans := svd(mat8);
tmp := first svd_ans * second svd_ans * tp third svd_ans;
tmp - mat8;

svd_ans := svd(mat10);
tmp := first svd_ans * second svd_ans * tp third svd_ans;
tmp - mat10;

mat10inv := pseudo_inverse(mat10);
mat10 * mat10inv * mat10;
mat10inv * mat10 * mat10inv;

mat9inv := pseudo_inverse(mat9);
mat9 * mat9inv;

% triang_adjoint(in_mat) calculates the
% triangularizing adjoint of in_mat

triang_adjoint(mat1);
triang_adjoint(mat2);
triang_adjoint(mat5);
triang_adjoint(mat6);
triang_adjoint(mat7);
triang_adjoint(mat8);
triang_adjoint(mat9);

% testing triang_adjoint with random matrices

% the range of the integers is in one case from
% -1000 to 1000. in the other case it is from
% -1 to 1 so that the deteminant of the i-th
% submatrix equals very often to zero.

% random matrix contains arbitrary real values
off only_integer;
tmp:=random_matrix(5,5,1000);
triang_adjoint tmp;

tmp:=random_matrix(1,1,1000);
triang_adjoint tmp;

% random matrix contains complex real values
on imaginary;
tmp:=random_matrix(5,5,1000);
triang_adjoint tmp;

tmp:=random_matrix(1,1,1000);
triang_adjoint tmp;
off imaginary;

% random matrix contains rounded real values
on rounded;
tmp:=random_matrix(5,5,1000);
triang_adjoint tmp;

tmp:=random_matrix(1,1,1000);
triang_adjoint tmp;
off rounded;

% random matrix contains only integer values
on only_integer;
tmp:=random_matrix(7,7,1000);
triang_adjoint tmp;

tmp:=random_matrix(7,7,1);
triang_adjoint tmp;

% random matrix contains only complex integer
% values

on imaginary;
tmp:=random_matrix(5,5,1000);
triang_adjoint tmp;

tmp:=random_matrix(5,5,2);
triang_adjoint tmp;

% Predicates.

matrixp(mat1);
matrixp(poly);

squarep(mat2);
squarep(mat3);

symmetricp(mat1);
symmetricp(mat3);

if not rounded_was_on then off rounded;


end;


