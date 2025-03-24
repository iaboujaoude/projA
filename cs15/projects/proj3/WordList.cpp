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
WordList::WordList(string word) {
    name = word;

    currentTableSize = INITIAL_TABLE_SIZE;
    numItems = 0;

    wordList = new tNode[currentTableSize];
}

/*
 * destructor
 */
WordList::~WordList()
{
    delete [] wordList;
}

/*
 * name:      WordList &operator=
 * purpose:   Make a deep copy of the rhs into lhs
 * arguments: A CharArrayList to be made a copy of
 * returns:   none
 * effects:   Recycles allocated memory of the lhs and edits it's elements
 */
WordList &WordList::operator=(const WordList &rhs) {
    // If they are equating the same just return
    if (this == &rhs) {
        return *this;
    }

    numItems = rhs.numItems;
    currentTableSize = rhs.currentTableSize;

    delete [] wordList;
    wordList = new tNode[currentTableSize];
    
    for (int i = 0; i < numItems; i++) {
        this.wordList[i] = rhs.wordList[i];
    }

    return *this;
}

/*    Name: insert node
 *    Purpose: add a new tNode to the word List
 *    Parameters: a new tNode to add to the word List
 *    Returns: None
 *    Effects: Adds new tNode to the array
 */
void WordList::insert(string key, Datum new_datum) {
    if (contains(key)) {
        insert_datum(key, new_datum);
    } else {
        make_node(key, new_datum);
    }
}

/*    Name: make node
 *    Purpose: add a new tNode to the word List given the key and datum if the
 *    word instance doesn't already exist
 *    Parameters: a new tNode to add to the word List
 *    Returns: None
 *    Effects: Adds new tNode to the array
 */
void WordList::make_node(string key, Datum new_datum) {

    if (currentTableSize == numItems) {
        expand();
    }

    int index = numItems;

    wordList[index].key = key;

    WordInstance new_instance;

    wordList[index].value = new_instance;
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
void WordList::insert_datum(string key, Datum new_datum) {
    for (int i = 0; i < numItems; i++) {
        if (wordList[i].key == key) {
            wordList[numItems].value.insert(new_datum);
        }
    }
}

/*    Name: Expand
 *    Purpose: expand the capacity of the wordList array
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
void WordList::expand() {
    tNode *data_temp = new tNode[(currentTableSize * 2) + 2];

    for (int i = 0; i < currentTableSize; i++) {
        // int index = hash<string>{}(wordList[i].key) % ((currentTableSize * 2) + 2);
        data_temp[i] = wordList[i];

    }

    currentTableSize = (currentTableSize * 2) + 2;
    delete [] wordList;

    wordList = data_temp;
}

/*    Name: isEmpty
 *    Purpose: find out if there are any elem
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
bool WordList::isEmpty() {
    return (numItems == 0);
}

/*    Name: print_list
 *    Purpose: print every word instance in the list
 *    Parameters: the stream of where it will be printed
 *    Returns: None
 */
 
void WordList::print_list(ostream &out) {
    for (int i = 0; i < currentTableSize; i++) {
        if (not wordList[i].value.isEmpty()) {
            wordList[i].value.insensitive_print(out);
        }
    }
}

/*    Name: element at
 *    Purpose: access the word Instance at a specific index in the Word List
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */
WordInstance WordList::element_at(string key) {
    WordInstance instanceToReturn;
    
    for (int i = 0; i < numItems; i++) {
        if (key == wordList[i].key) {
            instanceToReturn = wordList[i].value;
        }
    }
    
    return instanceToReturn; 
}

/*    Name: print at
 *    Purpose: To print a single word instance inside the table
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
bool WordList::print_at(string key, ostream &out) {
    WordInstance instanceToPrint;
    
    for (int i = 0; i < numItems; i++) {
        if (key == wordList[i].key) {
            instanceToPrint = wordList[i].value;
        }
    }

    if (instanceToPrint.isEmpty()) {
        return false;
    }
    
    instanceToPrint.print_list(out);

    return true;
}

/*    Name: conatins
 *    Purpose: assertain whether or not 
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool WordList::contains(string key) {  
    for (int i = 0; i < numItems; i++) {
        if (key == wordList[i].key) {
            return true;
        }
    }

    return false;
}

/*    Name: list size
 *    Purpose: return the number of nodes in the word list
 *    Parameters: none
 *    Returns: a interger serving as the number of nodes in the word list
 *    Effects: None
 */
int WordList::listSize() {
    return numItems;
}