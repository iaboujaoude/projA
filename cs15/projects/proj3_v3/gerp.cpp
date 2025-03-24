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
#include <sstream>
#include "FSTree.h"
#include "stringProcessing.h"
#include "WordInstance.h"
#include "WordList.h"
#include "HashTable.h"


using namespace std;

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);
void run_command_loop(ostream &outstream, HashTable *theHash, 
                      vector<string>& lines, vector<string>& paths);
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
g++ -o gerp -Wall -Wextra -Werror WordList.h WordList.cpp WordInstance.h 
WordInstance.cpp HashTableTest.cpp HashTable.cpp HashTable.h FSTree.h DirNode.h
FSTree.cpp DirNode.cpp gerp.cpp
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
    vector<string> lines;

    //Create and print new file paths
    string directory = argv[1];
    FSTree tree(directory);
    makePath(tree.getRoot(), directory, paths);
    
    HashTable *theHash = new HashTable;



    makeHash(paths, theHash, lines);

    run_command_loop(outstream, theHash, lines, paths);
    
    delete theHash;
}

/* run command loop
 *    Purpose: Run the command loop for the main body of the code
 * Parameters: where to print (outsream), the hash table being used, 
               the vector of lines of every path, the paths locations vector
 *    Returns: None
 *    Effects: None
 */
void run_command_loop(ostream &outstream, HashTable *theHash, 
                      vector<string>& lines, vector<string>& paths) {
    string word, command;
    command = "";

    while ((command != "@quit") and (command != "@q")) {
        cout << "Query? ";
        
        command = "";
        word = ""; 

        cin >> command;

        if (command[0] == '@') {
            if (command == "@i" or command == "@insensitive") {
                cin >> word;
                if (word != "") {
                    theHash->print_at_caseInSen(word, outstream, lines, paths);
                }
            }
            else if (command == "@f") {
                cin >> word;
                open_or_fail(outstream, word);
            }
        }
        else if ((command != "") and (word != "")) {
            theHash->print_at_caseSen(word, outstream, lines, paths);
        }
    }

    cout << "Goodbye! Thank you and have a nice day." << endl;
}

/* open or fail
 *    Purpose: try an open a given file
 * Parameters: the stream to be opened and the name of the file as a string
 *    Returns: None
 *    Effects: None
 */
template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string){
    stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Could not build index, exiting." << endl;
                exit(EXIT_FAILURE);
        }
}

/* make path
 *    Purpose: create a string vector containing the pathway for each
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

/* make hash
 *    Purpose: create the hash table that will be used for the program
 *    Parameters: vector of the paths we will use, the location of the hash 
                  table, the string vector of each line in the paths
 *    Returns: None
 *    Effects: Edits the hash and makes it
 */

void makeHash(vector<string>& paths, HashTable *theHash, vector<string>& lines) {
    int lineIndex = 0;
    float perc = 0;
    float percChange = 1;
    int you_count = 0;

    for (unsigned int i = 0; i < paths.size(); i++) {
        ifstream instream;
        open_or_fail(instream, paths.at(i));
        int lineNum = 1;

        while (not instream.eof()) {
            vector<string> vector_line;
            string string_line;
            getline(instream, string_line);
            make_line_vector(vector_line, string_line);
            lines.push_back(string_line);
            //Checks each word on line to see if it is first lowercase instance
            for (unsigned int n = 0; n < vector_line.size(); n++) {
                Datum dat_new = {static_cast<int>(i), lineNum, lineIndex, 
                                 checkFirstInstance(vector_line, n)};
                if (get_lowercase(vector_line[n]) == "you") {
                    you_count++;
                }
                theHash->insert(vector_line[n], dat_new);
            }
            lineIndex++;
            lineNum++;
        }
    }
}

/* checkFirstInstance
 *    Purpose: Checks to see if the given word is the first instance on line
 *    Parameters: vector of the line, that is a bunch of string words, and
                  the index of that word we are checking in the vector
 *    Returns: true if it is the first lowercase instance of the word in line
 *    Effects: None
 */

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

/* get_lowercase
 *    Purpose: Returns the lowercase version of a word
 *    Parameters: string to convert
 *    Returns: the lowercase version of the word
 *    Effects: None
 */

string get_lowercase(string word) {
    string to_return = "";
    
    for (unsigned int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);

        to_return = to_return + c;
    }

    return to_return;
}

/* make line vector
 *    Purpose: Creates a vector of individual words on a string line
 *    Parameters: location of vector to add, the line of words as a string
 *    Returns: none
 *    Effects: edits that vector
 */
void make_line_vector(vector<string>& vector_line, string string_line) {
    string string_line_copy = string_line;
    istringstream ss(string_line_copy);
    string temp;

    //Iterate line
    if (string_line != "") {
        while (ss >> temp) {
            vector_line.push_back(stripNonAlphaNum(temp));
        }
    }
}