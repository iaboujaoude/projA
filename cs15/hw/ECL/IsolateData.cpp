/*
 *  CharLinkedList.cpp
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */

#include "CharLinkedList.h"
#include <stdexcept>

using namespace std;



/*
 * name:      CharLinkedList
 * purpose:   Initializes an instance for the CharLinkedList that's empty 
              (constructor for the class)
 * arguments: none
 * returns:   none
 * effects:   Sets Size to 0
 */
 
 CharLinkedList::CharLinkedList() {
    constructorHelper();
}

/*
 * name:      CharLinkedList
 * purpose:   Initializes an instance for the CharLinkedList (constructor for 
              the class)
 * arguments: the first and only element of the list which is a char
 * returns:   none
 * effects:   Sets size to 1, and sets the first element of the linked list
 */
 
 CharLinkedList::CharLinkedList(char c) {
    constructorHelper();
    pushAtBack(c);
}

/*
 * name:      CharLinkedList
 * purpose:   Initializes an instance for the CharLinkedList (constructor for 
              the class)
 * arguments: an array of characters and array size
 * returns:   none
 * effects:   Sets size to array size, and sets the all the elements into the
 *            list
 */
 
 CharLinkedList::CharLinkedList(char arr[], int size) {
    constructorHelper();
    for (int i = 0; i < size; i++) {
        pushAtBack(arr[i]);
    }

    listSize = size;
}

/*
 * name:      CharLinkedList
 * purpose:   Initializes an instance for the CharLinkedList (constructor for 
              the class)
 * arguments: An LinkedList of characters
 * returns:   none
 * effects:   Creates a deep copy of all elements of the inputed LinkedList in
 *            a new LinkedList
 */
 
 CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    constructorHelper();
    Node *temp = other.front;

    for (int i = 0; i < other.listSize; i++) {
        pushAtBack(temp->data_c);
        temp = temp->next;
    }
}

/*
 * name:      ~CharLinkedList
 * purpose:   Recycle all memory used by our linked list
 * arguments: none
 * returns:   none
 * effects:   Deletes all heap allocated memory by the linked list
 */
 
 CharLinkedList::~CharLinkedList() {
    destructorHelper(front);
}

/*
 * name:      size
 * purpose:   return size of list
 * arguments: none
 * returns:   size int
 * effects:   none
 */
 
 int CharLinkedList::size() const {
    return listSize;
}
/*
 * name:      CharLinkedList &operator=
 * purpose:   Make a deep copy of the rhs into lhs
 * arguments: A CharLinkedList to be made a copy of
 * returns:   none
 * effects:   Recycles allocated memory of the lhs and edits it's elements
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other) {
    // If they are equating the same just return
     if (this == &other) {
         return *this;
    }
    //Clear the current list
    destructorHelper(front);

    //sets all values to null if we are copying an empty list
    if (other.isEmpty()) {
        constructorHelper();
        return *this;
    }
    
    constructorHelper();

    //Push at back each data element
    Node *curr = other.front;
    for (int i = 0; i < other.listSize; i++) {
        pushAtBack(curr->data_c);
        curr = curr->next;
    }

    listSize = other.listSize;
    return *this;
}

/*
 * name:      isEmpty
 * purpose:   Determine if the array is empty
 * arguments: None
 * returns:   boolean (true or false if empty)
 * effects:   none
 */
bool CharLinkedList::isEmpty() const {
    return (listSize == 0);
}

/*
 * name:      clear
 * purpose:   Clears all values of the array list
 * arguments: None
 * returns:   none
 * effects:   Makes the LinkedList empty
 */
void CharLinkedList::clear() {
    destructorHelper(front);
    constructorHelper();
}
/*
 * name:      first
 * purpose:   Gives the first character in the array list
 * arguments: None
 * returns:   Character (first in array)
 * effects:   none
 */
char CharLinkedList::first() const {
    if (isEmpty()) {
        throw runtime_error("cannot get first of empty LinkedList");
    }

    return front->data_c;
}

/*
 * name:      last
 * purpose:   Gives the last character in the array list
 * arguments: None
 * returns:   Character (last in array)
 * effects:   none
 */
char CharLinkedList::last() const {
    if (isEmpty()) {
        throw runtime_error("cannot get last of empty LinkedList");
    }

    return back->data_c;
}

/*
 * name:      elementAt
 * purpose:   Gives an element at some point
 * arguments: index for the LinkedList
 * returns:   Character (at given index)
 * effects:   none
 */
char CharLinkedList::elementAt(int index) const {
    throwRangeError(index);

    Node *node_at = elementAtHelper(index, 0, front);
    char return_c = node_at->data_c;
    return return_c;
}

/*
 * name:      toString
 * purpose:   To take the elements of chars and combine them into a string
 * arguments: None
 * returns:   String of charactere
 * effects:   none
 */
string CharLinkedList::toString() const {
    string listString = "";

    for (Node *curr = front; curr != nullptr; curr = curr->next) {
        listString = listString + curr->data_c;
    }

    return "[CharLinkedList of size " + to_string(listSize) + " <<" + 
            listString + ">>]";
}

/*
 * name:      toReverseString
 * purpose:   To take the elements of chars and combine them into a reversed 
 *            string
 * arguments: None
 * returns:   String of characters in reverse
 * effects:   none
 */
string CharLinkedList::toReverseString() const {
    string listString = "";

    for (Node *curr = back; curr != nullptr; curr = curr->previous) {
        listString = listString + curr->data_c;
    }

    return "[CharLinkedList of size " + to_string(listSize) + " <<" + 
            listString + ">>]";
}



/*
 * name:      pushAtBack
 * purpose:   Add a single element to the back of the list
 * arguments: The character to be added
 * returns:   none
 * effects:   Adds to the list size
 */
void CharLinkedList::pushAtBack(char c) {
    if (isEmpty()) {
        pushAtFront(c);
        return;
    }
    
    Node *temp = new Node;

    setNode(c, back, nullptr, temp);
    back->next = temp;

    back = temp;

    listSize++;
}

/*
 * name:      pushAtFront
 * purpose:   Add a single element to the front of the array
 * arguments: The character to be added
 * returns:   none
 * effects:   Expands the array if it's full and adds one more to size
 */
void CharLinkedList::pushAtFront(char c) {
    // Initialize if its empty
    if (isEmpty()) {
        Node *temp = new Node;
        setNode(c, nullptr, nullptr, temp);
        front = temp;
        back = temp;
        listSize++;
        return;
    }

    Node *temp = new Node;
    setNode(c, nullptr, front, temp);


    front->previous = temp;
    front = temp;

    listSize++;
}

/*
 * name:      insertAt
 * purpose:   Add a single element to the spot in the list
 * arguments: The character to be added, the index at where it should be added
 * returns:   none
 * effects:   Increases size by one
 */
void CharLinkedList::insertAt(char c, int index) {
    if ((0 > index) or (listSize < index)) {
        std::string er_message = "index (" + std::to_string(index) + 
                                  ") not in range [0.." + 
                                  std::to_string(listSize) + "]";
        throw range_error(er_message);
    }

    if (index == listSize) {
        pushAtBack(c);
        return;
    }
    if (index == 0) {
        pushAtFront(c);
        return;
    }

    Node *temp = new Node;
    temp->data_c = c;
    Node *curr = front;
    //Find the correct node node where we want to change
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    // Rearange where the function should be
    curr->previous->next = temp;
    temp->previous = curr->previous;
    temp->next = curr;
    curr->previous = temp;

    listSize++;
}

/*
 * name:      insertInOrder
 * purpose:   Add a single element to the list in a correct alphabetical order
 * arguments: The character to be added
 * returns:   none
 * effects:   Adds one more to size
 */
void CharLinkedList::insertInOrder(char c) {
    if (isEmpty()) {
        pushAtFront(c);
        return;
    }

    Node *curr = front;
    for (int i = 0; i < listSize; i++) {
        if (curr->data_c >= c) {
            insertAt(c, i);
            return;
        }   
        curr = curr->next;
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
void CharLinkedList::popFromFront() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }

    if (listSize == 1) {
        delete front;
        constructorHelper();
        return;
    }

    Node *curr = front;
    front = front->next;
    front->previous = nullptr;

    delete curr;
    listSize--;
}

/*
 * name:      popFromBack
 * purpose:   Removes the last item
 * arguments: none
 * returns:   none
 * effects:   Makes the array smaller by one
 */
void CharLinkedList::popFromBack() {
    if (isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }

    if (listSize == 1) {
        delete front;
        constructorHelper();
        return;
    }

    Node *curr = back;
    back = back->previous;
    back->next = nullptr;

    delete curr;
    listSize--;
}

/*
 * name:      removeAt
 * purpose:   Removes an element at a given spot in the list
 * arguments: the given index where we remove
 * returns:   none
 * effects:   Makes the list smaller by one
 */
void CharLinkedList::removeAt(int index) {
    throwRangeError(index);
    if (index == 0){
        popFromFront();
        return;
    }
    if (index == (listSize - 1)){
        popFromBack();
        return;
    }

    if (listSize == 1) {
        delete front;
        constructorHelper();
        return;
    }

    Node *curr = front;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }    

    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    delete curr;

    listSize--;
}

/*
 * name:      replaceAt
 * purpose:   Replaces a character with anotehr character at a given spot
 * arguments: the character we are replacing and the index at which it 
 *            is being removed
 * returns:   none
 * effects:   none
 */
void CharLinkedList::replaceAt(char c, int index) {
    throwRangeError(index);

    Node *curr = replaceAtHelper(front, index, 0);
    curr->data_c = c;
}


/*
 * name:      concatenate
 * purpose:   Adds a series of  to the end of the array
 * arguments: none
 * returns:   none
 * effects:   Makes the listSize larger
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    int size_const = other->listSize;
    Node *curr = other->front;

    for (int i = 0; i < size_const; i++) {
        pushAtBack(curr->data_c);
        curr = curr->next;
    }
}


/*

PRIVATE 

*/

/*
 * name:      copyArrayValues
 * purpose:   Copies each value within an a given array into our list
 * arguments: an array of characters and int size
 * returns:   none
 * effects:   Sets all values from the given array into our data array
 */
 
 void CharLinkedList::copyListValues(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        pushAtBack(arr[i]);
    }
 }

 /*
 * name:      throwRangeError
 * purpose:   Helper for all parts that have functions with indexes to throw
 *            range error with appropriate message
 * arguments: none
 * returns:   none
 * effects:   none
 */
 void CharLinkedList::throwRangeError(int index) const {
    if ((0 > index) or (listSize <= index)) {
        std::string er_message = "index (" + std::to_string(index) + 
                                  ") not in range [0.." + 
                                  std::to_string(listSize) + ")";
        throw range_error(er_message);
    }
 }

 /*
 * name:      setNode
 * purpose:   Helper for putting in a new node into the list
 * arguments: previous and next nodes we want this node to point to 
 * returns:   none
 * effects:   none
 */
 void CharLinkedList::setNode(char c, Node *previous_in, Node *next_in, Node *input) {
    input->data_c = c;
    input->previous = previous_in;
    input->next = next_in;
 }

 /*
 * name:      destructorHelper
 * purpose:   Helper for deleting each Node
 * arguments: the node we want to delete
 * returns:   none
 * effects:   makes size = 0
 */
 void CharLinkedList::destructorHelper(Node *curr) {
    if(isEmpty()){
        return;
    }
    
    if (curr->next == nullptr) {
        delete curr;
        return;
    }
    else {
        destructorHelper(curr->next);
        delete curr;
    }
 }
 
 /*
 * name:      elementAtHelper
 * purpose:   Helper for finding a node
 * arguments: the count of recursive processes, the index we want, the node
 *            we are using to find the next one
 * returns:   the node that we are looking for
 * effects:   none
 */
 CharLinkedList::Node* CharLinkedList::elementAtHelper(int index, int count, Node *current) const {
    if (count == index) {
        return current;
    }
    else {
        return elementAtHelper(index, ++count, current->next);
    }
 }


 /*
 * name:      constructorHelper
 * purpose:   Initializes the variiables for each private member
 * arguments: none
 * returns:   none
 * effects:   makes size = 0, front and back nullptr
 */
 void CharLinkedList::constructorHelper() {
    listSize = 0;
    front = nullptr;
    back = nullptr;
 }


 /*
 * name:      replaceAtHelper
 * purpose:   Helps with replaceAt to do recursively
 * arguments: none
 * returns:   none
 * effects:   makes size = 0, front and back nullptr
 */
 CharLinkedList::Node* CharLinkedList::replaceAtHelper(Node *curr, int index, int count) {
    if (count == index) {
        return curr;
    }
    else {
        return replaceAtHelper(curr->next, index, ++count);
    }
}