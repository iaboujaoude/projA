/*
 *  PassengerQueue.h
 *  Ian Abou-Jaoude
 *  Febuary 14
 *
 *  COMP 15 Proj 1
 *
 *  The header file for PassengerQueue
 *
 */

#ifndef PASSENGER_QUEUE
#define PASSENGER_QUEUE

#include <string>
#include "Passenger.h"
#include <vector>
#include <iostream>
#include <fstream>

class PassengerQueue 
{
    public:
    
        Passenger front();
        void dequeue();
        void enqueue(const Passenger &passenger);
        int size();
        void print(std::ostream &output);

    private: 
    
        std::vector<Passenger> pass_queue;
};

#endif
