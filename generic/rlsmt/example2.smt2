(set-option :print-success false)
(set-logic QF_NRA)
(set-option :produce-unsat-cores true)
(assert (<= (* v8 (+ (* (- 231) v5) (* v8 (+ 315 (* v8 (+ (* (- 315) v5) (* v8 (+ 105 (* v8 (+ (* (- 105) v5) (* v8 (+ 5 (* v8 (* (- 5) v5)))))))))))))) (- 231)))
(assert (<= (* v8 (+ (* 231 v5) (* v8 (+ (- 315) (* v8 (+ (* 315 v5) (* v8 (+ (- 105) (* v8 (+ (* 105 v5) (* v8 (+ (- 5) (* v8 (* 5 v5)))))))))))))) 231))
(assert (not (<= (* v37 (+ (- 231) (* v8 (+ (* 231 v5) (* v8 (+ (- 315) (* v8 (+ (* 315 v5) (* v8 (+ (- 105) (* v8 (+ (* 105 v5) (* v8 (+ (- 5) (* v8 (* 5 v5)))))))))))))))) (+ (+ (/ 231 4) (* 231 v5)) (* v8 (+ (* (- (/ 231 4)) v5) (* v8 (+ (+ (/ 315 4) (* 546 v5)) (* v8 (+ (+ 77 (* (- (/ 315 4)) v5)) (* v8 (+ (+ (/ 105 4) (* 343 v5)) (* v8 (+ (+ (/ 294 5) (* (- (/ 105 4)) v5)) (* v8 (+ (+ (/ 5 4) (* (/ 256 5) v5)) (* v8 (+ 5 (* (- (/ 5 4)) v5)))))))))))))))))))
(assert (not (<= 0 v8)))
(assert (not (<= (* v37 (+ (- 1) (* v8 v5))) (+ v5 v8))))
(assert (<= (* v37 (+ 1 (* v8 (* (- 1) v5)))) (+ (+ 1 (* (- 1) v5)) (* v8 (+ (- 1) (* (- 1) v5))))))
(assert (not (<= 0 v5)))
(assert (not (<= v37 0)))
(assert (not (<= v5 (- 1))))
(assert (not (<= 1 v8)))
(assert (not (<= v8 v5)))
(check-sat)
(get-unsat-core)