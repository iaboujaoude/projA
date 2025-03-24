# Makefile for Proj1: A Metro Simulator
# Ian Abou-Jaoude
# 
# This Makefile will build unit_test for the passenger and queue classes

CXX=clang++
CXXFLAGS=-Wall -Wextra -Wpedantic -Wshadow
LDFLAGS=-g3

unit_test: unit_test_driver.o PassengerQueue.o
	${CXX} ${LDFLAGS} unit_test_driver.o PassengerQueue.o -o unit_test

PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h
	${CXX} ${CXXFLAGS} -o PassengerQueue.o PassengerQueue.cpp -c

Passenger.o: Passenger.h Passenger.cpp
	${CXX} ${CXXFLAGS} -o Passenger.o Passenger.cpp -c
	
clean: 
	rm *.o a.out *~ *#