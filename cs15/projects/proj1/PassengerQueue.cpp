/*
 *  PassengerQueue.cpp
 *  Ian Abou-Jaoude
 *  Febuary 14
 *
 *  COMP 15 Proj 1
 *
 *  Implementation of the PassenngerQueue class
 *
 */

#include "PassengerQueue.h"
#include "Passenger.h"
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;


/*
 * name:      front
 * purpose:   Initializes an instance for the PassengerQueue
 * arguments: none
 * returns:   passenger at the front of the list
 * effects:   none
 */
 
 Passenger PassengerQueue::front() {
    return pass_queue.front();
}

/*
 * name:      dequeue
 * purpose:   Removes first element of list
 * arguments: none
 * returns:   none
 * effects:   reduces the size of queue
 */
 
 void PassengerQueue::dequeue() {
    pass_queue.erase(pass_queue.begin());
}

/*
 * name:      enqueue
 * purpose:   Adds an element at the end of the list
 * arguments: none
 * returns:   none
 * effects:   increases size by one
 */
 
 void PassengerQueue::enqueue(const Passenger &passenger) {
    pass_queue.push_back(passenger);
}

/*
 * name:      size
 * purpose:   Return the size of the list
 * arguments: none
 * returns:   none
 * effects:   none
 */
 
 int PassengerQueue::size() {
    return pass_queue.size();
}

/*
 * name:      print
 * purpose:   print each element of the list in the output stream
 * arguments: the outstream
 * returns:   none
 * effects:   none
 */
 
 void PassengerQueue::print(ostream &output) {
    Passenger temp;
    int size = pass_queue.size();

    for (int i = 0; i < size; i++) {
        temp = pass_queue.at(i);
        temp.print(output);
    }
}

