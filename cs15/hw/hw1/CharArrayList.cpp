/*
 *  CharArrayList.cpp
 *  Ian Abou-Jaoude
 *  January 31
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  This is the implementation of the CharArrayList for each private and 
 *  public class
 *
 */

#include "CharArrayList.h"
#include <stdexcept>

using namespace std;


/*
 * name:      CharArrayList
 * purpose:   Initializes an instance for the CharArrayList that's empty 
              (constructor for the class)
 * arguments: none
 * returns:   none
 * effects:   Sets capacity and arrSize to 0
 */
 
 CharArrayList::CharArrayList() {
    arrSize = 0;
    capacity = 0;
    data = nullptr;
}

/*
 * name:      CharArrayList
 * purpose:   Initializes an instance for the CharArrayList (constructor for 
              the class)
 * arguments: the first and only element of the array which is a char
 * returns:   none
 * effects:   Sets capacity and arrSize to 1, and sets the first element of
              the array list
 */
 
 CharArrayList::CharArrayList(char c) {
    arrSize = 1;
    capacity = 1;
    data = new char[capacity];
    data[0] = c;
}

/*
 * name:      CharArrayList
 * purpose:   Initializes an instance for the CharArrayList (constructor for 
              the class)
 * arguments: an array of characters and int size
 * returns:   none
 * effects:   Sets capacity and arrSize to 1, and sets the first element of
              the array list
 */
 
 CharArrayList::CharArrayList(char arr[], int size) {
    arrSize = size;
    capacity = size;
    data = new char[capacity];
    copyArrayValues(arr, size);
}

/*
 * name:      CharArrayList
 * purpose:   Initializes an instance for the CharArrayList (constructor for 
              the class)
 * arguments: An ArrayList of characters
 * returns:   none
 * effects:   Creates a deep copy of all elements of the inputed ArrayList in
 *            a new ArrayList
 */
 
 CharArrayList::CharArrayList(const CharArrayList &other) {
    arrSize = other.arrSize;
    capacity = arrSize;
    data = new char[capacity];
    copyArrayValues(other.data, arrSize);
}

/*
 * name:      ~CharArrayList
 * purpose:   Recycle all memory used by our data array
 * arguments: none
 * returns:   none
 * effects:   Deletes all heap allocated memory by data array
 */
 
 CharArrayList::~CharArrayList() {
    delete [] data;
}

/*
 * name:      size
 * purpose:   Recycle all memory used by our data array
 * arguments: none
 * returns:   none
 * effects:   Deletes all heap allocated memory by data array
 */
 
 int CharArrayList::size() const {
    return arrSize;
}
/*
 * name:      CharArrayList &operator=
 * purpose:   Make a deep copy of the rhs into lhs
 * arguments: A CharArrayList to be made a copy of
 * returns:   none
 * effects:   Recycles allocated memory of the lhs and edits it's elements
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &rhs) {
    // If they are equating the same just return
    if (this == &rhs) {
        return *this;
    }

    arrSize = rhs.arrSize;
    capacity = rhs.capacity;

    delete [] data;
    data = new char[capacity];
    
    // helper function that copies individual elements into data
    copyArrayValues(rhs.data, arrSize);

    return *this;
}

/*
 * name:      isEmpty
 * purpose:   Determine if the array is empty
 * arguments: None
 * returns:   boolean (true or false if empty)
 * effects:   none
 */
bool CharArrayList::isEmpty() const {
    return (arrSize == 0);
}

/*
 * name:      clear
 * purpose:   Clears all values of the array list
 * arguments: None
 * returns:   none
 * effects:   Makes the arraylist empty
 */
void CharArrayList::clear() {
    delete [] data;
    arrSize = 0;
    capacity = 0;
    data = new char[0];
}
/*
 * name:      first
 * purpose:   Gives the first character in the array list
 * arguments: None
 * returns:   Character (first in array)
 * effects:   none
 */
char CharArrayList::first() const {
    if (isEmpty()) {
        throw runtime_error("cannot get first of empty ArrayList");
    }

    return data[0];
}

/*
 * name:      last
 * purpose:   Gives the last character in the array list
 * arguments: None
 * returns:   Character (last in array)
 * effects:   none
 */
char CharArrayList::last() const {
    if (isEmpty()) {
        throw runtime_error("cannot get last of an empty ArrayList");
    }

    return data[arrSize - 1];
}

/*
 * name:      elementAt
 * purpose:   Gives an element at some point
 * arguments: index for the arraylist
 * returns:   Character (at given index)
 * effects:   none
 */
char CharArrayList::elementAt(int index) const {
    if ((0 > index) or (arrSize <= index)) {
        std::string er_message = "index (" + std::to_string(index) + 
                                  ") not in range [0.." + 
                                  std::to_string(arrSize) + ")";
        throw range_error(er_message);
    }

    return data[index];
}

/*
 * name:      toString
 * purpose:   To take the elements of chars and combine them into a string
 * arguments: None
 * returns:   String of charactere
 * effects:   none
 */
string CharArrayList::toString() const {
    string arrString = "";
    for (int i = 0; i < arrSize; i++) {
        arrString = arrString + data[i];
    }

    return "[CharArrayList of size " + to_string(arrSize) + " <<" + 
            arrString + ">>]";
}

/*
 * name:      toReverseString
 * purpose:   To take the elements of chars and combine them into a reversed 
 *            string
 * arguments: None
 * returns:   String of characters in reverse
 * effects:   none
 */
string CharArrayList::toReverseString() const {
    string arrString = "";
    for (int i = arrSize - 1; i >= 0; i--) {
        arrString = arrString + data[i];
    }

    return "[CharArrayList of size " + to_string(arrSize) + " <<" + 
            arrString + ">>]";
}

/*
 * name:      pushAtBack
 * purpose:   Add a single element to the back of the array
 * arguments: The character to be added
 * returns:   none
 * effects:   Expands the array if it's full and adds one more to size
 */
void CharArrayList::pushAtBack(char c) {
    if (arrSize == capacity) {
        expand();
    }

    data[arrSize] = c;
    arrSize++;
}

/*
 * name:      pushAtFront
 * purpose:   Add a single element to the front of the array
 * arguments: The character to be added
 * returns:   none
 * effects:   Expands the array if it's full and adds one more to size
 */
void CharArrayList::pushAtFront(char c) {
    if (arrSize == capacity) {
        expand();
    }
    for (int i = arrSize; i > 0; i--) {
        data[i] = data[i-1];
    }
    data[0] = c;
    arrSize++;
}

/*
 * name:      insertAt
 * purpose:   Add a single element to the spot indicated in the array
 * arguments: The character to be added, the index at where it should be added
 * returns:   none
 * effects:   Expands the array if it's full and adds one more to size
 */
void CharArrayList::insertAt(char c, int index) {
    if ((index < 0) or (index > arrSize)) {
        if ((0 > index) or (arrSize <= index)) {
        std::string er_message = "index (" + std::to_string(index) + 
                                  ") not in range [0.." + 
                                  std::to_string(arrSize) + "]";
        throw range_error(er_message);
        }
    }
    if (arrSize == capacity) {
        expand();
    }
    for (int i = arrSize; i > index; i--){
        data[i] = data[i-1];
    }
    data[index] = c;
    arrSize++;
}

/*
 * name:      insertInOrder
 * purpose:   Add a single element to an array in a correct alphabetical order
 * arguments: The character to be added
 * returns:   none
 * effects:   Expands the array if it's full and adds one more to size
 */
void CharArrayList::insertInOrder(char c) {
    if (arrSize == capacity) {
        expand();
    }

    if (isEmpty()) {
        pushAtFront(c);
        return;
    }

    for (int i = 0; i < arrSize; i++) {
        if (data[i] >= c) {
            insertAt(c, i);
            return;
        }   
    }

    pushAtBack(c);
}

/*
 * name:      popFromFront
 * purpose:   Removes the first item in list
 * arguments: none
 * returns:   none
 * effects:   Makes the array smaller by one
 */
void CharArrayList::popFromFront() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }

    char *data_temp = new char[arrSize - 1];

    // Fill copy and ignore first
    for (int i = 1; i < arrSize; i++) {
        data_temp[i - 1] = data[i];
    }

    delete [] data;

    data = data_temp;
    
    capacity = arrSize - 1;
    arrSize--;
}

/*
 * name:      popFromBack
 * purpose:   Removes the last item
 * arguments: none
 * returns:   none
 * effects:   Makes the array smaller by one
 */
void CharArrayList::popFromBack() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty ArrayList");
    }

    char *data_temp = new char[arrSize - 1];
    
    // Fill copy and ignore last
    for (int i = 0; i < arrSize - 1; i++) {
        data_temp[i] = data[i];
    }

    delete [] data;

    data = data_temp;
    
    capacity = arrSize - 1;
    arrSize--;
}

/*
 * name:      removeAt
 * purpose:   Removes an element at a given spot in the list
 * arguments: none
 * returns:   none
 * effects:   Makes the array smaller by one
 */
void CharArrayList::removeAt(int index) {
    throwRangeError(index);

    char *data_temp = new char[arrSize -1 ];

    //Traverse and copy all elements but skip over the one at the index
    for (int i = 0; i < index; i++) {
        data_temp[i] = data[i];
    }
    for (int i = index +1; i < arrSize; i++) {
        data_temp[i - 1] = data[i];
    }

    delete [] data;
    data = data_temp;
    capacity = arrSize - 1;
    arrSize--;
}

/*
 * name:      replaceAt
 * purpose:   Replaces a character with anotehr character at a given spot
 * arguments: none
 * returns:   none
 * effects:   Makes the array smaller by one
 */
void CharArrayList::replaceAt(char c, int index) {
    throwRangeError(index);

    data[index] = c;
}


/*
 * name:      concatenate
 * purpose:   Adds an array to the end of the array
 * arguments: none
 * returns:   none
 * effects:   Makes the array size larger
 */
void CharArrayList::concatenate(CharArrayList *other) {
    int other_size_const = other->size();

    while (other_size_const + arrSize > capacity) {
        expand();
    }

    for (int i = 0; i < other_size_const; i++) {
        pushAtBack(other->elementAt(i));
    }
}

/*
 * name:      shrink
 * purpose:   Removes all elements in the array that are not used
 * arguments: none
 * returns:   none
 * effects:   Sets the array size and capacity to be the same
 */
void CharArrayList::shrink() {
    if((isEmpty()) and (capacity == 0)) {
        return;
    }
    
    char *data_temp = new char[arrSize];

    for (int i = 0; i < arrSize; i++) {
        data_temp[i] = data[i];
    }

    delete [] data;
    data = data_temp;
    capacity = arrSize;
}


/*

PRIVATE 

*/

/*
 * name:      copyArrayValues
 * purpose:   Copies each value within an a given array into our data array
 * arguments: an array of characters and int size
 * returns:   none
 * effects:   Sets all values from the given array into our data array
 */
 
 void CharArrayList::copyArrayValues(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
    }
 }

 
/*
 * name:      expand
 * purpose:   Make the capacity larger
 * arguments: none
 * returns:   none
 * effects:   Expands the array to hold more characters, recycles 
 *            old data and reassigns it
 */
 
 void CharArrayList::expand() {
    char *data_temp = new char[(capacity * 2) + 2];

    for (int i = 0; i < arrSize; i++) {
        data_temp[i] = data[i];
    }

    capacity = (capacity * 2) + 2;
    delete [] data;

    data = data_temp;
 }

/*
 * name:      throwRangeError
 * purpose:   Helper for all parts that have functions with indexes to throw
 *            range error with appropriate message
 * arguments: none
 * returns:   none
 * effects:   none
 */
 void CharArrayList::throwRangeError(int index) {
    if ((0 > index) or (arrSize <= index)) {
        std::string er_message = "index (" + std::to_string(index) + 
                                  ") not in range [0.." + 
                                  std::to_string(arrSize) + ")";
        throw range_error(er_message);
    }
 }