module auxitens;

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

% $Id: auxitens.red 5872 2021-07-29 14:53:49Z arthurcnorman $

% this module introduces basic manipulation functions
% for handling indices and tensor structure

lisp remflag(list 'minus,'intfn);

global '(dimex!* sgn!*  signat!* spaces!* numindxl!* pair_id_num!*) ;


lisp (pair_id_num!*:= '((!0 . 0) (!1 . 1) (!2 . 2) (!3 . 3) (!4 . 4)
                        (!5 . 5) (!6 . 6) (!7 . 7) (!8 . 8) (!9 . 9)
                        (!10 . 10) (!11 . 11) (!12 . 12) (!13 . 13)));

fluid('(dummy_id!* g_dvnames epsilon!*));

% g_dvnames is a vector.


switch onespace;

!*onespace:=t;  % working inside a unique space is the default.


symbolic procedure raiseind!: u;
if atom u then u else raiseind u;

symbolic procedure lowerind_lst u;
% u is a list of indices.
% transforms into a list of covariant indices
for each j in u collect lowerind j;

symbolic procedure raiseind_lst u;
% u is a list of indices.
% transforms into a list of contravariant indices
for each j in u collect raiseind!: j;

symbolic procedure flatindxl u;
% This is taken from EXCALC
 for each j in u collect
   if atom j
     then j
     else if careq_minus(j)
            then cadr j
            else cdr j;

symbolic procedure cov_lst_idsp u;
% True if all indices in list u are covariant
 if null u then t
 else
 if careq_minus car u then cov_lst_idsp cdr u;

symbolic procedure cont_lst_idsp u;
% True if all indices in list u are contravariant
 if null u then t
 else
 if atom car u then cont_lst_idsp cdr u;

symbolic procedure identify_pos_cov_lst(u,i);
% allows to get the position of a fully covariant list
% u is a list of lists
% returns i which is the position of the FIRST relevant list in u.
% starting value of i is zero.
 if null u then
       if i=0 then nil
       else i-1
 else
 if cov_lst_idsp car u then i:=i+1
 else
 identify_pos_cov_lst(cdr u,i+1);

symbolic procedure identify_pos_cont_lst(u,i);
% allows to get the position of a fully contravariant list
% u is a list of lists
% returns i which is the position of the FIRST relevant list in u.
% starting value of i is zero.
 if null u then
      if i=0 then nil
      else i-1
 else
 if cont_lst_idsp car u then i:=i+1
 else
 identify_pos_cont_lst(cdr u,i+1);

symbolic procedure splitlist!: (u,idp);
% EXTRACTS THE SUBLIST OF ELEMENTS WHOSE CAR ARE EQUAL THE IDP.
% TAG.
% taken from my old tensor package.
  if null u then nil
  else
  if eqcar(car u,idp) then car u . splitlist!:(cdr u,idp)
  else splitlist!:(cdr u,idp);

symbolic procedure list_to_ids!: l;
if atom l then rederr "argument for list_to_ids must be a list"
else
intern compress for each i in l join explode i;


symbolic procedure split!:(u,v);
% split!:(list(a,b,c),list(1,1,1)); ==> {{A},{B},{C}}
% No longer used below but ...
if listp u and listp v then
 begin scalar x;
    return for each n in v collect
             for i := 1:n collect
                 <<x := car u; u := rest u; x>>
    end;


symbolic procedure symtree_splitlst(idtens,lsy,bool);
% idtens is the tensor indices argument list and lsy
% is cdr of symtree.
% output is the splitted indices list which mirrors lsy
% and make partial reordering whenever possible .
for each i in lsy collect
          if bool and car i memq {'!+,'!-} then
              ordn for each j in cdr i collect nth(idtens,j)
           else  for each j in cdr i collect nth(idtens,j);


symbolic procedure symtree_zerop (idtens,lsym);
% idtens is the list of indices of a given tensor.
% lsym is the symmetry tree list as generated by the
% 'symtree' operator of DUMMY.RED.
% pseudo-boolean: returns the set of indices which is repeated  or
% nil.
% It DOES detect MOST but NOT ALL possibilities leaving the rest for
% canonical.
 if null cdr lsym then nil
  else
 if numlis cdr lsym then
    if car lsym eq '!- and repeats idtens then repeats idtens
      else nil
  else
% here we start considering proper partial symmetries
   begin scalar lsy, idt,y;
     if car lsym eq  '!- then
       if (y := repeats symtree_splitlst(idtens,cdr lsym,nil))
             then return y;
    idt:= symtree_splitlst(idtens,cdr lsym,t);
    if car lsym eq '!- then
         if (y:=repeats idt) then return y;
   lsy:=for each j in cdr lsym collect car j;
    return partsym_zerop(idt,lsy)
   end;


symbolic procedure partsym_zerop(idt,lsy);
% idt: splitted list of indices
% lsy list of tags for partial symmetries.
% they should have the same lengths
 if null idt then nil
  else
 (if car lsy eq '!- and y then y
  else partsym_zerop(cdr idt,cdr lsy))where y=repeats car idt;


symbolic procedure cont_before_cov u;
% is a list of indices some are covariant
% others are contravariant
% returns a list with contravariant indices placed
% in front of the covariant indices.
 begin scalar x;
  x:=splitlist!:(u,'minus);
  return append(setdiff(u,x) ,x)
 end;

endmodule;

end;