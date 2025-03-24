/*
 *  MetroSim.cpp
 *  Ian Abou-Jaoude
 *  Feb 15
 *
 *  CS 15 Project 1
 *
 *  Header file of the MetroSim
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <vector>
using namespace std;

class MetroSim
{
    public:
        MetroSim(istream &instream);
        void commandLoop(ofstream &outstream, istream &instream);

    private:

        void insertPassenger(int arr, int dep);
        void moveMetro(ofstream &outstream);
        void print();
        
        vector<PassengerQueue> trains_queues;
        vector<PassengerQueue> stations_queues;
        vector<string> stations_names;

        unsigned int numStations;
        unsigned int currStations;
        int passengerID;

        ofstream output;
        

};

#endif
