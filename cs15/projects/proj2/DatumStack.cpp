/*
 *  DatumStack.cpp
 *  Ian Abou-Jaoude
 *  Febuary 27
 *
 *  COMP 15 Proj 2
 *
 *  This program allows to create a stack of datums and do things to it like
 *  add and remove datums
 *
 */

#include "DatumStack.h"
#include "Datum.h"
#include <stdexcept>
#include <list>
#include <iostream>

using namespace std;

/*
 * name:      DatumStack
 * purpose:   Initialize empty DatumStack
 * arguments: none
 * returns:   none
 * effects:   none
 */
 
 DatumStack::DatumStack() {

}

/*
 * name:      DatumStack
 * purpose:   Initialize DatumStack with a given array
 * arguments: array of datums, size of array
 * returns:   none
 * effects:   none
 */
 
 DatumStack::DatumStack(Datum arr[], int size) {
    for (int i = 0; i < size; i++) {
        push(arr[i]);
    }
}


/*
 * name:      isEmpty
 * purpose:   Get the top of the stack
 * arguments: none
 * returns:   datum at the top of the list
 * effects:   none
 */
 
 bool DatumStack::isEmpty() {
    return datum_stack.empty();
}

/*
 * name:      top
 * purpose:   Get the top of the stack
 * arguments: none
 * returns:   datum at the top of the list
 * effects:   none
 */
 
 Datum DatumStack::top() {
    runtime_helper();
    
    return datum_stack.front();
}

/*
 * name:      size
 * purpose:   Return the size of the stack
 * arguments: none
 * returns:   int of size
 * effects:   none
 */
 
 int DatumStack::size() {
    return datum_stack.size();
}

/*
 * name:      clear
 * purpose:   removes all elements from the stack
 * arguments: none
 * returns:   none
 * effects:   makes size 0
 */
 
 void DatumStack::clear() {
    datum_stack.clear();
}


/*
 * name:      pop
 * purpose:   removes top element of stack
 * arguments: none
 * returns:   none
 * effects:   none
 */
 
 void DatumStack::pop() {
    runtime_helper();

    datum_stack.pop_front();
}

/*
 * name:      push
 * purpose:   adds element at the top
 * arguments: datum to push
 * returns:   none
 * effects:   make size +1
 */
 
 void DatumStack::push(const Datum &dataIn) {
    datum_stack.push_front(dataIn);
}



/*
 * name:      runtime_helper
 * purpose:   runtime error helper
 * arguments: datum to push
 * returns:   none
 * effects:   make size +1
 */
 
 void DatumStack::runtime_helper() {
    if (isEmpty()) {
        throw runtime_error("empty_stack");
    }
} 