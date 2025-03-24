/*
 * FunkeyTable.cpp --- compare two different methods of handling hash
 * table collisions and two different hash functions.
 *
 * your job:  code the insert functions and expand function
 *  our job:  run the insert functions and report results
 *
 * Based on a previous lab by Ben Hescott, I think.
 *
 * Mark A. Sheldon, Tufts University, Spring 2017
 */

#include <iostream>
#include <stdio.h>
#include <functional>

#include "FunkeyTable.h"

using namespace std;

/*
 * Constructor allocates and initializes two empty tables
 * of the INITIAL_TABLE_SIZE
 */
FunkeyTable::FunkeyTable()
{
        currentTableSize = INITIAL_TABLE_SIZE;
        numItemsInTable  = 0;

        chainedTable     = new ChainNode *[currentTableSize];
        linearTable      = new TableEntry[currentTableSize];

        for (int i = 0; i < currentTableSize; i++) {
                chainedTable[i]        = nullptr;
                linearTable[i].isEmpty = true;
        }
}

/*
 * Delete all nodes in list starting with given node
 */
void FunkeyTable::deleteList(ChainNode *node)
{
        if (node == nullptr) {
                return;
        }

        deleteList(node->next);
        delete node;
}

/*
 * destructor
 */
FunkeyTable::~FunkeyTable()
{
        ChainNode *temp = *chainedTable;
        
        for (int i = 0; i < currentTableSize; i++) {
                ChainNode *temp2 = temp;
                deleteList(temp2);
                temp = temp->next;
        }
}


static size_t good_hash_function(KeyType key)
{
        return std::hash<KeyType>{}(key);
}

static size_t bad_hash_function(KeyType key)
{
        return key.length();
}

static size_t hashValue(KeyType key, FunkeyTable::HashFunction hashFunction)
{
        if (hashFunction == FunkeyTable::BAD_HASH_FUNCTION)
                return bad_hash_function(key);
        else
                return good_hash_function(key);
}

/*
 * Linear Probing
 *
 * Return number of collisions before finding a spot
 *
 */
int FunkeyTable::insertProbing(KeyType key, ValueType value,
                               HashFunction hashFunction)
{
        int    attempt = 0;
        bool   found   = false;

        // NOTE:  You can put things here if it helps you

        ChainNode *temp = linearTable; 

        while (not found) {
                if (temp->isEmpty) {
                        found = true;
                        temp->value = value;
                        temp->key = key;

                        TableEnry *curr = linearTable;
                }

                // TODO:  Students write code here
                //        (you may write code outside the loop, too)

                attempt++;
                temp = temp->next;
        }
        return attempt;
}

/*
 * Return length of list starting at given node
 */
int FunkeyTable::listLength(ChainNode *nodep)
{
        // TODO:  Students write code here
}

/*
 * Chained hashing --- each spot in table is a linked list 
 *
 * Return number of items in that spot before insertion
 */
int FunkeyTable::insertChaining(KeyType key, ValueType value,
                                HashFunction hashFunction)
{
        // TODO: Students write code here
        // STUB: Replace with the correct code
        return 0;
}




/*
 * Expand both of the hash tables
 */
void FunkeyTable::expand(HashFunction hashFunction)
{
        
        ChainNode *temp = new ChainNode[currentTableSize * 2];
        for (int i = 0; i < numItemsInTable; i++) {
                temp[i] = chainedTable[i];
        }
        delete [] chainedTable;
        chainedTable = temp;
        //currentTableSize = currentTableSize * 2;

        ChainNode *temp2 = new TableEnry[currentTableSize * 2];
        for (int i = 0; i < numItemsInTable; i++) {
                temp2[i] = TableEnry[i];
        }
        delete [] TableEnry;
        TableEnry = temp2;
        currentTableSize = currentTableSize * 2;
}

void FunkeyTable::printTableEntry(TableEntry entry)
{
        if (entry.isEmpty)
                cout << "empty";
        else
                cout << "key:  "
                     << entry.key
                     << "; value:  {"
                     << entry.value.chartPosition
                     << ", "
                     << entry.value.bpm
                     << "}";
}

void FunkeyTable::printChainNode(ChainNode *nodep)
{
        cout << "key:  " << nodep->key
             << "; value:  {" << nodep->value.chartPosition
             << ", " << nodep->value.bpm << "}";
}

/*
 * Print both hash tables
 * Could break this up into two print functions
 */
void FunkeyTable::print()
{
        cout << "Linear table" << endl;
        
        for (int i = 0; i < currentTableSize; ++i) {
                cout << i << ":  ";
                printTableEntry(linearTable[i]);
                cout << endl;
        }
        cout << endl << "Chained table" << endl;
        
        for (int i = 0; i < currentTableSize; ++i) {
                ChainNode *curr = chainedTable[i];
                cout << i << ":  [ ";
                while (curr != NULL) {
                        printChainNode(curr);
                        curr = curr->next;
                        if (curr != NULL)
                                cout << ", ";
                }
                cout << "]" << endl;
        }
        cout << endl;
}
