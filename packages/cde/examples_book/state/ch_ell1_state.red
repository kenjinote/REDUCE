% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_8t)
de!*:=(letop)
% odd equation
principal_odd!*:=(p_8t)
de_odd!*(letop)
% Settings:
indep_var!*:=(t x)
dep_var!*:=(u)
odd_var!*:=(p)
deg_indep_var!*:=nil
deg_dep_var!*:=nil
deg_odd_var!*:=nil
total_order:=8
id_tot_der!*:=dd
% Here starts the output of computations of the program.
% number of independent variables:
n_indep_var:=2
% all multiindexes in table format:
all_mind_table!*:=(((0 0) ((1 0) (0 1))) ((1 0) ((2 0) (1 1) (1 1) (0 2))) ((0 1
) ((1 1) (0 2))) ((2 0) ((3 0) (2 1) (2 1) (1 2) (1 2) (0 3))) ((1 1) ((2 1) (1
2) (1 2) (0 3))) ((0 2) ((1 2) (0 3))) ((3 0) ((4 0) (3 1) (3 1) (2 2) (2 2) (1
3) (1 3) (0 4))) ((2 1) ((3 1) (2 2) (2 2) (1 3) (1 3) (0 4))) ((1 2) ((2 2) (1
3) (1 3) (0 4))) ((0 3) ((1 3) (0 4))) ((4 0) ((5 0) (4 1) (4 1) (3 2) (3 2) (2
3) (2 3) (1 4) (1 4) (0 5))) ((3 1) ((4 1) (3 2) (3 2) (2 3) (2 3) (1 4) (1 4) (
0 5))) ((2 2) ((3 2) (2 3) (2 3) (1 4) (1 4) (0 5))) ((1 3) ((2 3) (1 4) (1 4) (
0 5))) ((0 4) ((1 4) (0 5))) ((5 0) ((6 0) (5 1) (5 1) (4 2) (4 2) (3 3) (3 3) (
2 4) (2 4) (1 5) (1 5) (0 6))) ((4 1) ((5 1) (4 2) (4 2) (3 3) (3 3) (2 4) (2 4)
(1 5) (1 5) (0 6))) ((3 2) ((4 2) (3 3) (3 3) (2 4) (2 4) (1 5) (1 5) (0 6))) ((
2 3) ((3 3) (2 4) (2 4) (1 5) (1 5) (0 6))) ((1 4) ((2 4) (1 5) (1 5) (0 6))) ((
0 5) ((1 5) (0 6))) ((6 0) ((7 0) (6 1) (6 1) (5 2) (5 2) (4 3) (4 3) (3 4) (3 4
) (2 5) (2 5) (1 6) (1 6) (0 7))) ((5 1) ((6 1) (5 2) (5 2) (4 3) (4 3) (3 4) (3
4) (2 5) (2 5) (1 6) (1 6) (0 7))) ((4 2) ((5 2) (4 3) (4 3) (3 4) (3 4) (2 5) (
2 5) (1 6) (1 6) (0 7))) ((3 3) ((4 3) (3 4) (3 4) (2 5) (2 5) (1 6) (1 6) (0 7)
)) ((2 4) ((3 4) (2 5) (2 5) (1 6) (1 6) (0 7))) ((1 5) ((2 5) (1 6) (1 6) (0 7)
)) ((0 6) ((1 6) (0 7))) ((7 0) ((8 0) (7 1) (7 1) (6 2) (6 2) (5 3) (5 3) (4 4)
(4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((6 1) ((7 1) (6 2) (6 2) (5 3
) (5 3) (4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((5 2) ((6 2) (5
3) (5 3) (4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((4 3) ((5 3) (
4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((3 4) ((4 4) (3 5) (3 5)
(2 6) (2 6) (1 7) (1 7) (0 8))) ((2 5) ((3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((
1 6) ((2 6) (1 7) (1 7) (0 8))) ((0 7) ((1 7) (0 8))) ((8 0) nil) ((7 1) nil) ((
6 2) nil) ((5 3) nil) ((4 4) nil) ((3 5) nil) ((2 6) nil) ((1 7) nil) ((0 8) nil
))
% all even derivatives in multiindex notation:
all_der_mind!*:=((u (0 0)) (u (1 0)) (u (0 1)) (u (2 0)) (u (1 1)) (u (0 2)) (u
(3 0)) (u (2 1)) (u (1 2)) (u (0 3)) (u (4 0)) (u (3 1)) (u (2 2)) (u (1 3)) (u
(0 4)) (u (5 0)) (u (4 1)) (u (3 2)) (u (2 3)) (u (1 4)) (u (0 5)) (u (6 0)) (u
(5 1)) (u (4 2)) (u (3 3)) (u (2 4)) (u (1 5)) (u (0 6)) (u (7 0)) (u (6 1)) (u
(5 2)) (u (4 3)) (u (3 4)) (u (2 5)) (u (1 6)) (u (0 7)) (u (8 0)) (u (7 1)) (u
(6 2)) (u (5 3)) (u (4 4)) (u (3 5)) (u (2 6)) (u (1 7)) (u (0 8)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((p (0 0)) (p (1 0)) (p (0 1)) (p (2 0)) (p (1 1)) (p (0 2)) (p
(3 0)) (p (2 1)) (p (1 2)) (p (0 3)) (p (4 0)) (p (3 1)) (p (2 2)) (p (1 3)) (p
(0 4)) (p (5 0)) (p (4 1)) (p (3 2)) (p (2 3)) (p (1 4)) (p (0 5)) (p (6 0)) (p
(5 1)) (p (4 2)) (p (3 3)) (p (2 4)) (p (1 5)) (p (0 6)) (p (7 0)) (p (6 1)) (p
(5 2)) (p (4 3)) (p (3 4)) (p (2 5)) (p (1 6)) (p (0 7)) (p (8 0)) (p (7 1)) (p
(6 2)) (p (5 3)) (p (4 4)) (p (3 5)) (p (2 6)) (p (1 7)) (p (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_t u_x u_2t u_tx u_2x u_3t u_2tx u_t2x u_3x u_4t u_3tx u_2t2x
u_t3x u_4x u_5t u_4tx u_3t2x u_2t3x u_t4x u_5x u_6t u_5tx u_4t2x u_3t3x u_2t4x
u_t5x u_6x u_7t u_6tx u_5t2x u_4t3x u_3t4x u_2t5x u_t6x u_7x u_8t u_7tx u_6t2x
u_5t3x u_4t4x u_3t5x u_2t6x u_t7x u_8x)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p p_t p_x p_2t p_tx p_2x p_3t p_2tx p_t2x p_3x p_4t p_3tx p_2t2x
p_t3x p_4x p_5t p_4tx p_3t2x p_2t3x p_t4x p_5x p_6t p_5tx p_4t2x p_3t3x p_2t4x
p_t5x p_6x p_7t p_6tx p_5t2x p_4t3x p_3t4x p_2t5x p_t6x p_7x p_8t p_7tx p_6t2x
p_5t3x p_4t4x p_3t5x p_2t6x p_t7x p_8x)
% number of all ext symbols:
n_all_ext:=45
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (u_t u (1 0)) (u_x u (0 1)) (u_2t u (2 0)) (u_tx u
(1 1)) (u_2x u (0 2)) (u_3t u (3 0)) (u_2tx u (2 1)) (u_t2x u (1 2)) (u_3x u (0
3)) (u_4t u (4 0)) (u_3tx u (3 1)) (u_2t2x u (2 2)) (u_t3x u (1 3)) (u_4x u (0 4
)) (u_5t u (5 0)) (u_4tx u (4 1)) (u_3t2x u (3 2)) (u_2t3x u (2 3)) (u_t4x u (1
4)) (u_5x u (0 5)) (u_6t u (6 0)) (u_5tx u (5 1)) (u_4t2x u (4 2)) (u_3t3x u (3
3)) (u_2t4x u (2 4)) (u_t5x u (1 5)) (u_6x u (0 6)) (u_7t u (7 0)) (u_6tx u (6 1
)) (u_5t2x u (5 2)) (u_4t3x u (4 3)) (u_3t4x u (3 4)) (u_2t5x u (2 5)) (u_t6x u
(1 6)) (u_7x u (0 7)) (u_8t u (8 0)) (u_7tx u (7 1)) (u_6t2x u (6 2)) (u_5t3x u
(5 3)) (u_4t4x u (4 4)) (u_3t5x u (3 5)) (u_2t6x u (2 6)) (u_t7x u (1 7)) (u_8x
u (0 8)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((p p (0 0)) (p_t p (1 0)) (p_x p (0 1)) (p_2t p (2 0)) (
p_tx p (1 1)) (p_2x p (0 2)) (p_3t p (3 0)) (p_2tx p (2 1)) (p_t2x p (1 2)) (
p_3x p (0 3)) (p_4t p (4 0)) (p_3tx p (3 1)) (p_2t2x p (2 2)) (p_t3x p (1 3)) (
p_4x p (0 4)) (p_5t p (5 0)) (p_4tx p (4 1)) (p_3t2x p (3 2)) (p_2t3x p (2 3)) (
p_t4x p (1 4)) (p_5x p (0 5)) (p_6t p (6 0)) (p_5tx p (5 1)) (p_4t2x p (4 2)) (
p_3t3x p (3 3)) (p_2t4x p (2 4)) (p_t5x p (1 5)) (p_6x p (0 6)) (p_7t p (7 0)) (
p_6tx p (6 1)) (p_5t2x p (5 2)) (p_4t3x p (4 3)) (p_3t4x p (3 4)) (p_2t5x p (2 5
)) (p_t6x p (1 6)) (p_7x p (0 7)) (p_8t p (8 0)) (p_7tx p (7 1)) (p_6t2x p (6 2)
) (p_5t3x p (5 3)) (p_4t4x p (4 4)) (p_3t5x p (3 5)) (p_2t6x p (2 6)) (p_t7x p (
1 7)) (p_8x p (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_t . 1) (u_x . 1) (u_2t . 2) (u_tx . 2) (u_2x . 2) (
u_3t . 3) (u_2tx . 3) (u_t2x . 3) (u_3x . 3) (u_4t . 4) (u_3tx . 4) (u_2t2x . 4)
(u_t3x . 4) (u_4x . 4) (u_5t . 5) (u_4tx . 5) (u_3t2x . 5) (u_2t3x . 5) (u_t4x .
5) (u_5x . 5) (u_6t . 6) (u_5tx . 6) (u_4t2x . 6) (u_3t3x . 6) (u_2t4x . 6) (
u_t5x . 6) (u_6x . 6) (u_7t . 7) (u_6tx . 7) (u_5t2x . 7) (u_4t3x . 7) (u_3t4x .
7) (u_2t5x . 7) (u_t6x . 7) (u_7x . 7) (u_8t . 8) (u_7tx . 8) (u_6t2x . 8) (
u_5t3x . 8) (u_4t4x . 8) (u_3t5x . 8) (u_2t6x . 8) (u_t7x . 8) (u_8x . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (p_t . 1) (p_x . 1) (p_2t . 2) (p_tx . 2) (p_2x . 2
) (p_3t . 3) (p_2tx . 3) (p_t2x . 3) (p_3x . 3) (p_4t . 4) (p_3tx . 4) (p_2t2x .
4) (p_t3x . 4) (p_4x . 4) (p_5t . 5) (p_4tx . 5) (p_3t2x . 5) (p_2t3x . 5) (
p_t4x . 5) (p_5x . 5) (p_6t . 6) (p_5tx . 6) (p_4t2x . 6) (p_3t3x . 6) (p_2t4x .
6) (p_t5x . 6) (p_6x . 6) (p_7t . 7) (p_6tx . 7) (p_5t2x . 7) (p_4t3x . 7) (
p_3t4x . 7) (p_2t5x . 7) (p_t6x . 7) (p_7x . 7) (p_8t . 8) (p_7tx . 8) (p_6t2x .
8) (p_5t3x . 8) (p_4t4x . 8) (p_3t5x . 8) (p_2t6x . 8) (p_t7x . 8) (p_8x . 8))
% list of even principal derivatives:
all_principal_der!*:=(u_8t)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_t u_x u_2t u_tx u_2x u_3t u_2tx u_t2x u_3x u_4t u_3tx
u_2t2x u_t3x u_4x u_5t u_4tx u_3t2x u_2t3x u_t4x u_5x u_6t u_5tx u_4t2x u_3t3x
u_2t4x u_t5x u_6x u_7t u_6tx u_5t2x u_4t3x u_3t4x u_2t5x u_t6x u_7x u_7tx u_6t2x
u_5t3x u_4t4x u_3t5x u_2t6x u_t7x u_8x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_8t)
p_8t = (ext 45)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p p_t p_x p_2t p_tx p_2x p_3t p_2tx p_t2x p_3x p_4t p_3tx
p_2t2x p_t3x p_4x p_5t p_4tx p_3t2x p_2t3x p_t4x p_5x p_6t p_5tx p_4t2x p_3t3x
p_2t4x p_t5x p_6x p_7t p_6tx p_5t2x p_4t3x p_3t4x p_2t5x p_t6x p_7x p_7tx p_6t2x
p_5t3x p_4t4x p_3t5x p_2t6x p_t7x p_8x)
p = (ext 1)
p_t = (ext 2)
p_x = (ext 3)
p_2t = (ext 4)
p_tx = (ext 5)
p_2x = (ext 6)
p_3t = (ext 7)
p_2tx = (ext 8)
p_t2x = (ext 9)
p_3x = (ext 10)
p_4t = (ext 11)
p_3tx = (ext 12)
p_2t2x = (ext 13)
p_t3x = (ext 14)
p_4x = (ext 15)
p_5t = (ext 16)
p_4tx = (ext 17)
p_3t2x = (ext 18)
p_2t3x = (ext 19)
p_t4x = (ext 20)
p_5x = (ext 21)
p_6t = (ext 22)
p_5tx = (ext 23)
p_4t2x = (ext 24)
p_3t3x = (ext 25)
p_2t4x = (ext 26)
p_t5x = (ext 27)
p_6x = (ext 28)
p_7t = (ext 29)
p_6tx = (ext 30)
p_5t2x = (ext 31)
p_4t3x = (ext 32)
p_3t4x = (ext 33)
p_2t5x = (ext 34)
p_t6x = (ext 35)
p_7x = (ext 36)
p_7tx = (ext 37)
p_6t2x = (ext 38)
p_5t3x = (ext 39)
p_4t4x = (ext 40)
p_3t5x = (ext 41)
p_2t6x = (ext 42)
p_t7x = (ext 43)
p_8x = (ext 44)
% number of ext principal derivatives:
n_all_principal_ext:=1
% number of ext parametric derivatives:
n_all_parametric_ext:=44
% set of identifiers for total derivatives:
tot_der!*:=(ddt ddx)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 31 u_8t))
primary_diffcon_odd_tot!*:=((ddt 1 29 p_8t))
primary_diffcon_der!*:=nil
primary_diffcon_odd!*:=nil
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_8t letop))
diffcon_odd!*:=((p_8t letop))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_8t)
diffcon_comp_odd!*:=(p_8t)
diffcon_comp_ext!*:=((ext 45))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_8t *sq ((((letop . 1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 45) *sq ((((letop . 1) . 1)) . 1) t))
% Coefficients of total derivatives:
% component of ddt w.r.t. t
ddt(0,1):=1
% component of ddt w.r.t. x
ddt(0,2):=0
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((u_t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,4):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,5):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,6):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx
ddt(0,7):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x
ddt(0,8):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,9):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx
ddt(0,10):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x
ddt(0,11):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,12):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,13):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3tx
ddt(0,14):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2x
ddt(0,15):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3x
ddt(0,16):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,17):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,18):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4tx
ddt(0,19):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2x
ddt(0,20):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3x
ddt(0,21):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4x
ddt(0,22):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,23):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,24):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5tx
ddt(0,25):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t2x
ddt(0,26):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t3x
ddt(0,27):=(*sq ((((u_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t4x
ddt(0,28):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t5x
ddt(0,29):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,30):=(*sq ((((u_t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,31):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6tx
ddt(0,32):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t2x
ddt(0,33):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t3x
ddt(0,34):=(*sq ((((u_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t4x
ddt(0,35):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t5x
ddt(0,36):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t6x
ddt(0,37):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,38):=(*sq ((((u_t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7tx
ddt(0,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t2x
ddt(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t3x
ddt(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t4x
ddt(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t5x
ddt(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t6x
ddt(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t7x
ddt(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,4):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_tx
ddt(1,5):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,7):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2tx
ddt(1,8):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2x
ddt(1,9):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,10):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,11):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3tx
ddt(1,12):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t2x
ddt(1,13):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t3x
ddt(1,14):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,15):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,16):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4tx
ddt(1,17):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t2x
ddt(1,18):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t3x
ddt(1,19):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t4x
ddt(1,20):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,21):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,22):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5tx
ddt(1,23):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t2x
ddt(1,24):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t3x
ddt(1,25):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t4x
ddt(1,26):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t5x
ddt(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x
ddt(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6tx
ddt(1,30):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t2x
ddt(1,31):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t3x
ddt(1,32):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t4x
ddt(1,33):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t5x
ddt(1,34):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t6x
ddt(1,35):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,36):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7tx
ddt(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t2x
ddt(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t3x
ddt(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t4x
ddt(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t5x
ddt(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t6x
ddt(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t7x
ddt(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. t
ddx(0,1):=0
% component of ddx w.r.t. x
ddx(0,2):=1
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,4):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,5):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,6):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx
ddx(0,7):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,8):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,9):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx
ddx(0,10):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x
ddx(0,11):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,12):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,13):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3tx
ddx(0,14):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2x
ddx(0,15):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3x
ddx(0,16):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,17):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,18):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4tx
ddx(0,19):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2x
ddx(0,20):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3x
ddx(0,21):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4x
ddx(0,22):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,23):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,24):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5tx
ddx(0,25):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t2x
ddx(0,26):=(*sq ((((u_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t3x
ddx(0,27):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t4x
ddx(0,28):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t5x
ddx(0,29):=(*sq ((((u_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,30):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,31):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6tx
ddx(0,32):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t2x
ddx(0,33):=(*sq ((((u_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t3x
ddx(0,34):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t4x
ddx(0,35):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t5x
ddx(0,36):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t6x
ddx(0,37):=(*sq ((((u_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,38):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7tx
ddx(0,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t2x
ddx(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t3x
ddx(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t4x
ddx(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t5x
ddx(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t6x
ddx(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t7x
ddx(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,2):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,3):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,4):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_tx
ddx(1,5):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,6):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,7):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2tx
ddx(1,8):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2x
ddx(1,9):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,10):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,11):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3tx
ddx(1,12):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t2x
ddx(1,13):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t3x
ddx(1,14):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4tx
ddx(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t2x
ddx(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t3x
ddx(1,19):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t4x
ddx(1,20):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,21):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,22):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5tx
ddx(1,23):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t2x
ddx(1,24):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t3x
ddx(1,25):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t4x
ddx(1,26):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t5x
ddx(1,27):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6tx
ddx(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t2x
ddx(1,31):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t3x
ddx(1,32):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t4x
ddx(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t5x
ddx(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t6x
ddx(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7tx
ddx(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t2x
ddx(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t3x
ddx(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t4x
ddx(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t5x
ddx(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t6x
ddx(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t7x
ddx(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
