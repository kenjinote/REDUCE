
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; MODULE      : reduce-input.scm
;; DESCRIPTION : Reduce input converters
;; COPYRIGHT   : (C) 1999  Joris van der Hoeven and Andrey Grozin
;;               This CSL-Reduce variant is exactly the same as the
;;               earlier code apart from the name-change reduce->reduce.
;;               A C Norman, 2005-8
;;
;; This software falls under the GNU general public license and comes WITHOUT
;; ANY WARRANTY WHATSOEVER. See the file $TEXMACS_PATH/LICENSE for details.
;; If you don't have this file, write to the Free Software Foundation, Inc.,
;; 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(texmacs-module (reduce-input)
  (:use (texmacs plugin plugin-convert)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Specific conversion routines
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (reduce-input-var-row r)
  (if (not (null? r))
      (begin
	(display ", ")
	(plugin-input (car r))
	(reduce-input-var-row (cdr r)))))

(define (reduce-input-row r)
  (display "(")
  (plugin-input (car r))
  (reduce-input-var-row (cdr r))
  (display ")"))

(define (reduce-input-var-rows t)
  (if (not (null? t))
      (begin
	(display ", ")
	(reduce-input-row (car t))
	(reduce-input-var-rows (cdr t)))))

(define (reduce-input-rows t)
  (display "mat(")
  (reduce-input-row (car t))
  (reduce-input-var-rows (cdr t))
  (display ")"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Initialization
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(plugin-input-converters reduce
  (rows reduce-input-rows))
