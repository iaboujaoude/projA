/*
 *  MetroSim.cpp
 *  Ian Abou-Jaoude
 *  Feb 15
 *
 *  CS 15 Project 1
 *
 *  Implementation of the MetroSim
 *
 */

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>

using namespace std;


/*
 * name:      MetroSim
 * purpose:   Initializes an instance for the MetroSim
 * arguments: none
 * returns:   none
 * effects:   fills the queues for all the stations and the names of all the
 *            stations
 */
MetroSim::MetroSim(istream &instream) {
    string tempLine;
    numStations = 0;
    passengerID = 1;
    currStations = 0;
    

    //Fill name of stations in a file and initialize all queues needed
    while (getline(instream, tempLine)) {
        PassengerQueue tempQueueStations;
        PassengerQueue tempQueueTrains;
        trains_queues.push_back(tempQueueTrains);
        stations_queues.push_back(tempQueueStations);

        stations_names.push_back(tempLine);
    }

    numStations = stations_names.size();
}


/*
 * name:      insertPassenger
 * purpose:   Insert a passenger at a station
 * arguments: arrival and departure station numbers
 * returns:   none
 * effects:   Enters a new passenger into the input station
 */
void MetroSim::insertPassenger(int arr, int dep) {
    Passenger passengerIn(passengerID, arr, dep);
    stations_queues.at(arr).enqueue(passengerIn);

    passengerID++;
}

/*
 * name:      moveMetro
 * purpose:   Moves the metro one down to gain or lose passenger
 * arguments: none
 * returns:   none
 * effects:   Adds all passengers at the station and removes train passengers
 */
void MetroSim::moveMetro(ofstream &outstream) {
    int stationQueueLength = stations_queues.at(currStations).size();

    // Adds passengers to train from station
    for (int i = stationQueueLength; i > 0; i--) {
        Passenger passengerIn = stations_queues.at(currStations).front();
        stations_queues.at(currStations).dequeue();
        trains_queues.at(passengerIn.to).enqueue(passengerIn);
    }

    currStations++;
    currStations = currStations % numStations;

    // Removes passengers getting off train to their destination
    while (trains_queues.at(currStations).size() != 0) {
        Passenger frontPass = trains_queues.at(currStations).front();
        outstream << "Passenger " << frontPass.id;
        outstream << " left train at station ";
        outstream << stations_names.at(currStations) << endl;
        trains_queues.at(currStations).dequeue();
    }
}

/*
 * name:      print
 * purpose:   Prints all metro informations and where the rain is
 * arguments: output stream
 * returns:   none
 * effects:   none
 */
void MetroSim::print() {
    cout << "Passengers on the train: {";

    unsigned int size_loop = trains_queues.size();

    //Print every person in train
    for (unsigned int i = 0; i < size_loop; i++) {
        trains_queues.at(i).print(cout);
    }
    cout << "}" << endl;

    size_loop = numStations;

    for (unsigned int i = 0; i < size_loop; i++) {
        if (i != currStations) {
            cout << "       " << "[";
        }
        else {
            cout << "TRAIN: [";
        }
        cout << i << "] " << stations_names.at(i) << " {";
        stations_queues.at(i).print(cout);
        cout << "}" << endl;
    }
}

/*
 * name:      commandLoop
 * purpose:   The public command loop to run the overall class by the user
 * arguments: the outputfile that we will print to
 * returns:   none
 * effects:   none
 */
void MetroSim::commandLoop(ofstream &outstream, istream &instream) {
    char userIn_1, userIn_2;
    userIn_2 = ' ';
    userIn_1 = ' ';
    
    do {
        print();
        cout << "Command? ";
        instream >> userIn_1;

        if (userIn_1 == 'm') {
            instream >> userIn_2;
            if (userIn_2 == 'm') {
                moveMetro(outstream);
            }
        }
        else {
            int dep, arr;
            instream >> arr >> dep;
            insertPassenger(arr, dep);
        }
    } while (userIn_2 != 'f' and not instream.eof());

    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}