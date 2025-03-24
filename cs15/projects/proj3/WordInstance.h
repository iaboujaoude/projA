/*
 *  WordInstance.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 18, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Interface of the Word Instance class which creates a list
 *  containing a data point at each time a certain word is found.
 *
 */

#include <vector>
#include <iostream>
#include <string>

#ifndef _WORD_INSTANCE_
#define _WORD_INSTANCE_

using namespace std;

struct Datum {
        string filePath;
        int lineNum;
        string lineString;
        int wordCount;
        bool first;
    };

class WordInstance
{
public:
    WordInstance();
    ~WordInstance();
    WordInstance &operator=(const WordInstance &rhs);

    void insert(Datum new_datum);
    void print_list(ostream &out);
    bool isEmpty();
    int  listSize();
    Datum make_datum(string filePath, int lineNum, string lineString,
                     int wordCount, bool first);

    
    void insensitive_print(ostream &out);
    bool datum_same_last(datum test);

private:
    vector<Datum> word_vector;
    void print_datum(Datum datum, ostream &out);
};

#endif