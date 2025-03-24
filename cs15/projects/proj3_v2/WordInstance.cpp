/*
 *  WordInstance.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 18, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Implementation of the Word Instance class which creates a list
 *  containing a data point at each time a certain word is found.
 *
 */

#include "WordInstance.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*    Name: Default constructor
 *    Purpose: create instance of empty list
 *    Parameters: none
 *    Returns: None
 *    Effects: none
 */
WordInstance::WordInstance() {

}

/*    Name: Destructor
 *    Purpose: destruct an instance of empty list
 *    Parameters: none
 *    Returns: None
 *    Effects: Recycles memory used by current instance
 */
WordInstance::~WordInstance() {
    word_vector.clear();
}

// WordInstance &WordInstance::operator=(const WordInstance &rhs) {
//     // If they are equating the same just return
//     if (this == &rhs) {
//         return *this;
//     }

//     this->word_vector.clear();
    
//     for (unsigned int i = 0; i < word_vector.size(); i++) {
//         this->word_vector.push_back(rhs.word_vector.at(i));
//     }

//     return *this;
// }

/*    Name: make datum
 *    Purpose: creates a datum from given input
 *    Parameters: the path of the file, number of line sotred, the whole line 
      as a string, count of words instances
 *    Returns: A datum conatining the given specifictions
 *    Effects: None
 */
Datum WordInstance::make_datum(string filePath, int lineNum, 
                               string lineString, int wordCount, bool first) {
    Datum new_datum;

    new_datum.filePath = filePath;
    new_datum.lineNum = lineNum;
    new_datum.lineString = lineString;
    new_datum.wordCount = wordCount;
    new_datum.first = first;

    return new_datum;
}

/*    Name: print datum
 *    Purpose: prints a datum instance
 *    Parameters: A datum to print
 *    Returns: None
 *    Effects: None
 */
void WordInstance::print_datum(Datum datum, ostream &out) {
    out << datum.filePath << ":" << datum.lineNum << ":"
    << datum.lineString << endl;
}


/*    Name: print list
 *    Purpose: prints all the datums in the list
 *    Parameters: none
 *    Returns: None
 *    Effects: None
 */
void WordInstance::print_list(ostream &out) {
    for (unsigned int i = 0; i < word_vector.size(); i ++) {
        print_datum(word_vector.at(i), out);
    }
}

/*    Name: insert
 *    Purpose: adds a new datum instance to the vector
 *    Parameters: a datum to add to the vector
 *    Returns: None
 *    Effects: Increases size of the word list by one
 */
void WordInstance::insert(Datum new_datum) {
    if (datum_same_last(new_datum)) {
        return;
    }
    word_vector.push_back(new_datum);
}

/*    Name: isEmpty
 *    Purpose: find out if the vector is empty
 *    Parameters: none
 *    Returns: a boolean containing true if the list contains datum
 *             and false otherwise
 *    Effects: none
 */
bool WordInstance::isEmpty() {
    return word_vector.empty();
}

/*    Name: listSize
 *    Purpose: get the number of datums in the list
 *    Parameters: none
 *    Returns: the number of datums in the word list
 *    Effects: none
 */
int WordInstance::listSize() {
    return word_vector.size();
}

/*    Name: insensitive print
 *    Purpose: print the word list for an insensitive query
 *    Parameters: none
 *    Returns: None
 *    Effects: none
 */
void WordInstance::insensitive_print(ostream &out) {
    for (unsigned int i = 0; i < word_vector.size(); i ++) {
        if (word_vector.at(i).first) {
            print_datum(word_vector.at(i), out);
        }
    }
}


/*    Name: datum_same
 *    Purpose: checks if the last added datum is the same as a new given datum
 *    Parameters: new given datum to test
 *    Returns: bool of if the datum is in the last
 *    Effects: none
 */
bool WordInstance::datum_same_last(Datum test) {
    if (isEmpty()) {
        return false;
    }
    return (word_vector.back().filePath == test.filePath) and
           (word_vector.back().lineNum == test.lineNum) and
           (word_vector.back().lineString == test.lineString);
}