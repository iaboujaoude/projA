###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Ian Abou-Jaoude

MAKEFLAGS += -L 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o
	${CXX} ${LDFLAGS} RPNCalc.o main.o DatumStack.o Datum.o -o CalcYouLater

DatumStack.o: DatumStack.cpp DatumStack.h Datum.h 
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp

main.o: main.cpp RPNCalc.h DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c main.cpp

RPNCalc.o: RPNCalc.cpp DatumStack.h RPNCalc.h Datum.h
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp


unit_test: unit_test_driver.o RPNCalc.o DatumStack.o Datum.o
	$(CXX) $(CXXFLAGS) $^


provide:
	provide comp15 proj2_calcyoulater DatumStack.h DatumStack.cpp \
	unit_tests.h RPNCalc.h RPNCalc.cpp main.cpp README Makefile \
	final_test.cyl parser_tester.txt


##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^
