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
#include "HashTable.h"
#include <sstream>

using namespace std;

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);
void run_command_loop(ostream &outstream, HashTable *theHash);
void makePath(DirNode *node, string initialDirectory, vector<string>& paths);
void makeHash(vector<string>& paths, HashTable *theHash, vector<string>& lines);
string get_lowercase(string word);
bool checkFirstInstance(vector<string>& vector_line, int index);

// When compiling your implementation of gerp, you should compile with
// the flag -O2 (That’s a captial letter ’O’, not the numeral zero). This will
// optimize your program for the system that it is compiling on, which will
// result in an implementation with a faster runtime. This will help during the
// testing phase because you will receive your results faster.

// COMPILE:
/*          
g++ -o gerp -Wall -Wextra -Werror WordList.h WordList.cpp WordInstance.h WordInstance.cpp HashTableTest.cpp HashTable.cpp HashTable.h FSTree.h DirNode.h FSTree.cpp DirNode.cpp gerp.cpp
*/


int main(int argc, char *argv[])
{
    if (argc != 3) {
        cerr << "Usage: ./gerp inputDirectory outputFile" << endl;
        exit(EXIT_FAILURE);
    }


    ofstream outstream;
    open_or_fail(outstream, argv[2]);

    //--------------TESTING--------------------








    // cout << "\n\n\nnow testing first instance: function\n\n\n";

    // vector<string> vector_test;

    // string string_line = "you** -You$ you cant you hello whenever You yOu cant test you";

    // string string_line_copy = string_line;
    
    // istringstream ss(string_line_copy);
    // vector<string> vector_line;
    
    // string temp;

    // vector<bool> instances;

    // //Iterate line
    // if (string_line != "") {
    //     while (ss >> temp){
    //         vector_test.push_back(stripNonAlphaNum(temp));
    //         cout << "temp stripped: " << stripNonAlphaNum(temp) << endl;
    //     }
    // }

    // for (unsigned int i = 0; i < vector_test.size(); i++) {
    //     instances.push_back(checkFirstInstance(vector_test, i));
    // }

    // for (unsigned int i = 0; i < instances.size(); i++) {
    //     cout << "first boolean at word " << i << " is: " << instances.at(i) << endl;
    // }
    










    

    vector<string> paths;
    vector<string> lines;

    //Create and print new file paths
    string directory = argv[1];
    FSTree tree(directory);
    makePath(tree.getRoot(), directory, paths);
    
    HashTable *theHash = new HashTable;



    makeHash(paths, theHash, lines);

    

    //theHash->print_at_caseInSen("you", outstream, lines, paths);
    // //theHash->print_at_caseInSen("cart", outstream, lines, paths);

    // cout << endl << "------FINDING YOU SLOT: --------" << endl;

    // theHash->find_you();

    // //cout << "here\n";

    // // int index = hash<string>{}("you") % currentTableSize;

    // cout << "num datums in you (YOU YOU:): " << theHash->something_you().num_instances() << endl;

    // // for (int i = 0; i < theHash[29116].element_at("you").li(); i++) {
    // //     if (theHash[29116].bucket_vector.at(i).return_name() == "you") {
    // //         cout << "num datums in you: " << theHash[29116].bucket_vector.at(i).num_instances() << endl;
    // //     }
    // // }
    

    // //cout << "HELLO HERE\n";

    // //run_command_loop(outstream, theHash);
    
    // delete theHash;
}


void run_command_loop(ostream &outstream, HashTable *theHash, 
                      vector<string>& lines, vector<string>& paths) {
    
    string word, command;
    command = "";

    while ((command != "@quit") or (command == "@q")) {
        cout << "Query? ";
        
        command = "";
        word = ""; 

        cin >> command;

        if (word[0] == '@') {
            if (word == "@i" or word == "@insensitive") {
                cin >> word;
                theHash->print_at_caseInSen(word, outstream, lines, paths);
            }
        }
        else if (command != "") {
            theHash->print_at_caseSen(word, outstream, lines, paths);
        }
    }
}

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string){
    stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Could not build index, exiting." << endl;
                exit(EXIT_FAILURE);
        }
}

/* make path
 *    Purpose: create a string containing the pathway for each 
 *             file in a given directory
 * Parameters: A node serving as the root of an FSTree, a string 
 *             with the initial file path, and a vector in which 
 *             to store the new path
 *    Returns: None
 *    Effects: None
 */
void makePath(DirNode *node, string initialDirectory, vector<string>& paths) {
    //If the current directory has a subdirectory, add its name 
    //to the file path and continue to traverse the tree
    if (node->hasSubDir()) {

        for (int i = 0; i < node->numSubDirs(); i++) {
            makePath(node->getSubDir(i), 
                        initialDirectory + "/" + 
                        node->getSubDir(i)->getName(), paths);
        }

    }

    //Add the files' names to the file path and add that string to the vector
    if (node->hasFiles()) {
        for (int i = 0; i < node->numFiles(); i++) {
            string newFullPath = initialDirectory + "/" + node->getFile(i);
            paths.push_back(newFullPath);
        }
    }
}

void makeHash(vector<string>& paths, HashTable *theHash, vector<string>& lines) {
    int lineIndex = 0;

    float perc = 0;
    float percChange = 1;

    int you_count = 0;

    cout << "paths size is: " << paths.size() << endl;

    for (unsigned int i = 0; i < paths.size(); i++) {
        ifstream instream;
        open_or_fail(instream, paths.at(i));

        perc = ((float)i) / ((float)paths.size());
        if ((perc) >= ((0.25) * percChange)) {
            cout << "we are: " << (perc*100) << "% the way there..." << endl;
            percChange = percChange + 1;
        }

        int lineNum = 1;

        while (not instream.eof()) {

            string string_line;
            getline(instream, string_line);

            string string_line_copy = string_line;
            
            istringstream ss(string_line_copy);
            vector<string> vector_line;
            
            string temp;

            //Iterate line
            if (string_line != "") {
                while (ss >> temp) {

                    vector_line.push_back(stripNonAlphaNum(temp));
                }

            }

            

            lines.push_back(string_line);

                for (unsigned int n = 0; n < vector_line.size(); n++) {
                    Datum dat_new = {static_cast<int>(i), lineNum, lineIndex, checkFirstInstance(vector_line, n)};

                    if (get_lowercase(vector_line[n]) == "you") {
                        you_count++;
                    }
                
                    theHash->insert(vector_line[n], dat_new);
                }
                
            lineIndex++;
            lineNum++;

        }
    }

    cout << "YOU COUNT IS: " << you_count << endl;
}

bool checkFirstInstance(vector<string>& vector_line, int index) {
    if (index == 0) {
        return true;
    }
    
    for (int i = index - 1; i >= 0; i--) {

        if (get_lowercase(vector_line[i]) == get_lowercase(vector_line[index])) {
            //cout << "comparing: " << get_lowercase(vector_line[i]) << " vs. " << get_lowercase(vector_line[index]) << endl;
            return false;
        }
    }

    return true;
}

string get_lowercase(string word) {
    string to_return = "";
    
    for (unsigned int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);

        to_return = to_return + c;
    }

    return to_return;
}

// void makeHash(vector<string>& paths, HashTable *theHash, vector<string>& lines) {
//     int lineIndex = 0;

//     float perc = 0;
//     float percChange = 1;

//     for (unsigned int i = 0; i < paths.size(); i++) {
//         ifstream instream;
//         open_or_fail(instream, paths.at(i));

//         perc = ((float)i) / ((float)paths.size());
//         if ((perc) >= ((0.25) * percChange)) {
//             cout << "we are: " << (perc*100) << "% the way there..." << endl;
//             percChange = percChange + 1;
//         }

//         int lineNum = 1;

//         while (not instream.eof()) {
//             string string_line;
//             getline(instream, string_line);

//             string string_line_copy = string_line;
            
//             istringstream ss(string_line_copy);
//             vector<string> vector_line;
            
//             string temp;

//             if (not (string_line == "")) {
//                 //Iterate line
//                 while (ss >> temp){
//                     if (not (stripNonAlphaNum(temp) == "")) {
                        
//                         vector_line.push_back(stripNonAlphaNum(temp));
//                     }
//                 }

//                 lines.push_back(string_line);

//                 for (unsigned int n = 0; n < vector_line.size(); n++) {
//                     Datum dat_new = {static_cast<int>(i), lineNum, lineIndex, checkFirstInstance(vector_line, i)};
                
//                     theHash->insert(vector_line[n], dat_new);
//                 }

//                 lineIndex++;
//                 lineNum++;
//             }
//         }
//     }
// }