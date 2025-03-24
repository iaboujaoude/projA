/*
 *  WordList.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 26, 2022
 *
 *  COMP 15 - Proj 3
 *
 *  Implementation of the WordList class.
 *
 */

#include "WordList.h"
#include "WordInstance.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*    Name: default constructor
 *    Purpose: create instance of empty list
 *    Parameters: none
 *    Returns: None
 *    Effects: sets null string
 */
WordList::WordList() {
    name = "";
}

/*    Name: set name
 *    Purpose: sets a new name for the WordList
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: None
 */
void WordList::set_name(string input_name) {
    name = input_name;
}

/*    Name: name constructor
 *    Purpose: create instance of empty list and set its name
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
WordList::WordList(string word) {
    name = word;
}

/*
 * destructor
 */
WordList::~WordList() {
    word_list.clear();
}

// /*
//  * name:      WordList &operator=
//  * purpose:   Make a deep copy of the rhs into lhs
//  * arguments: A WordList to be made a copy of
//  * returns:   none
//  * effects:   Recycles allocated memory of the lhs and edits it's elements
//  */
// WordList &WordList::operator=(const WordList &rhs) {
//     // If they are equating the same just return
//     if (this == &rhs) {
//         return *this;
//     }

//     this->word_list.clear();
    
//     for (unsigned int i = 0; i < rhs.word_list.size(); i++) {
//         this->word_list.push_back(rhs.word_list[i]);
//     }

//     return *this;
// }

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
    //Make new word instance
    WordInstance new_instance;

    //Make new node
    tNode new_node;
    new_node.key = key;
    new_node.value = new_instance;

    //Add node to the word list
    word_list.push_back(new_node);

    //Add individual instance
    insert(key, new_datum);
}

/*    Name: insert datum
 *    Purpose: add a datum to an existing word instance within the word list
 *    Parameters: a key to access the particular word instance to add to and
 *                a datum to add
 *    Returns: None
 *    Effects: Adds new datum to a word instance within the word list
 */
void WordList::insert_datum(string key, Datum new_datum) {
    //Find word instance in the word list with given key
    for (unsigned int i = 0; i < word_list.size(); i++) {
        //Insert node into proper slot in the vector
        if (word_list[i].key == key) {
            word_list[i].value.insert(new_datum);
        }
    }
}

/*    Name: isEmpty
 *    Purpose: find out if there are any elem
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
bool WordList::isEmpty() {
    return word_list.empty();
}

/*    Name: print_list
 *    Purpose: print every word instance in the list
 *    Parameters: the stream of where it will be printed
 *    Returns: None
 */
 
void WordList::print_list(ostream &out, vector<string>& lines, vector<string>& paths) {
    //Traverse vector and print contents if not empty
    for (unsigned int i = 0; i < word_list.size(); i++) {
        if (not word_list[i].value.isEmpty()) {
            word_list[i].value.insensitive_print(out, lines, paths);
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
    //Make word instance to return
    WordInstance new_instance;
    
    //Find word instance with matching key
    for (unsigned int i = 0; i < word_list.size(); i++) {
        if (key == word_list[i].key) {
            new_instance = word_list[i].value;
        }
    }

    return new_instance;
}

/*    Name: print at
 *    Purpose: To print a single word instance inside the table
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
bool WordList::print_at(string key, ostream &out, vector<string>& lines, vector<string>& paths) {
    //Traverse word list until reach instance with given key
    for (unsigned int i = 0; i < word_list.size(); i++) {
        if (key == word_list[i].key) {
            //return if empty
            if (word_list[i].value.isEmpty()) {
                return false;
            }
            //Print instance at the given index
            word_list[i].value.print_list(out, lines, paths);
            return true;
        }
    }

    return false;
}

/*    Name: conatins
 *    Purpose: assertain whether or not 
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool WordList::contains(string key) {  
    //Traverse vector until key is found
    for (unsigned int i = 0; i < word_list.size(); i++) {
        if (key == word_list[i].key) {
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
    return word_list.size();
}

/*    Name: name
 *    Purpose: return the name of a word list
 *    Parameters: none
 *    Returns: a string serving as the name of the word list
 *    Effects: None
 */
string WordList::return_name() {
    return name;
}

/*    Name: get size
 *    Purpose: attain the size of the word list
 *    Parameters: none
 *    Returns: an interger serving as the number of elements in the word list
 *    Effects: None
 */
int WordList::get_size() {
    return word_list.size();
}

int WordList::num_instances() {
    cout << "in num instances\n";
    int total = 0;
    for (unsigned int i = 0; i < word_list.size(); i++) {
        if (not word_list[i].value.isEmpty()) {
            total = total + word_list.at(i).value.listSize();
        }
    }
    return total;
}