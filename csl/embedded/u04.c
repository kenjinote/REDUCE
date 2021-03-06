
/* $destdir\u04.c        Machine generated C code */

/* Signature: 00000000 28-Sep-2011 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#ifdef OLD_VERSION
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_limit;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
                    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for remainder!-in!-vector */

static Lisp_Object MS_CDECL CC_remainderKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048, v0049, v0050, v0051, v0052, v0053, v0054, v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "remainder-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
    stack[-1] = v0002;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0048 = stack[0];
    v0047 = (Lisp_Object)1; /* 0 */
    if (v0048 == v0047) goto v0057;
    v0048 = stack[0];
    v0047 = (Lisp_Object)-15; /* -1 */
    if (!(v0048 == v0047)) goto v0058;
    v0047 = elt(env, 1); /* "ATTEMPT TO DIVIDE BY ZERO" */
    fn = elt(env, 3); /* errorf */
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-4];
    goto v0058;

v0058:
    v0048 = stack[-1];
    v0047 = stack[0];
    v0047 = *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0047/(16/CELL)));
    v0047 = Lmodular_reciprocal(nil, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0047);
        if (w != 0) w = current_modulus - w;
        v0047 = fixnum_of_int(w);
    }
    v0054 = v0047;
    v0047 = stack[0];
    v0047 = (Lisp_Object)((int32_t)(v0047) - 0x10);
    v0055 = v0047;
    goto v0060;

v0060:
    v0048 = stack[-2];
    v0047 = stack[0];
    v0048 = (Lisp_Object)(int32_t)((int32_t)v0048 - (int32_t)v0047 + TAG_FIXNUM);
    v0056 = v0048;
    v0047 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0048)) < ((int32_t)(v0047))) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0049 = v0054;
    v0048 = stack[-3];
    v0047 = stack[-2];
    v0047 = *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0047/(16/CELL)));
    v0047 = Lmodular_times(nil, v0049, v0047);
    env = stack[-4];
    v0053 = v0047;
    v0047 = (Lisp_Object)1; /* 0 */
    v0052 = v0047;
    goto v0061;

v0061:
    v0048 = v0055;
    v0047 = v0052;
    v0047 = (Lisp_Object)(int32_t)((int32_t)v0048 - (int32_t)v0047 + TAG_FIXNUM);
    v0047 = ((intptr_t)(v0047) < 0 ? lisp_true : nil);
    if (v0047 == nil) goto v0062;
    v0047 = stack[-2];
    v0047 = (Lisp_Object)((int32_t)(v0047) - 0x10);
    stack[-2] = v0047;
    goto v0063;

v0063:
    v0048 = stack[-2];
    v0047 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0048)) < ((int32_t)(v0047))) goto v0064;
    v0048 = stack[-3];
    v0047 = stack[-2];
    v0048 = *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0047/(16/CELL)));
    v0047 = (Lisp_Object)1; /* 0 */
    v0047 = (v0048 == v0047 ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0047 == nil) goto v0060;
    v0047 = stack[-2];
    v0047 = (Lisp_Object)((int32_t)(v0047) - 0x10);
    stack[-2] = v0047;
    goto v0063;

v0064:
    v0047 = qvalue(elt(env, 2)); /* nil */
    goto v0065;

v0062:
    v0051 = stack[-3];
    v0048 = v0052;
    v0047 = v0056;
    v0050 = (Lisp_Object)(int32_t)((int32_t)v0048 + (int32_t)v0047 - TAG_FIXNUM);
    v0049 = stack[-3];
    v0048 = v0052;
    v0047 = v0056;
    v0047 = (Lisp_Object)(int32_t)((int32_t)v0048 + (int32_t)v0047 - TAG_FIXNUM);
    v0049 = *(Lisp_Object *)((char *)v0049 + (CELL-TAG_VECTOR) + ((int32_t)v0047/(16/CELL)));
    v0048 = stack[-1];
    v0047 = v0052;
    v0048 = *(Lisp_Object *)((char *)v0048 + (CELL-TAG_VECTOR) + ((int32_t)v0047/(16/CELL)));
    v0047 = v0053;
    v0047 = Lmodular_times(nil, v0048, v0047);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v0049) + int_of_fixnum(v0047);
        if (w >= current_modulus) w -= current_modulus;
        v0047 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0051 + (CELL-TAG_VECTOR) + ((int32_t)v0050/(16/CELL))) = v0047;
    v0047 = v0052;
    v0047 = (Lisp_Object)((int32_t)(v0047) + 0x10);
    v0052 = v0047;
    goto v0061;

v0057:
    v0047 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0047); }
/* error exit handlers */
v0059:
    popv(5);
    return nil;
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0070, v0043;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gionep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    v0069 = v0043;
    v0069 = qcdr(v0069);
    v0070 = qcar(v0069);
    v0069 = (Lisp_Object)17; /* 1 */
    if (v0070 == v0069) goto v0071;
    v0069 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0069);

v0071:
    v0069 = v0043;
    v0069 = qcdr(v0069);
    v0070 = qcdr(v0069);
    v0069 = (Lisp_Object)1; /* 0 */
    v0069 = (v0070 == v0069 ? lisp_true : nil);
    return onevalue(v0069);
}



/* Code for !*!*s2a */

static Lisp_Object CC_HHs2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object v0072, v0025;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **s2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0001;
    v0025 = v0000;
/* end of prologue */
    return onevalue(v0025);
}



/* Code for quotf1 */

static Lisp_Object CC_quotf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0001;
    stack[-7] = v0000;
/* end of prologue */
    v0119 = stack[-7];
    if (v0119 == nil) goto v0025;
    v0120 = stack[-7];
    v0119 = stack[-6];
    if (equal(v0120, v0119)) goto v0121;
    v0120 = stack[-6];
    v0119 = (Lisp_Object)17; /* 1 */
    if (v0120 == v0119) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    v0119 = stack[-6];
    if (!consp(v0119)) goto v0122;
    v0119 = stack[-6];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0123;

v0123:
    if (v0119 == nil) goto v0043;
    v0120 = stack[-7];
    v0119 = stack[-6];
    {
        popv(10);
        fn = elt(env, 4); /* quotfd */
        return (*qfn2(fn))(qenv(fn), v0120, v0119);
    }

v0043:
    v0119 = stack[-7];
    if (!consp(v0119)) goto v0124;
    v0119 = stack[-7];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0125;

v0125:
    if (v0119 == nil) goto v0037;
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0037:
    v0119 = stack[-7];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0120 = qcar(v0119);
    v0119 = stack[-6];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    if (v0120 == v0119) goto v0039;
    v0119 = stack[-7];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0120 = qcar(v0119);
    v0119 = stack[-6];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    fn = elt(env, 5); /* ordop */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    if (v0119 == nil) goto v0127;
    v0120 = stack[-7];
    v0119 = stack[-6];
    {
        popv(10);
        fn = elt(env, 6); /* quotk */
        return (*qfn2(fn))(qenv(fn), v0120, v0119);
    }

v0127:
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0039:
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v0128;

v0128:
    v0119 = stack[-7];
    fn = elt(env, 7); /* rank */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-4] = v0119;
    if (symbolp(v0119)) goto v0129;
    v0119 = stack[-6];
    fn = elt(env, 7); /* rank */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[0] = v0119;
    if (symbolp(v0119)) goto v0129;
    v0120 = stack[-4];
    v0119 = stack[0];
    v0119 = (Lisp_Object)lessp2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0119 = v0119 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0119 == nil)) goto v0129;
    v0119 = stack[-7];
    fn = elt(env, 8); /* lt!* */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-4] = v0119;
    v0119 = stack[-6];
    fn = elt(env, 8); /* lt!* */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[0] = v0119;
    v0119 = stack[-6];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    stack[-8] = v0119;
    v0119 = stack[-4];
    v0120 = qcdr(v0119);
    v0119 = stack[0];
    v0119 = qcdr(v0119);
    v0119 = CC_quotf1(env, v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-5] = v0119;
    v0119 = stack[-5];
    if (v0119 == nil) goto v0023;
    v0119 = stack[-4];
    v0119 = qcar(v0119);
    v0120 = qcdr(v0119);
    v0119 = stack[0];
    v0119 = qcar(v0119);
    v0119 = qcdr(v0119);
    v0119 = difference2(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[0] = v0119;
    v0120 = stack[0];
    v0119 = (Lisp_Object)1; /* 0 */
    if (v0120 == v0119) goto v0130;
    v0120 = stack[-8];
    v0119 = stack[0];
    v0119 = cons(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-3] = v0119;
    goto v0130;

v0130:
    v0119 = stack[-5];
    fn = elt(env, 9); /* negf */
    v0120 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    v0119 = stack[-6];
    v0119 = qcdr(v0119);
    fn = elt(env, 10); /* multf */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-4] = v0119;
    v0119 = stack[-7];
    stack[-7] = qcdr(v0119);
    v0120 = stack[0];
    v0119 = (Lisp_Object)1; /* 0 */
    if (v0120 == v0119) goto v0004;
    v0120 = stack[-3];
    v0119 = (Lisp_Object)17; /* 1 */
    v0119 = cons(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    v0120 = ncons(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    v0119 = stack[-4];
    fn = elt(env, 10); /* multf */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    goto v0131;

v0131:
    fn = elt(env, 11); /* addf */
    v0119 = (*qfn2(fn))(qenv(fn), stack[-7], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-7] = v0119;
    v0119 = stack[-7];
    if (v0119 == nil) goto v0132;
    v0119 = stack[-7];
    if (!consp(v0119)) goto v0133;
    v0119 = stack[-7];
    v0119 = qcar(v0119);
    v0119 = (consp(v0119) ? nil : lisp_true);
    goto v0134;

v0134:
    if (v0119 == nil) goto v0135;
    v0119 = qvalue(elt(env, 2)); /* t */
    goto v0136;

v0136:
    if (v0119 == nil) goto v0132;
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0132:
    v0120 = stack[0];
    v0119 = (Lisp_Object)1; /* 0 */
    if (v0120 == v0119) goto v0137;
    stack[0] = stack[-2];
    v0120 = stack[-3];
    v0119 = stack[-5];
    v0119 = cons(v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    v0119 = ncons(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    v0119 = Lnconc(nil, stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-9];
    stack[-2] = v0119;
    v0119 = stack[-7];
    if (!(v0119 == nil)) goto v0128;
    v0119 = stack[-1];
    if (v0119 == nil) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    v0120 = stack[-2];
    v0119 = stack[-1];
    {
        popv(10);
        fn = elt(env, 12); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v0120, v0119);
    }

v0137:
    v0119 = stack[-7];
    if (v0119 == nil) goto v0138;
    v0119 = qvalue(elt(env, 3)); /* !*mcd */
    if (v0119 == nil) goto v0139;
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0139:
    v0119 = stack[-5];
    stack[-1] = v0119;
    goto v0128;

v0138:
    v0120 = stack[-2];
    v0119 = stack[-5];
    {
        popv(10);
        fn = elt(env, 12); /* rnconc */
        return (*qfn2(fn))(qenv(fn), v0120, v0119);
    }

v0135:
    v0119 = stack[-7];
    v0119 = qcar(v0119);
    v0119 = qcar(v0119);
    v0120 = qcar(v0119);
    v0119 = stack[-8];
    v0119 = (v0120 == v0119 ? lisp_true : nil);
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0136;

v0133:
    v0119 = qvalue(elt(env, 2)); /* t */
    goto v0134;

v0004:
    v0119 = stack[-4];
    goto v0131;

v0023:
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0129:
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }

v0124:
    v0119 = qvalue(elt(env, 2)); /* t */
    goto v0125;

v0122:
    v0119 = qvalue(elt(env, 2)); /* t */
    goto v0123;

v0121:
    v0119 = (Lisp_Object)17; /* 1 */
    { popv(10); return onevalue(v0119); }

v0025:
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0119); }
/* error exit handlers */
v0126:
    popv(10);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0140, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0045 = stack[-1];
    v0140 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v0140 = (*qfn2(fn))(qenv(fn), v0045, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    if (v0140 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v0066:
    popv(2);
    return nil;
}



/* Code for kernord!-sort */

static Lisp_Object CC_kernordKsort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-sort");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[0] = nil;
    goto v0017;

v0017:
    v0143 = stack[-1];
    if (v0143 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0143 = stack[-1];
    v0144 = qcdr(v0143);
    v0143 = stack[-1];
    v0143 = qcar(v0143);
    fn = elt(env, 2); /* maxdeg */
    v0143 = (*qfn2(fn))(qenv(fn), v0144, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[-2] = v0143;
    v0143 = stack[-2];
    v0144 = qcar(v0143);
    v0143 = stack[-1];
    fn = elt(env, 3); /* delallasc */
    v0143 = (*qfn2(fn))(qenv(fn), v0144, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[-1] = v0143;
    v0143 = stack[-2];
    v0144 = qcar(v0143);
    v0143 = stack[0];
    v0143 = cons(v0144, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[0] = v0143;
    goto v0017;
/* error exit handlers */
v0114:
    popv(4);
    return nil;
}



/* Code for free!-powerp */

static Lisp_Object CC_freeKpowerp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for free-powerp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0145:
    v0141 = stack[0];
    if (!consp(v0141)) goto v0017;
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = (consp(v0141) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0141 == nil) goto v0072;
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0141); }

v0072:
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    v0141 = integerp(v0141);
    if (v0141 == nil) goto v0140;
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = qcdr(v0141);
    v0141 = CC_freeKpowerp(env, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0143;
    env = stack[-1];
    if (!(v0141 == nil)) { popv(2); return onevalue(v0141); }
    v0141 = stack[0];
    v0141 = qcdr(v0141);
    stack[0] = v0141;
    goto v0145;

v0140:
    v0141 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0141); }

v0017:
    v0141 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0143:
    popv(2);
    return nil;
}



/* Code for isvalid */

static Lisp_Object CC_isvalid(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isvalid");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0146 = stack[0];
    v0146 = Lcompress(nil, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0147 = Lsymbolp(nil, v0146);
    env = stack[-2];
    v0146 = qvalue(elt(env, 1)); /* t */
    if (equal(v0147, v0146)) goto v0066;
    v0146 = stack[0];
        popv(3);
        return Lcompress(nil, v0146);

v0066:
    v0146 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v0147 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0146 = qvalue(elt(env, 2)); /* functions!* */
    v0146 = Lassoc(nil, v0147, v0146);
    if (v0146 == nil) goto v0058;
    v0146 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0146); }

v0058:
    stack[-1] = elt(env, 3); /* !/ */
    v0146 = stack[0];
    v0146 = Lreverse(nil, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0146 = cons(stack[-1], v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0146 = Lreverse(nil, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[0] = v0146;
    v0146 = stack[0];
    fn = elt(env, 6); /* compress!* */
    v0147 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0146 = qvalue(elt(env, 2)); /* functions!* */
    v0146 = Lassoc(nil, v0147, v0146);
    if (v0146 == nil) goto v0143;
    v0146 = stack[0];
    qvalue(elt(env, 4)) = v0146; /* char */
    v0146 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0146); }

v0143:
    v0146 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0146); }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for multi_elem */

static Lisp_Object CC_multi_elem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multi_elem");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0069 = stack[0];
    v0070 = Llength(nil, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0069 = (Lisp_Object)17; /* 1 */
    if (v0070 == v0069) goto v0030;
    v0069 = stack[0];
    v0069 = qcar(v0069);
    fn = elt(env, 2); /* expression */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0069 = stack[0];
    v0069 = qcdr(v0069);
    v0069 = CC_multi_elem(env, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0025;

v0025:
    v0069 = nil;
    { popv(2); return onevalue(v0069); }

v0030:
    v0069 = stack[0];
    v0069 = qcar(v0069);
    fn = elt(env, 2); /* expression */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    goto v0025;
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for findrow */

static Lisp_Object CC_findrow(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0040, v0041;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findrow");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0149 = v0001;
    v0150 = v0000;
/* end of prologue */
    v0040 = v0150;
    v0040 = Lconsp(nil, v0040);
    env = stack[0];
    if (v0040 == nil) goto v0123;
    v0040 = v0150;
    v0040 = qcar(v0040);
    v0041 = elt(env, 1); /* sparsemat */
    if (!(v0040 == v0041)) goto v0123;
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    goto v0123;

v0123:
    v0149 = *(Lisp_Object *)((char *)v0150 + (CELL-TAG_VECTOR) + ((int32_t)v0149/(16/CELL)));
    { popv(1); return onevalue(v0149); }
}



/* Code for prepd */

static Lisp_Object CC_prepd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0110, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepd");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0109 = stack[0];
    if (!consp(v0109)) goto v0163;
    v0109 = stack[0];
    v0110 = qcar(v0109);
    v0109 = elt(env, 2); /* minusp */
    v0110 = get(v0110, v0109);
    env = stack[-2];
    v0109 = stack[0];
    v0109 = Lapply1(nil, v0110, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    if (v0109 == nil) goto v0062;
    v0109 = stack[0];
    fn = elt(env, 4); /* !:minus */
    v0109 = (*qfn1(fn))(qenv(fn), v0109);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    v0162 = v0109;
    v0109 = v0162;
    if (!consp(v0109)) goto v0124;
    v0109 = v0162;
    v0110 = qcar(v0109);
    v0109 = elt(env, 3); /* prepfn */
    v0109 = get(v0110, v0109);
    env = stack[-2];
    v0110 = v0162;
    v0109 = Lapply1(nil, v0109, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-2];
    goto v0125;

v0125:
    v0110 = v0109;
    v0109 = v0110;
    if (v0109 == nil) goto v0106;
    v0109 = elt(env, 1); /* minus */
    popv(3);
    return list2(v0109, v0110);

v0106:
    v0109 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0109); }

v0124:
    v0109 = v0162;
    goto v0125;

v0062:
    v0109 = stack[0];
    v0110 = qcar(v0109);
    v0109 = elt(env, 3); /* prepfn */
    v0110 = get(v0110, v0109);
    v0109 = stack[0];
        popv(3);
        return Lapply1(nil, v0110, v0109);

v0163:
    v0110 = stack[0];
    v0109 = (Lisp_Object)1; /* 0 */
    v0109 = (Lisp_Object)lessp2(v0110, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    v0109 = v0109 ? lisp_true : nil;
    env = stack[-2];
    if (v0109 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 1); /* minus */
    v0109 = stack[0];
    v0109 = negate(v0109);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    {
        Lisp_Object v0012 = stack[-1];
        popv(3);
        return list2(v0012, v0109);
    }
/* error exit handlers */
v0027:
    popv(3);
    return nil;
}



/* Code for bcint2op */

static Lisp_Object MS_CDECL CC_bcint2op(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0022, v0013, v0014, v0170;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bcint2op");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcint2op");
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0170 = v0002;
    v0013 = v0001;
    v0014 = v0000;
/* end of prologue */
    v0024 = qvalue(elt(env, 1)); /* dmode!* */
    if (v0024 == nil) goto v0118;
    v0024 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0121:
    if (v0024 == nil) goto v0035;
    v0022 = v0014;
    v0024 = (Lisp_Object)1; /* 0 */
    if (v0022 == v0024) goto v0171;
    v0024 = v0014;
    v0022 = v0024;
    goto v0027;

v0027:
    v0024 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0022, v0024);

v0171:
    v0024 = qvalue(elt(env, 2)); /* nil */
    v0022 = v0024;
    goto v0027;

v0035:
    v0024 = nil;
    { popv(1); return onevalue(v0024); }

v0118:
    v0022 = (Lisp_Object)17; /* 1 */
    v0024 = v0014;
    v0024 = qcdr(v0024);
    if (v0022 == v0024) goto v0071;
    v0024 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0071:
    v0024 = v0014;
    v0024 = qcar(v0024);
    v0014 = v0024;
    if (is_number(v0024)) goto v0149;
    v0024 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0149:
    v0022 = (Lisp_Object)17; /* 1 */
    v0024 = v0013;
    v0024 = qcdr(v0024);
    if (v0022 == v0024) goto v0172;
    v0024 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0172:
    v0024 = v0013;
    v0024 = qcar(v0024);
    v0013 = v0024;
    if (is_number(v0024)) goto v0146;
    v0024 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0146:
    v0022 = v0170;
    v0024 = elt(env, 3); /* times */
    if (v0022 == v0024) goto v0173;
    v0022 = v0170;
    v0024 = elt(env, 4); /* plus */
    if (v0022 == v0024) goto v0087;
    v0024 = v0170;
    v0022 = v0014;
    v0024 = Lapply2(nil, 3, v0024, v0022, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[0];
    goto v0175;

v0175:
    v0014 = v0024;
    goto v0121;

v0087:
    v0024 = v0014;
    v0022 = v0013;
    v0024 = plus2(v0024, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[0];
    goto v0175;

v0173:
    v0024 = v0014;
    v0022 = v0013;
    v0024 = times2(v0024, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[0];
    goto v0175;
/* error exit handlers */
v0174:
    popv(1);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0146, v0147, v0176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convchk");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0146 = v0000;
/* end of prologue */
    v0147 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v0147 == nil) goto v0025;
    v0147 = v0146;
    if (!(!consp(v0147))) { popv(1); return onevalue(v0146); }
    v0147 = v0146;
    v0147 = Lfloatp(nil, v0147);
    env = stack[0];
    if (v0147 == nil) goto v0045;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v0146);
    }

v0045:
    v0147 = v0146;
    if (!(!consp(v0147))) goto v0142;
    v0147 = v0146;
    v0147 = integerp(v0147);
    if (v0147 == nil) goto v0143;
    v0176 = elt(env, 2); /* !:rd!: */
    v0147 = v0146;
    v0146 = (Lisp_Object)1; /* 0 */
    v0146 = list2star(v0176, v0147, v0146);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[0];
    goto v0142;

v0142:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0146);
    }

v0143:
    fn = elt(env, 5); /* read!:num */
    v0146 = (*qfn1(fn))(qenv(fn), v0146);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[0];
    goto v0142;

v0025:
    v0147 = v0146;
    if (!consp(v0147)) { popv(1); return onevalue(v0146); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v0146);
    }
/* error exit handlers */
v0177:
    popv(1);
    return nil;
}



/* Code for prin2!-downcase */

static Lisp_Object CC_prin2Kdowncase(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0178, v0156;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2-downcase");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0114 = v0000;
/* end of prologue */
    v0114 = Lexplodec(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-1];
    stack[0] = v0114;
    goto v0025;

v0025:
    v0114 = stack[0];
    if (v0114 == nil) goto v0179;
    v0114 = stack[0];
    v0114 = qcar(v0114);
    v0156 = v0114;
    v0114 = v0156;
    v0114 = Lalpha_char_p(nil, v0114);
    env = stack[-1];
    if (v0114 == nil) goto v0169;
    v0178 = v0156;
    v0114 = qvalue(elt(env, 2)); /* charassoc!* */
    v0114 = Latsoc(nil, v0178, v0114);
    v0178 = v0114;
    v0114 = v0178;
    if (v0114 == nil) goto v0040;
    v0114 = v0178;
    v0114 = qcdr(v0114);
    goto v0148;

v0148:
    v0114 = Lprinc(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-1];
    goto v0161;

v0161:
    v0114 = stack[0];
    v0114 = qcdr(v0114);
    stack[0] = v0114;
    goto v0025;

v0040:
    v0114 = v0156;
    goto v0148;

v0169:
    v0114 = v0156;
    v0114 = Lprinc(nil, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0125;
    env = stack[-1];
    goto v0161;

v0179:
    v0114 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0114); }
/* error exit handlers */
v0125:
    popv(2);
    return nil;
}



/* Code for opmtch!* */

static Lisp_Object CC_opmtchH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch*");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0057 = v0000;
/* end of prologue */
    v0163 = qvalue(elt(env, 1)); /* subfg!* */
    stack[0] = v0163;
    v0163 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0163; /* subfg!* */
    v0163 = v0057;
    fn = elt(env, 3); /* opmtch */
    v0163 = (*qfn1(fn))(qenv(fn), v0163);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-1];
    v0057 = v0163;
    v0163 = stack[0];
    qvalue(elt(env, 1)) = v0163; /* subfg!* */
    { popv(2); return onevalue(v0057); }
/* error exit handlers */
v0071:
    popv(2);
    return nil;
}



/* Code for repeatsp */

static Lisp_Object CC_repeatsp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0069;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeatsp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0116 = v0000;
/* end of prologue */

v0145:
    v0115 = v0116;
    if (v0115 == nil) goto v0072;
    v0115 = v0116;
    v0069 = qcar(v0115);
    v0115 = v0116;
    v0115 = qcdr(v0115);
    v0115 = Lmember(nil, v0069, v0115);
    if (!(v0115 == nil)) return onevalue(v0115);
    v0115 = v0116;
    v0115 = qcdr(v0115);
    v0116 = v0115;
    goto v0145;

v0072:
    v0115 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0115);
}



/* Code for nonzero!-length */

static Lisp_Object CC_nonzeroKlength(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0043, v0042;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonzero-length");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */

v0072:
    v0070 = v0043;
    if (v0070 == nil) goto v0035;
    v0070 = v0043;
    v0042 = qcar(v0070);
    v0070 = (Lisp_Object)1; /* 0 */
    if (v0042 == v0070) goto v0180;
    v0070 = v0043;
    v0070 = qcdr(v0070);
    v0070 = CC_nonzeroKlength(env, v0070);
    errexit();
    return add1(v0070);

v0180:
    v0070 = v0043;
    v0070 = qcdr(v0070);
    v0043 = v0070;
    goto v0072;

v0035:
    v0070 = (Lisp_Object)1; /* 0 */
    return onevalue(v0070);
}



/* Code for bas_rep */

static Lisp_Object CC_bas_rep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_rep");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0180 = v0000;
/* end of prologue */
    v0163 = v0180;
    v0180 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v0180 = (*qfn2(fn))(qenv(fn), v0163, v0180);
    errexit();
    v0180 = qcar(v0180);
    return onevalue(v0180);
}



/* Code for prin2!* */

static Lisp_Object CC_prin2H(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0135, v0200, v0201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prin2*");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0135 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v0135 == nil) goto v0148;
    v0200 = qvalue(elt(env, 1)); /* outputhandler!* */
    v0201 = elt(env, 0); /* prin2!* */
    v0135 = stack[-2];
        popv(5);
        return Lapply2(nil, 3, v0200, v0201, v0135);

v0148:
    v0200 = stack[-2];
    v0135 = elt(env, 2); /* oldnam */
    v0135 = get(v0200, v0135);
    env = stack[-4];
    v0200 = v0135;
    if (v0135 == nil) goto v0043;
    v0135 = v0200;
    stack[-2] = v0135;
    goto v0043;

v0043:
    v0135 = qvalue(elt(env, 3)); /* overflowed!* */
    if (v0135 == nil) goto v0144;
    v0135 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0135); }

v0144:
    v0135 = qvalue(elt(env, 5)); /* !*fort */
    if (v0135 == nil) goto v0114;
    v0135 = stack[-2];
    {
        popv(5);
        fn = elt(env, 18); /* fprin2!* */
        return (*qfn1(fn))(qenv(fn), v0135);
    }

v0114:
    v0135 = qvalue(elt(env, 6)); /* !*nat */
    if (v0135 == nil) goto v0169;
    v0200 = stack[-2];
    v0135 = elt(env, 7); /* pi */
    if (v0200 == v0135) goto v0060;
    v0200 = stack[-2];
    v0135 = elt(env, 9); /* infinity */
    if (!(v0200 == v0135)) goto v0169;
    v0135 = elt(env, 9); /* infinity */
    fn = elt(env, 19); /* symbol */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0169;

v0169:
    v0135 = stack[-2];
    v0135 = Llengthc(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[-1] = v0135;
    v0135 = stack[-2];
    v0135 = integerp(v0135);
    if (v0135 == nil) goto v0018;
    v0200 = stack[-1];
    v0135 = (Lisp_Object)801; /* 50 */
    v0135 = (Lisp_Object)greaterp2(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0135 = v0135 ? lisp_true : nil;
    env = stack[-4];
    if (v0135 == nil) goto v0018;
    v0135 = qvalue(elt(env, 10)); /* !*rounded */
    if (v0135 == nil) goto v0018;
    v0135 = stack[-2];
    fn = elt(env, 20); /* chkint!* */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0200 = v0135;
    if (!(!consp(v0200))) goto v0203;
    v0200 = elt(env, 11); /* !:rd!: */
    v0135 = cons(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0203;

v0203:
    v0200 = v0135;
    v0135 = v0200;
    v0135 = qcdr(v0135);
    if (!consp(v0135)) goto v0108;
    v0135 = v0200;
    stack[0] = v0135;
    goto v0204;

v0204:
    v0200 = qvalue(elt(env, 12)); /* !:bprec!: */
    v0135 = (Lisp_Object)49; /* 3 */
    v0135 = difference2(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    fn = elt(env, 21); /* round!:mt */
    v0135 = (*qfn2(fn))(qenv(fn), stack[0], v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    fn = elt(env, 22); /* csl_normbf */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 23); /* bfprin0 */
        return (*qfn1(fn))(qenv(fn), v0135);
    }

v0108:
    v0135 = v0200;
    v0135 = qcdr(v0135);
    fn = elt(env, 24); /* fl2bf */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[0] = v0135;
    goto v0204;

v0018:
    v0200 = qvalue(elt(env, 13)); /* posn!* */
    v0135 = stack[-1];
    v0135 = (Lisp_Object)(int32_t)((int32_t)v0200 + (int32_t)v0135 - TAG_FIXNUM);
    stack[-3] = v0135;
    v0135 = qvalue(elt(env, 14)); /* nil */
    v0200 = Llinelength(nil, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    v0135 = qvalue(elt(env, 15)); /* spare!* */
    v0135 = difference2(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[0] = v0135;
    v0200 = stack[-3];
    v0135 = stack[0];
    v0135 = (Lisp_Object)lesseq2(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0135 = v0135 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0135 == nil)) goto v0097;
    v0135 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (v0135 == nil) goto v0205;
    v0135 = qvalue(elt(env, 14)); /* nil */
    goto v0206;

v0206:
    if (!(v0135 == nil)) goto v0097;
    v0135 = qvalue(elt(env, 16)); /* testing!-width!* */
    if (v0135 == nil) goto v0133;
    v0135 = qvalue(elt(env, 17)); /* t */
    qvalue(elt(env, 3)) = v0135; /* overflowed!* */
    v0135 = elt(env, 4); /* overflowed */
    { popv(5); return onevalue(v0135); }

v0133:
    v0201 = stack[-2];
    v0135 = qvalue(elt(env, 13)); /* posn!* */
    v0200 = (Lisp_Object)((int32_t)(v0135) + 0x10);
    v0135 = stack[0];
    v0135 = (Lisp_Object)((int32_t)(v0135) - 0x10);
    {
        popv(5);
        fn = elt(env, 25); /* prin2lint */
        return (*qfnn(fn))(qenv(fn), 3, v0201, v0200, v0135);
    }

v0097:
    v0200 = stack[-2];
    v0135 = stack[-3];
    {
        popv(5);
        fn = elt(env, 26); /* add_prin_char */
        return (*qfn2(fn))(qenv(fn), v0200, v0135);
    }

v0205:
    v0135 = stack[-2];
    v0135 = integerp(v0135);
    if (!(v0135 == nil)) goto v0051;
    v0135 = qvalue(elt(env, 17)); /* t */
    fn = elt(env, 27); /* terpri!* */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    goto v0051;

v0051:
    v0200 = qvalue(elt(env, 13)); /* posn!* */
    v0135 = stack[-1];
    v0200 = (Lisp_Object)(int32_t)((int32_t)v0200 + (int32_t)v0135 - TAG_FIXNUM);
    stack[-3] = v0200;
    v0135 = stack[0];
    v0135 = (Lisp_Object)lesseq2(v0200, v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0135 = v0135 ? lisp_true : nil;
    env = stack[-4];
    goto v0206;

v0060:
    v0135 = elt(env, 8); /* !.pi */
    fn = elt(env, 19); /* symbol */
    v0135 = (*qfn1(fn))(qenv(fn), v0135);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-4];
    stack[-2] = v0135;
    goto v0169;
/* error exit handlers */
v0202:
    popv(5);
    return nil;
}



/* Code for lcm */

static Lisp_Object CC_lcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177, v0038, v0039, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0039 = v0001;
    v0036 = v0000;
/* end of prologue */
    v0177 = v0036;
    if (v0177 == nil) goto v0121;
    v0177 = v0039;
    v0177 = (v0177 == nil ? lisp_true : nil);
    goto v0017;

v0017:
    if (v0177 == nil) goto v0045;
    v0177 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0177); }

v0045:
    v0038 = v0036;
    v0177 = (Lisp_Object)17; /* 1 */
    if (v0038 == v0177) { popv(3); return onevalue(v0039); }
    v0038 = v0039;
    v0177 = (Lisp_Object)17; /* 1 */
    if (v0038 == v0177) { popv(3); return onevalue(v0036); }
    stack[-1] = v0036;
    stack[0] = v0039;
    v0177 = v0036;
    v0038 = v0039;
    fn = elt(env, 3); /* gcdf */
    v0177 = (*qfn2(fn))(qenv(fn), v0177, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    fn = elt(env, 4); /* quotf */
    v0177 = (*qfn2(fn))(qenv(fn), stack[0], v0177);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-2];
    {
        Lisp_Object v0208 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v0208, v0177);
    }

v0121:
    v0177 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0207:
    popv(3);
    return nil;
}



/* Code for lispapply */

static Lisp_Object CC_lispapply(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispapply");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0150 = v0001;
    v0040 = v0000;
/* end of prologue */
    v0149 = v0040;
    if (!consp(v0149)) goto v0042;
    v0149 = elt(env, 1); /* "Apply called with non-id arg" */
    v0150 = v0040;
    v0149 = list2(v0149, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[0];
    v0150 = v0149;
    v0149 = v0150;
    qvalue(elt(env, 2)) = v0149; /* errmsg!* */
    v0149 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0149 == nil)) goto v0044;
    v0149 = v0150;
    fn = elt(env, 4); /* lprie */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[0];
    goto v0044;

v0044:
    v0149 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0149 = nil;
    { popv(1); return onevalue(v0149); }

v0042:
    v0149 = v0040;
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0149, v0150);
    }
/* error exit handlers */
v0041:
    popv(1);
    return nil;
}



/* Code for sfto_reorder */

static Lisp_Object CC_sfto_reorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_reorder");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0068 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    fn = elt(env, 1); /* setkorder */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    stack[-1] = v0068;
    v0068 = stack[0];
    fn = elt(env, 2); /* reorder */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    stack[0] = v0068;
    v0068 = stack[-1];
    fn = elt(env, 1); /* setkorder */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v0118:
    popv(3);
    return nil;
}



/* Code for rl_smmkatl */

static Lisp_Object MS_CDECL CC_rl_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smmkatl");
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0115 = v0003;
    v0116 = v0002;
    v0069 = v0001;
    v0070 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smmkatl!* */
    v0115 = list4(v0070, v0069, v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        Lisp_Object v0123 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0123, v0115);
    }
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for resimp */

static Lisp_Object CC_resimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resimp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */
    v0030 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0030; /* varstack!* */
    v0030 = v0035;
    fn = elt(env, 3); /* resimp1 */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0030); }
/* error exit handlers */
v0121:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for pasf_smwupdknowl */

static Lisp_Object MS_CDECL CC_pasf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0141, v0169, v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_smwupdknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0003;
    v0141 = v0002;
    v0169 = v0001;
    v0143 = v0000;
/* end of prologue */
    v0040 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0040 == nil) goto v0116;
    v0040 = v0143;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0040, v0169, v0141, v0041);
    }

v0116:
    v0040 = v0143;
    {
        fn = elt(env, 3); /* cl_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0040, v0169, v0141, v0041);
    }
}



/* Code for ibalp_csat */

static Lisp_Object CC_ibalp_csat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0069;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_csat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0116 = v0000;
/* end of prologue */

v0145:
    v0069 = v0116;
    if (v0069 == nil) goto v0072;
    v0069 = v0116;
    v0069 = qcar(v0069);
    v0069 = qcdr(v0069);
    v0069 = qcdr(v0069);
    v0069 = qcdr(v0069);
    v0069 = qcdr(v0069);
    v0069 = qcar(v0069);
    if (v0069 == nil) goto v0163;
    v0116 = qcdr(v0116);
    goto v0145;

v0163:
    v0116 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0116);

v0072:
    v0116 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0116);
}



/* Code for cgp_evlmon */

static Lisp_Object CC_cgp_evlmon(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_evlmon");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0025 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_evlmon */
        return (*qfn1(fn))(qenv(fn), v0025);
    }
/* error exit handlers */
v0030:
    popv(1);
    return nil;
}



/* Code for rl_sacatlp */

static Lisp_Object CC_rl_sacatlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_sacatlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0161 = v0001;
    v0140 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_sacatlp!* */
    v0161 = list2(v0140, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    {
        Lisp_Object v0067 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0067, v0161);
    }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for indent!* */

static Lisp_Object CC_indentH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0209;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indent*");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0209 = stack[0];
    v0172 = qvalue(elt(env, 1)); /* t */
    if (!(equal(v0209, v0172))) goto v0025;
    v0209 = qvalue(elt(env, 2)); /* indent */
    v0172 = qvalue(elt(env, 3)); /* ind */
    v0172 = plus2(v0209, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0172; /* indent */
    goto v0025;

v0025:
    v0172 = stack[0];
    if (!(v0172 == nil)) goto v0142;
    v0209 = qvalue(elt(env, 2)); /* indent */
    v0172 = qvalue(elt(env, 3)); /* ind */
    v0172 = difference2(v0209, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0172; /* indent */
    goto v0142;

v0142:
    v0172 = nil;
    { popv(2); return onevalue(v0172); }
/* error exit handlers */
v0150:
    popv(2);
    return nil;
}



/* Code for isarb_compl */

static Lisp_Object CC_isarb_compl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0043, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_compl");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    v0070 = v0043;
    v0070 = Lconsp(nil, v0070);
    env = stack[0];
    if (v0070 == nil) goto v0025;
    v0070 = v0043;
    v0042 = qcar(v0070);
    v0070 = elt(env, 1); /* arbcomplex */
    if (v0042 == v0070) goto v0163;
    v0070 = v0043;
    v0070 = qcdr(v0070);
    fn = elt(env, 4); /* multi_isarb_compl */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    goto v0025;

v0025:
    v0070 = nil;
    { popv(1); return onevalue(v0070); }

v0163:
    v0070 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0070; /* found_compl */
    goto v0025;
/* error exit handlers */
v0123:
    popv(1);
    return nil;
}



/* Code for round!:mt */

static Lisp_Object CC_roundTmt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for round:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0013 = stack[-2];
    v0022 = elt(env, 1); /* !:rd!: */
    if (!consp(v0013)) goto v0116;
    v0013 = qcar(v0013);
    if (!(v0013 == v0022)) goto v0116;
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = (consp(v0022) ? nil : lisp_true);
    v0022 = (v0022 == nil ? lisp_true : nil);
    goto v0163;

v0163:
    if (v0022 == nil) goto v0159;
    v0022 = stack[-1];
    v0022 = integerp(v0022);
    if (v0022 == nil) goto v0123;
    v0013 = stack[-1];
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = (Lisp_Object)greaterp2(v0013, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-4];
    goto v0017;

v0017:
    if (v0022 == nil) goto v0214;
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    v0022 = Labsval(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    fn = elt(env, 4); /* msd */
    v0013 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    v0022 = stack[-1];
    v0022 = difference2(v0013, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    v0013 = sub1(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    stack[-1] = v0013;
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = (Lisp_Object)lessp2(v0013, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0022 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0013 = stack[-1];
    v0022 = (Lisp_Object)1; /* 0 */
    if (v0013 == v0022) goto v0155;
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    stack[0] = qcar(v0022);
    v0022 = stack[-1];
    v0022 = negate(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0013 = qcdr(v0022);
    v0022 = stack[-1];
    v0022 = plus2(v0013, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    v0022 = list2star(stack[-3], stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0155:
    v0022 = stack[-2];
    {
        popv(5);
        fn = elt(env, 5); /* round!:last */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0214:
    stack[0] = (Lisp_Object)1; /* 0 */
    v0013 = elt(env, 3); /* "Invalid argument to" */
    v0022 = elt(env, 0); /* round!:mt */
    v0022 = list2(v0013, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0204;
    env = stack[-4];
    {
        Lisp_Object v0215 = stack[0];
        popv(5);
        fn = elt(env, 6); /* error */
        return (*qfn2(fn))(qenv(fn), v0215, v0022);
    }

v0123:
    v0022 = qvalue(elt(env, 2)); /* nil */
    goto v0017;

v0159:
    v0022 = qvalue(elt(env, 2)); /* nil */
    goto v0017;

v0116:
    v0022 = qvalue(elt(env, 2)); /* nil */
    goto v0163;
/* error exit handlers */
v0204:
    popv(5);
    return nil;
}



/* Code for revlis */

static Lisp_Object CC_revlis(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revlis");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0143 = v0000;
/* end of prologue */
    stack[-3] = v0143;
    v0143 = stack[-3];
    if (v0143 == nil) goto v0180;
    v0143 = stack[-3];
    v0143 = qcar(v0143);
    fn = elt(env, 2); /* reval */
    v0143 = (*qfn1(fn))(qenv(fn), v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-4];
    v0143 = ncons(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-4];
    stack[-1] = v0143;
    stack[-2] = v0143;
    goto v0035;

v0035:
    v0143 = stack[-3];
    v0143 = qcdr(v0143);
    stack[-3] = v0143;
    v0143 = stack[-3];
    if (v0143 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0143 = stack[-3];
    v0143 = qcar(v0143);
    fn = elt(env, 2); /* reval */
    v0143 = (*qfn1(fn))(qenv(fn), v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-4];
    v0143 = ncons(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-4];
    v0143 = Lrplacd(nil, stack[0], v0143);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-4];
    v0143 = stack[-1];
    v0143 = qcdr(v0143);
    stack[-1] = v0143;
    goto v0035;

v0180:
    v0143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0143); }
/* error exit handlers */
v0114:
    popv(5);
    return nil;
}



/* Code for downwght */

static Lisp_Object CC_downwght(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for downwght");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0071 = stack[-1];
    fn = elt(env, 1); /* delhisto */
    v0071 = (*qfn1(fn))(qenv(fn), v0071);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0117 = stack[-1];
    v0071 = stack[0];
    fn = elt(env, 2); /* downwght1 */
    v0071 = (*qfn2(fn))(qenv(fn), v0117, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-2];
    v0071 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* inshisto */
        return (*qfn1(fn))(qenv(fn), v0071);
    }
/* error exit handlers */
v0140:
    popv(3);
    return nil;
}



/* Code for ordad */

static Lisp_Object CC_ordad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordad");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0017;

v0017:
    v0173 = stack[0];
    if (v0173 == nil) goto v0149;
    v0207 = stack[-1];
    v0173 = stack[0];
    v0173 = qcar(v0173);
    fn = elt(env, 2); /* ordp */
    v0173 = (*qfn2(fn))(qenv(fn), v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    if (!(v0173 == nil)) goto v0149;
    v0173 = stack[0];
    v0207 = qcar(v0173);
    v0173 = stack[-2];
    v0173 = cons(v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    stack[-2] = v0173;
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    stack[0] = v0173;
    goto v0017;

v0149:
    v0207 = stack[-1];
    v0173 = stack[0];
    v0173 = cons(v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    stack[0] = v0173;
    goto v0159;

v0159:
    v0173 = stack[-2];
    if (v0173 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0173 = stack[-2];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    v0207 = stack[-2];
    v0173 = stack[0];
    v0173 = Lrplacd(nil, v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-3];
    v0173 = stack[-2];
    stack[0] = v0173;
    v0173 = stack[-1];
    stack[-2] = v0173;
    goto v0159;
/* error exit handlers */
v0168:
    popv(4);
    return nil;
}



/* Code for xdiv */

static Lisp_Object CC_xdiv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdiv");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = stack[-1];
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = ncons(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-3];
    if (equal(stack[-2], v0169)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0143 = stack[-1];
    v0169 = stack[0];
    fn = elt(env, 1); /* sublistp */
    v0169 = (*qfn2(fn))(qenv(fn), v0143, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-3];
    if (v0169 == nil) goto v0118;
    v0143 = stack[0];
    v0169 = stack[-1];
    fn = elt(env, 2); /* listdiff */
    v0169 = (*qfn2(fn))(qenv(fn), v0143, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    stack[0] = v0169;
    if (!(v0169 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0169 = (Lisp_Object)17; /* 1 */
    popv(4);
    return ncons(v0169);

v0118:
    v0169 = nil;
    { popv(4); return onevalue(v0169); }
/* error exit handlers */
v0113:
    popv(4);
    return nil;
}



/* Code for scprint */

static Lisp_Object CC_scprint(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0173, v0207;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    v0207 = v0000;
/* end of prologue */
    v0173 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0173; /* posn!* */
    v0173 = v0207;
    stack[-1] = v0173;
    goto v0179;

v0179:
    v0173 = stack[-1];
    if (v0173 == nil) goto v0121;
    v0173 = stack[-1];
    v0173 = qcar(v0173);
    stack[0] = v0173;
    v0173 = stack[0];
    v0173 = qcar(v0173);
    v0207 = qcdr(v0173);
    v0173 = stack[-2];
    if (!(equal(v0207, v0173))) goto v0067;
    v0173 = stack[0];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0207 = qcar(v0173);
    v0173 = qvalue(elt(env, 1)); /* posn!* */
    v0207 = difference2(v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    stack[-3] = v0207;
    v0173 = (Lisp_Object)1; /* 0 */
    v0173 = (Lisp_Object)lessp2(v0207, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    v0173 = v0173 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0173 == nil)) goto v0058;
    v0173 = stack[-3];
    v0173 = Lxtab(nil, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    goto v0058;

v0058:
    v0173 = stack[0];
    v0173 = qcdr(v0173);
    v0173 = Lprinc(nil, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-4];
    v0173 = stack[0];
    v0173 = qcar(v0173);
    v0173 = qcar(v0173);
    v0173 = qcdr(v0173);
    qvalue(elt(env, 1)) = v0173; /* posn!* */
    goto v0067;

v0067:
    v0173 = stack[-1];
    v0173 = qcdr(v0173);
    stack[-1] = v0173;
    goto v0179;

v0121:
    v0173 = nil;
    { popv(5); return onevalue(v0173); }
/* error exit handlers */
v0157:
    popv(5);
    return nil;
}



/* Code for !:difference */

static Lisp_Object CC_Tdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0216, v0060, v0146, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :difference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0146 = v0001;
    v0147 = v0000;
/* end of prologue */
    v0216 = v0147;
    if (v0216 == nil) goto v0025;
    v0216 = v0146;
    if (v0216 == nil) return onevalue(v0147);
    v0060 = v0147;
    v0216 = v0146;
    if (equal(v0060, v0216)) goto v0068;
    v0216 = v0147;
    if (!consp(v0216)) goto v0069;
    v0216 = qvalue(elt(env, 1)); /* nil */
    goto v0116;

v0116:
    if (v0216 == nil) goto v0159;
    v0216 = v0147;
    v0060 = v0146;
    return difference2(v0216, v0060);

v0159:
    v0060 = v0147;
    v0216 = elt(env, 2); /* difference */
    {
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0060, v0146, v0216);
    }

v0069:
    v0216 = v0146;
    v0216 = (consp(v0216) ? nil : lisp_true);
    goto v0116;

v0068:
    v0216 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0216);

v0025:
    v0216 = v0146;
    {
        fn = elt(env, 4); /* !:minus */
        return (*qfn1(fn))(qenv(fn), v0216);
    }
}



/* Code for add2inputbuf */

static Lisp_Object CC_add2inputbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2inputbuf");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0041 = v0001;
    v0040 = v0000;
/* end of prologue */
    v0141 = qvalue(elt(env, 1)); /* !*int */
    if (v0141 == nil) goto v0180;
    v0141 = qvalue(elt(env, 2)); /* ifl!* */
    if (!(v0141 == nil)) goto v0180;
    v0141 = qvalue(elt(env, 4)); /* !*nosave!* */
    goto v0179;

v0179:
    if (v0141 == nil) goto v0070;
    v0040 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0040); }

v0070:
    v0141 = qvalue(elt(env, 6)); /* statcounter */
    v0041 = list3(v0141, v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[0];
    v0040 = qvalue(elt(env, 7)); /* inputbuflis!* */
    v0040 = cons(v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[0];
    qvalue(elt(env, 7)) = v0040; /* inputbuflis!* */
    v0040 = nil;
    { popv(1); return onevalue(v0040); }

v0180:
    v0141 = qvalue(elt(env, 3)); /* t */
    goto v0179;
/* error exit handlers */
v0169:
    popv(1);
    return nil;
}



/* Code for fs!:angle!-order */

static Lisp_Object CC_fsTangleKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0107, v0219;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:angle-order");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0021 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0021;
    v0107 = stack[-3];
    v0021 = (Lisp_Object)33; /* 2 */
    v0021 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    stack[-1] = v0021;
    v0107 = stack[-2];
    v0021 = (Lisp_Object)33; /* 2 */
    v0021 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    stack[0] = v0021;
    goto v0122;

v0122:
    v0107 = stack[-1];
    v0021 = stack[-4];
    v0219 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    v0107 = stack[0];
    v0021 = stack[-4];
    v0021 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    v0021 = difference2(v0219, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-5];
    v0219 = v0021;
    v0107 = v0219;
    v0021 = (Lisp_Object)1; /* 0 */
    if (v0107 == v0021) goto v0178;
    v0107 = v0219;
    v0021 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v0107, v0021);

v0178:
    v0021 = stack[-4];
    v0021 = add1(v0021);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-5];
    stack[-4] = v0021;
    v0107 = stack[-4];
    v0021 = (Lisp_Object)129; /* 8 */
    v0021 = (Lisp_Object)lessp2(v0107, v0021);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0021 = v0021 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0021 == nil)) goto v0122;
    v0107 = stack[-3];
    v0021 = (Lisp_Object)17; /* 1 */
    v0219 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    v0107 = stack[-2];
    v0021 = (Lisp_Object)17; /* 1 */
    v0021 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    if (equal(v0219, v0021)) goto v0087;
    v0107 = stack[-3];
    v0021 = (Lisp_Object)17; /* 1 */
    v0107 = *(Lisp_Object *)((char *)v0107 + (CELL-TAG_VECTOR) + ((int32_t)v0021/(16/CELL)));
    v0021 = elt(env, 2); /* sin */
    if (v0107 == v0021) goto v0153;
    v0021 = qvalue(elt(env, 3)); /* t */
    { popv(6); return onevalue(v0021); }

v0153:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0021); }

v0087:
    v0021 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0021); }
/* error exit handlers */
v0022:
    popv(6);
    return nil;
}



/* Code for mo!=sum */

static Lisp_Object CC_moMsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0216, v0060;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=sum");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0060 = nil;
    goto v0017;

v0017:
    v0175 = stack[-1];
    if (v0175 == nil) goto v0040;
    v0175 = stack[0];
    if (v0175 == nil) goto v0040;
    v0175 = stack[-1];
    v0216 = qcar(v0175);
    v0175 = stack[0];
    v0175 = qcar(v0175);
    v0175 = (Lisp_Object)(int32_t)((int32_t)v0216 + (int32_t)v0175 - TAG_FIXNUM);
    v0216 = v0060;
    v0175 = cons(v0175, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-2];
    v0060 = v0175;
    v0175 = stack[-1];
    v0175 = qcdr(v0175);
    stack[-1] = v0175;
    v0175 = stack[0];
    v0175 = qcdr(v0175);
    stack[0] = v0175;
    goto v0017;

v0040:
    v0175 = v0060;
    v0216 = Lnreverse(nil, v0175);
    v0175 = stack[-1];
    if (v0175 == nil) goto v0125;
    v0175 = stack[-1];
    goto v0169;

v0169:
        popv(3);
        return Lappend(nil, v0216, v0175);

v0125:
    v0175 = stack[0];
    goto v0169;
/* error exit handlers */
v0176:
    popv(3);
    return nil;
}



/* Code for rev */

static Lisp_Object CC_rev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0069, v0070;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rev");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0116 = v0001;
    v0069 = v0000;
/* end of prologue */

v0030:
    v0070 = v0069;
    if (v0070 == nil) { popv(2); return onevalue(v0116); }
    v0070 = v0069;
    v0070 = qcdr(v0070);
    stack[0] = v0070;
    v0069 = qcar(v0069);
    v0116 = cons(v0069, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0069 = stack[0];
    goto v0030;
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod#");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0148 = v0000;
/* end of prologue */
    v0058 = v0148;
    v0148 = qvalue(elt(env, 1)); /* current!-modulus */
    v0148 = Cremainder(v0058, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-1];
    stack[0] = v0148;
    v0058 = stack[0];
    v0148 = (Lisp_Object)1; /* 0 */
    v0148 = (Lisp_Object)lessp2(v0058, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    v0148 = v0148 ? lisp_true : nil;
    env = stack[-1];
    if (v0148 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0148 = stack[0];
    v0058 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v0148, v0058);
/* error exit handlers */
v0209:
    popv(2);
    return nil;
}



/* Code for anforml */

static Lisp_Object CC_anforml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0220, v0221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for anforml");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0030:
    v0220 = stack[0];
    if (!consp(v0220)) goto v0025;
    v0220 = stack[0];
    v0220 = qcar(v0220);
    fn = elt(env, 6); /* anform */
    v0220 = (*qfn1(fn))(qenv(fn), v0220);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    v0220 = stack[0];
    v0220 = qcdr(v0220);
    stack[0] = v0220;
    goto v0030;

v0025:
    v0220 = stack[0];
    if (v0220 == nil) goto v0140;
    v0220 = qvalue(elt(env, 2)); /* !*globals */
    if (v0220 == nil) goto v0140;
    v0220 = stack[0];
    if (v0220 == nil) goto v0140;
    v0221 = stack[0];
    v0220 = lisp_true;
    if (v0221 == v0220) goto v0176;
    v0220 = stack[0];
    if (symbolp(v0220)) goto v0112;
    v0220 = qvalue(elt(env, 1)); /* nil */
    goto v0148;

v0148:
    if (v0220 == nil) goto v0140;
    v0221 = stack[0];
    v0220 = elt(env, 4); /* glb2rf */
    v0220 = Lflagp(nil, v0221, v0220);
    env = stack[-1];
    if (!(v0220 == nil)) goto v0140;
    v0220 = stack[0];
    v0221 = ncons(v0220);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    v0220 = elt(env, 4); /* glb2rf */
    v0220 = Lflag(nil, v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    v0221 = stack[0];
    v0220 = qvalue(elt(env, 5)); /* globs!* */
    v0220 = cons(v0221, v0220);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-1];
    qvalue(elt(env, 5)) = v0220; /* globs!* */
    goto v0140;

v0140:
    v0220 = nil;
    { popv(2); return onevalue(v0220); }

v0112:
    v0221 = stack[0];
    v0220 = qvalue(elt(env, 3)); /* locls!* */
    v0220 = Lassoc(nil, v0221, v0220);
    v0220 = (v0220 == nil ? lisp_true : nil);
    goto v0148;

v0176:
    v0220 = qvalue(elt(env, 1)); /* nil */
    goto v0148;
/* error exit handlers */
v0218:
    popv(2);
    return nil;
}



/* Code for cl_cflip */

static Lisp_Object CC_cl_cflip(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0057 = v0001;
    v0068 = v0000;
/* end of prologue */
    if (!(v0057 == nil)) return onevalue(v0068);
    v0057 = v0068;
    {
        fn = elt(env, 1); /* cl_flip */
        return (*qfn1(fn))(qenv(fn), v0057);
    }
}



/* Code for get!+col!+nr */

static Lisp_Object CC_getLcolLnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+col+nr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */
    v0035 = qcar(v0035);
        return Llength(nil, v0035);
}



/* Code for mri_0mk2 */

static Lisp_Object MS_CDECL CC_mri_0mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0140, v0045, v0044;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mri_0mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0045 = v0002;
    v0161 = v0001;
    v0140 = v0000;
/* end of prologue */
    v0044 = qvalue(elt(env, 1)); /* nil */
    return list4(v0140, v0161, v0044, v0045);
}



/* Code for qqe_mk2 */

static Lisp_Object MS_CDECL CC_qqe_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0117, v0118;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "qqe_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0002;
    v0117 = v0001;
    v0118 = v0000;
/* end of prologue */
    return list3(v0118, v0117, v0071);
}



/* Code for lto_insertq */

static Lisp_Object CC_lto_insertq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0069, v0070;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insertq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0116 = v0001;
    v0069 = v0000;
/* end of prologue */
    v0070 = v0069;
    v0115 = v0116;
    v0115 = Lmemq(nil, v0070, v0115);
    if (!(v0115 == nil)) return onevalue(v0116);
    v0115 = v0069;
    return cons(v0115, v0116);
}



/* Code for aex_mk */

static Lisp_Object MS_CDECL CC_aex_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0002, Lisp_Object v0003, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116, v0069, v0070;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "aex_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mk");
#endif
    if (stack >= stacklimit)
    {
        push4(v0003,v0002,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0002,v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0115 = v0003;
    v0116 = v0002;
    v0069 = v0001;
    v0070 = v0000;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v0070;
    stack[0] = v0069;
    v0115 = list2(v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    {
        Lisp_Object v0148 = stack[-2];
        Lisp_Object v0058 = stack[-1];
        Lisp_Object v0172 = stack[0];
        popv(3);
        return list3star(v0148, v0058, v0172, v0115);
    }
/* error exit handlers */
v0122:
    popv(3);
    return nil;
}



/* Code for list2string */

static Lisp_Object CC_list2string(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2string");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0071 = stack[0];
    if (v0071 == nil) goto v0025;
    v0071 = stack[0];
    v0071 = qcar(v0071);
    v0071 = Lprinc(nil, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    v0071 = stack[0];
    v0071 = qcdr(v0071);
    v0071 = CC_list2string(env, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    goto v0025;

v0025:
    v0071 = nil;
    { popv(2); return onevalue(v0071); }
/* error exit handlers */
v0118:
    popv(2);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0043, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_int");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0043 = v0000;
/* end of prologue */
    v0070 = v0043;
    v0070 = Lconsp(nil, v0070);
    env = stack[0];
    if (v0070 == nil) goto v0025;
    v0070 = v0043;
    v0042 = qcar(v0070);
    v0070 = elt(env, 1); /* arbint */
    if (v0042 == v0070) goto v0163;
    v0070 = v0043;
    v0070 = qcdr(v0070);
    fn = elt(env, 4); /* multi_isarb_int */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    goto v0025;

v0025:
    v0070 = nil;
    { popv(1); return onevalue(v0070); }

v0163:
    v0070 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v0070; /* found_int */
    goto v0025;
/* error exit handlers */
v0123:
    popv(1);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0209;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:minus");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    if (!consp(v0172)) goto v0121;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    v0209 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    {
        Lisp_Object v0041 = stack[-1];
        popv(2);
        return list2star(v0041, v0209, v0172);
    }

v0121:
    stack[-1] = elt(env, 1); /* !:rd!: */
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    v0172 = negate(v0172);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    {
        Lisp_Object v0141 = stack[-1];
        popv(2);
        return cons(v0141, v0172);
    }
/* error exit handlers */
v0040:
    popv(2);
    return nil;
}



/* Code for depends */

static Lisp_Object CC_depends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0052, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depends");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0051 = stack[-1];
    if (v0051 == nil) goto v0121;
    v0051 = stack[-1];
    v0051 = (is_number(v0051) ? lisp_true : nil);
    if (!(v0051 == nil)) goto v0017;
    v0051 = stack[0];
    v0051 = (is_number(v0051) ? lisp_true : nil);
    goto v0017;

v0017:
    if (v0051 == nil) goto v0160;
    v0051 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0051); }

v0160:
    v0052 = stack[-1];
    v0051 = stack[0];
    if (equal(v0052, v0051)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0051 = stack[-1];
    if (!consp(v0051)) goto v0040;
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0172;

v0172:
    if (v0051 == nil) goto v0124;
    v0051 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0051); }

v0124:
    v0052 = stack[-1];
    v0051 = qvalue(elt(env, 4)); /* depl!* */
    v0051 = Lassoc(nil, v0052, v0051);
    v0052 = v0051;
    v0051 = v0052;
    if (v0051 == nil) goto v0036;
    v0051 = v0052;
    v0052 = qcdr(v0051);
    v0051 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v0051 = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0039;

v0039:
    if (v0051 == nil) goto v0125;
    v0051 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0051); }

v0125:
    v0051 = stack[-1];
    if (!consp(v0051)) goto v0212;
    v0051 = stack[-1];
    v0051 = qcar(v0051);
    if (symbolp(v0051)) goto v0029;
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0087;

v0087:
    if (v0051 == nil) goto v0032;
    v0051 = stack[-1];
    v0052 = qcar(v0051);
    v0051 = elt(env, 6); /* domain!-depends!-fn */
    v0051 = get(v0052, v0051);
    env = stack[-2];
    v0052 = v0051;
    v0051 = v0052;
    if (v0051 == nil) goto v0024;
    v0053 = v0052;
    v0052 = stack[-1];
    v0051 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0053, v0052, v0051);

v0024:
    v0051 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0051); }

v0032:
    v0051 = stack[-1];
    if (!consp(v0051)) goto v0065;
    v0051 = stack[-1];
    v0052 = qcdr(v0051);
    v0051 = stack[0];
    fn = elt(env, 7); /* ldepends */
    v0051 = (*qfn2(fn))(qenv(fn), v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (!(v0051 == nil)) goto v0194;
    v0051 = stack[-1];
    v0052 = qcar(v0051);
    v0051 = stack[0];
    v0051 = CC_depends(env, v0052, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    goto v0194;

v0194:
    if (v0051 == nil) goto v0170;
    v0051 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0051); }

v0170:
    v0051 = stack[0];
    if (!consp(v0051)) goto v0008;
    v0051 = stack[0];
    v0051 = qcar(v0051);
    if (symbolp(v0051)) goto v0229;
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0230;

v0230:
    if (v0051 == nil) goto v0048;
    v0051 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0051); }

v0048:
    v0051 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0051); }

v0229:
    v0051 = stack[0];
    v0052 = qcar(v0051);
    v0051 = elt(env, 5); /* dname */
    v0051 = get(v0052, v0051);
    env = stack[-2];
    goto v0230;

v0008:
    v0051 = qvalue(elt(env, 1)); /* t */
    goto v0230;

v0065:
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0194;

v0029:
    v0051 = stack[-1];
    v0052 = qcar(v0051);
    v0051 = elt(env, 5); /* dname */
    v0051 = get(v0052, v0051);
    env = stack[-2];
    goto v0087;

v0212:
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0087;

v0036:
    v0051 = qvalue(elt(env, 2)); /* nil */
    goto v0039;

v0040:
    v0052 = stack[-1];
    v0051 = qvalue(elt(env, 3)); /* frlis!* */
    v0051 = Lmemq(nil, v0052, v0051);
    goto v0172;

v0121:
    v0051 = qvalue(elt(env, 1)); /* t */
    goto v0017;
/* error exit handlers */
v0056:
    popv(3);
    return nil;
}



/* Code for subscriptedvarp */

static Lisp_Object CC_subscriptedvarp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subscriptedvarp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0043 = qvalue(elt(env, 1)); /* nil */
    v0070 = stack[0];
    fn = elt(env, 3); /* symtabget */
    v0070 = (*qfn2(fn))(qenv(fn), v0043, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-1];
    v0043 = Llength(nil, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-1];
    v0070 = (Lisp_Object)33; /* 2 */
    v0070 = (Lisp_Object)greaterp2(v0043, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    v0070 = v0070 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0070 == nil)) { popv(2); return onevalue(v0070); }
    v0070 = stack[0];
    v0043 = elt(env, 2); /* subscripted */
        popv(2);
        return Lflagp(nil, v0070, v0043);
/* error exit handlers */
v0123:
    popv(2);
    return nil;
}



/* Code for bound */

static Lisp_Object CC_bound(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bound");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* binding */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[0];
    v0067 = v0044;
    v0044 = v0067;
    if (v0044 == nil) goto v0035;
    v0044 = v0067;
    v0067 = elt(env, 2); /* unbound */
        popv(1);
        return Lneq(nil, v0044, v0067);

v0035:
    v0044 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0044); }
/* error exit handlers */
v0066:
    popv(1);
    return nil;
}



/* Code for vevcompless!? */

static Lisp_Object CC_vevcomplessW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevcompless?");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0140 = v0001;
    v0161 = v0000;
/* end of prologue */
    stack[0] = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* evcomp */
    v0161 = (*qfn2(fn))(qenv(fn), v0140, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    v0161 = (stack[0] == v0161 ? lisp_true : nil);
    { popv(1); return onevalue(v0161); }
/* error exit handlers */
v0044:
    popv(1);
    return nil;
}



/* Code for fast_unchecked_getmatelem */

static Lisp_Object CC_fast_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_unchecked_getmatelem");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0115 = stack[0];
    v0115 = qcar(v0115);
    v0116 = qcdr(v0115);
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    fn = elt(env, 1); /* pnth */
    v0115 = (*qfn2(fn))(qenv(fn), v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0116 = qcar(v0115);
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0115 = qcdr(v0115);
    v0115 = qcar(v0115);
    fn = elt(env, 1); /* pnth */
    v0115 = (*qfn2(fn))(qenv(fn), v0116, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    v0115 = qcar(v0115);
    { popv(2); return onevalue(v0115); }
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0071, v0117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkwedge");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0068 = v0000;
/* end of prologue */
    v0117 = v0068;
    v0071 = (Lisp_Object)17; /* 1 */
    v0068 = (Lisp_Object)17; /* 1 */
    v0068 = list2star(v0117, v0071, v0068);
    errexit();
    return ncons(v0068);
}



/* Code for tensopp */

static Lisp_Object CC_tensopp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0039, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensopp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    v0038 = v0039;
    if (symbolp(v0038)) goto v0140;
    v0038 = qvalue(elt(env, 1)); /* nil */
    goto v0030;

v0030:
    if (!(v0038 == nil)) { popv(1); return onevalue(v0038); }
    v0038 = v0039;
    if (!consp(v0038)) goto v0147;
    v0038 = v0039;
    v0036 = qcar(v0038);
    v0038 = elt(env, 2); /* phystype */
    v0036 = get(v0036, v0038);
    env = stack[0];
    v0038 = elt(env, 3); /* tensor */
    if (v0036 == v0038) goto v0058;
    v0038 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0038); }

v0058:
    v0038 = v0039;
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    fn = elt(env, 4); /* isanindex */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    v0038 = (v0038 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v0038); }

v0147:
    v0038 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0038); }

v0140:
    v0036 = v0039;
    v0038 = elt(env, 2); /* phystype */
    v0036 = get(v0036, v0038);
    env = stack[0];
    v0038 = elt(env, 3); /* tensor */
    v0038 = (v0036 == v0038 ? lisp_true : nil);
    goto v0030;
/* error exit handlers */
v0037:
    popv(1);
    return nil;
}



/* Code for getroad */

static Lisp_Object CC_getroad(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0041, v0141, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getroad");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0141 = v0001;
    v0169 = v0000;
/* end of prologue */

v0025:
    v0040 = v0141;
    if (v0040 == nil) goto v0017;
    v0040 = v0169;
    v0041 = qcdr(v0040);
    v0040 = v0141;
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    if (equal(v0041, v0040)) goto v0160;
    v0040 = v0141;
    v0040 = qcdr(v0040);
    v0141 = v0040;
    goto v0025;

v0160:
    v0040 = v0169;
    v0040 = qcar(v0040);
    v0041 = v0141;
    v0041 = qcar(v0041);
    v0041 = qcar(v0041);
    fn = elt(env, 1); /* qassoc */
    v0040 = (*qfn2(fn))(qenv(fn), v0040, v0041);
    errexit();
    v0040 = qcdr(v0040);
    return onevalue(v0040);

v0017:
    v0040 = (Lisp_Object)17; /* 1 */
    return onevalue(v0040);
}



/* Code for negf */

static Lisp_Object CC_negf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0061, v0220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negf");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0025;

v0025:
    v0061 = stack[-1];
    if (v0061 == nil) goto v0017;
    v0061 = stack[-1];
    if (!consp(v0061)) goto v0118;
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = (consp(v0061) ? nil : lisp_true);
    goto v0117;

v0117:
    if (v0061 == nil) goto v0155;
    stack[0] = stack[-2];
    v0061 = stack[-1];
    if (!consp(v0061)) goto v0143;
    v0061 = qvalue(elt(env, 4)); /* nil */
    goto v0150;

v0150:
    if (v0061 == nil) goto v0208;
    v0220 = qvalue(elt(env, 2)); /* dmode!* */
    v0061 = elt(env, 5); /* i2d */
    v0220 = get(v0220, v0061);
    env = stack[-3];
    v0061 = stack[-1];
    v0061 = Lapply1(nil, v0220, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    goto v0058;

v0058:
    fn = elt(env, 6); /* !:minus */
    v0061 = (*qfn1(fn))(qenv(fn), v0061);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    {
        Lisp_Object v0029 = stack[0];
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0029, v0061);
    }

v0208:
    v0061 = stack[-1];
    goto v0058;

v0143:
    v0220 = qvalue(elt(env, 2)); /* dmode!* */
    v0061 = elt(env, 3); /* convert */
    v0061 = Lflagp(nil, v0220, v0061);
    env = stack[-3];
    goto v0150;

v0155:
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    stack[0] = qcar(v0061);
    v0061 = stack[-1];
    v0061 = qcar(v0061);
    v0061 = qcdr(v0061);
    v0220 = CC_negf(env, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0061 = stack[-2];
    v0061 = acons(stack[0], v0220, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    stack[-2] = v0061;
    v0061 = stack[-1];
    v0061 = qcdr(v0061);
    stack[-1] = v0061;
    goto v0025;

v0118:
    v0061 = qvalue(elt(env, 1)); /* t */
    goto v0117;

v0017:
    v0061 = stack[-2];
    {
        popv(4);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0061);
    }
/* error exit handlers */
v0028:
    popv(4);
    return nil;
}



/* Code for command1 */

static Lisp_Object MS_CDECL CC_command1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0116, v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "command1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for command1");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 7); /* scan */
    v0116 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    v0116 = qvalue(elt(env, 1)); /* ifl!* */
    if (v0116 == nil) goto v0030;
    v0116 = qvalue(elt(env, 1)); /* ifl!* */
    v0070 = qcar(v0116);
    v0069 = (Lisp_Object)17; /* 1 */
    v0116 = qvalue(elt(env, 3)); /* curline!* */
    v0116 = list2star(v0070, v0069, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[0];
    goto v0025;

v0025:
    qvalue(elt(env, 4)) = v0116; /* cloc!* */
    v0116 = qvalue(elt(env, 5)); /* cursym!* */
    qvalue(elt(env, 6)) = v0116; /* key!* */
    v0116 = qvalue(elt(env, 2)); /* nil */
    {
        popv(1);
        fn = elt(env, 8); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0116);
    }

v0030:
    v0116 = qvalue(elt(env, 2)); /* nil */
    goto v0025;
/* error exit handlers */
v0043:
    popv(1);
    return nil;
}



/* Code for mo!=degcomp */

static Lisp_Object CC_moMdegcomp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0169, v0143, v0144;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=degcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0169 = v0001;
    v0143 = v0000;
/* end of prologue */

v0025:
    v0141 = v0143;
    if (v0141 == nil) goto v0017;
    v0141 = v0143;
    v0144 = qcar(v0141);
    v0141 = v0169;
    v0141 = qcar(v0141);
    if (equal(v0144, v0141)) goto v0163;
    v0141 = v0143;
    v0141 = qcar(v0141);
    v0169 = qcar(v0169);
    if (((int32_t)(v0141)) < ((int32_t)(v0169))) goto v0116;
    v0141 = (Lisp_Object)17; /* 1 */
    return onevalue(v0141);

v0116:
    v0141 = (Lisp_Object)-15; /* -1 */
    return onevalue(v0141);

v0163:
    v0141 = v0143;
    v0141 = qcdr(v0141);
    v0143 = v0141;
    v0141 = v0169;
    v0141 = qcdr(v0141);
    v0169 = v0141;
    goto v0025;

v0017:
    v0141 = (Lisp_Object)1; /* 0 */
    return onevalue(v0141);
}



/* Code for pv_sort */

static Lisp_Object CC_pv_sort(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0067 = v0000;
/* end of prologue */
    v0044 = v0067;
    if (v0044 == nil) goto v0072;
    v0044 = v0067;
    stack[0] = qcdr(v0044);
    v0044 = v0067;
    v0044 = qcar(v0044);
    v0044 = ncons(v0044);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-1];
    {
        Lisp_Object v0160 = stack[0];
        popv(2);
        fn = elt(env, 2); /* pv_sort1 */
        return (*qfn2(fn))(qenv(fn), v0160, v0044);
    }

v0072:
    v0044 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0044); }
/* error exit handlers */
v0142:
    popv(2);
    return nil;
}



/* Code for !*modular2f */

static Lisp_Object CC_Hmodular2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0233, v0152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *modular2f");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0121:
    v0152 = stack[0];
    v0233 = (Lisp_Object)1; /* 0 */
    if (v0152 == v0233) goto v0035;
    v0233 = qvalue(elt(env, 2)); /* !*balanced_mod */
    if (v0233 == nil) goto v0220;
    v0152 = stack[0];
    v0233 = stack[0];
    v0152 = plus2(v0152, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0233 = qvalue(elt(env, 3)); /* current!-modulus */
    v0233 = (Lisp_Object)greaterp2(v0152, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0233 = v0233 ? lisp_true : nil;
    env = stack[-2];
    if (v0233 == nil) goto v0038;
    stack[-1] = elt(env, 4); /* !:mod!: */
    v0152 = stack[0];
    v0233 = qvalue(elt(env, 3)); /* current!-modulus */
    v0233 = difference2(v0152, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    {
        Lisp_Object v0203 = stack[-1];
        popv(3);
        return cons(v0203, v0233);
    }

v0038:
    v0152 = stack[0];
    v0233 = stack[0];
    stack[-1] = plus2(v0152, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0233 = qvalue(elt(env, 3)); /* current!-modulus */
    v0233 = negate(v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0233 = (Lisp_Object)lesseq2(stack[-1], v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0233 = v0233 ? lisp_true : nil;
    env = stack[-2];
    if (v0233 == nil) goto v0020;
    v0152 = stack[0];
    v0233 = qvalue(elt(env, 3)); /* current!-modulus */
    v0233 = plus2(v0152, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    stack[0] = v0233;
    goto v0121;

v0020:
    v0152 = elt(env, 4); /* !:mod!: */
    v0233 = stack[0];
    popv(3);
    return cons(v0152, v0233);

v0220:
    v0152 = elt(env, 4); /* !:mod!: */
    v0233 = stack[0];
    popv(3);
    return cons(v0152, v0233);

v0035:
    v0233 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0233); }
/* error exit handlers */
v0198:
    popv(3);
    return nil;
}



/* Code for outdefr */

static Lisp_Object CC_outdefr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0142, v0160, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for outdefr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0066 = v0001;
    v0142 = v0000;
/* end of prologue */
    v0160 = v0142;
    v0115 = qcar(v0160);
    v0160 = v0142;
    v0160 = qcdr(v0160);
    v0160 = qcar(v0160);
    v0142 = qcdr(v0142);
    v0142 = qcdr(v0142);
    v0142 = qcar(v0142);
    {
        fn = elt(env, 1); /* outref */
        return (*qfnn(fn))(qenv(fn), 4, v0115, v0160, v0142, v0066);
    }
}



/* Code for rl_ordatp */

static Lisp_Object CC_rl_ordatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161, v0140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ordatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0161 = v0001;
    v0140 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ordatp!* */
    v0161 = list2(v0140, v0161);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    {
        Lisp_Object v0067 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0067, v0161);
    }
/* error exit handlers */
v0044:
    popv(2);
    return nil;
}



/* Code for qqe_id!-nyt!-branchb */

static Lisp_Object CC_qqe_idKnytKbranchb(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_id-nyt-branchb");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0115 = stack[0];
    if (!consp(v0115)) goto v0072;
    v0115 = stack[0];
    v0115 = qcar(v0115);
    fn = elt(env, 1); /* qqe_qopaddp */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    if (!(v0115 == nil)) goto v0118;
    v0115 = stack[0];
    v0115 = qcar(v0115);
    fn = elt(env, 2); /* qqe_qoptailp */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    goto v0118;

v0118:
    v0115 = (v0115 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0115); }

v0072:
    v0115 = stack[0];
    fn = elt(env, 3); /* qqe_btidp */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-1];
    if (!(v0115 == nil)) { popv(2); return onevalue(v0115); }
    v0115 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* qqe_nytidp */
        return (*qfn1(fn))(qenv(fn), v0115);
    }
/* error exit handlers */
v0069:
    popv(2);
    return nil;
}



/* Code for pasf_dec */

static Lisp_Object CC_pasf_dec(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_dec");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0143 = v0000;
/* end of prologue */
    v0169 = v0143;
    stack[-1] = v0169;
    goto v0017;

v0017:
    v0169 = stack[-1];
    if (!consp(v0169)) goto v0071;
    v0169 = stack[-1];
    v0169 = qcar(v0169);
    v0169 = (consp(v0169) ? nil : lisp_true);
    goto v0068;

v0068:
    if (v0169 == nil) goto v0179;
    stack[0] = v0143;
    v0169 = stack[-1];
    fn = elt(env, 3); /* negf */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    fn = elt(env, 4); /* addf */
    v0143 = (*qfn2(fn))(qenv(fn), stack[0], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0169 = stack[-1];
    popv(3);
    return cons(v0143, v0169);

v0179:
    v0169 = stack[-1];
    v0169 = qcdr(v0169);
    stack[-1] = v0169;
    goto v0017;

v0071:
    v0169 = qvalue(elt(env, 1)); /* t */
    goto v0068;
/* error exit handlers */
v0159:
    popv(3);
    return nil;
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_varlat");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0180 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v0180 = ncons(v0180);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    {
        Lisp_Object v0068 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0068, v0180);
    }
/* error exit handlers */
v0057:
    popv(2);
    return nil;
}



/* Code for lex */

static Lisp_Object MS_CDECL CC_lex(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lex");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v0082 = qvalue(elt(env, 2)); /* atts */
    if (v0082 == nil) goto v0030;
    v0082 = qvalue(elt(env, 2)); /* atts */
    qvalue(elt(env, 3)) = v0082; /* safe_atts */
    goto v0030;

v0030:
    v0082 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0082; /* atts */
    v0090 = qvalue(elt(env, 4)); /* ch */
    v0082 = qvalue(elt(env, 5)); /* !$eof!$ */
    if (equal(v0090, v0082)) goto v0057;
    v0090 = qvalue(elt(env, 4)); /* ch */
    v0082 = qvalue(elt(env, 6)); /* space */
    if (equal(v0090, v0082)) goto v0141;
    v0090 = qvalue(elt(env, 4)); /* ch */
    v0082 = elt(env, 7); /* !< */
    if (v0090 == v0082) goto v0178;
    fn = elt(env, 10); /* get_content */
    v0082 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0082; /* char */
    goto v0142;

v0142:
    v0082 = qvalue(elt(env, 8)); /* char */
    if (v0082 == nil) goto v0032;
    v0082 = qvalue(elt(env, 9)); /* count */
    v0082 = add1(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    qvalue(elt(env, 9)) = v0082; /* count */
    v0082 = qvalue(elt(env, 8)); /* char */
    v0082 = Lreverse(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    stack[0] = v0082;
    v0082 = stack[0];
    fn = elt(env, 11); /* butes */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0082; /* char */
    v0090 = qvalue(elt(env, 8)); /* char */
    v0082 = stack[0];
    fn = elt(env, 12); /* attributes */
    v0082 = (*qfn2(fn))(qenv(fn), v0090, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    goto v0057;

v0057:
    v0082 = nil;
    { popv(2); return onevalue(v0082); }

v0032:
    v0082 = CC_lex(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    goto v0057;

v0178:
    fn = elt(env, 13); /* get_token */
    v0082 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0082; /* char */
    goto v0142;

v0141:
    v0090 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-1];
    qvalue(elt(env, 4)) = v0090; /* ch */
    v0082 = qvalue(elt(env, 6)); /* space */
    if (equal(v0090, v0082)) goto v0141;
    else goto v0142;
/* error exit handlers */
v0167:
    popv(2);
    return nil;
}



/* Code for mk!*sq */

static Lisp_Object CC_mkHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk*sq");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0228 = v0000;
/* end of prologue */
    v0090 = qvalue(elt(env, 1)); /* !*exp */
    if (v0090 == nil) goto v0017;
    v0090 = v0228;
    goto v0003;

v0003:
    stack[0] = v0090;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    if (v0090 == nil) goto v0071;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    if (!consp(v0090)) goto v0069;
    v0090 = qvalue(elt(env, 2)); /* nil */
    goto v0066;

v0066:
    if (v0090 == nil) goto v0044;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    { popv(3); return onevalue(v0090); }

v0044:
    v0090 = stack[0];
    fn = elt(env, 7); /* kernp */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    if (v0090 == nil) goto v0207;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0228 = qcar(v0090);
    v0090 = elt(env, 3); /* list */
    if (!consp(v0228)) goto v0207;
    v0228 = qcar(v0228);
    if (!(v0228 == v0090)) goto v0207;
    v0090 = stack[0];
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    v0090 = qcar(v0090);
    { popv(3); return onevalue(v0090); }

v0207:
    stack[-1] = elt(env, 4); /* !*sq */
    v0090 = qvalue(elt(env, 5)); /* !*resubs */
    if (v0090 == nil) goto v0020;
    v0090 = qvalue(elt(env, 6)); /* !*sqvar!* */
    goto v0157;

v0157:
    {
        Lisp_Object v0061 = stack[-1];
        Lisp_Object v0220 = stack[0];
        popv(3);
        return list2star(v0061, v0220, v0090);
    }

v0020:
    v0090 = qvalue(elt(env, 2)); /* nil */
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    goto v0157;

v0069:
    v0090 = stack[0];
    v0228 = qcdr(v0090);
    v0090 = (Lisp_Object)17; /* 1 */
    v0090 = (v0228 == v0090 ? lisp_true : nil);
    goto v0066;

v0071:
    v0090 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0090); }

v0017:
    v0090 = v0228;
    fn = elt(env, 8); /* offexpchk */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-2];
    goto v0003;
/* error exit handlers */
v0137:
    popv(3);
    return nil;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0142, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0142 = v0000;
/* end of prologue */
    v0066 = v0142;
    if (!consp(v0066)) goto v0180;
    v0066 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0066); }

v0180:
    v0160 = v0142;
    v0066 = elt(env, 1); /* gen */
    v0066 = get(v0160, v0066);
    env = stack[0];
    if (!(v0066 == nil)) { popv(1); return onevalue(v0066); }
    v0066 = v0142;
    {
        popv(1);
        fn = elt(env, 3); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v0066);
    }
}



/* Code for evsum */

static Lisp_Object CC_evsum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0208, v0232;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evsum");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0232 = nil;
    goto v0017;

v0017:
    v0207 = stack[-1];
    if (v0207 == nil) goto v0035;
    v0207 = stack[0];
    if (v0207 == nil) goto v0035;
    v0207 = stack[-1];
    v0208 = qcar(v0207);
    v0207 = stack[0];
    v0207 = qcar(v0207);
    v0207 = (Lisp_Object)(int32_t)((int32_t)v0208 + (int32_t)v0207 - TAG_FIXNUM);
    v0208 = v0232;
    v0207 = cons(v0207, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-2];
    v0232 = v0207;
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    stack[-1] = v0207;
    v0207 = stack[0];
    v0207 = qcdr(v0207);
    stack[0] = v0207;
    goto v0017;

v0035:
    v0207 = v0232;
    v0207 = Lnreverse(nil, v0207);
    v0232 = v0207;
    v0207 = stack[-1];
    if (v0207 == nil) goto v0143;
    v0208 = v0232;
    v0207 = stack[-1];
        popv(3);
        return Lnconc(nil, v0208, v0207);

v0143:
    v0207 = stack[0];
    if (v0207 == nil) { popv(3); return onevalue(v0232); }
    v0208 = v0232;
    v0207 = stack[0];
        popv(3);
        return Lnconc(nil, v0208, v0207);
/* error exit handlers */
v0157:
    popv(3);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_item");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0145:
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    if (v0156 == nil) goto v0025;
    v0112 = stack[-1];
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    v0156 = CC_find_item(env, v0112, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-2];
    if (!(v0156 == nil)) { popv(3); return onevalue(v0156); }
    v0156 = stack[0];
    v0112 = qcar(v0156);
    v0156 = stack[-1];
    if (equal(v0112, v0156)) goto v0043;
    v0156 = nil;
    goto v0070;

v0070:
    if (!(v0156 == nil)) { popv(3); return onevalue(v0156); }
    v0112 = stack[-1];
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    v0156 = qcdr(v0156);
    stack[-1] = v0112;
    stack[0] = v0156;
    goto v0145;

v0043:
    v0156 = stack[0];
    goto v0070;

v0025:
    v0156 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0156); }
/* error exit handlers */
v0165:
    popv(3);
    return nil;
}



/* Code for physopp!* */

static Lisp_Object CC_physoppH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopp*");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0168 = stack[0];
    fn = elt(env, 6); /* physopp */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-1];
    if (!(v0168 == nil)) { popv(2); return onevalue(v0168); }
    v0168 = stack[0];
    if (!consp(v0168)) goto v0208;
    v0168 = stack[0];
    v0157 = qcar(v0168);
    v0168 = elt(env, 1); /* physopfn */
    v0168 = Lflagp(nil, v0157, v0168);
    env = stack[-1];
    if (v0168 == nil) goto v0172;
    v0168 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0168); }

v0172:
    v0168 = stack[0];
    v0157 = qcar(v0168);
    v0168 = elt(env, 3); /* physoparith */
    v0168 = Lflagp(nil, v0157, v0168);
    env = stack[-1];
    if (v0168 == nil) goto v0159;
    v0168 = stack[0];
    v0168 = qcdr(v0168);
    fn = elt(env, 7); /* hasonephysop */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0155;
    env = stack[-1];
    goto v0123;

v0123:
    if (!(v0168 == nil)) { popv(2); return onevalue(v0168); }
    v0168 = stack[0];
    v0157 = qcar(v0168);
    v0168 = elt(env, 5); /* physopmapping */
    v0168 = Lflagp(nil, v0157, v0168);
    env = stack[-1];
    if (v0168 == nil) goto v0037;
    v0168 = stack[0];
    v0168 = qcdr(v0168);
    {
        popv(2);
        fn = elt(env, 7); /* hasonephysop */
        return (*qfn1(fn))(qenv(fn), v0168);
    }

v0037:
    v0168 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0168); }

v0159:
    v0168 = qvalue(elt(env, 4)); /* nil */
    goto v0123;

v0208:
    v0168 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v0168); }
/* error exit handlers */
v0155:
    popv(2);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0161, v0140, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0118 = v0001;
    v0161 = v0000;
/* end of prologue */
    v0045 = v0161;
    v0140 = v0118;
    v0161 = qvalue(elt(env, 1)); /* nil */
    v0118 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v0045, v0140, v0161, v0118);
    }
}



/* Code for reval2 */

static Lisp_Object CC_reval2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval2");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    v0112 = v0000;
/* end of prologue */
    v0156 = stack[0];
    if (!(v0156 == nil)) goto v0025;
    v0156 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v0156 == nil) goto v0163;
    v0156 = qvalue(elt(env, 3)); /* dmode!* */
    goto v0180;

v0180:
    if (!(v0156 == nil)) goto v0025;
    v0156 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = qvalue(elt(env, 5)); /* !*mcd */
    qvalue(elt(env, 5)) = v0156; /* !*mcd */
    v0156 = v0112;
    fn = elt(env, 6); /* simp!* */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-2];
    qvalue(elt(env, 5)) = stack[-1]; /* !*mcd */
    v0112 = v0156;
    v0156 = stack[0];
    if (v0156 == nil) goto v0141;
    v0156 = v0112;
    {
        popv(3);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0141:
    v0156 = v0112;
    {
        popv(3);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0025:
    v0156 = v0112;
    fn = elt(env, 6); /* simp!* */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-2];
    v0112 = v0156;
    v0156 = stack[0];
    if (v0156 == nil) goto v0142;
    v0156 = v0112;
    {
        popv(3);
        fn = elt(env, 7); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0142:
    v0156 = v0112;
    {
        popv(3);
        fn = elt(env, 8); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0163:
    v0156 = qvalue(elt(env, 2)); /* t */
    goto v0180;
/* error exit handlers */
v0175:
    popv(3);
    return nil;
v0165:
    env = stack[-2];
    qvalue(elt(env, 5)) = stack[-1]; /* !*mcd */
    popv(3);
    return nil;
}



/* Code for fs!:plus */

static Lisp_Object CC_fsTplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0245, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:plus");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0145:
    v0244 = stack[-1];
    if (v0244 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0244 = stack[-2];
    if (v0244 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0245 = stack[-2];
    v0244 = (Lisp_Object)17; /* 1 */
    v0091 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0245 = stack[-1];
    v0244 = (Lisp_Object)17; /* 1 */
    v0244 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    if (equal(v0091, v0244)) goto v0158;
    v0244 = qvalue(elt(env, 1)); /* nil */
    goto v0117;

v0117:
    if (v0244 == nil) goto v0191;
    v0245 = stack[-2];
    v0244 = (Lisp_Object)1; /* 0 */
    v0091 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0245 = stack[-1];
    v0244 = (Lisp_Object)1; /* 0 */
    v0244 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    fn = elt(env, 2); /* addsq */
    v0244 = (*qfn2(fn))(qenv(fn), v0091, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    v0245 = v0244;
    v0245 = qcar(v0245);
    if (v0245 == nil) goto v0062;
    v0091 = stack[-2];
    v0245 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0091 + (CELL-TAG_VECTOR) + ((int32_t)v0245/(16/CELL))) = v0244;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0245 = stack[-2];
    v0244 = (Lisp_Object)49; /* 3 */
    v0091 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0245 = stack[-1];
    v0244 = (Lisp_Object)49; /* 3 */
    v0244 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0244 = CC_fsTplus(env, v0091, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0244;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0062:
    v0245 = stack[-2];
    v0244 = (Lisp_Object)49; /* 3 */
    v0091 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0245 = stack[-1];
    v0244 = (Lisp_Object)49; /* 3 */
    v0244 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    stack[-2] = v0091;
    stack[-1] = v0244;
    goto v0145;

v0191:
    v0245 = stack[-2];
    v0244 = stack[-1];
    fn = elt(env, 3); /* fs!:angle!-order */
    v0244 = (*qfn2(fn))(qenv(fn), v0245, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    if (v0244 == nil) goto v0099;
    stack[-3] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0245 = stack[-2];
    v0244 = (Lisp_Object)49; /* 3 */
    v0245 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0244 = stack[-1];
    v0244 = CC_fsTplus(env, v0245, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0244;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v0099:
    stack[-3] = stack[-1];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0245 = stack[-1];
    v0244 = (Lisp_Object)49; /* 3 */
    v0245 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0244 = stack[-2];
    v0244 = CC_fsTplus(env, v0245, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0244;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0158:
    v0245 = stack[-2];
    v0244 = (Lisp_Object)33; /* 2 */
    v0091 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    v0245 = stack[-1];
    v0244 = (Lisp_Object)33; /* 2 */
    v0244 = *(Lisp_Object *)((char *)v0245 + (CELL-TAG_VECTOR) + ((int32_t)v0244/(16/CELL)));
    fn = elt(env, 4); /* angles!-equal */
    v0244 = (*qfn2(fn))(qenv(fn), v0091, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0134;
    env = stack[-4];
    goto v0117;
/* error exit handlers */
v0134:
    popv(5);
    return nil;
}



/* Code for mo!=shorten */

static Lisp_Object CC_moMshorten(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=shorten");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0042 = v0000;
/* end of prologue */
    v0042 = Lreverse(nil, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-1];
    stack[0] = v0042;
    goto v0121;

v0121:
    v0042 = stack[0];
    if (v0042 == nil) goto v0017;
    v0042 = stack[0];
    v0123 = qcar(v0042);
    v0042 = (Lisp_Object)1; /* 0 */
    v0042 = Leqn(nil, v0123, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0148;
    env = stack[-1];
    if (v0042 == nil) goto v0017;
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    stack[0] = v0042;
    goto v0121;

v0017:
    v0042 = stack[0];
        popv(2);
        return Lnreverse(nil, v0042);
/* error exit handlers */
v0148:
    popv(2);
    return nil;
}



/* Code for unpkp */

static Lisp_Object CC_unpkp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0247, v0242, v0243;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unpkp");
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    v0247 = stack[-1];
    if (!(!consp(v0247))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0247 = stack[-1];
    v0247 = Lexplode(nil, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-1] = v0247;
    v0247 = stack[-1];
    v0242 = Llength(nil, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0247 = (Lisp_Object)161; /* 10 */
    v0247 = (Lisp_Object)geq2(v0242, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    v0247 = v0247 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v0247;
    v0247 = stack[0];
    if (v0247 == nil) goto v0143;
    v0247 = stack[-1];
    v0247 = Llength(nil, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0247 = Levenp(nil, v0247);
    env = stack[-3];
    if (!(v0247 == nil)) goto v0143;
    v0242 = elt(env, 1); /* !0 */
    v0247 = stack[-1];
    v0247 = cons(v0242, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-1] = v0247;
    goto v0143;

v0143:
    v0247 = stack[-1];
    if (v0247 == nil) goto v0169;
    v0247 = stack[0];
    if (v0247 == nil) goto v0153;
    v0247 = stack[-1];
    v0242 = qcar(v0247);
    v0247 = qvalue(elt(env, 3)); /* diglist!* */
    v0247 = Lassoc(nil, v0242, v0247);
    v0247 = qcdr(v0247);
    v0242 = v0247;
    v0247 = stack[-1];
    v0247 = qcdr(v0247);
    stack[-1] = v0247;
    v0247 = (Lisp_Object)161; /* 10 */
    v0243 = times2(v0242, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0247 = stack[-1];
    v0242 = qcar(v0247);
    v0247 = qvalue(elt(env, 3)); /* diglist!* */
    v0247 = Lassoc(nil, v0242, v0247);
    v0247 = qcdr(v0247);
    v0242 = plus2(v0243, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    v0247 = stack[-2];
    v0247 = cons(v0242, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-2] = v0247;
    goto v0112;

v0112:
    v0247 = stack[-1];
    v0247 = qcdr(v0247);
    stack[-1] = v0247;
    goto v0143;

v0153:
    v0247 = stack[-1];
    v0242 = qcar(v0247);
    v0247 = qvalue(elt(env, 3)); /* diglist!* */
    v0247 = Lassoc(nil, v0242, v0247);
    v0242 = qcdr(v0247);
    v0247 = stack[-2];
    v0247 = cons(v0242, v0247);
    nil = C_nil;
    if (exception_pending()) goto v0219;
    env = stack[-3];
    stack[-2] = v0247;
    goto v0112;

v0169:
    v0247 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0247);
/* error exit handlers */
v0219:
    popv(4);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rntimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0148 = qcar(v0122);
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    v0122 = qcar(v0122);
    stack[-2] = times2(v0148, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    v0122 = stack[-1];
    v0122 = qcdr(v0122);
    v0148 = qcdr(v0122);
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    v0122 = qcdr(v0122);
    v0122 = times2(v0148, v0122);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-3];
    {
        Lisp_Object v0150 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v0150, v0122);
    }
/* error exit handlers */
v0149:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0068 = v0001;
    v0071 = v0000;
/* end of prologue */
    v0071 = qcdr(v0071);
    v0068 = qcdr(v0068);
    fn = elt(env, 1); /* general!-modular!-plus */
    v0068 = (*qfn2(fn))(qenv(fn), v0071, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0117;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v0068);
    }
/* error exit handlers */
v0117:
    popv(1);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0020 = stack[-2];
    if (v0020 == nil) goto v0025;
    v0087 = stack[-1];
    v0020 = (Lisp_Object)17; /* 1 */
    if (v0087 == v0020) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0020 = stack[-2];
    if (!consp(v0020)) goto v0066;
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    v0020 = (consp(v0020) ? nil : lisp_true);
    goto v0067;

v0067:
    if (v0020 == nil) goto v0124;
    v0087 = stack[-2];
    v0020 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v0020 = (*qfn2(fn))(qenv(fn), v0087, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0087 = v0020;
    v0020 = v0087;
    v0020 = (Lisp_Object)zerop(v0020);
    v0020 = v0020 ? lisp_true : nil;
    env = stack[-4];
    if (v0020 == nil) { popv(5); return onevalue(v0087); }
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0020); }

v0124:
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    stack[-3] = qcar(v0020);
    v0020 = stack[-2];
    v0020 = qcar(v0020);
    v0087 = qcdr(v0020);
    v0020 = stack[-1];
    stack[0] = CC_genKmultKbyKconstKmodKp(env, v0087, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0020 = stack[-2];
    v0087 = qcdr(v0020);
    v0020 = stack[-1];
    v0020 = CC_genKmultKbyKconstKmodKp(env, v0087, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    {
        Lisp_Object v0128 = stack[-3];
        Lisp_Object v0137 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0128, v0137, v0020);
    }

v0066:
    v0020 = qvalue(elt(env, 2)); /* t */
    goto v0067;

v0025:
    v0020 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0020); }
/* error exit handlers */
v0167:
    popv(5);
    return nil;
}



setup_type const u04_setup[] =
{
    {"remainder-in-vector",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_remainderKinKvector},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"**s2a",                   too_few_2,      CC_HHs2a,      wrong_no_2},
    {"quotf1",                  too_few_2,      CC_quotf1,     wrong_no_2},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"kernord-sort",            CC_kernordKsort,too_many_1,    wrong_no_1},
    {"free-powerp",             CC_freeKpowerp, too_many_1,    wrong_no_1},
    {"isvalid",                 CC_isvalid,     too_many_1,    wrong_no_1},
    {"multi_elem",              CC_multi_elem,  too_many_1,    wrong_no_1},
    {"findrow",                 too_few_2,      CC_findrow,    wrong_no_2},
    {"prepd",                   CC_prepd,       too_many_1,    wrong_no_1},
    {"bcint2op",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_bcint2op},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"prin2-downcase",          CC_prin2Kdowncase,too_many_1,  wrong_no_1},
    {"opmtch*",                 CC_opmtchH,     too_many_1,    wrong_no_1},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"nonzero-length",          CC_nonzeroKlength,too_many_1,  wrong_no_1},
    {"bas_rep",                 CC_bas_rep,     too_many_1,    wrong_no_1},
    {"prin2*",                  CC_prin2H,      too_many_1,    wrong_no_1},
    {"lcm",                     too_few_2,      CC_lcm,        wrong_no_2},
    {"lispapply",               too_few_2,      CC_lispapply,  wrong_no_2},
    {"sfto_reorder",            too_few_2,      CC_sfto_reorder,wrong_no_2},
    {"rl_smmkatl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smmkatl},
    {"resimp",                  CC_resimp,      too_many_1,    wrong_no_1},
    {"pasf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwupdknowl},
    {"ibalp_csat",              CC_ibalp_csat,  too_many_1,    wrong_no_1},
    {"cgp_evlmon",              CC_cgp_evlmon,  too_many_1,    wrong_no_1},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"indent*",                 CC_indentH,     too_many_1,    wrong_no_1},
    {"isarb_compl",             CC_isarb_compl, too_many_1,    wrong_no_1},
    {"round:mt",                too_few_2,      CC_roundTmt,   wrong_no_2},
    {"revlis",                  CC_revlis,      too_many_1,    wrong_no_1},
    {"downwght",                too_few_2,      CC_downwght,   wrong_no_2},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"xdiv",                    too_few_2,      CC_xdiv,       wrong_no_2},
    {"scprint",                 too_few_2,      CC_scprint,    wrong_no_2},
    {":difference",             too_few_2,      CC_Tdifference,wrong_no_2},
    {"add2inputbuf",            too_few_2,      CC_add2inputbuf,wrong_no_2},
    {"fs:angle-order",          too_few_2,      CC_fsTangleKorder,wrong_no_2},
    {"mo=sum",                  too_few_2,      CC_moMsum,     wrong_no_2},
    {"rev",                     too_few_2,      CC_rev,        wrong_no_2},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"anforml",                 CC_anforml,     too_many_1,    wrong_no_1},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"get+col+nr",              CC_getLcolLnr,  too_many_1,    wrong_no_1},
    {"mri_0mk2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mri_0mk2},
    {"qqe_mk2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_qqe_mk2},
    {"lto_insertq",             too_few_2,      CC_lto_insertq,wrong_no_2},
    {"aex_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_mk},
    {"list2string",             CC_list2string, too_many_1,    wrong_no_1},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"depends",                 too_few_2,      CC_depends,    wrong_no_2},
    {"subscriptedvarp",         CC_subscriptedvarp,too_many_1, wrong_no_1},
    {"bound",                   CC_bound,       too_many_1,    wrong_no_1},
    {"vevcompless?",            too_few_2,      CC_vevcomplessW,wrong_no_2},
    {"fast_unchecked_getmatelem",CC_fast_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"tensopp",                 CC_tensopp,     too_many_1,    wrong_no_1},
    {"getroad",                 too_few_2,      CC_getroad,    wrong_no_2},
    {"negf",                    CC_negf,        too_many_1,    wrong_no_1},
    {"command1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_command1},
    {"mo=degcomp",              too_few_2,      CC_moMdegcomp, wrong_no_2},
    {"pv_sort",                 CC_pv_sort,     too_many_1,    wrong_no_1},
    {"*modular2f",              CC_Hmodular2f,  too_many_1,    wrong_no_1},
    {"outdefr",                 too_few_2,      CC_outdefr,    wrong_no_2},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"qqe_id-nyt-branchb",      CC_qqe_idKnytKbranchb,too_many_1,wrong_no_1},
    {"pasf_dec",                CC_pasf_dec,    too_many_1,    wrong_no_1},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"lex",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_lex},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"evsum",                   too_few_2,      CC_evsum,      wrong_no_2},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"physopp*",                CC_physoppH,    too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"reval2",                  too_few_2,      CC_reval2,     wrong_no_2},
    {"fs:plus",                 too_few_2,      CC_fsTplus,    wrong_no_2},
    {"mo=shorten",              CC_moMshorten,  too_many_1,    wrong_no_1},
    {"unpkp",                   CC_unpkp,       too_many_1,    wrong_no_1},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {NULL, (one_args *)"u04", (two_args *)"19203 2810979 4650731", 0}
};

/* end of generated code */
