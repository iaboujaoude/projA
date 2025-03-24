// yoda.cpp
// purpose:  reversing the order of a sentence
// by:  Ian Abou-Jaoude
// date:  September 20 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int main() {
    
    /*Declare 4 string variables that we will assign by asking for input from
    the user*/
    
    string word1;
    string word2;
    string word3;
    string word4;
    
    /*Ask for the 4 words and store each one individually so it can be 
    rearanged*/
    
    cout << "Type in four words: ";
    cin >> word1 >> word2 >> word3 >> word4;
    
    /*Print the series of words in reverese*/
    
    cout << word4 << " " << word3 << " " << word2 << " " << word1 << endl;
    
    return 0;
}