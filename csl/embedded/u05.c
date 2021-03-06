
/* $destdir\u05.c        Machine generated C code */

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


/* Code for times!-term!-mod!-p */

static Lisp_Object CC_timesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-term-mod-p");
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
    v0035 = stack[-1];
    if (v0035 == nil) goto v0038;
    v0035 = stack[-1];
    if (!consp(v0035)) goto v0039;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = (consp(v0035) ? nil : lisp_true);
    goto v0040;

v0040:
    if (v0035 == nil) goto v0041;
    v0035 = stack[-2];
    stack[0] = qcar(v0035);
    v0035 = stack[-2];
    v0036 = qcdr(v0035);
    v0035 = stack[-1];
    fn = elt(env, 3); /* multiply!-by!-constant!-mod!-p */
    v0036 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0035 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0043 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0043, v0036, v0035);
    }

v0041:
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    v0036 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    if (equal(v0036, v0035)) goto v0044;
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    v0036 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    fn = elt(env, 5); /* ordop */
    v0035 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    if (v0035 == nil) goto v0045;
    v0035 = stack[-2];
    stack[0] = qcar(v0035);
    v0035 = stack[-2];
    v0036 = qcdr(v0035);
    v0035 = stack[-1];
    fn = elt(env, 6); /* times!-mod!-p */
    v0036 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0035 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0046 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0046, v0036, v0035);
    }

v0045:
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    stack[-3] = qcar(v0035);
    v0036 = stack[-2];
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    stack[0] = CC_timesKtermKmodKp(env, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0036 = stack[-2];
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = CC_timesKtermKmodKp(env, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    {
        Lisp_Object v0047 = stack[-3];
        Lisp_Object v0048 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0047, v0048, v0035);
    }

v0044:
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    fn = elt(env, 7); /* fkern */
    v0037 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    v0036 = qcdr(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0035 = (Lisp_Object)(int32_t)((int32_t)v0036 + (int32_t)v0035 - TAG_FIXNUM);
    fn = elt(env, 8); /* getpower */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0037, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0035 = stack[-2];
    v0036 = qcdr(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    fn = elt(env, 6); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0036 = stack[-2];
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = CC_timesKtermKmodKp(env, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    {
        Lisp_Object v0049 = stack[-3];
        Lisp_Object v0050 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0049, v0050, v0035);
    }

v0039:
    v0035 = qvalue(elt(env, 2)); /* t */
    goto v0040;

v0038:
    v0035 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0035); }
/* error exit handlers */
v0042:
    popv(5);
    return nil;
}



/* Code for procstat */

static Lisp_Object MS_CDECL CC_procstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "procstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for procstat");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0051 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* procstat1 */
        return (*qfn1(fn))(qenv(fn), v0051);
    }
}



/* Code for cl_varl1 */

static Lisp_Object CC_cl_varl1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0055, v0056, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_varl1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0054 = v0000;
/* end of prologue */
    v0057 = v0054;
    v0056 = qvalue(elt(env, 1)); /* nil */
    v0055 = qvalue(elt(env, 1)); /* nil */
    v0054 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_varl2 */
        return (*qfnn(fn))(qenv(fn), 4, v0057, v0056, v0055, v0054);
    }
}



/* Code for subs2 */

static Lisp_Object CC_subs2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0020 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0020 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0020 = qvalue(elt(env, 2)); /* !*sub2 */
    if (!(v0020 == nil)) goto v0052;
    v0020 = qvalue(elt(env, 3)); /* powlis1!* */
    if (!(v0020 == nil)) goto v0052;

v0067:
    v0020 = qvalue(elt(env, 4)); /* !*combineexpt */
    if (v0020 == nil) goto v0068;
    v0020 = stack[-3];
    v0020 = qcar(v0020);
    fn = elt(env, 11); /* exptchk */
    stack[0] = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    v0020 = stack[-3];
    v0020 = qcdr(v0020);
    fn = elt(env, 11); /* exptchk */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    fn = elt(env, 12); /* invsq */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    fn = elt(env, 13); /* multsq */
    v0020 = (*qfn2(fn))(qenv(fn), stack[0], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    goto v0070;

v0070:
    stack[-3] = v0020;
    v0066 = elt(env, 5); /* slash */
    v0020 = elt(env, 6); /* opmtch */
    v0020 = get(v0066, v0020);
    env = stack[-5];
    stack[0] = v0020;
    v0020 = qvalue(elt(env, 7)); /* !*match */
    if (!(v0020 == nil)) goto v0016;
    v0020 = stack[0];
    if (!(v0020 == nil)) goto v0016;
    v0020 = qvalue(elt(env, 8)); /* t */
    goto v0071;

v0071:
    if (!(v0020 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0020 = qvalue(elt(env, 9)); /* !*exp */
    if (!(v0020 == nil)) goto v0072;
    v0020 = qvalue(elt(env, 8)); /* t */
    stack[-4] = v0020;
    v0020 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v0020; /* !*exp */
    v0020 = stack[-3];
    stack[-2] = v0020;
    v0020 = stack[-3];
    fn = elt(env, 14); /* resimp */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    stack[-3] = v0020;
    stack[-1] = v0020;
    goto v0072;

v0072:
    v0020 = stack[-3];
    fn = elt(env, 15); /* subs3q */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    stack[-3] = v0020;
    v0020 = stack[-4];
    if (v0020 == nil) goto v0025;
    v0020 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 9)) = v0020; /* !*exp */
    v0066 = stack[-3];
    v0020 = stack[-1];
    if (!(equal(v0066, v0020))) goto v0025;
    v0020 = stack[-2];
    stack[-3] = v0020;
    goto v0025;

v0025:
    v0020 = stack[0];
    if (v0020 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0020 = stack[-3];
    fn = elt(env, 16); /* subs4q */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    stack[-3] = v0020;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0016:
    v0020 = stack[-3];
    v0020 = qcar(v0020);
    v0020 = (v0020 == nil ? lisp_true : nil);
    goto v0071;

v0068:
    v0020 = stack[-3];
    goto v0070;

v0052:
    v0020 = stack[-3];
    fn = elt(env, 17); /* subs2q */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-5];
    stack[-3] = v0020;
    goto v0067;
/* error exit handlers */
v0069:
    popv(6);
    return nil;
}



/* Code for ibalp_getupl */

static Lisp_Object CC_ibalp_getupl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0023;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getupl");
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
    v0076 = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v0076;
    goto v0077;

v0077:
    v0076 = stack[-1];
    if (v0076 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0076 = stack[-1];
    v0076 = qcar(v0076);
    stack[0] = v0076;
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    if (v0076 == nil) goto v0033;
    v0076 = qvalue(elt(env, 1)); /* nil */
    goto v0068;

v0068:
    if (v0076 == nil) goto v0078;
    v0023 = stack[0];
    v0076 = stack[-2];
    v0076 = cons(v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    stack[-2] = v0076;
    goto v0078;

v0078:
    v0076 = stack[-1];
    v0076 = qcdr(v0076);
    stack[-1] = v0076;
    goto v0077;

v0033:
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0023 = qcar(v0076);
    v0076 = stack[0];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    v0023 = plus2(v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0076 = (Lisp_Object)17; /* 1 */
    v0076 = Leqn(nil, v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    goto v0068;
/* error exit handlers */
v0079:
    popv(4);
    return nil;
}



/* Code for ev_comp */

static Lisp_Object CC_ev_comp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0057;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_comp");
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
    v0056 = v0001;
    v0057 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dip_sortevcomp!* */
    v0056 = list2(v0057, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    {
        Lisp_Object v0064 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0064, v0056);
    }
/* error exit handlers */
v0081:
    popv(2);
    return nil;
}



/* Code for ps!:evaluate */

static Lisp_Object CC_psTevaluate(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0061)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:evaluate");
#endif
    if (stack >= stacklimit)
    {
        push2(v0061,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0061;
    v0084 = v0001;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v0084; /* ps */
    v0085 = qvalue(elt(env, 1)); /* ps */
    v0084 = stack[-2];
    fn = elt(env, 3); /* ps!:get!-term */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    stack[-1] = v0084;
    v0084 = stack[-1];
    if (v0084 == nil) goto v0078;
    v0084 = stack[-1];
    goto v0087;

v0087:
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v0084); }

v0078:
    v0084 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:last!-term */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0084 = add1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    stack[0] = v0084;
    goto v0088;

v0088:
    v0085 = stack[-2];
    v0084 = stack[0];
    v0084 = difference2(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    v0084 = Lminusp(nil, v0084);
    env = stack[-4];
    if (v0084 == nil) goto v0089;
    v0084 = stack[-1];
    goto v0087;

v0089:
    v0085 = qvalue(elt(env, 1)); /* ps */
    v0084 = stack[0];
    fn = elt(env, 5); /* ps!:evaluate!-next */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    stack[-1] = v0084;
    v0084 = stack[0];
    v0084 = add1(v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-4];
    stack[0] = v0084;
    goto v0088;
/* error exit handlers */
v0086:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for pnthxzz */

static Lisp_Object CC_pnthxzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0092, v0093, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pnthxzz");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0093 = v0001;
    v0065 = v0000;
/* end of prologue */

v0038:
    v0091 = v0093;
    if (v0091 == nil) goto v0040;
    v0091 = v0093;
    v0091 = qcar(v0091);
    v0092 = qcar(v0091);
    v0091 = v0065;
    v0091 = (equal(v0092, v0091) ? lisp_true : nil);
    goto v0034;

v0034:
    if (!(v0091 == nil)) return onevalue(v0093);
    v0091 = v0093;
    v0091 = qcdr(v0091);
    v0093 = v0091;
    goto v0038;

v0040:
    v0091 = qvalue(elt(env, 1)); /* t */
    goto v0034;
}



/* Code for csl_timbf */

static Lisp_Object CC_csl_timbf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0023, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csl_timbf");
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
    v0076 = stack[-3];
    v0076 = qcdr(v0076);
    v0023 = qcar(v0076);
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    v0076 = qcar(v0076);
    v0076 = times2(v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    v0099 = v0076;
    v0023 = v0099;
    v0076 = (Lisp_Object)1; /* 0 */
    if (v0023 == v0076) goto v0078;
    v0023 = v0099;
    v0076 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 4); /* inorm */
    v0076 = (*qfn2(fn))(qenv(fn), v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    v0099 = v0076;
    stack[-4] = elt(env, 3); /* !:rd!: */
    v0076 = v0099;
    stack[-1] = qcar(v0076);
    v0076 = v0099;
    stack[0] = qcdr(v0076);
    v0076 = stack[-3];
    v0076 = qcdr(v0076);
    v0023 = qcdr(v0076);
    v0076 = stack[-2];
    v0076 = qcdr(v0076);
    v0076 = qcdr(v0076);
    v0076 = plus2(v0023, v0076);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    env = stack[-5];
    v0076 = plus2(stack[0], v0076);
    nil = C_nil;
    if (exception_pending()) goto v0100;
    {
        Lisp_Object v0101 = stack[-4];
        Lisp_Object v0102 = stack[-1];
        popv(6);
        return list2star(v0101, v0102, v0076);
    }

v0078:
    v0076 = elt(env, 1); /* (!:rd!: 0 . 0) */
    { popv(6); return onevalue(v0076); }
/* error exit handlers */
v0100:
    popv(6);
    return nil;
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate0");
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
    stack[0] = v0001;
    v0040 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v0039 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0040 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v0039, v0040);
    }
/* error exit handlers */
v0053:
    popv(2);
    return nil;
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0034;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for optype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0080 = v0000;
/* end of prologue */
    v0034 = elt(env, 1); /* !*optype!* */
    return get(v0080, v0034);
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0061, Lisp_Object v0051, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0114, v0115, v0116, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode1");
#endif
    if (stack >= stacklimit)
    {
        push4(v0051,v0061,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0061,v0051);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0115 = v0051;
    stack[0] = v0061;
    stack[-1] = v0001;
    v0116 = v0000;
/* end of prologue */

v0040:
    v0045 = v0115;
    v0114 = elt(env, 1); /* real */
    if (!(v0045 == v0114)) goto v0068;
    v0114 = elt(env, 2); /* algebraic */
    v0115 = v0114;
    goto v0068;

v0068:
    v0045 = stack[0];
    v0114 = elt(env, 1); /* real */
    if (!(v0045 == v0114)) goto v0065;
    v0114 = elt(env, 2); /* algebraic */
    stack[0] = v0114;
    goto v0065;

v0065:
    v0045 = stack[0];
    v0114 = v0115;
    if (v0045 == v0114) { popv(4); return onevalue(v0116); }
    v0114 = v0116;
    if (!(symbolp(v0114))) goto v0117;
    v0045 = v0116;
    v0114 = stack[-1];
    v0114 = Latsoc(nil, v0045, v0114);
    stack[-2] = v0114;
    if (v0114 == nil) goto v0117;
    v0114 = stack[-2];
    v0045 = qcdr(v0114);
    v0114 = elt(env, 3); /* (integer scalar real) */
    v0114 = Lmemq(nil, v0045, v0114);
    if (v0114 == nil) goto v0118;
    v0114 = qvalue(elt(env, 4)); /* nil */
    goto v0119;

v0119:
    if (v0114 == nil) goto v0117;
    v0115 = stack[-1];
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    fn = elt(env, 5); /* form1 */
    v0116 = (*qfnn(fn))(qenv(fn), 3, v0116, v0115, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0045 = stack[-1];
    v0115 = stack[0];
    v0114 = stack[-2];
    v0114 = qcdr(v0114);
    stack[-1] = v0045;
    stack[0] = v0115;
    v0115 = v0114;
    goto v0040;

v0117:
    v0045 = v0115;
    v0114 = stack[0];
    v0114 = get(v0045, v0114);
    env = stack[-3];
    stack[-2] = v0114;
    if (v0114 == nil) goto v0121;
    v0115 = stack[-2];
    v0114 = stack[-1];
        popv(4);
        return Lapply2(nil, 3, v0115, v0116, v0114);

v0121:
    v0114 = stack[0];
    fn = elt(env, 6); /* typerr */
    v0114 = (*qfn2(fn))(qenv(fn), v0115, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    v0114 = nil;
    { popv(4); return onevalue(v0114); }

v0118:
    v0114 = stack[-2];
    v0045 = qcdr(v0114);
    v0114 = v0115;
    v0114 = (v0045 == v0114 ? lisp_true : nil);
    v0114 = (v0114 == nil ? lisp_true : nil);
    goto v0119;
/* error exit handlers */
v0120:
    popv(4);
    return nil;
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpplus");
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
    v0094 = stack[0];
    v0089 = Llength(nil, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    v0094 = (Lisp_Object)33; /* 2 */
    if (!(v0089 == v0094)) goto v0081;
    v0094 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    goto v0081;

v0081:
    v0089 = qvalue(elt(env, 1)); /* nil */
    v0094 = (Lisp_Object)17; /* 1 */
    v0094 = cons(v0089, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    stack[-1] = v0094;
    goto v0038;

v0038:
    v0094 = stack[0];
    if (v0094 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0094 = stack[0];
    v0094 = qcar(v0094);
    fn = elt(env, 3); /* simp */
    v0089 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    v0094 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v0094 = (*qfn2(fn))(qenv(fn), v0089, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-2];
    stack[-1] = v0094;
    v0094 = stack[0];
    v0094 = qcdr(v0094);
    stack[0] = v0094;
    goto v0038;
/* error exit handlers */
v0063:
    popv(3);
    return nil;
}



/* Code for fs!:timestermterm */

static Lisp_Object CC_fsTtimestermterm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0184, v0185, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:timestermterm");
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
    v0184 = (Lisp_Object)113; /* 7 */
    v0184 = Lmkvect(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[-8] = v0184;
    v0185 = stack[-7];
    v0184 = (Lisp_Object)33; /* 2 */
    v0184 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    stack[-4] = v0184;
    v0185 = stack[-6];
    v0184 = (Lisp_Object)33; /* 2 */
    v0184 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    stack[-3] = v0184;
    v0184 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0184;
    goto v0033;

v0033:
    v0185 = (Lisp_Object)113; /* 7 */
    v0184 = stack[-2];
    v0184 = difference2(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0184 = Lminusp(nil, v0184);
    env = stack[-9];
    if (v0184 == nil) goto v0074;
    v0184 = (Lisp_Object)113; /* 7 */
    v0184 = Lmkvect(nil, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[-5] = v0184;
    v0184 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0184;
    goto v0021;

v0021:
    v0185 = (Lisp_Object)113; /* 7 */
    v0184 = stack[-2];
    v0184 = difference2(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0184 = Lminusp(nil, v0184);
    env = stack[-9];
    if (v0184 == nil) goto v0188;
    v0185 = stack[-7];
    v0184 = (Lisp_Object)1; /* 0 */
    v0186 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0185 = stack[-6];
    v0184 = (Lisp_Object)1; /* 0 */
    v0184 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    fn = elt(env, 5); /* multsq */
    v0184 = (*qfn2(fn))(qenv(fn), v0186, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[0] = v0184;
    v0185 = stack[0];
    v0184 = elt(env, 2); /* (1 . 2) */
    fn = elt(env, 5); /* multsq */
    v0184 = (*qfn2(fn))(qenv(fn), v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[0] = v0184;
    v0184 = stack[0];
    v0184 = qcar(v0184);
    if (v0184 == nil) goto v0189;
    v0185 = stack[-7];
    v0184 = (Lisp_Object)17; /* 1 */
    v0185 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0184 = elt(env, 3); /* sin */
    if (v0185 == v0184) goto v0190;
    v0185 = stack[-6];
    v0184 = (Lisp_Object)17; /* 1 */
    v0185 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0184 = elt(env, 3); /* sin */
    if (v0185 == v0184) goto v0191;
    v0186 = elt(env, 4); /* cos */
    v0185 = stack[-8];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0186 = elt(env, 4); /* cos */
    v0185 = stack[-5];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0184 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    {
        Lisp_Object v0192 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0192, v0184);
    }

v0191:
    v0186 = elt(env, 3); /* sin */
    v0185 = stack[-8];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[-1] = elt(env, 3); /* sin */
    stack[-3] = stack[-5];
    v0184 = stack[0];
    v0184 = qcar(v0184);
    fn = elt(env, 8); /* negf */
    v0185 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0184 = stack[0];
    v0184 = qcdr(v0184);
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    v0184 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-3], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    {
        Lisp_Object v0193 = stack[-2];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0193, v0184);
    }

v0190:
    v0185 = stack[-6];
    v0184 = (Lisp_Object)17; /* 1 */
    v0185 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0184 = elt(env, 3); /* sin */
    if (v0185 == v0184) goto v0194;
    v0186 = elt(env, 3); /* sin */
    v0185 = stack[-8];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0186 = elt(env, 3); /* sin */
    v0185 = stack[-5];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0184 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    {
        Lisp_Object v0195 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0195, v0184);
    }

v0194:
    stack[-1] = elt(env, 4); /* cos */
    stack[-2] = stack[-8];
    v0184 = stack[0];
    v0184 = qcar(v0184);
    fn = elt(env, 8); /* negf */
    v0185 = (*qfn1(fn))(qenv(fn), v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0184 = stack[0];
    v0184 = qcdr(v0184);
    v0184 = cons(v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    fn = elt(env, 6); /* make!-term */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    v0186 = elt(env, 4); /* cos */
    v0185 = stack[-5];
    v0184 = stack[0];
    fn = elt(env, 6); /* make!-term */
    v0184 = (*qfnn(fn))(qenv(fn), 3, v0186, v0185, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    {
        Lisp_Object v0196 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0196, v0184);
    }

v0189:
    v0184 = qvalue(elt(env, 1)); /* nil */
    { popv(10); return onevalue(v0184); }

v0188:
    stack[-1] = stack[-5];
    stack[0] = stack[-2];
    v0185 = stack[-4];
    v0184 = stack[-2];
    v0186 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0185 = stack[-3];
    v0184 = stack[-2];
    v0184 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0184 = difference2(v0186, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0184;
    v0184 = stack[-2];
    v0184 = add1(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[-2] = v0184;
    goto v0021;

v0074:
    stack[-1] = stack[-8];
    stack[0] = stack[-2];
    v0185 = stack[-4];
    v0184 = stack[-2];
    v0186 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0185 = stack[-3];
    v0184 = stack[-2];
    v0184 = *(Lisp_Object *)((char *)v0185 + (CELL-TAG_VECTOR) + ((int32_t)v0184/(16/CELL)));
    v0184 = plus2(v0186, v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0184;
    v0184 = stack[-2];
    v0184 = add1(v0184);
    nil = C_nil;
    if (exception_pending()) goto v0187;
    env = stack[-9];
    stack[-2] = v0184;
    goto v0033;
/* error exit handlers */
v0187:
    popv(10);
    return nil;
}



/* Code for mo_sum */

static Lisp_Object CC_mo_sum(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_sum");
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
    v0082 = v0000;
/* end of prologue */
    v0082 = qcar(v0082);
    v0068 = qcar(v0068);
    fn = elt(env, 1); /* mo!=sum */
    v0068 = (*qfn2(fn))(qenv(fn), v0082, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    stack[-1] = v0068;
    v0068 = stack[-1];
    fn = elt(env, 2); /* mo!=shorten */
    stack[0] = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-2];
    v0068 = stack[-1];
    fn = elt(env, 3); /* mo!=deglist */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    {
        Lisp_Object v0111 = stack[0];
        popv(3);
        return cons(v0111, v0068);
    }
/* error exit handlers */
v0098:
    popv(3);
    return nil;
}



/* Code for gcdf!* */

static Lisp_Object CC_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0055;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf*");
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
    v0054 = v0001;
    v0055 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0053 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v0053; /* !*gcd */
    v0053 = v0055;
    fn = elt(env, 3); /* gcdf */
    v0053 = (*qfn2(fn))(qenv(fn), v0053, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0053); }
/* error exit handlers */
v0057:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0091, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv");
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
    stack[0] = v0001;
    v0030 = v0000;
/* end of prologue */
    v0091 = v0030;
    v0030 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0030 = (*qfn2(fn))(qenv(fn), v0091, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    v0091 = v0030;
    v0030 = v0091;
    if (v0030 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0030 = v0091;
    fn = elt(env, 3); /* pv_renorm */
    v0092 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-1];
    v0091 = stack[0];
    v0030 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 4); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v0092, v0091, v0030);
    }
/* error exit handlers */
v0065:
    popv(2);
    return nil;
}



/* Code for mkrn */

static Lisp_Object CC_mkrn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0085, v0108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrn");
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

v0034:
    v0108 = stack[-1];
    v0085 = (Lisp_Object)1; /* 0 */
    v0085 = (Lisp_Object)lessp2(v0108, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-4];
    if (v0085 == nil) goto v0082;
    v0085 = stack[-2];
    v0085 = negate(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[-2] = v0085;
    v0085 = stack[-1];
    v0085 = negate(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[-1] = v0085;
    goto v0034;

v0082:
    v0108 = stack[-2];
    v0085 = stack[-1];
    v0085 = Lgcd(nil, v0108, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    stack[-3] = v0085;
    stack[0] = elt(env, 1); /* !:rn!: */
    v0108 = stack[-2];
    v0085 = stack[-3];
    stack[-2] = quot2(v0108, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-4];
    v0108 = stack[-1];
    v0085 = stack[-3];
    v0085 = quot2(v0108, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    {
        Lisp_Object v0044 = stack[0];
        Lisp_Object v0197 = stack[-2];
        popv(5);
        return list2star(v0044, v0197, v0085);
    }
/* error exit handlers */
v0016:
    popv(5);
    return nil;
}



/* Code for divide!: */

static Lisp_Object MS_CDECL CC_divideT(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0061, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0198, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "divide:");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divide:");
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0061;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = stack[-1];
    v0198 = stack[-2];
    v0198 = qcdr(v0198);
    v0198 = qcar(v0198);
    v0198 = Labsval(nil, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 2); /* msd */
    v0198 = (*qfn1(fn))(qenv(fn), v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0198 = add1(v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0198 = plus2(stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    fn = elt(env, 3); /* conv!:mt */
    v0198 = (*qfn2(fn))(qenv(fn), stack[-3], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    stack[-3] = v0198;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0198 = stack[-3];
    v0198 = qcdr(v0198);
    v0095 = qcar(v0198);
    v0198 = stack[-2];
    v0198 = qcdr(v0198);
    v0198 = qcar(v0198);
    stack[0] = quot2(v0095, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0198 = stack[-3];
    v0198 = qcdr(v0198);
    v0095 = qcdr(v0198);
    v0198 = stack[-2];
    v0198 = qcdr(v0198);
    v0198 = qcdr(v0198);
    v0198 = difference2(v0095, v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    v0198 = list2star(stack[-4], stack[0], v0198);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-5];
    stack[-3] = v0198;
    v0095 = stack[-3];
    v0198 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v0095, v0198);
    }
/* error exit handlers */
v0079:
    popv(6);
    return nil;
}



/* Code for c!:ordexp */

static Lisp_Object CC_cTordexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0033, v0031, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:ordexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0033 = v0001;
    v0031 = v0000;
/* end of prologue */

v0038:
    v0032 = v0031;
    if (v0032 == nil) goto v0077;
    v0032 = v0031;
    v0109 = qcar(v0032);
    v0032 = v0033;
    v0032 = qcar(v0032);
    if (equal(v0109, v0032)) goto v0040;
    v0032 = v0031;
    v0032 = qcar(v0032);
    v0033 = qcar(v0033);
    {
        fn = elt(env, 2); /* c!:ordxp */
        return (*qfn2(fn))(qenv(fn), v0032, v0033);
    }

v0040:
    v0032 = v0031;
    v0032 = qcdr(v0032);
    v0031 = v0032;
    v0032 = v0033;
    v0032 = qcdr(v0032);
    v0033 = v0032;
    goto v0038;

v0077:
    v0032 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0032);
}



/* Code for !*i2gi */

static Lisp_Object CC_Hi2gi(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0052, v0053;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2gi");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0039 = v0000;
/* end of prologue */
    v0053 = elt(env, 1); /* !:gi!: */
    v0052 = v0039;
    v0039 = (Lisp_Object)1; /* 0 */
    return list2star(v0053, v0052, v0039);
}



/* Code for xread */

static Lisp_Object CC_xread(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xread");
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

v0060:
    fn = elt(env, 4); /* scan */
    v0064 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0064 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (v0064 == nil) goto v0177;
    v0070 = qvalue(elt(env, 2)); /* cursym!* */
    v0064 = elt(env, 3); /* !*semicol!* */
    if (v0070 == v0064) goto v0060;
    else goto v0177;

v0177:
    v0064 = stack[0];
    {
        popv(2);
        fn = elt(env, 5); /* xread1 */
        return (*qfn1(fn))(qenv(fn), v0064);
    }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for mcharg */

static Lisp_Object MS_CDECL CC_mcharg(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0061, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0011, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mcharg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg");
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0061;
    stack[0] = v0001;
    v0114 = v0000;
/* end of prologue */
    v0011 = elt(env, 1); /* minus */
    v0013 = stack[0];
    v0013 = Latsoc(nil, v0011, v0013);
    if (v0013 == nil) goto v0177;
    v0011 = v0114;
    v0013 = stack[0];
    fn = elt(env, 4); /* reform!-minus */
    v0114 = (*qfn2(fn))(qenv(fn), v0011, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0011 = stack[0];
    v0013 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v0114, v0011, v0013);
    }

v0177:
    v0013 = stack[0];
    if (v0013 == nil) goto v0010;
    v0013 = stack[0];
    v0011 = qcar(v0013);
    v0013 = elt(env, 2); /* slash */
    if (!consp(v0011)) goto v0010;
    v0011 = qcar(v0011);
    if (!(v0011 == v0013)) goto v0010;
    v0011 = v0114;
    v0013 = stack[0];
    fn = elt(env, 6); /* reform!-minus2 */
    v0013 = (*qfn2(fn))(qenv(fn), v0011, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-4] = v0013;
    goto v0075;

v0075:
    v0013 = stack[-4];
    if (v0013 == nil) goto v0044;
    v0013 = stack[-4];
    v0013 = qcar(v0013);
    v0011 = v0013;
    v0114 = qcar(v0011);
    v0011 = qcdr(v0013);
    v0013 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v0013 = (*qfnn(fn))(qenv(fn), 3, v0114, v0011, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-2] = v0013;
    v0013 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-1] = v0013;
    v0013 = stack[-4];
    v0013 = qcdr(v0013);
    stack[-4] = v0013;
    v0013 = stack[-1];
    if (!consp(v0013)) goto v0075;
    else goto v0073;

v0073:
    v0013 = stack[-4];
    if (v0013 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0013 = stack[-4];
    v0013 = qcar(v0013);
    v0011 = v0013;
    v0114 = qcar(v0011);
    v0011 = qcdr(v0013);
    v0013 = stack[-3];
    fn = elt(env, 5); /* mcharg1 */
    v0013 = (*qfnn(fn))(qenv(fn), 3, v0114, v0011, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0013 = Lrplacd(nil, stack[0], v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    v0013 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-5];
    stack[-1] = v0013;
    v0013 = stack[-4];
    v0013 = qcdr(v0013);
    stack[-4] = v0013;
    goto v0073;

v0044:
    v0013 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0013); }

v0010:
    v0011 = stack[0];
    v0013 = stack[-3];
    {
        popv(6);
        fn = elt(env, 5); /* mcharg1 */
        return (*qfnn(fn))(qenv(fn), 3, v0114, v0011, v0013);
    }
/* error exit handlers */
v0169:
    popv(6);
    return nil;
}



/* Code for ibalp_minclnr */

static Lisp_Object CC_ibalp_minclnr(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0204;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_minclnr");
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
    v0204 = v0000;
/* end of prologue */
    v0079 = (Lisp_Object)1600001; /* 100000 */
    stack[-2] = v0079;
    v0079 = v0204;
    stack[-1] = v0079;
    goto v0067;

v0067:
    v0079 = stack[-1];
    if (v0079 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    stack[0] = v0079;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    if (!(v0079 == nil)) goto v0081;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0204 = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0204 = plus2(v0204, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-3];
    v0079 = stack[-2];
    v0079 = (Lisp_Object)lessp2(v0204, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    v0079 = v0079 ? lisp_true : nil;
    env = stack[-3];
    if (v0079 == nil) goto v0081;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0204 = qcar(v0079);
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcdr(v0079);
    v0079 = qcar(v0079);
    v0079 = plus2(v0204, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-3];
    stack[-2] = v0079;
    goto v0081;

v0081:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-1] = v0079;
    goto v0067;
/* error exit handlers */
v0102:
    popv(4);
    return nil;
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobj");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0098 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v0111 = (*qfn1(fn))(qenv(fn), v0098);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[0];
    v0098 = qvalue(elt(env, 2)); /* omfuncs!* */
    v0098 = Lassoc(nil, v0111, v0098);
    v0111 = v0098;
    if (v0098 == nil) goto v0087;
    v0098 = v0111;
    v0098 = qcdr(v0098);
    v0111 = qcar(v0098);
    v0098 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v0111, v0098);
    }

v0087:
    v0098 = nil;
    { popv(1); return onevalue(v0098); }
/* error exit handlers */
v0110:
    popv(1);
    return nil;
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0094, v0089, v0074;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0094 = v0001;
    v0089 = v0000;
/* end of prologue */

v0067:
    v0074 = v0094;
    v0183 = nil;
    if (v0074 == v0183) goto v0177;
    v0183 = v0094;
    v0183 = qcar(v0183);
    v0089 = Lmember(nil, v0183, v0089);
    v0183 = v0094;
    v0183 = qcdr(v0183);
    v0094 = v0183;
    goto v0067;

v0177:
    v0183 = v0089;
    if (v0183 == nil) goto v0070;
    v0183 = v0089;
    v0183 = qcdr(v0183);
    return onevalue(v0183);

v0070:
    v0183 = elt(env, 1); /* (stop) */
    return onevalue(v0183);
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0061, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0059;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
    if (stack >= stacklimit)
    {
        push3(v0061,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0061);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0061;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = nil;
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    stack[-4] = v0058;
    goto v0040;

v0040:
    v0058 = stack[0];
    if (v0058 == nil) goto v0052;
    v0058 = nil;
    { popv(6); return onevalue(v0058); }

v0052:
    v0058 = stack[-4];
    if (v0058 == nil) goto v0082;
    v0059 = stack[-3];
    v0058 = stack[-4];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = (Lisp_Object)lessp2(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    v0058 = v0058 ? lisp_true : nil;
    env = stack[-5];
    if (v0058 == nil) goto v0207;
    stack[0] = stack[-2];
    v0059 = stack[-3];
    v0058 = stack[-1];
    v0058 = cons(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0059 = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = stack[-4];
    v0058 = Lrplacd(nil, v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = Lrplacd(nil, stack[0], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0058;
    goto v0040;

v0207:
    v0059 = stack[-3];
    v0058 = stack[-4];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = (Lisp_Object)greaterp2(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    v0058 = v0058 ? lisp_true : nil;
    env = stack[-5];
    if (v0058 == nil) goto v0040;
    v0058 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0058;
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    stack[-2] = v0058;
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    stack[-4] = v0058;
    goto v0040;

v0082:
    stack[0] = stack[-2];
    v0059 = stack[-3];
    v0058 = stack[-1];
    v0058 = cons(v0059, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = ncons(v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = Lrplacd(nil, stack[0], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-5];
    v0058 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0058;
    goto v0040;
/* error exit handlers */
v0188:
    popv(6);
    return nil;
}



/* Code for xdegree */

static Lisp_Object CC_xdegree(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0053;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegree");
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
    v0052 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* deg!*form */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    errexit();
    v0053 = v0052;
    v0052 = v0053;
    if (!(v0052 == nil)) return onevalue(v0053);
    v0052 = (Lisp_Object)1; /* 0 */
    return onevalue(v0052);
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemqlp");
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

v0208:
    v0086 = stack[0];
    if (v0086 == nil) goto v0067;
    v0086 = stack[0];
    v0086 = (is_number(v0086) ? lisp_true : nil);
    goto v0077;

v0077:
    if (v0086 == nil) goto v0087;
    v0086 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0086); }

v0087:
    v0086 = stack[0];
    if (!consp(v0086)) goto v0081;
    v0086 = stack[0];
    v0016 = qcar(v0086);
    v0086 = elt(env, 3); /* quote */
    if (v0016 == v0086) goto v0111;
    v0016 = stack[-1];
    v0086 = stack[0];
    v0086 = qcar(v0086);
    v0086 = CC_smemqlp(env, v0016, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    if (!(v0086 == nil)) { popv(3); return onevalue(v0086); }
    v0016 = stack[-1];
    v0086 = stack[0];
    v0086 = qcdr(v0086);
    stack[-1] = v0016;
    stack[0] = v0086;
    goto v0208;

v0111:
    v0086 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0086); }

v0081:
    v0016 = stack[0];
    v0086 = stack[-1];
    v0086 = Lmemq(nil, v0016, v0086);
    { popv(3); return onevalue(v0086); }

v0067:
    v0086 = qvalue(elt(env, 1)); /* t */
    goto v0077;
/* error exit handlers */
v0198:
    popv(3);
    return nil;
}



/* Code for delallasc */

static Lisp_Object CC_delallasc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0031, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delallasc");
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
    v0109 = nil;
    goto v0087;

v0087:
    v0033 = stack[0];
    if (v0033 == nil) goto v0067;
    v0031 = stack[-1];
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    if (v0031 == v0033) goto v0052;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    v0031 = v0109;
    v0033 = cons(v0033, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0183;
    env = stack[-2];
    v0109 = v0033;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0087;

v0052:
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0087;

v0067:
    v0033 = v0109;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0033);
    }
/* error exit handlers */
v0183:
    popv(3);
    return nil;
}



/* Code for getphystype!*sq */

static Lisp_Object CC_getphystypeHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype*sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0000;
/* end of prologue */
    v0087 = qcar(v0087);
    v0087 = qcar(v0087);
    {
        fn = elt(env, 1); /* getphystypesf */
        return (*qfn1(fn))(qenv(fn), v0087);
    }
}



/* Code for argnochk */

static Lisp_Object CC_argnochk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0162, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for argnochk");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0165 = qvalue(elt(env, 1)); /* !*argnochk */
    if (v0165 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0165 = stack[-4];
    v0162 = qcar(v0165);
    v0165 = elt(env, 2); /* number!-of!-args */
    v0165 = get(v0162, v0165);
    env = stack[-6];
    stack[-5] = v0165;
    if (v0165 == nil) goto v0218;
    stack[0] = stack[-5];
    v0165 = stack[-4];
    v0165 = qcdr(v0165);
    v0165 = Llength(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    if (equal(stack[0], v0165)) goto v0206;
    v0165 = stack[-4];
    v0162 = qcar(v0165);
    v0165 = elt(env, 3); /* simpfn */
    v0165 = get(v0162, v0165);
    env = stack[-6];
    if (!(v0165 == nil)) goto v0033;
    v0165 = stack[-4];
    v0162 = qcar(v0165);
    v0165 = elt(env, 4); /* psopfn */
    v0165 = get(v0162, v0165);
    env = stack[-6];
    if (!(v0165 == nil)) goto v0033;
    v0165 = stack[-4];
    v0162 = qcar(v0165);
    v0165 = elt(env, 5); /* variadic */
    v0165 = Lflagp(nil, v0162, v0165);
    env = stack[-6];
    goto v0033;

v0033:
    v0165 = (v0165 == nil ? lisp_true : nil);
    goto v0097;

v0097:
    if (v0165 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0165 = qvalue(elt(env, 7)); /* !*strict_argcount */
    if (v0165 == nil) goto v0013;
    v0165 = elt(env, 8); /* "+++++ " */
    v0165 = Lprinc(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = stack[-4];
    v0165 = Lprint(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = stack[-4];
    stack[-2] = qcar(v0165);
    stack[-1] = elt(env, 9); /* "called with" */
    v0165 = stack[-4];
    v0165 = qcdr(v0165);
    stack[0] = Llength(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = stack[-4];
    v0165 = qcdr(v0165);
    v0162 = Llength(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = (Lisp_Object)17; /* 1 */
    if (v0162 == v0165) goto v0175;
    v0165 = elt(env, 11); /* "arguments" */
    v0163 = v0165;
    goto v0019;

v0019:
    v0162 = elt(env, 12); /* "instead of" */
    v0165 = stack[-5];
    v0165 = list3(v0163, v0162, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = list3star(stack[-2], stack[-1], stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0162 = v0165;
    v0165 = v0162;
    qvalue(elt(env, 13)) = v0165; /* errmsg!* */
    v0165 = qvalue(elt(env, 14)); /* !*protfg */
    if (!(v0165 == nil)) goto v0219;
    v0165 = v0162;
    fn = elt(env, 17); /* lprie */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    goto v0219;

v0219:
    v0165 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    v0165 = nil;
    { popv(7); return onevalue(v0165); }

v0175:
    v0165 = elt(env, 10); /* "argument" */
    v0163 = v0165;
    goto v0019;

v0013:
    v0165 = qvalue(elt(env, 15)); /* !*msg */
    if (v0165 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    stack[-3] = elt(env, 16); /* "***" */
    v0165 = stack[-4];
    stack[-2] = qcar(v0165);
    stack[-1] = elt(env, 9); /* "called with" */
    v0165 = stack[-4];
    v0165 = qcdr(v0165);
    stack[0] = Llength(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0163 = elt(env, 12); /* "instead of" */
    v0162 = stack[-5];
    v0165 = elt(env, 11); /* "arguments" */
    v0165 = list3(v0163, v0162, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = list3star(stack[-2], stack[-1], stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    fn = elt(env, 18); /* lpriw */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-3], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v0206:
    v0165 = qvalue(elt(env, 6)); /* nil */
    goto v0097;

v0218:
    v0165 = stack[-4];
    stack[-1] = qcar(v0165);
    stack[0] = elt(env, 2); /* number!-of!-args */
    v0165 = stack[-4];
    v0165 = qcdr(v0165);
    v0165 = Llength(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-6];
    v0165 = Lputprop(nil, 3, stack[-1], stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
/* error exit handlers */
v0152:
    popv(7);
    return nil;
}



/* Code for simpminus */

static Lisp_Object CC_simpminus(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpminus");
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
    v0070 = v0000;
/* end of prologue */
    v0068 = v0070;
    v0070 = elt(env, 1); /* minus */
    fn = elt(env, 2); /* carx */
    v0070 = (*qfn2(fn))(qenv(fn), v0068, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    fn = elt(env, 3); /* simp */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    stack[0] = v0070;
    v0070 = stack[0];
    v0070 = qcar(v0070);
    fn = elt(env, 4); /* negf */
    v0068 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0070 = stack[0];
    v0070 = qcdr(v0070);
    popv(2);
    return cons(v0068, v0070);
/* error exit handlers */
v0090:
    popv(2);
    return nil;
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0086, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_compare");
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
    v0203 = stack[-1];
    v0086 = qcdr(v0203);
    v0203 = stack[0];
    v0203 = qcdr(v0203);
    fn = elt(env, 3); /* mo!=degcomp */
    v0203 = (*qfn2(fn))(qenv(fn), v0086, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0016 = v0203;
    v0086 = v0016;
    v0203 = (Lisp_Object)1; /* 0 */
    if (!(v0086 == v0203)) { popv(3); return onevalue(v0016); }
    v0203 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v0086 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-2];
    v0203 = elt(env, 2); /* revlex */
    if (v0086 == v0203) goto v0033;
    v0203 = stack[-1];
    v0086 = qcar(v0203);
    v0203 = stack[0];
    v0203 = qcar(v0203);
    fn = elt(env, 5); /* mo!=lexcomp */
    v0203 = (*qfn2(fn))(qenv(fn), v0086, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    goto v0098;

v0098:
    v0016 = v0203;
    { popv(3); return onevalue(v0016); }

v0033:
    v0203 = stack[-1];
    v0086 = qcar(v0203);
    v0203 = stack[0];
    v0203 = qcar(v0203);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v0203 = (*qfn2(fn))(qenv(fn), v0086, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    goto v0098;
/* error exit handlers */
v0198:
    popv(3);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprin");
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
    v0182 = stack[0];
    v0204 = elt(env, 1); /* prtch */
    v0204 = get(v0182, v0204);
    env = stack[-2];
    stack[-1] = v0204;
    v0204 = stack[-1];
    if (v0204 == nil) goto v0039;
    v0204 = qvalue(elt(env, 3)); /* !*fort */
    if (v0204 == nil) goto v0070;
    v0204 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0204);
    }

v0070:
    v0204 = qvalue(elt(env, 4)); /* !*list */
    if (v0204 == nil) goto v0085;
    v0204 = qvalue(elt(env, 5)); /* obrkp!* */
    if (v0204 == nil) goto v0085;
    v0182 = stack[0];
    v0204 = elt(env, 6); /* (plus minus) */
    v0204 = Lmemq(nil, v0182, v0204);
    if (v0204 == nil) goto v0085;
    v0204 = qvalue(elt(env, 7)); /* testing!-width!* */
    if (v0204 == nil) goto v0062;
    v0204 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v0204; /* overflowed!* */
    { popv(3); return onevalue(v0204); }

v0062:
    v0204 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 12); /* terpri!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0204 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0204);
    }

v0085:
    v0182 = stack[0];
    v0204 = elt(env, 10); /* spaced */
    v0204 = Lflagp(nil, v0182, v0204);
    env = stack[-2];
    if (v0204 == nil) goto v0099;
    v0204 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0204 = stack[-1];
    fn = elt(env, 11); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0204 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0204);
    }

v0099:
    v0204 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0204);
    }

v0039:
    v0204 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0204 = stack[0];
    fn = elt(env, 11); /* prin2!* */
    v0204 = (*qfn1(fn))(qenv(fn), v0204);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-2];
    v0204 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0204);
    }
/* error exit handlers */
v0102:
    popv(3);
    return nil;
}



/* Code for pv_renorm */

static Lisp_Object CC_pv_renorm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_renorm");
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
    stack[0] = v0000;
/* end of prologue */
    v0168 = stack[0];
    if (!(v0168 == nil)) goto v0054;
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }

v0054:
    v0168 = stack[0];
    if (v0168 == nil) goto v0053;
    v0168 = stack[0];
    v0168 = qcar(v0168);
    v0008 = qcar(v0168);
    v0168 = (Lisp_Object)1; /* 0 */
    if (!(v0008 == v0168)) goto v0053;
    v0168 = stack[0];
    v0168 = qcdr(v0168);
    stack[0] = v0168;
    goto v0054;

v0053:
    v0168 = stack[0];
    if (v0168 == nil) goto v0088;
    v0168 = stack[0];
    v0168 = qcar(v0168);
    v0008 = qcar(v0168);
    v0168 = (Lisp_Object)1; /* 0 */
    v0168 = (Lisp_Object)lessp2(v0008, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-4];
    if (v0168 == nil) goto v0083;
    v0168 = stack[0];
    fn = elt(env, 2); /* pv_neg */
    v0168 = (*qfn1(fn))(qenv(fn), v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[0] = v0168;
    goto v0083;

v0083:
    v0168 = stack[0];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    stack[-2] = v0168;
    v0168 = stack[0];
    v0168 = qcdr(v0168);
    stack[-3] = v0168;
    goto v0044;

v0044:
    v0168 = stack[-3];
    if (v0168 == nil) goto v0016;
    v0008 = stack[-2];
    v0168 = (Lisp_Object)17; /* 1 */
    if (v0008 == v0168) goto v0016;
    v0008 = stack[-2];
    v0168 = stack[-3];
    v0168 = qcar(v0168);
    v0168 = qcar(v0168);
    fn = elt(env, 3); /* gcdf!* */
    v0168 = (*qfn2(fn))(qenv(fn), v0008, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[-2] = v0168;
    v0168 = stack[-3];
    v0168 = qcdr(v0168);
    stack[-3] = v0168;
    goto v0044;

v0016:
    v0168 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0168;
    v0168 = stack[0];
    stack[-1] = v0168;
    goto v0018;

v0018:
    v0168 = stack[-1];
    if (v0168 == nil) goto v0022;
    v0168 = stack[-1];
    v0168 = qcar(v0168);
    stack[0] = v0168;
    v0168 = stack[0];
    v0008 = qcar(v0168);
    v0168 = (Lisp_Object)1; /* 0 */
    if (v0008 == v0168) goto v0112;
    v0008 = stack[-2];
    v0168 = (Lisp_Object)17; /* 1 */
    if (v0008 == v0168) goto v0223;
    v0168 = stack[0];
    v0008 = qcar(v0168);
    v0168 = stack[-2];
    v0008 = quot2(v0008, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0168 = stack[0];
    v0168 = qcdr(v0168);
    v0168 = cons(v0008, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    v0008 = v0168;
    goto v0121;

v0121:
    v0168 = stack[-3];
    v0168 = cons(v0008, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-4];
    stack[-3] = v0168;
    goto v0112;

v0112:
    v0168 = stack[-1];
    v0168 = qcdr(v0168);
    stack[-1] = v0168;
    goto v0018;

v0223:
    v0168 = stack[0];
    v0008 = v0168;
    goto v0121;

v0022:
    v0168 = stack[-3];
        popv(5);
        return Lnreverse(nil, v0168);

v0088:
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0168); }
/* error exit handlers */
v0213:
    popv(5);
    return nil;
}



/* Code for dv_skelhead */

static Lisp_Object CC_dv_skelhead(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelhead");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0038 = qcar(v0038);
    {
        fn = elt(env, 1); /* dv_cambhead */
        return (*qfn1(fn))(qenv(fn), v0038);
    }
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0062, v0063, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removev");
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
    v0027 = v0001;
    v0063 = v0000;
/* end of prologue */

v0038:
    v0074 = v0063;
    if (v0074 == nil) goto v0039;
    v0074 = v0063;
    v0074 = qcdr(v0074);
    v0062 = qcar(v0074);
    v0074 = v0027;
    if (v0062 == v0074) goto v0093;
    v0074 = v0063;
    v0074 = qcdr(v0074);
    v0063 = v0074;
    goto v0038;

v0093:
    v0074 = v0063;
    v0062 = v0063;
    v0062 = qcdr(v0062);
    v0062 = qcdr(v0062);
        popv(1);
        return Lrplacd(nil, v0074, v0062);

v0039:
    v0062 = elt(env, 1); /* "Vertex" */
    v0063 = v0027;
    v0074 = elt(env, 2); /* "is absent." */
    v0074 = list3(v0062, v0063, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v0074);
    }
/* error exit handlers */
v0072:
    popv(1);
    return nil;
}



/* Code for subs2f1 */

static Lisp_Object CC_subs2f1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0282, v0283, v0284, v0285, v0286;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2f1");
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
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
/* end of prologue */
    v0282 = stack[-7];
    if (!consp(v0282)) goto v0077;
    v0282 = stack[-7];
    v0282 = qcar(v0282);
    v0282 = (consp(v0282) ? nil : lisp_true);
    goto v0177;

v0177:
    if (v0282 == nil) goto v0057;
    v0282 = stack[-7];
    {
        popv(10);
        fn = elt(env, 12); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v0282);
    }

v0057:
    stack[-3] = nil;
    v0282 = stack[-7];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    stack[-8] = v0282;
    v0283 = qvalue(elt(env, 2)); /* nil */
    v0282 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-2] = v0282;
    goto v0111;

v0111:
    v0282 = stack[-7];
    if (v0282 == nil) goto v0084;
    v0283 = stack[-7];
    v0282 = stack[-8];
    fn = elt(env, 13); /* degr */
    v0283 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = (Lisp_Object)1; /* 0 */
    v0282 = (v0283 == v0282 ? lisp_true : nil);
    goto v0071;

v0071:
    if (!(v0282 == nil)) goto v0110;
    v0282 = stack[-7];
    v0283 = qcar(v0282);
    v0282 = stack[-3];
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-3] = v0282;
    v0282 = stack[-7];
    v0282 = qcdr(v0282);
    stack[-7] = v0282;
    goto v0111;

v0110:
    v0282 = qvalue(elt(env, 3)); /* powlis!* */
    stack[-4] = v0282;
    goto v0029;

v0029:
    v0282 = stack[-4];
    if (v0282 == nil) goto v0030;
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    if (equal(v0283, v0282)) goto v0112;
    v0283 = stack[-8];
    v0282 = elt(env, 4); /* expt */
    if (!consp(v0283)) goto v0163;
    v0283 = qcar(v0283);
    if (!(v0283 == v0282)) goto v0163;
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    if (equal(v0283, v0282)) goto v0008;
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0219;

v0219:
    if (v0282 == nil) goto v0288;
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0283 = qcdr(v0282);
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = Ldivide(nil, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-6] = v0282;
    v0282 = stack[-6];
    v0283 = qcar(v0282);
    v0282 = (Lisp_Object)1; /* 0 */
    if (v0283 == v0282) goto v0144;
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    fn = elt(env, 14); /* simp */
    v0283 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-6];
    v0282 = qcar(v0282);
    fn = elt(env, 15); /* exptsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0145;

v0145:
    v0282 = stack[-6];
    v0283 = qcdr(v0282);
    v0282 = (Lisp_Object)1; /* 0 */
    if (v0283 == v0282) goto v0289;
    stack[-1] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    stack[0] = qvalue(elt(env, 7)); /* dmode!* */
    qvalue(elt(env, 7)) = nil; /* dmode!* */
    v0282 = qvalue(elt(env, 2)); /* nil */
    v0282 = ncons(v0282);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-9];
    qvalue(elt(env, 6)) = v0282; /* alglist!* */
    v0282 = stack[-6];
    v0283 = qcdr(v0282);
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-9];
    fn = elt(env, 16); /* cancel */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0290;
    env = stack[-9];
    stack[-6] = v0282;
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-6];
    v0282 = qcar(v0282);
    v0284 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    fn = elt(env, 17); /* subs2p */
    v0282 = (*qfnn(fn))(qenv(fn), 3, v0284, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 18); /* mk!*sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0284 = elt(env, 5); /* quotient */
    v0283 = (Lisp_Object)17; /* 1 */
    v0282 = stack[-6];
    v0282 = qcdr(v0282);
    v0282 = list3(v0284, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = list2(stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 19); /* simpexpt */
    v0283 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-5];
    fn = elt(env, 20); /* multsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0289;

v0289:
    stack[0] = stack[-5];
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = CC_subs2f1(env, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 20); /* multsq */
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-2];
    fn = elt(env, 21); /* addsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-2] = v0282;
    goto v0093;

v0093:
    v0282 = stack[-3];
    v0282 = qcdr(v0282);
    stack[-3] = v0282;
    v0282 = stack[-3];
    if (!(v0282 == nil)) goto v0110;

v0065:
    v0282 = stack[-7];
    v0282 = CC_subs2f1(env, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-3] = v0282;
    v0282 = qvalue(elt(env, 10)); /* !*exp */
    if (!(v0282 == nil)) goto v0291;
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    fn = elt(env, 22); /* mkprod */
    stack[0] = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-3];
    v0282 = qcdr(v0282);
    fn = elt(env, 22); /* mkprod */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = cons(stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-3] = v0282;
    goto v0291;

v0291:
    v0283 = stack[-2];
    v0282 = stack[-3];
    {
        popv(10);
        fn = elt(env, 21); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0283, v0282);
    }

v0144:
    v0283 = (Lisp_Object)17; /* 1 */
    v0282 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0145;

v0288:
    v0282 = stack[-4];
    v0282 = qcdr(v0282);
    stack[-4] = v0282;
    goto v0029;

v0008:
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = elt(env, 5); /* quotient */
    if (!consp(v0283)) goto v0210;
    v0283 = qcar(v0283);
    if (!(v0283 == v0282)) goto v0210;
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = (Lisp_Object)17; /* 1 */
    if (v0283 == v0282) goto v0037;
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0219;

v0037:
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = (is_number(v0282) ? lisp_true : nil);
    goto v0219;

v0210:
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0219;

v0163:
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0219;

v0112:
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0284 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    fn = elt(env, 17); /* subs2p */
    v0282 = (*qfnn(fn))(qenv(fn), 3, v0284, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0289;

v0030:
    v0282 = qvalue(elt(env, 8)); /* powlis1!* */
    stack[-4] = v0282;
    goto v0091;

v0091:
    v0282 = stack[-4];
    if (v0282 == nil) goto v0292;
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0286 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0285 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0284 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-4];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    fn = elt(env, 23); /* mtchp */
    v0282 = (*qfnn(fn))(qenv(fn), 5, v0286, v0285, v0284, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    if (!(v0282 == nil)) goto v0289;
    v0282 = stack[-4];
    v0282 = qcdr(v0282);
    stack[-4] = v0282;
    goto v0091;

v0292:
    v0283 = stack[-8];
    v0282 = elt(env, 4); /* expt */
    if (!consp(v0283)) goto v0293;
    v0283 = qcar(v0283);
    if (!(v0283 == v0282)) goto v0293;
    v0282 = qvalue(elt(env, 9)); /* !*structure */
    v0282 = (v0282 == nil ? lisp_true : nil);
    goto v0294;

v0294:
    if (!(v0282 == nil)) goto v0295;
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0283 = qcar(v0282);
    v0282 = (Lisp_Object)17; /* 1 */
    v0282 = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0283 = ncons(v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = CC_subs2f1(env, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 20); /* multsq */
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-2];
    fn = elt(env, 21); /* addsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-2] = v0282;
    goto v0093;

v0295:
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0283 = qcdr(v0282);
    v0282 = (Lisp_Object)17; /* 1 */
    if (v0283 == v0282) goto v0296;
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0297;

v0297:
    if (v0282 == nil) goto v0298;
    v0283 = stack[-8];
    v0282 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 24); /* mksq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0299;

v0299:
    stack[0] = stack[-5];
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = CC_subs2f1(env, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 20); /* multsq */
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = stack[-2];
    fn = elt(env, 21); /* addsq */
    v0282 = (*qfn2(fn))(qenv(fn), v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-2] = v0282;
    v0282 = stack[-3];
    v0282 = qcdr(v0282);
    stack[-3] = v0282;
    v0282 = stack[-3];
    if (v0282 == nil) goto v0065;
    else goto v0295;

v0298:
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    stack[0] = qcar(v0282);
    v0284 = elt(env, 11); /* times */
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = stack[-3];
    v0282 = qcar(v0282);
    v0282 = qcar(v0282);
    v0282 = qcdr(v0282);
    v0282 = list3(v0284, v0283, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    v0282 = list2(stack[0], v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    fn = elt(env, 19); /* simpexpt */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0287;
    env = stack[-9];
    stack[-5] = v0282;
    goto v0299;

v0296:
    v0282 = stack[-8];
    v0282 = qcdr(v0282);
    v0283 = qcar(v0282);
    v0282 = elt(env, 4); /* expt */
    v0282 = Leqcar(nil, v0283, v0282);
    env = stack[-9];
    v0282 = (v0282 == nil ? lisp_true : nil);
    goto v0297;

v0293:
    v0282 = qvalue(elt(env, 2)); /* nil */
    goto v0294;

v0084:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0071;

v0077:
    v0282 = qvalue(elt(env, 1)); /* t */
    goto v0177;
/* error exit handlers */
v0290:
    env = stack[-9];
    qvalue(elt(env, 7)) = stack[0]; /* dmode!* */
    qvalue(elt(env, 6)) = stack[-1]; /* alglist!* */
    popv(10);
    return nil;
v0287:
    popv(10);
    return nil;
}



/* Code for ibalp_commonlenisone */

static Lisp_Object CC_ibalp_commonlenisone(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_commonlenisone");
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
    v0090 = stack[-1];
    if (v0090 == nil) goto v0077;
    v0090 = qvalue(elt(env, 1)); /* nil */
    goto v0177;

v0177:
    if (!(v0090 == nil)) { popv(3); return onevalue(v0090); }
    v0090 = stack[0];
    if (v0090 == nil) goto v0056;
    v0090 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0090); }

v0056:
    v0090 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* ibalp_lenisone */
        return (*qfn1(fn))(qenv(fn), v0090);
    }

v0077:
    v0090 = stack[0];
    fn = elt(env, 2); /* ibalp_lenisone */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-2];
    goto v0177;
/* error exit handlers */
v0111:
    popv(3);
    return nil;
}



/* Code for mathml */

static Lisp_Object MS_CDECL CC_mathml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 2); /* lex */
    v0177 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0077;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0077:
    popv(1);
    return nil;
}



/* Code for off_mod_reval */

static Lisp_Object CC_off_mod_reval(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off_mod_reval");
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
    v0070 = qvalue(elt(env, 1)); /* !*modular */
    if (v0070 == nil) goto v0056;
    v0070 = elt(env, 2); /* modular */
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    fn = elt(env, 4); /* off */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    v0070 = stack[0];
    fn = elt(env, 5); /* reval */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    stack[0] = v0070;
    v0070 = elt(env, 2); /* modular */
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    fn = elt(env, 6); /* on */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0056:
    v0070 = stack[0];
    fn = elt(env, 5); /* reval */
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    stack[0] = v0070;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0081;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mknwedge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0000;
/* end of prologue */
    v0078 = v0081;
    v0078 = qcdr(v0078);
    if (v0078 == nil) goto v0054;
    v0078 = elt(env, 1); /* wedge */
    return cons(v0078, v0081);

v0054:
    v0078 = v0081;
    v0078 = qcar(v0078);
    return onevalue(v0078);
}



/* Code for boundindp */

static Lisp_Object CC_boundindp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0091, v0092, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boundindp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0093 = v0001;
    v0092 = v0000;
/* end of prologue */

v0038:
    v0030 = v0092;
    if (v0030 == nil) goto v0077;
    v0030 = v0092;
    v0091 = qcar(v0030);
    v0030 = v0093;
    v0030 = Lmember(nil, v0091, v0030);
    if (v0030 == nil) goto v0111;
    v0030 = v0092;
    v0030 = qcdr(v0030);
    v0092 = v0030;
    goto v0038;

v0111:
    v0030 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0030);

v0077:
    v0030 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0030);
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-set");
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
    push(nil);
/* copy arguments values to proper place */
    v0055 = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* list */
    v0056 = v0055;
    v0055 = elt(env, 2); /* set!-ordp */
    fn = elt(env, 3); /* sort */
    v0055 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    {
        Lisp_Object v0081 = stack[0];
        popv(1);
        return cons(v0081, v0055);
    }
/* error exit handlers */
v0078:
    popv(1);
    return nil;
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxdeg");
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

v0087:
    v0093 = stack[-1];
    if (v0093 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    v0065 = qcdr(v0093);
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = (Lisp_Object)greaterp2(v0065, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    v0093 = v0093 ? lisp_true : nil;
    env = stack[-2];
    if (v0093 == nil) goto v0029;
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    v0065 = v0093;
    v0093 = stack[-1];
    v0093 = qcar(v0093);
    stack[0] = v0093;
    v0093 = v0065;
    stack[-1] = v0093;
    goto v0087;

v0029:
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    stack[-1] = v0093;
    goto v0087;
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for lpri */

static Lisp_Object CC_lpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpri");
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

v0060:
    v0056 = stack[0];
    if (v0056 == nil) goto v0177;
    v0056 = stack[0];
    v0056 = qcar(v0056);
    v0056 = Lprinc(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0056 = elt(env, 2); /* " " */
    v0056 = Lprinc(nil, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-1];
    v0056 = stack[0];
    v0056 = qcdr(v0056);
    stack[0] = v0056;
    goto v0060;

v0177:
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0056); }
/* error exit handlers */
v0078:
    popv(2);
    return nil;
}



/* Code for red!-weight */

static Lisp_Object CC_redKweight(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0078;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight");
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
    v0057 = stack[-1];
    fn = elt(env, 1); /* nonzero!-length */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0078 = stack[-1];
    v0057 = stack[0];
    fn = elt(env, 2); /* red!-weight1 */
    v0057 = (*qfn2(fn))(qenv(fn), v0078, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    {
        Lisp_Object v0082 = stack[-2];
        popv(4);
        return cons(v0082, v0057);
    }
/* error exit handlers */
v0068:
    popv(4);
    return nil;
}



/* Code for bc!=simp */

static Lisp_Object CC_bcMsimp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0300, v0301;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc=simp");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0000;
/* end of prologue */
    v0301 = elt(env, 1); /* cali */
    v0300 = elt(env, 2); /* rules */
    v0300 = get(v0301, v0300);
    env = stack[-5];
    stack[-4] = v0300;
    v0300 = stack[-4];
    if (v0300 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0300 = (Lisp_Object)1; /* 0 */
    stack[0] = v0300;
    v0300 = stack[-4];
    stack[-2] = v0300;
    goto v0090;

v0090:
    v0300 = stack[-2];
    if (v0300 == nil) goto v0302;
    v0301 = stack[0];
    v0300 = (Lisp_Object)16001; /* 1000 */
    v0300 = (Lisp_Object)lessp2(v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0300 = v0300 ? lisp_true : nil;
    env = stack[-5];
    if (v0300 == nil) goto v0302;
    v0301 = stack[-3];
    v0300 = stack[-2];
    v0300 = qcar(v0300);
    v0300 = qcar(v0300);
    fn = elt(env, 6); /* qremf */
    v0300 = (*qfn2(fn))(qenv(fn), v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[-1] = v0300;
    v0300 = stack[-1];
    v0300 = qcar(v0300);
    if (v0300 == nil) goto v0028;
    v0300 = stack[-1];
    v0301 = qcar(v0300);
    v0300 = stack[-2];
    v0300 = qcar(v0300);
    v0300 = qcdr(v0300);
    fn = elt(env, 7); /* multf */
    v0301 = (*qfn2(fn))(qenv(fn), v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    v0300 = stack[-1];
    v0300 = qcdr(v0300);
    fn = elt(env, 8); /* addf */
    v0300 = (*qfn2(fn))(qenv(fn), v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[-3] = v0300;
    v0300 = stack[0];
    v0300 = add1(v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    stack[0] = v0300;
    v0300 = stack[-4];
    stack[-2] = v0300;
    goto v0090;

v0028:
    v0300 = stack[-2];
    v0300 = qcdr(v0300);
    stack[-2] = v0300;
    goto v0090;

v0302:
    v0301 = stack[0];
    v0300 = (Lisp_Object)16001; /* 1000 */
    v0300 = (Lisp_Object)lessp2(v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0300 = v0300 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0300 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0300 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v0300 == nil)) goto v0281;
    v0300 = elt(env, 5); /* "recursion depth of bc!=simp too high" */
    fn = elt(env, 9); /* lprie */
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-5];
    goto v0281;

v0281:
    v0300 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    v0300 = nil;
    { popv(6); return onevalue(v0300); }
/* error exit handlers */
v0178:
    popv(6);
    return nil;
}



/* Code for pv_add */

static Lisp_Object CC_pv_add(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0171, v0172;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_add");
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
    v0045 = stack[-1];
    if (v0045 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0045 = stack[0];
    if (v0045 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v0081;

v0081:
    v0045 = stack[-1];
    if (!(v0045 == nil)) goto v0070;
    v0045 = stack[0];
    if (!(v0045 == nil)) goto v0070;
    v0045 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0045);

v0070:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0092;
    v0045 = stack[0];
    if (v0045 == nil) goto v0092;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    v0171 = qcdr(v0045);
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = qcdr(v0045);
    if (!(equal(v0171, v0045))) goto v0092;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    v0171 = qcar(v0045);
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = qcar(v0045);
    v0045 = plus2(v0171, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    v0172 = v0045;
    v0171 = v0172;
    v0045 = (Lisp_Object)1; /* 0 */
    if (v0171 == v0045) goto v0044;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    v0171 = qcdr(v0045);
    v0045 = stack[-2];
    v0045 = acons(v0172, v0171, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    stack[-2] = v0045;
    goto v0044;

v0044:
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    stack[0] = v0045;
    goto v0081;

v0092:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0058;
    v0045 = stack[0];
    if (!(v0045 == nil)) goto v0058;

v0106:
    v0045 = stack[-1];
    v0171 = qcar(v0045);
    v0045 = stack[-2];
    v0045 = cons(v0171, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    stack[-2] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0081;

v0058:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0219;
    v0045 = stack[0];
    if (v0045 == nil) goto v0219;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    v0171 = qcdr(v0045);
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = qcdr(v0045);
    v0045 = (Lisp_Object)greaterp2(v0171, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    v0045 = v0045 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0045 == nil)) goto v0106;

v0219:
    v0045 = stack[0];
    v0171 = qcar(v0045);
    v0045 = stack[-2];
    v0045 = cons(v0171, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0303;
    env = stack[-3];
    stack[-2] = v0045;
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    stack[0] = v0045;
    goto v0081;
/* error exit handlers */
v0303:
    popv(4);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_kern");
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
    push(nil);
/* copy arguments values to proper place */
    v0052 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v0052 = sub1(v0052);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    v0052 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0052/(16/CELL)));
    v0052 = qcdr(v0052);
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    { popv(1); return onevalue(v0052); }
/* error exit handlers */
v0054:
    popv(1);
    return nil;
}



/* Code for arzerop!: */

static Lisp_Object CC_arzeropT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arzerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0038 = v0000;
/* end of prologue */
    v0038 = qcdr(v0038);
    v0038 = (v0038 == nil ? lisp_true : nil);
    return onevalue(v0038);
}



/* Code for noncomdel */

static Lisp_Object CC_noncomdel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomdel");
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
    v0108 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0108 == nil) goto v0057;
    v0108 = stack[-1];
    fn = elt(env, 4); /* noncomp1 */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    if (!(v0108 == nil)) goto v0072;

v0057:
    v0119 = stack[-1];
    v0108 = elt(env, 2); /* expt */
    if (!consp(v0119)) goto v0088;
    v0119 = qcar(v0119);
    if (!(v0119 == v0108)) goto v0088;
    v0108 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0108 == nil) goto v0098;
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    fn = elt(env, 4); /* noncomp1 */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-2];
    goto v0053;

v0053:
    if (!(v0108 == nil)) goto v0072;
    v0119 = stack[-1];
    v0108 = stack[0];
        popv(3);
        return Ldelete(nil, v0119, v0108);

v0072:
    v0119 = stack[-1];
    v0108 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* noncomdel1 */
        return (*qfn2(fn))(qenv(fn), v0119, v0108);
    }

v0098:
    v0108 = qvalue(elt(env, 3)); /* nil */
    goto v0053;

v0088:
    v0108 = qvalue(elt(env, 3)); /* nil */
    goto v0053;
/* error exit handlers */
v0086:
    popv(3);
    return nil;
}



/* Code for frvarsof */

static Lisp_Object CC_frvarsof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0203, v0086, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frvarsof");
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
    v0203 = v0001;
    v0086 = v0000;
/* end of prologue */

v0034:
    v0016 = v0086;
    v0202 = qvalue(elt(env, 1)); /* frlis!* */
    v0202 = Lmemq(nil, v0016, v0202);
    if (v0202 == nil) goto v0080;
    v0016 = v0086;
    v0202 = v0203;
    v0202 = Lmemq(nil, v0016, v0202);
    if (!(v0202 == nil)) { popv(2); return onevalue(v0203); }
    stack[0] = v0203;
    v0202 = v0086;
    v0202 = ncons(v0202);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    {
        Lisp_Object v0198 = stack[0];
        popv(2);
        return Lappend(nil, v0198, v0202);
    }

v0080:
    v0202 = v0086;
    if (!consp(v0202)) { popv(2); return onevalue(v0203); }
    v0202 = v0086;
    v0202 = qcdr(v0202);
    stack[0] = v0202;
    v0202 = v0086;
    v0202 = qcar(v0202);
    v0202 = CC_frvarsof(env, v0202, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-1];
    v0203 = v0202;
    v0202 = stack[0];
    v0086 = v0202;
    goto v0034;
/* error exit handlers */
v0197:
    popv(2);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0031, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3q");
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
    v0033 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v0033;
    v0033 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0033; /* mchfg!* */
    v0033 = stack[-1];
    v0109 = qcar(v0033);
    v0031 = qvalue(elt(env, 3)); /* !*match */
    v0033 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0109, v0031, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0033 = stack[-1];
    v0109 = qcdr(v0033);
    v0031 = qvalue(elt(env, 3)); /* !*match */
    v0033 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    v0033 = (*qfnn(fn))(qenv(fn), 3, v0109, v0031, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    fn = elt(env, 6); /* invsq */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v0033 = (*qfn2(fn))(qenv(fn), stack[0], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-1] = v0033;
    v0033 = stack[-2];
    qvalue(elt(env, 1)) = v0033; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for tayexp!-difference */

static Lisp_Object CC_tayexpKdifference(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0215, v0188, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-difference");
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
    v0215 = v0000;
/* end of prologue */
    v0188 = v0215;
    if (!consp(v0188)) goto v0067;
    v0188 = qvalue(elt(env, 1)); /* nil */
    goto v0077;

v0077:
    if (v0188 == nil) goto v0082;
    v0188 = v0215;
    v0215 = stack[0];
    popv(3);
    return difference2(v0188, v0215);

v0082:
    v0188 = v0215;
    if (!consp(v0188)) goto v0032;
    v0188 = stack[0];
    if (!consp(v0188)) goto v0073;
    v0188 = v0215;
    v0215 = stack[0];
    fn = elt(env, 3); /* rndifference!: */
    v0215 = (*qfn2(fn))(qenv(fn), v0188, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    goto v0098;

v0098:
    v0107 = v0215;
    v0215 = v0107;
    v0215 = qcdr(v0215);
    v0188 = qcdr(v0215);
    v0215 = (Lisp_Object)17; /* 1 */
    if (!(v0188 == v0215)) { popv(3); return onevalue(v0107); }
    v0215 = v0107;
    v0215 = qcdr(v0215);
    v0215 = qcar(v0215);
    { popv(3); return onevalue(v0215); }

v0073:
    stack[-1] = v0215;
    v0107 = elt(env, 2); /* !:rn!: */
    v0188 = stack[0];
    v0215 = (Lisp_Object)17; /* 1 */
    v0215 = list2star(v0107, v0188, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    fn = elt(env, 3); /* rndifference!: */
    v0215 = (*qfn2(fn))(qenv(fn), stack[-1], v0215);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    goto v0098;

v0032:
    v0107 = elt(env, 2); /* !:rn!: */
    v0188 = v0215;
    v0215 = (Lisp_Object)17; /* 1 */
    v0188 = list2star(v0107, v0188, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-2];
    v0215 = stack[0];
    fn = elt(env, 3); /* rndifference!: */
    v0215 = (*qfn2(fn))(qenv(fn), v0188, v0215);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    goto v0098;

v0067:
    v0188 = stack[0];
    v0188 = (consp(v0188) ? nil : lisp_true);
    goto v0077;
/* error exit handlers */
v0020:
    popv(3);
    return nil;
}



/* Code for rl_prepat */

static Lisp_Object CC_rl_prepat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepat");
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
    v0034 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_prepat!* */
    v0034 = ncons(v0034);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-1];
    {
        Lisp_Object v0052 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0052, v0034);
    }
/* error exit handlers */
v0039:
    popv(2);
    return nil;
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0092, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simplat");
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
    v0092 = v0001;
    v0093 = v0000;
/* end of prologue */
    v0091 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v0091 == nil) goto v0067;
    v0091 = v0093;
    fn = elt(env, 3); /* rl_simplat1 */
    v0092 = (*qfn2(fn))(qenv(fn), v0091, v0092);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[0];
    v0091 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v0092, v0091);
    }

v0067:
    v0091 = v0093;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v0091, v0092);
    }
/* error exit handlers */
v0065:
    popv(1);
    return nil;
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0073;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0073 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    v0073 = plus2(v0073, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0075 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v0073, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0073 = qcar(v0075);
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcdr(v0075);
    v0075 = qcar(v0075);
    v0075 = times2(v0073, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    {
        Lisp_Object v0085 = stack[-1];
        popv(3);
        return plus2(v0085, v0075);
    }
/* error exit handlers */
v0084:
    popv(3);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0300, v0301, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizei");
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
    v0300 = stack[-1];
    v0300 = qcdr(v0300);
    stack[-2] = v0300;
    v0301 = v0300;
    v0300 = v0301;
    if (!consp(v0300)) goto v0054;
    v0300 = v0301;
    v0300 = qcar(v0300);
    v0300 = (consp(v0300) ? nil : lisp_true);
    goto v0053;

v0053:
    if (!(v0300 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0301 = elt(env, 2); /* i */
    v0300 = stack[-2];
    v0300 = Lsmemq(nil, v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    if (v0300 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0301 = elt(env, 2); /* i */
    v0300 = qvalue(elt(env, 3)); /* kord!* */
    v0300 = cons(v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 3)); /* kord!* */
    qvalue(elt(env, 3)) = v0300; /* kord!* */
    v0300 = stack[-1];
    v0300 = qcar(v0300);
    fn = elt(env, 6); /* reorder */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0300 = stack[-1];
    v0300 = qcdr(v0300);
    fn = elt(env, 6); /* reorder */
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0300 = cons(stack[-2], v0300);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    stack[-2] = v0300;
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    v0300 = stack[-2];
    v0300 = qcdr(v0300);
    stack[0] = v0300;
    v0300 = qcar(v0300);
    v0301 = qcar(v0300);
    v0300 = elt(env, 4); /* (i . 1) */
    if (equal(v0301, v0300)) goto v0203;
    v0300 = qvalue(elt(env, 5)); /* nil */
    goto v0202;

v0202:
    if (v0300 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0014 = elt(env, 2); /* i */
    v0301 = (Lisp_Object)17; /* 1 */
    v0300 = (Lisp_Object)17; /* 1 */
    v0300 = acons(v0014, v0301, v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    stack[-1] = ncons(v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0300 = stack[-2];
    v0300 = qcar(v0300);
    fn = elt(env, 6); /* reorder */
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    fn = elt(env, 7); /* multf */
    v0300 = (*qfn2(fn))(qenv(fn), stack[-1], v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    fn = elt(env, 8); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0300 = stack[0];
    v0300 = qcar(v0300);
    v0300 = qcdr(v0300);
    fn = elt(env, 6); /* reorder */
    v0300 = (*qfn1(fn))(qenv(fn), v0300);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    {
        Lisp_Object v0179 = stack[-1];
        popv(4);
        return cons(v0179, v0300);
    }

v0203:
    v0300 = stack[0];
    v0300 = qcdr(v0300);
    v0300 = (v0300 == nil ? lisp_true : nil);
    goto v0202;

v0054:
    v0300 = qvalue(elt(env, 1)); /* t */
    goto v0053;
/* error exit handlers */
v0178:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v0015:
    popv(4);
    return nil;
}



/* Code for retimes1 */

static Lisp_Object CC_retimes1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for retimes1");
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
    stack[-1] = nil;
    goto v0038;

v0038:
    v0217 = stack[0];
    if (v0217 == nil) goto v0077;
    v0217 = stack[0];
    v0105 = qcar(v0217);
    v0217 = (Lisp_Object)17; /* 1 */
    if (v0105 == v0217) goto v0039;
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0217 = Lminusp(nil, v0217);
    env = stack[-2];
    if (v0217 == nil) goto v0090;
    v0217 = qvalue(elt(env, 1)); /* !*bool */
    v0217 = (v0217 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0217; /* !*bool */
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0105 = negate(v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    v0217 = cons(v0105, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    stack[0] = v0217;
    goto v0038;

v0090:
    v0217 = stack[0];
    v0217 = qcar(v0217);
    if (!consp(v0217)) goto v0074;
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0105 = qcar(v0217);
    v0217 = elt(env, 2); /* minus */
    if (v0105 == v0217) goto v0085;
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0105 = qcar(v0217);
    v0217 = elt(env, 3); /* times */
    if (v0105 == v0217) goto v0058;
    v0217 = stack[0];
    v0105 = qcar(v0217);
    v0217 = stack[-1];
    v0217 = cons(v0105, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    stack[-1] = v0217;
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    stack[0] = v0217;
    goto v0038;

v0058:
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0105 = qcdr(v0217);
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    v0217 = Lappend(nil, v0105, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    stack[0] = v0217;
    goto v0038;

v0085:
    v0217 = qvalue(elt(env, 1)); /* !*bool */
    v0217 = (v0217 == nil ? lisp_true : nil);
    qvalue(elt(env, 1)) = v0217; /* !*bool */
    v0217 = stack[0];
    v0217 = qcar(v0217);
    v0217 = qcdr(v0217);
    v0105 = qcar(v0217);
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    v0217 = cons(v0105, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    stack[0] = v0217;
    goto v0038;

v0074:
    v0217 = stack[0];
    v0105 = qcar(v0217);
    v0217 = stack[-1];
    v0217 = cons(v0105, v0217);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-2];
    stack[-1] = v0217;
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    stack[0] = v0217;
    goto v0038;

v0039:
    v0217 = stack[0];
    v0217 = qcdr(v0217);
    stack[0] = v0217;
    goto v0038;

v0077:
    v0217 = stack[-1];
    {
        popv(3);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0217);
    }
/* error exit handlers */
v0178:
    popv(3);
    return nil;
}



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for areallindices");
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

v0208:
    v0068 = stack[0];
    v0068 = qcar(v0068);
    fn = elt(env, 3); /* isanindex */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    if (v0068 == nil) goto v0060;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    if (v0068 == nil) goto v0052;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0208;

v0052:
    v0068 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0068); }

v0060:
    v0068 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0068); }
/* error exit handlers */
v0090:
    popv(2);
    return nil;
}



setup_type const u05_setup[] =
{
    {"times-term-mod-p",        too_few_2,      CC_timesKtermKmodKp,wrong_no_2},
    {"procstat",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_procstat},
    {"cl_varl1",                CC_cl_varl1,    too_many_1,    wrong_no_1},
    {"subs2",                   CC_subs2,       too_many_1,    wrong_no_1},
    {"ibalp_getupl",            CC_ibalp_getupl,too_many_1,    wrong_no_1},
    {"ev_comp",                 too_few_2,      CC_ev_comp,    wrong_no_2},
    {"ps:evaluate",             too_few_2,      CC_psTevaluate,wrong_no_2},
    {"pnthxzz",                 too_few_2,      CC_pnthxzz,    wrong_no_2},
    {"csl_timbf",               too_few_2,      CC_csl_timbf,  wrong_no_2},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"fs:timestermterm",        too_few_2,      CC_fsTtimestermterm,wrong_no_2},
    {"mo_sum",                  too_few_2,      CC_mo_sum,     wrong_no_2},
    {"gcdf*",                   too_few_2,      CC_gcdfH,      wrong_no_2},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"mkrn",                    too_few_2,      CC_mkrn,       wrong_no_2},
    {"divide:",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_divideT},
    {"c:ordexp",                too_few_2,      CC_cTordexp,   wrong_no_2},
    {"*i2gi",                   CC_Hi2gi,       too_many_1,    wrong_no_1},
    {"xread",                   CC_xread,       too_many_1,    wrong_no_1},
    {"mcharg",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg},
    {"ibalp_minclnr",           CC_ibalp_minclnr,too_many_1,   wrong_no_1},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"xdegree",                 CC_xdegree,     too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {"delallasc",               too_few_2,      CC_delallasc,  wrong_no_2},
    {"getphystype*sq",          CC_getphystypeHsq,too_many_1,  wrong_no_1},
    {"argnochk",                CC_argnochk,    too_many_1,    wrong_no_1},
    {"simpminus",               CC_simpminus,   too_many_1,    wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"pv_renorm",               CC_pv_renorm,   too_many_1,    wrong_no_1},
    {"dv_skelhead",             CC_dv_skelhead, too_many_1,    wrong_no_1},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"subs2f1",                 CC_subs2f1,     too_many_1,    wrong_no_1},
    {"ibalp_commonlenisone",    too_few_2,      CC_ibalp_commonlenisone,wrong_no_2},
    {"mathml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml},
    {"off_mod_reval",           CC_off_mod_reval,too_many_1,   wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"boundindp",               too_few_2,      CC_boundindp,  wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"lpri",                    CC_lpri,        too_many_1,    wrong_no_1},
    {"red-weight",              too_few_2,      CC_redKweight, wrong_no_2},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"pv_add",                  too_few_2,      CC_pv_add,     wrong_no_2},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"arzerop:",                CC_arzeropT,    too_many_1,    wrong_no_1},
    {"noncomdel",               too_few_2,      CC_noncomdel,  wrong_no_2},
    {"frvarsof",                too_few_2,      CC_frvarsof,   wrong_no_2},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"rl_prepat",               CC_rl_prepat,   too_many_1,    wrong_no_1},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"retimes1",                CC_retimes1,    too_many_1,    wrong_no_1},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u05", (two_args *)"3525 7327379 8462480", 0}
};

/* end of generated code */
