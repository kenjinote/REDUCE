#! /bin/bash -v

# main-dmain.sh

# Usage: ./main-dmain.s

# This version used symval+NNN(%rip) everywhere. If this is what is wanted
# I obviously hope tha the compiler that generates mai.s will stick the
# extra annotation in there!

# Let me comment on these edits. Well firstly if all these work out I
# hope that the compiler can be persuaded to generate the version that
# these turn stuff into!

# References to "symval+nnn" turn into "symval+nnn(%rip)" so as to use
# pc relative addressing and make the code relocatable.
# Ditto symfnc, and property list access would need the same if used.
#
# Comments are introduced by "#" not "/" which makes the code treat them
# as comments on both a PC and a Mac
#
# "cmp lnnn" which compares against a local location turns into
# "cmp lnnn(%rip)" to use pc-relative addressing.
#
# "cmp" turns into "cmpq" in a bunch of places where the Mac assembler
# failed to deduce the appropriate width of operand.
#
# ".quad [a+b]" turns into ".quad (a+b)" and friends again for pc/Mac
# compatibility.
#
# lnnnn => Gnnnn which I find more reaable. I do not use Lnnnn because
# symbols starting with L are reserved as "local" bt at least some assemblers.
#
# For every label that I declare .globl and every label that I set I will
# set user both a version with and without a leading underscore. For
# refernces as between assembly code I will use the versions without the
# underscore, but the ones with are so that C code on Cygwin and Macintosh
# can access the names. The intent here is to create code that can assemble
# and be used by any of those platforms. The key problem that arises
# is that this leaves calls to C code from here (and in particular to
# the C library) done via names with leading underscores. So on Linux I
# need to provide stubs of the form
#   int _foo(int x) { return foo(x); }
# for every function called from this assemble-coded part of the kernel.
#


# I want to put data most data that is in main.s into the .data segment.
# the utility fudgedata tries to do that.

# Calling conventions on Linux and Cygwin differ so I MUST start with
# different versions of main... That will mean that the assembly code
# I try to use on Cygwin will tend to expect the Windows API to be used
# for everything. Well this fact should help me in a move towards supporting
# the native Windows version.
# For now at least I will use the same base version for both Linux and
# Macintosh - I may in due course find that I need to split there too.
#
# This script will make win-main.s and linux-main.s (and similarly for dmain)

case `uname -s` in
*Darwin*)
# On the Macintosh I need to use the GNU version of sed.
  SED=gsed
  ;;
*Cygwin* | *CYGWIN*)
  SED=sed
  ;;
*)
  SED=sed
  mc=AMD64_ext
  ;;
esac

gcc fudgedata.c -o fudgedata

action() {

$SED -e 's/symval+[0-9]*/&(%rip)/g' \
     -e 's/symfnc+[0-9]*/&(%rip)/g' \
     -e 's/mov l[0-9]*/&(%rip)/g'   \
     -e 's+^/+#+g'                  \
     -e 's/cmp l[0-9]*/&(%rip)/g'   \
     -e 's/cmp \$/cmpq $/g'         \
     -e 's/\[/(/g'                  \
     -e 's/\]/)/g'                  \
     -e 's/l\([0-9][0-9][0-9][0-9]\)/G\1/g' \
     -e 's/[a-zA-Z_][a-zA-Z_0-9]*:/&\n_&/g' \
     -e 's/ \.globl .*$/&\n@@@&/g'          \
     -e 's/@@@ .globl / .globl _/g'         \
     -e 's/call [a-z]/call _&/g; s/_call /_/g'   \
     -e 's/\.quad \(.*\)$\n#/.QUAD \1\n#/g'      \
      < ../psl/dist/kernel/$1/main.s > mainx.s

./fudgedata mainx.s $2.s

# dmain.s is simpler.

$SED -e 's/\[/(/g'                  \
     -e 's/\]/)/g'                  \
     -e 's/l\([0-9][0-9][0-9][0-9]\)/G\1/g' \
     -e 's/[a-zA-Z_][a-zA-Z_0-9]*:/&\n_&/g' \
     -e 's/ \.globl .*$/&\n@@@&/g'          \
     -e 's/@@@ .globl / .globl _/g'         \
     -e 's/\.comm[ ]*\(.*\)$/.comm _\1/'    \
     -e 's/.quad stack/.quad _stack/g'      \
     -e 's/.quad argumentblock/.quad _argumentblock/g' \
     -e 's/.quad tokenbuffer/.quad _tokenbuffer/g'     \
     -e 's/.quad bndstk/.quad _bndstk/g'               \
     -e 's/.quad catchstack/.quad _catchstack/g'       \
     -e 's/.quad hashtable/.quad _hashtable/g'         \
     -e 's/.quad onewordbuffer/.quad _onewordbuffer/g' \
     -e 's/.quad saveargc/.quad _saveargc/g'           \
     -e 's/.quad saveargv/.quad _saveargv/g'           \
     -e 's/.quad datebuffer/.quad _datebuffer/g'       \
      < ../psl/dist/kernel/$1/dmain.s > $3.s

}

action mingw-w64 win-main win-dmain
action AMD64_ext linux-main linux-dmain

# end of file
