module prep; % Functions for converting canon. forms into prefix forms.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation. All rights reserved.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id: prep.red 6238 2022-01-29 10:49:01Z schoepf $

fluid '(!*bool !*intstr);

symbolic procedure prepsqxx u;
   % This is a top level conversion function.  It is not clear if we
   % need prepsqxx, prepsqx, prepsq!* and prepsq, but we keep them all
   % for the time being.
   negnumberchk prepsqx u;

symbolic procedure negnumberchk u;
   if eqcar(u,'minus) and numberp cadr u then - cadr u else u;

symbolic procedure prepsqx u;
   if !*intstr then prepsq!* u else prepsq u;

symbolic procedure prepsq u;
   if null numr u then 0 else sqform(u,function prepf);

symbolic procedure sqform(u,v);
   (lambda (x,y); if y=1 then x else list('quotient,x,y))
      (apply1(v,numr u),apply1(v,denr u));

% For at least a while I am leaving the OLD version around, albeit
% unused.

symbolic procedure oldprepf u;
   (if null x then 0 else replus x) where x=oldprepf1(u,nil);

symbolic procedure prepf u;
  replus1 prepf1a(u, nil);

% This old version of prepf1 seems bad to me in that it keeps using
% nconc to append segments of the result. Each such call involves
% traversing the length of the result generated by an inner call to prepf1.
% In bad cases this leads to costs that grow badly as the number of variable
% increases.  

symbolic procedure oldprepf1(u,v);
   if null u then nil
   else if domainp u then list retimes(prepd u . exchk v)
   else nconc!*(oldprepf1(lc u,if mvar u eq 'k!* then v else lpow u . v),
                oldprepf1(red u,v));

% prepf1 seems only to be used in this file, and so as soon as it has been
% performed the result will be passed to replus (and through that to
% unplus). So it should make good sense to perform the replus/unplus steps
% as one goes... But I will leave a function prepf1 that behaves exactly as
% per the original just in case anybody wants it and make my composite
% of pref1 and replus a new function...

symbolic procedure prepf1(u, v);
   reversip prepf1_reversed(u, v, nil);

% This code builds up the result in reversed order. It is more explicitly
% tail-recursive in the CDR direction and avoids not just any twitching about
% side effects with nconc but potential repeated scannning of data.

symbolic procedure prepf1_reversed(u, v, r);
  begin
top:
    if null u then return r
    else if domainp u then return (retimes(prepd u . exchk v) . r);
    r := prepf1_reversed(lc u,
                         if mvar u eq 'k!* then v else lpow u . v,
                         r);
    u := red u;
    go to top
  end;

% prepf1a will be like prepf1 except that it performs any "unplus"
% operations that might be useful. It is the version that will actually go
% into service. If it proves sensible over a while then the earlier code
% will be removed totally. Note that this version will do what I believe to
% be correct rather than what the previous version of the code did!

symbolic procedure prepf1a(u, v);
  reversip prepf1a_reversed(u, v, nil);

symbolic procedure prepf1a_reversed(u, v, r);
  begin
top:
    if null u then return r
    else if domainp u then return
       begin
          scalar z;
          z := retimes(prepd u . exchk v);
% I will note that an embedded (plus P Q) or (difference P Q) can arise from
% the conversion of a domain element in the case of complex values, so without
% the top line (x + (i+1)) might end up as
%    (plus x (plus i 1)),
% while I adjust it here to be (plus x i 1). That seems reasonable.
% Similarly (x + (-1-i)) might end up as
%    (plus x (difference (minus 1) i))
% and is adjusted to (plus (minus 1) (minus i).
          if eqcar(z, 'plus) then <<
             for each y in cdr z do r := y . r >>
	  else if eqcar(z, 'difference) then <<
	     r := cadr z . r; r := {'minus,caddr z} . r >>
          else r := z . r;
          return r
       end;
    r := prepf1a_reversed(lc u,
                          if mvar u eq 'k!* then v else lpow u . v,
                          r);
    u := red u;
    go to top
  end;

symbolic procedure prepd u;
   if atom u then if u<0 then list('minus,-u) else u
    else if apply1(get(car u,'minusp),u)
%    then list('minus,prepd1 !:minus u)
     then (if null x then 0 else list('minus,x))
          where x=prepd1 !:minus u
%   else if !:onep u then 1
    else apply1(get(car u,'prepfn),u);

symbolic procedure prepd1 u;
   if atom u then u else apply1(get(car u,'prepfn),u);

% symbolic procedure exchk u;
%    begin scalar z;
%       for each j in u do
%          if cdr j=1
%            then if eqcar(car j,'expt) and caddar j = '(quotient 1 2)
%                    then z := list('sqrt,cadar j) .z
%                   else z := sqchk car j . z
%            else z := list('expt,sqchk car j,cdr j) . z;
%       return z
%   end;

symbolic procedure exchk u; exchk1(u,nil,nil,nil);

symbolic procedure exchk1(u,v,w,x);
   % checks forms for kernels in EXPT. U is list of powers.  V is used
   % to build up the final answer. W is an association list of
   % previous non-constant (non foldable) EXPT's, X is an association
   % list of constant (foldable) EXPT arguments.
   if null u then exchk2(append(x,w),v)
    else if eqcar(caar u,'expt)
     then begin scalar y,z;
            y := simpexpon list('times,cdar u,caddar car u);
            if numberp cadaar u   % constant argument
              then <<z := assoc2(y,x);
                     if z then rplaca(z,car z*cadaar u)
                      else x := (cadaar u . y) . x>>
             else <<z := assoc(cadaar u,w);
                    if z then rplacd(z,addsq(y,cdr z))
                     else w := (cadaar u . y) . w>>;
            return exchk1(cdr u,v,w,x)
        end
    else if cdar u=1 then exchk1(cdr u,sqchk caar u . v,w,x)
    else exchk1(cdr u,list('expt,sqchk caar u,cdar u) . v,w,x);

symbolic procedure exchk2(u,v);
   if null u then v
    else exchk2(cdr u,
%               ((if eqcar(x,'quotient) and caddr x = 2
%                  then if cadr x = 1 then list('sqrt,caar u)
%                        else list('expt,list('sqrt,caar u),cadr x)
                ((if x=1 then caar u
                   else if !*nosqrts then list('expt,caar u,x)
                   else if x = '(quotient 1 2) then list('sqrt,caar u)
                   else if x=0.5 then list('sqrt,caar u)
                   else list('expt,caar u,x)) where x = prepsqx cdar u)
                . v);

symbolic procedure assoc2(u,v);
   % Finds key U in second position of terms of V, or returns NIL.
   if null v then nil
    else if u = cdar v then car v
    else assoc2(u,cdr v);

symbolic procedure replus u;
   if null u then 0
    else if atom u then u
    else if null cdr u then car u
    else 'plus . unplus u;

% replus1 is like replus except that it expects that the list of items
% it is given do not contain "plus" objects... except possibly one that
% is used as a sort of marker.

symbolic procedure replus1 u;
   if null u then 0
    else if atom u or (eqcar(u, 'plus) and cdr u) then u
    else if null cdr u then car u
    else 'plus . u;

symbolic procedure unplus u;
   if atom u then u
   else if car u = 'plus then unplus cdr u
   else if atom car u or not eqcar(car u,'plus)
      then (car u) . unplus cdr u
   else append(cdar u,unplus cdr u);

% symbolic procedure retimes u;
%    % U is a list of prefix expressions. Value is prefix form for the
%    % product of these;
%    begin scalar bool,x;
%       for each j in u do
%         <<if j=1 then nil     % ONEP
%             else if eqcar(j,'minus)
%              then <<bool := not bool;
%                     if cadr j neq 1 then x := cadr j . x>>     % ONEP
%             else if numberp j and minusp j
%              then <<bool := not bool;
%                    if j neq -1 then x := (-j) . x>>
%             else x := j . x>>;
%        x := if null x then 1
%                else if cdr x then 'times . reverse x else car x;
%        return if bool then list('minus,x) else x
%   end;

symbolic procedure retimes u;
   begin scalar !*bool;
      u := retimes1 u;
      u := if null u then 1
            else if cdr u then 'times . u
            else car u;
      return if !*bool then list('minus,u) else u
   end;

symbolic procedure retimes1 u;
   if null u then nil
    else if car u = 1 then retimes1 cdr u
    else if minusp car u
     then <<!*bool := not !*bool; retimes1((-car u) . cdr u)>>
    else if atom car u then car u . retimes1 cdr u
    else if caar u eq 'minus
     then <<!*bool := not !*bool; retimes1(cadar u . cdr u)>>
    else if caar u eq 'times then retimes1 append(cdar u,cdr u)
    else car u . retimes1 cdr u;

symbolic procedure sqchk u;
   if atom u then u
    else (if x then apply1(x,u) else if atom car u then u else prepf u)
          where x=get(car u,'prepfn2);

put('!*sq,'prepfn2,'prepcadr);

put('expt,'prepfn2,'prepexpt);

symbolic procedure prepcadr u; prepsq cadr u;

symbolic procedure prepexpt u; if caddr u=1 then cadr u else u;

% When I enable this then "!*hold" is removed on the way towawards printing.
% This may generally be a good thing since it causes any necessary extra
% sets of parens to get inserted. When !*hold is removed that way there
% is then no cause to need a 'prifn on !*hold - but I leave that present
% for when anybody has gone "off prephold"... the flexibility here is
% provided because the "hold" capability is at present an experiment.

put('!*hold, 'prepfn2, 'prephold);

switch prephold=on;
%!*prephold := t;

symbolic procedure prephold u;
   if (not !*prephold) or atom u then u
   else if eqcar(u, '!*hold) then prephold cadr u
   else if eqcar(u, '!*sq) then prepsq cadr u
   else prephold car u . prephold cdr u;

endmodule;

end;
