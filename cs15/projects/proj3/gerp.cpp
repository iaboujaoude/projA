/*
 *  gerp.cpp
 *  Elijah Weston-Capulong, Ian Abou-Jaoude
 *  4/22/2022
 *
 *  COMP 15 Project 3 MetroSim
 *
 *  This file starts and works on gerp to create all the data structures
 *  and allow for inquiries
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "FSTree.h"
#include "stringProcessing.h"
#include "WordInstance.h"
#include "WordList.h"

using namespace std;

void run_command_loop(ostream &outstream, FSTree fileTree);
void read_file(ifstream &instream);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cerr << "Usage: ./gerp inputDirectory outputFile" << endl;
        exit(EXIT_FAILURE);
    }

    string filename = argv[1];
    ofstream outstream = argv[2];
    FSTree fileTree(filename);

    run_command_loop(outstream, FSTree);
    
}


void run_command_loop(ostream &outstream, FSTree fileTree) {
    string userIn_1;
    userIn_1 = "";
    
    do {
        cin >> userIn_1;
    } while (userIn_2 != "f");
}

void read_file(string file_name) {
    ifstream instream;
    instream.open (file_name);
    
    if (instream.is_open()) {
        string line;
        while (getline(file, line)) {
            
    file.close();
}