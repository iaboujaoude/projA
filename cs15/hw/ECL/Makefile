###########################################################################
##                    Makefile for HW2 (IsolateData)                   ##
###########################################################################

CXX      = clang++
CXXFLAGS = -c -g3 -std=c++11 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3

##unit_test: unit_test_driver.o IsolateData.o 
##	${CXX} ${LDFLAGS} unit_test_driver.o IsolateData.o

IsolateData.o: IsolateData.cpp IsolateData.h
	${CXX} ${CXXFLAGS} IsolateData.cpp

main.o: main.cpp IsolateData.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	@rm -rf *.o *~