% Raffaele Vitolo, 09/10/09
% This is the computation for symmetries of KdV
% ansatz: sym=x*(something of degree 3)+t*(something of degree  5)
%  +(something of degree 2)
% In order to work with the examples, load first CDIFF with the command
load_package cdiff;

super_vectorfield(ddx,{x,t,u,u1,u2,u3,u4,u5,u6,u7,
u8,u9,u10,u11,u12,u13,u14,u15,u16,u17},
{ext 1,ext 2,ext 3,ext 4,ext 5,ext 6,ext 7,ext 8,ext 9,ext 10,ext
11,ext 12,ext 13,ext 14,ext 15,ext 16,ext 17,ext 18,ext 19,ext 20,ext
21,ext 22,ext 23,ext 24,ext 25,ext 26,ext 27,ext 28,ext 29,ext 30,
ext 31,ext 32,ext 33,ext 34,ext 35,ext 36,ext 37,ext 38,ext 39,ext 40,
ext 41,ext 42,ext 43,ext 44,ext 45,ext 46,ext 47,ext 48,ext 49,ext 50,
ext 51,ext 52,ext 53,ext 54,ext 55,ext 56,ext 57,ext 58,ext 59,ext 60,
ext 61,ext 62,ext 63,ext 64,ext 65,ext 66,ext 67,ext 68,ext 69,ext 70,
ext 71,ext 72,ext 73,ext 74,ext 75,ext 76,ext 77,ext 78,ext 79,ext 80
});

super_vectorfield(ddt,{x,t,u,u1,u2,u3,u4,u5,u6,u7,
u8,u9,u10,u11,u12,u13,u14,u15,u16,u17},
{ext 1,ext 2,ext 3,ext 4,ext 5,ext 6,ext 7,ext 8,ext 9,ext 10,ext
11,ext 12,ext 13,ext 14,ext 15,ext 16,ext 17,ext 18,ext 19,ext 20,ext
21,ext 22,ext 23,ext 24,ext 25,ext 26,ext 27,ext 28,ext 29,ext 30,
ext 31,ext 32,ext 33,ext 34,ext 35,ext 36,ext 37,ext 38,ext 39,ext 40,
ext 41,ext 42,ext 43,ext 44,ext 45,ext 46,ext 47,ext 48,ext 49,ext 50,
ext 51,ext 52,ext 53,ext 54,ext 55,ext 56,ext 57,ext 58,ext 59,ext 60,
ext 61,ext 62,ext 63,ext 64,ext 65,ext 66,ext 67,ext 68,ext 69,ext 70,
ext 71,ext 72,ext 73,ext 74,ext 75,ext 76,ext 77,ext 78,ext 79,ext 80
});


%specification of the vectorfield ddx
%the even variables
ddx(0,1):=1$
ddx(0,2):=0$
ddx(0,3):=u1$
ddx(0,4):=u2$
ddx(0,5):=u3$
ddx(0,6):=u4$
ddx(0,7):=u5$
ddx(0,8):=u6$
ddx(0,9):=u7$
ddx(0,10):=u8$
ddx(0,11):=u9$
ddx(0,12):=u10$
ddx(0,13):=u11$
ddx(0,14):=u12$
ddx(0,15):=u13$
ddx(0,16):=u14$
ddx(0,17):=u15$
ddx(0,18):=u16$
ddx(0,19):=u17$
ddx(0,20):=letop$

%specification of the vectorfield ddt
%the even variables
ddt(0,1):=0$
ddt(0,2):=1$
ddt(0,3):=ut$
ddt(0,4):=ut1$
ddt(0,5):=ut2$
ddt(0,6):=ut3$
ddt(0,7):=ut4$
ddt(0,8):=ut5$
ddt(0,9):=ut6$
ddt(0,10):=ut7$
ddt(0,11):=ut8$
ddt(0,12):=ut9$
ddt(0,13):=ut10$
ddt(0,14):=ut11$
ddt(0,15):=ut12$
ddt(0,16):=ut13$
ddt(0,17):=ut14$
ddt(0,18):=letop$
ddt(0,19):=letop$
ddt(0,20):=letop$

ut:=u*u1+u3;

ut1:=ddx ut;
ut2:=ddx ut1;
ut3:=ddx ut2;
ut4:=ddx ut3;
ut5:=ddx ut4;
ut6:=ddx ut5;
ut7:=ddx ut6;
ut8:=ddx ut7;
ut9:=ddx ut8;
ut10:=ddx ut9;
ut11:=ddx ut10;
ut12:=ddx ut11;
ut13:=ddx ut12;
ut14:=ddx ut13;

operator ev;

for i:=1:17 do write ev(0,i):=ddt(ddx(0,i))-ddx(ddt(0,i));

pause;

all_graded_der:={{},{u},{u1},{u2},{u3},{u4},{u5},
{u6},{u7},{u8},{u9},{u10},{u11},{u12},{u13},{u14},{u15},{u16},{u17}};


grd0:={1};
grd1:= mkvarlist1(1,1)$
grd2:= mkvarlist1(2,2)$
grd3:= mkvarlist1(3,3)$
grd4:= mkvarlist1(4,4)$
grd5:= mkvarlist1(5,5)$
grd6:= mkvarlist1(6,6)$
grd7:= mkvarlist1(7,7)$
grd8:= mkvarlist1(8,8)$
grd9:= mkvarlist1(9,9)$
grd10:= mkvarlist1(10,10)$
grd11:= mkvarlist1(11,11)$
grd12:= mkvarlist1(12,12)$
grd13:= mkvarlist1(13,13)$
grd14:= mkvarlist1(14,14)$
grd15:= mkvarlist1(15,15)$
grd16:= mkvarlist1(16,16)$

operator c,equ;

ctel:=0;

sym:=
%(for each el in grd0 sum (c(ctel:=ctel+1)*el))+
%(for each el in grd1 sum (c(ctel:=ctel+1)*el))+
(for each el in grd2 sum (c(ctel:=ctel+1)*el))+
x*(for each el in grd3 sum (c(ctel:=ctel+1)*el))+
% (for each el in grd4 sum (c(ctel:=ctel+1)*el))+
t*(for each el in grd5 sum (c(ctel:=ctel+1)*el))$

equ 1:=ddt(sym)-u*ddx(sym)-u1*sym-ddx(ddx(ddx(sym)));

vars:={x,t,u,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,u12,u13,u14,u15,u16,u17};

tel:=1;

procedure splitvars i;
begin;
ll:=multi_coeff(equ i,vars);
equ(tel:=tel+1):=first ll;
ll:=rest ll;
for each el in ll do equ(tel:=tel+1):=second el;
end;

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

splitvars 1;

tel1:=tel;

put_equations_used tel;

for i:=2:te do integrate_equation i;

;end;

