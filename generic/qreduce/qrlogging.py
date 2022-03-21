# ----------------------------------------------------------------------
# $Id: qrlogging.py 2640 2014-08-12 02:04:01Z thomas-sturm $
# ----------------------------------------------------------------------
# Copyright (c) 2010 T. Sturm, C. Zengler
# ----------------------------------------------------------------------
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the relevant
#      copyright notice, this list of conditions and the following
#      disclaimer.
#    * Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
import logging

ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)

formatter = logging.Formatter("%(name)s-%(levelname)s: %(module)s/%(funcName)s: %(message)s")
ch.setFormatter(formatter)

signalLogger = logging.getLogger("sig")
signalLogger.addHandler(ch)
signalLogger.setLevel(logging.DEBUG)

fontLogger = logging.getLogger("fnt")
fontLogger.addHandler(ch)
fontLogger.setLevel(logging.WARNING)

traceLogger = logging.getLogger("trc")
traceLogger.addHandler(ch)
traceLogger.setLevel(logging.DEBUG)
