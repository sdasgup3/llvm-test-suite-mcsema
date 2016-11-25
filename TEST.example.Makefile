##===- TEST.example.Makefile -------------------------------*- Makefile -*-===##
#
# Example to show a custom test.  This test just prints the size of the bytecode
# file for each program.
#
##===----------------------------------------------------------------------===##

TESTNAME = $*
DIFFOUTPUT=Output/${TESTNAME}.simple.mcsema/${TESTNAME}.diff-mcsema
TESTOUTPUT=Output/${TESTNAME}.simple.mcsema/${TESTNAME}.out-mcsema
GOODOUTPUT=Output/${TESTNAME}.out-simple
BIN=Output/${TESTNAME}.simple.mcsema/${TESTNAME}.simple.new.lifted
SCRIPT=/home/sdasgup3/Github/binary-decompilation/test/utils/diffOutput.pl

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.simple
	@$(SCRIPT) -case $(TESTNAME) -output $(TESTOUTPUT) -bin $(BIN) -stdin_filename $(STDIN_FILENAME) -options $(RUN_OPTIONS) -golden $(GOODOUTPUT) -diff $(DIFFOUTPUT) -execsafely $(RUNSAFELY) -fcmp $(FPCMP)  $(TOLERANCEOPT)
