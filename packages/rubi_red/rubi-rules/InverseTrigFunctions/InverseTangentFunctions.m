(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.822.1, CRC 443, A&S 4.4.60*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]\[DifferentialD]x  \[LongRightArrow]  x ArcTan[a x]-Log[1+a^2 x^2]/(2a)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_],x_Symbol] :=
  x*ArcTan[a*x] - Log[1+a^2*x^2]/(2*a) /;
FreeQ[a,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  x ArcTan[a x]^n-a n \[Integral](x ArcTan[a x]^(n-1))/(1+a^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_,x_Symbol] :=
  x*ArcTan[a*x]^n -
  Dist[a*n,Int[x*ArcTan[a*x]^(n-1)/(1+a^2*x^2),x]] /;
FreeQ[a,x] && IntegerQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (ArcTan[a x]^n/(2a^2))+(x^2 ArcTan[a x]^n)/2-n/(2a) \[Integral]ArcTan[a x]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  ArcTan[a*x]^n/(2*a^2) + x^2*ArcTan[a*x]^n/2 -
  Dist[n/(2*a),Int[ArcTan[a*x]^(n-1),x]] /;
FreeQ[a,x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] m>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m-1) ArcTan[a x]^n)/(a^2 (m+1)))+(x^(m+1) ArcTan[a x]^n)/(m+1)-                                                *)
(*                                                n/(a(m+1)) \[Integral]x^(m-1) ArcTan[a x]^(n-1) \[DifferentialD]x-(m-1)/(a^2 (m+1)) \[Integral]x^(m-2) ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^(m-1)*ArcTan[a*x]^n/(a^2*(m+1)) + x^(m+1)*ArcTan[a*x]^n/(m+1) -
  Dist[n/(a*(m+1)),Int[x^(m-1)*ArcTan[a*x]^(n-1),x]] -
  Dist[(m-1)/(a^2*(m+1)),Int[x^(m-2)*ArcTan[a*x]^n,x]] /;
FreeQ[a,x] && IntegerQ[n] && n>0 && RationalQ[m] && m>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/x \[DifferentialD]x  \[LongRightArrow]  2 ArcTan[a x]^n ArcTanh[1-(2I)/(I-a x)]-2a n \[Integral](ArcTan[a x]^(n-1) ArcTanh[1-(2I)/(I-a x)])/(1+a^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_/x_,x_Symbol] :=
  2*ArcTan[a*x]^n*ArcTanh[1-2*I/(I-a*x)] -
  Dist[2*a*n,Int[ArcTan[a*x]^(n-1)*ArcTanh[1-2*I/(I-a*x)]/(1+a^2*x^2),x]] /;
FreeQ[a,x] && IntegerQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/x^2 \[DifferentialD]x  \[LongRightArrow]  -(ArcTan[a x]^n/x)+a n \[Integral]ArcTan[a x]^(n-1)/(x(1+a^2 x^2)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./x_^2,x_Symbol] :=
  -ArcTan[a*x]^n/x +
  Dist[a*n,Int[ArcTan[a*x]^(n-1)/(x*(1+a^2*x^2)),x]] /;
FreeQ[a,x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted iterated integration by parts special case*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/x^3 \[DifferentialD]x  \[LongRightArrow]  -((a^2 ArcTan[a x]^n)/2)-ArcTan[a x]^n/(2x^2)+(a n)/2 \[Integral]ArcTan[a x]^(n-1)/x^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./x_^3,x_Symbol] :=
  -a^2*ArcTan[a*x]^n/2 - ArcTan[a*x]^n/(2*x^2) +
  Dist[a*n/2,Int[ArcTan[a*x]^(n-1)/x^2,x]] /;
FreeQ[a,x] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Inverted iterated integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>0 \[And] m<-3, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcTan[a x]^n)/(m+1))+(a^2 x^(m+3) ArcTan[a x]^n)/(m+1)-                                                *)
(*                                                (a n)/(m+1) \[Integral]x^(m+1) ArcTan[a x]^(n-1) \[DifferentialD]x-(a^2 (m+3))/(m+1) \[Integral]x^(m+2) ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^(m+1)*ArcTan[a*x]^n/(m+1) + a^2*x^(m+3)*ArcTan[a*x]^n/(m+1) -
  Dist[a*n/(m+1),Int[x^(m+1)*ArcTan[a*x]^(n-1),x]] -
  Dist[a^2*(m+3)/(m+1),Int[x^(m+2)*ArcTan[a*x]^n,x]] /;
FreeQ[a,x] && IntegerQ[n] && n>0 && RationalQ[m] && m<-3


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 c^2+d^2=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x) \[DifferentialD]x  \[LongRightArrow]  -((ArcTan[a x]^n Log[(2 c)/(c +d x)])/d)+(a n)/d \[Integral](ArcTan[a x]^(n-1) Log[(2 c)/(c +d x)])/(1+a^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(c_+d_.*x_),x_Symbol] :=
  -ArcTan[a*x]^n*Log[2*c/(c+d*x)]/d +
  Dist[a*n/d,Int[ArcTan[a*x]^(n-1)*Log[2*c/(c+d*x)]/(1+a^2*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[a^2*c^2+d^2] && IntegerQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 c^2+d^2=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(x(c+d x)) \[DifferentialD]x  \[LongRightArrow]  ((ArcTan[a x]^n Log[2-(2 c)/(c+d x)])/c)-(a n)/c \[Integral](ArcTan[a x]^(n-1) Log[2-(2 c)/(c+d x)])/(1+a^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(x_*(c_+d_.*x_)),x_Symbol] :=
  ArcTan[a*x]^n*Log[2-2*c/(c+d*x)]/c -
  Dist[a*n/c,Int[ArcTan[a*x]^(n-1)*Log[2-2*c/(c+d*x)]/(1+a^2*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[a^2*c^2+d^2] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 c^2+d^2=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c x+d x^2) \[DifferentialD]x  \[LongRightArrow]  ((ArcTan[a x]^n Log[2-(2 c)/(c+d x)])/c)-(a n)/c \[Integral](ArcTan[a x]^(n-1) Log[2-(2 c)/(c+d x)])/(1+a^2 x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(c_.*x_+d_.*x_^2),x_Symbol] :=
  ArcTan[a*x]^n*Log[2-2*c/(c+d*x)]/c -
  Dist[a*n/c,Int[ArcTan[a*x]^(n-1)*Log[2-2*c/(c+d*x)]/(1+a^2*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[a^2*c^2+d^2] && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: x/(c+d x)==1/d-c/(d (c+d x))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 c^2+d^2=0 \[And] m>0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x) \[DifferentialD]x  \[LongRightArrow]  (1/d)\[Integral]x^(m-1) ArcTan[a x]^n \[DifferentialD]x-c/d \[Integral](x^(m-1) ArcTan[a x]^n)/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_.*x_]^n_./(c_+d_.*x_),x_Symbol] :=
  Dist[1/d,Int[x^(m-1)*ArcTan[a*x]^n,x]] -
  Dist[c/d,Int[x^(m-1)*ArcTan[a*x]^n/(c+d*x),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[a^2*c^2+d^2] && RationalQ[m] && m>0 && IntegerQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: 1/(c+d x)==1/c-(d x)/(c (c+d x))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2 c^2+d^2=0 \[And] m<-1 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x) \[DifferentialD]x  \[LongRightArrow]  (1/c)\[Integral]x^m ArcTan[a x]^n \[DifferentialD]x-d/c \[Integral](x^(m+1) ArcTan[a x]^n)/(c+d x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcTan[a_.*x_]^n_./(c_+d_.*x_),x_Symbol] :=
  Dist[1/c,Int[x^m*ArcTan[a*x]^n,x]] -
  Dist[d/c,Int[x^(m+1)*ArcTan[a*x]^n/(c+d*x),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[a^2*c^2+d^2] && RationalQ[m] && m<-1 && IntegerQ[n] && n>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Reciprocal rule for integration*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((c+d x^2)ArcTan[a x]) \[DifferentialD]x  \[LongRightArrow]  (Log[ArcTan[a x]]/(a c))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/((c_+d_.*x_^2)*ArcTan[a_.*x_]),x_Symbol] :=
  Log[ArcTan[a*x]]/(a*c) /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Power rule for integration*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (ArcTan[a x]^(n+1)/(a c(n+1)))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(c_+d_.*x_^2),x_Symbol] :=
  ArcTan[a*x]^(n+1)/(a*c*(n+1)) /;
FreeQ[{a,c,d,n},x] && ZeroQ[d-a^2*c] && NonzeroQ[n+1]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x/(1+a^2 x^2)=-(I/(a (1+a^2 x^2)))-1/(a (I-a x))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  -((I ArcTan[a x]^(n+1))/(d(n+1)))-1/(a c) \[Integral]ArcTan[a x]^n/(I-a x) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcTan[a_.*x_]^n_./(c_+d_.*x_^2),x_Symbol] :=
  -I*ArcTan[a*x]^(n+1)/(d*(n+1)) -
  Dist[1/(a*c),Int[ArcTan[a*x]^n/(I-a*x),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(x(1+a^2 x^2))=-((a I)/(1+a^2 x^2))+I/(x(I+a x))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(x(c+d x^2)) \[DifferentialD]x  \[LongRightArrow]  -((I ArcTan[a x]^(n+1))/(c(n+1)))+I/c \[Integral]ArcTan[a x]^n/(x(I+a x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(x_*(c_+d_.*x_^2)),x_Symbol] :=
  -I*ArcTan[a*x]^(n+1)/(c*(n+1)) +
  Dist[I/c,Int[ArcTan[a*x]^n/(x*(I+a*x)),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(x(1+a^2 x^2))=-((a I)/(1+a^2 x^2))+I/(x(I+a x))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c x+d x^3) \[DifferentialD]x  \[LongRightArrow]  -((I ArcTan[a x]^(n+1))/(c(n+1)))+I/c \[Integral]ArcTan[a x]^n/(x(I+a x)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_./(c_.*x_+d_.*x_^3),x_Symbol] :=
  -I*ArcTan[a*x]^(n+1)/(c*(n+1)) +
  Dist[I/c,Int[ArcTan[a*x]^n/(x*(I+a*x)),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^2/(c+d x^2)=1/d-c/(d (c+d x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m>1 \[And] n>0 , then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (1/d)\[Integral]x^(m-2) ArcTan[a x]^n \[DifferentialD]x-c/d \[Integral](x^(m-2) ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcTan[a_.*x_]^n_./(c_+d_.*x_^2),x_Symbol] :=
  Dist[1/d,Int[x^(m-2)*ArcTan[a*x]^n,x]] -
  Dist[c/d,Int[x^(m-2)*ArcTan[a*x]^n/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m>1 && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(c+d x^2)=1/c-(d x^2)/(c (c+d x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m<-1 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (1/c)\[Integral]x^m ArcTan[a x]^n \[DifferentialD]x-d/c \[Integral](x^(m+2) ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*ArcTan[a_.*x_]^n_./(c_+d_.*x_^2),x_Symbol] :=
  Dist[1/c,Int[x^m*ArcTan[a*x]^n,x]] -
  Dist[d/c,Int[x^(m+2)*ArcTan[a*x]^n/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m<-1 && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m\[Element]\[DoubleStruckCapitalZ] or a>0, (x^m ArcTan[a x]^n)/(1+a^2 x^2)=((Tan[ArcTan[a x]]^m) (ArcTan[a x]^n) )/a^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcTan[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] (m\[Element]\[DoubleStruckCapitalZ] \[Or] a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (1/(a^(m+1) c)) Subst[\[Integral]x^n Tan[x]^m \[DifferentialD]x,x,ArcTan[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_.*x_]^n_/(c_+d_.*x_^2),x_Symbol] :=
  Dist[1/(a^(m+1)*c),Subst[Int[x^n*Tan[x]^m,x],x,ArcTan[a*x]]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && (n<0 || Not[IntegerQ[n]]) && (IntegerQ[m] || PositiveQ[a])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: (x^m ArcTan[a x]^n)/(1+a^2 x^2)=1/a (Tan[ArcTan[a x]]/a)^m ArcTan[a x]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcTan[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] \[Not](m\[Element]\[DoubleStruckCapitalZ] \[Or] a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (1/(a c)) Subst[\[Integral]x^n (Tan[x]/a)^m \[DifferentialD]x,x,ArcTan[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_.*x_]^n_/(c_+d_.*x_^2),x_Symbol] :=
  Dist[1/(a*c),Subst[Int[x^n*(Tan[x]/a)^m,x],x,ArcTan[a*x]]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && (n<0 || Not[IntegerQ[n]]) && Not[IntegerQ[m] || PositiveQ[a]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](ArcTan[a x]^n ArcTanh[u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTanh[z]=1/2 Log[1+z]-1/2 Log[1-z]*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0 \[And] (u^2=(1-(2I)/(I+a x))^2 \[Or]  u^2=(1-(2I)/(I-a x))^2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcTan[a x]^n ArcTanh[u])/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (1/2) \[Integral](ArcTan[a x]^n Log[1+u])/(c+d x^2) \[DifferentialD]x-1/2 \[Integral](ArcTan[a x]^n Log[1-u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_.*ArcTanh[u_]/(c_+d_.*x_^2),x_Symbol] :=
  Dist[1/2,Int[ArcTan[a*x]^n*Log[1+u]/(c+d*x^2),x]] -
  Dist[1/2,Int[ArcTan[a*x]^n*Log[1-u]/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0 && (ZeroQ[u^2-(1-2*I/(I+a*x))^2] || ZeroQ[u^2-(1-2*I/(I-a*x))^2])


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](ArcTan[a x]^n Log[u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0 \[And] (1-u)^2=(1-(2I)/(I+a x))^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcTan[a x]^n Log[u])/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  (( I ArcTan[a x]^n PolyLog[2,1-u])/(2a c))-(n I)/2 \[Integral](ArcTan[a x]^(n-1) PolyLog[2,1-u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_.*Log[u_]/(c_+d_.*x_^2),x_Symbol] :=
  I*ArcTan[a*x]^n*PolyLog[2,1-u]/(2*a*c) -
  Dist[n*I/2,Int[ArcTan[a*x]^(n-1)*PolyLog[2,1-u]/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0 && ZeroQ[(1-u)^2-(1-2*I/(I+a*x))^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0 \[And] (1-u)^2=(1-(2I)/(I-a x))^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcTan[a x]^n Log[u])/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]  -((I ArcTan[a x]^n PolyLog[2,1-u])/(2a c))+(n I)/2 \[Integral](ArcTan[a x]^(n-1) PolyLog[2,1-u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_.*Log[u_]/(c_+d_.*x_^2),x_Symbol] :=
  -I*ArcTan[a*x]^n*PolyLog[2,1-u]/(2*a*c) +
  Dist[n*I/2,Int[ArcTan[a*x]^(n-1)*PolyLog[2,1-u]/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0 && ZeroQ[(1-u)^2-(1-2*I/(I-a*x))^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](ArcTan[a x]^n PolyLog[p,u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0 \[And] u^2=(1-(2I)/(I+a x))^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcTan[a x]^n PolyLog[p,u])/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                  *)
(*                                             -((I ArcTan[a x]^n PolyLog[p+1,u])/(2a c))+(n I)/2 \[Integral](ArcTan[a x]^(n-1) PolyLog[p+1,u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_.*PolyLog[p_,u_]/(c_+d_.*x_^2),x_Symbol] :=
  -I*ArcTan[a*x]^n*PolyLog[p+1,u]/(2*a*c) +
  Dist[n*I/2,Int[ArcTan[a*x]^(n-1)*PolyLog[p+1,u]/(c+d*x^2),x]] /;
FreeQ[{a,c,d,p},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0 && ZeroQ[u^2-(1-2*I/(I+a*x))^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>0 \[And] u^2=(1-(2I)/(I-a x))^2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcTan[a x]^n PolyLog[p,u])/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                 *)
(*                                                ((I ArcTan[a x]^n PolyLog[p+1,u])/(2a c))-(n I)/2 \[Integral](ArcTan[a x]^(n-1) PolyLog[p+1,u])/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_.*PolyLog[p_,u_]/(c_+d_.*x_^2),x_Symbol] :=
  I*ArcTan[a*x]^n*PolyLog[p+1,u]/(2*a*c) -
  Dist[n*I/2,Int[ArcTan[a*x]^(n-1)*PolyLog[p+1,u]/(c+d*x^2),x]] /;
FreeQ[{a,c,d,p},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>0 && ZeroQ[u^2-(1-2*I/(I-a*x))^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](ArcCot[a x]^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/((c+d x^2) ArcCot[a x] ArcTan[a x]) \[DifferentialD]x  \[LongRightArrow]  ((-Log[ArcCot[a x]]+Log[ArcTan[a x]])/(a c ArcCot[a x]+a c ArcTan[a x]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(ArcCot[a_.*x_]*ArcTan[a_.*x_]*(c_+d_.*x_^2)),x_Symbol] :=
  (-Log[ArcCot[a*x]]+Log[ArcTan[a*x]])/(a*c*ArcCot[a*x]+a*c*ArcTan[a*x]) /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalZ] \[And] 0<n<=m, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](ArcCot[a x]^m ArcTan[a x]^n)/(c+d x^2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                               *)
(*                                               -((ArcCot[a x]^(m+1) ArcTan[a x]^n)/(a c(m+1)))+n/(m+1) \[Integral](ArcCot[a x]^(m+1) ArcTan[a x]^(n-1))/(c+d x^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcCot[a_.*x_]^m_.*ArcTan[a_.*x_]^n_./(c_+d_.*x_^2),x_Symbol] :=
  -ArcCot[a*x]^(m+1)*ArcTan[a*x]^n/(a*c*(m+1)) +
  Dist[n/(m+1),Int[ArcCot[a*x]^(m+1)*ArcTan[a*x]^(n-1)/(c+d*x^2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n] && 0<n<=m


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] c>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]/Sqrt[c+d x^2] \[DifferentialD]x  \[LongRightArrow]  -((2 I ArcTan[a x]ArcTan[Sqrt[1+I a x]/Sqrt[1-I a x]])/(a Sqrt[c]))+(I PolyLog[2,-((I Sqrt[1+I a x])/Sqrt[1-I a x])])/(a Sqrt[c])-(I PolyLog[2,(I Sqrt[1+I a x])/Sqrt[1-I a x]])/(a Sqrt[c])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]/Sqrt[c_+d_.*x_^2],x_Symbol] :=
  -2*I*ArcTan[a*x]*ArcTan[Sqrt[1+I*a*x]/Sqrt[1-I*a*x]]/(a*Sqrt[c]) + 
  I*PolyLog[2,-I*Sqrt[1+I*a*x]/Sqrt[1-I*a*x]]/(a*Sqrt[c]) -
  I*PolyLog[2,I*Sqrt[1+I*a*x]/Sqrt[1-I*a*x]]/(a*Sqrt[c]) /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && PositiveQ[c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]*)
(*\*FractionBox[*)
(*SqrtBox[\(1 + *)
(*\*SuperscriptBox[\(a\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)], *)
(*SqrtBox[\(c\  + c\ *)
(*\*SuperscriptBox[\(a\), \(2\)]\ *)
(*\*SuperscriptBox[\(x\), \(2\)]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]/Sqrt[c+d x^2] \[DifferentialD]x  \[LongRightArrow]  (Sqrt[1+a^2 x^2]/Sqrt[c+d x^2])\[Integral]ArcTan[a x]/Sqrt[1+a^2 x^2] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]/Sqrt[c_+d_.*x_^2],x_Symbol] :=
  Sqrt[1+a^2*x^2]/Sqrt[c+d*x^2]*Int[ArcTan[a*x]/Sqrt[1+a^2*x^2],x] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && Not[PositiveQ[c]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]/(c+d x^2)^(3/2) \[DifferentialD]x  \[LongRightArrow]  (1/(a c Sqrt[c+d x^2]))+(x ArcTan[a x])/(c Sqrt[c+d x^2])*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]/(c_+d_.*x_^2)^(3/2),x_Symbol] :=
  1/(a*c*Sqrt[c+d*x^2]) +
  x*ArcTan[a*x]/(c*Sqrt[c+d*x^2]) /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x^2)^(3/2) \[DifferentialD]x  \[LongRightArrow]  ((n ArcTan[a x]^(n-1))/(a c Sqrt[c+d x^2]))+(x ArcTan[a x]^n)/(c Sqrt[c+d x^2])-n(n-1)\[Integral]ArcTan[a x]^(n-2)/(c+d x^2)^(3/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_/(c_+d_.*x_^2)^(3/2),x_Symbol] :=
  n*ArcTan[a*x]^(n-1)/(a*c*Sqrt[c+d*x^2]) +
  x*ArcTan[a*x]^n/(c*Sqrt[c+d*x^2]) -
  Dist[n*(n-1),Int[ArcTan[a*x]^(n-2)/(c+d*x^2)^(3/2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a x]^n/(c+d x^2)^(3/2) \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                       *)
(*                        (ArcTan[a x]^(n+1)/(a c (n+1) Sqrt[c+d x^2]))+(x ArcTan[a x]^(n+2))/(c (n+1) (n+2) Sqrt[c+d x^2])-1/((n+1)(n+2)) \[Integral]ArcTan[a x]^(n+2)/(c+d x^2)^(3/2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.*x_]^n_/(c_+d_.*x_^2)^(3/2),x_Symbol] :=
  ArcTan[a*x]^(n+1)/(a*c*(n+1)*Sqrt[c+d*x^2]) +
  x*ArcTan[a*x]^(n+2)/(c*(n+1)*(n+2)*Sqrt[c+d*x^2]) -
  Dist[1/((n+1)*(n+2)),Int[ArcTan[a*x]^(n+2)/(c+d*x^2)^(3/2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]\[DifferentialD]x  \[LongRightArrow]                                                                                                                                    *)
(*                                      -((c+d x^2)^m/(2 a m(2m+1)))+(x (c+d x^2)^m ArcTan[a x])/(2m+1)+(2 c m)/(2 m+1) \[Integral](c+d x^2)^(m-1) ArcTan[a x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_.*ArcTan[a_.*x_],x_Symbol] :=
  -(c+d*x^2)^m/(2*a*m*(2*m+1)) +
  x*(c+d*x^2)^m*ArcTan[a*x]/(2*m+1) +
  Dist[2*c*m/(2*m+1),Int[(c+d*x^2)^(m-1)*ArcTan[a*x],x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[m] && m>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m<-1 \[And] m!=-(3/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]\[DifferentialD]x  \[LongRightArrow]                                                                                                                                   *)
(*                            ((c+d x^2)^(m+1)/(4 a c (m+1)^2))-(x (c+d x^2)^(m+1) ArcTan[a x])/(2c(m+1))+(2m+3)/(2 c(m+1)) \[Integral](c+d x^2)^(m+1) ArcTan[a x]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_*ArcTan[a_.*x_],x_Symbol] :=
  (c+d*x^2)^(m+1)/(4*a*c*(m+1)^2) -
  x*(c+d*x^2)^(m+1)*ArcTan[a*x]/(2*c*(m+1)) +
  Dist[(2*m+3)/(2*c*(m+1)),Int[(c+d*x^2)^(m+1)*ArcTan[a*x],x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[m] && m<-1 && m!=-3/2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m<-1 \[And] m!=-(3/2) \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*	\[Integral](c+d x^2)^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  *)
(*	((n (c+d x^2)^(m+1) ArcTan[a x]^(n-1))/(4 a c (m+1)^2))-(x (c+d x^2)^(m+1) ArcTan[a x]^n)/(2 c(m+1))+*)
(*		(2 m+3)/(2 c(m+1)) \[Integral](c+d x^2)^(m+1) ArcTan[a x]^n \[DifferentialD]x-(n(n-1))/(4(m+1)^2) \[Integral](c+d x^2)^m ArcTan[a x]^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  n*(c+d*x^2)^(m+1)*ArcTan[a*x]^(n-1)/(4*a*c*(m+1)^2) -
  x*(c+d*x^2)^(m+1)*ArcTan[a*x]^n/(2*c*(m+1)) +
  Dist[(2*m+3)/(2*c*(m+1)),Int[(c+d*x^2)^(m+1)*ArcTan[a*x]^n,x]] -
  Dist[n*(n-1)/(4*(m+1)^2),Int[(c+d*x^2)^m*ArcTan[a*x]^(n-2),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m<-1 && m!=-3/2 && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If   d=a^2 c \[And] m<-1 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                  *)
(*                                  (((c+d x^2)^(m+1) ArcTan[a x]^(n+1))/(a c(n+1)))-(2 a (m+1))/(n+1)  \[Integral]x (c+d x^2)^m ArcTan[a x]^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  (c+d*x^2)^(m+1)*ArcTan[a*x]^(n+1)/(a*c*(n+1)) -
  Dist[2*a*(m+1)/(n+1),Int[x*(c+d*x^2)^m*ArcTan[a*x]^(n+1),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m<-1 && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: (1+a^2 x^2)^m ArcTan[a x]^n=1/a Sec[ArcTan[a x]]^(2(m+1)) ArcTan[a x]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcTan[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] m<-1 \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] (m\[Element]\[DoubleStruckCapitalZ] \[Or] c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (c^m/a) Subst[\[Integral]x^n Sec[x]^(2(m+1)) \[DifferentialD]x,x,ArcTan[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  Dist[c^m/a,Subst[Int[x^n*Sec[x]^(2*(m+1)),x],x,ArcTan[a*x]]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m<-1 && (n<0 || Not[IntegerQ[n]]) && (IntegerQ[m] || PositiveQ[c])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Basis: If d=a^2 c, D[(c^(m-1/2) Sqrt[c+d x^2])/Sqrt[1+a^2 x^2],x]=0*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] m<-1 \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] m-1/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](c+d x^2)^m ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((c^(m-1/2) Sqrt[c+d x^2])/Sqrt[1+a^2 x^2])\[Integral](1+a^2 x^2)^m ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(c_+d_.*x_^2)^m_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  c^(m-1/2)*Sqrt[c+d*x^2]/Sqrt[1+a^2*x^2]*Int[(1+a^2*x^2)^m*ArcTan[a*x]^n,x] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n}] && m<-1 && (n<0 || Not[IntegerQ[n]]) && IntegerQ[m-1/2] && Not[PositiveQ[c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] p\[Element]\[DoubleStruckCapitalQ] \[And] n>0 \[And] p!=-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (((c+d x^2)^(p+1) ArcTan[a x]^n)/(2 d(p+1)))-n/(2 a(p+1)) \[Integral](c+d x^2)^p ArcTan[a x]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(c_+d_.*x_^2)^p_.*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  (c+d*x^2)^(p+1)*ArcTan[a*x]^n/(2*d*(p+1)) -
  Dist[n/(2*a*(p+1)),Int[(c+d*x^2)^p*ArcTan[a*x]^(n-1),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{n,p}] && n>0 && p!=-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] p\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x (c+d x^2)^p)/ArcTan[a x]^2 \[DifferentialD]x  \[LongRightArrow]  -((x (c+d x^2)^(p+1))/(a c ArcTan[a x]))+1/a \[Integral]((1+(2 p+3) a^2 x^2) (c+d x^2)^p)/ArcTan[a x] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*(c_+d_.*x_^2)^p_./ArcTan[a_.*x_]^2,x_Symbol] :=
  -x*(c+d*x^2)^(p+1)/(a*c*ArcTan[a*x]) +
  Dist[1/a,Int[(1+(2*p+3)*a^2*x^2)*(c+d*x^2)^p/ArcTan[a*x],x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[p]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](x ArcTan[a x]^n)/(c+d x^2)^2 \[DifferentialD]x  \[LongRightArrow]                                                                                                                                                          *)
(*                ((x ArcTan[a x]^(n+1))/(a c (n+1) (c+d x^2)))-((1-a^2 x^2) ArcTan[a x]^(n+2))/(d (n+1) (n+2) (c+d x^2))-4/((n+1)(n+2)) \[Integral](x ArcTan[a x]^(n+2))/(c+d x^2)^2 \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_*ArcTan[a_.*x_]^n_/(c_+d_.*x_^2)^2,x_Symbol] :=
  x*ArcTan[a*x]^(n+1)/(a*c*(n+1)*(c+d*x^2)) -
  (1-a^2*x^2)*ArcTan[a*x]^(n+2)/(d*(n+1)*(n+2)*(c+d*x^2)) -
  Dist[4/((n+1)*(n+2)),Int[x*ArcTan[a*x]^(n+2)/(c+d*x^2)^2,x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] m+2p+3=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]                                                                                                                                    *)
(*                                      ((x^(m+1) (c+d x^2)^(p+1) ArcTan[a x]^n)/(c(m+1)))-(a n)/(m+1) \[Integral]x^(m+1) (c+d x^2)^p ArcTan[a x]^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(c_+d_.*x_^2)^p_.*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^(m+1)*(c+d*x^2)^(p+1)*ArcTan[a*x]^n/(c*(m+1)) -
  Dist[a*n/(m+1),Int[x^(m+1)*(c+d*x^2)^p*ArcTan[a*x]^(n-1),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && m<-1 && n>0 && ZeroQ[m+2*p+3]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] n<-1 \[And] m+2p+2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x \[LongRightArrow]                                                                                                                                     *)
(*                                   ((x^m (c+d x^2)^(p+1) ArcTan[a x]^(n+1))/(a c(n+1)))-m/(a (n+1)) \[Integral]x^(m-1) (c+d x^2)^p ArcTan[a x]^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(c_+d_.*x_^2)^p_.*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^m*(c+d*x^2)^(p+1)*ArcTan[a*x]^(n+1)/(a*c*(n+1)) -
  Dist[m/(a*(n+1)),Int[x^(m-1)*(c+d*x^2)^p*ArcTan[a*x]^(n+1),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && n<-1 && ZeroQ[m+2*p+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: x^2/(c+d x^2)=1/d-c/(d (c+d x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] m>1 \[And] n!=-1 \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (1/d)\[Integral]x^(m-2) (c+d x^2)^(p+1) ArcTan[a x]^n \[DifferentialD]x-c/d \[Integral]x^(m-2) (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(c_+d_.*x_^2)^p_*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  Dist[1/d,Int[x^(m-2)*(c+d*x^2)^(p+1)*ArcTan[a*x]^n,x]] -
  Dist[c/d,Int[x^(m-2)*(c+d*x^2)^p*ArcTan[a*x]^n,x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && m>1 && n!=-1 && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: 1/(c+d x^2)=1/c-(d x^2)/(c (c+d x^2))*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] m<0 \[And] n!=-1 \[And] p<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (1/c)\[Integral]x^m (c+d x^2)^(p+1) ArcTan[a x]^n \[DifferentialD]x-d/c \[Integral]x^(m+2) (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(c_+d_.*x_^2)^p_*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  Dist[1/c,Int[x^m*(c+d*x^2)^(p+1)*ArcTan[a*x]^n,x]] -
  Dist[d/c,Int[x^(m+2)*(c+d*x^2)^p*ArcTan[a*x]^n,x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && m<0 && n!=-1 && p<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] m<-1 \[And] n>0 \[And] m+2p+3!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) (c+d x^2)^(p+1) ArcTan[a x]^n)/(c(m+1)))-                                                                *)
(*(a n)/(m+1) \[Integral]x^(m+1) (c+d x^2)^p ArcTan[a x]^(n-1) \[DifferentialD]x-(a^2 (m+2p+3))/( m+1) \[Integral]x^(m+2) (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_*(c_+d_.*x_^2)^p_.*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^(m+1)*(c+d*x^2)^(p+1)*ArcTan[a*x]^n/(c*(m+1)) -
  Dist[a*n/(m+1),Int[x^(m+1)*(c+d*x^2)^p*ArcTan[a*x]^(n-1),x]] -
  Dist[a^2*(m+2*p+3)/(m+1),Int[x^(m+2)*(c+d*x^2)^p*ArcTan[a*x]^n,x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && m<-1 && n>0 && NonzeroQ[m+2*p+3]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,2p\[Element]\[DoubleStruckCapitalZ] \[And] n<-1 \[And] m+2p+2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x \[LongRightArrow]  ((x^m (c+d x^2)^(p+1) ArcTan[a x]^(n+1))/(a c(n+1)))-                                                                       *)
(*m/(a (n+1)) \[Integral]x^(m-1) (c+d x^2)^p ArcTan[a x]^(n+1) \[DifferentialD]x-(a(m+2p+2))/(n+1) \[Integral]x^(m+1) (c+d x^2)^p ArcTan[a x]^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_+d_.*x_^2)^p_.*ArcTan[a_.*x_]^n_.,x_Symbol] :=
  x^m*(c+d*x^2)^(p+1)*ArcTan[a*x]^(n+1)/(a*c*(n+1)) -
  Dist[m/(a*(n+1)),Int[x^(m-1)*(c+d*x^2)^p*ArcTan[a*x]^(n+1),x]] -
  Dist[a*(m+2*p+2)/(n+1),Int[x^(m+1)*(c+d*x^2)^p*ArcTan[a*x]^(n+1),x]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && IntegersQ[m,n,2*p] && n<-1 && NonzeroQ[m+2*p+2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If m\[Element]\[DoubleStruckCapitalZ] or a>0, (e+f x^m)(1+a^2 x^2)^p ArcTan[a x]^n=1/a^(m+1) (e a^m+f Tan[ArcTan[a x]]^m)Sec[ArcTan[a x]]^(2(p+1)) ArcTan[a x]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcTan[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n,p\[Element]\[DoubleStruckCapitalQ] \[And] p<-1 \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] (p\[Element]\[DoubleStruckCapitalZ] \[Or] c>0) \[And] (m\[Element]\[DoubleStruckCapitalZ] \[Or] a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](e+f x^m)(c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (c^p/a^(m+1)) Subst[\[Integral]x^n (e a^m+f Tan[x]^m) Sec[x]^(2(p+1)) \[DifferentialD]x,x,ArcTan[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(e_.+f_.*x_^m_.)*(c_+d_.*x_^2)^p_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  Dist[c^p/a^(m+1),Subst[Int[Expand[x^n*TrigReduce[Regularize[(e*a^m+f*Tan[x]^m)*Sec[x]^(2*(p+1)),x]]],x],x,ArcTan[a*x]]] /;
FreeQ[{a,c,d,e,f},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n,p}] && p<-1 && (n<0 || Not[IntegerQ[n]]) && (IntegerQ[p] || PositiveQ[c]) && (IntegerQ[m] || PositiveQ[a])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: x^m (1+a^2 x^2)^p ArcTan[a x]^n=1/a (Tan[ArcTan[a x]]/a)^m Sec[ArcTan[a x]]^(2(p+1)) ArcTan[a x]^n \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]\(ArcTan[a\ x]\)\)*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] p<-1 \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] (p\[Element]\[DoubleStruckCapitalZ] \[Or] c>0) \[And] \[Not](m\[Element]\[DoubleStruckCapitalZ] \[Or] a>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  (c^p/a) Subst[\[Integral]x^n (Tan[x]/a)^m Sec[x]^(2(p+1)) \[DifferentialD]x,x,ArcTan[a x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_+d_.*x_^2)^p_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  Dist[c^p/a,Subst[Int[x^n*(Tan[x]/a)^m*Sec[x]^(2*(p+1)),x],x,ArcTan[a*x]]] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n,p}] && p<-1 && (n<0 || Not[IntegerQ[n]]) && (IntegerQ[p] || PositiveQ[c]) && Not[IntegerQ[m] || PositiveQ[a]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Basis: If d=a^2 c, D[(c^(p-1/2) Sqrt[c+d x^2])/Sqrt[1+a^2 x^2],x]=0*)


(* ::Subsubsection:: *)
(*Rule: If  d=a^2 c \[And] m,n\[Element]\[DoubleStruckCapitalQ] \[And] p<-1 \[And] (n<0 \[Or] n\[NotElement]\[DoubleStruckCapitalZ]) \[And] p-1/2\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](c>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m (c+d x^2)^p ArcTan[a x]^n \[DifferentialD]x  \[LongRightArrow]  ((c^(p-1/2) Sqrt[c+d x^2])/Sqrt[1+a^2 x^2])\[Integral]x^m (1+a^2 x^2)^p ArcTan[a x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*(c_+d_.*x_^2)^p_*ArcTan[a_.*x_]^n_,x_Symbol] :=
  c^(p-1/2)*Sqrt[c+d*x^2]/Sqrt[1+a^2*x^2]*Int[x^m*(1+a^2*x^2)^p*ArcTan[a*x]^n,x] /;
FreeQ[{a,c,d},x] && ZeroQ[d-a^2*c] && RationalQ[{m,n,p}] && p<-1 && (n<0 || Not[IntegerQ[n]]) && IntegerQ[p-1/2] && Not[PositiveQ[c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.822.1, CRC 443, A&S 4.4.60*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b x]\[DifferentialD]x  \[LongRightArrow]  (((a+b x) ArcTan[a+b x])/b)-Log[1+(a+b x)^2]/(2 b)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_+b_.*x_],x_Symbol] :=
  (a+b*x)*ArcTan[a+b*x]/b - Log[1+(a+b*x)^2]/(2*b) /;
FreeQ[{a,b},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.822.1, CRC 443, A&S 4.4.60*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalQ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  x ArcTan[a+b x^n]-b n \[Integral]x^n/(1+a^2+2 a b x^n+b^2 x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_+b_.*x_^n_],x_Symbol] :=
  x*ArcTan[a+b*x^n] -
  Dist[b*n,Int[x^n/(1+a^2+2*a*b*x^n+b^2*x^(2*n)),x]] /;
FreeQ[{a,b},x] && RationalQ[n]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcTan[a+b x^n]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=1/2 I Log[1-I z]-1/2 I Log[1+I z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b x^n]/x \[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]Log[1-I a-I b x^n]/x \[DifferentialD]x-I/2 \[Integral]Log[1+I a+I b x^n]/x \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.+b_.*x_^n_.]/x_,x_Symbol] :=
  Dist[I/2,Int[Log[1-I*a-I*b*x^n]/x,x]] -
  Dist[I/2,Int[Log[1+I*a+I*b*x^n]/x,x]] /;
FreeQ[{a,b,n},x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.851, CRC 456, A&S 4.4.69*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalQ] \[And] m+1!=0 \[And] m+1!=n, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcTan[a+b x^n]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcTan[a+b x^n])/(m+1))-(b n)/(m+1) \[Integral]x^(m+n)/(1+a^2+2 a b x^n+b^2 x^(2 n)) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_+b_.*x_^n_.],x_Symbol] :=
  x^(m+1)*ArcTan[a+b*x^n]/(m+1) -
  Dist[b*n/(m+1),Int[x^(m+n)/(1+a^2+2*a*b*x^n+b^2*x^(2*n)),x]] /;
FreeQ[{a,b},x] && RationalQ[{m,n}] && m+1!=0 && m+1!=n


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral]ArcTan[x]^n \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b,Subst[Int[ArcTan[x]^n,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegerQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcTan[a+b x]^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Rule: If  m,n\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcTan[a+b x]^n \[DifferentialD]x  \[LongRightArrow]  (1/b^(m+1)) Subst[\[Integral](x-a)^m ArcTan[x]^n \[DifferentialD]x,x,a+b x]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_+b_.*x_]^n_,x_Symbol] :=
  Dist[1/b^(m+1),Subst[Int[(x-a)^m*ArcTan[x]^n,x],x,a+b*x]] /;
FreeQ[{a,b},x] && IntegersQ[m,n] && m>0 && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a+b x]/(c+d x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=1/2 I Log[1-I z]-1/2 I Log[1+I z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](n=2\[And]d=b^2 c), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[b x]/(c+d x^n) \[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]Log[1-I b x]/(c+d x^n) \[DifferentialD]x-I/2 \[Integral]Log[1+I b x]/(c+d x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[b_.*x_]/(c_+d_.*x_^n_.),x_Symbol] :=
  Dist[I/2,Int[Log[1-I*b*x]/(c+d*x^n),x]] -
  Dist[I/2,Int[Log[1+I*b*x]/(c+d*x^n),x]] /;
FreeQ[{b,c,d},x] && IntegerQ[n] && Not[n==2 && ZeroQ[d-b^2*c]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=1/2 I Log[1-I z]-1/2 I Log[1+I z]*)


(* ::Subsubsection:: *)
(*Rule: If  n\[Element]\[DoubleStruckCapitalZ] \[And] \[Not](n=1\[And]a d-b c=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b x]/(c+d x^n) \[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]Log[1-I a-I b x]/(c+d x^n) \[DifferentialD]x-I/2 \[Integral]Log[1+I a+I b x]/(c+d x^n) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_+b_.*x_]/(c_+d_.*x_^n_.),x_Symbol] :=
  Dist[I/2,Int[Log[1-I*a-I*b*x]/(c+d*x^n),x]] -
  Dist[I/2,Int[Log[1+I*a+I*b*x]/(c+d*x^n),x]] /;
FreeQ[{a,b,c,d},x] && IntegerQ[n] && Not[n==1 && ZeroQ[a*d-b*c]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]u ArcTan[c/(a+b x^n)]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=ArcCot[1/z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]u ArcTan[c/(a+b x^n)]^m \[DifferentialD]x  \[LongRightArrow]  \[Integral]u ArcCot[a/c+(b x^n)/c]^m \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*ArcTan[c_./(a_.+b_.*x_^n_.)]^m_.,x_Symbol] :=
  Int[u*ArcCot[a/c+b*x^n/c]^m,x] /;
FreeQ[{a,b,c,n,m},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]f[x,ArcTan[a+b x]]/(1-(a+b x)^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: f[z]/(1+z^2)=f[Tan[ArcTan[z]]] Derivative[1][ArcTan][z]*)


(* ::Subsubsection:: *)
(*Basis: r+s x+t x^2=-((s^2-4 r t)/(4 t)) (1-(s+2 t x)^2/(s^2-4 r t))*)


(* ::Subsubsection:: *)
(*Basis: 1+Tan[z]^2=Sec[z]^2*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]f[x,ArcTan[a+b x]]/(1+(a+b x)^2) \[DifferentialD]x  \[LongRightArrow]  (1/b) Subst[\[Integral]f[-(a/b)+Tan[x]/b,x]\[DifferentialD]x,x,ArcTan[a+b x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
If[ShowSteps,

Int[u_*v_^n_.,x_Symbol] :=
  Module[{tmp=InverseFunctionOfLinear[u,x]},
  ShowStep["","Int[f[x,ArcTan[a+b*x]]/(1+(a+b*x)^2),x]",
		   "Subst[Int[f[-a/b+Tan[x]/b,x],x],x,ArcTan[a+b*x]]/b",Hold[
  Dist[(-Discriminant[v,x]/(4*Coefficient[v,x,2]))^n/Coefficient[tmp[[1]],x,1],
	Subst[Int[Regularize[SubstForInverseFunction[u,tmp,x]*Sec[x]^(2*(n+1)),x],x], x, tmp]]]] /;
 NotFalseQ[tmp] && Head[tmp]===ArcTan && ZeroQ[Discriminant[v,x]*tmp[[1]]^2+D[v,x]^2]] /;
SimplifyFlag && QuadraticQ[v,x] && IntegerQ[n] && n<0 && NegQ[Discriminant[v,x]] && MatchQ[u,r_.*f_^w_ /; FreeQ[f,x]],

Int[u_*v_^n_.,x_Symbol] :=
  Module[{tmp=InverseFunctionOfLinear[u,x]},
  Dist[(-Discriminant[v,x]/(4*Coefficient[v,x,2]))^n/Coefficient[tmp[[1]],x,1],
	Subst[Int[Regularize[SubstForInverseFunction[u,tmp,x]*Sec[x]^(2*(n+1)),x],x], x, tmp]] /;
 NotFalseQ[tmp] && Head[tmp]===ArcTan && ZeroQ[Discriminant[v,x]*tmp[[1]]^2+D[v,x]^2]] /;
QuadraticQ[v,x] && IntegerQ[n] && n<0 && NegQ[Discriminant[v,x]] && MatchQ[u,r_.*f_^w_ /; FreeQ[f,x]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]ArcTan[a+b f^(c+d x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=1/2 I Log[1-I z]-1/2 I Log[1+I z]*)


(* ::Subsubsection:: *)
(*Rule:*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[a+b f^(c+d x)]\[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]Log[1-I (a+b f^(c+d x))]\[DifferentialD]x-I/2 \[Integral]Log[1+I (a+b f^(c+d x))]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[a_.+b_.*f_^(c_.+d_.*x_)],x_Symbol] :=
  Dist[I/2,Int[Log[1-I*a-I*b*f^(c+d*x)],x]] -
  Dist[I/2,Int[Log[1+I*a+I*b*f^(c+d*x)],x]] /;
FreeQ[{a,b,c,d,f},x]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]x^m ArcTan[a+b f^(c+d x)]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: ArcTan[z]=1/2 I Log[1-I z]-1/2 I Log[1+I z]*)


(* ::Subsubsection:: *)
(*Rule: If  m\[Element]\[DoubleStruckCapitalZ] \[And] m>0, then*)


(* ::Subtitle::Bold:: *)
(*\[Integral]x^m ArcTan[b f^(c+d x)]\[DifferentialD]x  \[LongRightArrow]  (I/2)\[Integral]x^m Log[1-I (a+b f^(c+d x))]\[DifferentialD]x-I/2 \[Integral]x^m Log[1+I (a+b f^(c+d x))]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[a_.+b_.*f_^(c_.+d_.*x_)],x_Symbol] :=
  Dist[I/2,Int[x^m*Log[1-I*a-I*b*f^(c+d*x)],x]] -
  Dist[I/2,Int[x^m*Log[1+I*a+I*b*f^(c+d*x)],x]] /;
FreeQ[{a,b,c,d,f},x] && IntegerQ[m] && m>0


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]v ArcTan[u]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]ArcTan[u]\[DifferentialD]x  \[LongRightArrow]  x ArcTan[u]-\[Integral](x \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(1+u^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[ArcTan[u_],x_Symbol] :=
  x*ArcTan[u] -
  Int[Regularize[x*D[u,x]/(1+u^2),x],x] /;
InverseFunctionFreeQ[u,x]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If  m+1!=0\[And] u is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]x^m ArcTan[u]\[DifferentialD]x  \[LongRightArrow]  ((x^(m+1) ArcTan[u])/(m+1))-1/(m+1) \[Integral](x^(m+1) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(1+u^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[x_^m_.*ArcTan[u_],x_Symbol] :=
  x^(m+1)*ArcTan[u]/(m+1) -
  Dist[1/(m+1),Int[Regularize[x^(m+1)*D[u,x]/(1+u^2),x],x]] /;
FreeQ[m,x] && NonzeroQ[m+1] && InverseFunctionFreeQ[u,x] && 
	Not[FunctionOfQ[x^(m+1),u,x]] && 
	FalseQ[PowerVariableExpn[u,m+1,x]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts*)


(* ::Subsubsection:: *)
(*Rule: If u is free of inverse functions, let  w=\[Integral]v \[DifferentialD]x, if w is free of inverse functions, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]v ArcTan[u]\[DifferentialD]x  \[LongRightArrow]  w ArcTan[u]-\[Integral](w \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(x\)]u\))/(1+u^2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[v_*ArcTan[u_],x_Symbol] :=
  Module[{w=Block[{ShowSteps=False,StepCounter=Null}, Int[v,x]]},  
  w*ArcTan[u] -
  Int[Regularize[w*D[u,x]/(1+u^2),x],x] /;
 InverseFunctionFreeQ[w,x]] /;
InverseFunctionFreeQ[u,x] && 
	Not[MatchQ[v, x^m_. /; FreeQ[m,x]]] &&
	FalseQ[FunctionOfLinear[v*ArcTan[u],x]]
