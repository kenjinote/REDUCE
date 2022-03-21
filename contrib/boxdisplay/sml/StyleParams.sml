signature STYLE_PARAMS  =
sig
  val xHeight:        BasicTypes.style -> BasicTypes.dist
  val MathUnit:       BasicTypes.style -> BasicTypes.dist
  val atopNum:        BasicTypes.style -> BasicTypes.dist
  val fractNum:       BasicTypes.style -> BasicTypes.dist
  val Denom:          BasicTypes.style -> BasicTypes.dist
  val Sup:    bool -> BasicTypes.style -> BasicTypes.dist
  val SubAlone:       BasicTypes.style -> BasicTypes.dist
  val SubWithSup:     BasicTypes.style -> BasicTypes.dist
  val SupDrop:        BasicTypes.style -> BasicTypes.dist
  val SubDrop:        BasicTypes.style -> BasicTypes.dist
  val Delim:          BasicTypes.style -> BasicTypes.dist
  val AxisHeight:     BasicTypes.style -> BasicTypes.dist
  val RuleThickness:  BasicTypes.style -> BasicTypes.dist
  val BigOpSupDist:   BasicTypes.style -> BasicTypes.dist
  val BigOpSubDist:   BasicTypes.style -> BasicTypes.dist
  val BigOpSupPos:    BasicTypes.style -> BasicTypes.dist
  val BigOpSubPos:    BasicTypes.style -> BasicTypes.dist
  val BigOpPadding:   BasicTypes.style -> BasicTypes.dist
end  (* signature STYLE_PARAMS *)
(*----------*)

structure StyleParams: STYLE_PARAMS  =
struct
  open BasicTypes
  open Size;  open FontParams

  fun use1sy f st  =  f (size SY st)
  fun use2sy f g   =  fn D  =>  f (size SY D)   |   st  =>  g (size SY st)
  fun use1ex f st  =  f (size EX st)

  fun xHeight  (st: style)  =  abs (math_x_height (size SY st))
  fun MathUnit (st: style)  =  math_quad (size SY st)  div  18

  val atopNum   =  use2sy num1 num3
  val fractNum  =  use2sy num1 num2
  val Denom     =  use2sy denom1 denom2

  fun Sup true   =  use1sy sup3
  |   Sup false  =  use2sy sup1 sup2

  val SubAlone       =  use1sy sub1
  val SubWithSup     =  use1sy sub2
  val SupDrop        =  use1sy sup_drop
  val SubDrop        =  use1sy sub_drop
  val Delim          =  use2sy delim1 delim2
  val AxisHeight     =  use1sy axis_height
  val RuleThickness  =  use1ex default_rule_thickness
  val BigOpSupDist   =  use1ex big_op_spacing1
  val BigOpSubDist   =  use1ex big_op_spacing2
  val BigOpSupPos    =  use1ex big_op_spacing3
  val BigOpSubPos    =  use1ex big_op_spacing4
  val BigOpPadding   =  use1ex big_op_spacing5
end  (* structure StyleParams *)
