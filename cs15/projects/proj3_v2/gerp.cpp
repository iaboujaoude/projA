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
void makeHash(vector<string>& paths, HashTable *theHash);
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

    

    vector<string> paths;

    //Create and print new file paths
    string directory = argv[1];
    FSTree tree(directory);
    makePath(tree.getRoot(), directory, paths);
    
    HashTable *theHash = new HashTable;

    string filename = argv[1];
    FSTree fileTree(filename);
    makePath(tree.getRoot(), directory, paths);

    makeHash(paths, theHash);

    run_command_loop(outstream, theHash);
    
    delete theHash;
}


void run_command_loop(ostream &outstream, HashTable *theHash) {
    string userIn_1 = "";
    string userIn_2 = "";
    (void)outstream;
    (void)theHash;
    do {
        cin >> userIn_1;
    } while (userIn_2 != "f");
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

void makeHash(vector<string>& paths, HashTable *theHash) {
    for (unsigned int i = 0; i < paths.size(); i++) {
        ifstream instream;
        open_or_fail(instream, paths.at(i));
        
        int x = 1;

        while (not instream.eof()) {
            string string_line;
            getline(instream, string_line);

            string string_line_copy = string_line;
            
            istringstream ss(string_line_copy);
            vector<string> vector_line;
            
            string temp;
            while (ss >> temp){
                vector_line.push_back(stripNonAlphaNum(temp));
            }
            for (unsigned int n = 0; n < vector_line.size(); n++) {
                Datum dat_new = {paths[i], x, string_line, 0, checkFirstInstance(vector_line, i)};
                theHash->insert(vector_line[n], dat_new);
            }

            x++;
        }
    }
}

bool checkFirstInstance(vector<string>& vector_line, int index) {
    for (unsigned int i = vector_line.size(); i == 0; i--) {
        if (get_lowercase(vector_line[i]) == get_lowercase(vector_line[index])) {
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

