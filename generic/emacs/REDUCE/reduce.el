;;; reduce.el --- Load and run ESL REDUCE.

;;; Author: Francis J. Wright
;;; Based on code by Anthony C. Hearn.

;; Load and run REDUCE on Emacs Lisp.
;; Interactive input from minibuffer and output to normal buffer.
;; Batch mode input from stdin and output to stdout.

(add-to-list 'load-path nil)

(require 'esl)							; defines LOAD-MODULE

(setq max-specpdl-size 3000)			; default of 1300 too small

;; Load core modules quietly:
(let ((*MSG nil))
  ;; LOAD-PACKAGE is defined in "rlisp/module.red", so...
  (declare-function LOAD-PACKAGE "fasl/module" (U))
  (LOAD-MODULE 'MODULE)

  ;; Each package fasl file calls CREATE!-PACKAGE, which is defined in
  ;; "eslprolo.red", so...
  (LOAD-MODULE 'ESLPROLO)

  (defvar LOADED-PACKAGES* '(ESLPROLO MODULE))

  (LOAD-PACKAGE 'RLISP)
  (LOAD-PACKAGE 'ESLREND)
  (LOAD-PACKAGE 'POLY)
  ;; This is in ENTRY, but needs to be here or earlier because ARBINT
  ;; is used in alg/elem.  Should ENTRY be loaded here?
  (put 'ARBINT 'SIMPFN 'SIMPIDEN)
  ;; alg must be before arith because alg defines evenp, used in arith!
  (LOAD-PACKAGE 'ALG)
  (setq *MSG nil)				 ; initialized to t in "alg/intro.red"
  (LOAD-PACKAGE 'ARITH)
  (LOAD-PACKAGE 'MATHPR)
  (LOAD-PACKAGE 'ENTRY))

(setq *MSG t)							; reset the correct default

(with-no-warnings			   ; suppress warning about lack of prefix
  (defvar STATCOUNTER))
(declare-function INITREDUCE "fasl/eslrend" ())
(declare-function BEGIN "fasl/eslrend" ())

(defun esl-reduce ()
  ;; reduce (lower case) is an alias for ‘cl-reduce’!
  ;; REDUCE (upper case) is a function in the REDUCE compact module!
  "Run ESL REDUCE with input via the minibuffer and output via a buffer."
  (interactive)
  (switch-to-buffer
   (setq esl--default-output-buffer
		 (get-buffer-create "*ESL REDUCE*")))
  ;; (require 'reduce-mode "../reduce-mode.el") ; temporary filename
  ;; (reduce-mode)
  (goto-char (point-max))  ; in case buffer already exists
  (let (value			   ; value of last sexp
		;; Output to the END of the current buffer:
		;; (standard-output (set-marker esl--marker (point-max)))
		;; The above is proving unreliable, so try this:
		(standard-output (or noninteractive	; in batch mode, output to stdout
							 (current-buffer)))
		;; Make (READCH) read from the minibuffer:
		(esl--readch-use-minibuffer t))
	(catch 'QUIT
	  ;; Run the standard REDUCE read-eval-print loop:
	  (if (zerop STATCOUNTER)
		  (INITREDUCE)
		(BEGIN)))))

(provide 'reduce)

(esl-reduce)	; Probably bad form, but convenient, to run this here!

;;; reduce.el ends here
