#! /bin/bash -v

# This tries to make a PSL compiler that will generate FASL files, ie
# it should support the idiom
#   (faslout 'foo) (dskin "file") (faslend)
# and create a file called "foo.b".

make psl OPT="-O0 -g"

script AMDfasl.log <<XXX
./vsl xxxfasl.lsp -Dmachine=AMD64_ext -o AMDfasl.img
exit $?
XXX


