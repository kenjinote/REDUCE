#!/bin/sh

JOBNAME=$1

MAXRUNS=6
SUCCESS=0
RUNS=0
NEED_BIBTEX=0

# Remove .ind file, could be left over from tex4ht run
rm -f ${JOBNAME}.ind

# Run latex until it no longer complains about cross references
until [ ${SUCCESS} = 1 ] ; do
   rm -f ${JOBNAME}.log
   pdflatex ${JOBNAME}
   grep -q "^No file ${JOBNAME}\.bbl" ${JOBNAME}.log && NEED_BIBTEX=1
   if [ ${NEED_BIBTEX} = 1 ] ; then
      bibtex ${JOBNAME}
      rm -f ${JOBNAME}.log
      pdflatex ${JOBNAME}
   fi
   fgrep -q "Rerun to get cross-references right." ${JOBNAME}.log || SUCCESS=1
   RUNS=`expr ${RUNS} + 1`
   if [ ${RUNS} -gt ${MAXRUNS} ] ; then
      echo >&2 Maximum number of runs reached. Stop.
# The code here USED to go "exit 1" but that stopped higher level scripts.
# I will now merely pretend that I had achieved convergence. The result may
# be that some cross-references end up incorrect in the generated file.
#     exit 1
      SUCCESS=1
   fi
#   checksum ${JOBNAME}.aux
done

# finally, run makeindex and latex once
if test -f ${JOBNAME}.idx ; then
  makeindex ${JOBNAME}
  pdflatex ${JOBNAME}
fi

exit 0

