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
#include <string>

#ifndef _HASH_TABLE_
#define _HASH_TABLE_

using namespace std;

struct hNode {
    vector<WordList> bucket_vector;
};

class HashTable
{
    public:
        HashTable();
        ~HashTable();

        void insert(string key, Datum new_datum);

        void print_list(ostream &out);
        bool isEmpty();
        int  listSize();
        bool containsBucket(string key);
        bool containsInstance(string key);
        WordList element_at(string key);
        void print_at_caseInSen(string key, ostream &out);
        void print_at_caseSen(string key, ostream &out);
        string get_lowercase(string word);

        void make_bucket(string key, Datum new_datum);
        void print_keys();

        bool collisions(string word);

    private:  


        static const int INITIAL_TABLE_SIZE = 1;
        int currentTableSize;
        int numItems;
        
        hNode *hashTable;

        void expand();
        
        void insert_datum(string key, Datum new_datum);
        int get_index(string word);
        void delete_buckets(int index);
        void insert_new_instance(string key, Datum new_datum);
};

#endif