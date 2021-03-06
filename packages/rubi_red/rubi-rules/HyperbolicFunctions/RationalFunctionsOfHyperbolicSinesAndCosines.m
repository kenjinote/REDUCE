(* ::Package:: *)

(* ::Title::Bold::Closed:: *)
(*\[Integral](a Cosh[c+d x]+b Sinh[c+d x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Cosh[c+d x]+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  ((a (a Cosh[c+d x]+b Sinh[c+d x])^n)/(b d n))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  a*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^n/(b*d*n) /;
FreeQ[{a,b,c,d,n},x] && ZeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a Cosh[c+d x]+b Sinh[c+d x])^2 \[DifferentialD]x  \[LongRightArrow]  (Sinh[c+d x]/(a d (a Cosh[c+d x]+b Sinh[c+d x])))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^2,x_Symbol] :=
  Sinh[c+d*x]/(a*d*(a*Cosh[c+d*x]+b*Sinh[c+d*x])) /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.449'*)


(* ::Subsubsection:: *)
(*Derivation: Integration by substitution*)


(* ::Subsubsection:: *)
(*Basis: If  (n-1)/2\[Element]\[DoubleStruckCapitalZ], then (a Cosh[z]+b Sinh[z])^n=(a^2-b^2+(b Cosh[z]+a Sinh[z])^2)^((n-1)/2) \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]\((b\ Cosh[z] + a\ Sinh[z])\)\)*)


(* ::Subsubsection:: *)
(*Note: For odd n<-1, might as well stay in the hyperbolic world using 2nd rule below. (???)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] (n-1)/2\[Element]\[DoubleStruckCapitalZ] \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Cosh[c+d x]+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(1/d)Subst[Int[(a^2-b^2+x^2)^((n-1)/2),x],x,b Cosh[c+d x]+a Sinh[c+d x]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  Dist[1/d,Subst[Int[Regularize[(a^2-b^2+x^2)^((n-1)/2),x],x],x,b*Cosh[c+d*x]+a*Sinh[c+d*x]]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && OddQ[n] && n>0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n>1 \[And] (n-1)/2\[NotElement]\[DoubleStruckCapitalZ], then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Cosh[c+d x]+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((b Cosh[c+d x]+a Sinh[c+d x]) (a Cosh[c+d x]+b Sinh[c+d x])^(n-1))/(d n))+*)
(*((n-1) (a^2-b^2))/n \[Integral](a Cosh[c+d x]+b Sinh[c+d x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  (b*Cosh[c+d*x]+a*Sinh[c+d*x])*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(n-1)/(d*n) +
  Dist[(n-1)*(a^2-b^2)/n,Int[(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(n-2),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n>1 && Not[OddQ[n]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Integration by parts with a double-back flip*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a Cosh[c+d x]+b Sinh[c+d x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((b Cosh[c+d x]+a Sinh[c+d x]) (a Cosh[c+d x]+b Sinh[c+d x])^(n+1))/(d (n+1) (a^2-b^2)))+*)
(*(n+2)/((n+1) (a^2-b^2)) \[Integral](a Cosh[c+d x]+b Sinh[c+d x])^(n+2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^n_,x_Symbol] :=
  -(b*Cosh[c+d*x]+a*Sinh[c+d*x])*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(n+1)/(d*(n+1)*(a^2-b^2)) +
  Dist[(n+2)/((n+1)*(a^2-b^2)),Int[(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(n+2),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && RationalQ[n] && n<-1 && n!=-2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](Cosh[c+d x]^m Sinh[c+d x]^n)/(a Cosh[c+d x]+b Sinh[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: (Cosh[z] Sinh[z])/(a Cosh[z]+b Sinh[z])=-((b Cosh[z])/(a^2-b^2))+(a Sinh[z])/(a^2-b^2)+(a b)/((a^2-b^2) (a Cosh[z]+b Sinh[z]))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] m,n,p\[Element]\[DoubleStruckCapitalZ] \[And] m>0 \[And] n>0 \[And] p<0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Cosh[c+d x]^m Sinh[c+d x]^n (a Cosh[c+d x]+b Sinh[c+d x])^p \[DifferentialD]x  \[LongRightArrow]                                        *)
(*-(b/(a^2-b^2))\[Integral]Cosh[c+d x]^m Sinh[c+d x]^(n-1) (a Cosh[c+d x]+b Sinh[c+d x])^(p+1) \[DifferentialD]x+*)
(*a/(a^2-b^2) \[Integral]Cosh[c+d x]^(m-1) Sinh[c+d x]^n (a Cosh[c+d x]+b Sinh[c+d x])^(p+1) \[DifferentialD]x+*)
(*(a b)/(a^2-b^2) \[Integral]Cosh[c+d x]^(m-1) Sinh[c+d x]^(n-1) (a Cosh[c+d x]+b Sinh[c+d x])^p \[DifferentialD]x    *)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Cosh[c_.+d_.*x_]^m_.*Sinh[c_.+d_.*x_]^n_.*(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_])^p_,x_Symbol] :=
  -Dist[b/(a^2-b^2),Int[Cosh[c+d*x]^m*Sinh[c+d*x]^(n-1)*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(p+1),x]] +
  Dist[a/(a^2-b^2),Int[Cosh[c+d*x]^(m-1)*Sinh[c+d*x]^n*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^(p+1),x]] +
  Dist[a*b/(a^2-b^2),Int[Cosh[c+d*x]^(m-1)*Sinh[c+d*x]^(n-1)*(a*Cosh[c+d*x]+b*Sinh[c+d*x])^p,x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && IntegersQ[m,n,p] && m>0 && n>0 && p<0


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Sinh[z]^2/(a Cosh[z]+b Sinh[z])=-((b Sinh[z])/(a^2-b^2))+(a Cosh[z])/(a^2-b^2)-a^2/((a^2-b^2) (a Cosh[z]+b Sinh[z]))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u Sinh[c+d x]^n)/(a Cosh[c+d x]+b Sinh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  -(b/(a^2-b^2))\[Integral]u Sinh[c+d x]^(n-1) \[DifferentialD]x+*)
(*a/(a^2-b^2) \[Integral]u Sinh[c+d x]^(n-2) Cosh[c+d x]\[DifferentialD]x-a^2/(a^2-b^2) \[Integral](u Sinh[c+d x]^(n-2))/(a Cosh[c+d x]+b Sinh[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Sinh[c_.+d_.*x_]^n_/(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_]),x_Symbol] :=
  Dist[-b/(a^2-b^2),Int[u*Sinh[c+d*x]^(n-1),x]] +
  Dist[a/(a^2-b^2),Int[u*Sinh[c+d*x]^(n-2)*Cosh[c+d*x],x]] -
  Dist[a^2/(a^2-b^2),Int[u*Sinh[c+d*x]^(n-2)/(a*Cosh[c+d*x]+b*Sinh[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && IntegerQ[n] && n>0 && 
(n>1 || MatchQ[u,v_.*Tanh[c+d*x]^m_. /; IntegerQ[m] && m>0])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic expansion*)


(* ::Subsubsection:: *)
(*Basis: Cosh[z]^2/(a Cosh[z]+b Sinh[z])=(a Cosh[z])/(a^2-b^2)-(b Sinh[z])/(a^2-b^2)-b^2/((a^2-b^2) (a Cosh[z]+b Sinh[z]))*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] n\[Element]\[DoubleStruckCapitalZ] \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](u Cosh[c+d x]^n)/(a Cosh[c+d x]+b Sinh[c+d x]) \[DifferentialD]x  \[LongRightArrow]  (a/(a^2-b^2))\[Integral]u Cosh[c+d x]^(n-1) \[DifferentialD]x-*)
(*b/(a^2-b^2) \[Integral]u Cosh[c+d x]^(n-2) Sinh[c+d x]\[DifferentialD]x-b^2/(a^2-b^2) \[Integral](u Cosh[c+d x]^(n-2))/(a Cosh[c+d x]+b Sinh[c+d x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[u_.*Cosh[c_.+d_.*x_]^n_/(a_.*Cosh[c_.+d_.*x_]+b_.*Sinh[c_.+d_.*x_]),x_Symbol] :=
  Dist[a/(a^2-b^2),Int[u*Cosh[c+d*x]^(n-1),x]] -
  Dist[b/(a^2-b^2),Int[u*Cosh[c+d*x]^(n-2)*Sinh[c+d*x],x]] -
  Dist[b^2/(a^2-b^2),Int[u*Cosh[c+d*x]^(n-2)/(a*Cosh[c+d*x]+b*Sinh[c+d*x]),x]] /;
FreeQ[{a,b,c,d},x] && NonzeroQ[a^2-b^2] && IntegerQ[n] && n>0 && 
(n>1 || MatchQ[u,v_.*Coth[c+d*x]^m_. /; IntegerQ[m] && m>0])


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.4c*)


(* ::Subsubsection:: *)
(*Rule: If  a-b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  (1/(c e))Log[a+c Tanh[(d+e x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  Log[a+c*Tanh[(d+e*x)/2]]/(c*e) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a-b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.4c*)


(* ::Subsubsection:: *)
(*Rule: If  a+b=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  -(1/(c e))Log[a-c Coth[(d+e x)/2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  -Log[a-c*Coth[(d+e*x)/2]]/(c*e) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a+b]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.4d*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  -((c+a Sinh[d+e x])/(c e (c Cosh[d+e x]+b Sinh[d+e x])))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  -(c+a*Sinh[d+e*x])/(c*e*(c*Cosh[d+e*x]+b*Sinh[d+e*x])) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a^2-b^2+c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.4b'*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] a^2-b^2+c^2>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  -(2/(e Sqrt[a^2-b^2+c^2]))ArcTanh[(c-(a-b) Tanh[(d+e x)/2])/Sqrt[a^2-b^2+c^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  -2*ArcTanh[(c-(a-b)*Tanh[(d+e*x)/2])/Rt[a^2-b^2+c^2,2]]/(e*Rt[a^2-b^2+c^2,2]) /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2] && PosQ[a^2-b^2+c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: Reference: G&R 2.451.4a*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2!=0 \[And] \[Not](a^2-b^2+c^2>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  (2/(e Sqrt[-a^2+b^2-c^2]))ArcTan[(c-(a-b) Tanh[(d+e x)/2])/Sqrt[-a^2+b^2-c^2]]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  2*ArcTan[(c-(a-b)*Tanh[(d+e*x)/2])/Rt[-a^2+b^2-c^2,2]]/(e*Rt[-a^2+b^2-c^2,2]) /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2] && NegQ[a^2-b^2+c^2]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]\[DifferentialD]x  \[LongRightArrow]  ((2 (c Cosh[d+e x]+b Sinh[d+e x]))/(e Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]],x_Symbol] :=
  2*(c*Cosh[d+e*x]+b*Sinh[d+e*x])/(e*Sqrt[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]) /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a^2-b^2+c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]+c Sinh[z]=a-I Sqrt[b^2-c^2] Sinh[z+I ArcTan[I c,b]]*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] a-Sqrt[b^2-c^2]>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]\[DifferentialD]x  \[LongRightArrow]  \[Integral]Sqrt[a-I Sqrt[b^2-c^2] Sinh[d+e x+I ArcTan[I c,b]]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]],x_Symbol] :=
  Int[Sqrt[a-I*Sqrt[b^2-c^2]*Sinh[d+e*x+I*ArcTan[I*c,b]]],x] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2] && PositiveQ[a-Sqrt[b^2-c^2]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]+c Sinh[z]=a-I Sqrt[b^2-c^2] Sinh[z+I ArcTan[I c,b]]*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] \[Not](a-Sqrt[b^2-c^2]>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]\[DifferentialD]x  \[LongRightArrow]  *)
(*((2 I Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]])/(e Sqrt[(a+b Cosh[d+e x]+c Sinh[d+e x])/(a-Sqrt[b^2-c^2])]))EllipticE[1/2 (\[Pi]/2-I (d+e x+I ArcTan[I c,b])),2/(1-a/Sqrt[b^2-c^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[Sqrt[a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]],x_Symbol] :=
  2*I*EllipticE[(Pi/2-I*(d+e*x+I*ArcTan[I*c,b]))/2,2/(1-a/Sqrt[b^2-c^2])]*
  Sqrt[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/
  (e*Sqrt[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])/(a-Sqrt[b^2-c^2])]) /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2] && Not[PositiveQ[a-Sqrt[b^2-c^2]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]+c Sinh[z]=a-I Sqrt[b^2-c^2] Sinh[z+I ArcTan[I c,b]]*)


(* ::Subsubsection:: *)
(*Rule: If  a-Sqrt[b^2-c^2]>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]] \[DifferentialD]x  \[LongRightArrow]  \[Integral]1/Sqrt[a-I Sqrt[b^2-c^2] Sinh[d+e x+I ArcTan[I c,b]]] \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]],x_Symbol] :=
  Int[1/Sqrt[a-I*Sqrt[b^2-c^2]*Sinh[d+e*x+I*ArcTan[I*c,b]]],x] /;
FreeQ[{a,b,c,d,e},x] && PositiveQ[a-Sqrt[b^2-c^2]]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Piecewise constant extraction and algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: \!\( *)
(*\*SubscriptBox[\(\[PartialD]\), \(z\)]*)
(*\*FractionBox[*)
(*SqrtBox[*)
(*FractionBox[\(a + b\ Cosh[z] + c\ Sinh[z]\), \(a - *)
(*\*SqrtBox[\( *)
(*\*SuperscriptBox[\(b\), \(2\)] - *)
(*\*SuperscriptBox[\(c\), \(2\)]\)]\)]], *)
(*SqrtBox[\(a + b\ Cosh[z] + c\ Sinh[z]\)]]\)=0*)


(* ::Subsubsection:: *)
(*Basis: a+b Cosh[z]+c Sinh[z]=a-I Sqrt[b^2-c^2] Sinh[z+I ArcTan[I c,b]]*)


(* ::Subsubsection:: *)
(*Rule: If  a-Sqrt[b^2-c^2]!=0 \[And] \[Not](a-Sqrt[b^2-c^2]>0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]] \[DifferentialD]x  \[LongRightArrow]  *)
(*((2 I Sqrt[(a+b Cosh[d+e x]+c Sinh[d+e x])/(a-Sqrt[b^2-c^2])])/(e Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]))EllipticF[1/2 (\[Pi]/2-I (d+e x+I ArcTan[I c,b])),2/(1-a/Sqrt[b^2-c^2])]*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/Sqrt[a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]],x_Symbol] :=
  2*I*EllipticF[(Pi/2-I*(d+e*x+I*ArcTan[I*c,b]))/2,2/(1-a/Sqrt[b^2-c^2])]*
  Sqrt[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])/(a-Sqrt[b^2-c^2])]/
  (e*Sqrt[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]) /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a-Sqrt[b^2-c^2]] && Not[PositiveQ[a-Sqrt[b^2-c^2]]]


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 inverted with a^2-b^2+c^2=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((c Cosh[d+e x]+b Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n-1))/(e n))+*)
(*(a (2 n-1))/n \[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^(n-1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (c*Cosh[d+e*x]+b*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1)/(e*n) +
  Dist[a*(2*n-1)/n,Int[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a^2-b^2+c^2] && RationalQ[n] && n>1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 inverted*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] n>1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((c Cosh[d+e x]+b Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n-1))/(e n))+*)
(*1/n \[Integral](n a^2+(n-1)(b^2-c^2)+a b (2 n-1) Cosh[d+e x]+a c (2 n-1)Sinh[d+e x])(a+b Cosh[d+e x]+c Sinh[d+e x])^(n-2) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (c*Cosh[d+e*x]+b*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1)/(e*n) +
  Dist[1/n,Int[(n*a^2+(n-1)*(b^2-c^2)+a*b*(2*n-1)*Cosh[d+e*x]+a*c*(2*n-1)*Sinh[d+e*x])*
    (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-2),x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n>1


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2=0 \[And] n<-1, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*-(((c Cosh[d+e x]+b Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^n)/(a e (2 n+1)))+*)
(*(n+1)/(a (2 n+1)) \[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  -(c*Cosh[d+e*x]+b*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^n/(a*e*(2*n+1)) +
  Dist[(n+1)/(a*(2*n+1)),Int[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,e},x] && ZeroQ[a^2-b^2+c^2] && RationalQ[n] && n<-1


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  n=-2*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x])^2 \[DifferentialD]x  \[LongRightArrow]  *)
(*-((c Cosh[d+e x]+b Sinh[d+e x])/(e (a^2-b^2+c^2) (a+b Cosh[d+e x]+c Sinh[d+e x])))+a/(a^2-b^2+c^2) \[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  -(c*Cosh[d+e*x]+b*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) +
  Dist[a/(a^2-b^2+c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with n=-(3/2)*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x])^(3/2) \[DifferentialD]x  \[LongRightArrow]  *)
(*-((2 (c Cosh[d+e x]+b Sinh[d+e x]))/(e (a^2-b^2+c^2) Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]))+1/(a^2-b^2+c^2) \[Integral]Sqrt[a+b Cosh[d+e x]+c Sinh[d+e x]]\[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[1/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^(3/2),x_Symbol] :=
  -2*(c*Cosh[d+e*x]+b*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*Sqrt[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]) +
  Dist[1/(a^2-b^2+c^2),Int[Sqrt[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]],x]] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] n<-1 \[And] n!=-2 \[And] n!=-(3/2), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((c Cosh[d+e x]+b Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1))/(e (n+1) (a^2-b^2+c^2)))+*)
(*1/((n+1) (a^2-b^2+c^2)) \[Integral]((n+1) a-(n+2) b Cosh[d+e x]-(n+2) c Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (c*Cosh[d+e*x]+b*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1)/(e*(n+1)*(a^2-b^2+c^2)) +
  1/((n+1)*(a^2-b^2+c^2))*
    Int[((n+1)*a-(n+2)*b*Cosh[d+e*x]-(n+2)*c*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x] /;
FreeQ[{a,b,c,d,e},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n<-1 && n!=-2 && n!=-3/2


(* ::PageBreak:: *)
(**)


(* ::Title::Bold::Closed:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])(a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.3*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-c^2=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  (((2 a A-b B+c C) x)/(2 a^2))-((b B-c C) (b Cosh[d+e x]-c Sinh[d+e x]))/(2 a b c e)+*)
(*((a^2 (b B+c C)-2 a A b^2+b^2 (b B-c C)) Log[a+b Cosh[d+e x]+c Sinh[d+e x]])/(2 a^2 b c e)*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  (2*a*A-b*B+c*C)*x/(2*a^2) - (b*B-c*C)*(b*Cosh[d+e*x]-c*Sinh[d+e*x])/(2*a*b*c*e) + 
  (a^2*(b*B+c*C)-2*a*A*b^2+b^2*(b*B-c*C))*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(2*a^2*b*c*e) /;
FreeQ[{a,b,c,d,e,A,B,C},x] && ZeroQ[b^2-c^2]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.3 with  B=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  (2*a*A+c*C)*x/(2*a^2) + C*Cosh[d+e*x]/(2*a*e) - c*C*Sinh[d+e*x]/(2*a*b*e) + 
  (a^2*C-2*a*c*A-b^2*C)*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(2*a^2*b*e) /;
FreeQ[{a,b,c,d,e,A,C},x] && ZeroQ[b^2-c^2]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.3 with  C=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])/(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  (2*a*A-b*B)*x/(2*a^2) - b*B*Cosh[d+e*x]/(2*a*c*e) + B*Sinh[d+e*x]/(2*a*e) + 
  (a^2*B-2*a*b*A+b^2*B)*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(2*a^2*c*e) /;
FreeQ[{a,b,c,d,e,A,B},x] && ZeroQ[b^2-c^2]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2 with  A(b^2-c^2)-a(b B-c C)=0*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-c^2!=0 \[And] A(b^2-c^2)-a(b B-c C)=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  (((b B-c C) x)/(b^2-c^2))-((c B-b C) Log[a+b Cosh[d+e x]+c Sinh[d+e x]])/(e (b^2-c^2))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  (b*B-c*C)*x/(b^2-c^2) - (c*B-b*C)*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[b^2-c^2] && ZeroQ[A*(b^2-c^2)-a*(b*B-c*C)]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2 with  B=0  and  A (b^2-c^2)+a c C=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  -c*C*x/(b^2-c^2) + b*C*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[b^2-c^2] && ZeroQ[A*(b^2-c^2)+a*c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2 with  C=0  and  A (b^2-c^2)-a b B=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  b*B*x/(b^2-c^2) - c*B*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[b^2-c^2] && ZeroQ[A*(b^2-c^2)-a*b*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2*)


(* ::Subsubsection:: *)
(*Rule: If  b^2-c^2!=0 \[And] A (b^2-c^2)-a (b B-c C)!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x  \[LongRightArrow]  *)
(*(((b B-c C) x)/(b^2-c^2))-((c B-b C) Log[a+b Cosh[d+e x]+c Sinh[d+e x]])/(e (b^2-c^2))+*)
(*(A (b^2-c^2)-a (b B-c C))/(b^2-c^2) \[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  (b*B-c*C)*x/(b^2-c^2) - (c*B-b*C)*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) + 
  Dist[(A*(b^2-c^2)-a*(b*B-c*C))/(b^2-c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[b^2-c^2] && NonzeroQ[A*(b^2-c^2)-a*(b*B-c*C)]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2 with  B=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  -c*C*x/(b^2-c^2) + b*C*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) + 
  Dist[(A*(b^2-c^2)+a*c*C)/(b^2-c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[b^2-c^2] && NonzeroQ[A*(b^2-c^2)+a*c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.2 with  C=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_]),x_Symbol] :=
  b*B*x/(b^2-c^2) - c*B*Log[a+b*Cosh[d+e*x]+c*Sinh[d+e*x]]/(e*(b^2-c^2)) + 
  Dist[(A*(b^2-c^2)-a*b*B)/(b^2-c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[b^2-c^2] && NonzeroQ[A*(b^2-c^2)-a*b*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  n=-2  and  a A-b B+c C=0*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] a A-b B+c C=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])/(a+b Cosh[d+e x]+c Sinh[d+e x])^2 \[DifferentialD]x  \[LongRightArrow]  -((c B-b C-(a C-c A) Cosh[d+e x]+(b A-a B) Sinh[d+e x])/(e (a^2-b^2+c^2) (a+b Cosh[d+e x]+c Sinh[d+e x])))*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  -(c*B-b*C-(a*C-c*A)*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])/
    (e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[a^2-b^2+c^2] && ZeroQ[a*A-b*B+c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  B=0,  n=-2  and  a A+c C=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  (b*C+(a*C-c*A)*Cosh[d+e*x]-b*A*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[a^2-b^2+c^2] && ZeroQ[a*A+c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  C=0,  n=-2  and  a A-b B=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  -(c*B+c*A*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[a^2-b^2+c^2] && ZeroQ[a*A-b*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  n=-2*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] a A-b B+c C!=0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])/(a+b Cosh[d+e x]+c Sinh[d+e x])^2 \[DifferentialD]x  \[LongRightArrow]  *)
(*-((c B-b C-(a C-c A) Cosh[d+e x]+(b A-a B) Sinh[d+e x])/(e (a^2-b^2+c^2) (a+b Cosh[d+e x]+c Sinh[d+e x])))+(a A-b B+c C)/(a^2-b^2+c^2) \[Integral]1/(a+b Cosh[d+e x]+c Sinh[d+e x]) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  -(c*B-b*C-(a*C-c*A)*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])/
     (e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) +
  Dist[(a*A-b*B+c*C)/(a^2-b^2+c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[a^2-b^2+c^2] && NonzeroQ[a*A-b*B+c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  B=0  and  n=-2*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  (b*C+(a*C-c*A)*Cosh[d+e*x]-b*A*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) +
  Dist[(a*A+c*C)/(a^2-b^2+c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[a^2-b^2+c^2] && NonzeroQ[a*A+c*C]


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  C=0  and  n=-2*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])/(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^2,x_Symbol] :=
  -(c*B+c*A*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])/(e*(a^2-b^2+c^2)*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])) +
  Dist[(a*A-b*B)/(a^2-b^2+c^2),Int[1/(a+b*Cosh[d+e*x]+c*Sinh[d+e*x]),x]] /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[a^2-b^2+c^2] && NonzeroQ[a*A-b*B]


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Derivation: Algebraic simplification*)


(* ::Subsubsection:: *)
(*Basis: (A+B z) (a+b z)^n=B/b (a+b z)^(n+1)+(A b-a B)/b (a+b z)^n*)


(* ::Subsubsection:: *)
(*Rule: If  b C-c B=0 \[And] b A-a B!=0 \[And] (n=-(1/2) \[Or] a^2-b^2+c^2=0), then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])(a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(B/b)\[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1) \[DifferentialD]x+(b A-a B)/b \[Integral](a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])*(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  Dist[B/b,Int[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x]] +
  Dist[(b*A-a*B)/b,Int[(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^n,x]] /;
FreeQ[{a,b,c,d,e,A,B,C},x] && ZeroQ[b*C-c*B] && NonzeroQ[b*A-a*B] && RationalQ[n] && (n==-1/2 || ZeroQ[a^2-b^2+c^2])


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] n<-1 \[And] n!=-2, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x])(a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((c B-b C-(a C-c A) Cosh[d+e x]+(b A-a B) Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1))/(e (n+1) (a^2-b^2+c^2)))+*)
(*1/((n+1) (a^2-b^2+c^2)) \[Integral]((n+1) (a A-b B+c C)-(n+2) (b A-a B) Cosh[d+e x]+(n+2) (a C-c A) Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^(n+1) \[DifferentialD]x*)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])*(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (c*B-b*C-(a*C-c*A)*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1)/
    (e*(n+1)*(a^2-b^2+c^2)) +
  Dist[1/((n+1)*(a^2-b^2+c^2)),
    Int[((n+1)*(a*A-b*B+c*C)-(n+2)*(b*A-a*B)*Cosh[d+e*x]+(n+2)*(a*C-c*A)*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  B=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])*(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  -(b*C+(a*C-c*A)*Cosh[d+e*x]-b*A*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1)/
    (e*(n+1)*(a^2-b^2+c^2)) +
  Dist[1/((n+1)*(a^2-b^2+c^2)),
    Int[((n+1)*(a*A+c*C)-(n+2)*b*A*Cosh[d+e*x]+(n+2)*(a*C-c*A)*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 with  C=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])*(a_.+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (c*B+c*A*Cosh[d+e*x]+(b*A-a*B)*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1)/
    (e*(n+1)*(a^2-b^2+c^2)) +
  Dist[1/((n+1)*(a^2-b^2+c^2)),
    Int[((n+1)*(a*A-b*B)-(n+2)*(b*A-a*B)*Cosh[d+e*x]-(n+2)*c*A*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n+1),x]] /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n<-1 && n!=-2


(* ::Subsubsection:: *)
(**)


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 inverted*)


(* ::Subsubsection:: *)
(*Rule: If  a^2-b^2+c^2!=0 \[And] n>0, then*)


(* ::Subsubtitle::Bold:: *)
(*\[Integral](A+B Cosh[d+e x]+C Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^n \[DifferentialD]x  \[LongRightArrow]  *)
(*(((-B c+b C+a C Cosh[d+e x]+a B Sinh[d+e x]) (a+b Cosh[d+e x]+c Sinh[d+e x])^n)/(a e (n+1)))+*)
(*1/(a (n+1)) \[Integral] (a(b B-c C) n+a^2 A (n+1)+(a^2 B n-c (b C-c B) n+a b A(n+1)) Cosh[d+e x]+(a^2 C n-b (b C-c B) n+a c A(n+1)) Sinh[d+e x])\[CenterDot]*)
(*(a+b Cosh[d+e x]+c Sinh[d+e x])^(n-1)\[DifferentialD]x *)


(* ::Subsubsection:: *)
(*Program code:*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_]+C_.*Sinh[d_.+e_.*x_])*(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (-B*c+b*C+a*C*Cosh[d+e*x]+a*B*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^n/(a*e*(n+1)) + 
  Dist[1/(a*(n+1)),
    Int[(a*(b*B-c*C)*n + a^2*A*(n+1) + 
        (a^2*B*n - c*(b*C-c*B)*n + a*b*A*(n+1))*Cosh[d+e*x] + 
        (a^2*C*n - b*(b*C-c*B)*n + a*c*A*(n+1))*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1), x]] /;
FreeQ[{a,b,c,d,e,A,B,C},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 inverted with B=0*)


(* ::Code:: *)
Int[(A_.+C_.*Sinh[d_.+e_.*x_])*(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (b*C+a*C*Cosh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^n/(a*e*(n+1)) + 
  Dist[1/(a*(n+1)),
    Int[(-a*c*C*n+a^2*A*(n+1)-b*(c*C*n-a*A*(n+1))*Cosh[d+e*x]+(a^2*C*n-b^2*C*n+a*c*A*(n+1))*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1), x]] /;
FreeQ[{a,b,c,d,e,A,C},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n>0


(* ::Subsubsection:: *)
(*Reference: G&R 2.451.1 inverted with C=0*)


(* ::Code:: *)
Int[(A_.+B_.*Cosh[d_.+e_.*x_])*(a_+b_.*Cosh[d_.+e_.*x_]+c_.*Sinh[d_.+e_.*x_])^n_,x_Symbol] :=
  (-B*c+a*B*Sinh[d+e*x])*(a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^n/(a*e*(n+1)) + 
  Dist[1/(a*(n+1)),
    Int[(a*b*B*n+a^2*A*(n+1)+(a^2*B*n+c^2*B*n+a*b*A*(n+1))*Cosh[d+e*x]+c*(b*B*n+a*A*(n+1))*Sinh[d+e*x])*
      (a+b*Cosh[d+e*x]+c*Sinh[d+e*x])^(n-1), x]] /;
FreeQ[{a,b,c,d,e,A,B},x] && NonzeroQ[a^2-b^2+c^2] && RationalQ[n] && n>0
