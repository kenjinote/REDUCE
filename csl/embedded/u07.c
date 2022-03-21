
/* $destdir\u07.c        Machine generated C code */

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


/* Code for gsetsugar */

static Lisp_Object CC_gsetsugar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gsetsugar");
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
    v0007 = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0006 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0006 == nil) goto v0008;
    stack[-2] = stack[-1];
    stack[0] = elt(env, 3); /* sugar */
    v0006 = v0007;
    if (!(v0006 == nil)) goto v0009;
    v0006 = stack[-1];
    fn = elt(env, 4); /* vdptdeg */
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    goto v0009;

v0009:
    fn = elt(env, 5); /* vdpputprop */
    v0006 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0006);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    goto v0011;

v0011:
    if (v0006 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else { popv(4); return onevalue(v0006); }

v0008:
    v0006 = qvalue(elt(env, 2)); /* nil */
    goto v0011;
/* error exit handlers */
v0010:
    popv(4);
    return nil;
}



/* Code for domain!*p */

static Lisp_Object CC_domainHp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for domain*p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0014 = v0000;
/* end of prologue */
    v0007 = v0014;
    if (v0007 == nil) goto v0015;
    v0007 = v0014;
    v0007 = (is_number(v0007) ? lisp_true : nil);
    if (!(v0007 == nil)) return onevalue(v0007);
    v0007 = v0014;
    if (!consp(v0007)) goto v0016;
    v0007 = v0014;
    v0007 = qcar(v0007);
    v0014 = qvalue(elt(env, 2)); /* domainlist!* */
    v0007 = Lmemq(nil, v0007, v0014);
    return onevalue(v0007);

v0016:
    v0007 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0007);

v0015:
    v0007 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0007);
}



/* Code for add2resultbuf */

static Lisp_Object CC_add2resultbuf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0028, v0029, v0030;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add2resultbuf");
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
    v0028 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0030 = v0028;
    v0029 = elt(env, 1); /* symbolic */
    if (v0030 == v0029) goto v0031;
    v0029 = stack[0];
    if (v0029 == nil) goto v0016;
    v0029 = qvalue(elt(env, 5)); /* nil */
    goto v0032;

v0032:
    if (v0029 == nil) goto v0033;
    v0029 = qvalue(elt(env, 2)); /* t */
    goto v0034;

v0034:
    if (v0029 == nil) goto v0002;
    v0028 = qvalue(elt(env, 5)); /* nil */
    { popv(2); return onevalue(v0028); }

v0002:
    v0029 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0029 == nil) goto v0035;
    v0030 = elt(env, 7); /* ws */
    v0029 = stack[0];
    fn = elt(env, 13); /* putobject */
    v0028 = (*qfnn(fn))(qenv(fn), 3, v0030, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    goto v0037;

v0037:
    v0028 = qvalue(elt(env, 9)); /* !*int */
    if (v0028 == nil) goto v0038;
    v0028 = qvalue(elt(env, 10)); /* ifl!* */
    if (!(v0028 == nil)) goto v0038;
    v0030 = qvalue(elt(env, 11)); /* statcounter */
    v0029 = stack[0];
    v0028 = qvalue(elt(env, 12)); /* resultbuflis!* */
    v0028 = acons(v0030, v0029, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    qvalue(elt(env, 12)) = v0028; /* resultbuflis!* */
    goto v0038;

v0038:
    v0028 = nil;
    { popv(2); return onevalue(v0028); }

v0035:
    v0028 = qvalue(elt(env, 5)); /* nil */
    v0028 = ncons(v0028);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-1];
    qvalue(elt(env, 8)) = v0028; /* alglist!* */
    v0028 = stack[0];
    qvalue(elt(env, 7)) = v0028; /* ws */
    goto v0037;

v0033:
    v0029 = qvalue(elt(env, 6)); /* !*nosave!* */
    goto v0034;

v0016:
    v0029 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0029 == nil) goto v0039;
    v0030 = v0028;
    v0029 = elt(env, 4); /* empty_list */
    v0029 = (v0030 == v0029 ? lisp_true : nil);
    v0029 = (v0029 == nil ? lisp_true : nil);
    goto v0032;

v0039:
    v0029 = qvalue(elt(env, 2)); /* t */
    goto v0032;

v0031:
    v0029 = qvalue(elt(env, 2)); /* t */
    goto v0034;
/* error exit handlers */
v0036:
    popv(2);
    return nil;
}



/* Code for groeb!=testa */

static Lisp_Object CC_groebMtesta(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testa");
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
    v0012 = v0000;
/* end of prologue */
    v0032 = v0012;
    v0012 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v0012 = (*qfn2(fn))(qenv(fn), v0032, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    stack[-1] = qcar(v0012);
    v0032 = stack[0];
    v0012 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* pnth */
    v0012 = (*qfn2(fn))(qenv(fn), v0032, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-2];
    v0012 = qcar(v0012);
    {
        Lisp_Object v0007 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* mo_divides!? */
        return (*qfn2(fn))(qenv(fn), v0007, v0012);
    }
/* error exit handlers */
v0006:
    popv(3);
    return nil;
}



/* Code for pv_sort2a */

static Lisp_Object CC_pv_sort2a(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0058;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort2a");
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

v0059:
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    if (v0057 == nil) goto v0040;
    v0057 = stack[-1];
    v0058 = qcdr(v0057);
    v0057 = stack[0];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    v0057 = (Lisp_Object)greaterp2(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0057 = v0057 ? lisp_true : nil;
    env = stack[-3];
    if (v0057 == nil) goto v0061;
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    stack[0] = v0057;
    goto v0059;

v0061:
    v0057 = stack[0];
    v0058 = qcar(v0057);
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[-2] = v0057;
    v0058 = stack[0];
    v0057 = stack[-1];
    v0058 = Lrplaca(nil, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0057 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0058, v0057);

v0040:
    v0057 = stack[-1];
    v0058 = qcdr(v0057);
    v0057 = stack[0];
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    v0057 = (Lisp_Object)greaterp2(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0057 = v0057 ? lisp_true : nil;
    env = stack[-3];
    if (v0057 == nil) goto v0062;
    v0057 = stack[-1];
    v0057 = ncons(v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    {
        Lisp_Object v0063 = stack[0];
        popv(4);
        return Lrplacd(nil, v0063, v0057);
    }

v0062:
    v0057 = stack[0];
    v0058 = qcar(v0057);
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = cons(v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[-2] = v0057;
    v0058 = stack[0];
    v0057 = stack[-1];
    v0058 = Lrplaca(nil, v0058, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0057 = stack[-2];
        popv(4);
        return Lrplacd(nil, v0058, v0057);
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for ordn */

static Lisp_Object CC_ordn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordn");
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
    v0022 = stack[0];
    if (v0022 == nil) goto v0015;
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    if (v0022 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = qcdr(v0022);
    if (v0022 == nil) goto v0003;
    v0022 = stack[0];
    stack[-1] = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = CC_ordn(env, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-2];
    {
        Lisp_Object v0071 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ordad */
        return (*qfn2(fn))(qenv(fn), v0071, v0022);
    }

v0003:
    v0022 = stack[0];
    v0020 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    fn = elt(env, 3); /* ordp */
    v0022 = (*qfn2(fn))(qenv(fn), v0020, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    if (v0022 == nil) goto v0056;
    v0022 = stack[0];
    v0020 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    popv(3);
    return list2(v0020, v0022);

v0056:
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    v0020 = qcar(v0022);
    v0022 = stack[0];
    v0022 = qcar(v0022);
    popv(3);
    return list2(v0020, v0022);

v0015:
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0022); }
/* error exit handlers */
v0070:
    popv(3);
    return nil;
}



/* Code for undefdchk */

static Lisp_Object CC_undefdchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0003, v0004;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for undefdchk");
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
    v0003 = v0000;
/* end of prologue */
    v0004 = v0003;
    v0005 = elt(env, 1); /* defd */
    v0005 = Lflagp(nil, v0004, v0005);
    env = stack[0];
    if (v0005 == nil) goto v0040;
    v0005 = nil;
    { popv(1); return onevalue(v0005); }

v0040:
    v0005 = qvalue(elt(env, 2)); /* undefns!* */
    v0005 = cons(v0003, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[0];
    qvalue(elt(env, 2)) = v0005; /* undefns!* */
    { popv(1); return onevalue(v0005); }
/* error exit handlers */
v0041:
    popv(1);
    return nil;
}



/* Code for polynomadd */

static Lisp_Object CC_polynomadd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0090, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynomadd");
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
    v0090 = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0089 = stack[-2];
    stack[-3] = v0089;
    v0089 = v0090;
    stack[-1] = v0089;
    goto v0074;

v0074:
    v0089 = stack[-3];
    v0089 = qcar(v0089);
    if (v0089 == nil) goto v0073;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    if (v0089 == nil) goto v0073;
    v0089 = stack[-3];
    v0090 = qcar(v0089);
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    fn = elt(env, 2); /* monomcompare */
    v0089 = (*qfn2(fn))(qenv(fn), v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0091 = v0089;
    v0090 = v0091;
    v0089 = (Lisp_Object)17; /* 1 */
    if (v0090 == v0089) goto v0093;
    v0090 = v0091;
    v0089 = (Lisp_Object)-15; /* -1 */
    if (v0090 == v0089) goto v0094;
    v0090 = stack[-3];
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    v0090 = Lrplaca(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0089 = Lrplacd(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0074;

v0094:
    stack[0] = stack[-3];
    v0089 = stack[-3];
    v0090 = qcar(v0089);
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    v0089 = cons(v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0090 = Lrplacd(nil, stack[0], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0089 = Lrplaca(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    stack[-3] = v0089;
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0074;

v0093:
    v0089 = stack[-3];
    v0089 = qcdr(v0089);
    stack[-3] = v0089;
    goto v0074;

v0073:
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    if (v0089 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0090 = stack[-3];
    v0089 = stack[-1];
    v0089 = Lrplacd(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    stack[0] = v0089;
    v0090 = stack[0];
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    v0089 = qcar(v0089);
    v0090 = Lrplaca(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-4];
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    v0089 = qcdr(v0089);
    v0089 = Lrplacd(nil, v0090, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v0092:
    popv(5);
    return nil;
}



/* Code for cl_apply2ats */

static Lisp_Object CC_cl_apply2ats(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0042, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0095 = v0001;
    v0042 = v0000;
/* end of prologue */
    v0043 = v0042;
    v0042 = v0095;
    v0095 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0043, v0042, v0095);
    }
}



/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0096, Lisp_Object v0082, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg2");
#endif
    if (stack >= stacklimit)
    {
        push4(v0082,v0096,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0096,v0082);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v0082;
    stack[-7] = v0096;
    stack[-8] = v0001;
    stack[-9] = v0000;
/* end of prologue */
    v0107 = stack[-9];
    if (v0107 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v0107 = stack[-9];
    v0108 = qcar(v0107);
    v0107 = stack[-8];
    v0107 = qcar(v0107);
    fn = elt(env, 2); /* mchk */
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0108 = v0107;
    v0107 = stack[-9];
    v0107 = qcdr(v0107);
    stack[-9] = v0107;
    v0107 = stack[-8];
    v0107 = qcdr(v0107);
    stack[-8] = v0107;
    v0107 = v0108;
    stack[-10] = v0107;
    goto v0014;

v0014:
    v0107 = stack[-10];
    if (v0107 == nil) goto v0110;
    v0107 = stack[-10];
    v0107 = qcar(v0107);
    stack[-2] = v0107;
    stack[-1] = stack[-9];
    v0109 = stack[-2];
    v0108 = stack[-8];
    v0107 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0108 = stack[-7];
    v0107 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0108 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0107 = stack[-6];
    v0107 = CC_mcharg2(env, 4, stack[-1], stack[0], v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    stack[-5] = v0107;
    v0107 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    stack[-4] = v0107;
    v0107 = stack[-10];
    v0107 = qcdr(v0107);
    stack[-10] = v0107;
    v0107 = stack[-4];
    if (!consp(v0107)) goto v0014;
    else goto v0039;

v0039:
    v0107 = stack[-10];
    if (v0107 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v0107 = stack[-10];
    v0107 = qcar(v0107);
    stack[-2] = v0107;
    stack[-1] = stack[-9];
    v0109 = stack[-2];
    v0108 = stack[-8];
    v0107 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v0109, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0108 = stack[-7];
    v0107 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v0108 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0107 = stack[-6];
    v0107 = CC_mcharg2(env, 4, stack[-1], stack[0], v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0107 = Lrplacd(nil, stack[-3], v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    v0107 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-11];
    stack[-4] = v0107;
    v0107 = stack[-10];
    v0107 = qcdr(v0107);
    stack[-10] = v0107;
    goto v0039;

v0110:
    v0107 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v0107); }
/* error exit handlers */
v0090:
    popv(12);
    return nil;
}



/* Code for mri_pasf2mriat */

static Lisp_Object CC_mri_pasf2mriat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0026, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_pasf2mriat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0001;
    v0026 = v0000;
/* end of prologue */
    v0027 = v0026;
    v0027 = qcar(v0027);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0027, v0026, v0040);
    }
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0021, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt1");
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
    v0035 = v0000;
/* end of prologue */
    v0021 = v0035;
    v0020 = (Lisp_Object)1; /* 0 */
    if (v0021 == v0020) goto v0031;
    v0021 = v0035;
    v0020 = (Lisp_Object)17; /* 1 */
    v0020 = (v0021 == v0020 ? lisp_true : nil);
    goto v0034;

v0034:
    if (v0020 == nil) goto v0002;
    v0020 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0020); }

v0002:
    v0020 = v0035;
    if (symbolp(v0020)) goto v0110;
    v0020 = v0035;
    fn = elt(env, 3); /* ibalp_argn */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    stack[-1] = v0020;
    goto v0053;

v0053:
    v0020 = stack[-1];
    if (v0020 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    v0021 = v0020;
    v0020 = stack[0];
    v0020 = CC_ibalp_varlt1(env, v0021, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-2];
    stack[0] = v0020;
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    goto v0053;

v0110:
    v0021 = v0035;
    v0020 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v0021, v0020);
    }

v0031:
    v0020 = qvalue(elt(env, 1)); /* t */
    goto v0034;
/* error exit handlers */
v0050:
    popv(3);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checktag");
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
    v0003 = v0000;
/* end of prologue */
    v0004 = qvalue(elt(env, 1)); /* char */
    if (equal(v0004, v0003)) goto v0059;
    v0004 = elt(env, 2); /* "Problem" */
    v0003 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v0003 = (*qfn2(fn))(qenv(fn), v0004, v0003);
    errexit();
    goto v0059;

v0059:
    v0003 = nil;
    return onevalue(v0003);
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0195, v0196, v0197, v0198, v0199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval1");
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
    v0195 = qvalue(elt(env, 1)); /* !*revalp */
    if (v0195 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0195 = qvalue(elt(env, 2)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0195; /* varstack!* */
    v0195 = stack[-2];
    if (v0195 == nil) goto v0027;
    v0195 = stack[-2];
    v0195 = Lstringp(nil, v0195);
    env = stack[-4];
    if (v0195 == nil) goto v0004;
    v0195 = stack[-2];
    goto v0043;

v0043:
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v0195); }

v0004:
    v0195 = stack[-2];
    v0195 = integerp(v0195);
    if (v0195 == nil) goto v0016;
    v0196 = qvalue(elt(env, 4)); /* dmode!* */
    v0195 = elt(env, 5); /* convert */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    if (v0195 == nil) goto v0200;
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0200:
    v0195 = stack[-2];
    goto v0043;

v0016:
    v0195 = stack[-2];
    if (!consp(v0195)) goto v0052;
    v0195 = stack[-2];
    v0195 = qcar(v0195);
    if (symbolp(v0195)) goto v0202;
    v0199 = elt(env, 11); /* "Syntax error:" */
    v0198 = stack[-2];
    v0197 = elt(env, 12); /* "invalid" */
    v0196 = qvalue(elt(env, 3)); /* nil */
    v0195 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 32); /* msgpri */
    v0195 = (*qfnn(fn))(qenv(fn), 5, v0199, v0198, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0026;

v0026:
    v0195 = stack[-2];
    fn = elt(env, 33); /* getrtype */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[0] = v0195;
    if (v0195 == nil) goto v0203;
    v0196 = stack[0];
    v0195 = elt(env, 10); /* evfn */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    v0197 = v0195;
    if (v0195 == nil) goto v0204;
    v0196 = stack[-2];
    v0195 = stack[-1];
    v0195 = Lapply2(nil, 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0204:
    v0196 = elt(env, 21); /* "Missing evaluation for type" */
    v0195 = stack[0];
    v0195 = list2(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0196 = v0195;
    v0195 = v0196;
    qvalue(elt(env, 22)) = v0195; /* errmsg!* */
    v0195 = qvalue(elt(env, 23)); /* !*protfg */
    if (!(v0195 == nil)) goto v0205;
    v0195 = v0196;
    fn = elt(env, 34); /* lprie */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0205;

v0205:
    v0195 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0195 = nil;
    goto v0043;

v0203:
    v0195 = stack[-2];
    if (!consp(v0195)) goto v0206;
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    if (!consp(v0195)) goto v0207;
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    fn = elt(env, 33); /* getrtype */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0197 = v0195;
    if (v0195 == nil) goto v0208;
    v0196 = v0197;
    v0195 = elt(env, 24); /* list */
    if (v0196 == v0195) goto v0209;
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0210;

v0210:
    if (v0195 == nil) goto v0211;
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0212:
    if (v0195 == nil) goto v0213;
    v0197 = stack[0];
    v0196 = stack[-2];
    v0195 = stack[-1];
    v0195 = Lapply2(nil, 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0213:
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0211:
    v0196 = v0197;
    v0195 = elt(env, 25); /* aggregatefn */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    stack[0] = v0195;
    if (v0195 == nil) goto v0214;
    v0196 = stack[0];
    v0195 = elt(env, 26); /* matrixmap */
    if (v0196 == v0195) goto v0215;
    v0195 = qvalue(elt(env, 9)); /* t */
    goto v0216;

v0216:
    if (v0195 == nil) goto v0217;
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 28); /* boolean */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    if (v0195 == nil) goto v0218;
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0218:
    v0195 = qvalue(elt(env, 29)); /* !*listargs */
    if (v0195 == nil) goto v0219;
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0219:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 30); /* listargp */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    v0195 = (v0195 == nil ? lisp_true : nil);
    goto v0212;

v0217:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0215:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 27); /* matmapfn */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    goto v0216;

v0214:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0209:
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    goto v0210;

v0208:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0207:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0206:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0212;

v0202:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 13); /* !*sq */
    if (v0196 == v0195) goto v0220;
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 15); /* remember */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    if (v0195 == nil) goto v0221;
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 35); /* rmmbreval */
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0221:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 16); /* opfn */
    v0195 = Lflagp(nil, v0196, v0195);
    env = stack[-4];
    if (v0195 == nil) goto v0222;
    v0195 = stack[-2];
    fn = elt(env, 36); /* opfneval */
    v0196 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0195 = stack[-1];
    v0195 = CC_reval1(env, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0222:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 17); /* psopfn */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    stack[0] = v0195;
    if (v0195 == nil) goto v0223;
    v0196 = stack[0];
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    v0195 = Lapply1(nil, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-2] = v0195;
    v0196 = stack[0];
    v0195 = elt(env, 18); /* cleanupfn */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    stack[0] = v0195;
    if (v0195 == nil) goto v0224;
    v0197 = stack[0];
    v0196 = stack[-2];
    v0195 = stack[-1];
    v0195 = Lapply2(nil, 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    stack[-2] = v0195;
    goto v0224;

v0224:
    v0195 = stack[-2];
    goto v0043;

v0223:
    v0195 = stack[-2];
    v0196 = qcar(v0195);
    v0195 = elt(env, 19); /* rtype */
    v0196 = get(v0196, v0195);
    env = stack[-4];
    v0195 = elt(env, 20); /* array */
    if (!(v0196 == v0195)) goto v0026;
    v0195 = stack[-2];
    fn = elt(env, 37); /* getelv */
    v0196 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    v0195 = stack[-1];
    v0195 = CC_reval1(env, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0220:
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    if (v0195 == nil) goto v0225;
    v0195 = qvalue(elt(env, 14)); /* !*resimp */
    if (!(v0195 == nil)) goto v0225;
    v0195 = stack[-1];
    if (v0195 == nil) goto v0226;
    v0195 = stack[-2];
    v0195 = qcdr(v0195);
    v0195 = qcar(v0195);
    fn = elt(env, 38); /* prepsqxx */
    v0195 = (*qfn1(fn))(qenv(fn), v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0226:
    v0195 = stack[-2];
    goto v0043;

v0225:
    v0196 = stack[-2];
    v0195 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v0195 = (*qfn2(fn))(qenv(fn), v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0052:
    v0195 = qvalue(elt(env, 6)); /* subfg!* */
    if (v0195 == nil) goto v0227;
    v0195 = stack[-2];
    if (!(symbolp(v0195))) goto v0026;
    v0196 = stack[-2];
    v0195 = elt(env, 7); /* avalue */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    stack[0] = v0195;
    if (v0195 == nil) goto v0026;
    v0196 = stack[-2];
    v0195 = qvalue(elt(env, 2)); /* varstack!* */
    v0195 = Lmemq(nil, v0196, v0195);
    if (v0195 == nil) goto v0228;
    v0199 = qvalue(elt(env, 3)); /* nil */
    v0198 = stack[-2];
    v0197 = elt(env, 8); /* "improperly defined in terms of itself" */
    v0196 = qvalue(elt(env, 3)); /* nil */
    v0195 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 32); /* msgpri */
    v0195 = (*qfnn(fn))(qenv(fn), 5, v0199, v0198, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0026;

v0228:
    v0196 = stack[-2];
    v0195 = qvalue(elt(env, 2)); /* varstack!* */
    v0195 = cons(v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0195; /* varstack!* */
    v0195 = stack[0];
    v0196 = qcar(v0195);
    v0195 = elt(env, 10); /* evfn */
    v0195 = get(v0196, v0195);
    env = stack[-4];
    v0197 = v0195;
    if (v0195 == nil) goto v0079;
    v0196 = stack[-2];
    v0195 = stack[-1];
    v0195 = Lapply2(nil, 3, v0197, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0079:
    v0195 = stack[0];
    v0195 = qcdr(v0195);
    v0196 = qcar(v0195);
    v0195 = stack[-1];
    v0195 = CC_reval1(env, v0196, v0195);
    nil = C_nil;
    if (exception_pending()) goto v0201;
    env = stack[-4];
    goto v0043;

v0227:
    v0195 = stack[-2];
    goto v0043;

v0027:
    v0195 = qvalue(elt(env, 3)); /* nil */
    goto v0043;
/* error exit handlers */
v0201:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109, v0185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk2");
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

v0002:
    v0108 = stack[-1];
    if (v0108 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-2] = v0108;
    v0108 = qvalue(elt(env, 1)); /* !*intstr */
    if (v0108 == nil) goto v0013;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    fn = elt(env, 8); /* prepsq!* */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    goto v0066;

v0066:
    v0185 = v0108;
    v0109 = (Lisp_Object)17; /* 1 */
    if (v0185 == v0109) goto v0067;
    v0109 = qvalue(elt(env, 3)); /* !*nosqrts */
    if (v0109 == nil) goto v0236;
    v0185 = elt(env, 4); /* expt */
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0109 = qcar(v0109);
    v0108 = list3(v0185, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0109 = v0108;
    goto v0009;

v0009:
    v0108 = stack[0];
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    stack[0] = v0108;
    v0108 = stack[-2];
    stack[-1] = v0108;
    goto v0002;

v0236:
    v0185 = v0108;
    v0109 = elt(env, 5); /* (quotient 1 2) */
    if (equal(v0185, v0109)) goto v0237;
    v0185 = v0108;
    v0109 = elt(env, 7); /* 0.5 */
    if (equal(v0185, v0109)) goto v0100;
    v0185 = elt(env, 4); /* expt */
    v0109 = stack[-1];
    v0109 = qcar(v0109);
    v0109 = qcar(v0109);
    v0108 = list3(v0185, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0109 = v0108;
    goto v0009;

v0100:
    v0109 = elt(env, 6); /* sqrt */
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = list2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0109 = v0108;
    goto v0009;

v0237:
    v0109 = elt(env, 6); /* sqrt */
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0108 = list2(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    v0109 = v0108;
    goto v0009;

v0067:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcar(v0108);
    v0109 = v0108;
    goto v0009;

v0013:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = qcar(v0108);
    if (v0108 == nil) goto v0007;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0109 = qcdr(v0108);
    v0108 = elt(env, 2); /* prepf */
    fn = elt(env, 9); /* sqform */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-3];
    goto v0066;

v0007:
    v0108 = (Lisp_Object)1; /* 0 */
    goto v0066;
/* error exit handlers */
v0079:
    popv(4);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0088, v0024;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v0088 = nil;
    goto v0002;

v0002:
    v0068 = stack[0];
    if (v0068 == nil) goto v0011;
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = cons(v0068, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-1];
    v0088 = v0068;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0002;

v0011:
    v0068 = (Lisp_Object)1; /* 0 */
    goto v0008;

v0008:
    v0024 = v0088;
    if (v0024 == nil) { popv(2); return onevalue(v0068); }
    v0024 = v0088;
    v0024 = qcar(v0024);
    v0068 = (Lisp_Object)(int32_t)((int32_t)v0024 + (int32_t)v0068 - TAG_FIXNUM);
    v0088 = qcdr(v0088);
    goto v0008;
/* error exit handlers */
v0056:
    popv(2);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype");
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
    v0100 = stack[0];
    fn = elt(env, 9); /* physopp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    if (v0100 == nil) goto v0008;
    v0100 = stack[0];
    fn = elt(env, 10); /* scalopp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    if (v0100 == nil) goto v0095;
    v0100 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v0100); }

v0095:
    v0100 = stack[0];
    fn = elt(env, 11); /* vecopp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    if (v0100 == nil) goto v0027;
    v0100 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v0100); }

v0027:
    v0100 = stack[0];
    fn = elt(env, 12); /* tensopp */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    if (v0100 == nil) goto v0004;
    v0100 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v0100); }

v0004:
    v0100 = stack[0];
    fn = elt(env, 13); /* statep */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    if (v0100 == nil) goto v0014;
    v0100 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0100); }

v0014:
    v0100 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0100); }

v0008:
    v0100 = stack[0];
    if (!consp(v0100)) goto v0010;
    v0100 = stack[0];
    v0060 = qcar(v0100);
    v0100 = elt(env, 6); /* phystype */
    v0060 = get(v0060, v0100);
    env = stack[-2];
    v0100 = v0060;
    if (!(v0060 == nil)) { popv(3); return onevalue(v0100); }
    v0100 = stack[0];
    v0060 = qcar(v0100);
    v0100 = elt(env, 7); /* phystypefn */
    v0060 = get(v0060, v0100);
    env = stack[-2];
    v0100 = v0060;
    if (v0060 == nil) goto v0033;
    v0060 = v0100;
    v0100 = stack[0];
    v0100 = qcdr(v0100);
        popv(3);
        return Lapply1(nil, v0060, v0100);

v0033:
    v0100 = stack[0];
    fn = elt(env, 14); /* collectphystype */
    v0060 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    v0100 = v0060;
    if (v0060 == nil) goto v0021;
    v0060 = v0100;
    v0060 = qcdr(v0060);
    if (v0060 == nil) goto v0234;
    v0060 = elt(env, 4); /* state */
    v0100 = Lmember(nil, v0060, v0100);
    if (v0100 == nil) goto v0028;
    v0100 = elt(env, 4); /* state */
    { popv(3); return onevalue(v0100); }

v0028:
    stack[-1] = elt(env, 0); /* getphystype */
    v0060 = elt(env, 8); /* "PHYSOP type conflict in" */
    v0100 = stack[0];
    v0100 = list2(v0060, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0188;
    env = stack[-2];
    {
        Lisp_Object v0184 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v0184, v0100);
    }

v0234:
    v0100 = qcar(v0100);
    { popv(3); return onevalue(v0100); }

v0021:
    v0100 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0100); }

v0010:
    v0100 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v0100); }
/* error exit handlers */
v0188:
    popv(3);
    return nil;
}



/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0243, v0230, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form");
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
    v0230 = v0000;
/* end of prologue */
    v0243 = v0230;
    if (!consp(v0243)) goto v0009;
    v0243 = v0230;
    v0075 = qcar(v0243);
    v0243 = elt(env, 1); /* always_nform */
    v0243 = Lflagp(nil, v0075, v0243);
    env = stack[0];
    goto v0011;

v0011:
    if (v0243 == nil) goto v0059;
    v0243 = v0230;
    {
        popv(1);
        fn = elt(env, 11); /* n_form */
        return (*qfn1(fn))(qenv(fn), v0243);
    }

v0059:
    v0243 = qvalue(elt(env, 3)); /* !*rlisp88 */
    if (v0243 == nil) goto v0016;
    v0075 = qvalue(elt(env, 5)); /* !*mode */
    v0243 = elt(env, 6); /* symbolic */
    if (v0075 == v0243) goto v0084;
    v0243 = qvalue(elt(env, 7)); /* t */
    goto v0194;

v0194:
    if (v0243 == nil) goto v0105;
    v0230 = elt(env, 9); /* "algebraic expression" */
    v0243 = elt(env, 10); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 12); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0230, v0243);
    }

v0105:
    v0075 = v0230;
    v0230 = qvalue(elt(env, 4)); /* !*vars!* */
    v0243 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v0075, v0230, v0243);
    }

v0084:
    v0075 = v0230;
    v0243 = elt(env, 8); /* modefn */
    v0243 = Lflagp(nil, v0075, v0243);
    env = stack[0];
    if (v0243 == nil) goto v0086;
    v0075 = v0230;
    v0243 = elt(env, 6); /* symbolic */
    v0243 = (v0075 == v0243 ? lisp_true : nil);
    v0243 = (v0243 == nil ? lisp_true : nil);
    goto v0227;

v0227:
    if (v0243 == nil) goto v0045;
    v0243 = qvalue(elt(env, 7)); /* t */
    goto v0194;

v0045:
    v0075 = v0230;
    v0243 = elt(env, 8); /* modefn */
    v0243 = Lflagpcar(nil, v0075, v0243);
    env = stack[0];
    if (v0243 == nil) goto v0048;
    v0243 = v0230;
    v0075 = qcar(v0243);
    v0243 = elt(env, 6); /* symbolic */
    v0243 = (v0075 == v0243 ? lisp_true : nil);
    v0243 = (v0243 == nil ? lisp_true : nil);
    goto v0194;

v0048:
    v0243 = qvalue(elt(env, 2)); /* nil */
    goto v0194;

v0086:
    v0243 = qvalue(elt(env, 2)); /* nil */
    goto v0227;

v0016:
    v0075 = v0230;
    v0230 = qvalue(elt(env, 4)); /* !*vars!* */
    v0243 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v0075, v0230, v0243);
    }

v0009:
    v0243 = qvalue(elt(env, 2)); /* nil */
    goto v0011;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v0072 = stack[0];
    if (v0072 == nil) goto v0015;
    v0072 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    v0072 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v0072 = (*qfn1(fn))(qenv(fn), v0072);
    nil = C_nil;
    if (exception_pending()) goto v0004;
    {
        Lisp_Object v0041 = stack[-1];
        popv(3);
        return difference2(v0041, v0072);
    }

v0015:
    v0072 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v0072); }
/* error exit handlers */
v0004:
    popv(3);
    return nil;
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0096)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v0096,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0096);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0266 = v0096;
    stack[-3] = v0001;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v0266; /* p!*!* */
    stack[0] = nil;
    v0266 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v0266;
    v0266 = stack[-3];
    if (v0266 == nil) goto v0043;
    v0266 = stack[-3];
    if (!consp(v0266)) goto v0009;
    v0266 = stack[-3];
    v0266 = qcar(v0266);
    if (!consp(v0266)) goto v0044;
    v0266 = stack[-3];
    v0159 = qcar(v0266);
    v0266 = stack[-2];
    v0266 = CC_maprint(env, v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0042;

v0042:
    v0266 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 13)) = v0266; /* obrkp!* */
    v0266 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v0266;
    v0159 = qvalue(elt(env, 12)); /* posn!* */
    v0266 = (Lisp_Object)289; /* 18 */
    v0266 = (Lisp_Object)lessp2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-5];
    if (v0266 == nil) goto v0166;
    v0266 = qvalue(elt(env, 12)); /* posn!* */
    goto v0268;

v0268:
    qvalue(elt(env, 11)) = v0266; /* orig!* */
    v0266 = stack[-3];
    v0266 = qcdr(v0266);
    if (v0266 == nil) goto v0269;
    v0160 = elt(env, 14); /* !*comma!* */
    v0159 = (Lisp_Object)1; /* 0 */
    v0266 = stack[-3];
    v0266 = qcdr(v0266);
    fn = elt(env, 16); /* inprint */
    v0266 = (*qfnn(fn))(qenv(fn), 3, v0160, v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0269;

v0269:
    v0266 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 13)) = v0266; /* obrkp!* */
    v0266 = stack[0];
    qvalue(elt(env, 11)) = v0266; /* orig!* */
    v0266 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = stack[-3];
    goto v0002;

v0002:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v0266); }

v0166:
    v0159 = qvalue(elt(env, 11)); /* orig!* */
    v0266 = (Lisp_Object)49; /* 3 */
    v0266 = plus2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0268;

v0044:
    v0266 = stack[-3];
    v0159 = qcar(v0266);
    v0266 = elt(env, 8); /* pprifn */
    v0266 = get(v0159, v0266);
    env = stack[-5];
    stack[-1] = v0266;
    if (v0266 == nil) goto v0229;
    v0160 = stack[-1];
    v0159 = stack[-3];
    v0266 = stack[-2];
    v0159 = Lapply2(nil, 3, v0160, v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = elt(env, 9); /* failed */
    if (!(v0159 == v0266)) goto v0036;

v0229:
    v0266 = stack[-3];
    v0159 = qcar(v0266);
    v0266 = elt(env, 10); /* prifn */
    v0266 = get(v0159, v0266);
    env = stack[-5];
    stack[-1] = v0266;
    if (v0266 == nil) goto v0270;
    v0159 = stack[-1];
    v0266 = stack[-3];
    v0159 = Lapply1(nil, v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = elt(env, 9); /* failed */
    if (!(v0159 == v0266)) goto v0036;

v0270:
    v0266 = stack[-3];
    v0159 = qcar(v0266);
    v0266 = elt(env, 5); /* infix */
    v0266 = get(v0159, v0266);
    env = stack[-5];
    stack[-1] = v0266;
    if (v0266 == nil) goto v0271;
    v0159 = stack[-1];
    v0266 = stack[-2];
    v0266 = (Lisp_Object)greaterp2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-5];
    v0266 = (v0266 == nil ? lisp_true : nil);
    stack[-2] = v0266;
    v0266 = stack[-2];
    if (v0266 == nil) goto v0272;
    v0266 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v0266;
    v0266 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0159 = qvalue(elt(env, 12)); /* posn!* */
    v0266 = (Lisp_Object)289; /* 18 */
    v0266 = (Lisp_Object)lessp2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-5];
    if (v0266 == nil) goto v0273;
    v0266 = qvalue(elt(env, 12)); /* posn!* */
    goto v0274;

v0274:
    qvalue(elt(env, 11)) = v0266; /* orig!* */
    goto v0272;

v0272:
    v0266 = stack[-3];
    v0160 = qcar(v0266);
    v0159 = stack[-1];
    v0266 = stack[-3];
    v0266 = qcdr(v0266);
    fn = elt(env, 16); /* inprint */
    v0266 = (*qfnn(fn))(qenv(fn), 3, v0160, v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = stack[-2];
    if (v0266 == nil) goto v0275;
    v0266 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = stack[0];
    qvalue(elt(env, 11)) = v0266; /* orig!* */
    goto v0275;

v0275:
    v0266 = stack[-3];
    goto v0002;

v0273:
    v0159 = qvalue(elt(env, 11)); /* orig!* */
    v0266 = (Lisp_Object)49; /* 3 */
    v0266 = plus2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0274;

v0271:
    v0266 = stack[-3];
    v0266 = qcar(v0266);
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0042;

v0036:
    v0266 = stack[-3];
    goto v0002;

v0009:
    v0266 = stack[-3];
    v0266 = Lsimple_vectorp(nil, v0266);
    env = stack[-5];
    if (v0266 == nil) goto v0013;
    v0159 = stack[-3];
    v0266 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 17); /* vec!-maprin */
    v0266 = (*qfn2(fn))(qenv(fn), v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0004;

v0004:
    v0266 = stack[-3];
    goto v0002;

v0013:
    v0266 = stack[-3];
    if (is_number(v0266)) goto v0200;
    v0266 = qvalue(elt(env, 3)); /* t */
    goto v0069;

v0069:
    if (v0266 == nil) goto v0038;
    v0266 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0004;

v0038:
    v0266 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    v0266 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[-5];
    goto v0004;

v0200:
    v0159 = stack[-3];
    v0266 = (Lisp_Object)1; /* 0 */
    v0266 = (Lisp_Object)lessp2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-5];
    if (v0266 == nil) goto v0235;
    v0160 = stack[-2];
    v0159 = elt(env, 4); /* minus */
    v0266 = elt(env, 5); /* infix */
    v0266 = get(v0159, v0266);
    env = stack[-5];
    v0266 = (Lisp_Object)lesseq2(v0160, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0266 = v0266 ? lisp_true : nil;
    env = stack[-5];
    goto v0069;

v0235:
    v0266 = qvalue(elt(env, 3)); /* t */
    goto v0069;

v0043:
    v0266 = qvalue(elt(env, 2)); /* nil */
    goto v0002;
/* error exit handlers */
v0267:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0096, Lisp_Object v0082, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0084, v0094;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm1");
#endif
    if (stack >= stacklimit)
    {
        push4(v0082,v0096,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0096,v0082);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0082;
    stack[-2] = v0096;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0023:
    v0051 = stack[-4];
    if (v0051 == nil) goto v0043;
    v0051 = stack[-4];
    v0051 = qcdr(v0051);
    stack[-5] = v0051;
    v0051 = stack[-4];
    v0084 = qcar(v0051);
    v0051 = stack[-2];
    v0051 = cons(v0084, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-6];
    stack[0] = v0051;
    v0084 = stack[-3];
    v0051 = stack[-2];
    v0051 = cons(v0084, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v0084 = (*qfn2(fn))(qenv(fn), stack[-4], v0051);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-6];
    v0051 = stack[-1];
    v0051 = cons(v0084, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-6];
    stack[-1] = v0051;
    v0051 = stack[0];
    stack[-2] = v0051;
    v0051 = stack[-5];
    stack[-4] = v0051;
    goto v0023;

v0043:
    v0094 = stack[-3];
    v0084 = stack[-2];
    v0051 = stack[-1];
    popv(7);
    return acons(v0094, v0084, v0051);
/* error exit handlers */
v0021:
    popv(7);
    return nil;
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
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

v0031:
    v0064 = stack[0];
    v0094 = (Lisp_Object)17; /* 1 */
    if (v0064 == v0094) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0094 = stack[-1];
    if (!consp(v0094)) goto v0003;
    v0094 = stack[-1];
    v0094 = qcar(v0094);
    v0094 = (consp(v0094) ? nil : lisp_true);
    goto v0005;

v0005:
    if (v0094 == nil) goto v0192;
    v0094 = stack[-1];
    fn = elt(env, 2); /* minusf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    if (v0094 == nil) goto v0025;
    v0094 = stack[-1];
    fn = elt(env, 3); /* negf */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    v0064 = v0094;
    goto v0265;

v0265:
    v0094 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v0064, v0094);
    }

v0025:
    v0094 = stack[-1];
    v0064 = v0094;
    goto v0265;

v0192:
    v0094 = stack[-1];
    v0094 = qcdr(v0094);
    stack[-2] = v0094;
    v0094 = stack[-1];
    v0094 = qcar(v0094);
    v0064 = qcdr(v0094);
    v0094 = stack[0];
    v0094 = CC_sfto_dcontentf1(env, v0064, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-3];
    stack[0] = v0094;
    v0094 = stack[-2];
    stack[-1] = v0094;
    goto v0031;

v0003:
    v0094 = qvalue(elt(env, 1)); /* t */
    goto v0005;
/* error exit handlers */
v0022:
    popv(4);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0188, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn1");
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
    v0188 = stack[0];
    if (!consp(v0188)) goto v0073;
    v0188 = stack[0];
    v0188 = qcar(v0188);
    v0188 = (consp(v0188) ? nil : lisp_true);
    goto v0031;

v0031:
    if (!(v0188 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0003:
    v0188 = stack[0];
    v0188 = qcar(v0188);
    v0188 = qcdr(v0188);
    v0184 = CC_ckrn1(env, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-2];
    v0188 = stack[-1];
    fn = elt(env, 3); /* gck2 */
    v0188 = (*qfn2(fn))(qenv(fn), v0184, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-2];
    stack[-1] = v0188;
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    if (v0188 == nil) goto v0265;
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    if (!consp(v0188)) goto v0035;
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    v0188 = qcar(v0188);
    v0188 = (consp(v0188) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0188 == nil) goto v0191;
    v0188 = qvalue(elt(env, 1)); /* t */
    goto v0264;

v0264:
    if (v0188 == nil) goto v0039;
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    v0184 = CC_ckrn1(env, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-2];
    v0188 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v0184, v0188);
    }

v0039:
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    stack[0] = v0188;
    goto v0003;

v0191:
    v0188 = stack[0];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0184 = qcar(v0188);
    v0188 = stack[0];
    v0188 = qcdr(v0188);
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = (v0184 == v0188 ? lisp_true : nil);
    v0188 = (v0188 == nil ? lisp_true : nil);
    goto v0264;

v0035:
    v0188 = qvalue(elt(env, 1)); /* t */
    goto v0021;

v0265:
    v0188 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v0188 == nil) goto v0066;
    v0188 = stack[0];
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    v0188 = qcar(v0188);
    fn = elt(env, 4); /* noncomp1 */
    v0188 = (*qfn1(fn))(qenv(fn), v0188);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-2];
    if (!(v0188 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v0066:
    v0188 = stack[0];
    v0188 = qcar(v0188);
    v0184 = qcar(v0188);
    v0188 = stack[-1];
    v0188 = cons(v0184, v0188);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    popv(3);
    return ncons(v0188);

v0073:
    v0188 = qvalue(elt(env, 1)); /* t */
    goto v0031;
/* error exit handlers */
v0231:
    popv(3);
    return nil;
}



/* Code for ofsf_smwcpknowl */

static Lisp_Object CC_ofsf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0095 = v0000;
/* end of prologue */
    v0074 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0074 == nil) goto v0023;
    v0074 = v0095;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v0074);
    }

v0023:
    v0074 = v0095;
    {
        fn = elt(env, 3); /* ofsf_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v0074);
    }
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbol");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    v0031 = elt(env, 1); /* symbol!-character */
    return get(v0034, v0031);
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord");
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
    v0003 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0004 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v0003 = (*qfn2(fn))(qenv(fn), v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    stack[0] = v0003;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    env = stack[-2];
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    fn = elt(env, 2); /* kernord!-sort */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    {
        Lisp_Object v0032 = stack[-1];
        popv(3);
        return Lappend(nil, v0032, v0003);
    }
/* error exit handlers */
v0012:
    popv(3);
    return nil;
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0013;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0000;
/* end of prologue */

v0276:
    v0013 = v0041;
    if (v0013 == nil) goto v0015;
    v0013 = v0041;
    v0013 = qcar(v0013);
    v0013 = qcdr(v0013);
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    if (v0013 == nil) goto v0073;
    v0041 = qcdr(v0041);
    goto v0276;

v0073:
    v0041 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0041);

v0015:
    v0041 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0041);
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiom");
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
    v0032 = stack[0];
    v0016 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0032 = (Lisp_Object)17; /* 1 */
    if (v0016 == v0032) goto v0002;
    v0032 = stack[0];
    v0032 = qcar(v0032);
    fn = elt(env, 2); /* objectom */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    v0032 = CC_multiom(env, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    goto v0059;

v0059:
    v0032 = nil;
    { popv(2); return onevalue(v0032); }

v0002:
    v0032 = stack[0];
    v0032 = qcar(v0032);
    fn = elt(env, 2); /* objectom */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    goto v0059;
/* error exit handlers */
v0006:
    popv(2);
    return nil;
}



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0229, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:get-term");
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
    v0075 = stack[-2];
    fn = elt(env, 5); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0075 = stack[-2];
    fn = elt(env, 6); /* ps!:last!-term */
    v0075 = (*qfn1(fn))(qenv(fn), v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v0075;
    v0229 = stack[-1];
    v0075 = stack[-3];
    v0075 = (Lisp_Object)lessp2(v0229, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    v0075 = v0075 ? lisp_true : nil;
    env = stack[-4];
    if (v0075 == nil) goto v0007;
    v0229 = qvalue(elt(env, 1)); /* nil */
    v0075 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0229, v0075);

v0007:
    v0229 = stack[-1];
    v0075 = stack[0];
    v0075 = (Lisp_Object)greaterp2(v0229, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    v0075 = v0075 ? lisp_true : nil;
    env = stack[-4];
    if (v0075 == nil) goto v0193;
    v0075 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0075); }

v0193:
    v0229 = stack[-1];
    v0075 = stack[-3];
    stack[0] = difference2(v0229, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0075 = stack[-2];
    if (!consp(v0075)) goto v0084;
    v0075 = stack[-2];
    v0229 = qcar(v0075);
    v0075 = elt(env, 3); /* !:ps!: */
    if (v0229 == v0075) goto v0045;
    v0075 = stack[-2];
    v0229 = qcar(v0075);
    v0075 = elt(env, 4); /* dname */
    v0075 = get(v0229, v0075);
    env = stack[-4];
    goto v0051;

v0051:
    if (v0075 == nil) goto v0228;
    v0107 = (Lisp_Object)1; /* 0 */
    v0229 = stack[-2];
    v0075 = (Lisp_Object)17; /* 1 */
    v0075 = list2star(v0107, v0229, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0075 = ncons(v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0053;

v0053:
    v0075 = Lassoc(nil, stack[0], v0075);
    v0229 = v0075;
    v0075 = v0229;
    if (v0075 == nil) goto v0077;
    v0075 = v0229;
    v0075 = qcdr(v0075);
    { popv(5); return onevalue(v0075); }

v0077:
    v0229 = qvalue(elt(env, 1)); /* nil */
    v0075 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v0229, v0075);

v0228:
    v0229 = stack[-2];
    v0075 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 7); /* ps!:getv */
    v0075 = (*qfn2(fn))(qenv(fn), v0229, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0053;

v0045:
    v0075 = qvalue(elt(env, 1)); /* nil */
    goto v0051;

v0084:
    v0075 = qvalue(elt(env, 2)); /* t */
    goto v0051;
/* error exit handlers */
v0262:
    popv(5);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsearchinlist");
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

v0059:
    v0006 = stack[0];
    if (v0006 == nil) goto v0008;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    v0006 = qcdr(v0006);
    v0007 = qcar(v0006);
    v0006 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0265;
    env = stack[-2];
    if (v0006 == nil) goto v0012;
    v0006 = stack[0];
    v0006 = qcar(v0006);
    { popv(3); return onevalue(v0006); }

v0012:
    v0006 = stack[0];
    v0006 = qcdr(v0006);
    stack[0] = v0006;
    goto v0059;

v0008:
    v0006 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0006); }
/* error exit handlers */
v0265:
    popv(3);
    return nil;
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0255, v0283, v0272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*form");
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

v0276:
    v0255 = stack[0];
    if (!consp(v0255)) goto v0008;
    v0255 = stack[0];
    v0255 = qcar(v0255);
    v0272 = v0255;
    v0283 = v0272;
    v0255 = elt(env, 3); /* indexvar */
    v0255 = Lflagp(nil, v0283, v0255);
    env = stack[-2];
    if (v0255 == nil) goto v0070;
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0272 = Llength(nil, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-2];
    v0255 = stack[0];
    v0283 = qcar(v0255);
    v0255 = elt(env, 4); /* ifdegree */
    v0255 = get(v0283, v0255);
    env = stack[-2];
    v0255 = Lassoc(nil, v0272, v0255);
    v0283 = v0255;
    v0255 = v0283;
    if (v0255 == nil) goto v0239;
    v0255 = v0283;
    v0255 = qcdr(v0255);
    { popv(3); return onevalue(v0255); }

v0239:
    v0255 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0255); }

v0070:
    v0283 = v0272;
    v0255 = elt(env, 5); /* wedge */
    if (v0283 == v0255) goto v0021;
    v0283 = v0272;
    v0255 = elt(env, 6); /* d */
    if (v0283 == v0255) goto v0019;
    v0283 = v0272;
    v0255 = elt(env, 7); /* hodge */
    if (v0283 == v0255) goto v0187;
    v0283 = v0272;
    v0255 = elt(env, 9); /* partdf */
    if (v0283 == v0255) goto v0080;
    v0283 = v0272;
    v0255 = elt(env, 10); /* liedf */
    if (v0283 == v0255) goto v0285;
    v0283 = v0272;
    v0255 = elt(env, 11); /* innerprod */
    if (v0283 == v0255) goto v0259;
    v0283 = v0272;
    v0255 = elt(env, 12); /* (plus minus difference quotient) */
    v0255 = Lmemq(nil, v0283, v0255);
    if (v0255 == nil) goto v0286;
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    stack[0] = v0255;
    goto v0276;

v0286:
    v0283 = v0272;
    v0255 = elt(env, 13); /* times */
    if (v0283 == v0255) goto v0287;
    v0255 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0255); }

v0287:
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0255);
    }

v0259:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = CC_degHform(env, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-2];
    {
        Lisp_Object v0288 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v0288, v0255);
    }

v0285:
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    stack[0] = v0255;
    goto v0276;

v0080:
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcdr(v0255);
    if (v0255 == nil) goto v0263;
    v0255 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0255); }

v0263:
    v0255 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v0255); }

v0187:
    stack[-1] = qvalue(elt(env, 8)); /* dimex!* */
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = CC_degHform(env, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-2];
    fn = elt(env, 16); /* negf */
    v0255 = (*qfn1(fn))(qenv(fn), v0255);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-2];
    {
        Lisp_Object v0289 = stack[-1];
        popv(3);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v0289, v0255);
    }

v0019:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    v0255 = qcar(v0255);
    v0255 = CC_degHform(env, v0255);
    nil = C_nil;
    if (exception_pending()) goto v0284;
    env = stack[-2];
    {
        Lisp_Object v0174 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v0174, v0255);
    }

v0021:
    v0255 = stack[0];
    v0255 = qcdr(v0255);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v0255);
    }

v0008:
    v0283 = stack[0];
    v0255 = elt(env, 1); /* fdegree */
    v0255 = get(v0283, v0255);
    env = stack[-2];
    v0283 = v0255;
    v0255 = v0283;
    if (v0255 == nil) goto v0003;
    v0255 = v0283;
    v0255 = qcar(v0255);
    { popv(3); return onevalue(v0255); }

v0003:
    v0255 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0255); }
/* error exit handlers */
v0284:
    popv(3);
    return nil;
}



/* Code for set!-ordp */

static Lisp_Object CC_setKordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0097, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0097 = v0001;
    v0006 = v0000;
/* end of prologue */
    v0016 = v0006;
    if (!(is_number(v0016))) goto v0005;
    v0016 = v0097;
    if (!(is_number(v0016))) goto v0005;
    v0016 = v0006;
        return Llessp(nil, v0016, v0097);

v0005:
    v0016 = v0006;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0016, v0097);
    }
}



/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0193;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp2f");
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

v0059:
    v0192 = stack[0];
    if (!consp(v0192)) goto v0073;
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0192 = (consp(v0192) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0192 == nil) goto v0023;
    v0192 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0192); }

v0023:
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    v0192 = qcar(v0192);
    v0193 = v0192;
    if (!consp(v0192)) goto v0005;
    v0192 = v0193;
    v0192 = qcar(v0192);
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 0); /* noncom */
#ifdef RECORD_GET
             if (v0192 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0192 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0192 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; else v0192 = lisp_true; }}
#endif
    if (v0192 == nil) goto v0010;
    v0192 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0192); }

v0010:
    v0192 = stack[0];
    v0192 = qcar(v0192);
    v0192 = qcdr(v0192);
    v0192 = CC_noncomp2f(env, v0192);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-1];
    if (v0192 == nil) goto v0011;
    v0192 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0192); }

v0011:
    v0192 = stack[0];
    v0192 = qcdr(v0192);
    stack[0] = v0192;
    goto v0059;

v0005:
    v0192 = v0193;
    if (!symbolp(v0192)) v0192 = nil;
    else { v0192 = qfastgets(v0192);
           if (v0192 != nil) { v0192 = elt(v0192, 0); /* noncom */
#ifdef RECORD_GET
             if (v0192 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0192 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0192 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0192 == SPID_NOPROP) v0192 = nil; else v0192 = lisp_true; }}
#endif
    if (v0192 == nil) goto v0011;
    v0192 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0192); }

v0073:
    v0192 = qvalue(elt(env, 1)); /* t */
    goto v0031;
/* error exit handlers */
v0033:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0096, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0052, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroad");
#endif
    if (stack >= stacklimit)
    {
        push3(v0096,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0096);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0096;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0066 = nil;
    goto v0011;

v0011:
    v0067 = stack[0];
    if (v0067 == nil) goto v0034;
    v0052 = stack[-2];
    v0067 = stack[0];
    v0067 = qcar(v0067);
    if (equal(v0052, v0067)) goto v0013;
    v0067 = stack[0];
    v0067 = qcar(v0067);
    v0052 = v0066;
    v0067 = cons(v0067, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    v0066 = v0067;
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    stack[0] = v0067;
    goto v0011;

v0013:
    stack[-2] = v0066;
    v0052 = stack[-1];
    v0067 = stack[0];
    v0067 = qcdr(v0067);
    v0067 = Lappend(nil, v0052, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-3];
    {
        Lisp_Object v0054 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0054, v0067);
    }

v0034:
    v0067 = v0066;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0067);
    }
/* error exit handlers */
v0227:
    popv(4);
    return nil;
}



/* Code for assert_analyze */

static Lisp_Object MS_CDECL CC_assert_analyze(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_analyze");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_analyze");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v0266 = (Lisp_Object)1; /* 0 */
    stack[0] = v0266;
    v0266 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0266;
    v0266 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0266;
    v0159 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v0266 = elt(env, 2); /* lambda_ls8o1i_1 */
    fn = elt(env, 8); /* sort */
    v0266 = (*qfn2(fn))(qenv(fn), v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0266; /* assertstatistics!* */
    v0266 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-3] = v0266;
    goto v0005;

v0005:
    v0266 = stack[-3];
    if (v0266 == nil) goto v0072;
    v0266 = stack[-3];
    v0266 = qcar(v0266);
    stack[-1] = v0266;
    v0159 = stack[0];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = plus2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    v0159 = stack[-4];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = plus2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[-4] = v0266;
    v0159 = stack[-2];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = plus2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[-2] = v0266;
    v0266 = stack[-3];
    v0266 = qcdr(v0266);
    stack[-3] = v0266;
    goto v0005;

v0072:
    v0266 = elt(env, 4); /* (function !#calls !#bad! calls !#assertion! violations) 
*/
    stack[-3] = v0266;
    stack[-1] = elt(env, 5); /* sum */
    v0159 = stack[-4];
    v0266 = stack[-2];
    v0266 = list2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = list2star(stack[-1], stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    stack[0] = v0266;
    v0159 = qvalue(elt(env, 3)); /* nil */
    v0266 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v0266 = cons(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = list2star(stack[-1], stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lnreverse(nil, v0266);
    env = stack[-5];
    v0266 = cons(stack[-2], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = list2star(stack[-4], stack[-3], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0266; /* assertstatistics!* */
    v0266 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-2] = v0266;
    goto v0081;

v0081:
    v0266 = stack[-2];
    if (v0266 == nil) goto v0080;
    v0266 = stack[-2];
    v0266 = qcar(v0266);
    stack[-1] = v0266;
    v0266 = stack[-1];
    if (v0266 == nil) goto v0296;
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[-1];
    v0266 = qcar(v0266);
    v0266 = Lexplodec(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = Llength(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lexplodec(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Llength(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = plus2(stack[0], v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0297;

v0297:
    v0159 = (Lisp_Object)369; /* 23 */
    v0266 = stack[0];
    v0266 = difference2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lminusp(nil, v0266);
    env = stack[-5];
    if (v0266 == nil) goto v0298;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lexplodec(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Llength(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0278;

v0278:
    v0159 = (Lisp_Object)369; /* 23 */
    v0266 = stack[0];
    v0266 = difference2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lminusp(nil, v0266);
    env = stack[-5];
    if (v0266 == nil) goto v0176;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lexplodec(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Llength(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0169;

v0169:
    v0159 = (Lisp_Object)369; /* 23 */
    v0266 = stack[0];
    v0266 = difference2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lminusp(nil, v0266);
    env = stack[-5];
    if (v0266 == nil) goto v0299;
    v0266 = stack[-1];
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcdr(v0266);
    v0266 = qcar(v0266);
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    goto v0109;

v0109:
    v0266 = stack[-2];
    v0266 = qcdr(v0266);
    stack[-2] = v0266;
    goto v0081;

v0299:
    v0266 = elt(env, 6); /* " " */
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[0];
    v0266 = add1(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0169;

v0176:
    v0266 = elt(env, 6); /* " " */
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[0];
    v0266 = add1(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0278;

v0298:
    v0266 = elt(env, 6); /* " " */
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[0];
    v0266 = add1(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0297;

v0296:
    v0266 = (Lisp_Object)17; /* 1 */
    stack[0] = v0266;
    goto v0300;

v0300:
    v0159 = (Lisp_Object)1153; /* 72 */
    v0266 = stack[0];
    v0266 = difference2(v0159, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = Lminusp(nil, v0266);
    env = stack[-5];
    if (v0266 == nil) goto v0301;
    v0266 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    goto v0109;

v0301:
    v0266 = elt(env, 7); /* "-" */
    v0266 = Lprinc(nil, v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    v0266 = stack[0];
    v0266 = add1(v0266);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-5];
    stack[0] = v0266;
    goto v0300;

v0080:
    v0266 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0266; /* assertstatistics!* */
    v0266 = nil;
    { popv(6); return onevalue(v0266); }
/* error exit handlers */
v0295:
    popv(6);
    return nil;
}



/* Code for lambda_ls8o1i_1 */

static Lisp_Object CC_lambda_ls8o1i_1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_ls8o1i_1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0095 = v0001;
    v0074 = v0000;
/* end of prologue */
    v0095 = qcar(v0095);
    v0074 = qcar(v0074);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0095, v0074);
    }
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0096, Lisp_Object v0082, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0228, v0238, v0100, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
    if (stack >= stacklimit)
    {
        push4(v0082,v0096,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0096,v0082);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0082;
    stack[-2] = v0096;
    stack[-3] = v0001;
    stack[-4] = v0000;
/* end of prologue */

v0276:
    v0228 = stack[-4];
    if (v0228 == nil) goto v0031;
    v0238 = stack[-2];
    v0228 = stack[-3];
    v0228 = qcar(v0228);
    stack[0] = times2(v0238, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    stack[-5] = stack[0];
    v0238 = stack[-1];
    v0228 = stack[-4];
    v0228 = qcar(v0228);
    v0228 = times2(v0238, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    if (equal(stack[0], v0228)) goto v0053;
    v0228 = qvalue(elt(env, 1)); /* nil */
    goto v0026;

v0026:
    if (v0228 == nil) goto v0019;
    v0238 = stack[-1];
    v0228 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v0238, v0228);
    }

v0019:
    v0228 = stack[-4];
    v0060 = qcdr(v0228);
    v0228 = stack[-3];
    v0100 = qcdr(v0228);
    v0238 = stack[-2];
    v0228 = stack[-1];
    stack[-4] = v0060;
    stack[-3] = v0100;
    stack[-2] = v0238;
    stack[-1] = v0228;
    goto v0276;

v0053:
    v0238 = stack[-5];
    v0228 = (Lisp_Object)1; /* 0 */
    if (v0238 == v0228) goto v0234;
    v0238 = stack[-1];
    v0228 = stack[-2];
    v0238 = Lgcd(nil, v0238, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    v0228 = stack[-1];
    v0238 = Cremainder(v0238, v0228);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-6];
    v0228 = (Lisp_Object)1; /* 0 */
    v0228 = (v0238 == v0228 ? lisp_true : nil);
    goto v0026;

v0234:
    v0228 = qvalue(elt(env, 1)); /* nil */
    goto v0026;

v0031:
    v0228 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0228); }
/* error exit handlers */
v0231:
    popv(7);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0001,
                         Lisp_Object v0096, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tsym4");
#endif
    if (stack >= stacklimit)
    {
        push3(v0096,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0096);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0096;
    stack[-1] = v0001;
    v0088 = v0000;
/* end of prologue */

v0011:
    v0024 = v0088;
    if (v0024 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0024 = v0088;
    v0024 = qcdr(v0024);
    stack[-2] = v0024;
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    v0088 = qcar(v0088);
    fn = elt(env, 1); /* pv_applp */
    v0024 = (*qfn2(fn))(qenv(fn), v0024, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    v0088 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v0088 = (*qfn2(fn))(qenv(fn), v0024, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v0024 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    v0088 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v0088 = (*qfn2(fn))(qenv(fn), v0024, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-3];
    stack[0] = v0088;
    v0088 = stack[-2];
    goto v0011;
/* error exit handlers */
v0235:
    popv(4);
    return nil;
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0031;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2ar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0034 = v0000;
/* end of prologue */
    v0031 = elt(env, 1); /* !:ar!: */
    return cons(v0031, v0034);
}



/* Code for polynommultiplybymonom */

static Lisp_Object CC_polynommultiplybymonom(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybymonom");
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
    v0235 = v0000;
/* end of prologue */
    v0053 = v0235;
    if (v0053 == nil) goto v0059;
    v0053 = v0235;
    fn = elt(env, 2); /* polynomclone */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    stack[-1] = v0053;
    v0235 = stack[0];
    v0053 = (Lisp_Object)17; /* 1 */
    v0053 = *(Lisp_Object *)((char *)v0235 + (CELL-TAG_VECTOR) + ((int32_t)v0053/(16/CELL)));
    stack[0] = v0053;
    goto v0012;

v0012:
    v0053 = stack[0];
    v0053 = qcar(v0053);
    if (v0053 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0235 = stack[-1];
    v0053 = stack[0];
    v0053 = qcar(v0053);
    fn = elt(env, 3); /* polynommultiplybyvariable */
    v0053 = (*qfn2(fn))(qenv(fn), v0235, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-2];
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    stack[0] = v0053;
    goto v0012;

v0059:
    v0053 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0053); }
/* error exit handlers */
v0200:
    popv(3);
    return nil;
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0095, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
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
    v0095 = v0001;
    v0042 = v0000;
/* end of prologue */
    v0074 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v0074; /* !*gcd */
    v0074 = v0042;
    fn = elt(env, 3); /* sfto_gcdf */
    v0074 = (*qfn2(fn))(qenv(fn), v0074, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v0074); }
/* error exit handlers */
v0040:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp");
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
    v0058 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (v0058 == nil) goto v0027;
    v0058 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0058;
    goto v0023;

v0023:
    v0058 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (v0058 == nil) goto v0007;
    v0058 = qvalue(elt(env, 1)); /* nil */
    goto v0034;

v0034:
    fn = elt(env, 3); /* symbollessp */
    v0058 = (*qfn2(fn))(qenv(fn), stack[-2], v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (!(v0058 == nil)) { popv(4); return onevalue(v0058); }
    v0058 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (v0058 == nil) goto v0067;
    v0058 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0058;
    goto v0088;

v0088:
    v0058 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (v0058 == nil) goto v0065;
    v0058 = qvalue(elt(env, 1)); /* nil */
    goto v0024;

v0024:
    if (equal(stack[-2], v0058)) goto v0070;
    v0058 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0058); }

v0070:
    v0058 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    if (v0058 == nil) goto v0190;
    v0058 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0058;
    goto v0050;

v0050:
    v0058 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    if (v0058 == nil) goto v0030;
    v0058 = (Lisp_Object)1; /* 0 */
    goto v0234;

v0234:
    {
        Lisp_Object v0063 = stack[-1];
        popv(4);
        return Llessp(nil, v0063, v0058);
    }

v0030:
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    goto v0234;

v0190:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0050;

v0065:
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    goto v0024;

v0067:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    stack[-2] = v0058;
    goto v0088;

v0007:
    v0058 = stack[0];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    goto v0034;

v0027:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    stack[-2] = v0058;
    goto v0023;
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litlp");
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

v0276:
    v0003 = stack[0];
    if (v0003 == nil) goto v0015;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    fn = elt(env, 3); /* ibalp_litp */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    if (v0003 == nil) goto v0073;
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    stack[0] = v0003;
    goto v0276;

v0073:
    v0003 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0003); }

v0015:
    v0003 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0003); }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0039, v0265;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
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
    v0039 = v0001;
    v0265 = v0000;
/* end of prologue */
    v0014 = v0265;
    v0014 = qcdr(v0014);
    if (v0014 == nil) goto v0059;
    v0014 = elt(env, 1); /* "Wrong number of arguments to" */
    v0014 = list2(v0014, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    v0039 = v0014;
    v0014 = v0039;
    qvalue(elt(env, 2)) = v0014; /* errmsg!* */
    v0014 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v0014 == nil)) goto v0013;
    v0014 = v0039;
    fn = elt(env, 4); /* lprie */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[0];
    goto v0013;

v0013:
    v0014 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    v0014 = nil;
    { popv(1); return onevalue(v0014); }

v0059:
    v0014 = v0265;
    v0014 = qcar(v0014);
    { popv(1); return onevalue(v0014); }
/* error exit handlers */
v0010:
    popv(1);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0192, v0193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
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
    v0192 = v0000;
/* end of prologue */
    v0235 = v0192;
    if (!consp(v0235)) goto v0008;
    v0235 = v0192;
    v0193 = qcar(v0235);
    v0235 = elt(env, 2); /* !:ps!: */
    if (v0193 == v0235) goto v0265;
    v0235 = v0192;
    v0193 = qcar(v0235);
    v0235 = elt(env, 3); /* dname */
    v0235 = get(v0193, v0235);
    env = stack[0];
    goto v0011;

v0011:
    if (!(v0235 == nil)) { popv(1); return onevalue(v0192); }
    v0235 = (Lisp_Object)97; /* 6 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0192, v0235);
    }

v0265:
    v0235 = qvalue(elt(env, 4)); /* nil */
    goto v0011;

v0008:
    v0235 = qvalue(elt(env, 1)); /* t */
    goto v0011;
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0281;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extmult");
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
    v0091 = stack[-2];
    if (v0091 == nil) goto v0023;
    v0091 = stack[-1];
    v0091 = (v0091 == nil ? lisp_true : nil);
    goto v0008;

v0008:
    if (v0091 == nil) goto v0009;
    v0091 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0091); }

v0009:
    v0281 = stack[-1];
    v0091 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0091) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    v0281 = qcar(v0091);
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcar(v0091);
    fn = elt(env, 3); /* c!:ordexn */
    v0091 = (*qfn2(fn))(qenv(fn), v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0281 = v0091;
    v0091 = v0281;
    if (v0091 == nil) goto v0243;
    v0091 = v0281;
    stack[0] = qcdr(v0091);
    v0091 = v0281;
    v0091 = qcar(v0091);
    if (v0091 == nil) goto v0190;
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0281 = qcdr(v0091);
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    fn = elt(env, 4); /* c!:subs2multf */
    v0091 = (*qfn2(fn))(qenv(fn), v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 5); /* negf */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    goto v0227;

v0227:
    v0091 = cons(stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0281 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[0] = CC_cTextmult(env, v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0091 = stack[-2];
    v0281 = qcdr(v0091);
    v0091 = stack[-1];
    v0091 = CC_cTextmult(env, v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    fn = elt(env, 6); /* c!:extadd */
    v0091 = (*qfn2(fn))(qenv(fn), stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    {
        Lisp_Object v0303 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0303, v0091);
    }

v0190:
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0281 = qcdr(v0091);
    v0091 = stack[-1];
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    fn = elt(env, 4); /* c!:subs2multf */
    v0091 = (*qfn2(fn))(qenv(fn), v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    goto v0227;

v0243:
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    v0281 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[0] = CC_cTextmult(env, v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    v0091 = stack[-2];
    v0281 = qcdr(v0091);
    v0091 = stack[-1];
    v0091 = CC_cTextmult(env, v0281, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    {
        Lisp_Object v0293 = stack[0];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v0293, v0091);
    }

v0023:
    v0091 = qvalue(elt(env, 1)); /* t */
    goto v0008;
/* error exit handlers */
v0260:
    popv(5);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108, v0109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testred");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0108 = qvalue(elt(env, 2)); /* maxvar */
    v0107 = stack[0];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0108 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (Lisp_Object)1; /* 0 */
    v0107 = *(Lisp_Object *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    if (v0107 == nil) goto v0059;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0108 = qvalue(elt(env, 2)); /* maxvar */
    v0107 = stack[0];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0108 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (Lisp_Object)17; /* 1 */
    v0107 = *(Lisp_Object *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = qcar(v0107);
    v0108 = qcar(v0107);
    v0107 = (Lisp_Object)33; /* 2 */
    v0107 = (Lisp_Object)lessp2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    v0107 = v0107 ? lisp_true : nil;
    env = stack[-2];
    if (v0107 == nil) goto v0059;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0108 = qvalue(elt(env, 2)); /* maxvar */
    v0107 = stack[0];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0109 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0108 = (Lisp_Object)1; /* 0 */
    v0107 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0109 + (CELL-TAG_VECTOR) + ((int32_t)v0108/(16/CELL))) = v0107;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0108 = qvalue(elt(env, 2)); /* maxvar */
    v0107 = stack[0];
    v0107 = plus2(v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0108 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    v0107 = (Lisp_Object)65; /* 4 */
    v0107 = *(Lisp_Object *)((char *)v0108 + (CELL-TAG_VECTOR) + ((int32_t)v0107/(16/CELL)));
    stack[-1] = v0107;
    goto v0048;

v0048:
    v0107 = stack[-1];
    if (v0107 == nil) goto v0063;
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    stack[0] = v0107;
    v0107 = stack[0];
    v0108 = qcar(v0107);
    v0107 = stack[0];
    v0107 = qcdr(v0107);
    v0107 = qcar(v0107);
    fn = elt(env, 4); /* downwght1 */
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0107 = stack[0];
    v0107 = qcar(v0107);
    v0107 = CC_testred(env, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-2];
    v0107 = stack[-1];
    v0107 = qcdr(v0107);
    stack[-1] = v0107;
    goto v0048;

v0063:
    v0107 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0107); }

v0059:
    v0107 = nil;
    { popv(3); return onevalue(v0107); }
/* error exit handlers */
v0262:
    popv(3);
    return nil;
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0242, v0194, v0068;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcone?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0068 = v0000;
/* end of prologue */
    v0242 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0242 == nil) goto v0072;
    v0194 = v0068;
    v0242 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v0194, v0242);

v0072:
    v0242 = v0068;
    v0194 = qcdr(v0242);
    v0242 = (Lisp_Object)17; /* 1 */
    if (v0194 == v0242) goto v0016;
    v0242 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0242);

v0016:
    v0242 = v0068;
    v0194 = qcar(v0242);
    v0242 = (Lisp_Object)17; /* 1 */
    v0242 = (v0194 == v0242 ? lisp_true : nil);
    return onevalue(v0242);
}



/* Code for ncmpchk */

static Lisp_Object CC_ncmpchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncmpchk");
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
    v0012 = stack[-1];
    v0013 = stack[0];
    fn = elt(env, 2); /* noncommuting */
    v0013 = (*qfn2(fn))(qenv(fn), v0012, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-2];
    if (v0013 == nil) goto v0059;
    v0012 = stack[-1];
    v0013 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0012, v0013);
    }

v0059:
    v0013 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0013); }
/* error exit handlers */
v0097:
    popv(3);
    return nil;
}



setup_type const u07_setup[] =
{
    {"gsetsugar",               too_few_2,      CC_gsetsugar,  wrong_no_2},
    {"domain*p",                CC_domainHp,    too_many_1,    wrong_no_1},
    {"add2resultbuf",           too_few_2,      CC_add2resultbuf,wrong_no_2},
    {"groeb=testa",             too_few_2,      CC_groebMtesta,wrong_no_2},
    {"pv_sort2a",               too_few_2,      CC_pv_sort2a,  wrong_no_2},
    {"ordn",                    CC_ordn,        too_many_1,    wrong_no_1},
    {"undefdchk",               CC_undefdchk,   too_many_1,    wrong_no_1},
    {"polynomadd",              too_few_2,      CC_polynomadd, wrong_no_2},
    {"cl_apply2ats",            too_few_2,      CC_cl_apply2ats,wrong_no_2},
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"mri_pasf2mriat",          too_few_2,      CC_mri_pasf2mriat,wrong_no_2},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,too_many_1, wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"set-ordp",                too_few_2,      CC_setKordp,   wrong_no_2},
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_ls8o1i_1",         too_few_2,      CC_lambda_ls8o1i_1,wrong_no_2},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"polynommultiplybymonom",  too_few_2,      CC_polynommultiplybymonom,wrong_no_2},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {NULL, (one_args *)"u07", (two_args *)"19315 9788390 6858679", 0}
};

/* end of generated code */
