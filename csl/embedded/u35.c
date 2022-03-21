
/* $destdir\u35.c        Machine generated C code */

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


/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0237, v0238, v0239, v0240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-3] = nil;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    stack[-6] = v0236;
    v0236 = stack[-5];
    v0236 = qcar(v0236);
    stack[-5] = v0236;
    v0237 = stack[-6];
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = (Lisp_Object)greaterp2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    v0236 = v0236 ? lisp_true : nil;
    env = stack[-7];
    if (v0236 == nil) goto v0242;
    v0236 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v0236 == nil) goto v0242;
    v0236 = stack[-5];
    fn = elt(env, 24); /* noncomp1 */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0242;
    v0237 = stack[-5];
    v0236 = stack[-4];
    v0236 = list2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 25); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[0] = stack[-5];
    v0236 = stack[-6];
    v0236 = sub1(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = list2(stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 26); /* simpexpt */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 27); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0238 = stack[-5];
    v0237 = (Lisp_Object)17; /* 1 */
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = acons(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0237 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-2] = stack[-5];
    v0236 = stack[-6];
    v0236 = sub1(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0237 = cons(stack[-2], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-4];
    v0236 = CC_diffp(env, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 27); /* multsq */
    v0236 = (*qfn2(fn))(qenv(fn), stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    {
        Lisp_Object v0243 = stack[-1];
        popv(8);
        fn = elt(env, 28); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0243, v0236);
    }

v0242:
    v0237 = stack[-5];
    v0236 = stack[-4];
    if (v0237 == v0236) goto v0244;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0245;

v0245:
    if (!(v0236 == nil)) goto v0246;
    v0236 = stack[-5];
    if (!consp(v0236)) goto v0247;
    v0236 = stack[-5];
    v0236 = qcar(v0236);
    if (!consp(v0236)) goto v0248;
    v0237 = stack[-5];
    v0236 = stack[-4];
    fn = elt(env, 29); /* difff */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0249;

v0249:
    if (!(v0236 == nil)) goto v0246;
    v0236 = stack[-5];
    v0237 = qcar(v0236);
    v0236 = elt(env, 3); /* !*sq */
    if (v0237 == v0236) goto v0250;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0251;

v0251:
    if (!(v0236 == nil)) goto v0246;
    v0236 = stack[-5];
    v0237 = qcar(v0236);
    v0236 = elt(env, 4); /* dfform */
    v0236 = get(v0237, v0236);
    env = stack[-7];
    stack[-2] = v0236;
    if (v0236 == nil) goto v0252;
    v0239 = stack[-2];
    v0238 = stack[-5];
    v0237 = stack[-4];
    v0236 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v0239, v0238, v0237, v0236);

v0252:
    v0236 = stack[-5];
    stack[0] = qcar(v0236);
    v0236 = stack[-5];
    fn = elt(env, 30); /* dfn_prop */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = get(stack[0], v0236);
    env = stack[-7];
    stack[-2] = v0236;
    if (v0236 == nil) goto v0253;
    v0236 = stack[-2];
    stack[-1] = v0236;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    stack[0] = v0236;
    goto v0254;

v0254:
    v0236 = stack[0];
    v0236 = qcar(v0236);
    fn = elt(env, 31); /* simp */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-4];
    fn = elt(env, 32); /* diffsq */
    v0237 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-3];
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    v0236 = stack[-3];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    if (v0236 == nil) goto v0255;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    if (!(v0236 == nil)) goto v0255;

v0256:
    v0236 = stack[-5];
    v0237 = qcar(v0236);
    v0236 = elt(env, 16); /* df */
    if (v0237 == v0236) goto v0257;
    v0238 = elt(env, 16); /* df */
    v0237 = stack[-5];
    v0236 = stack[-4];
    v0236 = list3(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0258;

v0258:
    v0236 = stack[-3];
    fn = elt(env, 33); /* opmtch */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-2] = v0236;
    if (v0236 == nil) goto v0259;
    v0236 = stack[-2];
    fn = elt(env, 31); /* simp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0246:
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 6)); /* wtl!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0260;
    stack[0] = elt(env, 7); /* k!* */
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0237 = negate(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = acons(stack[0], v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0237 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (Lisp_Object)17; /* 1 */
    v0237 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-3];
    fn = elt(env, 27); /* multsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0260;

v0260:
    v0236 = stack[-6];
    v0236 = sub1(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[0] = v0236;
    v0237 = stack[-6];
    v0236 = (Lisp_Object)17; /* 1 */
    if (v0237 == v0236) goto v0261;
    v0237 = qvalue(elt(env, 8)); /* dmode!* */
    v0236 = elt(env, 9); /* convert */
    v0236 = Lflagp(nil, v0237, v0236);
    env = stack[-7];
    if (v0236 == nil) goto v0262;
    v0237 = qvalue(elt(env, 8)); /* dmode!* */
    v0236 = elt(env, 10); /* i2d */
    v0237 = get(v0237, v0236);
    env = stack[-7];
    v0236 = stack[-6];
    v0236 = Lapply1(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 34); /* int!-equiv!-chk */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-6] = v0236;
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0263;

v0263:
    if (v0236 == nil) goto v0264;
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0265;

v0265:
    {
        popv(8);
        fn = elt(env, 35); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v0236);
    }

v0264:
    v0238 = stack[-5];
    v0237 = stack[0];
    v0236 = stack[-6];
    v0236 = acons(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0237 = ncons(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (Lisp_Object)17; /* 1 */
    v0237 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-3];
    fn = elt(env, 27); /* multsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0265;

v0262:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0263;

v0261:
    v0236 = stack[-3];
    goto v0265;

v0259:
    v0237 = stack[-5];
    v0236 = stack[-4];
    fn = elt(env, 36); /* depends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0266;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0267;

v0267:
    if (v0236 == nil) goto v0268;
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0237, v0236);

v0268:
    v0236 = qvalue(elt(env, 14)); /* !*expanddf */
    if (v0236 == nil) goto v0269;
    v0236 = stack[-5];
    if (!consp(v0236)) goto v0270;
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    if (v0236 == nil) goto v0271;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0272;

v0272:
    if (v0236 == nil) goto v0269;
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 15)); /* depl!* */
    v0236 = Lassoc(nil, v0237, v0236);
    stack[-2] = v0236;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    if (v0236 == nil) goto v0273;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    fn = elt(env, 37); /* get!-all!-kernels */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0274;

v0274:
    stack[-1] = v0236;
    v0236 = stack[-2];
    if (v0236 == nil) goto v0275;
    v0236 = stack[-1];
    if (v0236 == nil) goto v0275;
    v0237 = stack[-4];
    v0236 = stack[-1];
    v0237 = Ldelete(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-4];
    fn = elt(env, 38); /* ldepends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0275;
    v0240 = elt(env, 23); /* "Possible inconsistent dependencies in" */
    v0239 = stack[-5];
    v0238 = qvalue(elt(env, 2)); /* nil */
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 39); /* msgpri */
    v0236 = (*qfnn(fn))(qenv(fn), 5, v0240, v0239, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0275:
    v0236 = stack[-2];
    if (v0236 == nil) goto v0276;
    v0237 = stack[-4];
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    stack[-2] = v0236;
    v0236 = Lmemq(nil, v0237, v0236);
    if (v0236 == nil) goto v0277;
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0277:
    v0238 = stack[-5];
    v0237 = stack[-4];
    v0236 = stack[-2];
    fn = elt(env, 41); /* df!-chain!-rule */
    v0236 = (*qfnn(fn))(qenv(fn), 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0276:
    v0236 = stack[-1];
    if (v0236 == nil) goto v0278;
    v0237 = stack[-4];
    v0236 = stack[-1];
    fn = elt(env, 42); /* smember */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0279;
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0280;

v0280:
    stack[-3] = v0236;
    goto v0246;

v0279:
    v0238 = stack[-5];
    v0237 = stack[-4];
    v0236 = stack[-1];
    fn = elt(env, 41); /* df!-chain!-rule */
    v0236 = (*qfnn(fn))(qenv(fn), 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0280;

v0278:
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0273:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0274;

v0269:
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0271:
    v0236 = stack[-5];
    v0237 = qcar(v0236);
    v0236 = elt(env, 22); /* (df int) */
    v0236 = Lmemq(nil, v0237, v0236);
    if (v0236 == nil) goto v0281;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0272;

v0281:
    v0237 = stack[-4];
    v0236 = stack[-5];
    fn = elt(env, 42); /* smember */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0282;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0272;

v0282:
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 11)); /* powlis!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0283;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    fn = elt(env, 36); /* depends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0272;

v0283:
    v0236 = qvalue(elt(env, 12)); /* t */
    goto v0272;

v0270:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0272;

v0266:
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    stack[-5] = v0237;
    v0236 = qvalue(elt(env, 11)); /* powlis!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0284;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    fn = elt(env, 43); /* dependsl */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0285;

v0285:
    if (v0236 == nil) goto v0286;
    v0236 = qvalue(elt(env, 13)); /* !*depend */
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0267;

v0286:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0267;

v0284:
    v0236 = qvalue(elt(env, 12)); /* t */
    goto v0285;

v0257:
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    if (v0237 == v0236) goto v0287;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = elt(env, 19); /* int */
    if (!consp(v0237)) goto v0288;
    v0237 = qcar(v0237);
    if (!(v0237 == v0236)) goto v0288;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    if (v0237 == v0236) goto v0289;
    v0236 = qvalue(elt(env, 20)); /* !*allowdfint */
    if (v0236 == nil) goto v0288;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    fn = elt(env, 44); /* simp!* */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-4];
    fn = elt(env, 32); /* diffsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    fn = elt(env, 45); /* not_df_p */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0288;
    stack[-1] = elt(env, 16); /* df */
    stack[0] = elt(env, 19); /* int */
    v0236 = stack[-3];
    fn = elt(env, 46); /* mk!*sq */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = list3(stack[0], v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 47); /* reval */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = list2star(stack[-1], v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0258;

v0288:
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    stack[0] = qcar(v0236);
    v0237 = stack[-5];
    v0236 = stack[-4];
    fn = elt(env, 48); /* merge!-ind!-vars */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0238 = cons(stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0238;
    v0237 = elt(env, 16); /* df */
    v0236 = elt(env, 21); /* kvalue */
    v0236 = get(v0237, v0236);
    env = stack[-7];
    fn = elt(env, 49); /* find_sub_df */
    v0236 = (*qfn2(fn))(qenv(fn), v0238, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-2] = v0236;
    if (v0236 == nil) goto v0290;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    fn = elt(env, 31); /* simp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    stack[-2] = v0236;
    goto v0291;

v0291:
    v0236 = stack[-2];
    if (v0236 == nil) goto v0246;
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    stack[-1] = v0236;
    v0236 = (Lisp_Object)17; /* 1 */
    stack[0] = v0236;
    goto v0292;

v0292:
    v0236 = stack[-1];
    v0237 = qcdr(v0236);
    v0236 = stack[0];
    v0236 = difference2(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = Lminusp(nil, v0236);
    env = stack[-7];
    if (v0236 == nil) goto v0293;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    stack[-2] = v0236;
    goto v0291;

v0293:
    v0237 = stack[-3];
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    fn = elt(env, 32); /* diffsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    v0236 = stack[0];
    v0236 = add1(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[0] = v0236;
    goto v0292;

v0290:
    v0237 = elt(env, 16); /* df */
    v0236 = stack[-3];
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0258;

v0289:
    v0238 = elt(env, 16); /* df */
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = list2star(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0258;

v0287:
    v0236 = qvalue(elt(env, 17)); /* !*commutedf */
    if (v0236 == nil) goto v0294;
    v0236 = qvalue(elt(env, 13)); /* !*depend */
    if (!(v0236 == nil)) goto v0294;
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0237, v0236);

v0294:
    v0236 = qvalue(elt(env, 18)); /* !*simpnoncomdf */
    if (v0236 == nil) goto v0288;
    v0237 = stack[-4];
    v0236 = qvalue(elt(env, 15)); /* depl!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-3] = v0236;
    if (v0236 == nil) goto v0288;
    v0236 = stack[-3];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    if (!(v0236 == nil)) goto v0288;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcar(v0236);
    stack[-2] = v0236;
    v0238 = elt(env, 16); /* df */
    v0237 = stack[-5];
    v0236 = stack[-2];
    v0236 = list3(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 31); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0238 = elt(env, 16); /* df */
    v0237 = stack[-4];
    v0236 = stack[-2];
    v0236 = list3(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 31); /* simp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 50); /* invsq */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 27); /* multsq */
    v0236 = (*qfn2(fn))(qenv(fn), stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0255:
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    v0236 = stack[0];
    v0236 = qcdr(v0236);
    stack[0] = v0236;
    v0236 = stack[0];
    if (v0236 == nil) goto v0295;
    v0236 = stack[-1];
    if (!(v0236 == nil)) goto v0254;

v0295:
    v0236 = stack[0];
    if (!(v0236 == nil)) goto v0256;
    v0236 = stack[-1];
    if (!(v0236 == nil)) goto v0256;
    v0236 = stack[-3];
    v0236 = Lreverse(nil, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-1] = v0236;
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    stack[0] = v0236;
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0296;

v0296:
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    if (v0236 == nil) goto v0297;
    v0236 = stack[-1];
    stack[-4] = qcar(v0236);
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[0];
    fn = elt(env, 51); /* pair */
    v0237 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-2];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    v0236 = Lsubla(nil, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 31); /* simp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    fn = elt(env, 27); /* multsq */
    v0237 = (*qfn2(fn))(qenv(fn), stack[-4], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-3];
    fn = elt(env, 28); /* addsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0297;

v0297:
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    stack[-2] = v0236;
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    v0236 = stack[-1];
    if (v0236 == nil) goto v0246;
    else goto v0296;

v0253:
    v0236 = stack[-5];
    v0237 = qcar(v0236);
    v0236 = elt(env, 5); /* plus */
    if (v0237 == v0236) goto v0298;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0299;

v0299:
    if (v0236 == nil) goto v0256;
    else goto v0246;

v0298:
    v0236 = stack[-5];
    fn = elt(env, 31); /* simp */
    v0237 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = stack[-4];
    fn = elt(env, 32); /* diffsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0299;

v0250:
    v0236 = stack[-5];
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    fn = elt(env, 32); /* diffsq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0251;

v0248:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0249;

v0247:
    v0237 = stack[-5];
    v0236 = stack[-4];
    fn = elt(env, 36); /* depends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    if (v0236 == nil) goto v0300;
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0301;

v0301:
    if (v0236 == nil) goto v0302;
    v0237 = qvalue(elt(env, 2)); /* nil */
    v0236 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v0237, v0236);

v0302:
    v0236 = qvalue(elt(env, 14)); /* !*expanddf */
    if (v0236 == nil) goto v0303;
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 11)); /* powlis!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0304;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    fn = elt(env, 36); /* depends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0305;

v0305:
    if (v0236 == nil) goto v0306;
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 15)); /* depl!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0307;
    v0237 = stack[-4];
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    stack[-2] = v0236;
    v0236 = Lmemq(nil, v0237, v0236);
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0308;

v0308:
    if (v0236 == nil) goto v0303;
    v0238 = stack[-5];
    v0237 = stack[-4];
    v0236 = stack[-2];
    fn = elt(env, 41); /* df!-chain!-rule */
    v0236 = (*qfnn(fn))(qenv(fn), 3, v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0246;

v0303:
    v0238 = elt(env, 16); /* df */
    v0237 = stack[-5];
    v0236 = stack[-4];
    v0236 = list3(v0238, v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    v0236 = stack[-3];
    fn = elt(env, 33); /* opmtch */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-2] = v0236;
    if (v0236 == nil) goto v0309;
    v0236 = stack[-2];
    fn = elt(env, 31); /* simp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0310;

v0310:
    stack[-3] = v0236;
    goto v0246;

v0309:
    v0237 = stack[-3];
    v0236 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 40); /* mksq */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    goto v0310;

v0307:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0308;

v0306:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0308;

v0304:
    v0236 = qvalue(elt(env, 12)); /* t */
    goto v0305;

v0300:
    v0237 = stack[-5];
    v0236 = qvalue(elt(env, 11)); /* powlis!* */
    v0236 = Latsoc(nil, v0237, v0236);
    stack[-2] = v0236;
    if (v0236 == nil) goto v0311;
    v0236 = stack[-2];
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0236 = qcdr(v0236);
    v0237 = qcar(v0236);
    v0236 = stack[-4];
    fn = elt(env, 36); /* depends */
    v0236 = (*qfn2(fn))(qenv(fn), v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0312;

v0312:
    if (v0236 == nil) goto v0313;
    v0236 = qvalue(elt(env, 13)); /* !*depend */
    v0236 = (v0236 == nil ? lisp_true : nil);
    goto v0301;

v0313:
    v0236 = qvalue(elt(env, 2)); /* nil */
    goto v0301;

v0311:
    v0236 = qvalue(elt(env, 12)); /* t */
    goto v0312;

v0244:
    v0237 = (Lisp_Object)17; /* 1 */
    v0236 = (Lisp_Object)17; /* 1 */
    v0236 = cons(v0237, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-7];
    stack[-3] = v0236;
    goto v0245;
/* error exit handlers */
v0241:
    popv(8);
    return nil;
}



/* Code for ofsf_ir2atl */

static Lisp_Object MS_CDECL CC_ofsf_ir2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0331, v0218, v0332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ir2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ir2atl");
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0314;
    stack[0] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0331 = stack[0];
    v0218 = qcar(v0331);
    v0331 = (Lisp_Object)17; /* 1 */
    v0331 = cons(v0218, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    stack[-6] = v0331;
    v0331 = stack[0];
    v0331 = qcdr(v0331);
    stack[-3] = v0331;
    goto v0334;

v0334:
    v0331 = stack[-3];
    if (v0331 == nil) goto v0335;
    v0331 = stack[-3];
    v0331 = qcar(v0331);
    v0218 = v0331;
    v0331 = v0218;
    v0332 = qcar(v0331);
    v0331 = stack[-4];
    if (equal(v0332, v0331)) goto v0336;
    v0331 = nil;
    goto v0232;

v0232:
    stack[-2] = v0331;
    v0331 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    stack[-1] = v0331;
    v0331 = stack[-3];
    v0331 = qcdr(v0331);
    stack[-3] = v0331;
    v0331 = stack[-1];
    if (!consp(v0331)) goto v0334;
    else goto v0337;

v0337:
    v0331 = stack[-3];
    if (v0331 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v0331 = stack[-3];
    v0331 = qcar(v0331);
    v0218 = v0331;
    v0331 = v0218;
    v0332 = qcar(v0331);
    v0331 = stack[-4];
    if (equal(v0332, v0331)) goto v0222;
    v0331 = nil;
    goto v0338;

v0338:
    v0331 = Lrplacd(nil, stack[0], v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    v0331 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v0331 = (*qfn1(fn))(qenv(fn), v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    stack[-1] = v0331;
    v0331 = stack[-3];
    v0331 = qcdr(v0331);
    stack[-3] = v0331;
    goto v0337;

v0222:
    v0332 = stack[-5];
    v0331 = v0218;
    v0218 = qcdr(v0331);
    v0331 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v0331 = (*qfnn(fn))(qenv(fn), 3, v0332, v0218, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    goto v0338;

v0336:
    v0332 = stack[-5];
    v0331 = v0218;
    v0218 = qcdr(v0331);
    v0331 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v0331 = (*qfnn(fn))(qenv(fn), 3, v0332, v0218, v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    v0331 = ncons(v0331);
    nil = C_nil;
    if (exception_pending()) goto v0333;
    env = stack[-7];
    goto v0232;

v0335:
    v0331 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0331); }
/* error exit handlers */
v0333:
    popv(8);
    return nil;
}



/* Code for createtriple */

static Lisp_Object CC_createtriple(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0345, v0346, v0226;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createtriple");
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
    stack[0] = v0000;
/* end of prologue */
    v0345 = (Lisp_Object)49; /* 3 */
    v0345 = Lmkvect(nil, v0345);
    nil = C_nil;
    if (exception_pending()) goto v0347;
    env = stack[-3];
    stack[-2] = v0345;
    v0226 = stack[-2];
    v0346 = (Lisp_Object)1; /* 0 */
    v0345 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    *(Lisp_Object *)((char *)v0226 + (CELL-TAG_VECTOR) + ((int32_t)v0346/(16/CELL))) = v0345;
    v0226 = stack[-2];
    v0346 = (Lisp_Object)17; /* 1 */
    v0345 = stack[0];
    *(Lisp_Object *)((char *)v0226 + (CELL-TAG_VECTOR) + ((int32_t)v0346/(16/CELL))) = v0345;
    v0226 = stack[-2];
    v0346 = (Lisp_Object)33; /* 2 */
    v0345 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    *(Lisp_Object *)((char *)v0226 + (CELL-TAG_VECTOR) + ((int32_t)v0346/(16/CELL))) = v0345;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v0345 = qvalue(elt(env, 2)); /* nil */
    v0345 = ncons(v0345);
    nil = C_nil;
    if (exception_pending()) goto v0347;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0345;
    v0345 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    v0345 = (Lisp_Object)((int32_t)(v0345) + 0x10);
    qvalue(elt(env, 1)) = v0345; /* fluidbibasistripleid */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0347:
    popv(4);
    return nil;
}



/* Code for rl_fvarl */

static Lisp_Object CC_rl_fvarl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0329;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_fvarl");
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
    v0329 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_fvarl!* */
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-1];
    {
        Lisp_Object v0321 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0321, v0329);
    }
/* error exit handlers */
v0318:
    popv(2);
    return nil;
}



/* Code for subtractinds */

static Lisp_Object MS_CDECL CC_subtractinds(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0351, v0352;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subtractinds");
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0314;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0151:
    v0351 = stack[-2];
    if (v0351 == nil) goto v0329;
    v0351 = stack[-3];
    v0352 = qcar(v0351);
    v0351 = stack[-2];
    v0351 = qcar(v0351);
    v0351 = qcar(v0351);
    v0352 = difference2(v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0351 = (Lisp_Object)1; /* 0 */
    v0351 = (Lisp_Object)lessp2(v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    v0351 = v0351 ? lisp_true : nil;
    env = stack[-5];
    if (v0351 == nil) goto v0353;
    v0351 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0351); }

v0353:
    v0351 = stack[-3];
    v0351 = qcdr(v0351);
    stack[-4] = v0351;
    v0351 = stack[-2];
    v0351 = qcdr(v0351);
    stack[0] = v0351;
    v0351 = stack[-3];
    v0352 = qcar(v0351);
    v0351 = stack[-2];
    v0351 = qcar(v0351);
    v0351 = qcar(v0351);
    v0352 = difference2(v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    v0351 = stack[-1];
    v0351 = cons(v0352, v0351);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-5];
    stack[-1] = v0351;
    v0351 = stack[0];
    stack[-2] = v0351;
    v0351 = stack[-4];
    stack[-3] = v0351;
    goto v0151;

v0329:
    v0351 = stack[-1];
        popv(6);
        return Lnreverse(nil, v0351);
/* error exit handlers */
v0229:
    popv(6);
    return nil;
}



/* Code for pasf_exprng1 */

static Lisp_Object CC_pasf_exprng1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0398, v0399, v0400, v0401, v0402, v0176, v0403;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_exprng1");
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
    v0398 = v0000;
/* end of prologue */
    v0400 = v0398;
    v0399 = elt(env, 1); /* true */
    if (v0400 == v0399) goto v0329;
    v0400 = v0398;
    v0399 = elt(env, 3); /* false */
    v0399 = (v0400 == v0399 ? lisp_true : nil);
    goto v0404;

v0404:
    if (!(v0399 == nil)) { popv(6); return onevalue(v0398); }
    v0399 = v0398;
    if (!consp(v0399)) goto v0233;
    v0399 = v0398;
    v0399 = qcar(v0399);
    goto v0232;

v0232:
    stack[-4] = v0399;
    v0400 = stack[-4];
    v0399 = elt(env, 4); /* or */
    if (v0400 == v0399) goto v0325;
    v0400 = stack[-4];
    v0399 = elt(env, 5); /* and */
    v0399 = (v0400 == v0399 ? lisp_true : nil);
    goto v0324;

v0324:
    if (v0399 == nil) goto v0405;
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0345;

v0345:
    if (v0399 == nil) goto v0223;
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0213;

v0213:
    if (v0399 == nil) goto v0406;
    v0398 = qcdr(v0398);
    stack[-3] = v0398;
    v0398 = stack[-3];
    if (v0398 == nil) goto v0407;
    v0398 = stack[-3];
    v0398 = qcar(v0398);
    v0398 = CC_pasf_exprng1(env, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-5];
    v0398 = ncons(v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-5];
    stack[-1] = v0398;
    stack[-2] = v0398;
    goto v0409;

v0409:
    v0398 = stack[-3];
    v0398 = qcdr(v0398);
    stack[-3] = v0398;
    v0398 = stack[-3];
    if (v0398 == nil) goto v0410;
    stack[0] = stack[-1];
    v0398 = stack[-3];
    v0398 = qcar(v0398);
    v0398 = CC_pasf_exprng1(env, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-5];
    v0398 = ncons(v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-5];
    v0398 = Lrplacd(nil, stack[0], v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    env = stack[-5];
    v0398 = stack[-1];
    v0398 = qcdr(v0398);
    stack[-1] = v0398;
    goto v0409;

v0410:
    v0398 = stack[-2];
    goto v0411;

v0411:
    v0399 = v0398;
    v0398 = v0399;
    if (v0398 == nil) goto v0412;
    v0398 = v0399;
    v0398 = qcdr(v0398);
    if (v0398 == nil) goto v0412;
    v0398 = stack[-4];
    popv(6);
    return cons(v0398, v0399);

v0412:
    v0398 = v0399;
    if (v0398 == nil) goto v0413;
    v0398 = v0399;
    v0398 = qcar(v0398);
    { popv(6); return onevalue(v0398); }

v0413:
    v0399 = stack[-4];
    v0398 = elt(env, 5); /* and */
    if (v0399 == v0398) goto v0414;
    v0398 = elt(env, 3); /* false */
    { popv(6); return onevalue(v0398); }

v0414:
    v0398 = elt(env, 1); /* true */
    { popv(6); return onevalue(v0398); }

v0407:
    v0398 = qvalue(elt(env, 10)); /* nil */
    goto v0411;

v0406:
    v0400 = stack[-4];
    v0399 = elt(env, 11); /* ex */
    if (v0400 == v0399) goto v0415;
    v0400 = stack[-4];
    v0399 = elt(env, 12); /* all */
    v0399 = (v0400 == v0399 ? lisp_true : nil);
    goto v0252;

v0252:
    if (v0399 == nil) goto v0416;
    stack[-1] = stack[-4];
    v0399 = v0398;
    v0399 = qcdr(v0399);
    stack[0] = qcar(v0399);
    v0398 = qcdr(v0398);
    v0398 = qcdr(v0398);
    v0398 = qcar(v0398);
    v0398 = CC_pasf_exprng1(env, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0408;
    {
        Lisp_Object v0178 = stack[-1];
        Lisp_Object v0179 = stack[0];
        popv(6);
        return list3(v0178, v0179, v0398);
    }

v0416:
    v0400 = stack[-4];
    v0399 = elt(env, 13); /* ball */
    if (v0400 == v0399) goto v0417;
    v0400 = stack[-4];
    v0399 = elt(env, 14); /* bex */
    if (!(v0400 == v0399)) { popv(6); return onevalue(v0398); }
    v0403 = stack[-4];
    v0399 = v0398;
    v0399 = qcdr(v0399);
    v0176 = qcar(v0399);
    v0399 = v0398;
    v0399 = qcdr(v0399);
    v0399 = qcdr(v0399);
    v0399 = qcdr(v0399);
    v0402 = qcar(v0399);
    v0398 = qcdr(v0398);
    v0398 = qcdr(v0398);
    v0401 = qcar(v0398);
    v0400 = elt(env, 4); /* or */
    v0399 = elt(env, 3); /* false */
    v0398 = elt(env, 1); /* true */
    {
        popv(6);
        fn = elt(env, 15); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v0403, v0176, v0402, v0401, v0400, v0399, v0398);
    }

v0417:
    v0403 = stack[-4];
    v0399 = v0398;
    v0399 = qcdr(v0399);
    v0176 = qcar(v0399);
    v0399 = v0398;
    v0399 = qcdr(v0399);
    v0399 = qcdr(v0399);
    v0399 = qcdr(v0399);
    v0402 = qcar(v0399);
    v0398 = qcdr(v0398);
    v0398 = qcdr(v0398);
    v0401 = qcar(v0398);
    v0400 = elt(env, 5); /* and */
    v0399 = elt(env, 1); /* true */
    v0398 = elt(env, 3); /* false */
    {
        popv(6);
        fn = elt(env, 15); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v0403, v0176, v0402, v0401, v0400, v0399, v0398);
    }

v0415:
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0252;

v0223:
    v0400 = stack[-4];
    v0399 = elt(env, 7); /* impl */
    if (v0400 == v0399) goto v0320;
    v0400 = stack[-4];
    v0399 = elt(env, 8); /* repl */
    if (v0400 == v0399) goto v0317;
    v0400 = stack[-4];
    v0399 = elt(env, 9); /* equiv */
    v0399 = (v0400 == v0399 ? lisp_true : nil);
    goto v0213;

v0317:
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0213;

v0320:
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0213;

v0405:
    v0400 = stack[-4];
    v0399 = elt(env, 6); /* not */
    v0399 = (v0400 == v0399 ? lisp_true : nil);
    goto v0345;

v0325:
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0324;

v0233:
    v0399 = v0398;
    goto v0232;

v0329:
    v0399 = qvalue(elt(env, 2)); /* t */
    goto v0404;
/* error exit handlers */
v0408:
    popv(6);
    return nil;
}



/* Code for intervalom */

static Lisp_Object CC_intervalom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0320, v0225, v0223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalom");
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
    v0320 = stack[-2];
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    stack[-3] = v0320;
    v0320 = stack[-2];
    v0320 = qcar(v0320);
    stack[-1] = v0320;
    v0225 = stack[-1];
    v0320 = elt(env, 1); /* lowupperlimit */
    if (!(v0225 == v0320)) goto v0421;
    v0320 = elt(env, 2); /* integer_interval */
    stack[-1] = v0320;
    v0320 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v0320;
    v0320 = stack[-2];
    v0223 = qcar(v0320);
    v0225 = qvalue(elt(env, 3)); /* nil */
    v0320 = stack[-2];
    v0320 = qcdr(v0320);
    v0320 = list2star(v0223, v0225, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    stack[-2] = v0320;
    goto v0421;

v0421:
    v0225 = stack[-1];
    v0320 = qvalue(elt(env, 4)); /* valid_om!* */
    v0320 = Lassoc(nil, v0225, v0320);
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    stack[0] = v0320;
    v0320 = stack[-3];
    if (v0320 == nil) goto v0390;
    v0320 = stack[-3];
    v0320 = qcar(v0320);
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    v0225 = Lintern(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = qvalue(elt(env, 5)); /* interval!* */
    v0320 = Lassoc(nil, v0225, v0320);
    v0320 = qcdr(v0320);
    v0320 = qcar(v0320);
    stack[-1] = v0320;
    goto v0390;

v0390:
    v0320 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = stack[0];
    v0320 = Lprinc(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = elt(env, 9); /* """ name=""" */
    v0320 = Lprinc(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = stack[-1];
    v0320 = Lprinc(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = elt(env, 10); /* """/>" */
    v0320 = Lprinc(nil, v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = stack[-2];
    v0320 = qcdr(v0320);
    v0320 = qcdr(v0320);
    fn = elt(env, 14); /* multiom */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    env = stack[-4];
    v0320 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v0320 = (*qfn1(fn))(qenv(fn), v0320);
    nil = C_nil;
    if (exception_pending()) goto v0388;
    v0320 = nil;
    { popv(5); return onevalue(v0320); }
/* error exit handlers */
v0388:
    popv(5);
    return nil;
}



/* Code for reduceroots */

static Lisp_Object CC_reduceroots(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0340, v0336, v0213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduceroots");
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
    v0340 = nil;
    goto v0151;

v0151:
    v0336 = stack[-1];
    if (v0336 == nil) { popv(3); return onevalue(v0340); }
    v0336 = stack[0];
    v0213 = qcar(v0336);
    v0336 = elt(env, 2); /* sqrt */
    if (!consp(v0213)) goto v0258;
    v0213 = qcar(v0213);
    if (!(v0213 == v0336)) goto v0258;
    v0213 = stack[-1];
    v0336 = stack[0];
    v0336 = qcar(v0336);
    fn = elt(env, 3); /* tryreduction */
    v0340 = (*qfnn(fn))(qenv(fn), 3, v0213, v0336, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0390;
    env = stack[-2];
    goto v0258;

v0258:
    v0336 = stack[-1];
    v0336 = qcdr(v0336);
    stack[-1] = v0336;
    v0336 = stack[0];
    v0336 = qcdr(v0336);
    stack[0] = v0336;
    goto v0151;
/* error exit handlers */
v0390:
    popv(3);
    return nil;
}



/* Code for reprod */

static Lisp_Object CC_reprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reprod");
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

v0018:
    v0323 = stack[-1];
    if (v0323 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0323 = stack[-1];
    v0232 = qcar(v0323);
    v0323 = (Lisp_Object)17; /* 1 */
    v0323 = cons(v0232, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-2];
    v0232 = ncons(v0323);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-2];
    v0323 = stack[0];
    fn = elt(env, 2); /* multf */
    v0323 = (*qfn2(fn))(qenv(fn), v0232, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-2];
    stack[0] = v0323;
    v0323 = stack[-1];
    v0323 = qcdr(v0323);
    stack[-1] = v0323;
    goto v0018;
/* error exit handlers */
v0341:
    popv(3);
    return nil;
}



/* Code for fnreval */

static Lisp_Object MS_CDECL CC_fnreval(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0383, v0380;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fnreval");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnreval");
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0314;
    stack[-1] = v0001;
    stack[0] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0180;

v0180:
    v0383 = stack[0];
    if (v0383 == nil) goto v0404;
    v0380 = stack[-1];
    v0383 = qvalue(elt(env, 1)); /* t */
    if (v0380 == v0383) goto v0335;
    v0383 = stack[-1];
    if (v0383 == nil) goto v0341;
    v0383 = stack[-1];
    v0383 = qcar(v0383);
    if (v0383 == nil) goto v0208;
    v0383 = stack[0];
    v0383 = qcar(v0383);
    v0380 = v0383;
    goto v0429;

v0429:
    v0383 = stack[-2];
    v0383 = cons(v0380, v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    stack[-2] = v0383;
    v0383 = stack[0];
    v0383 = qcdr(v0383);
    stack[0] = v0383;
    v0383 = stack[-1];
    v0383 = qcdr(v0383);
    stack[-1] = v0383;
    goto v0180;

v0208:
    v0383 = stack[0];
    v0380 = qcar(v0383);
    v0383 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v0383 = (*qfn2(fn))(qenv(fn), v0380, v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0380 = v0383;
    goto v0429;

v0341:
    stack[-5] = stack[-2];
    v0383 = stack[0];
    stack[-3] = v0383;
    v0383 = stack[-3];
    if (v0383 == nil) goto v0345;
    v0383 = stack[-3];
    v0383 = qcar(v0383);
    v0380 = v0383;
    v0383 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v0383 = (*qfn2(fn))(qenv(fn), v0380, v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0383 = ncons(v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    stack[-1] = v0383;
    stack[-2] = v0383;
    goto v0213;

v0213:
    v0383 = stack[-3];
    v0383 = qcdr(v0383);
    stack[-3] = v0383;
    v0383 = stack[-3];
    if (v0383 == nil) goto v0430;
    stack[0] = stack[-1];
    v0383 = stack[-3];
    v0383 = qcar(v0383);
    v0380 = v0383;
    v0383 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v0383 = (*qfn2(fn))(qenv(fn), v0380, v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0383 = ncons(v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0383 = Lrplacd(nil, stack[0], v0383);
    nil = C_nil;
    if (exception_pending()) goto v0407;
    env = stack[-6];
    v0383 = stack[-1];
    v0383 = qcdr(v0383);
    stack[-1] = v0383;
    goto v0213;

v0430:
    v0383 = stack[-2];
    goto v0421;

v0421:
    {
        Lisp_Object v0431 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0431, v0383);
    }

v0345:
    v0383 = qvalue(elt(env, 2)); /* nil */
    goto v0421;

v0335:
    v0380 = stack[-2];
    v0383 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0380, v0383);
    }

v0404:
    v0383 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0383);
    }
/* error exit handlers */
v0407:
    popv(7);
    return nil;
}



/* Code for sqprla */

static Lisp_Object CC_sqprla(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0318, v0321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprla");
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
    v0318 = v0000;
/* end of prologue */
    v0318 = qcar(v0318);
    fn = elt(env, 1); /* prepsq!* */
    v0321 = (*qfn1(fn))(qenv(fn), v0318);
    nil = C_nil;
    if (exception_pending()) goto v0258;
    env = stack[-1];
    v0318 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v0321, v0318);
    }
/* error exit handlers */
v0258:
    popv(2);
    return nil;
}



/* Code for gfftimes */

static Lisp_Object CC_gfftimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0432, v0433, v0228;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfftimes");
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
    v0433 = v0001;
    v0228 = v0000;
/* end of prologue */
    v0432 = v0228;
    v0432 = qcar(v0432);
    stack[-4] = v0432;
    v0432 = v0228;
    v0432 = qcdr(v0432);
    stack[-3] = v0432;
    v0432 = v0433;
    v0432 = qcar(v0432);
    stack[-2] = v0432;
    v0432 = v0433;
    v0432 = qcdr(v0432);
    stack[-1] = v0432;
    v0433 = stack[-4];
    v0432 = stack[-2];
    stack[0] = times2(v0433, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[-5];
    v0433 = stack[-3];
    v0432 = stack[-1];
    v0432 = times2(v0433, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[-5];
    stack[0] = difference2(stack[0], v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[-5];
    v0433 = stack[-4];
    v0432 = stack[-1];
    stack[-1] = times2(v0433, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[-5];
    v0433 = stack[-3];
    v0432 = stack[-2];
    v0432 = times2(v0433, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    env = stack[-5];
    v0432 = plus2(stack[-1], v0432);
    nil = C_nil;
    if (exception_pending()) goto v0434;
    {
        Lisp_Object v0338 = stack[0];
        popv(6);
        return cons(v0338, v0432);
    }
/* error exit handlers */
v0434:
    popv(6);
    return nil;
}



/* Code for lispcodeexp */

static Lisp_Object CC_lispcodeexp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0498, v0499, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispcodeexp");
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
    stack[-3] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0500:
    v0498 = stack[-2];
    if (is_number(v0498)) goto v0180;
    v0499 = stack[-2];
    v0498 = elt(env, 1); /* e */
    if (v0499 == v0498) goto v0341;
    v0498 = stack[-2];
    if (!consp(v0498)) goto v0501;
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = elt(env, 5); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v0498 = Lmemq(nil, v0499, v0498);
    goto v0213;

v0213:
    if (v0498 == nil) goto v0502;
    v0498 = qvalue(elt(env, 6)); /* irena!-constants */
    if (v0498 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0498 = stack[-2];
    if (v0498 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0498 = stack[-2];
    v0498 = Lstringp(nil, v0498);
    env = stack[-5];
    if (!(v0498 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0498 = stack[-2];
    fn = elt(env, 21); /* check!-for!-irena!-constants */
    v0498 = (*qfn1(fn))(qenv(fn), v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v0502:
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = elt(env, 7); /* expt */
    if (v0499 == v0498) goto v0320;
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = elt(env, 12); /* quotient */
    if (v0499 == v0498) goto v0504;
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = elt(env, 14); /* recip */
    if (v0499 == v0498) goto v0505;
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = elt(env, 16); /* difference */
    if (v0499 == v0498) goto v0506;
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = qvalue(elt(env, 19)); /* !*lisparithexpops!* */
    v0498 = Lmemq(nil, v0499, v0498);
    if (v0498 == nil) goto v0507;
    v0498 = qvalue(elt(env, 13)); /* nil */
    goto v0508;

v0508:
    if (v0498 == nil) goto v0133;
    v0498 = stack[-2];
    stack[-3] = v0498;
    v0498 = stack[-3];
    if (v0498 == nil) goto v0156;
    v0498 = stack[-3];
    v0498 = qcar(v0498);
    v0499 = v0498;
    v0498 = qvalue(elt(env, 13)); /* nil */
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = ncons(v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    stack[-1] = v0498;
    stack[-2] = v0498;
    goto v0509;

v0509:
    v0498 = stack[-3];
    v0498 = qcdr(v0498);
    stack[-3] = v0498;
    v0498 = stack[-3];
    if (v0498 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0498 = stack[-3];
    v0498 = qcar(v0498);
    v0499 = v0498;
    v0498 = qvalue(elt(env, 13)); /* nil */
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = ncons(v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = Lrplacd(nil, stack[0], v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-1];
    v0498 = qcdr(v0498);
    stack[-1] = v0498;
    goto v0509;

v0156:
    v0498 = qvalue(elt(env, 13)); /* nil */
    { popv(6); return onevalue(v0498); }

v0133:
    v0498 = stack[-2];
    stack[-4] = v0498;
    v0498 = stack[-4];
    if (v0498 == nil) goto v0141;
    v0498 = stack[-4];
    v0498 = qcar(v0498);
    v0499 = v0498;
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = ncons(v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    stack[-1] = v0498;
    stack[-2] = v0498;
    goto v0510;

v0510:
    v0498 = stack[-4];
    v0498 = qcdr(v0498);
    stack[-4] = v0498;
    v0498 = stack[-4];
    if (v0498 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0498 = stack[-4];
    v0498 = qcar(v0498);
    v0499 = v0498;
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = ncons(v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = Lrplacd(nil, stack[0], v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-1];
    v0498 = qcdr(v0498);
    stack[-1] = v0498;
    goto v0510;

v0141:
    v0498 = qvalue(elt(env, 13)); /* nil */
    { popv(6); return onevalue(v0498); }

v0507:
    v0498 = stack[-2];
    v0499 = qcar(v0498);
    v0498 = qvalue(elt(env, 20)); /* !*lisplogexpops!* */
    v0498 = Lmemq(nil, v0499, v0498);
    v0498 = (v0498 == nil ? lisp_true : nil);
    goto v0508;

v0506:
    stack[-4] = elt(env, 17); /* plus */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    stack[0] = elt(env, 18); /* minus */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = list2(stack[0], v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0511 = stack[-4];
        Lisp_Object v0512 = stack[-1];
        popv(6);
        return list3(v0511, v0512, v0498);
    }

v0505:
    v0498 = qvalue(elt(env, 15)); /* !*period */
    if (v0498 == nil) goto v0513;
    stack[-1] = elt(env, 12); /* quotient */
    stack[0] = elt(env, 3); /* 1.0 */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0120 = stack[-1];
        Lisp_Object v0308 = stack[0];
        popv(6);
        return list3(v0120, v0308, v0498);
    }

v0513:
    stack[-1] = elt(env, 12); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0514 = stack[-1];
        Lisp_Object v0515 = stack[0];
        popv(6);
        return list3(v0514, v0515, v0498);
    }

v0504:
    stack[-1] = elt(env, 12); /* quotient */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = qvalue(elt(env, 4)); /* t */
    stack[0] = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = qvalue(elt(env, 4)); /* t */
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0126 = stack[-1];
        Lisp_Object v0305 = stack[0];
        popv(6);
        return list3(v0126, v0305, v0498);
    }

v0320:
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = elt(env, 1); /* e */
    if (v0499 == v0498) goto v0516;
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = elt(env, 8); /* (quotient 1 2) */
    if (equal(v0499, v0498)) goto v0517;
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = elt(env, 10); /* !:rd!: */
    if (!consp(v0499)) goto v0518;
    v0499 = qcar(v0499);
    if (!(v0499 == v0498)) goto v0518;
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0498 = qcar(v0498);
    fn = elt(env, 22); /* realrat */
    v0498 = (*qfn1(fn))(qenv(fn), v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    stack[-1] = v0498;
    v0499 = stack[-1];
    v0498 = elt(env, 11); /* (1 . 2) */
    if (equal(v0499, v0498)) goto v0201;
    stack[0] = elt(env, 7); /* expt */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0132 = elt(env, 12); /* quotient */
    v0498 = stack[-1];
    v0499 = qcar(v0498);
    v0498 = stack[-1];
    v0498 = qcdr(v0498);
    v0499 = list3(v0132, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = qvalue(elt(env, 13)); /* nil */
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0304 = stack[0];
        Lisp_Object v0519 = stack[-2];
        popv(6);
        return list3(v0304, v0519, v0498);
    }

v0201:
    stack[0] = elt(env, 9); /* sqrt */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0520 = stack[0];
        popv(6);
        return list2(v0520, v0498);
    }

v0518:
    stack[0] = elt(env, 7); /* expt */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0499 = qcar(v0498);
    v0498 = qvalue(elt(env, 13)); /* nil */
    v0498 = CC_lispcodeexp(env, v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    {
        Lisp_Object v0521 = stack[0];
        Lisp_Object v0522 = stack[-1];
        popv(6);
        return list3(v0521, v0522, v0498);
    }

v0517:
    v0499 = elt(env, 9); /* sqrt */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcar(v0498);
    v0499 = list2(v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-3];
    stack[-2] = v0499;
    stack[-3] = v0498;
    goto v0500;

v0516:
    v0499 = elt(env, 2); /* exp */
    v0498 = stack[-2];
    v0498 = qcdr(v0498);
    v0498 = qcdr(v0498);
    v0498 = qcar(v0498);
    v0499 = list2(v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-3];
    stack[-2] = v0499;
    stack[-3] = v0498;
    goto v0500;

v0501:
    v0498 = qvalue(elt(env, 4)); /* t */
    goto v0213;

v0341:
    v0499 = elt(env, 2); /* exp */
    v0498 = elt(env, 3); /* 1.0 */
    v0499 = list2(v0499, v0498);
    nil = C_nil;
    if (exception_pending()) goto v0503;
    env = stack[-5];
    v0498 = stack[-3];
    stack[-2] = v0499;
    stack[-3] = v0498;
    goto v0500;

v0180:
    v0498 = stack[-3];
    if (v0498 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0498 = stack[-2];
        popv(6);
        return Lfloat(nil, v0498);
/* error exit handlers */
v0503:
    popv(6);
    return nil;
}



/* Code for incident1 */

static Lisp_Object MS_CDECL CC_incident1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0523, v0333, v0423, v0386, v0212;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident1");
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0423 = v0314;
    v0386 = v0001;
    v0212 = v0000;
/* end of prologue */
    v0333 = v0212;
    v0523 = v0386;
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    if (v0333 == v0523) goto v0397;
    v0333 = v0212;
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    if (v0333 == v0523) goto v0325;
    v0333 = v0212;
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    if (v0333 == v0523) goto v0223;
    v0523 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0523); }

v0223:
    v0523 = v0386;
    v0523 = qcar(v0523);
    stack[-1] = qcar(v0523);
    stack[0] = v0423;
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    v0333 = v0423;
    v0523 = cons(v0523, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-2];
    v0523 = ncons(v0523);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    {
        Lisp_Object v0383 = stack[-1];
        Lisp_Object v0380 = stack[0];
        popv(3);
        return acons(v0383, v0380, v0523);
    }

v0325:
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    stack[-1] = qcar(v0523);
    stack[0] = v0423;
    v0523 = v0386;
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    v0333 = v0423;
    v0523 = cons(v0523, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-2];
    v0523 = ncons(v0523);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    {
        Lisp_Object v0411 = stack[-1];
        Lisp_Object v0409 = stack[0];
        popv(3);
        return acons(v0411, v0409, v0523);
    }

v0397:
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    stack[-1] = qcar(v0523);
    stack[0] = v0423;
    v0523 = v0386;
    v0523 = qcdr(v0523);
    v0523 = qcdr(v0523);
    v0523 = qcar(v0523);
    v0523 = qcar(v0523);
    v0333 = v0423;
    v0523 = cons(v0523, v0333);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-2];
    v0523 = ncons(v0523);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    {
        Lisp_Object v0209 = stack[-1];
        Lisp_Object v0210 = stack[0];
        popv(3);
        return acons(v0209, v0210, v0523);
    }
/* error exit handlers */
v0244:
    popv(3);
    return nil;
}



/* Code for negex */

static Lisp_Object CC_negex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0232, v0233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negex");
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
    goto v0018;

v0018:
    v0232 = stack[-1];
    if (v0232 == nil) goto v0151;
    v0232 = stack[-1];
    v0232 = qcar(v0232);
    stack[0] = qcar(v0232);
    v0232 = stack[-1];
    v0232 = qcar(v0232);
    v0232 = qcdr(v0232);
    fn = elt(env, 1); /* negf */
    v0233 = (*qfn1(fn))(qenv(fn), v0232);
    nil = C_nil;
    if (exception_pending()) goto v0418;
    env = stack[-3];
    v0232 = stack[-2];
    v0232 = acons(stack[0], v0233, v0232);
    nil = C_nil;
    if (exception_pending()) goto v0418;
    env = stack[-3];
    stack[-2] = v0232;
    v0232 = stack[-1];
    v0232 = qcdr(v0232);
    stack[-1] = v0232;
    goto v0018;

v0151:
    v0232 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0232);
    }
/* error exit handlers */
v0418:
    popv(4);
    return nil;
}



/* Code for msolve!-psys1 */

static Lisp_Object CC_msolveKpsys1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-psys1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0212 = qvalue(elt(env, 1)); /* nil */
    v0212 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    v0211 = v0212;
    v0212 = stack[0];
    stack[-4] = v0212;
    goto v0321;

v0321:
    v0212 = stack[-4];
    if (v0212 == nil) { popv(8); return onevalue(v0211); }
    v0212 = stack[-4];
    v0212 = qcar(v0212);
    stack[-3] = v0212;
    v0212 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v0212;
    v0212 = v0211;
    stack[-2] = v0212;
    goto v0396;

v0396:
    v0212 = stack[-2];
    if (v0212 == nil) goto v0395;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    stack[-1] = v0212;
    v0211 = stack[-3];
    v0212 = stack[-1];
    fn = elt(env, 3); /* subf */
    v0212 = (*qfn2(fn))(qenv(fn), v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    v0212 = qcar(v0212);
    fn = elt(env, 4); /* moduntag */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    fn = elt(env, 5); /* general!-reduce!-mod!-p */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    v0211 = v0212;
    v0212 = v0211;
    if (v0212 == nil) goto v0347;
    v0212 = v0211;
    if (!consp(v0212)) goto v0433;
    v0212 = v0211;
    v0212 = qcar(v0212);
    v0212 = (consp(v0212) ? nil : lisp_true);
    goto v0432;

v0432:
    if (!(v0212 == nil)) goto v0346;
    v0212 = stack[-5];
    fn = elt(env, 6); /* msolve!-poly */
    v0212 = (*qfn2(fn))(qenv(fn), v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    stack[0] = v0212;
    goto v0525;

v0525:
    v0212 = stack[0];
    if (v0212 == nil) goto v0346;
    v0212 = stack[0];
    v0212 = qcar(v0212);
    v0211 = stack[-1];
    v0211 = Lappend(nil, v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    v0212 = stack[-6];
    v0212 = cons(v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    stack[-6] = v0212;
    v0212 = stack[0];
    v0212 = qcdr(v0212);
    stack[0] = v0212;
    goto v0525;

v0346:
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    goto v0396;

v0433:
    v0212 = qvalue(elt(env, 2)); /* t */
    goto v0432;

v0347:
    v0211 = stack[-1];
    v0212 = stack[-6];
    v0212 = cons(v0211, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0210;
    env = stack[-7];
    stack[-6] = v0212;
    goto v0346;

v0395:
    v0212 = stack[-6];
    v0211 = v0212;
    v0212 = stack[-4];
    v0212 = qcdr(v0212);
    stack[-4] = v0212;
    goto v0321;
/* error exit handlers */
v0210:
    popv(8);
    return nil;
}



/* Code for settreset */

static Lisp_Object MS_CDECL CC_settreset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "settreset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for settreset");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v0010 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0010; /* fluidbibasisjanettreerootnode */
    v0010 = qvalue(elt(env, 1)); /* nil */
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0180;
    env = stack[0];
    qvalue(elt(env, 3)) = v0010; /* fluidbibasissett */
    v0010 = nil;
    { popv(1); return onevalue(v0010); }
/* error exit handlers */
v0180:
    popv(1);
    return nil;
}



/* Code for ofsf_evalatp */

static Lisp_Object CC_ofsf_evalatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0217, v0385, v0316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_evalatp");
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
    v0316 = v0000;
/* end of prologue */
    v0385 = v0316;
    v0217 = elt(env, 1); /* equal */
    if (v0385 == v0217) goto v0018;
    v0385 = v0316;
    v0217 = elt(env, 2); /* neq */
    if (v0385 == v0217) goto v0258;
    v0385 = v0316;
    v0217 = elt(env, 3); /* leq */
    if (v0385 == v0217) goto v0395;
    v0385 = v0316;
    v0217 = elt(env, 4); /* geq */
    if (v0385 == v0217) goto v0339;
    v0385 = v0316;
    v0217 = elt(env, 5); /* lessp */
    if (v0385 == v0217) goto v0325;
    v0385 = v0316;
    v0217 = elt(env, 6); /* greaterp */
    if (v0385 == v0217) goto v0432;
    v0217 = qvalue(elt(env, 7)); /* !*protfg */
    if (!(v0217 == nil)) goto v0526;
    v0217 = elt(env, 8); /* "ofsf_evalatp: unknown operator " */
    v0385 = v0316;
    v0217 = list2(v0217, v0385);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    env = stack[-1];
    fn = elt(env, 9); /* lprie */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    env = stack[-1];
    goto v0526;

v0526:
    v0217 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    v0217 = nil;
    { popv(2); return onevalue(v0217); }

v0432:
    v0217 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    if (!(v0217 == nil)) goto v0527;
    v0217 = stack[0];
    v0217 = (v0217 == nil ? lisp_true : nil);
    goto v0527;

v0527:
    v0217 = (v0217 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0217); }

v0325:
    v0217 = stack[0];
    {
        popv(2);
        fn = elt(env, 10); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0217);
    }

v0339:
    v0217 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    v0217 = (v0217 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0217); }

v0395:
    v0217 = stack[0];
    fn = elt(env, 10); /* minusf */
    v0217 = (*qfn1(fn))(qenv(fn), v0217);
    nil = C_nil;
    if (exception_pending()) goto v0497;
    if (!(v0217 == nil)) { popv(2); return onevalue(v0217); }
    v0217 = stack[0];
    v0217 = (v0217 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0217); }

v0258:
    v0217 = stack[0];
    v0217 = (v0217 == nil ? lisp_true : nil);
    v0217 = (v0217 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0217); }

v0018:
    v0217 = stack[0];
    v0217 = (v0217 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0217); }
/* error exit handlers */
v0497:
    popv(2);
    return nil;
}



/* Code for qqe_ofsf_varlat */

static Lisp_Object CC_qqe_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0396, v0428;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_ofsf_varlat");
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
    v0396 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* qqe_ofsf_prepat */
    v0396 = (*qfn1(fn))(qenv(fn), v0396);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    stack[-1] = v0396;
    v0396 = stack[-1];
    fn = elt(env, 3); /* qqe_arg2l */
    v0428 = (*qfn1(fn))(qenv(fn), v0396);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    v0396 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    stack[0] = (*qfn2(fn))(qenv(fn), v0428, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    v0396 = stack[-1];
    fn = elt(env, 5); /* qqe_arg2r */
    v0428 = (*qfn1(fn))(qenv(fn), v0396);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    v0396 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    v0396 = (*qfn2(fn))(qenv(fn), v0428, v0396);
    nil = C_nil;
    if (exception_pending()) goto v0232;
    env = stack[-2];
    {
        Lisp_Object v0233 = stack[0];
        popv(3);
        fn = elt(env, 6); /* union */
        return (*qfn2(fn))(qenv(fn), v0233, v0396);
    }
/* error exit handlers */
v0232:
    popv(3);
    return nil;
}



/* Code for aex_subrp */

static Lisp_Object MS_CDECL CC_aex_subrp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0428, v0326, v0323;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "aex_subrp");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_subrp");
#endif
    if (stack >= stacklimit)
    {
        push3(v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0314);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0314;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0428 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    v0323 = (*qfn1(fn))(qenv(fn), v0428);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-3];
    v0326 = stack[-1];
    v0428 = stack[0];
    fn = elt(env, 3); /* ratpoly_sub */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0323, v0326, v0428);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-3];
    v0428 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    v0323 = (*qfn1(fn))(qenv(fn), v0428);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-3];
    v0326 = qvalue(elt(env, 1)); /* nil */
    v0428 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0353 = stack[0];
        popv(4);
        fn = elt(env, 5); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0353, v0323, v0326, v0428);
    }
/* error exit handlers */
v0341:
    popv(4);
    return nil;
}



/* Code for intervalrd */

static Lisp_Object MS_CDECL CC_intervalrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0353, v0418;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    fn = elt(env, 4); /* mathml */
    v0353 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-2];
    stack[-1] = v0353;
    fn = elt(env, 4); /* mathml */
    v0353 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-2];
    stack[0] = v0353;
    fn = elt(env, 5); /* lex */
    v0353 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    env = stack[-2];
    v0418 = qvalue(elt(env, 1)); /* char */
    v0353 = elt(env, 2); /* (!/ i n t e r v a l) */
    if (equal(v0418, v0353)) goto v0337;
    v0418 = elt(env, 3); /* "</interval>" */
    v0353 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v0353 = (*qfn2(fn))(qenv(fn), v0418, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0424;
    v0353 = nil;
    { popv(3); return onevalue(v0353); }

v0337:
    v0418 = stack[-1];
    v0353 = stack[0];
    popv(3);
    return list2(v0418, v0353);
/* error exit handlers */
v0424:
    popv(3);
    return nil;
}



/* Code for simpsqrtsq */

static Lisp_Object CC_simpsqrtsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrtsq");
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
    v0321 = stack[0];
    v0321 = qcar(v0321);
    fn = elt(env, 1); /* simpsqrt2 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0321);
    nil = C_nil;
    if (exception_pending()) goto v0528;
    env = stack[-2];
    v0321 = stack[0];
    v0321 = qcdr(v0321);
    fn = elt(env, 1); /* simpsqrt2 */
    v0321 = (*qfn1(fn))(qenv(fn), v0321);
    nil = C_nil;
    if (exception_pending()) goto v0528;
    {
        Lisp_Object v0397 = stack[-1];
        popv(3);
        return cons(v0397, v0321);
    }
/* error exit handlers */
v0528:
    popv(3);
    return nil;
}



/* Code for cr!:onep */

static Lisp_Object CC_crTonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0524, v0320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:onep");
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
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcdr(v0524);
    if (!consp(v0524)) goto v0151;
    v0320 = elt(env, 1); /* !:rd!: */
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcdr(v0524);
    v0524 = cons(v0320, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-1];
    goto v0180;

v0180:
    v0320 = v0524;
    v0524 = v0320;
    if (!consp(v0524)) goto v0326;
    v0524 = v0320;
    v0524 = qcdr(v0524);
    v0320 = qcar(v0524);
    v0524 = (Lisp_Object)1; /* 0 */
    v0524 = (v0320 == v0524 ? lisp_true : nil);
    goto v0428;

v0428:
    if (v0524 == nil) goto v0004;
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcar(v0524);
    if (!consp(v0524)) goto v0392;
    v0320 = elt(env, 1); /* !:rd!: */
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcar(v0524);
    v0524 = cons(v0320, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-1];
    goto v0226;

v0226:
    v0320 = v0524;
    if (!(!consp(v0320))) goto v0338;
    v0320 = elt(env, 1); /* !:rd!: */
    v0524 = cons(v0320, v0524);
    nil = C_nil;
    if (exception_pending()) goto v0223;
    env = stack[-1];
    goto v0338;

v0338:
    {
        popv(2);
        fn = elt(env, 3); /* rd!:onep */
        return (*qfn1(fn))(qenv(fn), v0524);
    }

v0392:
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcar(v0524);
    goto v0226;

v0004:
    v0524 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0524); }

v0326:
    v0524 = v0320;
    v0524 = (Lisp_Object)zerop(v0524);
    v0524 = v0524 ? lisp_true : nil;
    env = stack[-1];
    goto v0428;

v0151:
    v0524 = stack[0];
    v0524 = qcdr(v0524);
    v0524 = qcdr(v0524);
    goto v0180;
/* error exit handlers */
v0223:
    popv(2);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0393, v0394, v0434;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhr");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    stack[-1] = nil;
    goto v0318;

v0318:
    v0394 = qvalue(elt(env, 1)); /* headhisto */
    v0393 = (Lisp_Object)1; /* 0 */
    v0393 = (Lisp_Object)greaterp2(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    v0393 = v0393 ? lisp_true : nil;
    env = stack[-2];
    if (v0393 == nil) goto v0018;
    v0394 = qvalue(elt(env, 2)); /* codhisto */
    v0393 = qvalue(elt(env, 1)); /* headhisto */
    v0393 = *(Lisp_Object *)((char *)v0394 + (CELL-TAG_VECTOR) + ((int32_t)v0393/(16/CELL)));
    stack[-1] = v0393;
    if (!(v0393 == nil)) goto v0018;
    v0393 = qvalue(elt(env, 1)); /* headhisto */
    v0393 = sub1(v0393);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0393; /* headhisto */
    goto v0318;

v0018:
    v0393 = stack[-1];
    if (v0393 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0393 = stack[-1];
    v0393 = ncons(v0393);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0393; /* psi */
    v0393 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v0393; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v0394 = qvalue(elt(env, 7)); /* maxvar */
    v0393 = stack[-1];
    v0393 = plus2(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-2];
    v0434 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0393/(16/CELL)));
    v0394 = (Lisp_Object)1; /* 0 */
    v0393 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0434 + (CELL-TAG_VECTOR) + ((int32_t)v0394/(16/CELL))) = v0393;
    v0394 = stack[-1];
    v0393 = qvalue(elt(env, 8)); /* rcoccup */
    v0393 = cons(v0394, v0393);
    nil = C_nil;
    if (exception_pending()) goto v0215;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0393; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0215:
    popv(3);
    return nil;
}



/* Code for evinsert */

static Lisp_Object MS_CDECL CC_evinsert(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0314, Lisp_Object v0150, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0426, v0432, v0433;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "evinsert");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evinsert");
#endif
    if (stack >= stacklimit)
    {
        push4(v0150,v0314,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0314,v0150);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0150;
    stack[-1] = v0314;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0433 = nil;
    goto v0151;

v0151:
    v0426 = stack[-3];
    if (v0426 == nil) goto v0322;
    v0426 = stack[0];
    v0426 = (v0426 == nil ? lisp_true : nil);
    goto v0321;

v0321:
    if (v0426 == nil) goto v0422;
    v0426 = v0433;
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0426);
    }

v0422:
    v0426 = stack[0];
    v0432 = qcar(v0426);
    v0426 = stack[-2];
    if (equal(v0432, v0426)) goto v0341;
    v0426 = stack[-3];
    v0426 = qcar(v0426);
    v0432 = v0433;
    v0426 = cons(v0426, v0432);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    v0433 = v0426;
    v0426 = stack[-3];
    v0426 = qcdr(v0426);
    stack[-3] = v0426;
    v0426 = stack[0];
    v0426 = qcdr(v0426);
    stack[0] = v0426;
    goto v0151;

v0341:
    stack[0] = v0433;
    v0432 = stack[-1];
    v0426 = stack[-3];
    v0426 = qcdr(v0426);
    v0426 = cons(v0432, v0426);
    nil = C_nil;
    if (exception_pending()) goto v0393;
    env = stack[-4];
    {
        Lisp_Object v0394 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0394, v0426);
    }

v0322:
    v0426 = qvalue(elt(env, 1)); /* t */
    goto v0321;
/* error exit handlers */
v0393:
    popv(5);
    return nil;
}



/* Code for xpartitop */

static Lisp_Object CC_xpartitop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitop");
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
    v0018 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* xpartitsq */
        return (*qfn1(fn))(qenv(fn), v0018);
    }
/* error exit handlers */
v0010:
    popv(1);
    return nil;
}



/* Code for listpri */

static Lisp_Object CC_listpri(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0210, v0529;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listpri");
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
    v0210 = stack[-2];
    stack[0] = v0210;
    v0210 = stack[-2];
    v0210 = qcdr(v0210);
    stack[-2] = v0210;
    v0529 = elt(env, 1); /* !*lcbkt!* */
    v0210 = elt(env, 2); /* prtch */
    v0210 = get(v0529, v0210);
    env = stack[-4];
    fn = elt(env, 10); /* prin2!* */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0210 = qvalue(elt(env, 3)); /* orig!* */
    stack[-3] = v0210;
    v0529 = qvalue(elt(env, 4)); /* posn!* */
    v0210 = (Lisp_Object)289; /* 18 */
    v0210 = (Lisp_Object)lessp2(v0529, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    v0210 = v0210 ? lisp_true : nil;
    env = stack[-4];
    if (v0210 == nil) goto v0418;
    v0210 = qvalue(elt(env, 4)); /* posn!* */
    goto v0420;

v0420:
    qvalue(elt(env, 3)) = v0210; /* orig!* */
    v0210 = stack[-2];
    if (v0210 == nil) goto v0212;
    v0529 = stack[-2];
    v0210 = (Lisp_Object)641; /* 40 */
    fn = elt(env, 11); /* treesizep1 */
    v0529 = (*qfn2(fn))(qenv(fn), v0529, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0210 = (Lisp_Object)1; /* 0 */
    v0210 = (v0529 == v0210 ? lisp_true : nil);
    stack[-1] = v0210;
    goto v0502;

v0502:
    v0210 = stack[-2];
    v0529 = qcar(v0210);
    v0210 = elt(env, 5); /* minus */
    if (!consp(v0529)) goto v0225;
    v0529 = qcar(v0529);
    if (!(v0529 == v0210)) goto v0225;
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    v0210 = (is_number(v0210) ? lisp_true : nil);
    goto v0338;

v0338:
    if (v0210 == nil) goto v0429;
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0210 = qcdr(v0210);
    v0210 = qcar(v0210);
    v0210 = negate(v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0529 = v0210;
    goto v0433;

v0433:
    v0210 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 12); /* maprint */
    v0210 = (*qfn2(fn))(qenv(fn), v0529, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0210 = stack[-2];
    v0210 = qcdr(v0210);
    stack[-2] = v0210;
    v0210 = stack[-2];
    if (v0210 == nil) goto v0212;
    v0210 = elt(env, 7); /* !*comma!* */
    fn = elt(env, 13); /* oprin */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0210 = stack[-1];
    if (v0210 == nil) goto v0502;
    v0210 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 14); /* terpri!* */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    goto v0502;

v0212:
    v0529 = elt(env, 9); /* !*rcbkt!* */
    v0210 = elt(env, 2); /* prtch */
    v0210 = get(v0529, v0210);
    env = stack[-4];
    fn = elt(env, 10); /* prin2!* */
    v0210 = (*qfn1(fn))(qenv(fn), v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    v0210 = stack[-3];
    qvalue(elt(env, 3)) = v0210; /* orig!* */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v0429:
    v0210 = stack[-2];
    v0210 = qcar(v0210);
    v0529 = v0210;
    goto v0433;

v0225:
    v0210 = qvalue(elt(env, 6)); /* nil */
    goto v0338;

v0418:
    v0529 = qvalue(elt(env, 3)); /* orig!* */
    v0210 = (Lisp_Object)49; /* 3 */
    v0210 = plus2(v0529, v0210);
    nil = C_nil;
    if (exception_pending()) goto v0530;
    env = stack[-4];
    goto v0420;
/* error exit handlers */
v0530:
    popv(5);
    return nil;
}



/* Code for numprintlen */

static Lisp_Object CC_numprintlen(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0475, v0361;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numprintlen");
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
    stack[-1] = v0000;
/* end of prologue */

v0004:
    v0475 = stack[-1];
    if (!consp(v0475)) goto v0180;
    v0475 = stack[-1];
    v0475 = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = Lonep(nil, v0475);
    env = stack[-6];
    if (v0475 == nil) goto v0419;
    v0475 = stack[-1];
    v0475 = qcar(v0475);
    stack[-1] = v0475;
    goto v0004;

v0419:
    v0475 = stack[-1];
    v0361 = qcar(v0475);
    v0475 = elt(env, 1); /* !:rd!: */
    if (v0361 == v0475) goto v0232;
    v0475 = stack[-1];
    v0361 = qcar(v0475);
    v0475 = elt(env, 3); /* (!:cr!: !:crn!: !:gi!:) */
    v0475 = Lmemq(nil, v0361, v0475);
    if (v0475 == nil) goto v0192;
    v0361 = elt(env, 1); /* !:rd!: */
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    v0475 = cons(v0361, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0361 = v0475;
    v0475 = v0361;
    v0475 = qcdr(v0475);
    if (!consp(v0475)) goto v0492;
    v0475 = v0361;
    stack[0] = v0475;
    goto v0383;

v0383:
    v0361 = qvalue(elt(env, 2)); /* !:bprec!: */
    v0475 = (Lisp_Object)49; /* 3 */
    v0475 = difference2(v0361, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0361 = elt(env, 1); /* !:rd!: */
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcdr(v0475);
    v0475 = cons(v0361, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0361 = v0475;
    v0475 = v0361;
    v0475 = qcdr(v0475);
    if (!consp(v0475)) goto v0207;
    v0475 = v0361;
    stack[-1] = v0475;
    goto v0546;

v0546:
    v0361 = qvalue(elt(env, 2)); /* !:bprec!: */
    v0475 = (Lisp_Object)49; /* 3 */
    v0475 = difference2(v0361, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v0475 = (*qfn2(fn))(qenv(fn), stack[-1], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = cons(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-1] = v0475;
    stack[-4] = (Lisp_Object)193; /* 12 */
    v0475 = stack[-1];
    v0475 = qcar(v0475);
    v0475 = qcar(v0475);
    stack[-3] = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = stack[-1];
    v0475 = qcar(v0475);
    v0475 = qcdr(v0475);
    v0475 = Lexplode(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-2] = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    stack[0] = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcdr(v0475);
    v0475 = Lexplode(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = plus2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = plus2(stack[-2], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = plus2(stack[-3], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    {
        Lisp_Object v0363 = stack[-4];
        popv(7);
        return plus2(v0363, v0475);
    }

v0207:
    v0475 = v0361;
    v0475 = qcdr(v0475);
    fn = elt(env, 9); /* fl2bf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-1] = v0475;
    goto v0546;

v0492:
    v0475 = v0361;
    v0475 = qcdr(v0475);
    fn = elt(env, 9); /* fl2bf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[0] = v0475;
    goto v0383;

v0192:
    v0475 = stack[-1];
    stack[-5] = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-4] = elt(env, 4); /* plus */
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    stack[-3] = v0475;
    v0475 = stack[-3];
    if (v0475 == nil) goto v0547;
    v0475 = stack[-3];
    v0475 = qcar(v0475);
    v0475 = CC_numprintlen(env, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-1] = v0475;
    stack[-2] = v0475;
    goto v0548;

v0548:
    v0475 = stack[-3];
    v0475 = qcdr(v0475);
    stack[-3] = v0475;
    v0475 = stack[-3];
    if (v0475 == nil) goto v0478;
    stack[0] = stack[-1];
    v0475 = stack[-3];
    v0475 = qcar(v0475);
    v0475 = CC_numprintlen(env, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = ncons(v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = Lrplacd(nil, stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    stack[-1] = v0475;
    goto v0548;

v0478:
    v0475 = stack[-2];
    goto v0371;

v0371:
    v0475 = cons(stack[-4], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 10); /* eval */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    {
        Lisp_Object v0469 = stack[-5];
        popv(7);
        return plus2(v0469, v0475);
    }

v0547:
    v0475 = qvalue(elt(env, 5)); /* nil */
    goto v0371;

v0232:
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    if (!consp(v0475)) goto v0549;
    v0475 = stack[-1];
    stack[0] = v0475;
    goto v0345;

v0345:
    v0361 = qvalue(elt(env, 2)); /* !:bprec!: */
    v0475 = (Lisp_Object)49; /* 3 */
    v0475 = difference2(v0361, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 6); /* round!:mt */
    v0475 = (*qfn2(fn))(qenv(fn), stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 7); /* csl_normbf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    fn = elt(env, 8); /* bfexplode0 */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[-1] = v0475;
    stack[-2] = (Lisp_Object)33; /* 2 */
    v0475 = stack[-1];
    v0475 = qcar(v0475);
    stack[0] = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    v0475 = qcar(v0475);
    v0475 = Lexplode(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = Llength(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    v0475 = plus2(stack[0], v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    {
        Lisp_Object v0468 = stack[-2];
        popv(7);
        return plus2(v0468, v0475);
    }

v0549:
    v0475 = stack[-1];
    v0475 = qcdr(v0475);
    fn = elt(env, 9); /* fl2bf */
    v0475 = (*qfn1(fn))(qenv(fn), v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
    env = stack[-6];
    stack[0] = v0475;
    goto v0345;

v0180:
    v0475 = stack[-1];
    v0475 = Lexplode(nil, v0475);
    nil = C_nil;
    if (exception_pending()) goto v0545;
        popv(7);
        return Llength(nil, v0475);
/* error exit handlers */
v0545:
    popv(7);
    return nil;
}



/* Code for lndepends */

static Lisp_Object CC_lndepends(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0323, v0232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lndepends");
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

v0500:
    v0323 = stack[-1];
    if (v0323 == nil) goto v0018;
    v0323 = stack[-1];
    v0232 = qcar(v0323);
    v0323 = stack[0];
    fn = elt(env, 2); /* ndepends */
    v0323 = (*qfn2(fn))(qenv(fn), v0232, v0323);
    nil = C_nil;
    if (exception_pending()) goto v0341;
    env = stack[-2];
    if (!(v0323 == nil)) { popv(3); return onevalue(v0323); }
    v0323 = stack[-1];
    v0232 = qcdr(v0323);
    v0323 = stack[0];
    stack[-1] = v0232;
    stack[0] = v0323;
    goto v0500;

v0018:
    v0323 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0323); }
/* error exit handlers */
v0341:
    popv(3);
    return nil;
}



/* Code for listquotient */

static Lisp_Object CC_listquotient(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0418, v0421, v0549, v0424;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listquotient");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0549 = v0001;
    v0424 = v0000;
/* end of prologue */
    v0421 = v0549;
    v0418 = (Lisp_Object)17; /* 1 */
    if (v0421 == v0418) return onevalue(v0424);
    v0421 = v0549;
    v0418 = v0424;
    if (equal(v0421, v0418)) goto v0322;
    v0418 = elt(env, 1); /* quotient */
    v0421 = v0424;
    return list3(v0418, v0421, v0549);

v0322:
    v0418 = (Lisp_Object)17; /* 1 */
    return onevalue(v0418);
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0348;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v0348 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v0348 = (*qfn1(fn))(qenv(fn), v0348);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-1];
    v0348 = stack[0];
    v0348 = qcdr(v0348);
    fn = elt(env, 4); /* fs!:prin */
    v0348 = (*qfn1(fn))(qenv(fn), v0348);
    nil = C_nil;
    if (exception_pending()) goto v0329;
    env = stack[-1];
    v0348 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0348);
    }
/* error exit handlers */
v0329:
    popv(2);
    return nil;
}



/* Code for cl_pop */

static Lisp_Object CC_cl_pop(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0150;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0150 = v0000;
/* end of prologue */
    return onevalue(v0150);
}



setup_type const u35_setup[] =
{
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"ofsf_ir2atl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ir2atl},
    {"createtriple",            CC_createtriple,too_many_1,    wrong_no_1},
    {"rl_fvarl",                CC_rl_fvarl,    too_many_1,    wrong_no_1},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"pasf_exprng1",            CC_pasf_exprng1,too_many_1,    wrong_no_1},
    {"intervalom",              CC_intervalom,  too_many_1,    wrong_no_1},
    {"reduceroots",             too_few_2,      CC_reduceroots,wrong_no_2},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"fnreval",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnreval},
    {"sqprla",                  too_few_2,      CC_sqprla,     wrong_no_2},
    {"gfftimes",                too_few_2,      CC_gfftimes,   wrong_no_2},
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"incident1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident1},
    {"negex",                   CC_negex,       too_many_1,    wrong_no_1},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"settreset",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_settreset},
    {"ofsf_evalatp",            too_few_2,      CC_ofsf_evalatp,wrong_no_2},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,too_many_1, wrong_no_1},
    {"aex_subrp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_aex_subrp},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"cr:onep",                 CC_crTonep,     too_many_1,    wrong_no_1},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"evinsert",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evinsert},
    {"xpartitop",               CC_xpartitop,   too_many_1,    wrong_no_1},
    {"listpri",                 CC_listpri,     too_many_1,    wrong_no_1},
    {"numprintlen",             CC_numprintlen, too_many_1,    wrong_no_1},
    {"lndepends",               too_few_2,      CC_lndepends,  wrong_no_2},
    {"listquotient",            too_few_2,      CC_listquotient,wrong_no_2},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"cl_pop",                  CC_cl_pop,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u35", (two_args *)"14327 682348 2758096", 0}
};

/* end of generated code */
