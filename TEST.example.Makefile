##===- TEST.example.Makefile -------------------------------*- Makefile -*-===##
#
# Example to show a custom test.  This test just prints the size of the bytecode
# file for each program.
#
##===----------------------------------------------------------------------===##

TESTNAME = $*

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.simple
	@echo "========================================="
	@echo "Running '$(TEST)' test on '$(TESTNAME)' program"
