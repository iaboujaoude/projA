###
### Makefile for Gerp Project
### Gerp is a file searching program
###
### Author:  Elijah Weston-Capulong, Ian Abou-Jaoude

MAKEFLAGS += -L
CXX = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow -O2
LDFLAGS = -g3

gerp: WordInstance.o stringProcessing.o FSTree.o \
 			WordList.o gerp.o DirNode.o HashTable.o
	${CXX} ${LDFLAGS} -o gerp WordInstance.o stringProcessing.o FSTree.o \
	WordList.o gerp.o DirNode.o HashTable.o

gerp.o: WordInstance.h WordInstance.cpp WordList.cpp WordList.h \
			HashTable.h HashTable.cpp gerp.cpp
	${CXX} $(CXXFLAGS) -o gerp.o gerp.cpp -c

HashTable.o: HashTable.cpp HashTable.h
	${CXX} ${CXXFLAGS} -o HashTable.o HashTable.cpp -c

WordList.o: WordList.cpp WordList.h
	${CXX} ${CXXFLAGS} -o WordList.o WordList.cpp -c

WordInstance.o: WordInstance.cpp WordInstance.h
	${CXX} ${CXXFLAGS} -o WordInstance.o WordInstance.cpp -c

#treeTraversal.o: FSTreeTraversal.o FSTree.o DirNode.o
#	${CXX} ${LDFLAGS} -o treeTraversal FSTreeTraversal.o FSTree.o DirNode.o -c

#
#FSTreeTraversal.o: FSTreeTraversal.cpp FSTree.h DirNode.h
#	${CXX} $(CXXFLAGS) -o FSTreeTraversal.o FSTreeTraversal.cpp -c

stringProcessing.o: stringProcessing.cpp stringProcessing.h
	${CXX} $(CXXFLAGS) -o stringProcessing.o stringProcessing.cpp -c

unit_test: unit_test_driver.o WordInstance.o
	${CXX} unit_test_driver.o WordInstance.o

DirNode.o: DirNode.h
	${CXX} $(CXXFLAGS) -o DirNode.o DirNode.h -c

FSTree.o: FSTree.h
	${CXX} $(CXXFLAGS) -o FSTree.o FSTree.h -c