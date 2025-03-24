/*
 *  WordList.h
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 15, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Header for the list of the same words with different capitalizations
 *  will be a vector containing datums of each word instance (wordinstance.cpp)
 *
 */

#include "WordInstance.h"
#include <iostream>
#include <vector>

#ifndef _WORD_LIST_
#define _WORD_LIST_

using namespace std;

struct tNode {
        string key;
        WordInstance value;
    };

class WordList
{
public:
    WordList(string word);
    ~WordList();

    void insert(string key, Datum new_datum);
    WordList &operator=(const WordList &rhs);
    void print_list(ostream &out);
    bool isEmpty();
    int  listSize();
    bool contains(string key);
    WordInstance element_at(string key);
    bool print_at(string key, ostream &out);

    string return_name();

private:  
    string name = "";

    static const int INITIAL_TABLE_SIZE = 1;
    int currentTableSize;
    int numItems;
    
    tNode *wordList;

    void expand();
    void make_node(string key, Datum new_datum);
    void insert_datum(string key, Datum new_datum);
};

#endif