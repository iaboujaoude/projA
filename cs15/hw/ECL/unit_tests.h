/*
 *  unit_tests.h
 *  Ian Abou-Jaoude
 *  Feb 4
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  To test each function from the CharLinkedList class
 *
 */

#include "CharLinkedList.h"
#include <cassert>
#include <iostream>

using namespace std;

// Tests the default constructor to see if it initialized wihtout errors 
// and checks the size
// Checks to make sure default constructor is empty
void Constructor1_works() {
    CharLinkedList test_list;
    assert(test_list.size() == 0);
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Tests the default constructor to see if it initialized wihtout errors 
// and that we can add onto it using pushAtBack and front
void Constructor1_works_with_adding() {
    CharLinkedList test_list;
    assert(test_list.size() == 0);
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");

    test_list.pushAtBack('h');
    test_list.pushAtBack('i');
    test_list.pushAtFront('.');

    assert(test_list.toString() == "[CharLinkedList of size 3 <<.hi>>]");

}


// Checks to make sure insert one element constructor works
void Constructor2_works() {
    CharLinkedList test_list2('h');
    assert(test_list2.size() == 1);
    assert(test_list2.toString() == "[CharLinkedList of size 1 <<h>>]");
}

// Checks to make sure insert one element constructor works and that it can be
// added to
void Constructor2_works_with_adding() {
    CharLinkedList test_list2('h');
    assert(test_list2.size() == 1);
    assert(test_list2.toString() == "[CharLinkedList of size 1 <<h>>]");

    test_list2.pushAtBack('i');
    test_list2.pushAtFront('.');

    assert(test_list2.toString() == "[CharLinkedList of size 3 <<.hi>>]");

}


// Checks to make sure insert array constructor works with the linked list
void Constructor3_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list3(array_test, 5);

    assert(test_list3.size() == 5);
    assert(test_list3.toString() == "[CharLinkedList of size 5 <<abcde>>]");
}

// Checks to make sure insert array constructor works with the linked list
// and that we can add to the front and back to ensure it was initialized
// properly
void Constructor3_works_with_adding() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list3(array_test, 5);

    assert(test_list3.size() == 5);
    assert(test_list3.toString() == "[CharLinkedList of size 5 <<abcde>>]");

    test_list3.pushAtBack('i');
    test_list3.pushAtFront('.');

    assert(test_list3.toString() == "[CharLinkedList of size 7 <<.abcdei>>]");
}


// Checks to make sure insert array constructor works (put array list in
// perameter)
void Constructor4_works_array() {

    //Create a CharLinkedList to do a deep copy of
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list3(array_test, 5);

    CharLinkedList test_list5(test_list3);
    assert(test_list5.size() == 5);
    assert(test_list5.toString() == "[CharLinkedList of size 5 <<abcde>>]");
}

// Checks to make sure insert empty char lsts work with deep copies
void Constructor4_works_empty() {

    //Create a CharLinkedList to do a deep copy of
    CharLinkedList test_list3;

    CharLinkedList test_list5(test_list3);
    assert(test_list5.size() == 0);
    assert(test_list5.toString() == "[CharLinkedList of size 0 <<>>]");
}


// Checks to see if you can correctly copy different kinds of linkedlists
void CopyOperator_works_full() {
    
    //Create a CharLinkedList to do a deep copy of
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5);

    CharLinkedList test_list('c');
    assert(test_list.size() == 1);
    
    test_list = test_list2;
    assert(test_list.size() == 5);

    assert(test_list.toString() == "[CharLinkedList of size 5 <<abcde>>]");
}

// Checks to copy an empty list
void CopyOperator_works_empty() {
    
    //Create a CharLinkedList to do a deep copy of
    CharLinkedList test_list2;

    CharLinkedList test_list('c');
    assert(test_list.size() == 1);
    
    test_list = test_list2;
    assert(test_list.size() == 0);

    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Checks to copy the same list
void CopyOperator_works_same() {
    
    //Create a CharLinkedList to do a deep copy of
    CharLinkedList test_list('c');
    assert(test_list.size() == 1);
    
    test_list = test_list;

    assert(test_list.toString() == "[CharLinkedList of size 1 <<c>>]");
}

// Checks to see that size function works by checking an empty list 
// has a size of 0 and another of size 5
void size_works() {
    CharLinkedList test_list;
    assert(test_list.size() == 0);

    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5);
    assert(test_list2.size() == 5);
}


// Checks to see if you can determine if different lists are empty or not
// correctly using isEmpty function
void isEmpty_works() {
    CharLinkedList test_list_full('d');
    CharLinkedList test_list_empty;

    assert(not (test_list_full.isEmpty()));
    assert(test_list_empty.isEmpty());
}



// Checks to see if you can make an empty list using clear function
// with different number of elements
void clear_works() {
    CharLinkedList test_list_full('g');
    test_list_full.clear();
    CharLinkedList test_list_empty;
    test_list_empty.clear();

    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list_array(array_test, 5);
    test_list_array.clear();


    assert(test_list_full.isEmpty());
    assert(test_list_empty.isEmpty());
    assert(test_list_full.toString() == "[CharLinkedList of size 0 <<>>]");
    assert(test_list_array.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Checks to see if you can make an empty list using clear function
// with different number of elements and then add onto it to make sure 
// it realocates everything correctly
void clear_works_with_adding() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list_array(array_test, 5);
    test_list_array.clear();

    assert(test_list_array.isEmpty());
    assert(test_list_array.toString() == "[CharLinkedList of size 0 <<>>]");

    test_list_array.pushAtBack('c');
    assert(test_list_array.toString() == "[CharLinkedList of size 1 <<c>>]");
}

// Check if you can use first function to get the first value or array
void first_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5);

    assert(test_list2.first() == 'a');
} 

// Testing first() error statement
void first_works_err() {
    CharLinkedList test_list_empt;
    // CharLinkedList test_list;
    bool runtime_error_thrown = false;
    std::string error_message = "";


    try {
        test_list_empt.first();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");                        
} 



// Check if you can use last function to get the last value or array
void last_works() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);

    assert(test_list2.last() == 'p');            
}

// Check if last() err is correct
void last_works_err() {
    CharLinkedList test_list_empt;
    bool runtime_error_thrown = false;
    std::string error_message = "";


    try {
        test_list_empt.last();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");            
} 



// Check if you can use elementAt function by trying to look in a full array
void elementAt_works() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);

    assert(test_list2.elementAt(2) == 'n');            
}

// Check if elementAt correctly fails for range errors
void elementAt_works_err() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);
    bool range_error_thrown = false;
    std::string error_message = "";


    try {
        test_list2.elementAt(7);
    }

    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (7) not in range [0..5)");            
} 


///////////////


// Check if toString properly converts the array of characters to a string
// if full
void toString_works_full() {
    char array_test[5] = {'w', 'x', 'y', 'z', 'a'};
    CharLinkedList test_list2(array_test, 5);

    
    assert(test_list2.toString() == "[CharLinkedList of size 5 <<wxyza>>]");
}

// Check if toString properly converts the array of characters to a string
// if empty
void toString_works_empty() {
    CharLinkedList test_list;
    
    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Check if toReverseString properly converts the list of characters to a 
// reversal of the characters as a string when full
void toReverseString_works_full() {
    char array_test[5] = {'w', 'x', 'y', 'z', 'a'};
    CharLinkedList test_list(array_test, 5);
    
    assert(test_list.toReverseString() == 
           "[CharLinkedList of size 5 <<azyxw>>]");
}

// Check if toReverseString properly converts the list of characters to a 
// reversal of the characters as a string when empty
void toReverseString_works_empty() {
    CharLinkedList test_list;

    assert(test_list.toReverseString() == "[CharLinkedList of size 0 <<>>]");
}

// Check if PushAtBack works by adding a non empty list chars
// to one's that are full
void pushAtBack_Works_full() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5);

    test_list2.pushAtBack('f');

    // Adding to a full list
    assert(test_list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
    assert(test_list2.last() == 'f');


    //Testing after we expanded once
    test_list2.pushAtBack('g');

    assert(test_list2.toString() == "[CharLinkedList of size 7 <<abcdefg>>]");
    assert(test_list2.last() == 'g');
}

// Check if PushAtBack works by adding am empty list of chars
// to one's that are full
void pushAtBack_Works_empty() {
    CharLinkedList test_list;

    test_list.pushAtBack('S');

    assert(test_list.toReverseString() == "[CharLinkedList of size 1 <<S>>]");
    assert(test_list.last() == 'S');

    // Add twice

    test_list.pushAtBack('O');


    assert(test_list.toString() == "[CharLinkedList of size 2 <<SO>>]");
    assert(test_list.last() == 'O');

}


// Check if PushAtFront works by adding to empty lists
void pushAtFront_Works_empty() {    
    CharLinkedList test_list;

    test_list.pushAtFront('x');

    assert(test_list.toString() == "[CharLinkedList of size 1 <<x>>]");
    assert(test_list.first() == 'x');

    test_list.pushAtFront('y');

    assert(test_list.toString() == "[CharLinkedList of size 2 <<yx>>]");
    assert(test_list.first() == 'y');
}

// Check if PushAtFront works by adding to full lists
void pushAtFront_Works_full() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5);

    test_list2.pushAtFront('f');

    assert(test_list2.toString() == "[CharLinkedList of size 6 <<fabcde>>]");
    assert(test_list2.first() == 'f');
}


// Check if insertAt works with empty lists at the front, back, 
// and middle
void insertAt_works_empty() {
    //Create a full and empty list
    
    CharLinkedList test_list;

    test_list.insertAt('M', 0);

    //Test empty list
    assert(test_list.toReverseString() == "[CharLinkedList of size 1 <<M>>]");
    assert(test_list.first() == 'M');
}

// Check if insertAt works with full lists at the front, back, 
// and middle
void insertAt_works_full() {
    //Create a full and empty list
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list2(array_test, 5); 

    test_list2.insertAt('x', 0);

    //Test full list in middle
    assert(test_list2.toString() == "[CharLinkedList of size 6 <<xabcde>>]");
    assert(test_list2.first() == 'x');

    //Test list at front and back
    test_list2.insertAt('x', 3);
    assert(test_list2.toString() == "[CharLinkedList of size 7 <<xabxcde>>]");
    assert(test_list2.elementAt(3) == 'x');
    test_list2.insertAt('x', 7);
    assert(test_list2.toString() == "[CharLinkedList of size 8 <<xabxcdex>>]");
    assert(test_list2.elementAt(7) == 'x');
}

//Test the error message from insert at
void insertAt_err() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);
    
    bool range_error_thrown = false;
    std::string error_message = "";


    try {
        test_list2.insertAt('c', 8);
    }

    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (8) not in range [0..5]");  
}


// Tests insertInOrder starts with empty and adds on to a full
// multiple times reepeating the same letter at some
void insertInOrder_empty(){
    CharLinkedList empty;

    empty.insertInOrder('c');
    empty.insertInOrder('b');
    empty.insertInOrder('d');
    empty.insertInOrder('r');
    empty.insertInOrder('c');
    empty.insertInOrder('f');
    empty.insertInOrder('b');

    assert(empty.toString() == "[CharLinkedList of size 7 <<bbccdfr>>]");
}



// Test popping front of a one element list
void popFromFront_works_one() {
    CharLinkedList test_list2('s');
    test_list2.popFromFront();

    assert(test_list2.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Test popping front of a full list mulptiple times
void popFromFront_works_full() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharLinkedList test_list(test_arr, 8);

    test_list.popFromFront();

    assert(test_list.toString() == "[CharLinkedList of size 7 <<bcdefgh>>]");
    
    test_list.popFromFront();
    test_list.popFromFront();
    assert(test_list.toString() == "[CharLinkedList of size 5 <<defgh>>]");
}

// Testing popFromFront error statement
void popFromFront_works_err() {
    CharLinkedList test_list_empty;
    // CharLinkedList test_list;
    bool runtime_error_thrown = false;
    std::string error_message = "";


    try {
        test_list_empty.popFromFront();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");                        
} 

// Test popping back of a one element
void popFromBack_works_empty() {
    CharLinkedList test_list2('l');
    test_list2.popFromBack();

    assert(test_list2.toString() == "[CharLinkedList of size 0 <<>>]");
}

// Test popping back of a full list
void popFromBack_works_full() {
    char test_arr[6] = {'h', 'i', 'j', 'k', 'l', 'm'};
    CharLinkedList test_list(test_arr, 6);

    test_list.popFromBack();

    assert(test_list.toString() == "[CharLinkedList of size 5 <<hijkl>>]");
    
    test_list.popFromBack();
    test_list.popFromBack();
    assert(test_list.toString() == "[CharLinkedList of size 3 <<hij>>]");
}

// Testing popFromFront error statement
void popFromBack_works_err() {
    CharLinkedList test_list_empty;
    bool runtime_error_thrown = false;
    std::string error_message = "";


    try {
        test_list_empty.popFromBack();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");                        
} 

// Testing remove at from starting ending and middle of full list
void removeAt_works_full() {
    char test_arr[7] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    CharLinkedList test_list(test_arr, 7);

    test_list.removeAt(3);
    
    test_list.removeAt(5);
    test_list.removeAt(0);
    assert(test_list.toString() == "[CharLinkedList of size 4 <<bcef>>]");
}


// Testing remove at from one element
void removeAt_works_empty() {
    CharLinkedList test_list('c');

    test_list.removeAt(0);

    assert(test_list.toString() == "[CharLinkedList of size 0 <<>>]");
}

//Test the error message from insert at
void removeAt_err() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);
    
    bool range_error_thrown = false;
    std::string error_message = "";


    try {
        test_list2.removeAt(9);
    }

    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (9) not in range [0..5)");  
}



// Testing replaceAt to replace an empty list, at the front, at the back, 
// and in the middle
void replaceAt_works() {
    char test_arr[8] = { 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's' };
    CharLinkedList test_list(test_arr, 8);

    test_list.replaceAt('a', 0);
    test_list.replaceAt('b', 3);
    test_list.replaceAt('f', 7);
    assert(test_list.toString() == "[CharLinkedList of size 8 <<amnbpqrf>>]");
}

// Testing replaceAt error message
void replaceAt_works_err() {
    char array_test[5] = {'l', 'm', 'n', 'o', 'p'};
    CharLinkedList test_list2(array_test, 5);
    
    bool range_error_thrown = false;
    std::string error_message = "";


    try {
        test_list2.replaceAt('t', 9);
    }

    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (9) not in range [0..5)");  
}

// Testing concatenate with full and empty lists and trying to concat
// themselves
void concatenate_works() {
    CharLinkedList empty_copying;

    
    char test_arr[8] = { 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's' };
    CharLinkedList testing_list(test_arr, 8);

    CharLinkedList *test_list_array = new CharLinkedList(test_arr, 8);
    CharLinkedList *empty_being_coppied = new CharLinkedList;

    // testing the full list with and empty one
    testing_list.concatenate(empty_being_coppied);
    assert(testing_list.toString() == 
            "[CharLinkedList of size 8 <<lmnopqrs>>]");
    
    // testing an empty list with itself
    empty_copying.concatenate(empty_being_coppied);
    assert(empty_copying.toString() == 
           "[CharLinkedList of size 0 <<>>]");
    
    // try empty with a full list
    empty_copying.concatenate(test_list_array);
    assert(empty_copying.toString() == 
           "[CharLinkedList of size 8 <<lmnopqrs>>]");

    // testing with itself
    test_list_array->concatenate(test_list_array);
    assert(test_list_array->toString() == 
           "[CharLinkedList of size 16 <<lmnopqrslmnopqrs>>]");

    delete test_list_array;
    delete empty_being_coppied;
}