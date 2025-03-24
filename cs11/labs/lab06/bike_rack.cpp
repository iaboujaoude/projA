/*
 * CS 11: Lab 06
 * bike_rack.cpp
 *
 * Purpose: To practice reading in data from a file, interacting with
 *          command line arguments, and initializing 2D arrays of structs
 *
 * Written by: Sam Berman (sberma04), Fall 2021
 *
 * Modified by: 
 *
 */

#include <iostream>
#include <fstream>    // Needed to use ifstream

using namespace std;

// Global constants indicating the size of the 2D array
const int NUM_ROWS = 4;
const int NUM_COLS = 5;

struct Bike
{
    bool   no_bike_here;
    string color;
    int    price;
    string bike_type;
    string owner;
};

// Function declarations
Bike read_one_bike(ifstream &infile);
void print_one_bike(Bike bike_to_print);

int main(int argc, char *argv[])
{
    // (void) argc and (void) argv are here in order to silence the
    // compiler from giving you a warning with "unused variables" until
    // you actually use them in a later part. Feel free to delete these two
    // lines of code below if you get to the part where you're using argc and
    // argv.
    (void) argc;
    (void) argv;
    
    
    //    ifstream small.testdata;
    
    
    string filename = "small.testdata";

    // ================================================================
    //                     Opening The File 
    // 
    // The following code creates a variable of type ifstream ("if" 
    // stands for "input file") used for reading input files, "opens" it
    // for reading, then makes sure there were no errors. The Lab 06
    // spec has a detailed explanation of each of these parts.
    //
    // There's no need to change any of this code.
    //

    ifstream input_file;

    input_file.open(filename);

    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: "
             << filename << endl;
        return 1; // non-zero return from main means error
    }

    // ================================================================


    //
    // TODO: Put your solutions to Programming Problems 1-3 here
    //
    
    int num_bikes;
    input_file >> num_bikes;
    // Bike test_bike = read_one_bike(input_file);
    
    
    Bike rack[NUM_ROWS][NUM_COLS];
    
    for (int i = 0; i < NUM_ROWS; i++){
        for (int n = 0; n < NUM_COLS; n++){
            rack[i][n]no_bike_here = true;
        }
    }
    
    for (int i = 0; i < NUM_ROWS; i++){
        for (int n = 0; n < NUM_COLS; n++){
            rack[i][n] = read_one_bike(input_file);
        }
    }
    
    for (int i = 0; i < NUM_ROWS; i++){
        for (int n = 0; n < NUM_COLS; n++){
            cout << rack[i][n];
        }
    }
    

    // ================================================================
    
    // When you are done with a file, you "close" it, which tells C++ 
    // do any cleaning up that is necessary.
    input_file.close();

    return 0;
}

Bike read_one_bike(ifstream &infile)
{
    Bike return_bike;
    
    infile >> return_bike.color;
    infile >> return_bike.price;
    infile >> return_bike.bike_type;
    infile >> return_bike.owner;
    
    return_bike.no_bike_here = false;
    
    return return_bike;
    
    
}

void print_one_bike(Bike bike_to_print)
{
    cout << "Printing Bike's attributes:" << endl;
    cout << "Color: " << bike_to_print.color << endl;
    cout << "Price: $" << bike_to_print.price << endl;
    cout << "Bike type: " << bike_to_print.bike_type << endl;
    cout << "Owner's name: " << bike_to_print.owner << endl;

    cout << endl;         // for visual clarity when printing
}
