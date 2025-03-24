/*
 *  deleted_test_code(main).cpp
 *  Ian Abou-Jaoude
 *  Feb 22
 *
 *  CS 15 Project 1
 *
 *  Testing the implementation of individuakl functions for MetroSim
 *
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

/*
        TESTING FUNCTIONS:
void test



*/

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

        ifstream instream;
        ofstream outstream;
        ifstream instream_2;

        open_or_fail(instream, argv[1]);
        open_or_fail(outstream, argv[2]);

        MetroSim simulation(instream);


        if (argc == 3) {
                simulation.commandLoop(outstream, cin);
                outstream.close();
                instream.close();
        }

        else {
                open_or_fail(instream_2, argv[3]);
                simulation.commandLoop(outstream, instream_2);

                outstream.close();
                instream.close();
                instream_2.close();
        }
        
        return 0;
}

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string)
{
        stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Unable to open: " << file_string << endl;
                exit(EXIT_FAILURE);
        }
}