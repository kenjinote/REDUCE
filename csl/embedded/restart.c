/*  restart.c                       Copyright (C) 1989-2010 Codemist Ltd */

/*
 * Code needed to start off Lisp when no initial heap image is available,
 * or to re-instate links between heap and C-coded core if there IS a
 * heap loaded.  This code is run in a state that is in effect (in-package
 * "lisp").
 */

/**************************************************************************
 * Copyright (C) 2010, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/



/* Signature: 0ebe04d3 18-Aug-2010 */

#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else
#ifndef EMBEDDED
#include <dlfcn.h>
#endif
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <sys/stat.h>
#include <sys/types.h>

#ifdef HAVE_FWIN
extern int showmathInitialised;
#endif

#ifndef S_IRUSR
#ifdef __S_IRUSR
#define S_IRUSR __S_IRUSR
#endif
#endif

#ifndef S_IWUSR
#ifdef __S_IWUSR
#define S_IWUSR __S_IWUSR
#endif
#endif

#ifndef S_IXUSR
#ifdef __S_IXUSR
#define S_IXUSR __S_IXUSR
#endif
#endif

/* 
 * jit
 */
#ifdef JIT
#ifndef WIN32
#include <sys/mman.h>
#endif
#endif

extern int load_count, load_limit;

/*
 * machineid.c is a dynamically-created file that contains 
 *  (a) Identification of the type of object file used by this system.
 *      In many cases this is the ELF magic code for the machine.
 *  (b) Information about the command used to compile C code.
 *  (c) Header files relating to the Lisp-to-C compilation process.
 */
#include "machineid.c"

Lisp_Object address_sign;

/*
 * OK, so I will write a short essay here about the issues of converting
 * between 32 and 64-bit formats. Let me deal with the easier case first.
 * If the image file I wish to reload had been made on a 64-bit computer
 * but now I am just a 32-bit one I can take every item
 *   | abcdabcdabcdabcd | efghefghefghefgh |
 * and convert it in memory to
 *   | abcdabcd | efghefgh | pad_pad_ | pad_pad_ |
 * where the start address of the object is the same and my image encoding
 * means that truncating the data does not hurt. I must be careful that
 * strings, bignums and other types of stuff that contain raw binary do
 * not end up squashed, and as a matter of caution (if only while I debug
 * this) I will fill vacated space with tidy padding. Actually I now see
 * that I MUST fill up the gaps that are left with validly structured
 * material that has correct length codes in it if I shrink/compact the
 * data before I relocate pointers in it, since if I do not the attempt to
 * relocate pointers etc will fail.
 * The cost to a person with a 32-bit machine will be that there is a
 * little more time spent loading the image file, and the image file
 * will be a bit bulkier (with all that padding) so the first garbage
 * collection will need to happen sooner.
 *
 * Things are less pleasant if the image file had been made on a 32-bit
 * machine but is now being loaded on a 64-bit one. The reason this is
 * messier is that data must be expanded and moved, not just compacted with
 * gaps left.
 *
 * The basic idea is that when an object made out of 32-bit values is
 * seen it gets expanded out into 64-bit items. The image file format is
 * such that mere sign-extension should suffice for this. Then when addresses
 * are adjusted later during the reload process all offsets need to be
 * doubled. So the expansion must place each expanded object starting at
 * twice the offset from its page-start as it originally was. This is not
 * too bad. But what is nastier is that this means that the page it is put
 * into has to be a double-sized one. Normally all CSL heap is built within
 * fixed size (at present 4 Mbyte) pages. So when a 32-bit heap is to be
 * reloaded on a 64-bit machine it must be put in 8 Mbyte pages to allow for
 * the expansion. Trying to use a pair of normal sized pages seems really hard
 * because there may be a big object spanning the middle of the original
 * page - ie the place where one wanted to split it. There is an insuperable
 * problem if a 32-bit image contains a vector that would fit on that
 * architecture but not on a 64-bit one, so on 32-bit machine to allow for
 * conversion I may need to here. I also need to tune my internal
 * representation for hash tables to allow for this.
 *
 * So when reloading a 32-bit image on a 64-bit machine I must make double-
 * sized pages to reload into. That is not too bad. But then I must consider
 * their subsequent usage. There are three major concerns - the garbage
 * collector, the code that creates a new image file and freeing memory at
 * the end of a run. Before creating a new image file garbage collection is
 * performed, so if AFTER garbage collection all pages are the correct size
 * all will be well. I will ensure that that is the case.
 *
 * The sliding garbage collector leaves data in the page it started in, and
 * has no guaranteed way to shrink a page to become single size. But in the
 * case I am considering I am on a 64-bit machine and I can perhaps assume
 * that I have "plenty" of free memory - in that case I can force the first
 * garbage collection of the run to be a copying one, and fail if there is
 * insufficient memory for that to be possible. That is OK if I can
 * ensure that the total memory available is at least three the size of the
 * image that I am loading. The need for this size is to cope with a 32-bit
 * vector page that is 1/4 full of small vectors, then has a single vector
 * of maximum size and finally fills up to its top. When expanded to
 * 64-bit form and copied the copy can need 3 pages because the big vector in
 * the middle must all end up within one page.
 *
 * An initial heap image for the bootstrap version of Reduce is larger than
 * the one for the release version, but both easily fit within 1 page of
 * each of cons-heap, vector-heap and bps-heap. So loading the image in a
 * simple way requires 12 Mbytes of allocated memory. When I load into
 * double-sized pages I need 24 Mbytes of contiguous memory. To be certain
 * that I can manage a copying garbage collection even in worst case
 * situations that will not arise, I should have 2 pages of cons heap and
 * 3 for each of vector- and bps-heap available, ie 8 more pages. That is
 * 11 pages in all, and in fact I will allocate a further page for a stack,
 * so I need at least 12 pages, 48 Mbytes available at the start of a run.
 * On a 64-bit machine I will take the view that this is reasonable. Obviously
 * larger initial heap images will put more severe strains on everything!
 *
 * When expanding a page vectors that contain pointers will often double in
 * size, but if they hold an even number of items the padder word needed in
 * the 32-bit world will become superfluous. Vectors containing non-pointer
 * data (eg strings and bignums) will only expand by 4 bytes. In each case
 * if space is left unoccupied it must be filled with some form of valid
 * padding so that subsequent linear scans of the heap can succeed.
 *
 * There was an apparent pan as regards BPS pointers and refereces into
 * double-sized pages, but I found a solution to it (albeit a slightly
 * grungy one).
 *
 * I need to review the copying GC to verify that it will not be hurt
 * by having a few oversize pages, but my expectation is that it only looks
 * at the size of NEW pages that it allocates.
 *
 * At the end of a run I go "free()" on all the pages I allocated. If in
 * the copying collector I detect when I have copied out from an oversized
 * page and I return it to the pool as a pair of regular pages (a good thing
 * to do!) then if I tried to free the upper such page disaster could ensue.
 * A way to avoid that pain is to demand that the double size pages all
 * reside within an initial single block that I already allocate at the
 * start of a run and that gets freed wholesale. I will need a way to detect
 * when the garbage collector is discarding a big page.
 *
 * Note that I have a plan to introduce a conservative garbage collector
 * at some stage, and that would lead to some old pages needing to be
 * retained across a mostly-copying collection. In consequence over-sized
 * pages would live for some longer time. But my plans in that direction
 * are that the conservative system can be replaced by a precise copying
 * collector in at least the key case that a new heap image is about to
 * be created, and so at least some of the isssues can be side-stepped.
 * Detecting valid references might well need information about the size
 * of pages - but I can record that somehow when I get to that point.
 * See the file "conservative.txt" for elaboration on my plans. In the
 * very worst case I could instantly do a first precise compacting garbage
 * collection immediately after a restart so as to normalise the heap. The
 * cost effect would be that the restart took longer, but probably not by
 * very much!
 *
 * Hmm that is all a bit of a business, but I hope I have covered
 * everything that will matter! 
 */


static int converting_to_32 = 0, converting_to_64 = 0;

Lisp_Object C_nil;
Lisp_Object *stackbase;
Lisp_Object * volatile stacklimit;

Lisp_Object *nilsegment;
Lisp_Object *stacksegment;
int32_t stack_segsize = 1;

char *exit_charvec = NULL;
intptr_t exit_reason;

#ifdef NILSEG_EXTERNS

intptr_t byteflip;
Lisp_Object codefringe;
Lisp_Object volatile codelimit;
Lisp_Object fringe;
Lisp_Object volatile heaplimit;
Lisp_Object volatile vheaplimit;
Lisp_Object vfringe;
intptr_t nwork;
intptr_t exit_count;
intptr_t gensym_ser, print_precision, miscflags;
intptr_t current_modulus, fastget_size, package_bits;
Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
Lisp_Object quote_symbol, function_symbol, comma_symbol, comma_at_symbol;
Lisp_Object cons_symbol, eval_symbol, work_symbol, evalhook, applyhook;
Lisp_Object macroexpand_hook, append_symbol, exit_tag;
Lisp_Object exit_value, catch_tags;
#ifdef COMMON
Lisp_Object keyword_package;
#endif
Lisp_Object current_package;
Lisp_Object startfn;
#ifdef COMMON
Lisp_Object all_packages, package_symbol, internal_symbol;
Lisp_Object external_symbol, inherited_symbol;
#endif
Lisp_Object gensym_base, string_char_sym, boffo;
#ifdef COMMON
Lisp_Object key_key, allow_other_keys, aux_key;
#endif
Lisp_Object err_table;
#ifdef COMMON
Lisp_Object format_symbol;
#endif
Lisp_Object progn_symbol;
#ifdef COMMON
Lisp_Object expand_def_symbol, allow_key_key;
#endif
Lisp_Object declare_symbol, special_symbol;
Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol, echo_symbol;
Lisp_Object codevec, litvec, supervisor, B_reg, savedef, comp_symbol;
Lisp_Object compiler_symbol, faslvec, tracedfn, lisp_terminal_io;
Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
Lisp_Object prompt_thing, faslgensyms, prinl_symbol, emsg_star, redef_msg;
Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
Lisp_Object cl_symbols, active_stream, current_module;
Lisp_Object native_defs, features_symbol, lisp_package, sys_hash_table;
Lisp_Object help_index, cfunarg, lex_words, get_counts, fastget_names;
Lisp_Object input_libraries, output_library, current_file, break_function;
Lisp_Object standard_output, standard_input, debug_io;
Lisp_Object error_output, query_io, terminal_io, trace_output, fasl_stream;
Lisp_Object native_code, native_symbol, traceprint_symbol, loadsource_symbol;
Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
Lisp_Object gchook, resources, callstack, procstack, procmem;
Lisp_Object workbase[51];


#endif

Lisp_Object user_base_0, user_base_1, user_base_2, user_base_3, user_base_4;
Lisp_Object user_base_5, user_base_6, user_base_7, user_base_8, user_base_9;

Lisp_Object eq_hash_tables, equal_hash_tables;

/*
 * On an Intel 80x86 (because I am almost forced to) and on other machines
 * (much more cheerfully, and for choice!) I will arrange my memory as
 * a number of pages.  A general pool of these pages gets used
 * to satisfy requests for heap, vector heap and BPS space. 
 *
 * Since this code was first written it has become silly to even consider
 * computers with 16-bit segmented addressing! It is still convenient to
 * allocate memory in chunks, although that does set an upper limit to the
 * size of any individual object: this may hurt if a user wants a big vector
 * and it does constrain the range of big-numbers supported by the
 * artithmetic.
 */

void **pages,
     **heap_pages,
     **vheap_pages,
     **bps_pages,
     **native_pages;
void **new_heap_pages,
     **new_vheap_pages,
     **new_bps_pages,
     **new_native_pages;

#ifdef CONSERVATIVE

page_map_t *page_map;

#endif

/*
 * Used for allocating jit functions executable space
 */

#ifdef JIT
void *jit_space,
     *jit_space_p;
unsigned long jit_size;
#endif

int32_t pages_count,
        heap_pages_count,
        vheap_pages_count,
        bps_pages_count,
        native_pages_count;
int32_t new_heap_pages_count,
        new_vheap_pages_count,
        new_bps_pages_count,
        new_native_pages_count;

char program_name[64] = {0};

#ifndef COMMON
#ifdef HAVE_FWIN
char **loadable_packages = NULL, **switches = NULL;
#endif
#endif

int native_code_tag;
int32_t native_pages_changed;
int32_t native_fringe;
int current_fp_rep;
static int old_fp_rep;
static CSLbool flip_needed;
static int old_page_bits;

int procstackp;

/*
 * The next function is handed a page
 * of hard code that has just been loaded into memory and it must scan it
 * performing all relevant relocation. fringe give the offset within the
 * page that is the first byte not in use. The first 4 bytes of the page
 * are reserved for storing fringe from one run to the next. The exact
 * format of the rest must be sufficient to allow this code to scan
 * and correct the code, but thus far I have not defined it, and it will
 * anyway tend to need extension each time a new target architecture is
 * incorporated (to support the new and curious relocation modes tha the
 * new machine requires).
 */

static void relocate_native_code(unsigned char *p, int32_t n)
{
/*
 * One helpful observation here. In pretty well all other parts of CSL
 * there is a possibility that an image file created on one computer will
 * be reloaded on another and so all the code is ultra-careful to avoid
 * sensitivity to byte order etc etc issues. But here the native code that
 * is being loaded MUST have been created using the conventions of the
 * current computer (otherwise I should not be loading it and I will be
 * in huge trouble when I try to execute code from it). So direct and
 * simple access to data is legitimate.
 */
    int32_t k = 8;
    term_printf("Native code page type %d size %d to be relocated\n",
        native_code_tag, n);
    while (k <= n)
    {   unsigned char *block = p + k;
        int32_t len = car32(block);
        term_printf("Block of %d bytes found\n", len);
        if (len == 0)
        {   term_printf("End of native page reached\n");
            break;
        }
        relocate_native_function(block);
        k += len;
    }
}

void relocate_native_function(unsigned char *bps)
{
/*
 * Just for now I will not support native code on 64-bit machines.
 * This is just to save me some hassle re-working this relocation mess!
 */
    unsigned char *r, *next;
    int32_t n;
    int code;
    if (SIXTY_FOUR_BIT) return; /* No native for 64-bit architectures yet */
/*
 * Each chunk of memory allocated by make-native will have its length (in
 * bytes) in its first 32-bit word. Next comes the offset of the
 * start of real code in the block. Just after that there will be a
 * hunk of relocation information. The code proper must not start until
 * after the relocation records. Relocation information is stored in the
 * following format as a sequence of bytes:
 *         0                 end of relocation information.
 *         1 to 170/xx       encode a value 0 to 169
 *         171 to 255/xx/yy  extra byte yy extends following offset xx, and
 *                           its top bit is used to extend opcode to range
 *                           0 to 169.
 * The opcode now in the range 0 to 169 is interpreted as
 *         169            no operation
 *         otherwise (0-12)*(0-12) as target*mode
 */
    r = bps + 4;
    n = *r++;          /* code start offset in LSB format */
    n |= (*r++) << 8;
    n |= (*r++) << 16;
    n |= (*r++) << 24;
    next = bps + n;
#define RELOC_END           0
    while ((code = *r++) != RELOC_END)
    {   int32_t off = *r++;
        unsigned char *target;
/*
 * A native compiler will have to generate a sequence of bytes that adhere to
 * the contorted format used here.
 */
        if (code <= 170) code--;
        else
        {   int off1 = *r++;
            code = 2*(code-171) + (off1 >> 7);
            off = off | ((off1 & 0x7f) << 8);
        }
        next += off;   /* address where next relocation is to be applied */
#define RELOC_NOP           169
/*
 * One might like to note that with a long offset the NOP opcode turns into
 * an opcode byte 0xff. And if it then has the longest possible offset one]
 * gets the 3-byte sequence 0xff/0xff/0xff.
 */
        if (code == RELOC_NOP) continue;

#define RELOC_0_ARGS        0
#define RELOC_1_ARGS        1
#define RELOC_2_ARGS        2
#define RELOC_3_ARGS        3
#define RELOC_DIRECT_ENTRY  4
#define RELOC_VAR           5
#define RELOC_SELF_1        6
#define RELOC_SELF_2        7
        switch (code % 13)
        {
    default:
            term_printf("Illegal relocation byte %.2x\n", code);
            my_exit(EXIT_FAILURE);
    case RELOC_SELF_1:
/*
 * base of current native code block with an 8-bit offset.
 */
            target = bps + *r++;
            break;
    case RELOC_SELF_2:
/*
 * base of current native code block with 15 or 23-bit offset. The first byte
 * is the low 8-bits of the offset. The next is the next 7 bits, with its
 * 0x80 bit selecting whether a third byte is needed (which it will hardly
 * ever be).
 */
            off = *r++;
            off = off + (*r++ << 8);
            if (off & 0x8000) off = (off & 0x7fff) + (*r++ << 15);
            target = bps + off;
            break;
    case RELOC_0_ARGS:
/*
 * The next few relocation modes provide access to the C entrypoints
 * associated with a medium number of Lisp functions. The tables and
 * offsets used are documented in file "eval4.c" and are as used with the
 * byte-code compiler.
 */
            target = (unsigned char *)zero_arg_functions[*r++];
            break;
    case RELOC_1_ARGS:
            target = (unsigned char *)one_arg_functions[*r++];
            break;
    case RELOC_2_ARGS:
            target = (unsigned char *)two_arg_functions[*r++];
            break;
    case RELOC_3_ARGS:
            target = (unsigned char *)three_arg_functions[*r++];
            break;
    case RELOC_DIRECT_ENTRY:
/*
 * There are some entrypoints into the CSL kernel that are not
 * called using the usual Lisp conventions but are at a lower-level.
 * A selection of these are visible via the table "useful_functions"
 * in file fns3.c. This table can be extended if a native-mode compiler
 * needs access to any other speciality.
 */
            target = (unsigned char *)useful_functions[*r++];
            break;
    case RELOC_VAR:
/*
 * The function address_f_var (in fns3.c) returns the address of a Lisp
 * internal variable. See there for the numeric encoding used and what can
 * be accessed.
 */
            target = (unsigned char *)address_of_var(*r++);
            break;
        }

#define RELMODE_ABSOLUTE     0
#define RELMODE_RELATIVE     1
#define RELMODE_REL_PLUS_4   2
#define RELMODE_REL_MINUS_2  3
#define RELMODE_REL_MINUS_4  4
#define RELMODE_REL_OFFSET   5
#define RELMODE_SPARE1       6
#define RELMODE_SPARE2       7

        switch (code/13)
        {
    default:
            term_printf("Illegal relocation byte %.2x\n", code);
            my_exit(EXIT_FAILURE);
    case RELMODE_ABSOLUTE:
/*
 * relocate by pointing a 32-bit value directly at the absolute address
 * of the target.
 */
/*
 * In this general section of the code there are a bunch of cases where I
 * cast to intptr_t and after that to int32_t. Well at present this section
 * of code can only even possibly get executed if these two types are the
 * same width! But on a 64-bit machine I would need to take extra care
 * relocating references to 64-bit addresses.
 */
            *(int32_t *)next = (int32_t)(intptr_t)target;
            break;
    case RELMODE_RELATIVE:
/*
 * relocate by setting a 32-bit value of the offset from its own first
 * byte to the target.
 */
            *(int32_t *)next = (int32_t)((intptr_t)target - (intptr_t)next);
            break;
    case RELMODE_REL_PLUS_4:
/*
 * relocate by setting a 32-bit value of the offset from the start of the
 * word after it.
 */
            *(int32_t *)next = (int32_t)((intptr_t)target - ((intptr_t)next + 4));
            break;
    case RELMODE_REL_MINUS_2:
/*
 * relocate by setting a 32-bit value of the offset from the address 2 bytes
 * before its start. This may be used on machines where the relative address
 * is computed based on the start of the instruction rather than the start of
 * the field within the instruction that contains the offset.
 */
            *(int32_t *)next = (int32_t)((intptr_t)target - ((intptr_t)next - 2));
            break;
    case RELMODE_REL_MINUS_4:
/*
 * relocate by setting a 32-bit value of the offset from the address 4 bytes
 * before its start. This may be used on machines where the relative address
 * is computed based on the start of the instruction rather than the start of
 * the field within the instruction that contains the offset.
 */
            *(int32_t *)next = (int32_t)((intptr_t)target - ((intptr_t)next - 4));
            break;
    case RELMODE_REL_OFFSET:
/*
 * relocate by setting a 32-bit value of the offset from some place
 * offset using an 8-bit signed value from the start of the address. The
 * offset represents the number of bytes after the start of the address
 * that is to be used in the calculation. Note that the special values
 * -4, -2, 0 and 4 need never be used here because there are special
 * relocation modes for those common cases.
 */
            code = *r++;
            if (code & 0x80) code |= ~0xff; /* Sign extend */
            *(int32_t *)next = (int32_t)((intptr_t)target - ((intptr_t)next + code));
            break;
        }
    } 
}

static int32_t fread_count;
static unsigned char *fread_ptr;

#define FREAD_BUFFER_SIZE ((CSL_PAGE_SIZE - 1) & ~0xfff)

static unsigned char *pair_c, *char_stack;
static unsigned short int *pair_prev;

static void Cfread(char *p, int32_t n)
{
/*
 * The decompression process does not need hashed access to see if
 * character-pairs have been seen before, but it can need a stack to
 * unwind codes that have very lengthy expansions.
 */
    int c1, k;
    unsigned int prev, c, next_code;
    int32_t count = fread_count;
    unsigned char *ptr = fread_ptr;
    if (n < compression_worth_while)
    {
        while (n > count)
        {   memcpy(p, ptr, (size_t)count);
            p += count;
            n -= count;
            ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        if (n != 0)
        {   memcpy(p, ptr, (size_t)n);
            ptr += n;
            count -= n;
        }
        fread_count = count;
        fread_ptr = ptr;
        return;
    }

    next_code = 256;

    if (count == 0)
    {   ptr = (unsigned char *)stack;
        count = Iread(ptr, FREAD_BUFFER_SIZE);
    }
    c = *ptr++;
    count--;

    if (count == 0)
    {   ptr = (unsigned char *)stack;
        count = Iread(ptr, FREAD_BUFFER_SIZE);
    }
    c = (c << 8) | *ptr++;
    count--;

    prev = c >> 4;
    *p++ = (char)prev;    /* The first character is not compressed */
    n--;

    while (n > 0)
    {   if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = ((c & 0xf) << 8) | *ptr++;
        count--;
/*
 * Decode the next 12 bit character
 */
        c1 = c;
        k = 1;
        while (c1 >= 256)
        {   char_stack[k++] = pair_c[c1];
            if (pair_prev[c1] > CODESIZE || k >= CODESIZE)
            {   term_printf("Bad decoded char %x -> %x, k=%d\n", c1, pair_prev[c1], k);
                my_exit(EXIT_FAILURE);
            }
            c1 = pair_prev[c1];
        }
/*
 * Write the decoded stuff into the output array.
 */
        n -= k;
        *p++ = (char)c1;
        while (k != 1)
        {   *p++ = char_stack[--k];
        }
/*
 * ... then build up the decoding tables ready for next time.  Of course
 * the table building in this decoder MUST exactly match the behaviour of
 * the compression code above.
 */
        if (next_code >= CODESIZE) next_code = 256;
        else
        {   pair_prev[next_code] = (unsigned short int)prev;
            pair_c[next_code] = (unsigned char)c1;
            next_code++;
        }
        prev = c;

        if (n <= 0) break;

/*
 * read the next 12 bit character.
 */
        if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = *ptr++;
        count--;
        if (count == 0)
        {   ptr = (unsigned char *)stack;
            count = Iread(ptr, FREAD_BUFFER_SIZE);
        }
        c = (c << 8) | *ptr++;
        count--;
/*
 * Decode it...
 */
        c1 = c >> 4;
        k = 1;
        while (c1 >= 256)
        {   char_stack[k++] = pair_c[c1];
            if (pair_prev[c1] > CODESIZE || k >= CODESIZE)
            {   term_printf("Bad decoded char %x -> %x, k=%d\n", c1, pair_prev[c1], k);
                my_exit(EXIT_FAILURE);
            }
            c1 = pair_prev[c1];
        }
/*
 * Write the decoded stuff into the output array.
 */
        n -= k;
        *p++ = (char)c1;
        while (k != 1)
        {   *p++ = char_stack[--k];
        }
/*
 * ... then build up the decoding tables ready for next time.  Of course
 * the table building in this decoder MUST exactly match the behaviour of
 * the compression code above.
 */
        if (next_code >= CODESIZE) next_code = 256;
        else
        {   pair_prev[next_code] = (unsigned short int)prev;
            pair_c[next_code] = (unsigned char)c1;
            next_code++;
        }
        prev = c >> 4;
    }
    fread_count = count;
    fread_ptr = ptr;
}

/*
 * There is a misery here in that the width of a Lisp_Object on the
 * current architecture can not be a compile-time constant and so I can
 * not parameterise how to swap bytes based on "#ifdef". Hence I need to
 * write things as run-time checks. But then the version of the code I
 * will not execute has weird types - so I put in explicit casts so that
 * there is at last some local consistency and expack the compiler to
 * optimise away the code that is not wanted.
 */

#define flip_bytes(a)                                             \
    (!flip_needed ? (a) :                                         \
     SIXTY_FOUR_BIT ? (Lisp_Object)flip_64bits((uint64_t)(a)) :   \
     (Lisp_Object)flip_32bits((uint32_t)(a)))

/*
 * If I know a value is just 32-bits but it may need flipping I can use this
 */

#define flip_32(a)                                                \
    (!flip_needed ? (a) :                                         \
     flip_32bits(a))

static uint32_t flip_32bits(uint32_t x)
{
    uint32_t b0, b1, b2, b3;
    b0 = (x >> 24) & 0xffU;
    b1 = (x >> 8) & 0xff00U;
    b2 = (x << 8) & 0xff0000U;
    b3 = (x << 24) & 0xff000000U;
    return b0 | b1 | b2 | b3;
}

#define flip_64(a)                                                \
    (!flip_needed ? (a) :                                         \
     flip_64bits(a))

static uint64_t flip_64bits(uint64_t x)
{
    uint64_t b0, b1, b2, b3, b4, b5, b6, b7;
    b0 = (x >> 56) & ((uint64_t)0xff);
    b1 = (x >> 40) & (((uint64_t)0xff)<<8);
    b2 = (x >> 24) & (((uint64_t)0xff)<<16);
    b3 = (x >> 8)  & (((uint64_t)0xff)<<24);
    b4 = (x << 8)  & (((uint64_t)0xff)<<32);
    b5 = (x << 24) & (((uint64_t)0xff)<<40);
    b6 = (x << 40) & (((uint64_t)0xff)<<48);
    b7 = (x << 56) & (((uint64_t)0xff)<<56);
    return b0 | b1 | b2 | b3 | b4 | b5 | b6 | b7;
}

#define flip_halfwords(a) \
    (flip_needed ? flip_halfwords_fn(a) : (a))

static uint32_t flip_halfwords_fn(uint32_t x)
{
    uint32_t b0, b1, b2, b3;
    b0 = (x >> 8) & 0xffU;
    b1 = (x << 8) & 0xff00U;
    b2 = (x >> 8) & 0xff0000U;
    b3 = (x << 8) & 0xff000000U;
    return b0 | b1 | b2 | b3;
}


void convert_fp_rep(void *p, int old_rep, int new_rep, int type)
{
    uint32_t *f = (uint32_t *)p;
    if (old_rep == new_rep) return;
/*
 * type == 0 for sfloat, 1 for single float, 2 for double and 3 for extended.
 * in CSL mode only case 2 can arise. If I ever implement "long floats"
 * (ie 80-bit values) I will need to re-visit this code.
 */
    if (type >= 2 && ((old_rep ^ new_rep) & FP_WORD_ORDER))
    {   uint32_t w = f[0];
        f[0] = f[1];
        f[1] = w;
    }
/*
 * Note that I flip the bytes in each word and ALSO flip the order of the
 * words to achieve a full 64-bit flip here.
 */
    if ((old_rep ^ new_rep) & FP_BYTE_ORDER)
    {   f[0] = flip_32bits(f[0]);
        if (type >= 2) f[1] = flip_32bits(f[1]);
    }
    return;
}

static void adjust(Lisp_Object *cp)
/*
 * If p is a pointer to an object that has moved, adjust it.
 */
{
    Lisp_Object nil = C_nil, p = flip_bytes(*cp);
/*
 * The value 0 ought not to occur, but to be conservative I detect it and
 * treat it as signalling NIL.
 */
    if  (p == SPID_NIL || p == 0) *cp = nil;
    else if (is_cons(p))
    {   intptr_t h = (intptr_t)heap_pages[(p>>PAGE_BITS) & PAGE_MASK];
/* If I am expanding a 32-bit image onto a 64-bit computer then I will
 * have allocated double-sized pages (on a temporary basis) and placed
 * all items at exactly twice their original offset from the page
 * start. But note that OFFSET_MASK only allows for offsets up to the
 * normal page size.
 */
        p &= OFFSET_MASK;
/*
 * In a bunch of places that I check for converting_to_64 I only do so if
 * SIXTY_FOUR_BIT is set. That is because SIXTY_FOUR_BIT is something that
 * (while not a constant at preprocessor time) is a constant by the stage
 * that compiler optimisation should be being done, and so on 32-bit
 * machines the extra work should be removed totally... at least of the
 * compiler is up to scratch.
 * Note that TAG_CONS=0 so merely doubling the offset field here is OK.
 */
        if (SIXTY_FOUR_BIT && converting_to_64) p *= 2;
        *cp = (Lisp_Object)((char *)quadword_align_up(h) + p);
    }
    else if (is_immed_or_cons(p))
    {
#ifdef COMMON
        if (is_sfloat(p))
        {   intptr_t w = flip_32(p);    /* delicate here!! */
            convert_fp_rep((void *)&w, old_fp_rep, current_fp_rep, 0);
            *cp = w;
            continue;
        }
#endif
/*
 * A further messiness here! If I am remapping from a 64 bit image to a
 * 32-bit one I will move all bps items down one word (leaving their
 * headers starting doubleword aligned as before). So I need to change
 * all references to them.
 */
        if (converting_to_32 && is_bps(p)) p -= 0x100;
        else if (SIXTY_FOUR_BIT && converting_to_64 && is_bps(p))
        {    uint32_t page = ((uint32_t)p)>>(PAGE_BITS+6);
/*
 * Here I want to double the offset within the page. The key complication
 * is that the 32-bit packed value here only has room to cope with a
 * reference into a normal-sized page, but I need to double all offsets.
 * I deal with that by using the bottom bit of the upper 32-bits as an
 * extension of the offset. So all NORMAL references will have their top
 * half all zero, while special ones that arise only when expanding an
 * image will have non-zerop top half.
 */
             uint32_t offset = (((uint32_t)p) >> 5) & (2*PAGE_POWER_OF_TWO-8);
             uint64_t x = (offset >> PAGE_BITS) & 1;
             offset &= (PAGE_POWER_OF_TWO-8);
             p = (x<<32) | (page<<(PAGE_BITS+6)) | (offset<<6) | TAG_BPS;
        }
        *cp = p;   /* Immediate data here */
    }
    else
    {   intptr_t h = (intptr_t)vheap_pages[(p>>PAGE_BITS) & PAGE_MASK];
        p &= OFFSET_MASK;
/* Here I must double the offset but preserve the tag information */
        if (SIXTY_FOUR_BIT && converting_to_64) p += (p & ~TAG_BITS);
        *cp = (Lisp_Object)((char *)doubleword_align_up(h) + p);
    }
}

/*
 * expand_to_64() must take a 32-bit value that is in potentially flipped
 * byte order and convert it into a (potentially byte flipped) 64-bit value
 * by sign extending it. So the cast to int32_t here is to ensure that it is
 * signed so that the cast to int64_t sign extends (this is vital for
 * fixnums). Similarly shrink_to_32 must understand that it is working on
 * possibly flipped values.
 * Observe that if byte-flipping is not required then things become a little
 * easier and hence faster, so I specialize on that case.
 */

#define expand_to_64(x) \
    (flip_needed ? (Lisp_Object)flip_64bits((int64_t)(int32_t)flip_32bits(x)) : \
     ((Lisp_Object)(int64_t)(int32_t)(x)))

#define shrink_to_32(x) \
    (flip_needed ? (Lisp_Object)flip_32bits((int32_t)flip_64bits(x)) : \
     (Lisp_Object)(x))

static void adjust_consheap(void)
{
/*
 * layout of CONS heap:
 *
 * The lowest 32-bit of the heap contains a value "low" that is the offset
 * (in bytes) of the lowest active data in the heap. From there up to
 * CSL_PAGE_SIZE the page is just full on pairs of Lisp_Objects.
 * when allocating within the heap I create new cells downwards, and I
 * stop as I approach the bottom of the page. I leave SPARE bytes free
 * in simple cases so that I can overrun that limit a bit in functions that
 * want to perform up to around 3 cons operations but with only one overflow
 * test.
 *
 * On a temporary basis when loading a 64-bit image into a 32-bit system I
 * can create a double-sized page where the top limit is 2*CSL_PAGE_SIZE
 * and I will need some way to identify that when I come to garbage collect.
 */
    nil_as_base
    int32_t page_number;
    for (page_number = 0; page_number < heap_pages_count; page_number++)
    {   void *page = heap_pages[page_number];
        char *low = (char *)quadword_align_up((intptr_t)page);
        char *start = low +
            (converting_to_64 ? 2*CSL_PAGE_SIZE : CSL_PAGE_SIZE);
        int32_t len = flip_32((uint32_t)car32(low));
        char *fr;
        if (SIXTY_FOUR_BIT && converting_to_64)
        {
/* If I am converting from a 32-bit image to a 64-bit one I need to
 * expand each cell into one that is double its width. And when I do so
 * here I will need to reflect that the items stored have not yet had
 * any byte-order corrections applied.
 */
            char *oldp = low + CSL_PAGE_SIZE;
            char *newp = low + 2*CSL_PAGE_SIZE;
            fr = low + len;
/*
 * The "-8" and "-16" above reflect the size of Cons cells in the new and
 * old heap. So oldp points to the top existing 32-bit cell, and newp to
 * where it must be copied to. fr points to the lowest cell in use in the
 * 32-bit world. Note that each cell is copied to a location that has
 * exactly twice the offset from the start of page that it originally had.
 */
            while (oldp >= fr)
            {   oldp -= 4;
                newp -= 8;
                *(Lisp_Object *)newp = expand_to_64(*(int32_t *)oldp);
                oldp -= 4;
                newp -= 8;
                *(Lisp_Object *)newp = expand_to_64(*(int32_t *)oldp);
            }
/*
 * Done! By copying from the top downwards I will never overwrite what I
 * am reading from. Now the low point of the new heap should be just
 * twice the original value.
 */
            len *= 2;
        }
        else if (converting_to_32)
        {
/*
 * If the original image was a 64-bit one but the new one is 32-bits I just
 * need to truncate every cell to 32-bits and fill in the gaps that are
 * left with something safe. Well the gaps should in fact never get inspected
 * and so leaving mess in them ought to be OK - but of I look forward to
 * a future potential conservative garbage collectoe that may change at
 * least slightly, so I will try to be tidy here. The bit-pattern I use
 * to fill, 0x01000001 remains unchanged when byte-flipped and denotes
 * a fixnum either way.
 */
            fr = low + len;
            while (fr < start)
            {   *(Lisp_Object *)fr = shrink_to_32(*(int64_t *)fr);
                *(Lisp_Object *)(fr+4) = shrink_to_32(*(int64_t *)(fr+8));
                *(Lisp_Object *)(fr+8) =
                    *(Lisp_Object *)(fr+12) = 0x01000001;
                fr += 16;
            }
        }
        car32(low) = len;
        fr = low + len;
        fringe = (Lisp_Object)fr;
        heaplimit = (Lisp_Object)(low + SPARE);
#ifdef DEBUG_WIDTH
        {   int32_t *w = (int32_t *)fringe;
            printf("Consheap\n");
            while ((char *)w < start)
            {   printf("%p %.8x: %.8x%.8x %.8x%.8x\n",
                       w, (int)((char *)w-low), w[1], w[0], w[3], w[2]);
                w += 4;
            }
            printf("\n");
        }
#endif
        while (fr < start)
        {   adjust((Lisp_Object *)fr);
            fr += sizeof(Lisp_Object);
        }
#ifdef DEBUG_WIDTH
        {   int32_t *w = (int32_t *)fringe;
            printf("Adjusted Consheap\n");
            while ((char *)w < start)
            {   printf("%p %.8x: %.8x%.8x %.8x%.8x\n",
                       w, (int)((char *)w-low), w[1], w[0], w[3], w[2]);
                w += 4;
            }
            printf("\n");
        }
#endif
    }
}

entry_point1 entries_table1[] =
{
/*
 * All values that can go in the function cells of symbols to stand for
 * special interpreter activity are kept here. In most cases where there
 * is an entrypoint there is a corresponding one that behaves just the
 * same except that it has tracing enabled.
 */
    {0,                                  "illegal"},
    {undefined1,                         "undefined1"},
    {autoload1,                          "autoload1"},
    {interpreted1,                       "interpreted1"},
    {traceinterpreted1,                  "traceinterpreted1"},
    {double_interpreted1,                "double_interpreted1"},
    {funarged1,                          "funarged1"},
    {tracefunarged1,                     "tracefunarged1"},
    {double_funarged1,                   "double_funarged1"},
    {bytecoded1,                         "bytecoded1"},
    {tracebytecoded1,                    "tracebytecoded1"},
    {double_bytecoded1,                  "double_bytecoded1"},
    {byteopt1,                           "byteopt1"},
    {tracebyteopt1,                      "tracebyteopt1"},
    {double_byteopt1,                    "double_byteopt1"},
    {hardopt1,                           "hardopt1"},
    {tracehardopt1,                      "tracehardopt1"},
    {double_hardopt1,                    "double_hardopt1"},
    {byteoptrest1,                       "byteoptrest1"},
    {tracebyteoptrest1,                  "tracebyteoptrest1"},
    {double_byteoptrest1,                "double_byteoptrest1"},
    {hardoptrest1,                       "hardoptrest1"},
    {tracehardoptrest1,                  "tracehardoptrest1"},
    {double_hardoptrest1,                "double_hardoptrest1"},
    {too_few_2,                          "too_few_2"},
    {wrong_no_0a,                        "wrong_no_0a"},
    {wrong_no_3a,                        "wrong_no_3a"},
    {wrong_no_na,                        "wrong_no_na"},

/*
 * The batch here relate to function re-work that discards unwanted
 * extra arguments.
 */
    {f1_as_0,                            "1->0"},
    {f1_as_1,                            "1->1"},
#ifdef JIT
    {jitcompileme1,                      "jitcompileme1"},
#endif
#ifdef CJAVA
    {java1,                              "java1"},
#endif
    {NULL,                               "dummy"}
};

#define entry_table_size1 (sizeof(entries_table1)/sizeof(entries_table1[0]))

entry_point2 entries_table2[] =
{
    {0,                                  "illegal"},
    {undefined2,                         "undefined2"},
    {autoload2,                          "autoload2"},
    {interpreted2,                       "interpreted2"},
    {traceinterpreted2,                  "traceinterpreted2"},
    {double_interpreted2,                "double_interpreted2"},
    {funarged2,                          "funarged2"},
    {tracefunarged2,                     "tracefunarged2"},
    {double_funarged2,                   "double_funarged2"},
    {bytecoded2,                         "bytecoded2"},
    {tracebytecoded2,                    "tracebytecoded2"},
    {double_bytecoded2,                  "double_bytecoded2"},
    {byteopt2,                           "byteopt2"},
    {tracebyteopt2,                      "tracebyteopt2"},
    {double_byteopt2,                    "double_byteopt2"},
    {hardopt2,                           "hardopt2"},
    {tracehardopt2,                      "tracehardopt2"},
    {double_hardopt2,                    "double_hardopt2"},
    {byteoptrest2,                       "byteoptrest2"},
    {tracebyteoptrest2,                  "tracebyteoptrest2"},
    {double_byteoptrest2,                "double_byteoptrest2"},
    {hardoptrest2,                       "hardoptrest2"},
    {tracehardoptrest2,                  "tracehardoptrest2"},
    {double_hardoptrest2,                "double_hardoptrest2"},
    {too_many_1,                         "too_many_1"},
    {wrong_no_0b,                        "wrong_no_0b"},
    {wrong_no_3b,                        "wrong_no_3b"},
    {wrong_no_nb,                        "wrong_no_nb"},
/*
 * The batch here relate to function re-work that discards unwanted
 * extra arguments.
 */
    {f2_as_0,                            "2->0"},
    {f2_as_1,                            "2->1"},
    {f2_as_2,                            "2->2"},
#ifdef JIT
    {jitcompileme2,                      "jitcompileme2"},
#endif
#ifdef CJAVA
    {java2,                              "java2"},
#endif
    {NULL,                               "dummy"}
};

#define entry_table_size2 (sizeof(entries_table2)/sizeof(entries_table2[0]))

entry_pointn entries_tablen[] =
{
    {0,                                  "illegal"},
    {undefinedn,                         "undefinedn"},
    {autoloadn,                          "autoloadn"},
    {interpretedn,                       "interpretedn"},
    {traceinterpretedn,                  "traceinterpretedn"},
    {double_interpretedn,                "double_interpretedn"},
    {funargedn,                          "funargedn"},
    {tracefunargedn,                     "tracefunargedn"},
    {double_funargedn,                   "double_funargedn"},
    {bytecoded0,                         "bytecoded0"},
    {tracebytecoded0,                    "tracebytecoded0"},
    {double_bytecoded0,                  "double_bytecoded0"},
    {bytecoded3,                         "bytecoded3"},
    {tracebytecoded3,                    "tracebytecoded3"},
    {double_bytecoded3,                  "double_bytecoded3"},
    {bytecodedn,                         "bytecodedn"},
    {tracebytecodedn,                    "tracebytecodedn"},
    {double_bytecodedn,                  "double_bytecodedn"},
    {byteoptn,                           "byteoptn"},
    {tracebyteoptn,                      "tracebyteoptn"},
    {double_byteoptn,                    "double_byteoptn"},
    {hardoptn,                           "hardoptn"},
    {tracehardoptn,                      "tracehardoptn"},
    {double_hardoptn,                    "double_hardoptn"},
    {byteoptrestn,                       "byteoptrestn"},
    {tracebyteoptrestn,                  "tracebyteoptrestn"},
    {double_byteoptrestn,                "double_byteoptrestn"},
    {hardoptrestn,                       "hardoptrestn"},
    {tracehardoptrestn,                  "tracehardoptrestn"},
    {double_hardoptrestn,                "double_hardoptrestn"},
    {wrong_no_1,                         "wrong_no_1"},
    {wrong_no_2,                         "wrong_no_2"},
/*
 * The batch here relate to function variants that discard unwanted
 * extra arguments and call something else.
 */
    {f0_as_0,                            "0->0"},
    {f3_as_0,                            "3->0"},
    {f3_as_1,                            "3->1"},
    {f3_as_2,                            "3->2"},
    {f3_as_3,                            "3->3"},
#ifdef JIT
    {jitcompileme0,                      "jitcompileme0"},
    {jitcompileme3,                      "jitcompileme3"},
    {jitcompilemen,                      "jitcompilemen"},
#endif
#ifdef CJAVA
    {java0,                              "java0"},
    {java3,                              "java3"},
    {javan,                              "javan"},
#endif
    {NULL,                               "dummy"}
};

#define entry_table_sizen (sizeof(entries_tablen)/sizeof(entries_tablen[0]))

entry_pointn entries_tableio[] =
{
    {0,                                          "illegal"},
    {(void *)char_from_illegal,                  "char_from_illegal"},
    {(void *)char_to_illegal,                    "char_to_illegal"},
    {(void *)read_action_illegal,                "read_action_illegal"},
    {(void *)write_action_illegal,               "write_action_illegal"},
    {(void *)char_from_terminal,                 "char_from_terminal"},
    {(void *)char_to_terminal,                   "char_to_terminal"},
    {(void *)read_action_terminal,               "read_action_terminal"},
    {(void *)write_action_terminal,              "write_action_terminal"},
    {(void *)char_from_file,                     "char_from_file"},
    {(void *)char_to_file,                       "char_to_file"},
    {(void *)read_action_file,                   "read_action_file"},
    {(void *)read_action_output_file,            "read_action_output_file"},
    {(void *)write_action_file,                  "write_action_file"},
    {(void *)binary_outchar,                     "binary_outchar"},
    {(void *)char_from_list,                     "char_from_list"},
    {(void *)char_to_list,                       "char_to_list"},
    {(void *)code_to_list,                       "code_to_list"},
    {(void *)read_action_list,                   "read_action_list"},
    {(void *)write_action_list,                  "write_action_list"},
    {(void *)count_character,                    "count_character"},
    {(void *)char_to_pipeout,                    "char_to_pipeout"},
    {(void *)write_action_pipe,                  "write_action_pipe"},
    {(void *)char_from_synonym,                  "char_from_synonym"},
    {(void *)char_to_synonym,                    "char_to_synonym"},
    {(void *)read_action_synonym,                "read_action_synonym"},
    {(void *)write_action_synonym,               "write_action_synonym"},
    {(void *)char_from_concatenated,             "char_from_concatenated"},
    {(void *)char_to_broadcast,                  "char_to_broadcast"},
    {(void *)read_action_concatenated,           "read_action_concatenated"},
    {(void *)write_action_broadcast,             "write_action_broadcast"},
    {(void *)char_from_echo,                     "char_from_echo"},
    {NULL,                                       "dummy"}
};

#define entry_table_sizeio (sizeof(entries_tableio)/sizeof(entries_tableio[0]))



static struct entry_lookup1
{   int32_t code;
    one_args *entry;
    char *s;
} entry_lookup1[entry_table_size1];

static struct entry_lookup2
{   int32_t code;
    two_args *entry;
    char *s;
} entry_lookup2[entry_table_size2];

static struct entry_lookupn
{   int32_t code;
    n_args *entry;
    char *s;
} entry_lookupn[entry_table_sizen];

static int MS_CDECL order_lookup_entries(void const *aa, void const *bb)
{
/*
 * I rely here on having entry_lookup[1,2,n] all the same shape so that
 * when I want to sort I only use one comparison function.
 */
    struct entry_lookup1 *a = (struct entry_lookup1 *)aa,
                         *b = (struct entry_lookup1 *)bb;
    intptr_t ap = (intptr_t)a->entry, bp = (intptr_t)b->entry;
    if (ap < bp) return -1;
    else if (ap > bp) return 1;
    else return 0;
} 

void set_up_entry_lookup(void)
/*
 * This makes a sorted version of entries_table.  Since the table is
 * only a few dozen words long it hardly seems worth being too clever,
 * but the C library provides qsort() for me so I use it.
 */
{
    int i;
    for (i=0; i<entry_table_size1; i++)
    {   entry_lookup1[i].code = i;
        entry_lookup1[i].entry = entries_table1[i].p;
        entry_lookup1[i].s = entries_table1[i].s;
    }
    qsort((void *)entry_lookup1,
          entry_table_size1, sizeof(struct entry_lookup1),
          order_lookup_entries);
    for (i=0; i<entry_table_size2; i++)
    {   entry_lookup2[i].code = i;
        entry_lookup2[i].entry = entries_table2[i].p;
        entry_lookup2[i].s = entries_table2[i].s;
    }
    qsort((void *)entry_lookup2,
          entry_table_size2, sizeof(struct entry_lookup2),
          order_lookup_entries);
    for (i=0; i<entry_table_sizen; i++)
    {   entry_lookupn[i].code = i;
        entry_lookupn[i].entry = entries_tablen[i].p;
        entry_lookupn[i].s = entries_tablen[i].s;
    }
    qsort((void *)entry_lookupn,
          entry_table_sizen, sizeof(struct entry_lookupn),
          order_lookup_entries);
}

int32_t code_up_fn1(one_args *e)
{
    int low = 0, high = entry_table_size1-1;
    while (low < high)
    {   int mid = (high + low)/2;
        intptr_t s = (intptr_t)entry_lookup1[mid].entry;
        if (s == (intptr_t)e) return entry_lookup1[mid].code;
        if ((intptr_t)s < (intptr_t)e) low = mid + 1;
        else high = mid - 1;
    }
    if (low == high &&
        entry_lookup1[low].entry == e) return entry_lookup1[low].code;
    else return 0;
}

int32_t code_up_fn2(two_args *e)
{
    int low = 0, high = entry_table_size2-1;
    while (low < high)
    {   int mid = (high + low)/2;
        intptr_t s = (intptr_t)entry_lookup2[mid].entry;
        if (s == (intptr_t)e) return entry_lookup2[mid].code;
        if ((intptr_t)s < (intptr_t)e) low = mid + 1;
        else high = mid - 1;
    }
    if (low == high &&
        entry_lookup2[low].entry == e) return entry_lookup2[low].code;
    else return 0;
}

int32_t code_up_fnn(n_args *e)
{
    int low = 0, high = entry_table_sizen-1;
    while (low < high)
    {   int mid = (high + low)/2;
        intptr_t s = (intptr_t)entry_lookupn[mid].entry;
        if (s == (intptr_t)e) return entry_lookupn[mid].code;
        if ((intptr_t)s < (intptr_t)e) low = mid + 1;
        else high = mid - 1;
    }
    if (low == high &&
        entry_lookupn[low].entry == e) return entry_lookupn[low].code;
    else return 0;
}

int32_t code_up_io(void *e)
{
    int i;
    for (i=0; i<entry_table_sizen; i++)
    {   if (entries_tableio[i].p == e) return i;
    }
    return 0;
}

#define make_padder(n) (TYPE_VEC8 + ((n)<<10) + TAG_ODDS)

static void shrink_vecheap_page_to_32(char *p, char *fr)
{
    if (!SIXTY_FOUR_BIT)
    {   int32_t *newp;  /* specific widths used here */
        int64_t *oldp;
        int i, len;
        while (p < fr)
        {
/* Fetch header as a 64-bit value, truncate to 32-bit */
            Header h = (Header)flip_64(*(int64_t *)p), h1;
#ifdef DEBUG_WIDTH
/*
 * I use printf() not term_printf() here because at the stage I run this
 * code I can not be confident that Lisp-style streams are fully set up.
 * And the debug display here is only DEBUG display and so I do not feel
 * to bad if it is generated in a way that could conflict with use of a
 * windowed application.
 */
            printf("p=%p Header = %.16llx = %.16llx (is_sym=%d)\n",
                    p, *(long long *)p, (long long)h, (int)is_symbol_header(h));
            printf("Length = %d\n", (int)length_of_header(h));
            for(i=-32; i<=32; i+=4)
            {    if (i == 0) printf("\n%p: ", p);
                 printf("%.8x ", *(int32_t *)(p+i));
                 if (i==0) printf("\n");
            }
            printf("\n");
            fflush(stdout);
            if (!is_symbol_header(h) && length_of_header(h) == 0) exit(8);
#endif
            if (is_symbol_header(h))
            {
/*
 * Symbol headers do not contain any explicit length info and so do not
 * need to be changed at all here.
 */
#ifdef DEBUG_WIDTH
                for (i=0; i<80; i+=4)
                {   printf("%.8x ", *(int32_t *)(p+i));
                    if (((i/4)%8) == 7) printf("\n");
                }
                printf("\n");
#endif
                *(Lisp_Object *)p = flip_32(h); /* write back header */
/*
 * I do not know if I police it anywhere, but if one tried to mix images from
 * COMMON and plain mode the result would be a crash, if only because symbols
 * are represented as a different length. That is because in Common Lisp mode
 * there has to be an extra field to hold the identity of the package that
 * a symbol lives in.
 */
                for (i=1; i<(symhdr_length/4); i++)
                {   ((Lisp_Object *)p)[i] =
                        shrink_to_32(((int64_t *)p)[i]);
                }
/*
 * Insert a padding vector - a byte-vector should be a safe case to use. I
 * provide myself with a "make_padder" macro to create the relevant header.
 * I do not tidy up the contents of the padder block, but since the block is
 * tagged as a vector of 8 bit bytes this does not matter.
 */
                *(Lisp_Object *)(p+symhdr_length) =
                    flip_32(make_padder(symhdr_length));
#ifdef DEBUG_WIDTH
                for (i=0; i<80; i+=4)
                {   printf("%.8x ", *(int32_t *)(p+i));
                    if (((i/4)%8) == 7) printf("\n");
                }
                printf("\n");
#endif
                p += 2*symhdr_length;
            }
            else switch (type_of_header(h))
            {
/*
 * If I do not have a symbol then I have some sort of vector where the
 * header word contains length information. I need to discriminate here
 * between all the cases where the following data is in 64-bit fields
 * (and so needs truncating to fit in 32) as against cases where the
 * follow-on data is in 8, 16 or 32-bit chunks in a format that does not
 * depend on the word-length of the host machine. It seems fairly important
 * that I cover every possible sort of tag that could ever exist.
 */
#ifdef COMMON
        case TYPE_RATNUM:
        case TYPE_COMPLEX_NUM:
#endif
        case TYPE_HASH:
        case TYPE_SIMPLE_VEC:
        case TYPE_ARRAY:
        case TYPE_STRUCTURE:
        case TYPE_MIXED1:
        case TYPE_MIXED2:
        case TYPE_MIXED3:
        case TYPE_STREAM:
/*      case TYPE_LITVEC: */
/*
 * "len" will be the length of the old 64-bit version, and in the 64-bit
 * world there will never be a padding word at the end of a vector.
 */
                len = doubleword_align_up(length_of_header(h));
#ifdef DEBUG_WIDTH
                printf("Shrinking vec to 32 bits:\n");
                for (i=0; i<len; i+=4)
                {   printf("%.8x ", *(int32_t *)(p+i));
                    if (((i/4) % 8) == 7) printf("\n");
                }
                printf("\n");
#endif
                newp = (int32_t *)p;
                oldp = (int64_t *)p;
                for (i=8; i<len; i+=8)
                {   ++newp;
                    ++oldp;
                    *newp = shrink_to_32(*oldp);
                }
/*
 * Now the length needed in the new header will be (newp-p+4)
 */
                h1 = (h & 0x3ff) | ((((char *)newp)-p+4)<<10);
#ifdef DEBUG_WIDTH
                printf("new object length = %d, h=%.8x\n",
                       (int)(((char *)newp)-p+4), (int)h1);
#endif
                *(Lisp_Object *)p = flip_32(h1); /* write back header */
                if ((4 & (intptr_t)newp) == 0)
                    *++newp = SPID_NIL; /* fill to doubleword */
                p += len;
/*
 * Now I must put in a padding object if needed to fill any gap left.
 * There would be no gap if the original vector had length zero, otherwise
 * I put in something that looks like a vector of bytes or like BPS.
 */
                newp++;
                if (p != (char *)newp)
                    *newp = flip_32(make_padder(p - (char *)newp));
#ifdef DEBUG_WIDTH
                printf("AFTER shrinking vec to 32 bits:\n");
                for (i=0; i<len; i+=4)
                {   printf("%.8x ", *(int32_t *)(p-len+i));
                    if (((i/4) % 8) == 7) printf("\n");
                }
                printf("\n");
#endif
                break;
        case TYPE_STRING:
#ifdef DEBUG_WIDTH
                printf("String: %p: \"%s\"\n", p, ((char *)p)+2*CELL);
#endif
        case TYPE_BIGNUM:
        case TYPE_VEC32:
        case TYPE_VEC16:
/*      case TYPE_VEC8:                  same as TYPE_BPS */
        case TYPE_BPS:
        case TYPE_SPARE:
        case TYPE_SP:
#ifdef COMMON
        case TYPE_BITVEC1:
        case TYPE_BITVEC2:
        case TYPE_BITVEC3:
        case TYPE_BITVEC4:
        case TYPE_BITVEC5:
        case TYPE_BITVEC6:
        case TYPE_BITVEC7:
        case TYPE_BITVEC8:
        case TYPE_SINGLE_FLOAT:
        case TYPE_LONG_FLOAT:
#endif
        case TYPE_DOUBLE_FLOAT:
        case TYPE_FLOAT32:
        case TYPE_FLOAT64:
                len = doubleword_align_up(length_of_header(h));
/* I copy all the stuff that will go into the 32-bit version */
#ifdef DEBUG_WIDTH
                for (i=-16; i<=8; i+=4) printf("%.8x ", *(int32_t *)(p+len+i)); printf("\n");
#endif
                for (i=4; i<len-4; i+=4)
                    *(uint32_t *)(p+i) =
                        *(uint32_t *)(p+i+4);
/*
 * These all shrink by one word because their header word has become
 * 4 bytes rather than 8 bytes wide. This certainly means that there is
 * a 32-bit word beyond the stuff that I copy that I can and should fill
 * with zero. Sometimes this will end up counting as part of the new
 * 32-bit representation, sometimes it will be part of a gap left over.
 * If I were very keen I could put in a zero as required when it is the
 * word used to round up a vector size of an even number of words, and
 * make_padder(8) when it represents a gap between real items.
 */
                *(uint32_t *)(p+len-4) = 0;
#ifdef DEBUG_WIDTH
                for (i=-16; i<=8; i+=4) printf("%.8x ", *(int32_t *)(p+len+i)); printf("\n");
#endif
/*
 * Here I write the header word back into memory shortening things by
 * 4 bytes because the header has changed from a 64 to a 32-bit value.
 * But I then expect to find the next item the distance on that the
 * 64-bit header indicated.
 */
#ifdef DEBUG_WIDTH
                printf("h=%.8x h1=%.8x\n", (int)h, (int)h - (4<<10));
#endif
                *(Lisp_Object *)p = flip_32(h - (4<<10)); /* write back header */
#ifdef DEBUG_WIDTH
                printf("move on after binary stuff by %d\n", len);
                printf("len=%d len-4=%d\n", (int)len, (int)doubleword_align_up(length_of_header(h)-4));
#endif
/* Test if the vector has shrunk in memory - if so insert padding */
                if (len != doubleword_align_up(length_of_header(h)-4))
                    *(int32_t *)(p + len - 8) = flip_32(make_padder(8));
#ifdef DEBUG_WIDTH
                for (i=-16; i<=8; i+=4) printf("%.8x ", *(int32_t *)(p+len+i)); printf("\n");
#endif
                p += len;
                break;
        default:
                printf("Unrecognized type info in vector header %.8x\n", (int32_t)h);
                fflush(stdout);
                my_exit(4);
            }
        }
    }
}

/*
 * In what follows low will point to the 64-bit vector to be filled in
 * and olow to the 32-bit one being copied. fr is the fringe in the
 * 64-bit world. Much of the logic here is closely related to that in
 * shrink_vecheap_page. If SIXTY_FOUR_BIT could be a compile-time
 * constant I could use #ifdef to avoid compiling one or the other
 * of these. As things are I can get most of the benefit of that if
 * I have a good optimising compiler.
 */

static void expand_vecheap_page(char *low, char *olow, char *fr)
{
    if (SIXTY_FOUR_BIT)
    {
        int64_t *newp = (int64_t *)low;  /* specific widths used here */
        int32_t *oldp = (int32_t *)olow;
        int i, len;
        while ((char *)newp < fr)
        {
/* Fetch header as a 32-bit value, widen to 64-bit */
            Header h = (Header)flip_32(*oldp), h1;
#ifdef DEBUG_WIDTH
/*
 * I use printf() not term_printf() here because at the stage I run this
 * code I can not be confident that Lisp-style streams are fully set up.
 * And the debug display here is only DEBUG display and so I do not feel
 * to bad if it is generated in a way that could conflict with use of a
 * windowed application.
 */
            printf("oldp=%p Header = %.16llx (%d)\n", oldp, (long long)h, (int)is_symbol_header(h));
            printf("Length = %d\n", (int)length_of_header(h));
            for(i=-32; i<=32; i+=4)
            {    if (i == 0) printf("\n%p: ", oldp);
                 printf("%.8x ", *(int32_t *)(((char *)oldp)+i));
                 if (i == 0) printf("\n");
            }
            printf("\n");
            fflush(stdout);
            if (!is_symbol_header(h) && length_of_header(h) == 0) exit(8);
#endif
            if (is_symbol_header(h))
            {
/*
 * Symbol headers do not contain any explicit length info and so do not
 * need to be changed at all here.
 */
#ifdef DEBUG_WIDTH
                for (i=0; i<80; i+=4)
                {   printf("%.8x ", *(int32_t *)((char *)oldp+i));
                    if (((i/4)%8) == 7) printf("\n");
                }
                printf("\n");
#endif
                *newp = flip_64(h); /* write back header */
/*
 * I do not know if I police it anywhere, but if one tried to mix images from
 * COMMON and plain mode the result would be a crash, if only because symbols
 * are represented as a different length. That is because in Common Lisp mode
 * there has to be an extra field to hold the identity of the package that
 * a symbol lives in.
 */
                for (i=1; i<(symhdr_length/8); i++)
                {   newp[i] = expand_to_64(oldp[i]);
                }
                oldp = (int32_t *)((char *)oldp + symhdr_length/2);
                newp = (int64_t *)((char *)newp + symhdr_length);
            }
            else switch (type_of_header(h))
            {
/*
 * If I do not have a symbol then I have some sort of vector where the
 * header word contains length information. I need to discriminate here
 * between all the cases where the following data is in 64-bit fields
 * (and so needs truncating to fit in 32) as against cases where the
 * follow-on data is in 8, 16 or 32-bit chunks in a format that does not
 * depend on the word-length of the host machine. It seems fairly important
 * that I cover every possible sort of tag that could ever exist.
 */
#ifdef COMMON
        case TYPE_RATNUM:
        case TYPE_COMPLEX_NUM:
#endif
        case TYPE_HASH:
        case TYPE_SIMPLE_VEC:
        case TYPE_ARRAY:
        case TYPE_STRUCTURE:
        case TYPE_MIXED1:
        case TYPE_MIXED2:
        case TYPE_MIXED3:
        case TYPE_STREAM:
/*      case TYPE_LITVEC: */
/*
 * "len" will be the length of the old 32-bit version, and the data in
 * memory may have a padder word after that. However the 64-bit version I
 * copy this into never needs a padder word as part of the vector itself,
 * but to preserve layout it may need one after it. Note that for all
 * these sorts of vector the length should already be a multiple of 4. I
 * remind myself of that because strings (for instance) can have odd lengths
 * recorded in the header.
 */
                len = length_of_header(h);
                *newp++ = flip_64((h & 0x3ff) + (len<<11)); /* double length */
                oldp++;
                for (i=4; i<len; i+=4)
                {   *newp++ = expand_to_64(*oldp);
                    oldp++;
                }
/*
 * Now if the 32-bit vector has a length that corresponded to an even
 * number of cells of data (so with the header that makes an odd number
 * in all) I need to skip over the padder word in the 32-bit space and
 * write in something safe in the 64-bit one.
 */
                if ((len & 4) != 0)
                {   *newp++ = flip_64(make_padder(8));
                    oldp++;
                }
                break;
        case TYPE_STRING:
#ifdef DEBUG_WIDTH
                printf("String: %p: \"%s\"\n", oldp, ((char *)oldp)+4);
#endif
        case TYPE_BIGNUM:
        case TYPE_VEC32:
        case TYPE_VEC16:
/*      case TYPE_VEC8:                  same as TYPE_BPS */
        case TYPE_BPS:
        case TYPE_SPARE:
        case TYPE_SP:
#ifdef COMMON
        case TYPE_BITVEC1:
        case TYPE_BITVEC2:
        case TYPE_BITVEC3:
        case TYPE_BITVEC4:
        case TYPE_BITVEC5:
        case TYPE_BITVEC6:
        case TYPE_BITVEC7:
        case TYPE_BITVEC8:
        case TYPE_SINGLE_FLOAT:
        case TYPE_LONG_FLOAT:
#endif
        case TYPE_DOUBLE_FLOAT:
        case TYPE_FLOAT32:
        case TYPE_FLOAT64:
/*
 * The effects of alignment and passing here are distinctly odd. A 32-bit
 * item can be in one of two forms
 *      || header | d0 || d1 | - ||          length 4 mod 8
 * or   || header | d0 || d1 | d2 ||         length 8 mod 8
 * where the double vertical bars denote doubleword boundaries and the "-"
 * is padder data.
 *
 * In the 64-bit world these two cases map onto
 *      || h e a d e r || d0 | d1 ||
 * and  || h e a d e r || d0 | d1 || d2 | - ||
 * in each case a dummy item must be places after to fill up space to where
 * the next new item will fall. Well actually there is a special case
 *      || header | d0 ||
 * ->   || h e a d e r || d0 | - ||
 * does not need that filler.
 * An item in the 32-bit world may sometimes only partly fill its final
 * 32-bit word. In this part of the code I can copy data as raw 32-bit
 * values - any byte-order adjustments get done later.
 */
                len = word_align_up(length_of_header(h));
/*
 * The vector increases in size of 4 bytes because the header-word is
 * twice as wide.
 */
                *newp++ = flip_64(h + (4<<10));
                oldp++;
/* Now newp, oldp point at the raw data. Copy it down */
                for (i=4; i<len; i+=4)
                {   *((int32_t *)newp) = *oldp;
                    newp = (int64_t *)(((char *)newp)+4);
                    oldp++;
                }
/*
 * Sometimes I need to pad out the new version to be a whole number of
 * doublewords.
 */
                if ((len & 4) == 0)
                {   *((int32_t *)newp) = 0;
                    newp = (int64_t *)(((char *)newp)+4);
                }
                else oldp++;
/*
 * Now I have oldp and newp both doubleword aligned again. In many
 * cases I now need to insert a dummy header at newp so that items in the
 * new space all end up at twice the address they had in the old.
 */
                len = 2*doubleword_align_up(len) -
                      doubleword_align_up(len+4);
/* len is now the amount of gap to fill */
                if (len != 0)
                {   *newp = flip_64(make_padder(len));
                    newp = (int64_t *)(((char *)newp) + len);
                }
#ifdef DEBUG_WIDTH
                for (i=-16; i<=8; i+=4) printf("%.8x ", *(int32_t *)(newp+len+i)); printf("\n");
#endif
                break;
    default:
                printf("Unrecognized type info in vector header %.8x\n", (int32_t)h);
                fflush(stdout);
                my_exit(4);
            }
        }
    }
}


static void adjust_vecheap(void)
{
    nil_as_base
    int32_t page_number;
    intptr_t iw;
    for (page_number = 0; page_number < vheap_pages_count; page_number++)
    {   void *page = vheap_pages[page_number];
        char *low = (char *)doubleword_align_up((intptr_t)page);
        int32_t len = flip_32((uint32_t)car32(low));
        char *fr;
        int i;
#ifdef DEBUG_WIDTH
        printf("len = %d = %x (%d:%.8x)\n", len, len, car32(low), car32(low));
        for (i=0; i<4*32; i+=4)
        {   printf("%.8x ", *(int32_t *)(low+i));
            if ((i/4)%8 == 7) printf("\n");
        }
        fflush(stdout);
#endif
        if (SIXTY_FOUR_BIT && converting_to_64) len *= 2;
        car32(low) = len;
        fr = low + len;
        vfringe = (Lisp_Object)fr;
        if (SIXTY_FOUR_BIT && converting_to_64)
            vheaplimit = (Lisp_Object)(low + 2*(CSL_PAGE_SIZE - 8));
        else vheaplimit = (Lisp_Object)(low + (CSL_PAGE_SIZE - 8));
        if (SIXTY_FOUR_BIT && converting_to_64)
        {   *(Header *)(low+8) = make_padder(8);
/*
 * I want all expanded vectors to fall at an address exactly twice
 * as far from the page base as they started. Hence the first one must start
 * at offset 16 not 8. I put a padder in at 8 to fill the gap.
 */
            low += 16;
        }
        else low += 8;
        if (converting_to_64)
        {
/*
 * vecheap allocation is from the low end of the heap upwards, and
 * because I have to parse the heap to perform the correct expansion
 * I must start from the bottom. To cope with that I have loaded
 * my 32-bit heap CSL_PAGE_SIZE bytes up into the double sized page.
 * Now when I copy stuff downwards the last item comes from
 * low+CSL_PAGE_SIZE+len and it gets written back to low+2*len. So since
 * len is at worst CSL_PAGE_SIZE-8 I will not trip over myself - just.
 */
            expand_vecheap_page(low, low+CSL_PAGE_SIZE-8, fr);
/*
 * Well in principle I know how to do this. The actual data is at present in
 * the top half of a double-sized page and I need to copy it down towards
 * the bottom sign-extended each Lisp_Object and (for tidiness) putting in
 * padding when items had been full of binary stuff that did not expand.
 */
        }
        else if (converting_to_32) shrink_vecheap_page_to_32(low, fr);
/*
 * Now the data is at least arranged to be the correct width.
 */
        while (low < fr)
        {   Header h = flip_bytes(*(Header *)low);
            *(Header *)low = h;
            if (is_symbol_header(h))
            {   Lisp_Object ss = (Lisp_Object)(low + TAG_SYMBOL);
                adjust(&qvalue(ss));
                adjust(&qenv(ss));
                adjust(&qpname(ss));
                adjust(&qplist(ss));
                adjust(&qfastgets(ss));
#ifdef COMMON
                adjust(&qpackage(ss));
#endif
/*
 * The mess here is because when CSL is re-loaded the position of all
 * C-coded entrypoints will very probably have changed since the
 * previous run - the set of entrypoints tested for here has to be
 * a complete list, except for ones established via "restart.c".  Note
 * that setup establishes entrypoints later on, so I can afford to leave
 * junk in the function cells of things that will be initialised then.
 * Thus if a "real" function pointer left over from last time happens
 * to look like one of the small integers used here to stand for special
 * built-in cases the false-hit I get here is not important.
 */
                iw = flip_bytes(ifn1(ss));
                if (0 < iw && iw < entry_table_size1)
                    ifn1(ss) = (intptr_t)entries_table1[iw].p;
                else ifn1(ss) = (intptr_t)undefined1;
                iw = flip_bytes(ifn2(ss));
                if (0 < iw && iw < entry_table_size2)
                    ifn2(ss) = (intptr_t)entries_table2[iw].p;
                else ifn2(ss) = (intptr_t)undefined2;
                iw = flip_bytes(ifnn(ss));
                if (0 < iw && iw < entry_table_sizen)
                    ifnn(ss) = (intptr_t)entries_tablen[iw].p;
                else ifnn(ss) = (intptr_t)undefinedn;
                qcount(ss) = flip_bytes(qcount(ss));
                low += symhdr_length;
                continue;
            }
            else switch (type_of_header(h))
            {
#ifdef COMMON
        case TYPE_RATNUM:
        case TYPE_COMPLEX_NUM:
                adjust((Lisp_Object *)(low+CELL));
                adjust((Lisp_Object *)(low+2*CELL));
                break;
#endif
        case TYPE_HASH:
        case TYPE_SIMPLE_VEC:
        case TYPE_ARRAY:
        case TYPE_STRUCTURE:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=CELL)
                    adjust((Lisp_Object *)(low+i));
                break;
        case TYPE_MIXED1:
        case TYPE_MIXED2:
        case TYPE_MIXED3:
        case TYPE_STREAM:
                for (i=CELL; i<4*CELL; i+=CELL) adjust((Lisp_Object *)(low+i));
                if (!SIXTY_FOUR_BIT)
                {   for (; i<doubleword_align_up(length_of_header(h)); i+=4)
                        *(uint32_t *)(low+i) =
                            flip_bytes(*(uint32_t *)(low+i));
                }
                if (type_of_header(h) == TYPE_STREAM)
                {   Lisp_Object ss = (Lisp_Object)(low + TAG_VECTOR);
                    iw = elt(ss, 4);
                    if (0 < iw && iw < entry_table_sizeio)
                        elt(ss, 4) = (intptr_t)entries_tableio[iw].p;
                    else elt(ss, 4) = (intptr_t)char_to_illegal;
                    iw = elt(ss, 5);
                    if (0 < iw && iw < entry_table_sizeio)
                        elt(ss, 5) = (intptr_t)entries_tableio[iw].p;
                    else elt(ss, 5) = (intptr_t)write_action_illegal;
                    iw = elt(ss, 8);
                    if (0 < iw && iw < entry_table_sizeio)
                        elt(ss, 8) = (intptr_t)entries_tableio[iw].p;
                    else elt(ss, 8) = (intptr_t)char_from_illegal;
                    iw = elt(ss, 9);
                    if (0 < iw && iw < entry_table_sizeio)
                        elt(ss, 9) = (intptr_t)entries_tableio[iw].p;
                    else elt(ss, 9) = (intptr_t)read_action_illegal;
                }
                break;
        case TYPE_BIGNUM:
        case TYPE_VEC32:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    *(uint32_t *)(low+i) =
                        flip_32(*(uint32_t *)(low+i));
                break;
        case TYPE_VEC16:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    *(uint32_t *)(low+i) =
                        flip_halfwords(*(uint32_t *)(low+i));
                break;
        case TYPE_DOUBLE_FLOAT:
/*
 * note that this conversion is triggered by the vector header, not by
 * the pointer to the object, so punning associated with the pnames of
 * un-printed gensyms will not cause any confusion.
 */
                convert_fp_rep((void *)(low + 8),
                               old_fp_rep, current_fp_rep, 2);
                break;
#ifdef COMMON
        case TYPE_SINGLE_FLOAT:
                convert_fp_rep((void *)(low + CELL),
                               old_fp_rep, current_fp_rep, 1);
                break;
        case TYPE_LONG_FLOAT:
/* Beware - if long floats move up to 3-word values the +8 here will change */
                convert_fp_rep((void *)(low + 8),
                               old_fp_rep, current_fp_rep, 3);
                break;
#endif
        case TYPE_FLOAT32:
                for (i=CELL; i<doubleword_align_up(length_of_header(h)); i+=4)
                    convert_fp_rep((void *)(low+i),
                                   old_fp_rep, current_fp_rep, 1);
                break;
        case TYPE_FLOAT64:
                for (i=8; i<doubleword_align_up(length_of_header(h)); i+=8)
                    convert_fp_rep((void *)(low+i),
                                   old_fp_rep, current_fp_rep, 2);
                break;
        default:
                break;
            }
            low += doubleword_align_up(length_of_header(h));
        }
    }
}

static void adjust_bpsheap(void)
/*
 * This is needed so that (e.g.) headers in the code here get byte-flipped
 * if necessary.  Also to set codefringe.
 * The bpsheap has space allocated in it from the top downwards (for some
 * stray historical reason) and so the locic here is not at all the
 * same as that used when expanding or squashing the vector heap when
 * allowing for word length changes. What a shame!
 */
{
    nil_as_base
    int32_t page_number;
    int32_t i;
    codelimit = codefringe = 0;
    for (page_number = 0; page_number < bps_pages_count; page_number++)
    {   void *page = bps_pages[page_number];
        char *low = (char *)doubleword_align_up((intptr_t)page);
        int32_t len = flip_32((uint32_t)car32(low));
        char *fr;
/*
 * The BPS heap also has to double its size if I am converting to a 64-bit
 * machine, ONLY because all the header words in it get larger. The data
 * in it is all bytes so remains unaltered.
 */
        if (SIXTY_FOUR_BIT && converting_to_64) len *= 2;
        car32(low) = len;
        fr = low + len;
        codefringe = (Lisp_Object)fr;
        codelimit = (Lisp_Object)(low + 8);
/*
 * If the computer that created the image file has the same word length and
 * byte order and if I am not keeping environment vectors in the BPS
 * heap (and indeed at present I am not) then the page contains only
 * BPS vectors which contain binary and do not need any adjustment at all.
 * If in the future I do put environment vectors here then I will need to
 * scan to adjust all the reference values within them.
 */
#ifndef ENVIRONMENT_VECTORS_IN_BPS_HEAP
        if (!converting_to_32 && !converting_to_64 && !flip_needed) continue;
#endif
        if (SIXTY_FOUR_BIT && converting_to_64)
        {   char *oldfr = (low + (fr - low)/2 + CSL_PAGE_SIZE);
/*
 * Here I will just move the data from where it had to be in the 32-bit world
 * to where it will end up in a 64-bit one. I will leave it in whatever byte
 * order it is in to start with (and that makes the sign extension process
 * a bit odd!). I do things this way so that the subsequent pass can correct
 * for byte-order without worrying about much need to move things.
 */
            while (oldfr < low + 2*CSL_PAGE_SIZE)
            {   Header h = (Header)flip_32(*(uint32_t *)oldfr);
                int32_t len, len32, len64, gap;
                len = length_of_header(h); /* 32 bit hdr + actual data */
/*
 * Now establish the amount of space that will be used in both 32 and 64
 * bit layouts and the size of any padding that will be called for.
 */
                len32 = doubleword_align_up(len);
                len64 = doubleword_align_up(len + 4);
                gap = 2*len32 - len64;
                *(int64_t *)fr = flip_64(h + (4<<10)); /* write new header */
/*
 * Now copy the data down as raw 32-bit words with no byte-flipping.
 * This will NOT be sufficient if I were ever to implement the
 * ENVIRONMENT_VECTORS_IN_BPS_HEAP idea, because in that case my lengths
 * as suggested above will be wrong and I would need to sign-extend all the
 * 32-bit data in the old vector into 64-bit values in the new. I am NOT
 * going to do that for now.
 */
                for (i=4; i<len; i+=4)
                {   *(int32_t *)(fr + i + 4) = *(int32_t *)(oldfr + i);
                }
                if (gap != 0)
                    *(int64_t *)(fr + len64) = flip_64(make_padder(gap));
                oldfr += len32;
                fr += 2*len32;
            }
/* And put fr back where it is needed for what follows... */
            fr = (char *)codefringe;
        }

        while (fr < low + (converting_to_64 ? 2*CSL_PAGE_SIZE : CSL_PAGE_SIZE))
        {   Header h;
            int32_t len, llen;
            if (converting_to_32) h = (Header)flip_64(*(int64_t *)fr);
            else h = flip_bytes(*(Header *)fr);
            len = length_of_header(h);
            llen = doubleword_align_up(len);
            switch (type_of_header(h))
            {
        case TYPE_SIMPLE_VEC:   /* This option not used at present */
                if (converting_to_32)
                {   /* Since this is not used yet I will not put any code
                     * here to deal with it! */
                }
                for (i=CELL; i<llen; i+=CELL)
                    adjust((Lisp_Object *)(fr+i));
                *(Header *)fr = h;
                break;
        case TYPE_BPS:
#ifdef DEBUG_WIDTH
                printf("BPS item length %d\n", len);
#endif
                if (!SIXTY_FOUR_BIT && converting_to_32)
                {   for (i=4; i<llen-4; i+=4)
                        *(int32_t *)(fr+i) = *(int32_t *)(fr+i+4);
                    *(int32_t *)(fr+llen-4) = 0;
                    if (doubleword_align_up(len-4) != llen)
                         *(Header *)(fr+llen-8) = make_padder(8);
                    h -= (4<<10); /* reduce length of the BPS object */
                }
                *(Header *)fr = h;
                break;
        default:
                /* This case should NEVER happen */
                printf("Illegal header %.8x in BPS heap\n", (int32_t)h);
                fflush(stdout);
                my_exit(4);
            }
            fr += llen;
        }
    }
/*
 * Now the code that allocates fresh binary code space (eg for the compiler
 * or for loading pre-compiled modules) does not know about oversized
 * pages of the form that can arise when I convert a 32 bit image to make it
 * work in a 64-bit world. The effect is that I would run into trouble if
 * I allocated a new bit of code space and it lived in the upper half of
 * such a page. Specifically the bit marking it as belonging in the top
 * half-space could be missed off to very bad effect, including crashes within
 * the garbage collector. So if necessary I allocate a big padder block of
 * BPS here so that all subsequent allocations end up in the lower (and hence
 * standrard( part of the page. I prefer to do this here rather than to spread
 * support for double-sized pages into other parts of the code.
 */
    if (SIXTY_FOUR_BIT && converting_to_64)
    {   intptr_t w = codefringe - codelimit - CSL_PAGE_SIZE - 0x100;
        if (w > 0) getcodevector(TYPE_BPS, w);
    }
}

void adjust_all(void)
{
    int32_t i;
    Lisp_Object nil = C_nil;
    qheader(nil)  = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;
#ifdef COMMON
    qheader(nil) |= SYM_EXTERN_IN_HOME;
#endif
    qvalue(nil)   = nil;
    qenv(nil)     = nil;
    ifn1(nil)     = (intptr_t)undefined1;
    ifn2(nil)     = (intptr_t)undefined2;
    ifnn(nil)     = (intptr_t)undefinedn;
    adjust(&(qpname(nil)));     /* not a gensym */
    adjust(&(qplist(nil)));
    adjust(&(qfastgets(nil)));
#ifdef COMMON
    adjust(&(qpackage(nil)));
#endif

    copy_into_nilseg(NO);
    for (i = first_nil_offset; i<last_nil_offset; i++)
        adjust(&BASE[i]);
    copy_out_of_nilseg(NO);

    adjust_consheap();
    adjust_vecheap();
    adjust_bpsheap();
}

static void *allocate_page(char *why)
{
    if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
intptr_t memory_base, memory_size, memory_count, memory_records = 0;
unsigned char *memory_map = NULL;
static intptr_t memory_lowest = 0x7fffffff, memory_highest = -1;
FILE *memory_file = NULL;

void memory_comment(int n)
{
    if (memory_map != NULL)
    {   putc(0xc0 + (n & 0x3f), memory_file);
        putc(0, memory_file);
        putc(0, memory_file);
    }
}

int kk = 0;

static void identify_one(void *p, intptr_t size, int type)
{
    int32_t i, j;
    intptr_t base = (intptr_t)p;
    int32_t a = 0, b = 0;
    intptr_t da = 1, db = 1;
    intptr_t click = size/0x400;
    switch (type)
    {
case 0:  b = click; break;
case 1:  db = -1;   break;
case 2:  b = click; da = db = 2; break;
case 3:  da = 2; db = -2; break;
case 4:  db = 0; break;
case 5:  da = -1; db = 0; break;
default: b = click; da = db = 0; break;
    }
    if (size > 256)
    {   da *= (size/256);
        db *= (size/256);
    }
    memory_count |= 0x3ff;
    cmemory_reference(base);
    memory_comment(kk ? 3 : 5);
    kk = !kk;
    for (i=0; i<32; i++)
    {   int x;
        memory_count |= 0x3ff;
        cmemory_reference(base);
        for (j=0; j<0x400; j++)
        {   x = a + j*(size/8);
            while (x > size) x -= size;
            while (x < 0) x += size;
            cmemory_reference(base+x);
            x = b + j*(size/8);
            while (x > size) x -= size;
            while (x < 0) x += size;
            cmemory_reference(base+x);
        }
        a += da;
        b += db;
    }
}

static void identify_page(void *p[], int32_t n, int type)
{
    while (n != 0)
    {   void *w = p[--n];
        if (w != NULL) identify_one(w, CSL_PAGE_SIZE, type);
    }
}

void identify_page_types()
{
    identify_page(pages,               pages_count,            0);
    identify_page(heap_pages,          heap_pages_count,       1);
    identify_page(vheap_pages,         vheap_pages_count,      2);
    identify_page(bps_pages,           bps_pages_count,        3);
    identify_page(native_pages,        native_pages_count,     4);
    identify_one((void *)stacksegment, CSL_PAGE_SIZE,          5);
    identify_one((void *)nilsegment,   NIL_SEGMENT_SIZE,       6);
}

#endif /* CHECK_ONLY */

long int car_counter;
unsigned long int car_low, car_high;

Cons_Cell *memory_reference(intptr_t p)
{
    if (p & 0x7)
    {   term_printf("Access to mis-aligned address %.8x\n", (int)p);
        ensure_screen();
        abort();
    }
    return (Cons_Cell *)cmemory_reference(p);
}

char *cmemory_reference(intptr_t p)
{
#ifdef CHECK_ONLY
    return (char *)p;
#else
    intptr_t a = p - memory_base;
    if (memory_map != NULL && a >= 0 && a < memory_size)
    {   int bit;
        a = a >> 2;                          /* Get a word address */
        a = a >> 2;                          /* reduce to 4-word resolution */
        if (memory_count >= car_counter &&
            (unsigned long int)a >= car_low &&
            (unsigned long int)a <= car_high)
        {   Lisp_Object nil = C_nil;
            if (exception_pending()) nil = (Lisp_Object)((intptr_t)nil ^ 1);
            interrupt_pending = 1;
            miscflags |= HEADLINE_FLAG | MESSAGES_FLAG;
            car_counter = 0x7fffffff; /* Do not interrupt again */
        }
        bit = 1 << (a & 7);
        a = a >> 3;
        if (a < memory_lowest) memory_lowest = a;
        if (a > memory_highest) memory_highest = a;
        memory_map[a] |= bit;
        if ((++memory_count & 0x3ff) == 0)   /* Every 1024 references... */
        {   unsigned char *pp;
            int c;
            int32_t run = 0, i;
/*
 * I use a run-length encoded representation for the file that I write out.
 * Each scan-line is stored as a collection of bytes each of which indicates
 * the number of '0' items before the next '1' in the bit-vector. The encoding
 * of individual lengths is as follows:
 *     0 - 127          1 byte
 *     128 - 16K        First byte has 0x80 plus 6 bits of data (+ 1 more)
 *     16K - 4M         First byte has 0xc0 plus 6 bits of data (+ 2 more)
 *     The byte pair (0x8n, 0x00) stands for n times 4M as a a prefix to
 *     one of the above. This gives up to 2^28 as the max span.
 *     The byte pair (0x80, 0x00) can be used to terminate a line.
 *     Codes (0xcn, 0x00, 0x00) give 64 special codes that can be used
 *     to interveave comments and annotations within the stream.
 */
            pp = memory_map + memory_lowest;
            run = 8*memory_lowest;
            for (i=memory_lowest; i<=memory_highest; i++)
            {   c = *pp++;
                if (c != 0)
                {   bit = 1;
                    while ((c & bit) == 0) run++, bit = bit << 1;
                    if (run >= 0x400000)
                    {   putc(0x80 + ((run >> 22) & 0x3f), memory_file);
                        putc(0x00, memory_file);
                        run &= 0x3fffff;
                    }
                    if (run < 0x80) putc(run, memory_file);
                    else if (run < 0x4000)
                    {   putc(0x80 + (run & 0x3f), memory_file);
                        putc((run >> 6) & 0xff, memory_file);
                    }
                    else
                    {   putc(0xc0 + (run & 0x3f), memory_file);
                        putc((run >> 6) & 0xff, memory_file);
                        putc((run >> 14) & 0xff, memory_file);
                    }
                    c &= ~bit;
                    run = 0;
                    bit = bit << 1;
                    while (c != 0)
                    {   while ((c & bit) == 0) run++, bit = bit << 1;
                        putc(run, memory_file);
                        c &= ~bit;
                        run = 0;
                        bit = bit << 1;
                    }
                    while (bit != 0x100) run++, bit = bit << 1;
                }
                else run += 8;
            }
            putc(0x80, memory_file);
            putc(0x00, memory_file);
            memory_lowest = 0x7fffffff;
            memory_highest = -1;
            memset(memory_map, 0, memory_size/32+8);
            memory_records++;
        }
    }
    return (char *)p;
#endif /* CHECK_ONLY */
}

#endif

static char *global_handle;

void *my_malloc(size_t n)
{
#ifdef NO_WORRY_ABOUT_MEMORY_PROBLEMS
    return (*malloc_hook)(n);
#else
/*
 * The idea here is INTENDED to provide a small amount of extra checking and
 * robustness about use of malloc and free. It is very probable these days
 * that I would do MUCH better to use a well-developed separate package
 * to help me out here - eg I understand that "valgrind" is useful for
 * detecting memory leaks...
 */
#define EXPLICIT_FREE_AT_END_OF_RUN  1
    char *r = (char *)(*malloc_hook)(n+64);
    int32_t *p = (int32_t *)quadword_align_up(r);
/*
 *    | ... |   :   |    |    |    |    |    |    | to user |    |    |
 *    r     p <-r->    n  55aa 1234 3456 1234 3456           8765 cba9
 * where p is quadword aligned whatever r is.
 *
 */
    if (r == NULL) return NULL;
    n = quadword_align_up(n);
    inject_randomness((int)(intptr_t)r);
    if (!SIXTY_FOUR_BIT) p[1] = 0;
    *(void **)(p) = r;                 /* base address for free() */
    *(int64_t *)(&p[2]) = (int64_t)n;  /* allow for 64-bit size */
    p[4] = 0x12345678;            /* Marker words for security */
    p[5] = 0x3456789a;
    p[6] = 0x12345678;
    p[7] = 0x3456789a;
    r = (char *)&p[8];
    car32(r+n)   = 0x87654321;
    car32(r+n+4) = 0xcba98765;
    return (void *)r;
#endif
}

char *big_chunk_start, *big_chunk_end;

#ifdef EXPLICIT_FREE_AT_END_OF_RUN

static void my_free(void *r)
{
#ifdef NO_WORRY_ABOUT_MEMORY_PROBLEMS
    char *rr = (char *)r;
/*
 * I will not free it if the pointer is strictly inside the single big
 * chunk that I grabbed at the start of the run.
 */
    if (rr > big_chunk_start && rr <= big_chunk_end) return;
    int32_t *p, *q, n;
    *(free_hook)(r);
#else /* NO_WORRY... */
    int32_t *p, *q;
    size_t n;
    char *rr = (char *)r;
/*
 * I will not free it if the pointer is strictly inside the single big
 * chunk that I grabbed at the start of the run.
 */
    if (rr > big_chunk_start && rr <= big_chunk_end) return;
    p = (int32_t *)r - 8;
    n = (size_t)*(int64_t *)(&p[2]);
    if (p[4] != 0x12345678 ||
        p[5] != 0x3456789a)
    {   term_printf("Corruption at start of memory block %p: %.8x %.8x\n",
            r, p[4], p[5]);
        ensure_screen();
        my_exit(0);
    }
    q = (int32_t *)((char *)r + n);
    if (q[0] != 0x87654321 ||
        q[1] != 0xcba98765)
    {   term_printf("Corruption at end of memory block %p: %.8x %.8x\n",
            r, q[0], q[1]);
        ensure_screen();
        my_exit(0);
    }
    (*free_hook)((void *)((void **)p)[0]);
#endif
}

#endif

static void *my_malloc_1(size_t n)
/*
 * This is a pretty silly function - it gobbles up 24Kbytes of
 * stack and then just calls malloc - it stuffs a pointer to the
 * stack-chunk into a static variable so that compilers can not
 * detect (I hope!) that the array remains unused.  The purpose of this
 * is to make malloc fail if it is about to encroach on space that
 * should be used for stack.  This is relevant on small systems where
 * stack and heap grow towards one another and where one space has been
 * grabbed by malloc it is unavailable for stack (even if it is FREEd).
 * The number 24000 is pretty arbitrary - but if I have 24K bytes of stack
 * I will be able to do at least something.
 * Also this code verifies that the memory addresses returned have the
 * correct most significant bit. I allocate just a bit more memory than
 * is really needed to leave a one-word (or so) guard-band between
 * allocated blocks. This is necessary on some releases of an SGI C
 * compiler (library) where blocks of memory that are word but not
 * doubleword aligned can be returned.
 */
{
    char gobble_stack[24000];
    char *r;
    intptr_t pun, pun1;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    pun = (intptr_t)r;
    pun1 = (intptr_t)(r + n);
/*
 * I will moan if the block of memory allocated spans zero.
 * Note that if this does happen then something very funny is happening
 * about 0 cast to a pointer (i.e. a NULL pointer) since NULL is supposed
 * not to be valid as an address (?) but appears to be within the address
 * range of the block of store just allocated.
 */
    if ((pun ^ pun1) < 0) fatal_error(err_mem_spans_zero);
/*
 * Now if I get a block with the "wrong" top bit I will just return NULL
 * to suggest that no more memory was available - CSL can then proceed
 * or fail as it sees fit.
 */
/*
 * For dynamic address sign I should not test the address sign on the
 * first call - instead I just remember what it was.  On subsequent calls
 * I will check it.
  */
    if (nilsegment != NULL)
    {   if ((pun + address_sign) < 0) return NULL;
                                      /* fatal_error(err_top_bit); */
    }
    else address_sign = pun & GC_BIT_P;
    return (void *)r;
}

static void *my_malloc_2(size_t n)
/*
 * Rather like my_malloc_1(), but does NOT check the sign bit of the
 * returned pointer. Provided as a place to put hooks to check memory
 * allocation problems.
 */
{
    char gobble_stack[24000];
    char *r;
    global_handle = gobble_stack;
    r = (char *)my_malloc(n+16);
    return (void *)r;
}

static void init_heap_segments(double store_size)
/*
 * This function just makes nil and the pool of page-frames available.
 * The store-size is passed in units of Kilobyte, and as a double not
 * an integer so that overflow is not an issue.
 */
{
    char *memfile = "memory.use"; /* For memory statistics etc */
    pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
#ifdef CONSERVATIVE
    page_map = (page_map_t *)my_malloc_2(MAX_PAGES*sizeof(page_map_t));
#endif
    heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    bps_pages = (void **)my_malloc_2(MAX_BPS_PAGES*sizeof(void *));
    native_pages = (void **)my_malloc_2(MAX_NATIVE_PAGES*sizeof(void *));
    new_heap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)my_malloc_2(MAX_PAGES*sizeof(void *));
    new_bps_pages = (void **)my_malloc_2(MAX_BPS_PAGES*sizeof(void *));
    new_native_pages = (void **)my_malloc_2(MAX_NATIVE_PAGES*sizeof(void *));
    pair_c = (unsigned char *)my_malloc_2(CODESIZE);
/*
 * Sets up codebuffer for jit functions
 */
#ifdef JIT
    jit_size = JIT_INIT_SIZE;
#ifdef WIN32
    DWORD old_protection_status;
    printf("About to VirtualAlloc\n");
    fflush(stdout);
    jit_space = VirtualAlloc(
        NULL,                    /* system selects address */
        jit_size,                    /* size to allocate */
        MEM_RESERVE | MEM_COMMIT,/* allocate reserved pages */
        PAGE_EXECUTE_READWRITE); /* Execute, Read and Write access */
    printf("VirtualAlloc = %p\n", jit_space);
    fflush(stdout);

/*
 * Now just to show that I know how to I will change the protection of
 * the dynamic page to "read-only" so that nobody else can clobber it by
 * accident (or in malice).
 */
/*
    VirtualProtect(
        shell,
        8192,
        PAGE_READONLY,
        &old_protection_status);
*/
#else
    jit_space = mmap(NULL, jit_size,
                     PROT_WRITE|PROT_EXEC,MAP_PRIVATE|MAP_ANONYMOUS,
                     0,0);
    if (jit_space==(caddr_t)-1) 
    {
        perror("mmap failed");
    }
#endif
    jit_space_p = jit_space;
#endif

/*
 * The next line is utterly unsatisfactory at present
 */
    char_stack = (unsigned char *)my_malloc_2(CSL_PAGE_SIZE+16 /*CODESIZE*/);
    pair_prev = (unsigned short int *)
                    my_malloc_2(CODESIZE*sizeof(unsigned short int));
    if (pages == NULL ||
#ifdef CONSERVATIVE
        page_map == NULL ||
#endif
        new_heap_pages == NULL ||
        new_vheap_pages == NULL ||
        new_bps_pages == NULL ||
        new_native_pages == NULL ||
        heap_pages == NULL ||
        vheap_pages == NULL ||
        bps_pages == NULL ||
        native_pages == NULL ||
        pair_c == NULL ||
        char_stack == NULL ||
        pair_prev == NULL)
    {
        fatal_error(err_no_store);
    }

    {
/*
 * Using an int32_t here was about to get embarassing as I move to 64-bit
 * machines and the amount of memory I ought to use grows to be over
 * 2 or over 4 Gbytes... so I use an intrpr_t.
 * This just sets up a DEFAULT allocation, which is 128 Mbytes on
 * 64-bit machines and 32 Mbytes on 32-bit ones. Later on I override this
 * in one of two ways. On a TINY machine with a smaller page size I
 * give myself just 16 Mbytes, and then if the user indicated a desire
 * for a particular initial heap-size using the "-Knnn" command line option
 * I will use that.
 */
        intptr_t free_space = SIXTY_FOUR_BIT ? 128000000 : 32000000;
        intptr_t request;
/*
 * There are two special cases where I will override the default, both
 * of which relate to "trick" builds for small machines. The two cases I
 * have most recently used these were
 * (a) Building for an HP Ipaq 4700 PDA
 * (b) Building to run on a Linksys router (!)
 */
#if defined UNDER_CE || PAGE_BITS < 20
        free_space = 16000000;
#endif
        request = (intptr_t)store_size;
/* By doing this in intptr_t I should avoid overflow */
        if (request != 0) free_space = 1024*request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count =
                      bps_pages_count = native_pages_count = 0;
        native_fringe = 0;
/*
 * I grab memory using a function called my_malloc_1(), which verifies that
 * all addresses used in the heap have the same top bit.  The very first time
 * it is called nilsegment will be NULL - that time it does less checking.
 */
        nilsegment = NULL;
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*(CSL_PAGE_SIZE+16));
/*
 * I try to get the whole of the initial hunk of memory that I need in
 * one gulp since that (maybe) gives me the best chance to obtain all
 * the memory in just one half of my address space.
 */
            char *pool = (char *)my_malloc_1(n);
/*
 * I get 8 bytes more than seems necessary because I will need to
 * align my page frames up to a doubleword boundary, and that can
 * potentially waste 7 bytes.
 */
            if (pool != NULL)
            {   big_chunk_start = (char *)pool;
                big_chunk_end = big_chunk_start + (n-1);
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
                memory_base = (intptr_t)pool;
                memory_size = n;
                memory_count = 0;
                memory_map = (unsigned char *)(*malloc_hook)(n/32 + 16);
                if (memory_map != 0)
                {   memset(memory_map, 0, n/32+8);
                    memory_file = fopen(memfile, "wb");
                    if (memory_file == NULL)
                    {   (*free_hook)(memory_map);
                        memory_map = 0;
                    }
                    else
                    {   n = n/32 + 8;
                        putc(0, memory_file);
                        putc(0, memory_file);
                        putc(0, memory_file); /* 3 bytes to overwrite later on */
                        putc(n, memory_file);
                        putc(n>>8, memory_file);
                        putc(n>>16, memory_file);
                        memory_comment(2);  /* startup code */
                        init_flags &= ~INIT_EXPANDABLE;
                    }
                }
#endif
#endif
                nilsegment = (Lisp_Object *)pool;
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
/* NB here that NIL is tagged as a CONS not as a symbol */
                C_nil = doubleword_align_up(nilsegment) + TAG_CONS + 8;
#else
                C_nil = doubleword_align_up(nilsegment) + TAG_SYMBOL;
#endif
/*
 * If at the end of the run I am going to free some space I had better not
 * free these pages. When I free the nilsegment they all get discarded at
 * once. Observe here that the page that will be at the top of the list of
 * pages will be the one with the higher address, and pages here will
 * all be contiguous. So if I merely grab two pages from here I may
 * view them as a single double-sized one. Since I will normally grab
 * from the top of the pile it will be the second one that I grab that
 * is the base of the double-page. This feels close to cheating!
 */
                while (pages_count < free_space)
                {   void *page = (void *)&pool[pages_count*(CSL_PAGE_SIZE+16)];
                    pages[pages_count++] = page;
                }
            }
        }
    }

/*
 * I allocate a stack segment first because I will use it as buffer space for
 * decompressing the contents of an image file. It will come out of the
 * initial contiguous block in general, however to give myself the best
 * chance when converting a 32-bit image to 64-bits I allocate it afresh
 * when I am on a 64-bit machine. If the user had asked for an oversize stack
 * it has to be allocated independently here anyway.
 */
    if (nilsegment != NULL && pages_count > 0)
    {   if (stack_segsize != 1 || SIXTY_FOUR_BIT)
        {   stacksegment =
                (Lisp_Object *)my_malloc(stack_segsize*CSL_PAGE_SIZE + 16);
            if (stacksegment == NULL)
                fatal_error(err_no_store);
        }
        else stacksegment = (Lisp_Object *)pages[--pages_count];
    }
    else
    {
        printf("pages_count <= 0 = %d\n", pages_count);
        fatal_error(err_no_store);
    }
    CSL_MD5_Update((unsigned char *)memfile, 8);
/*
 * The stack does not need to be doubleword aligned, but it does need
 * to be word aligned (otherwise certain back-pointers in the garbage
 * collector give trouble), so I fix it up here.  Note that stacksegment
 * remains pointing at the original base so that I can free() it later.
 */
    stackbase = (Lisp_Object *)doubleword_align_up((intptr_t)stacksegment);
}

#ifdef EXPLICIT_FREE_AT_END_OF_RUN
/*
 * In general I will let CSL exit without bothering to free up all the
 * memory that it allocated - that job can be left (to the extent that
 * it is needed at all) to the run-time system.  But if for some reason
 * you really mind about such things here is some code to do it for you...
 */

static void abandon(void *p[], int32_t n)
{
    while (n != 0)
    {   void *w = p[--n];
/*
 * The test here that avoids calling free on a NULL pointer is
 * certainly not needed with an ANSI compliant library - but
 * rumour has it that many Unix libraries are unkind in this
 * respect, and the test is pretty cheap...
 */
        if (w != NULL) my_free(w);
    }
}

#endif

void drop_heap_segments(void)
{
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    identify_page_types();
#endif
#endif
#ifdef EXPLICIT_FREE_AT_END_OF_RUN
    abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
    abandon(bps_pages,       bps_pages_count);
    abandon(native_pages,    native_pages_count);
    my_free(stacksegment);
    my_free(nilsegment);
#endif
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    fseek(memory_file, 0L, SEEK_SET);
    putc(memory_records & 0xff, memory_file);
    putc((memory_records>>8) & 0xff, memory_file);
    putc((memory_records>>16) & 0xff, memory_file);
    fclose(memory_file);
    memory_file = NULL;
    memory_map = NULL;
#endif
#endif
}

static char *find_checksum(char *name, int32_t len, const setup_type *p)
{
    char *n;
    while (p->name != NULL) p++;
    n = (char *)p->one;
    if (strlen(n) == (size_t)len && memcmp(name, n, len) == 0)
        return (char *)p->two;
    else return NULL;
}

setup_type const *setup_tables[] =
{
               u01_setup, u02_setup, u03_setup, u04_setup,
    u05_setup, u06_setup, u07_setup, u08_setup, u09_setup,
    u10_setup, u11_setup, u12_setup, u13_setup, u14_setup,
    u15_setup, u16_setup, u17_setup, u18_setup, u19_setup,
    u20_setup, u21_setup, u22_setup, u23_setup, u24_setup,
    u25_setup, u26_setup, u27_setup, u28_setup, u29_setup,
    u30_setup, u31_setup, u32_setup, u33_setup, u34_setup,
    u35_setup, u36_setup, u37_setup, u38_setup, u39_setup,
    u40_setup, u41_setup, u42_setup, u43_setup, u44_setup,
    u45_setup, u46_setup, u47_setup, u48_setup, u49_setup,
    u50_setup, u51_setup, u52_setup, u53_setup, u54_setup,
    u55_setup, u56_setup, u57_setup, u58_setup, u59_setup,
    u60_setup,
/*
 * I also include the kernel setup tables, but I put a NULL in this
 * table so it is easy to see where they start.
 */
    NULL,
    arith06_setup, arith08_setup, arith10_setup, arith12_setup,
    char_setup, eval1_setup, eval2_setup, eval3_setup,
    funcs1_setup, funcs2_setup, funcs3_setup, print_setup,
    read_setup, mpi_setup,
    NULL
};

/*
 * If C code is to be instated (via c!:install calls in u01.lsp etc) there
 * needs to be a verification that the file u01.c and the file u01.lsp (etc)
 * are in step. So once for each such file this does the check. It should
 * only happen when the system is being built and ought not to be a bit
 * performance issue.
 */

static Lisp_Object MS_CDECL Lcheck_c_code(Lisp_Object nil, int nargs, ...)
{
    Lisp_Object name, lc1, lc2, lc3;
    int32_t c1=-1, c2=-1, c3=-1;
    long int x1=-2, x2=-2, x3=-2;
    int32_t len;
    va_list a;
    char *p;
    char *sname;
    int i;
    argcheck(nargs, 4, "check-c-code");
    va_start(a, nargs);
    name = va_arg(a, Lisp_Object);
    lc1 = va_arg(a, Lisp_Object);
    lc2 = va_arg(a, Lisp_Object);
    lc3 = va_arg(a, Lisp_Object);
    va_end(a);
    if (!is_vector(name) ||
        type_of_header(vechdr(name)) != TYPE_STRING ||
        !is_fixnum(lc1) ||
        !is_fixnum(lc2) ||
        !is_fixnum(lc3)) return aerror1("check-c-code", name);
    c1 = int_of_fixnum(lc1);
    c2 = int_of_fixnum(lc2);
    c3 = int_of_fixnum(lc3);
    sname = &celt(name, 0);
    len = length_of_header(vechdr(name)) - CELL;
  
    p = NULL;
    for (i=0; setup_tables[i]!=NULL; i++)
    {   if ((p = find_checksum(sname, len, setup_tables[i])) != NULL) break;
    }
    if (p == NULL) return aerror1("check-c-code", name);

    if (sscanf(p, "%ld %ld %ld", &x1, &x2, &x3) != 3)
        return aerror("check-c-code");
    if (c1 == x1 && c2 == x2 && c3 == x3) return onevalue(nil);
    err_printf("\n+++++ C code and environment files not compatible\n");
    err_printf("please check, re-compile and try again\n");
    return aerror("check-c-code");
}

static setup_type const restart_setup[] =
/*
 * things that are in modules that do not define enough Lisp entrypoints
 * to be worth giving separate entry-tables.
 */
{
    {"check-c-code",            wrong_no_na, wrong_no_nb, Lcheck_c_code},
    {"define-in-module",        Ldefine_in_module, too_many_1, wrong_no_1},
    {"modulep",                 Lmodule_exists, too_many_1, wrong_no_1},
    {"start-module",            Lstart_module, too_many_1, wrong_no_1},
    {"write-module",            Lwrite_module, too_many_1, wrong_no_1},
    {"copy-module",             Lcopy_module, too_many_1, wrong_no_1},
    {"copy-native",             too_few_2, Lcopy_native, wrong_no_2},
    {"delete-module",           Ldelete_module, too_many_1, wrong_no_1},
    {"load-module",             Lload_module, too_many_1, wrong_no_1},
    {"list-modules",            wrong_no_na, wrong_no_nb, Llist_modules},
    {"writable-libraryp",       Lwritable_libraryp, too_many_1, wrong_no_1},
    {"library-members",         Llibrary_members, too_many_1, Llibrary_members0},
    {"startup-banner",          Lbanner, too_many_1, wrong_no_1},
    {"instate-c-code",          too_few_2, Linstate_c_code, wrong_no_2},
/* An embedded help system that used to exist has now been disabled */
#if 0
    {"write-help-module",       too_few_2, Lwrite_help_module, wrong_no_2},
    {"help",                    Lhelp, Lhelp_2, Lhelp_n},
    {"?",                       Lhelp, too_many_1, wrong_no_1},
#endif
    {"set-help-file",           too_few_2, Lset_help_file, wrong_no_2},
    {"mapstore",                Lmapstore, too_many_1, Lmapstore0},
    {"verbos",                  Lverbos, too_many_1, wrong_no_1},
#ifdef COMMON
    {"errorset",                Lerrorset1, Lerrorset2, Lerrorsetn},
    {"gc",                      Lgc, too_many_1, Lgc0},
#else
    {"errorset",                Lerrorset1, Lerrorset2, Lerrorsetn},
    {"reclaim",                 Lgc, too_many_1, Lgc0},
#endif
    {"resource-limit",          too_few_2, Lresource_limit2, Lresource_limitn},
    {NULL,                      0, 0, 0}
};


static void create_symbols(setup_type const s[], CSLbool restartp)
{
    int i;
    for (i=0; s[i].name != NULL; i++)
        make_symbol(s[i].name, restartp, s[i].one, s[i].two, s[i].n);
}

static int32_t defined_symbols;

static void count_symbols(setup_type const s[])
{
    int i;
    for (i=0; s[i].name != NULL; i++) defined_symbols++;
}

static void set_up_variables(CSLbool restartp);
static setup_type_1 *find_def_table(Lisp_Object mod, Lisp_Object checksum);

typedef struct dynamic_modules
{
    char *name;
    setup_type_1 *entries;
} dynamic_modules;

static dynamic_modules *loaded_dynamic_modules = NULL;
static unsigned int loaded_dynamic_count = 0 , loaded_dynamic_size = 0;

/*
 * A real curiosity of my implementation is that find_dynamic_module
 * takes a char * and a length. The "string" it is given need not be
 * properly terminated with a "\0". The string data might be transient.
 * in contrase, record_dynamic_module takes a normal-style C string (which
 * of course is terminated with '\0', and it requires that the string
 * data is non-transient. BEWARE if you try to use these at some stage in the
 * future.
 */
static setup_type_1 *find_dynamic_module(char *name, int32_t len)
{
    unsigned int hash = 0;
    int i;
    char *p = name;
    if (loaded_dynamic_size == 0) return NULL;
    for (i=0; i<len; i++) hash=169*hash+(*p++ & 0xff);
    hash %= loaded_dynamic_size;
    for (;;)
    {   if (loaded_dynamic_modules[hash].name == NULL) return NULL;
        if (strncmp(name, loaded_dynamic_modules[hash].name, len) == 0 &&
            strlen(loaded_dynamic_modules[hash].name) == len)
            return loaded_dynamic_modules[hash].entries;
        hash = (hash + 1) % loaded_dynamic_size;
    }
}

/*
 * The constant here must be a prime number.
 */
#define INITIAL_DYNAMIC_MODULE_HASH_SIZE 1009

static void record_dynamic_module(char *name, setup_type_1 *entries)
{
    unsigned int hash;
    char *p;
    loaded_dynamic_count++;
    if (3*loaded_dynamic_count >= 2*loaded_dynamic_size)
    {   dynamic_modules *newtable;
        unsigned int newsize;
        unsigned int i;
        if (loaded_dynamic_size == 0)
            newsize = INITIAL_DYNAMIC_MODULE_HASH_SIZE;
        else
        {   newsize = 2*loaded_dynamic_size-1;
            while (!primep(newsize)) newsize+=2;
        }
#ifdef TRACE_NATIVE
        trace_printf("Hash needs to grow from %d to %d\n", loaded_dynamic_size, newsize);
        ensure_screen();
#endif
        newtable = (dynamic_modules *)
             malloc(newsize*sizeof(dynamic_modules));
        for (i=0; i<newsize; i++) newtable[i].name = NULL;
        for (i=0; i<loaded_dynamic_size; i++)
        {   if ((p = loaded_dynamic_modules[i].name) == NULL) continue;
            hash = 0;
            while (*p != 0) hash=169*hash+(*p++ & 0xff);
/*
 * I will leave the trace print here when I rehash so that I spot cases of
 * rehashing in case to increase the chance of spotting associated bugs.
 * I will also start with a small hash table so that repeated rehashing is
 * provoked.
 */
#ifdef TRACE_NATIVE
            trace_printf("Hash for %s is %x in REHASH\n", loaded_dynamic_modules[i].name, hash);
            ensure_screen();
#endif
            hash %= newsize;
            for (;;)
            {   if (newtable[hash].name == NULL)
                {   newtable[hash].name = loaded_dynamic_modules[i].name;
                    newtable[hash].entries = loaded_dynamic_modules[i].entries;
                    break;
                }
                hash = (hash + 1) % newsize;
            }
        }
        if (loaded_dynamic_size != 0) free(loaded_dynamic_modules);
        loaded_dynamic_modules = newtable;
        loaded_dynamic_size = newsize;
    }
    p = name;
    hash = 0;
    while (*p != 0) hash=169*hash+(*p++ & 0xff);
    hash %= loaded_dynamic_size;
    for (;;)
    {   if (loaded_dynamic_modules[hash].name == NULL)
        {   loaded_dynamic_modules[hash].name = name;
            loaded_dynamic_modules[hash].entries = entries;
            return;
        }
        if (strcmp(name, loaded_dynamic_modules[hash].name) == 0)
        {   loaded_dynamic_modules[hash].entries = entries;
            return;
        }
        hash = (hash + 1) % loaded_dynamic_size;
    }
}

static void warm_setup();

static void warm_setup()
{
/*
 * Here I need to read in the bulk of the checkpoint file.
 */
    Lisp_Object nil = C_nil;
    int32_t i;
/*
 * NOTE that I have made these variable of type int32_t so that
 * their size is the same (ie 4) whether I am on a 32 or 64-bit machine
 */
    Cfread((char *)&heap_pages_count, sizeof(heap_pages_count));
    Cfread((char *)&vheap_pages_count, sizeof(vheap_pages_count));
    Cfread((char *)&bps_pages_count, sizeof(bps_pages_count));

    heap_pages_count = flip_32(heap_pages_count);
    vheap_pages_count = flip_32(vheap_pages_count);
    bps_pages_count = flip_32(bps_pages_count);

/*
 * Here I want to arrange to have at least one free page after re-loading
 * an image.  If malloc can give me enough I grab it here. Note that I do
 * not yet know how many pages will be needed for hard code, which is a
 * bit of a nuisance!
 * And if I am loading a 32-bit image on a 64-bit machine I will arrange that
 * all the pages that I reload stuff into here are (temporarily) double
 * the usual size. Because the 32-bit image was created on a 32-bit system (!)
 * it can have a total heap of at most 2Gb, ie 512 pages (for so long as my
 * page size is 4Mb, ie PAGE_BITS=22). So I could have a bitmap that
 * indicated which of the first up to 512 pages was oversized if I was
 * worried. Right now I will just allocate the memory large and on a 64-bit
 * machine not worry about the waste if later on I do not use half of it!
 *
 * When I look at a Reduce image I find that the (compressed) main heap image
 * is around 0.5Mb for a normal Reduce and just over 1Mb for the bulkier
 * bootstrap version. That is just the heap image part of the full image file.
 * A consequence of this is that if my pages are 4Mb each even after
 * decompression I will use just one page each of cons, vector and bps heap
 * here. However potentially somebody could use "preserve" to capture the
 * state in the middle of a huge calculation, in which case life would
 * end up messier... with LOTS of oversized pages.
 */
    i = heap_pages_count+vheap_pages_count+
        bps_pages_count+1 - pages_count;
#ifdef MEMORY_TRACE
/*
 * The MEMORY_TRACE options requires that all store be in a single
 * contiguous chunk, and hence can not cope with any piecemeal allocation
 * in the form that follows. That means it is incompatible with loading
 * 32-bit images on a 64-bit machine! So if I find anybody trying I
 * abort. OK so the message merely says "not enough memory" but that is better
 * than trying to continue and then crashing messily!
 */
    if (i > 0 || converting_to_64) fatal_error(err_no_store);
#else
/*
 * If I am converting to 64-bits I need all my memory here to be
 * contiguous. So rather than check I have enough here I will do
 * that later,,,
 */
    if (i>0 && converting_to_64) fatal_error(err_no_store);
    while (i-- > 0)
    {   void *page = my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
        if (page == NULL)
        {
            fatal_error(err_no_store);
        }
        else pages[pages_count++] = page;
    }
/*
 * Now I have at least just enough pages to load op the heap image. Well I
 * really hope I have a fair amount in hand or else garbage collection will
 * be a pain! But at least we can get started. Depending on how full memory
 * looks I will select the type for the first garbage collection. See
 * comments in gc.c for further thoughts about this.
 */
    gc_method_is_copying = (pages_count >
                 3*(heap_pages_count +
                      (3*(vheap_pages_count +
                          bps_pages_count +
                          native_pages_count))/2));
#endif
    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(6);  /* vector heap */
#endif
#endif
    for (i=0; i<vheap_pages_count; i++)
    {   intptr_t p;
/* When I want to make the page double size I do TWO allocations here. */
        if (converting_to_64) allocate_page("vheap 64-bit padder");
        vheap_pages[i] = allocate_page("vheap reload");
        p = doubleword_align_up((intptr_t)vheap_pages[i]);
/*
 * Vheap pages that need expanding to 64-bits will most easily by copied
 * in an order that goes best if I put the initial raw 32-bit data in the
 * top half of the double-sized page.
 */
        if (converting_to_64)
        {   Cfread(CSL_PAGE_SIZE+(char *)p, CSL_PAGE_SIZE);
/* For convenience later I copy the length field down to the bottom now */
            car32(p) = car32(CSL_PAGE_SIZE+(char *)p);
        }
        else Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(5);  /* cons heap */
#endif
#endif
    for (i=0; i<heap_pages_count; i++)
    {   intptr_t p;
/* When I want to make the page double size I do TWO allocations here. */
        if (converting_to_64) allocate_page("heap 64-bit padder");
        heap_pages[i] = allocate_page("heap reload");
        p = quadword_align_up((intptr_t)heap_pages[i]);
        Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char dummy[16];
        Cfread(dummy, 8);
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(14);  /* BPS heap */
#endif
#endif
    for (i=0; i<bps_pages_count; i++)
    {   intptr_t p;
/* When I want to make the page double size I do TWO allocations here. */
        if (converting_to_64) allocate_page("bps 64-bit padder");
        bps_pages[i] = allocate_page("bps reload");
        p = doubleword_align_up((intptr_t)bps_pages[i]);
/* Same issue as for Vheap pages */
        if (converting_to_64)
        {   Cfread(CSL_PAGE_SIZE+(char *)p, CSL_PAGE_SIZE);
            car32(p) = car32(CSL_PAGE_SIZE+(char *)p);
        }
        else Cfread((char *)p, CSL_PAGE_SIZE);
    }

    {   char endmsg[32];
        Cfread(endmsg, 24);  /* the termination record */
/*
 * Although I check here I will not make the system crash if I see an
 * error - at least until I have tested things and found this test
 * properly reliable.
 */
#ifdef COMMON
        if (strncmp(endmsg, "\n\nEnd of CCL dump file\n\n", 24) != 0)
#else
        if (strncmp(endmsg, "\n\nEnd of CSL dump file\n\n", 24) != 0)
#endif
        {   term_printf("\n+++ Bad end record |%s|\n", endmsg);
        }
    }
/*
 * There is a delicacy here - Cfread uses Iread to read chunks of
 * data from the real input file, but it never goes beyond the recorded
 * end of file mark.  This buffering ensures that at this stage any
 * pending part-word of data will have been read - this because the
 * read buffer used is a multiple of 4 bytes long.  This point matters
 * with regard to checksum validation on these files. For an image in a native
 * directory I must have set up the initial read_bytes_remaining allowing for
 * the final checksum...
 */
    {   Lisp_Object w = error_output;
        error_output = 0;
        if (IcloseInput(YES))
        {
/*
 * I write a moan to stderr, even though in some cases this will not be
 * visible, because the general-purpose Lisp print streams have not yet been
 * fully set up. So on some windowed platforms this message, if it appears
 * at all, may show up in an unusual way. Sorry!
 */
            fprintf(stderr, "\n+++ Initial Image file checksum failure\n");
        }
        error_output = w;
    }

#ifndef MEMORY_TRACE
    if (converting_to_64)
    {
/*
 * Now if the heap image was a 32-bit one but I am now on a 64-bit machine
 * I will allocate more pages (if necessary) to ensure that a copying
 * garbage collection will be possible.
 */
        i = 2*heap_pages_count+3*vheap_pages_count+
                3*bps_pages_count - pages_count;
        while (i-- > 0)
        {   void *page = my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
            if (page == NULL)
            {
                fatal_error(err_no_store);
            }
            else pages[pages_count++] = page;
        }
        gc_method_is_copying = 1;
    }
#endif /* MEMORY_TRACE */

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(9);  /* adjusting */
#endif
#endif
    inject_randomness((int)clock());
    adjust_all();

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(12);  /* remainder of setup */
#endif
#endif
/*
 * An explanation is needed here. Hash tables can be really odd things in
 * that if they are keyed on the EQ test they are based on memory addresses
 * that objects lie at. So the garbage collector has to do magic things with
 * them! I therefore keep a list of all hash tables, but it must not be
 * processed in a naive way. I keep it in a variable that is NOT in the range
 * of places where the garbage collector normally looks. But when it comes
 * to preserve and restart I need to save the information, so I have the two
 * lists I need saved in the nilseg under the aliass eq_hash_table_list and
 * equal_hash_table_list. As soon as I can I extract them and put them
 * back in the magic special places they need to live.
 */
    eq_hash_tables = eq_hash_table_list;
    equal_hash_tables = equal_hash_table_list;
    eq_hash_table_list = equal_hash_table_list = nil;
    {   Lisp_Object qq;
        for (qq = eq_hash_tables; qq!=nil; qq=qcdr(qq))
        {   if (!is_vector(qcar(qq)))
            {   printf("qq=%p should be a vector\n", (void *)qcar(qq));
                exit(4);
            }
            rehash_this_table(qcar(qq));
        }
        for (qq = equal_hash_tables; qq!=nil; qq=qcdr(qq))
        {   if (!is_vector(qcar(qq)))
            {   printf("qq=%p should be a vector\n", (void *)qcar(qq));
                exit(4);
            }
            rehash_this_table(qcar(qq));
        }
    }

/*
 * The following few lines allude to a historical oddity from before the time
 * when 32 bit and 64-bit images could be used interchangably. The fields
 * stored used to be explicitly 32-bit ones even on a 64-bit machine. Now they
 * are 64-bit values in that case. When they were 32-bit values on a 64-bit
 * machine they lived in the low memory address of that (double)word. Now
 * where they live depends on the byte order of the machine that wrote them!
 * this all really messes up conversion between different word lengths and
 * different byte orderings. Part of the hack to unwind that is that if I am
 * NOW on a 64-bit machine I may end up after flipping with data in the
 * top not the low part of the 64-bit words, so I patch that.
 */
    gensym_ser = flip_bytes(gensym_ser);
    print_precision = flip_bytes(print_precision);
    miscflags = flip_bytes(miscflags);
    current_modulus = flip_bytes(current_modulus);
    fastget_size = flip_bytes(fastget_size);
    package_bits = flip_bytes(package_bits);
/*
 * The adjustments used here can arise when I have read a 32-bit image in
 * on a 64-bit machine, but may possibly arise if I load an ancient 64-bit
 * image on a computer with the opposite byte order. I think one might say
 * that this sort of trouble relates to my breaching various rules related
 * to strict aliasing! Observe that I expect and indeed demand that the
 * quantities stored here are really just 31-bits - that is to reduce pain
 * associated with sign extension into the high 32-bits of a 64-bit value.
 * So you see it seems best to do this even if I am not converting from
 * 32 to 64 bits.
 */
    if (SIXTY_FOUR_BIT)
    {   if ((int32_t)gensym_ser==0)
             gensym_ser =
                 (Lisp_Object)(((int64_t)gensym_ser)>>32) & 0x7fffffff;
        if ((int32_t)print_precision==0)
             print_precision =
                 (Lisp_Object)(((int64_t)print_precision)>>32) & 0x7fffffff;
        if ((int32_t)miscflags==0)
             miscflags =
                 (Lisp_Object)(((int64_t)miscflags)>>32) & 0x7fffffff;
        if ((int32_t)current_modulus==0)
             current_modulus =
                 (Lisp_Object)(((int64_t)current_modulus)>>32) & 0x7fffffff;
        if ((int32_t)fastget_size==0)
             fastget_size =
                 (Lisp_Object)(((int64_t)fastget_size)>>32) & 0x7fffffff;
        if ((int32_t)package_bits==0)
             package_bits =
                 (Lisp_Object)(((int64_t)package_bits)>>32) & 0x7fffffff;
    }

    set_up_functions(1);
    set_up_variables(1);
/*
 * Now I have closed the main heap image, but if there is any hard machine
 * code available for this architecture I should load it. When I do this
 * the main heap has been loaded and relocated and all the entrypoints
 * in it that relate to kernel code have been inserted.
 */
    if (native_code_tag != 0) /* Not worth trying if none available */
    {   if (!IopenRoot(NULL, -native_code_tag, 0))
        {   int32_t nn = Igetc() & 0xff;
            nn = nn + ((Igetc() & 0xff) << 8);
            native_pages_count = nn;
            for (i=0; i<native_pages_count; i++)
            {   intptr_t p;
/*
 * Because I did not know earlier how many pages would be needed here I
 * may not have overall enough. So I expand my heap (if possible)
 * when things start to look tight here.
 */
                if (pages_count <= 1)
                {   void *page = my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
                    if (page == NULL)
                    {
                        fatal_error(err_no_store);
                    }
                    else pages[pages_count++] = page;
                }
                native_pages[i] = allocate_page("native code");
                p = (intptr_t)native_pages[i];
                p = doubleword_align_up(p);
                fread_count = 0;
                Cfread((char *)p, CSL_PAGE_SIZE);
                native_fringe = car32(p);
                relocate_native_code((unsigned char *)p, native_fringe);
            }
            IcloseInput(YES);
        }
    }
/*
 * With a warm start I must instate the definitions of all functions
 * that may have been compiled into hard code on this platform. Functions that
 * may be hard-coded on SOME platform may also be in a mess and will have
 * a byte-coded definition put back in place at this point. Observe that this
 * happens AFTER the system has otherwise been loaded and relocated.
 */
    {   Lisp_Object f_list = native_code, byte_code_def;
        do_not_kill_native_code = 1;
        while (f_list != nil)
        {   Lisp_Object w, fn, defs;
            int32_t nargs;
            int instated_something = 0;
            byte_code_def = nil;
            w = qcar(f_list);
            f_list = qcdr(f_list);
            fn = qcar(w); w = qcdr(w);
            nargs = int_of_fixnum(qcar(w));
            defs = qcdr(w);
            while (defs != nil)
            {   int32_t n, tag, type, off;
                intptr_t page;
                void *e;
                w = qcar(defs);
                defs = qcdr(defs);
                n = int_of_fixnum(qcar(w));
                w = qcdr(w);
                tag = (n >> 20) & 0xff;
                type = (n >> 18) & 0x3;
                page = n & 0x3ffff;
                if (tag == 0)
                {   byte_code_def = qcdr(w);
                    continue;
                }
                if (tag != native_code_tag) continue; /* Not for me today */
                instated_something = 1;
                off = int_of_fixnum(qcar(w));
                w = qcdr(w);
/*
 * Now fn should be a symbol, the function to be defined. w is the thing to go
 * into its environment cell. page and off define a location in the hard
 * code space and type tells me which of the 3 function cells to put that in.
 *
 * I will not (yet) mess around with the removal of C definition
 * flags and all the other delicacies. Note that this means attempts to
 * redefine built-in functions with user-provided native code varients
 * may cause all sorts of muddle! Please do not try it, but when you
 * do (!) tell me and I will attempt to work out what ought to happen.
 * Maybe it will all be OK provided that a consistent byte-code definition
 * is in place before any native code gets generated.
 */
                page = (intptr_t)native_pages[page];
                page = doubleword_align_up(page);
                e = (void *)((char *)page + off);
                switch (type)
                {
/*
 * Warning - I just support nargs being a simple integer here, with no
 * fancy encoding for variable numbers of args or &rest args etc. I think
 * that for native code all such cases need to be dealt with via non-zero
 * type code so that the 3 individual function cells get filled in one
 * by 1.
 */
            case 0: switch (nargs)
                    {
                case 0: set_fns(fn, wrong_no_0a, wrong_no_0b, (n_args *)e);
                        break;
                case 1: set_fns(fn, (one_args *)e, too_many_1, wrong_no_1);
                        break;
                case 2: set_fns(fn, too_few_2, (two_args *)e, wrong_no_2);
                        break;
                case 3: set_fns(fn, wrong_no_3a, wrong_no_3b, (n_args *)e);
                        break;
                default:set_fns(fn, wrong_no_na, wrong_no_nb, (n_args *)e);
                        break;
                    }
                    break;
/*
 * A non-zero type field allows me to fill in just one of the function cells.
 * Note that I ought to arrange to get ALL of them filled in somehow, either
 * by using type=0 or by using all three of type = 1,2,3.
 */
            case 1: ifn1(fn) = (intptr_t)e;
                    break;
            case 2: ifn2(fn) = (intptr_t)e;
                    break;
            case 3: ifnn(fn) = (intptr_t)e;
                    break;
                }
                qenv(fn) = w;
            }
            if (!instated_something && byte_code_def != nil)
            {   w = cons(fixnum_of_int(nargs), byte_code_def);
/*
 * You can look at this bit of code and moan, saying "What happens if
 * the call to CONS causes a garbage collection?". Well I have this policy
 * that garbage collection attempts during startup should be thought of
 * as fatal, and that the user should give enough memory to make it possible
 * to get at least started. I hope that I do not generate much litter here
 * and in other places within the startup code. Not thinking about GC
 * safety leaves the code neater and easier to work with.
 */
                Lsymbol_set_definition(nil, fn, w);
            }
        }
        do_not_kill_native_code = 0;
    }
/*
 * The stuff above is about the internal native compilation that I am no
 * longer pursuing. Well I may look back at it some day, but it would
 * involve CSL itselh having compiler back-ends for all relevant architectures
 * and now I am moving to using a local C compiler to do that stuff.
 */
    {   Lisp_Object n = native_defs;
        char *p;
        while (n != nil)
        {   Lisp_Object w, name, mod, fname, env, env1, checksum;
            setup_type_1 *table, *tp;
            uint32_t *pp;
            int32_t len;
            name = qcar(n);
            n = qcdr(n);
            w = get(name, nativecoded_symbol);
            if (consp(w))
            {   mod = qcar(w);
                w = qcdr(w);
                if (consp(w))
                {   fname = qcar(w);
                    w = qcdr(w);
                    if (consp(w))
                    {   checksum = qcar(w);
                        env = qcdr(w);
                    }
                    else continue;
                }
                else continue;
            }
            else continue;
/*
 * If I get here I have
 *   name     the Lisp symbol that may get a native definition
 *   mod      a string that names the module it lives in
 *   fname    the name of the function in the native code to load
 *   env      an environment to give the native definition
 *   checksum module checksum
 * name and fname may differ, for instance fname is the name that the
 * function had when it was compiled, but a copy of the definition may
 * have been copied to name...
 */
#ifdef TRACE_NATIVE
            trace_printf("Possible native def: ");
            prin_to_trace(name);
            trace_printf("\nmodule: ");
            prin_to_trace(mod);
            trace_printf("\nfname: ");
            prin_to_trace(fname);
            trace_printf("\nEnv: ");
            prin_to_trace(env);
            trace_printf("\nChecksum: ");
            prin_to_trace(checksum);
            trace_printf("\n");
#endif
/*
 * First I will try to ensure that the module concerned gets loaded. It
 * may have been already, in which case I just need its handle.
 */
            push4(name, fname, env, n);
            table = find_def_table(mod, checksum);
            pop4(n, env, fname, name);
            if (table == NULL) continue;  /* This module is not available */
#ifdef TRACE_NATIVE
            trace_printf("setup table at %p\n", table);
#endif
/* Now seek for fname in there... */
            tp = table;
            while (tp->name != NULL) tp++;
#ifdef SOON
            modname = "???";
            if (strcmp(modname, (char *)tp->one) != 0)
            {   trace_printf("Module name %s disagrees with %s\n",
                             modname, (char *)tp->one);
                continue;
            }
#else
#ifdef DEBUG_NATIVE
            modname = "???";
            trace_printf("module itself says it is called %s, wants to be %s\n", (char *)tp->one, modname);
#endif
#endif
            push4(name, fname, env, n);
            p = get_string_data(fname, "restart:native_code", &len);
            pop4(n, env, fname, name);
            nil = C_nil;
            if (exception_pending()) continue;
            while (tp!=table)
            {   tp--;
                if (strncmp(p, tp->name, len) == 0 &&
                    strlen(tp->name)==len)
                {   p = NULL;
                    break;
                }
            }
            if (p != NULL) continue;
/*
 * I will ONLY install native code if I have a bytecoded version in place
 * already. Note that I will require the function now about to be
 * redefined to have a bytecoded form that agrees wrt a checksum with the
 * native code version from the dynamically loaded module.
 * WELL there is an issue about the tail-call specials. They have a
 * symbol in the env cell and no checksum for me to look at at all. I
 * think I will just trust things in those cases.
 */
            env1 = qenv(name);
#ifdef TRACE_NATIVE
            prin_to_trace(env1);
            trace_printf(" is the bytecoded version\n");
#endif
            if (!is_symbol(env))
            {   if (!consp(env1) || !is_bps(qcar(env1))) continue;
                env1 = qcdr(env1);
                if (!is_vector(env1)) continue;
                env1 = Lgetv(nil, env1, Lupbv(nil, env1));
#ifdef TRACE_NATIVE
                prin_to_trace(env1); trace_printf(" should be checksum again\n");
#endif
                if (!is_numbers(env1) || !is_bignum(env1)) continue;
                pp = bignum_digits(env1);
#ifdef TRACE_NATIVE
                trace_printf("%u %u vs %u %u\n", pp[0], pp[1], tp->c2, tp->c1);
#endif
                if (pp[0] != tp->c2 || pp[1] != tp->c1) continue;
            }
            if (load_limit != 0x7fffffff)
            {   if (load_count >= load_limit) continue;
                prin_to_trace(name);
                trace_printf(" : %d\n", load_count++);
            }
/*
 * Gosh: now I can actually make the function available to users!
 */
#ifdef TRACE_NATIVE
            trace_printf("actually set up native function\n");
#endif
/*
 * The symbol I am about to define is already on native_defs and
 * has all the property-list info that it needs, so I am in the
 * happy situation of not needing to do much here.
 */
            ifn1(name) = (intptr_t)tp->one;
            ifn2(name) = (intptr_t)tp->two;
            ifnn(name) = (intptr_t)tp->n;
            qenv(name) = env;
        }
    }
    inject_randomness((int)clock());
}

static char dll_cache_directory[LONGEST_LEGAL_FILENAME] = {0};

static void find_dll_cache_directory()
{
    unsigned char md[16];
    char userinfo[80], counts[8];
    int i;
#ifdef WIN32
    DWORD n;
#endif
    char *p;
    struct stat stbuf;
    int count;
    if (dll_cache_directory[0] != 0) return;
/*
 * This does its real work just once. But I may need to re-try
 * if the first choice directory name does not work well.
 */
    for (count=0; count<100; count++)
    {   CSL_MD5_Init();
        sprintf(counts, "%d:", count);
        CSL_MD5_Update((unsigned char *)counts, strlen(counts));
        CSL_MD5_Update((unsigned char *)fwin_full_program_name,
                         strlen(fwin_full_program_name));
#ifdef WIN32
        userinfo[0] = ';';
        n = sizeof(userinfo) - 1;
        if (!GetUserName(userinfo+1, &n)) strcpy(userinfo, ";UnknownUser;");
        else strcat(userinfo, ";");
        if (GetTempPath(LONGEST_LEGAL_FILENAME, dll_cache_directory) == 0)
            strcpy(dll_cache_directory, ".\\");
#else
        sprintf(userinfo, ";%d;", geteuid());
        strcpy(dll_cache_directory, "/tmp/");
#endif
        CSL_MD5_Update((unsigned char *)userinfo, strlen(userinfo));
        CSL_MD5_Update((unsigned char *)linker_type, strlen(linker_type));
        CSL_MD5_Final(md);
#ifdef TRACE_NATIVE
        trace_printf("Base cache name on %s %s %s\n",
            fwin_full_program_name, userinfo, linker_type);
#endif
        p = dll_cache_directory + strlen(dll_cache_directory);
/*
 * The name of the directory that I invent will be the letters
 * CSL followed by 25 characters (0-9, a-t) (ie 25*5-125 bits derived
 * from an MD5 checksum).
 */
        *p++ = 'C'; *p++ = 'S'; *p++ = 'L';
        for (i=0; i<25; i++)
        {   int j, w = 0;
            for (j=15; j>=0; j--)
            {   int w1 = (md[j] >> 5) | (w << 3);
                w = md[j] & 0x1f;
                md[j] = w1;
            }
            if (w < 10) *p++ = '0' + w;
            else *p++ = 'a' + w - 10;
        }
        *p = 0;
#ifdef TRACE_NATIVE
        trace_printf("DLL cache directory will be %s\n", dll_cache_directory);  
#endif
/*
 * I should now verify that that directory exists and is readable and
 * writable! If it is I am done. If not I will try to create it as
 * a directory - if that works I can return. If that still does not help
 * I will loop to try a second-choice name. If the "temporary directory"
 * that I obtained did not exist this might loop I suppose, so anybody
 * who sets the shell variable TEMP to something silly might get hurt? To
 * avoid infinite pain I will just declare disaster if I do not succeed in
 * a fair number of tries.
 */
        if (stat(dll_cache_directory, &stbuf) == 0 &&
#ifdef S_IRUSR
            stbuf.st_mode & S_IRUSR &&
#endif
#ifdef S_IWUSR
            stbuf.st_mode & S_IWUSR &&
#endif
            (stbuf.st_mode & S_IFMT) == S_IFDIR) return;
        Cmkdir(dll_cache_directory);
        if (stat(dll_cache_directory, &stbuf) == 0 &&
#ifdef S_IRUSR
            stbuf.st_mode & S_IRUSR &&
#endif
#ifdef S_IWUSR
            stbuf.st_mode & S_IWUSR &&
#endif
            (stbuf.st_mode & S_IFMT) == S_IFDIR) return;
    }
/*
 * here 100 different attempts to find a suitable directory have all
 * failed. I just give up!
 */
    fatal_error(err_no_tempdir);
}

static char objname[LONGEST_LEGAL_FILENAME];

static void tidy_up_old_dlls(const char *name, int why, long int size)
{
    const char *p = name, *q = objname;
/*
 * If the file I have found has a name rather like objname then I will delete
 * it. So I will start to scanning past initial equal parts in the names.
 */
    while ((*p)==(*q) && (*p)!=0)
    {   p++;
        q++;
    }
/*
 * Now if p is of the form (where nnn is numeric)
 *    nnn-nnn-nnn.dll    or nnn-nnn-nnn.so
 * it is an old DLL for the same module so it should go. I have
 * some fairly grotty code here that is intended to detect this
 * pattern. Well it is a bit messier than that - the first few chars of the
 * checksum info may have matched...
 */
    while (*p != 0 && isdigit(*p)) p++;
    if (*p == '-') p++;
    while (*p != 0 && isdigit(*p)) p++;
    if (*p == '-') p++;
    while (*p != 0 && isdigit(*p)) p++;
    if (strcmp(p, ".dll") != 0 &&
        strcmp(p, ".so") != 0) return;
#ifdef TRACE_NATIVE
    trace_printf("Deleting old DLL file %s\n", name);
#endif
    remove(name);
}

static setup_type_1 *find_def_table(Lisp_Object mod, Lisp_Object checksum)
{
    int32_t len, checklen;
    char *sname, *checkname;
    char modname[80], xmodname[LONGEST_LEGAL_FILENAME];
    char sname1[LONGEST_LEGAL_FILENAME];
    Ihandle save;
    FILE *dest;
    int c;
    Lisp_Object nil = C_nil;
    char setupname[80];
    char *p;
    setup_type_1 *dll;
    initfn *init;
#ifdef WIN32
    HANDLE a;
    UINT ww;
#else
    void *a;
#endif
#ifdef TRACE_NATIVE
    trace_printf("find_def_table "); 
    prin_to_trace(mod);
    trace_printf("\n");
    ensure_screen();
#endif

    sname = get_string_data(mod, "find_def_table", &len);
    nil = C_nil;
    if (exception_pending()) return NULL;
    checkname = get_string_data(checksum, "find_def_table", &checklen);
    nil = C_nil;
    if (exception_pending()) return NULL;
#ifdef TRACE_NATIVE
    trace_printf("Checksum given as \"%.*s\"\n", checklen, checkname);
#endif
    sprintf(sname1, "%.*s-%.*s", (int)len, sname, (int)checklen, checkname);
    p = sname1;
    while (*p!=0)
    {   if (*p == ' ') *p = '-'; 
        p++;
    }
    dll = find_dynamic_module(sname1, strlen(sname1));
    if (dll != NULL) return dll;
/*
 * I keep dynamically-loadable read code in the image where a module
 * whose portable version is called foo.fasl might have a machine-specific
 * variant foo.win32.fasl.
 */
    sprintf(modname, "%.*s.%s", (int)len, sname, linker_type);

/*
 * Here I will do some more cache-style activity. I will hold a
 * dirctory typically called /tmp/nnnnnn (where nnnnn is a checksum
 * on fwin_full_program_name and the linker type and the curren user)
 * and put extracted DLL files there.
 * If I find one present there I will use it. Otherwise I
 * will extract it from the image file. This may give me trouble
 * with regard to versioning, and so when I initially create or update
 * a file in the image I should delete any cached version as outdated.
 * (that last bit not done to start with)
 */
    find_dll_cache_directory();

#ifdef TRACE_NATIVE
    trace_printf("Attempt to load module %s\n", modname);
#endif
/*
 * Now if dll_cache_directory/sname.[so/dll] exists I will use it.
 * otherwise I will create it by copying from the image file.
 * The name I use here will include checksum information. At some stage
 * I should possibly try to delete any files in the cache that match in
 * their root but disagree in the checksum portion, since they are liable
 * to be old.
 */
#ifdef WIN32
    sprintf(objname, "%s\\%s.dll", dll_cache_directory, sname1);
#else
    sprintf(objname, "%s/%s.so", dll_cache_directory, sname1);
#endif
#ifdef TRACE_NATIVE
    trace_printf("Invented name %s for temp location of module\n", objname);
#endif
    {   struct stat stbuf;
/*
 * Check if the module exists in the cache - if not try to create it...
 * I count the DLL as unavailable if either stat fails (which may indicate
 * that the file does not exist) or if it is not readable by its owner
 * (who ought to be me!). Not if it is not readable it may not be writable
 * either, and in that case the attempt here to create it will fail.
 */
        if (stat(objname, &stbuf) != 0
#ifdef S_IRUSR
            || (stbuf.st_mode & S_IRUSR) == 0
#endif
            )
        {   Icontext(&save);
            if (Iopen(modname, strlen(modname), IOPEN_UNCHECKED, xmodname))
            {   Irestore_context(save);
                trace_printf("module not found\n");
                return NULL;
            }

#ifdef TRACE_NATIVE
            trace_printf("Will now copy %s to the DLL cache\n", modname);
#endif
/*
 * Here I can tidy up the cache directory. I want to DELETE any files in
 * it whose names are somewhat similar to the one I am about to create.
 * Just for now I will just print a message ratherthan actually do anything.
 */
            set_hostcase(1);
            scan_files(dll_cache_directory, tidy_up_old_dlls);
/*
 * Here I can read and process the module...
 */
            dest = fopen(objname, "wb");
            if (dest == NULL)              /* failed to write to temp file */
            {   IcloseInput(0);
                Irestore_context(save);
                return NULL;
            }
            while ((c = Igetc()) != EOF)
                putc(c, dest);
            IcloseInput(0);
            Irestore_context(save);
            if (fclose(dest) != 0)
            {   trace_printf("failed to write DLL to temp directory\n");
                return NULL;
            }
        }
    }
/*
 * Now I have copied the object file data to a "real" but temporary file.
 */
    sprintf(modname, "%.*s", (int)len, sname);

#ifdef TRACE_NATIVE
    trace_printf("load_dynamic for find_def_table %s %s\n", objname, modname);
#endif
    sprintf(setupname, "%s_setup", modname);
    for (p=setupname; *p!=0; p++)
        if (*p=='-') *p='_';
#ifdef TRACE_NATIVE
    trace_printf("Look for \"%s\"\n", setupname);
#endif
#ifdef WIN32
/*
 * In various cases of failure Windows has a default behaviour of popping
 * up a dialog box when a DLL can not be loaded. I do not want that, since
 * I intend to recover graciously if the module can not be located or
 * loaded.
 */
    ww = SetErrorMode(SEM_FAILCRITICALERRORS);
#ifdef TRACE_NATIVE
    trace_printf("Loading DLL called %s for %s\n", objname, modname);
#endif
    a = LoadLibrary(objname);
    if (a == 0)
    {   DWORD err = GetLastError(), err1;
        LPTSTR errbuf = NULL;
/*
 * If I let Windows pop up its message box I still seem to get more info
 * than FormatMessage presents me with... Specifically if the module I tried
 * to load refused to because of a symbol that it needed to load, the
 * pop up tells me the name of that symbol.
 */
        err1 = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                             FORMAT_MESSAGE_ALLOCATE_BUFFER |
                             FORMAT_MESSAGE_IGNORE_INSERTS,
                             NULL,
                             err,
                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                             (LPTSTR)&errbuf,
                             0,
                             NULL);
        if (err1 == 0 || errbuf==NULL)
            trace_printf("FormatMessage on code %d failed with %d\n",
                         (int)err, (int)GetLastError());
        else
        {   trace_printf("%s", errbuf);
            LocalFree(errbuf);
        }
    }
    SetErrorMode(ww);
#ifdef TRACE_NATIVE
    trace_printf("Dynamic loading of test code\na = %p\n", (void *)a);
#endif
    if (a == 0) return 0;
    dll = (setup_type_1 *)GetProcAddress(a, setupname);
/*
 * The dynamic module that I create should always have a function called
 * "init" that I must call to tell it where nil, stack and stacklimit are.
 */
    init = (initfn *)GetProcAddress(a, "init");
#else
#ifdef EMBEDDED
    return 0;
#else
    a = dlopen(objname, RTLD_NOW | RTLD_GLOBAL);
#ifdef TRACE_NATIVE
    trace_printf("a = %p\n", a);
#endif
    if (a == NULL)
    {   trace_printf("Err = <%s>\n", dlerror()); fflush(stdout);
        return 0;
    }
    dll = (setup_type_1 *)dlsym(a, setupname);
    init = (initfn *)dlsym(a, "init");
#endif
#ifdef TRACE_NATIVE
    trace_printf("setup table is %p, init fn is %p\n", dll, init);
#endif
    if (dll == NULL || init == NULL) 
    {
#ifdef WIN32
        FreeLibrary(a);
#endif
        return NULL;
    }
    (*init)(&C_nil, &C_stack, &stacklimit);
/*
 * Wheee - I have now loaded and initialised the module.
 */
#ifdef TRACE_NATIVE
    {   setup_type_1 *b = dll;
        while (b->name != NULL)
        {   trace_printf("%s %p %p %p %u %u\n",
                         b->name, b->one, b->two, b->n, b->c1, b->c2);
            b++;
        }
        trace_printf("%s %s\n", (char *)(b->one), (char *)(b->two));
    }
#endif
/*
 *  remove(objname);
 * At one stage I wanted to count the DLL files as temporary - but now I keep
 * them all in a cache directory, so I really do NOT want to delete them
 * here... If the user deletes them that will not be a problem - they will get
 * re-created if necessary.
 */

/*
 * Update the cache...
 */
    p = (char *)malloc(strlen(sname1)+1);
    strcpy(p, sname1);
    p[len] = 0;
    record_dynamic_module(p, dll);
    return dll;
#endif /* EMBEDDED */
}

int setup_dynamic(setup_type_1 *dll, char *modname,
                 Lisp_Object name, Lisp_Object fns)
{
    char *p;
    setup_type_1 *b;
    int32_t len;
    Lisp_Object nil = C_nil, xchecksum;
    int32_t all_ok = 1;
#ifdef TRACE_NATIVE
    trace_printf("setup_dynamic %s\n", modname);
/*  prin_to_trace(fns); */ trace_printf("\n");
#endif
    if (!consp(fns)) return 0; 
#ifdef TRACE_NATIVE
    b = dll;
    while (b->name != NULL)
    {   trace_printf("%s %p %p %p %u %u\n",
                     b->name, b->one, b->two, b->n, b->c1, b->c2);
        b++;
    }
    trace_printf("%s %s\n", (char *)(b->one), (char *)(b->two));
#endif
/*
 * First I will check if the module loaded appears to match against the set
 * of functions I am expecting from it...
 */
    b = dll;
    while (b->name != NULL) b++;
/*
 * now b->one is expected to match modname, and b->two is expected
 * to match the string that is the first item in fns.
 */
    if (strcmp(modname, (char *)b->one) != 0)
    {   trace_printf("Module name %s disagrees with %s\n",
                     modname, (char *)b->one);
        return 0;
    }
    p = get_string_data(qcar(fns), "instate_c_code", &len);
    nil = C_nil;
    if (exception_pending()) return 0;
    if (strncmp(p, (char *)b->two, len) != 0)
    {   trace_printf("Module signature %.*s disagrees with %s\n",
                     (int)len, p, (char *)b->two);
        return 0;
    }
    xchecksum = qcar(fns);
    fns = qcdr(fns);
    b = dll;
/*
 * Now the table b and the list fns ought to match up. The list will have
 * entries
 *      (name (e1 e2 ... en) . check)
 * where the name is the name of a Lisp function and the list needs
 * turning into a vector to go into its environment cell.
 * The table has columns
 *      name f1 f2 n2 c1 c2
 * where the name ought to match what is seen in the list, and then the
 * three functions go in the f1, f2 and fn cells. I will stop if I get
 * any mismatch at all - just to be cautious!
 */
    while (consp(fns))
    {   Lisp_Object fname, env, env1, ww;
        if (b->name == NULL)
        {
#ifdef TRACE_NATIVE
            trace_printf("Failed: setup table length problem\n");
#endif
            return 0;  /* lengths of lists differ */
        }
        env = qcar(fns);
        if (consp(env))
        {   fname = qcar(env);
            env = qcdr(env);
            if (consp(env))
            {   Lisp_Object chk = qcdr(env);
                uint32_t *pp;
                env = qcar(env);
                p = get_string_data(fname, "instate_c_code", &len);
                nil = C_nil;
                if (exception_pending())
                {
#ifdef TRACE_NATIVE
                    trace_printf("Failed: get_string_data\n");
#endif
                    return 0;
                }
#ifdef TRACE_NATIVE
                trace_printf("instate next function %.*s vs %s\n", len, p, b->name);
                prin_to_trace(chk); trace_printf(" vs %u %u\n", b->c1, b->c2);
#endif
                if (strncmp(p, b->name, len) != 0)
                {
#ifdef TRACE_NATIVE
                    trace_printf("Failed: name in setup table and env list differ\n");
#endif
                    return 0;
                }
/*
 * There is a small chance of misery here. The checksum MIGHT happen to
 * be a 1-word bignum or even a fixnum. If that happens the tests here will
 * reject it and the native code will not get instated. If this happens
 * the result can be a performance loss but it ought not to lead to
 * incorrect results, and if the checksum scheme is good it is only
 * expected to hit for around 1 in 10^9 functions that are processed, so
 * I will (for now) accept it. If I ever feel twitchy I will respond by
 * ensuring that md60 always returns a 2-word bignum result. Hmm I AM twitchy
 * and I have now done just that!
 */
                if (!is_numbers(chk) || !is_bignum(chk))
                {
#ifdef TRACE_NATIVE
                    trace_printf("Failed: checksum not a number or not big\n");
#endif
                    return 0;
                }
                pp = bignum_digits(chk);
#ifdef TRACE_NATIVE
                trace_printf("%u %u vs %u %u\n", pp[0], pp[1], b->c2, b->c1);
#endif
                if (pp[0] != b->c2 || pp[1] != b->c1)
                {   all_ok = 0;   /* function's definition has changed? */
#ifdef TRACE_NATIVE
                    trace_printf("Failed on a function: checksum discrepancy\n");
#endif
                    goto next_def;
                }
/*
 * I will ONLY install native code if I have a bytecoded version in place
 * already. I apply that rule to ensure that image files can be used across
 * different architectures. Well I will want to count tailcall magic as
 * OK.
 */
                env1 = qenv(fname);
#ifdef TRACE_NATIVE
                prin_to_trace(env1);
                trace_printf(" is the bytecoded version\n");
#endif
                if (qfn1(fname) == f1_as_0 ||
                    qfn1(fname) == f1_as_1 ||
                    qfn2(fname) == f2_as_0 ||
                    qfn2(fname) == f2_as_1 ||
                    qfn2(fname) == f2_as_2 ||
                    qfnn(fname) == f0_as_0 ||
                    qfnn(fname) == f3_as_0 ||
                    qfnn(fname) == f3_as_1 ||
                    qfnn(fname) == f3_as_2 ||
                    qfnn(fname) == f3_as_3)
                {   if (!is_symbol(env1))
                    {   all_ok = 0;   /* malformed */
#ifdef TRACE_NATIVE
                        prin_to_trace(fname);
                        trace_printf(" Failed on a function: tailcall with env malformed\n");
#endif
                        goto next_def;
                    }
                }
                else
                {   if (!consp(env1) || !is_bps(qcar(env1)))
                    {   all_ok = 0;   /* no bytecoded version available */
#ifdef TRACE_NATIVE
                        prin_to_trace(fname);
                        trace_printf(" Failed on a function: no bytecoded version\n");
#endif
                        goto next_def;
                    }
                    env1 = qcdr(env1);
                    if (!is_vector(env1)) return nil;
                    env1 = Lgetv(nil, env1, Lupbv(nil, env1));
#ifdef TRACE_NATIVE
                    prin_to_trace(env1); trace_printf(" should be checksum again\n");
#endif
                    if (!equal(env1, chk))
                    {   all_ok = 0;   /* bytecoded definition differs */
#ifdef TRACE_NATIVE
                        trace_printf("Failed: bytecoded version checksum differs\n");
#endif
                        goto next_def;
                    }
                }
                nil = C_nil;
                if (exception_pending()) return 0;
                push2(name, fname);
                env = Llist_to_vector(nil, env);
                pop2(fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                if (load_limit != 0x7fffffff)
                {   if (load_count >= load_limit)
                    {   all_ok = 0;
                        goto next_def;
                    }
                    prin_to_trace(fname);
                    trace_printf(" :: %d\n", load_count++);
                }
/*
 * Gosh: now I can actually make the function available to users!
 */
#ifdef TRACE_NATIVE
                trace_printf("actually set up native function\n");
#endif
/*
 * I want to do a few things in addition to filling in the function and
 * environment cells...
 * (a) ensure that this symbol is in the list "native_defs";
 * (b) give it a "bytecoded_symbol" property that captures all info about
 *     the bytecode definition that I am displacing;
 * (c) give it a "nativecoded_symbol" property that should let me
 *     re-instate this fast version of the code on subsequent runs when
 *     the module loading must be repeated following a preserve/restart.
 */
                ww = native_defs;
                while (consp(ww))
                {   if (qcar(ww) == fname) goto already_native;
                    ww = qcdr(ww);
                }
                push4(name, fname, env, xchecksum);
                ww = cons(fname, native_defs);
                pop4(xchecksum, env, fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                native_defs = ww;
            already_native:
                ww = Lsymbol_argcode(nil, fname);
                if (ww == nil) return 0;
                push4(name, fname, env, xchecksum);
                ww = cons(ww, qenv(fname));
                pop4(xchecksum, env, fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                push4(name, fname, env, xchecksum);
                putprop(fname, bytecoded_symbol, ww);
                pop4(xchecksum, env, fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                push4(name, fname, env, xchecksum);
                ww = list3star(name, fname, xchecksum, env);
                pop4(xchecksum, env, fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                push4(name, fname, env, xchecksum);
                putprop(fname, nativecoded_symbol, ww); 
                pop4(xchecksum, env, fname, name);
                nil = C_nil;
                if (exception_pending()) return 0;
                ifn1(fname) = (intptr_t)b->one;
                ifn2(fname) = (intptr_t)b->two;
                ifnn(fname) = (intptr_t)b->n;
                qenv(fname) = env;
            }
        }
    next_def:
        fns = qcdr(fns);
        b++;
    }
/*
 * At present I take the view that when a module has been loaded it will
 * be wanted for the rest of the Lisp run, and so I do not unload it...
 */
    return 1;
}

/*
 * The next function is to do with compiling modules into machine
 * code (via C) and tben dynamically loading them. The first argument is
 * the name given to the module, which is the same as the name of the
 * FASL file I believe I am loading now. Furthermore the module
 * should (when loaded) define an external symbol called
 *      <name>_setup
 * that is its table of functions that it defines.
 *
 * The second argument will be a
 * header string "int int int" followed by a list of triples
 *   (name env . checksum)
 * where each name should be in the setup table from the file, and the
 * corresponding env is a list that needs to be converted to a vector and
 * placed in the symbol's environment cell.
 *
 * Note that the final entry in the setup table is of the form
 *    NULL, "name", "int int int", 0
 * and the name and triple of integers are expected to match the
 * information passed to instate_c_code. If they do not then the
 * modules concerned have somehow got out of step...
 */

Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object name, Lisp_Object fns)
{
/*
 * See if there is a module in the image file with the given name and
 * with its linker-tag matching the one for the current executable. If so
 * copy it to a temporary file called say t1.dll or t1.so. Dynamically load
 * it into memory. Keep the temporary file in a temporary directory but
 * where I might find it again next time I need it. Access a
 * symbol name_setup in it. The style of binary found should match the
 * information in the variable "linker_type". This version is to be called
 * by Lisp from a fasl-file as a module is loaded. The checksum information at
 * the start of "fns" will used in names for the .dll files and will be
 * recorded associated with the module name.
 */
    int32_t len;
    char *sname;
    char modname[80];
    int c;
    setup_type_1 *dll;

#ifdef TRACE_NATIVE
    trace_printf("instate_c_code "); 
    prin_to_trace(name);
    trace_printf("\n");
#endif

    if (!consp(fns)) return onevalue(nil);

    sname = get_string_data(name, "instate-c-code", &len);
    nil = C_nil;
    if (exception_pending()) return nil;

    dll = find_def_table(name, qcar(fns));
    if (dll == NULL) return onevalue(nil);

    sprintf(modname, "%.*s", (int)len, sname);
    c = setup_dynamic(dll, modname, name, fns);
    return onevalue(c ? lisp_true : nil);
}

static void cold_setup();

static void cold_setup()
{
    Lisp_Object nil = C_nil;
    void *p;
    int i;
    p = vheap_pages[vheap_pages_count++] = allocate_page("vheap cold setup");
    vfringe = (Lisp_Object)(8 + (char *)doubleword_align_up((intptr_t)p));
    vheaplimit = (Lisp_Object)((char *)vfringe + (CSL_PAGE_SIZE - 16));

    p = heap_pages[heap_pages_count++] = allocate_page("heap cold setup");
    heaplimit = quadword_align_up((intptr_t)p);
    fringe = (Lisp_Object)((char *)heaplimit + CSL_PAGE_SIZE);
    heaplimit = (Lisp_Object)((char *)heaplimit + SPARE);

    codelimit = codefringe = 0; /* no BPS to start with */

    miscflags = 3;
    qplist(nil) = nil;
    qfastgets(nil) = nil;
    qenv(nil) = nil;        /* points to self in undefined case */
    ifn1(nil) = (intptr_t)undefined1;
    ifn2(nil) = (intptr_t)undefined2;
    ifnn(nil) = (intptr_t)undefinedn;
    qheader(nil) = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;
    qvalue(nil) = nil;
/*
 * When I am debugging CSL I can validate the heap, for instance whenever
 * I allocate vector. The call to make_string here does that, and so I MUST
 * have a tidy world in place here.
 */
    qpname(nil) = nil;
    for (i=first_nil_offset; i<last_nil_offset; i++)
         BASE[i] = nil;
    eq_hash_tables = equal_hash_tables = nil;
#ifdef COMMON
    qpackage(nil) = nil;
    qpname(nil) = make_string("NIL");
#else
    qpname(nil) = make_string("nil");
#endif
    qcount(nil) = 0;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;
    eq_hash_tables = equal_hash_tables = nil;

    current_package = nil;
/*
 * The code here is generally coded on the supposition that there will NEVER
 * be a garbage collection here, so all the "fun" about push/pop and errexit
 * tests can be omitted. That makes this code much cleaner! It means that
 * during a cold start that there is enough space (well for a COLD start that
 * hardly likely to be an issue!) and in a warm start that none of the
 * calls that make strings or symbols etc here trigger a genuine garbage
 * collection - that can probably be assured by ensuring that on restart there
 * is at least a little bit of space in hand.
 */
    qvalue(nil) = getvector_init(sizeof(Package), nil);
#ifdef COMMON
    qpackage(nil) = qvalue(nil);    /* For sake of restart code */
    all_packages = ncons(qvalue(nil));
#endif

    packhdr_(CP) = TYPE_STRUCTURE + (packhdr_(CP) & ~header_mask);
#ifdef COMMON
    packname_(CP) = make_string("LISP");
#endif
/*
 * The size chosen here is only an initial size - the hash table in a package
 * can grow later on if needbe - but I ought to ensure that the initial
 * size is big enough for the built-in symbols that Lisp creates in
 * this restart code.  The size must be a power of 2. I want the object
 * table to have the same number of entries regardless of whether I am on
 * a 32 or 64-bit machine to make cross-loading of images possible.
 */
    packint_(CP) = getvector_init(CELL*(1+INIT_OBVECI_SIZE), fixnum_of_int(0));
    packvint_(CP) = fixnum_of_int(1);
    packflags_(CP) = fixnum_of_int(++package_bits);
#ifdef COMMON
/*
 * Common Lisp also has "external" symbols to allow for...
 */
    packnint_(CP) = fixnum_of_int(0);
    packext_(CP) = getvector_init(CELL*(1+INIT_OBVECX_SIZE), fixnum_of_int(0));
    packvext_(CP) = fixnum_of_int(1);
    packnext_(CP) = fixnum_of_int(1); /* Allow for nil */
    {   int i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECX_SIZE - 1));
        elt(packext_(CP), i) = nil;
    }
#else
    packnint_(CP) = fixnum_of_int(1); /* Allow for nil */
    {   int i = (int)(hash_lisp_string(qpname(nil)) &
                      (INIT_OBVECI_SIZE - 1));
        elt(packint_(CP), i) = nil;
    }
#endif
    gensym_ser = 0;
    print_precision = 15;
    current_modulus = 1;
    fastget_size = 8*sizeof(Lisp_Object);
    package_bits = 0;
    unset_var = nil;
/*
 * there had better not be a need for garbage collection here...
 * ... or elsewhere in setup, since the world is not yet put together.
 * Ditto interrupts.
 */
#define boffo_size 256
    boffo = getvector(TAG_VECTOR, TYPE_STRING, CELL+boffo_size);
    memset((void *)((char *)boffo + (CELL - TAG_VECTOR)), '@', boffo_size);
#ifndef COMMON
    if (current_package == nil)
    {   current_package      = make_undefined_symbol("*package*");
        qheader(current_package) |= SYM_SPECIAL_VAR;
        lisp_package = qvalue(current_package) = qvalue(nil);
        qvalue(nil) = nil;
    }
#else
/*
 * The next line has hidden depths.  When it is obeyed during cold start
 * the C variable current_package has the value nil, hence make_symbol
 * looks in the value cell of nil to find the package to intern wrt. Once
 * this has been done I can put nil back how it ought to have been!
 */
    current_package          = make_undefined_symbol("*package*");
    qheader(current_package)|= SYM_SPECIAL_VAR;
    lisp_package = qvalue(current_package)  = qpackage(nil);
    qvalue(nil)              = nil;          /* Whew! */
#endif

    B_reg = nil;                             /* safe for GC */
    unset_var                = make_undefined_symbol("~indefinite-value~");
    qheader(unset_var)      |= SYM_SPECIAL_VAR;
    qvalue(unset_var)        = unset_var;
    Lunintern(nil, unset_var);
/*
 * Now in some minor sense the world is in a self-consistent state
 */
    lisp_true           = make_undefined_symbol("t");
    qheader(lisp_true) |= SYM_SPECIAL_VAR;
    qvalue(lisp_true)   = lisp_true;
    savedef             = make_undefined_symbol("*savedef");
    comma_symbol        = make_undefined_symbol("~comma");
    comma_at_symbol     = make_undefined_symbol("~comma-at");
    lambda              = make_undefined_symbol("lambda");
    funarg              = make_undefined_symbol("funarg");
    cfunarg             = make_undefined_symbol("cfunarg");
    opt_key             = make_undefined_symbol("&optional");
    rest_key            = make_undefined_symbol("&rest");
#ifdef COMMON
    key_key             = make_undefined_symbol("&key");
    allow_other_keys    = make_undefined_symbol("&allow-other-keys");
    aux_key             = make_undefined_symbol("&aux");
#endif
    work_symbol         = make_undefined_symbol("~magic-internal-symbol~");
    Lunintern(nil, work_symbol);
#ifndef COMMON
    packid_(CP)         = make_undefined_symbol("package");
#else
    package_symbol      = make_undefined_symbol("package");
    packid_(CP)         = package_symbol;
#endif

    macroexpand_hook    = make_undefined_symbol("*macroexpand-hook*");
    qheader(macroexpand_hook) |= SYM_SPECIAL_VAR;
    evalhook            = make_undefined_symbol("*evalhook*");
    qheader(evalhook)  |= SYM_SPECIAL_VAR;
    qvalue(evalhook)    = nil;
    applyhook           = make_undefined_symbol("*applyhook*");
    qheader(applyhook) |= SYM_SPECIAL_VAR;
    qvalue(applyhook)   = nil;
#ifdef COMMON
    keyword_package     = make_undefined_symbol("*keyword-package*");
    qheader(keyword_package) |= SYM_SPECIAL_VAR;
    qvalue(keyword_package) = make_package(make_string("KEYWORD"));
    err_table           = make_undefined_symbol("*ERROR-MESSAGE*");
#else
    err_table           = make_undefined_symbol("*error-messages*");
#endif
    qheader(err_table) |= SYM_SPECIAL_VAR;
    qvalue(err_table)   = nil;
#ifdef COMMON
#define make_keyword(name) \
        Lintern_2(nil, make_string(name), qvalue(keyword_package))
    internal_symbol     = make_keyword("INTERNAL");
    external_symbol     = make_keyword("EXTERNAL");
    inherited_symbol    = make_keyword("INHERITED");
    allow_key_key       = make_keyword("ALLOW-OTHER-KEYS");
#else
#define make_keyword(name) make_undefined_symbol(name)
#endif
    gensym_base         = make_string("G");
#ifdef COMMON
    expand_def_symbol   = make_undefined_symbol("expand-definer");
    format_symbol       = make_undefined_symbol("format");
    string_char_sym     = make_undefined_symbol("string-char");
    cl_symbols          = make_undefined_symbol("*cl-symbols*");
/*
 * cl_symbols has to be at least a vector or else I can not
 * read in the Lisp file that sets its proper value...
 */
    qvalue(cl_symbols)  = getvector_init(8*CELL, nil);
    features_symbol     = make_undefined_symbol("*features*");
    qheader(cl_symbols)      |= SYM_SPECIAL_VAR;
    qheader(features_symbol) |= SYM_SPECIAL_VAR;
    {   Lisp_Object w;
#define make_constant(name, value)       \
        w = make_undefined_symbol(name); \
        qheader(w) |= SYM_SPECIAL_VAR;   \
        qvalue(w) = value;
        make_constant("most-positive-fixnum", fixnum_of_int(0x07ffffff));
        make_constant("most-negative-fixnum", fixnum_of_int(0xf8000000));
/* #undef  TYPE_LONG_FLOAT                   */
/* #define TYPE_LONG_FLOAT TYPE_DOUBLE_FLOAT */
        make_constant("pi",
            make_boxfloat(3.141592653589793238, TYPE_LONG_FLOAT));
    }
#endif
    append_symbol       = make_undefined_symbol("append");
    raise_symbol        = make_undefined_symbol("*raise");
    lower_symbol        = make_undefined_symbol("*lower");
    echo_symbol         = make_undefined_symbol("*echo");
/*
 * I think that having a built-in symbol called *hankaku even if Kanji support
 * is not otherwise present is not too severe a problem, and making the
 * symbol present always will help keep image files re-usable from one
 * version of CSL to another.
 */
    hankaku_symbol      = make_undefined_symbol("*hankaku");
    comp_symbol         = make_undefined_symbol("*comp");
    compiler_symbol     = make_undefined_symbol("compile");
    native_symbol       = make_undefined_symbol("native-compile");
    bytecoded_symbol    = make_undefined_symbol("bytecoded-definition");
    nativecoded_symbol  = make_undefined_symbol("native-code-definition");
    traceprint_symbol   = make_undefined_symbol("trace-print");
    loadsource_symbol   = make_symbol("load-source", 0, Lload_source, too_many_1, wrong_no_1);
    prinl_symbol        = make_symbol("prinl", 0, Lprin, too_many_1, wrong_no_1);
    emsg_star           = make_undefined_symbol("emsg*");
    redef_msg           = make_undefined_symbol("*redefmsg");
    expr_symbol         = make_undefined_symbol("expr");
    fexpr_symbol        = make_undefined_symbol("fexpr");
    macro_symbol        = make_undefined_symbol("macro");
    break_function      = make_undefined_symbol("*break-loop*");
    gchook              = make_undefined_symbol("*gc-hook*");
    resources           = make_undefined_symbol("*resources*");
    qheader(raise_symbol) |= SYM_SPECIAL_VAR;
    qheader(lower_symbol) |= SYM_SPECIAL_VAR;
    qheader(echo_symbol)  |= SYM_SPECIAL_VAR;
    qheader(hankaku_symbol) |= SYM_SPECIAL_VAR;
    qheader(comp_symbol)  |= SYM_SPECIAL_VAR;
    qheader(emsg_star)    |= SYM_SPECIAL_VAR;
    qheader(redef_msg)    |= SYM_SPECIAL_VAR;
    qheader(break_function)    |= SYM_SPECIAL_VAR;
    qvalue(break_function)      = nil;
    qheader(loadsource_symbol) |= SYM_SPECIAL_VAR;
    qvalue(loadsource_symbol)   = nil;
    qheader(gchook)       |= SYM_SPECIAL_VAR;
    qvalue(gchook)         = nil;
    qheader(resources)    |= SYM_SPECIAL_VAR;
    qvalue(resources)      = nil;
    {   Lisp_Object common = make_undefined_symbol("common-lisp-mode");
        qheader(common)   |= SYM_SPECIAL_VAR;
#ifdef COMMON
        qvalue(common)        = lisp_true;
        qvalue(raise_symbol)  = lisp_true;
        qvalue(lower_symbol)  = nil;
#else
        qvalue(common)        = nil;
        qvalue(raise_symbol)  = nil;
        qvalue(lower_symbol)  = lisp_true;
#endif
    }
    qvalue(echo_symbol)    = nil;
    qvalue(hankaku_symbol) = nil;
    qvalue(comp_symbol)    = nil;
    qvalue(emsg_star)      = nil;
    qvalue(redef_msg)      = lisp_true;

    sys_hash_table = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(2), nil);
    get_counts = Lmkhash(nil, 3, fixnum_of_int(5), fixnum_of_int(0), nil);
/*
 * I make the vector that can hold the names used for "fast" get tags big
 * enough for the largest possible number.
 */
    fastget_names = getvector_init((MAX_FASTGET_SIZE+2)*CELL, SPID_NOPROP);
/*
 * The next bit is a horrid fudge, used in read.c (function orderp) to
 * support REDUCE. It ensures that the flag 'noncom is subject to an
 * optimisation for flag/flagp that allows it to be tested for using a
 * simple bit-test.  This MUST use entry zero (coded as 1 here!).
 * Also I insist that 'lose be the second fastget thing!
 */
    {   Lisp_Object nc = make_undefined_symbol("noncom");
        qheader(nc) |= (1L << SYM_FASTGET_SHIFT);
        elt(fastget_names, 0) = nc;
        nc = make_undefined_symbol("lose");
        qheader(nc) |= (2L << SYM_FASTGET_SHIFT);
        elt(fastget_names, 1) = nc;
    }
/*
 * I create the stream objects just once at cold-start time, but every time I
 * restart I will fill in their components in the standard way again.
 */
    lisp_work_stream = make_stream_handle();
    lisp_terminal_io = make_stream_handle();
    lisp_standard_output = make_stream_handle();
    lisp_standard_input = make_stream_handle();
    lisp_error_output = make_stream_handle();
    lisp_trace_output = make_stream_handle();
    lisp_debug_io = make_stream_handle();
    lisp_query_io = make_stream_handle();
    inject_randomness((int)clock());
    set_up_functions(0);
    set_up_variables(0);
    procstack = nil;
    procmem = getvector_init(CELL*100, nil); /* 0 to 99 */
    procstackp = 0;
}

void set_up_functions(CSLbool restartp)
{
/*
 * All symbols that have a pointer to C code in their function cell must
 * be set up whether we are in a warm OR a cold start state, because the
 * actual addresses associated with C entrypoints will vary from version
 * to version of the binary of the system.
 */
    int i;
    nil_as_base
#ifdef COMMON
/*
 * In Common Lisp mode it could be that the user had something other than the
 * LISP package active when the image was saved. But I want all the symbols
 * that I create or restore here to be in the LISP (or sometimes keyword)
 * package. So I temporarily reset the package here...
 */
    Lisp_Object saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    function_symbol          = make_symbol("function", restartp, function_fn, bad_special2, bad_specialn);
    qheader(function_symbol)|= SYM_SPECIAL_FORM;
    quote_symbol             = make_symbol("quote", restartp, quote_fn, bad_special2, bad_specialn);
    qheader(quote_symbol)   |= SYM_SPECIAL_FORM;
    progn_symbol             = make_symbol("progn", restartp, progn_fn, bad_special2, bad_specialn);
    qheader(progn_symbol)   |= SYM_SPECIAL_FORM;
    declare_symbol           = make_symbol("declare", restartp, declare_fn, bad_special2, bad_specialn);
    qheader(declare_symbol) |= SYM_SPECIAL_FORM;
    special_symbol           = make_undefined_symbol("special");
    cons_symbol              = make_symbol("cons", restartp, too_few_2, Lcons, wrong_no_2);
    eval_symbol              = make_symbol("eval", restartp, Leval, too_many_1, wrong_no_1);
    loadsource_symbol        = make_symbol("load-source", restartp, Lload_source, too_many_1, wrong_no_1);
/*
 * The main bunch of symbols can be handed using a table that
 * gives names and values.
 */
    for (i=0; eval2_setup[i].name != NULL; i++)
        qheader(make_symbol(eval2_setup[i].name,
                            restartp,
                            eval2_setup[i].one,
                            eval2_setup[i].two,
                            eval2_setup[i].n)) |= SYM_SPECIAL_FORM;
    for (i=0; eval3_setup[i].name != NULL; i++)
        qheader(make_symbol(eval3_setup[i].name,
                            restartp,
                            eval3_setup[i].one,
                            eval3_setup[i].two,
                            eval3_setup[i].n)) |= SYM_SPECIAL_FORM;

    create_symbols(arith06_setup, restartp);
    create_symbols(arith08_setup, restartp);
    create_symbols(arith10_setup, restartp);
    create_symbols(arith12_setup, restartp);
    create_symbols(char_setup, restartp);
    create_symbols(eval1_setup, restartp);
    create_symbols(funcs1_setup, restartp);
    create_symbols(funcs2_setup, restartp);
    create_symbols(funcs3_setup, restartp);
    create_symbols(print_setup, restartp);
    create_symbols(read_setup, restartp);
    create_symbols(restart_setup, restartp);
    create_symbols(mpi_setup, restartp);
/*
 * Although almost everything is mapped into upper case in a Common Lisp
 * world I will preserve the case of symbols defined in u01 to u60.
 */
    for (i=0; setup_tables[i]!=NULL; i++)
        create_symbols(setup_tables[i], restartp | 2);

#ifdef NAG
    create_symbols(asp_setup, restartp);
    create_symbols(nag_setup, restartp);
    create_symbols(socket_setup, restartp);
    create_symbols(xdr_setup, restartp);
    create_symbols(grep_setup, restartp);
    create_symbols(axfns_setup, restartp);
    create_symbols(gr_setup, restartp);
#endif

#ifdef OPENMATH
    create_symbols(om_setup, restartp);
    create_symbols(om_parse_setup, restartp);
#endif

#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(13);  /* tail end of setup */
#endif
#endif

#ifdef COMMON
    CP = saved_package;
#endif
}

#ifndef COMMON
#ifdef HAVE_FWIN

static int MS_CDECL alpha1(const void *a, const void *b)
{
    return strcmp(1+*(const char **)a, 1+*(const char **)b);
}

#else

static int MS_CDECL alpha0(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

#endif
#endif

static void set_up_variables(CSLbool restartp)
{
    Lisp_Object nil = C_nil;
    int i;
#ifdef COMMON
    Lisp_Object saved_package = CP;
    CP = find_package("LISP", 4);
#endif
    qvalue(macroexpand_hook) = make_symbol("funcall", restartp, Lfuncall1, Lfuncall2, Lfuncalln);
    input_libraries = make_undefined_symbol("input-libraries");
    qheader(input_libraries)  |= SYM_SPECIAL_VAR;
    qvalue(input_libraries) = nil;
    for (i=number_of_fasl_paths-1; i>=0; i--)
        qvalue(input_libraries) = cons(SPID_LIBRARY + (((int32_t)i)<<20),
                                       qvalue(input_libraries));
    output_library = make_undefined_symbol("output-library");
    qvalue(output_library)  = output_directory < 0 ? nil :
                              SPID_LIBRARY + (((int32_t)output_directory)<<20);
/*
 * The Lisp variable lispsystem* gets set here. (in COMMON mode it is
 * the variable *features*)
 * Its value is a list.
 *       csl                      says I am a CSL Lisp
 *       (executable . "string")  name of current executable (if available)
 *       (shortname . "string")   executable wuithout path or extension
 *       pipes                    do I support open-pipe?
 *       (version . "string")     eg "2.11"
 *       (name . "string")        eg "MSDOS/386"
 *       (opsys . id)             unix/msdos/riscos/win32/finder/riscos/...
 *       id                       unix/msdos etc again...
 *       help                     help mechanism provided within Lisp
 *       debug                    Lisp built with debug options
 *       (native . number)        native code tag
 *       (c-code . number)        u01.c through u60.c define n functions
 *       sixty-four               64-bit address version
 *       texmacs                  "--texmacs" option on command line
 *
 * In COMMON mode the tags on the *features* list are generally in the
 * keyword package. Otherwise they are just regular symbols. This makes it
 * slightly hard to use code that tests this list in a generic environment!
 */
    {
#ifdef COMMON
        Lisp_Object n = features_symbol;
        Lisp_Object w;
        char opsys[32];
        char *p1 = opsys, *p2 = OPSYS;
        int ii;
        while ((*p1++ = toupper(*p2++)) != 0);
        *p1 = 0;
        w = cons(make_keyword(opsys), nil);
#if defined WIN64 || defined __WIN64__ || defined WIN32
        w = cons(make_keyword("WIN32"), w);
#endif
#if defined WIN64 || defined __WIN64__
        w = cons(make_keyword("WIN64"), w);
#endif
        w = acons(make_keyword("LINKER"),
                  make_undefined_symbol(linker_type), w);
        w1 = nil;
        for (ii=sizeof(compiler_command)/sizeof(compiler_command[0])-1;
             ii>=0;
             ii--)
            w1 = cons(make_undefined_symbol(compiler_command[ii]), w1);
        w = acons(make_keyword("COMPILER-COMMAND"), w1, w);
#else
        Lisp_Object n = make_undefined_symbol("lispsystem*");
        Lisp_Object w = cons(make_keyword(OPSYS), nil), w1;
        int ii;
#if defined WIN64 || defined __WIN64__ || defined WIN32
/*
 * In the WIN64 case I will ALSO tell the user than I am "win32". This is
 * a curious thing to do maybe, but is because historically win32 may have
 * been used as a "windows" test, and win64 is in general terms a
 * compatible extension so all win32 options ought still to be available.
 */
        w = cons(make_keyword("win32"), w);
#endif
#if defined WIN64 || defined __WIN64__
        w = cons(make_keyword("win64"), w);
#endif
        qheader(n) |= SYM_SPECIAL_VAR;
        w = acons(make_keyword("linker"),
                  make_undefined_symbol(linker_type), w);
        w1 = nil;
        for (ii=sizeof(compiler_command)/sizeof(compiler_command[0])-1;
             ii>=0;
             ii--)
            w1 = cons(make_undefined_symbol(compiler_command[ii]), w1);
        w = acons(make_keyword("compiler-command"), w1, w);
#endif
        defined_symbols = 0;
        for (i=0; setup_tables[i]!=NULL; i++) count_symbols(setup_tables[i]);
#ifdef COMMON
/*
 * A gratuitous misery here is the need to make COMMON words
 * upper case.
 */
        w = acons(make_keyword("OPSYS"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("NATIVE"),
                  fixnum_of_int(native_code_tag), w);
        w = acons(make_keyword("C-CODE"),
                  fixnum_of_int(defined_symbols), w);
        if (SIXTY_FOUR_BIT) w = cons(make_keyword("SIXTY-FOUR"), w);
#if defined HAVE_POPEN || defined HAVE_FWIN
            w = cons(make_keyword("PIPES"), w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("DEBUG"), w);
#endif
        w = cons(make_keyword("RECORD_GET"), w);
#ifdef HAVE_FWIN
        w = acons(make_keyword("EXECUTABLE"),
                  make_string(fwin_full_program_name), w);
#else
        if (program_name[0] != 0)
            w = acons(make_keyword("EXECUTABLE"),
                      make_string(program_name), w);
#endif
        w = acons(make_keyword("NAME"), make_string(IMPNAME), w);
        w = acons(make_keyword("VERSION"), make_string(VERSION), w);
        w = cons(make_keyword("CCL"), w);
        w = cons(make_keyword("COMMON-LISP"), w);
#else /* !COMMON */
        w = acons(make_keyword("opsys"),
                  make_undefined_symbol(OPSYS), w);
        w = acons(make_keyword("native"),
                  fixnum_of_int(native_code_tag), w);
        w = acons(make_keyword("c-code"),
                  fixnum_of_int(defined_symbols), w);
#ifdef HAVE_FWIN
        if (texmacs_mode)
            w = cons(make_keyword("texmacs"), w);
#endif
        if (SIXTY_FOUR_BIT) w = cons(make_keyword("sixty-four"), w);
#if defined HAVE_POPEN || defined HAVE_FWIN
        w = cons(make_keyword("pipes"), w);
#endif
#ifdef DEBUG
        w = cons(make_keyword("debug"), w);
#endif
#ifdef HAVE_FWIN
        if (fwin_windowmode() & FWIN_WITH_TERMED)
            w = cons(make_keyword("termed"), w);
#ifdef HAVE_LIBFOX
//      if (fwin_windowmode() & FWIN_WITH_FOX)    REINSTATE SOON PLEASE
//          w = cons(make_keyword("fox"), w);
        if (fwin_windowmode() & FWIN_IN_WINDOW)
        {   w = cons(make_keyword("windowed"), w);
// It could be the case that SHOWMATH is compiled in but the necessary
// fonts were not located. Or if they were there but "--" has been used to
// redirect standard output to a file.
            if (showmathInitialised &&
                alternative_stdout == NULL)
                w = cons(make_keyword("showmath"), w);
        }
#endif
#endif
#ifdef RECORD_GET
        w = cons(make_keyword("record_get"), w);
#endif
#ifdef HAVE_FWIN
        w = acons(make_keyword("executable"),
                  make_string(fwin_full_program_name), w);
        w = acons(make_keyword("shortname"),
                  make_string(programName), w);
#else
        if (program_name[0] != 0)
            w = acons(make_keyword("executable"),
                      make_string(program_name), w);
#endif
        w = acons(make_keyword("name"), make_string(IMPNAME), w);
        w = acons(make_keyword("version"), make_string(VERSION), w);
        w = cons(make_keyword("csl"), w);
/*
 * Ha Ha a trick here - if a symbol ADDSQ is defined I view this image
 * as being one for REDUCE and push that information onto lispsystem*,
 * and I also reset the "about box" information (if using fwin).
 */
        w1 = make_undefined_symbol("addsq");
        if (qfn1(w1) != undefined1)
        {   w = cons(make_keyword("reduce"), w);
            w1 = qvalue(make_undefined_symbol("version*"));
            if (is_vector(w1) && 
                type_of_header(vechdr(w1)) == TYPE_STRING)
            {
#if defined HAVE_FWIN && !defined EMBEDDED
                int n = length_of_header(vechdr(w1))-CELL;
                sprintf(about_box_title, "About %.*s",
                   (n > 31-(int)strlen("About ") ?
                        31-(int)strlen("About ") : n),
                   &celt(w1, 0));
                sprintf(about_box_description, "%.*s",
                   (n > 31 ? 31 : n),
                   &celt(w1, 0));
/*
 * The provision here is that if variables called "author!*" and
 * "author2!*" exist with strings as values then those values will
 * appear in the "about box". See a commentary in the file fwin.c about
 * possibly non-obvious constraints on what text you may properly place
 * in these strings.
 */
                w1 = qvalue(make_undefined_symbol("author1*"));
                if (is_vector(w1) && 
                    type_of_header(vechdr(w1)) == TYPE_STRING)
                {   n = length_of_header(vechdr(w1))-CELL;
                    sprintf(about_box_rights_1, "%.*s",
                        n > 31 ? 31 : n, &celt(w1, 0));
                }
                else strcpy(about_box_rights_1, "A C Hearn/RAND");
                w1 = qvalue(make_undefined_symbol("author2*"));
                if (is_vector(w1) && 
                    type_of_header(vechdr(w1)) == TYPE_STRING)
                {   n = length_of_header(vechdr(w1))-CELL;
                    sprintf(about_box_rights_2, "%.*s",
                        n > 31 ? 31 : n, &celt(w1, 0));
                }
                else strcpy(about_box_rights_2, "Codemist Ltd");
#endif
            }
            else
            {
#ifdef HAVE_FWIN
                strcpy(about_box_title, "About REDUCE");
                strcpy(about_box_description, "REDUCE");
                strcpy(about_box_rights_1, "A C Hearn/RAND");
                strcpy(about_box_rights_2, "Codemist Ltd");
#endif
            }
        }
#endif
        qheader(n) |= SYM_SPECIAL_VAR;
        qvalue(n) = w;
    }
#ifdef COMMON
/*
 * Floating point characteristics are taken from <float.h> where it is
 * supposed that the C compiler involved has got the values correct.
 * I do this every time the system is loaded rather than just when an
 * image is cold-created. This is because an image file may have been created
 * on a system differing from the one on which it is used. Mayve in fact
 * IEEE arithmetic is ALMOST universal and I am being too cautious here?
 */
    {   Lisp_Object w;
        make_constant("short-float-epsilon",
                      make_sfloat(16.0*FLT_EPSILON));
        make_constant("single-float-epsilon",
                      make_boxfloat(FLT_EPSILON, TYPE_SINGLE_FLOAT));
        make_constant("double-float-epsilon",
                      make_boxfloat(DBL_EPSILON, TYPE_DOUBLE_FLOAT));
/* For now "long" = "double" */
        make_constant("long-float-epsilon",
                      make_boxfloat(DBL_EPSILON, TYPE_LONG_FLOAT));
/*
 * I assume that I have a radix 2 representation, and float-negative-epsilon
 * is just half float-epsilon. Correct me if I am wrong...
 */
        make_constant("short-float-negative-epsilon",
                      make_sfloat(16.0*FLT_EPSILON/2.0));
        make_constant("single-float-negative-epsilon",
                      make_boxfloat(FLT_EPSILON/2.0, TYPE_SINGLE_FLOAT));
        make_constant("double-float-negative-epsilon",
                      make_boxfloat(DBL_EPSILON/2.0, TYPE_DOUBLE_FLOAT));
/* For now "long" = "double" */
        make_constant("long-float-negative-epsilon",
                      make_boxfloat(DBL_EPSILON/2.0, TYPE_LONG_FLOAT));
/*
 * I hope that the C header file gets extremal values correct. Note that
 * because make_sfloat() truncates (rather than rounding) it should give
 * correct values for most-positive-short-float etc
 */
        make_constant("most-positive-short-float",
                      make_sfloat(FLT_MAX));
        make_constant("most-positive-single-float",
                      make_boxfloat(FLT_MAX, TYPE_SINGLE_FLOAT));
        make_constant("most-positive-double-float",
                      make_boxfloat(DBL_MAX, TYPE_DOUBLE_FLOAT));
        make_constant("most-positive-long-float",
                      make_boxfloat(DBL_MAX, TYPE_LONG_FLOAT));
/*
 * Here I assume that the floating point representation is sign-and-magnitude
 * and hence symmetric about zero.
 */
        make_constant("most-negative-short-float",
                      make_sfloat(-FLT_MAX));
        make_constant("most-negative-single-float",
                      make_boxfloat(-FLT_MAX, TYPE_SINGLE_FLOAT));
        make_constant("most-negative-double-float",
                      make_boxfloat(-DBL_MAX, TYPE_DOUBLE_FLOAT));
        make_constant("most-negative-long-float",
                      make_boxfloat(-DBL_MAX, TYPE_LONG_FLOAT));
/*
 * The "least-xxx" set of values did not consider the case of denormalised
 * numbers too carefully in ClTl-1, so in ClTl-2 there are elaborations. I
 * believe that a proper C header file <float.h> will make the macros that
 * I use here refer to NORMALISED values, so the numeric results I use
 * here will not be quite proper (ie there are smaller floats that are
 * un-normalised). But I will ignore that worry just for now.
 */
        make_constant("least-positive-short-float",
                      make_sfloat(FLT_MIN));
        make_constant("least-positive-single-float",
                      make_boxfloat(FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-positive-double-float",
                      make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-positive-long-float",
                      make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
        make_constant("least-negative-short-float",
                      make_sfloat(-FLT_MIN));
        make_constant("least-negative-single-float",
                      make_boxfloat(-FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-negative-double-float",
                      make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-negative-long-float",
                      make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
/*
 * The bunch here are intended to be NORMALISED numbers, while the unqualified
 * ones above may not be.
 */
        make_constant("least-positive-normalized-short-float",
                      make_sfloat(FLT_MIN));
        make_constant("least-positive-normalized-single-float",
                      make_boxfloat(FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-positive-normalized-double-float",
                      make_boxfloat(DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-positive-normalized-long-float",
                      make_boxfloat(DBL_MIN, TYPE_LONG_FLOAT));
        make_constant("least-negative-normalized-short-float",
                      make_sfloat(-FLT_MIN));
        make_constant("least-negative-normalized-single-float",
                      make_boxfloat(-FLT_MIN, TYPE_SINGLE_FLOAT));
        make_constant("least-negative-normalized-double-float",
                      make_boxfloat(-DBL_MIN, TYPE_DOUBLE_FLOAT));
        make_constant("least-negative-normalized-long-float",
                      make_boxfloat(-DBL_MIN, TYPE_LONG_FLOAT));
#endif
#ifdef UNIX_TIMES
/* /*
 * ACN believes that the following is misguided, since the time-reading
 * function (defined in fns1.c) that CCL provides always returns its answer
 * in milliseconds. This the 1000 below is NOT as arbitrary as all that, it
 * represents the unit that CCL (across all platforms) returns time
 * measurements in. The UNIX_TIMES macro is set on Unix systems to
 * influence whether the times() function or clock() is used to read
 * time, where in the former case Unix makes it possible to separate
 * user and system time.
 */
        /* UNIX_TIMES is set in machine.h and will usually be HZ. */
        make_constant("internal-time-units-per-second",
#ifdef UNIX_TIMES
            fixnum_of_int(UNIX_TIMES));
#else
            fixnum_of_int(1000));
#endif
    }
#endif
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(3);  /* creating symbols */
#endif
#endif
    charvec = getvector_init(257*CELL, nil);
    faslvec = nil;
    faslgensyms = nil;

    qheader(terminal_io = make_undefined_symbol("*terminal-io*"))
        |= SYM_SPECIAL_VAR;
    qheader(standard_input = make_undefined_symbol("*standard-input*"))
        |= SYM_SPECIAL_VAR;
    qheader(standard_output = make_undefined_symbol("*standard-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(error_output = make_undefined_symbol("*error-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(trace_output = make_undefined_symbol("*trace-output*"))
        |= SYM_SPECIAL_VAR;
    qheader(debug_io = make_undefined_symbol("*debug-io*"))
        |= SYM_SPECIAL_VAR;
    qheader(query_io = make_undefined_symbol("*query-io*"))
        |= SYM_SPECIAL_VAR;

    stream_type(lisp_work_stream) = make_undefined_symbol("work-stream");

    {   Lisp_Object f = lisp_terminal_io;
        stream_type(f) = make_undefined_symbol("terminal-stream");
        set_stream_read_fn(f, char_from_terminal);
        set_stream_read_other(f, read_action_terminal);
        set_stream_write_fn(f, char_to_terminal);
        set_stream_write_other(f, write_action_terminal);
        qvalue(terminal_io) = f;

        f = lisp_standard_input;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
/*
 * If I do not have COMMON defined I will take a slight short cut here and
 * make reading from *standard-input* read directly from the terminal. For
 * full Common Lisp compatibility I think *standard-input* is required to
 * be a synonym stream that will dynamically look at the value of the variable
 * *terminal-io* every time it does anything. Ugh, since people who assign to
 * or re-bind *terminal-io* seem to me to be asking for terrible trouble!
 */
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
        qvalue(standard_input) = f;

        f = lisp_standard_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(standard_output) = f;

        f = lisp_error_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(error_output) = f;

        f = lisp_trace_output;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(trace_output) = f;

        f = lisp_debug_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(debug_io) = f;

        f = lisp_query_io;
        stream_type(f) = make_undefined_symbol("synonym-stream");
#ifdef COMMON
        set_stream_read_fn(f, char_from_synonym);
#else
        set_stream_read_fn(f, char_from_terminal);
#endif
        set_stream_read_other(f, read_action_synonym);
        stream_read_data(f) = terminal_io;
#ifdef COMMON
        set_stream_write_fn(f, char_to_synonym);
#else
        set_stream_write_fn(f, char_to_terminal);
#endif
        set_stream_write_other(f, write_action_synonym);
        stream_write_data(f) = terminal_io;
        qvalue(query_io) = f;
    }

#ifdef HAVE_LIBFOX
    {   Lisp_Object stream = make_undefined_symbol("*math-output*");
        Lisp_Object f = make_stream_handle();
        qheader(stream) |= SYM_SPECIAL_VAR;
        stream_type(f) = make_undefined_symbol("math-output");
        set_stream_write_fn(f, char_to_math);
        set_stream_write_other(f, write_action_math);
        qvalue(stream) = f;
        stream = make_undefined_symbol("*spool-output*");
        qheader(stream) |= SYM_SPECIAL_VAR;
        f = make_stream_handle();
        stream_type(f) = make_undefined_symbol("spool-output");
        set_stream_write_fn(f, char_to_spool);
        set_stream_write_other(f, write_action_spool);
        qvalue(stream) = f;
    }
#endif

/*
 * I can not handle boffo overflow very well here, but I do really hope that
 * symbols spelt out on the command line will always be fairly short.
 */
    for (i=0; i<number_of_symbols_to_define; i++)
    {   CSLbool undef = undefine_this_one[i];
        char *s = symbols_to_define[i];
        if (undef)
        {   Lisp_Object n = make_undefined_symbol(s);
            qvalue(n) = unset_var;
        }
        else
        {   char buffer[256];
            char *p = buffer;
            int c;
            Lisp_Object n, v;
            while ((c = *s++) != 0 && c != '=') *p++ = (char)c;
            *p = 0;
            n = make_undefined_symbol(buffer);
            push(n);
            if (c == 0) v = lisp_true;
            else
            {
/*
 * I have been having a big difficulty here, caused by the inconsistent and
 * awkward behaviours of various shells and "make" utilities. In a tidy
 * and simple world I might like a command-line option -Dxx=yyy to allow
 * arbitrary text for yyy terminating it at the next whitespace. Then yyy
 * could be processed by the Lisp reader so that numbers, symbols, strings
 * etc could be specified. However I find that things I often want to
 * use involve characters such as "\" and ":" (as components of file-names
 * on some machines), and sometimes "make" treats these as terminators, or
 * wants to do something magic with "\".  If I put things within quote marks
 * then sometimes the quotes get passed through to Lisp and sometimes not.
 * This is all a BIG misery in a multi-platform situation!  As a fresh
 * attempt to inject sanity I will always convert yyy to a Lisp string. If
 * it is specified with leading and trailing '"' marks I will strip them. Thus
 * both -Dxxx=yyy and -Dxxx="yyy" will leave the variable xxx set to the
 * string "yyy". Then as a Lisp user I can parse the string if I need to
 * interpret it as something else.
 */
#ifndef PASS_PREDEFINES_THROUGH_READER
                if (*s == '"')   /* Convert "yyy" to just yyy */
                {   p = ++s;
                    while (*p != 0) p++;
                    if (*--p == '"') *p = 0;
                }
#endif
                v = make_string(s);
#ifdef PASS_PREDEFINES_THROUGH_READER
                v = Lexplodec(nil, v);
                v = Lcompress(nil, v);
/*
 * The above will first make the value in -Dname=value into a string,
 * then explode it into a list, and compress back - the effect is as if the
 * original value had been passed through the regular Lisp READ function,
 * so symbols, numbers and even s-expressions can be parsed.  If the
 * parsing fails I (silently) treat the value as just NIL.
 */
#endif
                nil = C_nil;
                if (exception_pending()) v = flip_exception();
            }
            pop(n);
            qheader(n) |= SYM_SPECIAL_VAR;
            qvalue(n) = v;
        }
    }
#ifndef COMMON
#ifdef HAVE_FWIN
/*
 * Now if I have the FWIN windowed system I look in the Lisp variables
 *    loadable-packages!*
 *    switches!*
 * (both expected to be lists of symbols) and copy info into a couple of
 * C vectors, whence it can go to the window manager and be used to create
 * suitable menus. I might get in a mess if I try to set and reset menus
 * multiple times, and so to avoid possible confusion I do this step
 * JUST ONCE. This may be limiting (in particular it means that menus get
 * set at the very start of a run ONLY) but should only be visible to those
 * who call restart!-csl.
 */
    if (loadable_packages == NULL && switches==NULL)
    {   Lisp_Object w1 = qvalue(make_undefined_symbol("loadable-packages*"));
        Lisp_Object w2;
        int n;
        char *v;
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; /* How many? */
#ifdef HAVE_FWIN
        n = 2*n;
#endif
        loadable_packages = (char **)(*malloc_hook)((n+1)*sizeof(char *));
        if (loadable_packages != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   Lisp_Object w3 = qcar(w2);
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    type_of_header(vechdr(w3)) != TYPE_STRING) break;
                n1 = length_of_header(vechdr(w3))-CELL;
#ifdef HAVE_FWIN
                v = (char *)(*malloc_hook)(n1+2);
                if (v == NULL) break;
                v[0] = ' ';
                memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
#else
                v = (char *)(*malloc_hook)(n1+1);
                if (v == NULL) break;
                memcpy(v, &celt(w3, 0), n1);
                v[n1] = 0;
#endif
                loadable_packages[n++] = v;
#ifdef HAVE_FWIN
                loadable_packages[n++] = NULL;
#endif
            }
#ifdef HAVE_FWIN
            qsort(loadable_packages, n/2, 2*sizeof(char *), alpha1);
#else
            qsort(loadable_packages, n, sizeof(char *), alpha0);
#endif
            loadable_packages[n] = NULL;   /* NULL-terminate the list */
        }
        w1 = qvalue(make_undefined_symbol("switches*"));
        n = 0;
        for (w2=w1; consp(w2); w2=qcdr(w2)) n++; /* How many? */
        n = (n+1)*sizeof(char *);
#ifdef HAVE_FWIN
        n = 2*n;
#endif
        switches = (char **)(*malloc_hook)(n);
        if (switches != NULL)
        {   n = 0;
            for (w2=w1; consp(w2); w2=qcdr(w2))
            {   Lisp_Object w3 = qcar(w2), w4;
                char sname[64];
                int n1;
                if (is_symbol(w3)) w3 = qpname(w3);
                if (!is_vector(w3) ||
                    type_of_header(vechdr(w3)) != TYPE_STRING) break;
                n1 = length_of_header(vechdr(w3))-CELL;
                if (n1 > 60) break;
                sprintf(sname, "*%.*s", n1, &celt(w3, 0));
                w4 = make_undefined_symbol(sname);
                v = (char *)(*malloc_hook)(n1+2);
                if (v == NULL) break;
/*
 * The first character records the current state of the switch. With FWIN
 * I have entries that say "x" for "I am not at present active" which copes
 * with switches that will become relevant only when a package of code is
 * loaded. I will scan from time to time to update my information - I guess
 * that I can put in a hook that triggers review after any module has been
 * loaded. See the function review_switch_settings() the follows...
 */
                if (qvalue(w4) == nil) v[0] = 'n';
#ifdef HAVE_FWIN
                else if (qvalue(w4) == unset_var) v[0] = 'x';
#endif
                else v[0] = 'y';
                memcpy(v+1, &celt(w3, 0), n1);
                v[n1+1] = 0;
                switches[n++] = v;
#ifdef HAVE_FWIN
                switches[n++] = NULL;
#endif
            }
#ifdef HAVE_FWIN
            qsort(switches, n/2, 2*sizeof(char *), alpha1);
#else
            qsort(switches, n, sizeof(char *), alpha1);
#endif
            switches[n] = NULL;
        }
    }

#endif /* HAVE_FWIN */
#endif /* COMMON */
#ifdef COMMON
    CP = saved_package;
#endif
}

#ifndef COMMON
#ifdef HAVE_FWIN

/*
 * This alse reviews the list of loaded packages...
 */
void review_switch_settings()
{
    Lisp_Object sw = qvalue(make_undefined_symbol("switches*"));
    while (consp(sw))
    {   Lisp_Object s = qcar(sw);
        char sname[64];
        int n1;
        char *v, **p;
        Lisp_Object nil, starsw;
        sw = qcdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) ||
            type_of_header(vechdr(s)) != TYPE_STRING) continue;
        n1 = length_of_header(vechdr(s))-CELL;
        if (n1 > 60) continue;
        sprintf(sname, "*%.*s", n1, &celt(s, 0));
        for (p=switches; *p!=NULL; p+=2)
        {   if (strcmp(1+*p, &sname[1]) == 0) break;
        }
        if ((v=*p) == NULL) continue; 
        starsw = make_undefined_symbol(sname);
        nil = C_nil;
        if (exception_pending())
        {   flip_exception();
            continue;
        }
        if (qvalue(starsw) == nil) switch(*v)
        {
    case 'y':  *v = 0x3f&'N'; break;
    case 'n':                 break;
    case 'x':  *v = 'N';      break;
        }
        else if (qvalue(starsw) == unset_var) switch(*v)
        {
    case 'y':  *v = 'X';      break;
    case 'n':  *v = 'X';      break;
    case 'x':                 break;
        }
        else switch(*v)
        {
    case 'y':                 break;
    case 'n':  *v = 0x3f&'Y'; break;
    case 'x':  *v = 'Y';      break;
        }
    }
    sw = qvalue(make_undefined_symbol("loaded-packages*"));
    while (consp(sw))
    {   Lisp_Object s = qcar(sw);
        char sname[64];
        int n1;
        char *v, **p;
        sw = qcdr(sw);
        if (is_symbol(s)) s = qpname(s);
        if (!is_vector(s) ||
            type_of_header(vechdr(s)) != TYPE_STRING) continue;
        n1 = length_of_header(vechdr(s))-CELL;
        if (n1 > 60) continue;
        sprintf(sname, "%.*s", n1, &celt(s, 0));
        for (p=loadable_packages; *p!=NULL; p+=2)
        {   if (strcmp(1+*p, sname) == 0) break;
        }
        if ((v=*p) == NULL) continue;
        if (*v == ' ') *v = 'X';  /* X here says "update the info" */
    }
    fwin_refresh_switches(switches, loadable_packages);
}

#endif
#endif

CSLbool CSL_MD5_busy;
unsigned char unpredictable[256];
static int n_unpredictable = 0;
static CSLbool unpredictable_pending = 0;

void inject_randomness(int n)
{
    unpredictable[n_unpredictable++] ^= (n % 255);
    if (n_unpredictable >= 256)
    {   n_unpredictable = 0;
        unpredictable_pending = YES;
    }
    if (unpredictable_pending & !CSL_MD5_busy)
    {   CSL_MD5_Init();
        CSL_MD5_Update(unpredictable, sizeof(unpredictable));
        CSL_MD5_Final(unpredictable);
        unpredictable_pending = NO;
    }
}

/*
 * Used to ensure that an image file matches up with the C code compiled
 * into the main executable. The linear search here for the place the
 * checksum lives is a bit crummy. But the total cost is linear in the
 * number of things that have been compiled into C.
 */
static void get_checksum(const setup_type *p)
{
    while (p->name!=NULL) p++;
    if (p->one != NULL && p->two != NULL)
    {   unsigned char *w = (unsigned char *)p->two;
        CSL_MD5_Update(w, strlen((char *)w));
    }
}

void get_user_files_checksum(unsigned char *b)
{
    int i;
    CSL_MD5_Init();
    for (i=0; setup_tables[i]!=NULL; i++)
        get_checksum(setup_tables[i]);
    CSL_MD5_Final(b);
}

void setup(int restartp, double store_size)
{
    int i;
    Lisp_Object nil;
    if (restartp & 2) init_heap_segments(store_size);
    garbage_collection_permitted = 0;
    nil = C_nil;
#ifdef TIDY_UP_MEMORY_AT_START
/*
 * The following feature, which should not be neded, is liable to be
 * expensive on big machines because it touches all memory.
 * The code is left in case it helps with repeatability in the face
 * of accesses to uninitialised locations (ie BUGS).
 */
    for (i=0; i<pages_count; i++)
        memset(pages[i], 0, (size_t)CSL_PAGE_SIZE+16);
    memset(stacksegment, 0, (size_t)stack_segsize*CSL_PAGE_SIZE+16);
    memset(nilsegment, 0, (size_t)NIL_SEGMENT_SIZE);
#endif
    stack = stackbase;
    exit_tag = exit_value = nil;
    exit_reason = UNWIND_NULL;

    if (restartp & 1)
    {   char junkbuf[120];
        char filename[LONGEST_LEGAL_FILENAME];
        if (IopenRoot(filename, 0, 0))
        {   term_printf("\n+++ Image file \"%s\" can not be read\n",
                    filename);
            my_exit(EXIT_FAILURE);
        }
/*
 * I read input via a buffer of size FREAD_BUFFER_SIZE, which I pre-fill
 * at this stage before I even try to read anything
 */
        fread_ptr = (unsigned char *)stack;
        fread_count = Iread(fread_ptr, FREAD_BUFFER_SIZE);
/*
 * I can adjust here (automatically) for whatever compression threshold
 * had been active when the image file was created.
 */
        compression_worth_while = 128;
        Cfread(junkbuf, 112);
        {   int fg = junkbuf[111];
            while (fg != 0) compression_worth_while <<= 1, fg--;
        }
        if (init_flags & INIT_VERBOSE)
        {   term_printf("Created: %.25s\n", &junkbuf[64]);
            /* Time dump was taken */
        }
        {   unsigned char chk[16];
            get_user_files_checksum(chk);
            for (i=0; i<16; i++)
            {   if (chk[i] != (junkbuf[90+i] & 0xff))
                {   term_printf(
                        "\n+++ Image file belongs with a different version\n");
                    term_printf(
                        "    of the executable file (incompatible code\n");
                    term_printf(
                        "    has been optimised into C and incorporated)\n");
                    term_printf(
                        "    Unable to use this image file, so stopping\n");
                    my_exit(EXIT_FAILURE);
                }
            }
        }
/*
 * To make things more responsive for the user I will display a
 * banner rather early (before reading the bulk of the image file).
 * The banner that I will display is one provided to be by PRESERVE.
 */
        {   Ihandle save;
            char b[64];
            Icontext(&save);
#define BANNER_CODE (-1002)
            if (IopenRoot(filename, BANNER_CODE, 0)) b[0] = 0;
            else
            {   for (i=0; i<64; i++) b[i] = (char)Igetc();
                IcloseInput(NO);
            }
            Irestore_context(save);
/*
 * A banner set via startup-banner takes precedence over one from preserve.
 * But as a very special hack I detect if --texmacs was on the command
 * line and in that case I stay quiet...
 */
#ifdef HAVE_FWIN
            if (!texmacs_mode)
#endif
            {   if (b[0] != 0)
                {   term_printf("%s\n", b);
                    ensure_screen();
                }
                else if (junkbuf[0] != 0)
                {   term_printf("%s\n", junkbuf);
                    ensure_screen();
                }
            }
        }
/*
 * Now I need to start worrying about 32 vs 64-bit image files.
 */
        if (SIXTY_FOUR_BIT)
        {   converting_to_32 = 0;
            converting_to_64 = ((rootDirectory->h.version & 0x80) == 0);
        }
        else
        {   converting_to_32 = ((rootDirectory->h.version & 0x80) != 0);
            converting_to_64 = 0;
        }
/*
 * If if image file was made by a 32-bit system but I am now running in
 * 64-bit mode or vice versa things are tricky and at present may CRASH!!!
 * I BELIEVE that loading a 64-bit image on a 32-bit system may be OK but
 * conversion in the other direction is unambiguously not supported yet.
 * But there are comments and fragments of code that show the path I am
 * taking towards it.
 *
 * One thing I have not yet thought about properly is checking that if I
 * re-preserve to this image file the new image directory entry for the
 * freshly created heap image must have the correct information. I hope that
 * that happens naturally in preserve.c.
 *
 * Temporary alert while I develop code to support width conversion... This
 * should never appear unless you are loading a "different word width" image
 * and in that case I want you to have been warned that there may be glitches.
 */
#ifdef DEBUG
/*
 * If I am debugging a brief indication that I need to re-size the heap
 * is probably justifiable.
 */
        if (converting_to_32 || converting_to_64)
        {   printf("->32 = %d  ->64 = %d\n", converting_to_32, converting_to_64);
            fflush(stderr);
        }
#endif
        Cfread(junkbuf, 8);
/*
 * If the heap image had been made on a 64-bit machine but the current
 * system is running at 32-bits then the region in the file I need to
 * read here is twice as big as is needed. I must shrink it. I need
 * some temporary space while I do that. I will use the memory at
 * pages[0], which is a bit of a cheat, but I have allocated that already
 * but do not use it until later.
 */
        if (converting_to_32)
        {   int64_t *p = (int64_t *)pages[0];
            int32_t *q = (int32_t *)BASE;
/* read twice as much because it should be in 64-bit units */
            Cfread((char *)p, (2*sizeof(Lisp_Object))*last_nil_offset);
/*
 * At present I just truncate the values in all the nil-segment to 32-bits.
 * I can imagine a further messy case if I ever introduce wide fixnums for
 * 64-bit machines. In that case I would need to detect when a value here
 * fell into that category and convert it to a reference to a newly created
 * bignum. But that should not arise at the moment!
 *
 * Now in fact here and in the conversion the other way I have a bit of
 * pain in that I can not merely truncate because it could be that I should
 * be adjusting the byte order. In that case I would need to preserve the
 * other 4 bytes of each 8-byte quantity. Unfortunately in the normal
 * pattern on things I load the nil-segment BEFORE I test to see if I need
 * to do a byte-order conversion! So here I put in an ad-hoc early check
 * on the byte-order signature... Ugh.
 */
            uint64_t temp_byteflip = p[12];
/*
 * The test here will only be needed in the case that the image was made on
 * a 64-bit system, in which case the value of byteflip is 00000000xxxxxxxx
 * if no flip is needed, and xxxxxxxx00000000 if it is. Note that the
 * fact that the 32-bit part never has its top bit set removes risk of
 * sign-extension ever having propagated ffffffff into where I want 00000000.
 * Note also that these days I will ensure that EVERY item in the nil-segment
 * is an intprt_t so I can handle all of them uniformly.
 */
            flip_needed = (temp_byteflip & 0x7fffffffU) == 0;
            for (i=0; i<last_nil_offset; i++)
            {   int64_t w = *p++;
                int32_t r;
/*
 * Items 24-31 are handled in a very odd way here because once they were
 * 32-bit values stashed in the lower 4 bytes of the field regardless of
 * byte-order. I keep any non-zero part of a 64-bit word in that case. 
 */
                if (i<24 || i>31) r = (int32_t)(flip_needed ? (w>>32) : w); 
                else if ((int32_t)w == 0) r = (int32_t)(w>>32);
                else r = (int32_t)w;
                *q++ = r;
            }
        }
        else if (converting_to_64)
        {
/*
 * The heap image was made by a 32-bit system but I am a 64-bit one. So
 * when I read in the nilseg it will need to be expanded out to 64-bit
 * values. I will sign extend in each case.. that will cope with the
 * packed representation of Lisp_Objects (because immediate data is
 * all naturally signed, and pointer data is really only 31 bits wide to
 * leave room for a GC bit).
 * As in the case of narrowing the data I will need to cope with possible
 * byte-order effects. In the normal case I will expand abcdefgh into
 * ssssssssabcdefgh where s is the sign bit I propagate. If I am
 * flipping bytes it will need to turn into abcdefghssssssss where s comes
 * from the top bit of h. That is because later on I will turn that back
 * into sssssssshgfedcba.
 * Note also that the amount I read will be based on 32-bit data not 64
 * hence the odd-looking "/2" in the next line.
 */
            Cfread((char *)BASE, (sizeof(Lisp_Object)/2)*last_nil_offset);
/*
 * Copying from the top downwards avoids clobbering stuff here. As with the
 * conversion in the other direction I coull have extra work to do if I
 * introduced 64-bit fixnums. I would need to detect fixnums that fitted in
 * 64-bits but not 32 and convert them into bignums...
 */
/*
 * Beware here that I want to sign extend data but it may at present be
 * in the wrong byte order for the current machine - but to know that I
 * must first establish if flipping is required!
 */
            i = ((int32_t *)BASE)[12]; /* 32-bit value of byteflip */
            if (((i >> 16) & 0xffffU) == 0x5678U) flip_needed = NO;
            else if ((i & 0xffffU) == 0x7856U) flip_needed = YES;
            else
            {   term_printf("\n+++ The checkpoint file is corrupt\n");
                my_exit(EXIT_FAILURE);
            }
            for (i=last_nil_offset-1; i>=0; i--)
            {   *(int64_t *)((char *)BASE+8*i) =
                    expand_to_64(*(int32_t *)((char *)BASE+4*i));
            }
        }
        else Cfread((char *)BASE, sizeof(Lisp_Object)*last_nil_offset);
        copy_out_of_nilseg(YES);
#ifndef COMMON
        qheader(nil) = TAG_ODDS+TYPE_SYMBOL+SYM_SPECIAL_VAR;/* BEFORE nil... */
#endif
/*
 * Now the value in byteflip is really a 32-bit value saved an intptr_t,
 * and if my bytes are in a funny order because the 64-bit values had been
 * saved on a machine with the other byte-order it may be that the 32-bits
 * that I want are in fact in the top half of the 64-bit word. So if I am on
 * a 64-bit machine I adjust for that. I do not take the mere fact of the
 * low half being zero as full evidence that I am flipped, since I would
 * like to check for the 0x5678 pattern as an extra consistency check.
 */
        if (SIXTY_FOUR_BIT)
        {   if ((byteflip & 0x7fffffff) == 0)
                byteflip = (Lisp_Object)((int64_t)byteflip >> 32);
        }
        if (((byteflip >> 16) & 0xffffU) == 0x5678U)
        {
            flip_needed = NO;
            old_fp_rep = (int)(byteflip & FP_MASK);
            old_page_bits = (int)((byteflip >> 8) & 0x1f);
        }
        else if ((byteflip & 0xffffU) == 0x7856U)
        {
            flip_needed = YES;
            old_fp_rep = (int)(flip_32bits(byteflip) & FP_MASK);
            old_page_bits = (int)((flip_32bits(byteflip) >> 8) & 0x1f);
        }
        else
        {   term_printf("\n+++ The checkpoint file is corrupt\n");
/*
 * Note: I use different numbers to check byte-ordering on segmented feature
 * non-segmented systems, since the heap image formats are not compatible.
 * A result will be that use of the wrong sort of image will lead to a
 * "checkpoint file corrupt" message rather than a more serious shambles.
 */
            my_exit(EXIT_FAILURE);
        }
        if (old_page_bits == 0) old_page_bits = 16; /* Old default value */
/*
 * I could in fact recover in the case that old_page_bits < PAGE_BITS, since
 * I could just map the old small pages into the new big ones with a little
 * padding where needed.  I will not do that JUST yet.  In general it will
 * not be possible to load an image with large pages into a CSL that only
 * has small ones - eg there might be some vector that just would not fit
 * in the small page size.  Even discounting that worry rearranging the
 * heap to allow for the discontinuities at the smaller page granularity would
 * be pretty painful.  Again in the limit something very much akin to the
 * normal garbage collector could probably do it if it ever became really
 * necessary.
 */
        if (old_page_bits != PAGE_BITS)
        {   term_printf("\n+++ The checkpoint file was made on a machine\n");
            term_printf("where CSL had been configured with a different page\n");
            term_printf("size. It is not usable with this version.\n");
            my_exit(EXIT_FAILURE);
        }
        /* The saved value of NIL is not needed in this case */
    }
    else
    {
        for (i=first_nil_offset; i<last_nil_offset; i++)
             BASE[i] = nil;
        copy_out_of_nilseg(NO);
    }

    savestacklimit = stacklimit = &stack[stack_segsize*CSL_PAGE_SIZE/4-200]; 
                 /* allow some slop at end */
/*
 * Note that the value of byteflip on 1 32-bit machine will look like
 *     0x5678nm0b   where nm is certainly less than 64 and b is just a few
 * bits. If the byte order is reversed this becomes
 *     0x0bnm7856
 * On a 64-bit system it is
 *     0x000000005678nm0b
 * or  0x0bnm785600000000
 * and in ALL cases it is positive, so whether it is represented as a
 * signed or unsigned value is immaterial.
 */
    byteflip = 0x56780000 |
               ((int32_t)current_fp_rep & ~FP_WORD_ORDER) |
               (((int32_t)PAGE_BITS) << 8);
    native_pages_changed = 0;
    if ((restartp & 1) != 0) warm_setup((restartp & 4) != 0);
    else cold_setup((restartp & 4) != 0);

    if (init_flags & INIT_QUIET) Lverbos(nil, fixnum_of_int(1));
    if (init_flags & INIT_VERBOSE) Lverbos(nil, fixnum_of_int(3));
/*
 * Here I grab more memory (if I am allowed to) until the proportion of the
 * heap active at the end of garbage collection is less than 1/2.  If the
 * attempt to grab more memory fails I clear the bit in init_flags that
 * allows me to try to expand, so I will not waste time again.
 * The aim of keeping the heap less than half full is an heuristic and
 * could be adjusted on the basis of experience with this code.
 */
    if (init_flags & INIT_EXPANDABLE)
    {   int32_t more = heap_pages_count + vheap_pages_count +
                     bps_pages_count + native_pages_count;
        more = 3 *more - pages_count;
        while (more-- > 0)
        {   void *page = (void *)my_malloc_1((size_t)(CSL_PAGE_SIZE + 16));
/*
 * CF the code in gc.c -- I can still use my_malloc_1 here, which makes this
 * code just a tiny bit safer.
 */
            intptr_t pun = (intptr_t)page;
            intptr_t pun1 = (intptr_t)((char *)page + CSL_PAGE_SIZE + 16);
            if ((pun ^ pun1) < 0) page = NULL;
            if ((pun + address_sign) < 0) page = NULL;
            if (page == NULL)
            {   init_flags &= ~INIT_EXPANDABLE;
                break;
            }
            else pages[pages_count++] = page;
        }
    }
    {
      int32_t w = 0;
/*
 * The total store allocated is that used plus that free, including the
 * page set aside for the Lisp stack. I had better report this in Kbytes
 * which should then be sort of OK up to a total of 4000 Gbytes before the
 * unsigned long overflows on me.
 */
        if (init_flags & INIT_VERBOSE)
        {   unsigned long m =
                ((unsigned long)(CSL_PAGE_SIZE/1000))*(pages_count+w+1);
            if (m > 4000)
                term_printf("Memory allocation: %lu Mbytes\n", m/1000);
            else term_printf("Memory allocation: %lu Kbytes\n", m);
        }
    }
#ifdef MEMORY_TRACE
#ifndef CHECK_ONLY
    memory_comment(15);
#endif
#endif
    if (init_flags & INIT_VERBOSE)
    {   int n = number_of_processors();
        if (n > 1)
            term_printf("There are %d processors available\n", n);
    }
#ifdef DEBUG
    copy_into_nilseg(NO);
    validate_all("restarting", __LINE__, __FILE__);
#endif
    garbage_collection_permitted = 1;
    return;
}

void copy_into_nilseg(int fg)
{
    Lisp_Object nil = C_nil;

#ifdef NILSEG_EXTERNS
    int i;
    if (fg)     /* move non list bases too */
    {   BASE[12]                                 = byteflip;
        BASE[13]                                 = codefringe;
        *(Lisp_Object volatile *)&BASE[14]       = codelimit;
/*
 * The messing around here is to ensure that on 64-bit architectures
 * stacklimit is kept properly aligned.
 */
#ifdef COMMON
        *(Lisp_Object * volatile *)&BASE[16] = stacklimit;
#else
        *(Lisp_Object * volatile *)&BASE[15] = stacklimit;
#endif
        BASE[18]                             = fringe;
        *(Lisp_Object volatile *)&BASE[19]   = heaplimit;
        *(Lisp_Object volatile *)&BASE[20]   = vheaplimit;
        BASE[21]                             = vfringe;
        BASE[22]                             = miscflags;

        BASE[24]                             = nwork;
/*      BASE[25]                             = exit_reason; */
        BASE[26]                             = exit_count;
        BASE[27]                             = gensym_ser;
        BASE[28]                             = print_precision;
        BASE[29]                             = current_modulus;
        BASE[30]                             = fastget_size;
        BASE[31]                             = package_bits;
    }
/*
 * Entries 50 and 51 are used for chains of hash tables, and so get
 * very special individual treatment. See comments elsewhere.
 */
    BASE[52]     = current_package;
    BASE[53]     = B_reg;
    BASE[54]     = codevec;
    BASE[55]     = litvec;
    BASE[56]     = exit_tag;
    BASE[57]     = exit_value;
    BASE[58]     = catch_tags;
    BASE[59]     = lisp_package;
    BASE[60]     = boffo;
    BASE[61]     = charvec;
    BASE[62]     = sys_hash_table;
    BASE[63]     = help_index;
    BASE[64]     = gensym_base;
    BASE[65]     = err_table;
    BASE[66]     = supervisor;
    BASE[67]     = startfn;
    BASE[68]     = faslvec;
    BASE[69]     = tracedfn;
    BASE[70]     = prompt_thing;
    BASE[71]     = faslgensyms;
    BASE[72]     = cl_symbols;
    BASE[73]     = active_stream;
    BASE[74]     = current_module;
    BASE[75]     = native_defs;

    BASE[90]     = append_symbol;
    BASE[91]     = applyhook;
    BASE[92]     = cfunarg;
    BASE[93]     = comma_at_symbol;
    BASE[94]     = comma_symbol;
    BASE[95]     = compiler_symbol;
    BASE[96]     = comp_symbol;
    BASE[97]     = cons_symbol;
    BASE[98]     = echo_symbol;
    BASE[99]     = emsg_star;
    BASE[100]    = evalhook;
    BASE[101]    = eval_symbol;
    BASE[102]    = expr_symbol;
    BASE[103]    = features_symbol;
    BASE[104]    = fexpr_symbol;
    BASE[105]    = funarg;
    BASE[106]    = function_symbol;
    BASE[107]    = lambda;
    BASE[108]    = lisp_true;
    BASE[109]    = lower_symbol;
    BASE[110]    = macroexpand_hook;
    BASE[111]    = macro_symbol;
    BASE[112]    = opt_key;
    BASE[113]    = prinl_symbol;
    BASE[114]    = progn_symbol;
    BASE[115]    = quote_symbol;
    BASE[116]    = raise_symbol;
    BASE[117]    = redef_msg;
    BASE[118]    = rest_key;
    BASE[119]    = savedef;
    BASE[120]    = string_char_sym;
    BASE[121]    = unset_var;
    BASE[122]    = work_symbol;
    BASE[123]    = lex_words;
    BASE[124]    = get_counts;
    BASE[125]    = fastget_names;
    BASE[126]    = input_libraries;
    BASE[127]    = output_library;
    BASE[128]    = current_file;
    BASE[129]    = break_function;

    BASE[130]    = lisp_work_stream;
    BASE[131]    = lisp_standard_output;
    BASE[132]    = lisp_standard_input;
    BASE[133]    = lisp_debug_io;
    BASE[134]    = lisp_error_output;
    BASE[135]    = lisp_query_io;
    BASE[136]    = lisp_terminal_io;
    BASE[137]    = lisp_trace_output;
    BASE[138]    = standard_output;
    BASE[139]    = standard_input;
    BASE[140]    = debug_io;
    BASE[141]    = error_output;
    BASE[142]    = query_io;
    BASE[143]    = terminal_io;
    BASE[144]    = trace_output;
    BASE[145]    = fasl_stream;
    BASE[146]    = native_code;
    BASE[147]    = native_symbol;
    BASE[148]    = traceprint_symbol;
    BASE[149]    = loadsource_symbol;
    BASE[150]    = hankaku_symbol;
    BASE[151]    = bytecoded_symbol;
    BASE[152]    = nativecoded_symbol;
    BASE[153]    = gchook;
    BASE[154]    = resources;
    BASE[155]    = callstack;
    BASE[156]    = procstack;
    BASE[157]    = procmem;

#ifdef COMMON
    BASE[170]    = keyword_package;
    BASE[171]    = all_packages;
    BASE[172]    = package_symbol;
    BASE[173]    = internal_symbol;
    BASE[174]    = external_symbol;
    BASE[175]    = inherited_symbol;
    BASE[176]    = key_key;
    BASE[177]    = allow_other_keys;
    BASE[178]    = aux_key;
    BASE[179]    = format_symbol;
    BASE[180]    = expand_def_symbol;
    BASE[181]    = allow_key_key;
#endif
/*
 * I USED to support these only in Common Lisp mode but now I find I need
 * them even in Standard Lisp mode...
 */
    BASE[182]    = declare_symbol;
    BASE[183]    = special_symbol;

    for (i=0; i<=50; i++)
        BASE[work_0_offset+i]   = workbase[i];
#endif /* NILSEG_EXTERNS */

    if (fg)
    {
#ifdef COMMON
        *(Lisp_Object * volatile *)&BASE[16] = stacklimit;
#else
        *(Lisp_Object * volatile *)&BASE[15] = stacklimit;
#endif
    }
    BASE[190]    = user_base_0;
    BASE[191]    = user_base_1;
    BASE[192]    = user_base_2;
    BASE[193]    = user_base_3;
    BASE[194]    = user_base_4;
    BASE[195]    = user_base_5;
    BASE[196]    = user_base_6;
    BASE[197]    = user_base_7;
    BASE[198]    = user_base_8;
    BASE[199]    = user_base_9;

}

void copy_out_of_nilseg(int fg)
{
    Lisp_Object nil = C_nil;

#ifdef NILSEG_EXTERNS
    int i;
    if (fg)
    {
        byteflip         = BASE[12];
        codefringe       = BASE[13];
        codelimit        = *(Lisp_Object volatile *)&BASE[14];
        fringe           = BASE[18];
        heaplimit        = *(Lisp_Object volatile *)&BASE[19];
        vheaplimit       = *(Lisp_Object volatile *)&BASE[20];
        vfringe          = BASE[21];
        miscflags        = BASE[22];

        nwork            = BASE[24];
/*      exit_reason      = BASE[25]; */
        exit_count       = BASE[26];
        gensym_ser       = BASE[27];
        print_precision  = BASE[28];
        current_modulus  = BASE[29];
        fastget_size     = BASE[30];
        package_bits     = BASE[31];
    }

    current_package       = BASE[52];
    B_reg                 = BASE[53];
    codevec               = BASE[54];
    litvec                = BASE[55];
    exit_tag              = BASE[56];
    exit_value            = BASE[57];
    catch_tags            = BASE[58];
    lisp_package          = BASE[59];
    boffo                 = BASE[60];
    charvec               = BASE[61];
    sys_hash_table        = BASE[62];
    help_index            = BASE[63];
    gensym_base           = BASE[64];
    err_table             = BASE[65];
    supervisor            = BASE[66];
    startfn               = BASE[67];
    faslvec               = BASE[68];
    tracedfn              = BASE[69];
    prompt_thing          = BASE[70];
    faslgensyms           = BASE[71];
    cl_symbols            = BASE[72];
    active_stream         = BASE[73];
    current_module        = BASE[74];
    native_defs           = BASE[75];

    append_symbol         = BASE[90];
    applyhook             = BASE[91];
    cfunarg               = BASE[92];
    comma_at_symbol       = BASE[93];
    comma_symbol          = BASE[94];
    compiler_symbol       = BASE[95];
    comp_symbol           = BASE[96];
    cons_symbol           = BASE[97];
    echo_symbol           = BASE[98];
    emsg_star             = BASE[99];
    evalhook              = BASE[100];
    eval_symbol           = BASE[101];
    expr_symbol           = BASE[102];
    features_symbol       = BASE[103];
    fexpr_symbol          = BASE[104];
    funarg                = BASE[105];
    function_symbol       = BASE[106];
    lambda                = BASE[107];
    lisp_true             = BASE[108];
    lower_symbol          = BASE[109];
    macroexpand_hook      = BASE[110];
    macro_symbol          = BASE[111];
    opt_key               = BASE[112];
    prinl_symbol          = BASE[113];
    progn_symbol          = BASE[114];
    quote_symbol          = BASE[115];
    raise_symbol          = BASE[116];
    redef_msg             = BASE[117];
    rest_key              = BASE[118];
    savedef               = BASE[119];
    string_char_sym       = BASE[120];
    unset_var             = BASE[121];
    work_symbol           = BASE[122];
    lex_words             = BASE[123];
    get_counts            = BASE[124];
    fastget_names         = BASE[125];
    input_libraries       = BASE[126];
    output_library        = BASE[127];
    current_file          = BASE[128];
    break_function        = BASE[129];

    lisp_work_stream      = BASE[130];
    lisp_standard_output  = BASE[131];
    lisp_standard_input   = BASE[132];
    lisp_debug_io         = BASE[133];
    lisp_error_output     = BASE[134];
    lisp_query_io         = BASE[135];
    lisp_terminal_io      = BASE[136];
    lisp_trace_output     = BASE[137];
    standard_output       = BASE[138];
    standard_input        = BASE[139];
    debug_io              = BASE[140];
    error_output          = BASE[141];
    query_io              = BASE[142];
    terminal_io           = BASE[143];
    trace_output          = BASE[144];
    fasl_stream           = BASE[145];
    native_code           = BASE[146];
    native_symbol         = BASE[147];
    traceprint_symbol     = BASE[148];
    loadsource_symbol     = BASE[149];
    hankaku_symbol        = BASE[150];
    bytecoded_symbol      = BASE[151];
    nativecoded_symbol    = BASE[152];
    gchook                = BASE[153];
    resources             = BASE[154];
    callstack             = BASE[155];
    procstack             = BASE[156];
    procmem               = BASE[157];

#ifdef COMMON

    keyword_package       = BASE[170];
    all_packages          = BASE[171];
    package_symbol        = BASE[172];
    internal_symbol       = BASE[173];
    external_symbol       = BASE[174];
    inherited_symbol      = BASE[175];
    key_key               = BASE[176];
    allow_other_keys      = BASE[177];
    aux_key               = BASE[178];
    format_symbol         = BASE[179];
    expand_def_symbol     = BASE[180];
    allow_key_key         = BASE[181];

#endif

    declare_symbol        = BASE[182];
    special_symbol        = BASE[183];

    for (i = 0; i<=50; i++)
        workbase[i]  = BASE[work_0_offset+i];
#endif /* NILSEG_EXTERNS */

    if (fg)
    {
#ifdef COMMON
        stacklimit       = *(Lisp_Object *volatile *)&BASE[16];
#else
        stacklimit       = *(Lisp_Object *volatile *)&BASE[15];
#endif
    }

    user_base_0           = BASE[190];
    user_base_1           = BASE[191];
    user_base_2           = BASE[192];
    user_base_3           = BASE[193];
    user_base_4           = BASE[194];
    user_base_5           = BASE[195];
    user_base_6           = BASE[196];
    user_base_7           = BASE[197];
    user_base_8           = BASE[198];
    user_base_9           = BASE[199];
}

/*
 * For some of what follows I think I need to show that I have considered
 * the issue of export regulations.
 *
 * What I have here is MD5 (and when and if I feel keen SHA-1). I observe
 * that MD5, SHA-1 and DSA are made available as part of Sun's Java
 * Development Kit in the version that can be downloade freely from their
 * servers. They have a separate Java Cryptography Extension within which
 * they keep things that are subject to USA export regulations. I take this
 * as encouragement to believe that these three algorithms are not subject
 * to USA export limits. I believe such limits to be supersets (ie more
 * restrictive) than ones that apply in the UK and so feel happy about
 * including the implementations that I do here. Specifically, although I
 * have extracts from the SSL code which as a whole might give trouble if
 * importen to the USA and the re-exported I only have the message digest
 * bits that should not be so encumbered. I am aware that MD5 is now
 * considered weakish with SHA-1 the improved replacement, but will take the
 * view that I was not aiming for real security on anything anyway!
 */

/*
 *  MD5 message digest code, adapted from Eric Young's version,
 *  for which the copyright and disclaimer notices follow. Observe that
 *  this code can be adapted and re-used subject to these terms being
 *  retained.
 *
 * NOTE that I have stuck "CSL_" on the front of names since in some cases
 * a crypto library may find itself getting linked in with bits of CSL code
 * and names could otehrwise clash. Specifically this could happen on
 * Mac/Darwin when CSL is built with a flat namespace ready for dynamically
 * loading modules.
 */


/* crypto/md/md5.c and support files */
/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@mincom.oz.au).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@mincom.oz.au).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@mincom.oz.au)"
 *    The word 'cryptographic' can be left out if the routines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

/*
 * End of Eric Young's copyright and disclaimer notice.
 *
 * The changes made by A C Norman remove some optimisation to leave shorter
 * code (I will not be using this in speed-critical applications) and
 * adjusting the style and layout to agree with other Codemist utilities.
 */

#define MD5_CBLOCK         64
#define MD5_LBLOCK         16

static uint32_t MD5_A, MD5_B, MD5_C, MD5_D;
static uint32_t MD5_Nl;
static int MD5_num;
static uint32_t MD5_data[MD5_CBLOCK];

#define F(x,y,z)        ((((y) ^ (z)) & (x)) ^ (z))
#define G(x,y,z)        ((((x) ^ (y)) & (z)) ^ (y))
#define H(x,y,z)        ((x) ^ (y) ^ (z))
#define I(x,y,z)        (((x) | (~(z))) ^ (y))

#define ROTATE(a,n)     (((a)<<(n))|((a)>>(32-(n))))


#define R0(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+F((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R1(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+G((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R2(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+H((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }

#define R3(a,b,c,d,k,s,t) {          \
        a+=((k)+(t)+I((b),(c),(d))); \
        a=ROTATE(a,s);               \
        a+=b; }


/*
 * Implemented from RFC1321 The MD5 Message-Digest Algorithm
 */

void CSL_MD5_Init(void)
{
    CSL_MD5_busy = YES;
    MD5_A = 0x67452301;
    MD5_B = 0xefcdab89;
    MD5_C = 0x98badcfe;
    MD5_D = 0x10325476;
    MD5_Nl = 0;
    MD5_num = 0;
}

/*
 * Use of "D" as a variable name clashes with a debugging-macro that I have!
 */

#undef D

static unsigned char byte_order_test[4] = {1, 0, 0, 0};

static void md5_block(void)
{
    uint32_t A=MD5_A, B=MD5_B, C=MD5_C, D=MD5_D;
    int i;
/*
 * Here I re-write the buffer so that it now behaves as if it is
 * an array of 32-bit words in native computer representation. On
 * many machines the code here will have no effect at all apart from
 * consuming a little time. I do a little test first to see if
 * it is really needed.
 */
    uint32_t *p = MD5_data;
    unsigned char *q = (unsigned char *)p;
    if (((uint32_t *)byte_order_test)[0] != 1)
    {   for (i=0; i<MD5_LBLOCK; i++)
        {   uint32_t w = *q++;
            w |= *q++ << 8;
            w |= *q++ << 16;
            w |= *q++ << 24;
            *p++ = w;
        }
    }
    p = MD5_data;
    /* Round 0 */
    R0(A,B,C,D,p[ 0], 7,0xd76aa478); R0(D,A,B,C,p[ 1],12,0xe8c7b756);
    R0(C,D,A,B,p[ 2],17,0x242070db); R0(B,C,D,A,p[ 3],22,0xc1bdceee);
    R0(A,B,C,D,p[ 4], 7,0xf57c0faf); R0(D,A,B,C,p[ 5],12,0x4787c62a);
    R0(C,D,A,B,p[ 6],17,0xa8304613); R0(B,C,D,A,p[ 7],22,0xfd469501);
    R0(A,B,C,D,p[ 8], 7,0x698098d8); R0(D,A,B,C,p[ 9],12,0x8b44f7af);
    R0(C,D,A,B,p[10],17,0xffff5bb1); R0(B,C,D,A,p[11],22,0x895cd7be);
    R0(A,B,C,D,p[12], 7,0x6b901122); R0(D,A,B,C,p[13],12,0xfd987193);
    R0(C,D,A,B,p[14],17,0xa679438e); R0(B,C,D,A,p[15],22,0x49b40821);
    /* Round 1 */
    R1(A,B,C,D,p[ 1], 5,0xf61e2562); R1(D,A,B,C,p[ 6], 9,0xc040b340);
    R1(C,D,A,B,p[11],14,0x265e5a51); R1(B,C,D,A,p[ 0],20,0xe9b6c7aa);
    R1(A,B,C,D,p[ 5], 5,0xd62f105d); R1(D,A,B,C,p[10], 9,0x02441453);
    R1(C,D,A,B,p[15],14,0xd8a1e681); R1(B,C,D,A,p[ 4],20,0xe7d3fbc8);
    R1(A,B,C,D,p[ 9], 5,0x21e1cde6); R1(D,A,B,C,p[14], 9,0xc33707d6);
    R1(C,D,A,B,p[ 3],14,0xf4d50d87); R1(B,C,D,A,p[ 8],20,0x455a14ed);
    R1(A,B,C,D,p[13], 5,0xa9e3e905); R1(D,A,B,C,p[ 2], 9,0xfcefa3f8);
    R1(C,D,A,B,p[ 7],14,0x676f02d9); R1(B,C,D,A,p[12],20,0x8d2a4c8a);
    /* Round 2 */
    R2(A,B,C,D,p[ 5], 4,0xfffa3942); R2(D,A,B,C,p[ 8],11,0x8771f681);
    R2(C,D,A,B,p[11],16,0x6d9d6122); R2(B,C,D,A,p[14],23,0xfde5380c);
    R2(A,B,C,D,p[ 1], 4,0xa4beea44); R2(D,A,B,C,p[ 4],11,0x4bdecfa9);
    R2(C,D,A,B,p[ 7],16,0xf6bb4b60); R2(B,C,D,A,p[10],23,0xbebfbc70);
    R2(A,B,C,D,p[13], 4,0x289b7ec6); R2(D,A,B,C,p[ 0],11,0xeaa127fa);
    R2(C,D,A,B,p[ 3],16,0xd4ef3085); R2(B,C,D,A,p[ 6],23,0x04881d05);
    R2(A,B,C,D,p[ 9], 4,0xd9d4d039); R2(D,A,B,C,p[12],11,0xe6db99e5);
    R2(C,D,A,B,p[15],16,0x1fa27cf8); R2(B,C,D,A,p[ 2],23,0xc4ac5665);
    /* Round 3 */
    R3(A,B,C,D,p[ 0], 6,0xf4292244); R3(D,A,B,C,p[ 7],10,0x432aff97);
    R3(C,D,A,B,p[14],15,0xab9423a7); R3(B,C,D,A,p[ 5],21,0xfc93a039);
    R3(A,B,C,D,p[12], 6,0x655b59c3); R3(D,A,B,C,p[ 3],10,0x8f0ccc92);
    R3(C,D,A,B,p[10],15,0xffeff47d); R3(B,C,D,A,p[ 1],21,0x85845dd1);
    R3(A,B,C,D,p[ 8], 6,0x6fa87e4f); R3(D,A,B,C,p[15],10,0xfe2ce6e0);
    R3(C,D,A,B,p[ 6],15,0xa3014314); R3(B,C,D,A,p[13],21,0x4e0811a1);
    R3(A,B,C,D,p[ 4], 6,0xf7537e82); R3(D,A,B,C,p[11],10,0xbd3af235);
    R3(C,D,A,B,p[ 2],15,0x2ad7d2bb); R3(B,C,D,A,p[ 9],21,0xeb86d391);

    MD5_A += A;
    MD5_B += B;
    MD5_C += C;
    MD5_D += D;
}

void CSL_MD5_Update(unsigned char *data, int len)
{
    unsigned char *p = (unsigned char *)MD5_data;
/*
 * The full MD5 procedure allows for encoding strings of up to
 * around 2^64 bits. I will restrict myself to 2^32 so I can just ignore
 * the high word of the bit-count.
 */
    MD5_Nl += len<<3;   /* Counts in BITS not BYTES here */
    while (len != 0)
    {   p[MD5_num++] = *data++;
        len--;
        if (MD5_num == MD5_CBLOCK)
        {   md5_block();
            MD5_num = 0;
        }
    }
}

void CSL_MD5_Final(unsigned char *md)
{
    uint32_t l = MD5_Nl;
    unsigned char *p = (unsigned char *)MD5_data;
    
    p[MD5_num++] = 0x80;
    if (MD5_num >= MD5_CBLOCK-8)
    {   while (MD5_num < MD5_CBLOCK) p[MD5_num++] = 0;
        md5_block();
        MD5_num = 0;
    }
    while (MD5_num < MD5_CBLOCK-8) p[MD5_num++] = 0;
    p[MD5_num++] = (unsigned char)l;
    p[MD5_num++] = (unsigned char)(l>>8);
    p[MD5_num++] = (unsigned char)(l>>16);
    p[MD5_num++] = (unsigned char)(l>>24);
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    p[MD5_num++] = 0;
    md5_block();
    p = md;
    l = MD5_A;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_B;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_C;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    l = MD5_D;
    *p++ = (unsigned char)l;
    *p++ = (unsigned char)(l>>8);
    *p++ = (unsigned char)(l>>16);
    *p++ = (unsigned char)(l>>24);
    CSL_MD5_busy = NO;
}

unsigned char *CSL_MD5(unsigned char *d, int n, unsigned char *md)
{
    if (n < 0) n = strlen((char *)d);
    CSL_MD5_Init();
    CSL_MD5_Update(d, n);
    CSL_MD5_Final(md);
    return md;
}

#ifdef STAND_ALONE_TESTING_OF_MD5_CODE

int main(int argc, char *argv[])
{
    int i;
    unsigned char mm[16];
    CSL_MD5("", 0, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("a", 1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("abc", 3, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("message digest", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("abcdefghijklmnopqrstuvwxyz", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    CSL_MD5("12345678901234567890123456789012345678901234567890123456789012345678901234567890", -1, mm);
    for (i=0; i<16; i++) printf("%.2x", mm[i] & 0xff);
    printf("\n");
    return 0;
}

#endif

/*
 * This is the end of the Eric Young code - what follows is Codemist
 * original code again.
 */


/* end of restart.c */

