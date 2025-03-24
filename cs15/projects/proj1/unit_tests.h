/*
 *  unit_tests.h
 *  Ian Abou-Jaoude
 *  Feb 15
 *
 *  CS 15 Project 1
 *
 *  Testing the implementation of Passengers and PassengerQueue using unittest
 *
 */

#include "Passenger.h"
#include "PassengerQueue.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

// Tests the default constructor to see if it initialized wihtout errors 
// Checks to make sure default constructor is empty
// Check to see if print statements for passenger work
void Passenger_Works() {
      
    Passenger passenger_test_empty;
    Passenger passenger_test_full(1, 3, 4);
    
    passenger_test_full.print(cout);
    passenger_test_empty.print(cout);
}

// Make sure that queues are initialized correctly without error and are 
// empty or of size 0
void PassengerQueue_Initialization_Works() {
    PassengerQueue queue_test;
    assert(queue_test.size() == 0);
}

// Test to see that front works correctly
void PassengerQueue_Front_Works() {
    PassengerQueue queue_test;

    Passenger pass_front;

    Passenger passenger_test_full1(1, 3, 4);
    Passenger passenger_test_full2(2, 4, 5);
    Passenger passenger_test_full3(3, 6, 3);

    queue_test.enqueue(passenger_test_full1);
    queue_test.enqueue(passenger_test_full2);
    queue_test.enqueue(passenger_test_full3);
    
    pass_front = queue_test.front();

    pass_front.print(cout);
}


// Test the enqueue function to make sure it works correctly
// also tests print and size implicitly
void PassengerQueue_Enqueue_Works() {
    PassengerQueue queue_test;

    Passenger passenger_test_full1(1, 3, 4);
    Passenger passenger_test_full2(2, 4, 5);
    Passenger passenger_test_full3(3, 6, 3);

    queue_test.enqueue(passenger_test_full1);
    queue_test.enqueue(passenger_test_full2);
    queue_test.enqueue(passenger_test_full3);
    
    assert(queue_test.size() == 3);  
    queue_test.print(cout);
}


// Test the dequeue function to make sure it works correctly by filling and 
// then removing, also tests print and size implicitly
void PassengerQueue_Dequeue_Works() {
    PassengerQueue queue_test;

    Passenger passenger_test_full1(1, 3, 4);
    Passenger passenger_test_full2(2, 4, 5);
    Passenger passenger_test_full3(3, 6, 3);

    queue_test.enqueue(passenger_test_full1);
    queue_test.enqueue(passenger_test_full2);
    queue_test.enqueue(passenger_test_full3);

    cout << "after filling: ";
    queue_test.print(cout);
    cout << "\n";
    assert(queue_test.size() == 3);  
    
    queue_test.dequeue();
    queue_test.dequeue();

    assert(queue_test.size() == 1);  
    
    cout << "after removing first 2: ";
    queue_test.print(cout);
    cout << "\n";
}