signature OUT_HIGH  =
sig
  val outChar    :  char   -> unit
  val outStr     :  string -> unit  (* the naked string *)
  val outString  :  string -> unit  (* the string preceded by its length *)
  val outNat1    :  int    -> unit
  val outNat2    :  int    -> unit
  val outInt4    :  int    -> unit
  val outZero    :  int    -> unit
  val outInstrV  :  int -> int -> unit
end
(*----------*)

structure OutHigh: OUT_HIGH  =
struct
  open Powers2
  open Out

  val byteSmall   =  Word8.fromInt
  val byteChar    =  byteSmall o Char.ord

  val outNat1  =  outByte o byteSmall
  val outChar  =  outByte o byteChar

  val outStr  =  List.app outChar o String.explode
  fun outString s  =  (outNat1 (String.size s);  outStr s)

  fun outZero 0  =  ()
  |   outZero n  =  (outNat1 0;  outZero (n-1))

  fun outNat2 n  =  ( outNat1 (n div two8 );  outNat1 (n mod two8 ) )
  fun outNat3 n  =  ( outNat1 (n div two16);  outNat2 (n mod two16) )

  (* The following differs from Knuth's method since SML's integers
     have 31 Bits only *)
  fun splitInt4 n  =
      if  n >= 0  then  (n div two24,  n mod two24)
      else  let val n'  =  n  + two29
                val n'' =  n' + two29
            in  ((n'' div two24) + two7 + two6, n'' mod two24)  end

  fun outInt4 n  =
  let val (n1, nr)  =  splitInt4 n
  in  outNat1 n1;  outNat3 nr  end

  fun makeNat twoI n  =   if  n>= 0  then  n  else  n + twoI

  fun outInstrV code n  =
  let fun Code l  =  outNat1 (code + l)  in
  if  abs n >= two23  then ( Code 4;  outInt4 n                 ) else
  if  abs n >= two15  then ( Code 3;  outNat3 (makeNat two24 n) ) else
  if  abs n >= two7   then ( Code 2;  outNat2 (makeNat two16 n) ) else
  if      n <> 0      then ( Code 1;  outNat1 (makeNat two8  n) ) else  ()
  end

end
