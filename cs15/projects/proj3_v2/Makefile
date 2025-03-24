###
### Makefile for Gerp Project
### Gerp is a file searching program
###
### Author:  Elijah Weston-Capulong, Ian Abou-Jaoude

MAKEFLAGS += -L
CXX = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS = -g3

# gerp: WordInstance.o stringProcessing.o FSTree.o \
# 			WordList.o gerp.o
# 	${CXX} ${LDFLAGS} -o gerp WordInstance.o \
# 				stringProcessing.o FSTree.o WordList.o gerp.o

WordList.o: WordList.cpp WordList.h
	${CXX} ${CXXFLAGS} -o WordList.o WordList.cpp -c

WordInstance.o: WordInstance.cpp WordInstance.h
	${CXX} ${CXXFLAGS} -o WordInstance.o WordInstance.cpp -c

#gerp.o: gerp.cpp WordInstance.h WordList.h stringProcessing.h
#	${CXX} $(CXXFLAGS) -o gerp.o gerp.cpp -c
# 
#treeTraversal.o: FSTreeTraversal.o FSTree.o DirNode.o
#	${CXX} ${LDFLAGS} -o treeTraversal FSTreeTraversal.o FSTree.o DirNode.o -c

#
#FSTreeTraversal.o: FSTreeTraversal.cpp FSTree.h DirNode.h
#	${CXX} $(CXXFLAGS) -o FSTreeTraversal.o FSTreeTraversal.cpp -c

stringProcessing.o: stringProcessing.cpp stringProcessing.h
	${CXX} $(CXXFLAGS) -o stringProcessing.o stringProcessing.cpp -c

unit_test: unit_test_driver.o WordInstance.o
	${CXX} unit_test_driver.o WordInstance.o

#DirNode.o: DirNode.h
#	${CXX} $(CXXFLAGS) -o DirNode.o DirNode.h -c