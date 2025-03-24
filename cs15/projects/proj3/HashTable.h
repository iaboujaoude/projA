/*
 *  HashTable.h
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
#include "WordList.h"
#include <iostream>
#include <vector>

#ifndef _HASH_TABLE_
#define _HASH_TABLE_

using namespace std;

struct hNode {
        string key;
        WordList value;
        WordList *next;
    };

class HashTable
{
public:
    HashTable(string word);
    ~HashTable();

    void insert(string key, Datum new_datum);

    void print_list(ostream &out);
    bool isEmpty();
    int  listSize();
    bool conatinsBucket(string key);
    bool containsInstance(string key);
    WordInstance element_at(string key);
    bool print_at_caseInSen(string key, ostream &out);
    bool print_at_caseSen(string key, ostream &out);

    string return_name();

private:  
    string name = "";

    static const int INITIAL_TABLE_SIZE = 1;
    int currentTableSize;
    int numItems;
    
    hNode *hashTable;

    void expand();
    void make_node(string key, Datum new_datum);
    void insert_datum(string key, Datum new_datum);
    int get_index(string word);
};

#endif