#include "HashTable.h"
#include "WordList.h"
#include "WordInstance.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*    Name: Default constructor
 *    Purpose: create instance of empty list and set its name
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
HashTable::HashTable(string word) {
    name = word;

    currentTableSize = INITIAL_TABLE_SIZE;
    numItems = 0;

    hashTable = new hNode[currentTableSize];
}

/*
 * destructor
 */
HashTable::~HashTable()
{
    //TO DO
    delete [] hashTable;
}

/*    Name: insert node
 *    Purpose: add a new hNode to the word List
 *    Parameters: a new hNode to add to the word List
 *    Returns: None
 *    Effects: Adds new hNode to the array
 */
void HashTable::insert(string key, Datum new_datum) {
    if (contains(key)) {
        insert_datum(key, new_datum);
    } else {
        make_node(key, new_datum);
    }
}

/*    Name: make node
 *    Purpose: add a new hNode to the word List given the key and datum if the
 *    word instance doesn't already exist
 *    Parameters: a new hNode to add to the word List
 *    Returns: None
 *    Effects: Adds new hNode to the array
 */
void HashTable::make_node(string key, Datum new_datum) {

    if (currentTableSize == numItems) {
        expand();
    }

    int index = get_index(key);

    hashTable[index].key = key;

    WordList new_list;

    hashTable[index].value = new_list;
    insert_datum(key, new_datum);

    numItems++;
}

/*    Name: insert datum
 *    Purpose: add a datum to an existing word instance within the word list
 *    Parameters: a key to access the particular word instance to add to and
 *                a datum to add
 *    Returns: None
 *    Effects: Adds new datum to a word instance within the word list
 */
void HashTable::insert_datum(string key, Datum new_datum) {
    hashTable[get_index(key)].value.insert(key, new_datum);
}

/*    Name: Expand
 *    Purpose: expand the capacity of the hashTable array
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
void HashTable::expand() {
    hNode *data_temp = new hNode[(currentTableSize * 2) + 2];

    for (int i = 0; i < currentTableSize; i++) {
        int index = hash<string>{}(hashTable[i].key) % ((currentTableSize * 2) + 2);
        data_temp[index] = hashTable[i];

    }

    currentTableSize = (currentTableSize * 2) + 2;
    delete [] hashTable;

    hashTable = data_temp;
}

/*    Name: isEmpty
 *    Purpose: find out if there are any elem
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
bool HashTable::isEmpty() {
    return (numItems == 0);
}

// /*    Name: print_list
//  *    Purpose: print every word instance in the hash table
//  *    Parameters: a string to be the name of the list
//  *    Returns: None
//  *    Effects: Makes new instance of a WordLst
//  */
 
// void HashTable::print_list(ostream &out, string key) {
//     for (int i = 0; i < currentTableSize; i++) {
//         if (not hashTable[i].value.isEmpty()) {
//             hashTable[i].value.value.print_list(out);
//         }
//     }
// }

/*    Name: element at
 *    Purpose: access the word Instance at a specific index in the Word List
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */
WordList HashTable::element_at(string key) {
    WordList null("");
    
    if (not containsBucket(key)) {
        return null;
    }

    WordList listToReturn = hashTable[get_index(key)].value;
    hNode *hTemp = hashTable[get_index(key)];
    
    while ((listToReturn.key != key) and (hTemp != nullptr)) {
        lisToReturn = hTemp->(*next);
        hTemp = hTemp->next;

        if (listToReturn.key == key) {
            return listToReturn;
        }
    }
    
    return null; 
}

/*    Name: print at caseInSen
 *    Purpose: To print the list of words in a wordlist
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
bool HashTable::print_at_caseInSen(string key, ostream &out) {
    if (not contains(key)) {
        return false;
    }
    
    WordList listToPrint = element_at(key);
    listToPrint.print_list(out);

    return true;
}

/*    Name: print at caseSen
 *    Purpose: To print the instance to be printed in a sensitive search
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
bool HashTable::print_at_caseSen(string key, ostream &out) {
    if (not conatinsInstance(key)) {
        return false;
    }
    
    WordList listToPrint = element_at(key);
    listToPrint.print_at(key, out);

    return true;
}

/*    Name: conatinsSen
 *    Purpose: assertain whether or not the instance of the word exists
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool HashTable::conatinsInstance(string key) { 
    WordList listToCheck = element_at(key);
    hNode *hTemp = hashTable[get_index(key)];
    
    while (hTemp != nullptr) {
        if (listToCheck.contains(key))
        listToCheck = hTemp->(*next);
        hTemp = hTemp->next;
    }

    return false;
}

/*    Name: conatinsInSen
 *    Purpose: assertain whether or not 
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool HashTable::conatinsBucket(string key) { 
    return (hashTable[get_index(key)].key == key);
}

/*    Name: get index
 *    Purpose: return the hashed value of a string 
 *    Parameters: a string which serves as the key of the hash value
 *    Returns: a interger hash value 
 *    Effects: None
 */
int HashTable::get_index(string word) {
    return hash<string>{}(word) % currentTableSize;
}

/*    Name: list size
 *    Purpose: return the number of nodes in the word list
 *    Parameters: none
 *    Returns: a interger serving as the number of nodes in the word list
 *    Effects: None
 */
int HashTable::listSize() {
    return numItems;
}