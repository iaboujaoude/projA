/*
 *  deleted_test_code(main).cpp
 *  Ian Abou-Jaoude
 *  Feb 22
 *
 *  CS 15 Project 1
 *
 *  Testing the implementation of individuakl functions for MetroSim
 *  
 *  Note: The code that has been commented out will not run unless all
 *  private memebers of MetroSim become public
 */ 


#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "Passenger.h"


using namespace std;

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);


//         //TESTING FUNCTIONS:
// void testing_constructor(istream &instream);
// void testing_insertPassenger(istream &instream);
// void testing_moveMetro(istream &instream, ofstream &outstream);
// void testing_print(istream &instream, ofstream &outstream);



int main(int argc, char *argv[])
{
        // First round of testing was to check I could fail and succeed in
        // opening files and print appropriately, also to out errors if
        // the wrong number of arguments

        if ((argc != 3) and (argc != 4)) {
                cerr << "Usage: ./MetroSim stationsFile outputFile "
                     << "[commandsFile]" << endl;
                return 1;
        }

//         // end of test 1

        ifstream instream;
        ofstream outstream;
        ifstream instream_2;

        open_or_fail(instream, argv[1]);
        open_or_fail(outstream, argv[2]);

//         //end of test 2  

//         //testing_constructor(instream);
        
//         // cout << endl;

//         // end of test 3

//         //testing_insertPassenger(instream);

//         // end of test 4

//         //testing_moveMetro(instream, outstream);

//         // end of test 5

//         testing_print(instream, outstream);

//         // end of test 6

        
        return 0;
}


/*
 * name:      open_or_fail
 * purpose:   Tries and makes sure you can open a file
 * arguments: the stream and name of the files
 * returns:   none
 * effects:   prints error message in case of failure
 */

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string)
{
        stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Unable to open: " << file_string << endl;
                exit(EXIT_FAILURE);
        }
}

// /*
//  * name:      testing_constructor
//  * purpose:   test constructor, make sure stations were put in correctly
//  * arguments: istream of stations
//  * returns:   none
//  * effects:   prints all station names
//  */
 
// void testing_constructor(istream &instream) {
//         MetroSim simulation(instream);
//         cout << simulation.numStations << endl;
        
//         for (unsigned int i = 0; i < simulation.numStations; i++) {
//                 cout << simulation.stations_names.at(i);
//                 cout << ", ";
//         }

//         cout << endl;

//         cout << simulation.trains_queues.size();

//         cout << endl;
// }

// /*
//  * name:      testing_insertPassenger
//  * purpose:   test insertPassenger, make sure you can add a passenger
//  * arguments: istream of stations
//  * returns:   none
//  * effects:   prints the list queue for the station where we added
//  */
 
// void testing_insertPassenger(istream &instream) {
//         MetroSim simulation(instream);
        
//         simulation.insertPassenger(0, 8);

//         cout << simulation.trains_queues.size();

//         cout << endl;

//         simulation.stations_queues.at(0).print(cout);
//         simulation.insertPassenger(0, 5);

//         simulation.stations_queues.at(0).print(cout);

//         cout << endl;
// }

// /*
//  * name:      testing_moveMetro
//  * purpose:   test moveMetro, add passengers and use metroMove to see if they
//  *            get off
//  * arguments: istream of stations
//  * returns:   none
//  * effects:   prints the queue of the station before and after they leave
//  */
 
// void testing_moveMetro(istream &instream, ofstream &outstream) {
//         MetroSim simulation(instream);
        
//         simulation.insertPassenger(0, 8);

//         cout << endl;

//         simulation.stations_queues.at(0).print(cout);
//         simulation.insertPassenger(0, 5);

//         simulation.stations_queues.at(0).print(cout);

//         cout << endl;

//         simulation.moveMetro(outstream);
//         simulation.moveMetro(outstream);

//         simulation.stations_queues.at(0).print(cout);
        
//         cout << endl;
// }



// void testing_print(istream &instream, ofstream &outstream);
// /*
//  * name:      testing_moveMetro
//  * purpose:   test moveMetro, add passengers and use metroMove to see if they
//  *            get off
//  * arguments: istream of stations
//  * returns:   none
//  * effects:   prints the queue of the station before and after they leave
//  */
 
// void testing_print(istream &instream, ofstream &outstream) {
//         MetroSim simulation(instream);
        
//         simulation.insertPassenger(0, 8);
        
//         simulation.print();

//         cout << endl;

//         simulation.moveMetro(outstream);

//         simulation.print();
        
//         cout << endl;
// }

