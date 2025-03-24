/*
 * unit_tests.h
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * Instructions for using testing framework can be found at in CS 15's lab
 * 1 -- both in the spec and in the provided ArrayList_tests.h and Makefile.
 * More in-depth information for those who are curious as to how it works can
 * be found at http://www.github.com/mattrussell2/unit_test.
 */

#include "CharArrayList.h"
#include <cassert>
#include <iostream>

using namespace std;

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */



//Constructor tests: Tests to see if all constructors works correctly

// Checks to make sure default constructor is empty
void Constructor1_works() {
    CharArrayList test_list;
    assert(test_list.size() == 0);
}

// Checks to make sure insert one element constructor works
void Constructor2_works() {
    CharArrayList test_list2('h');
    assert(test_list2.size() == 1);
}

// Checks to make sure insert array constructor works
void Constructor3_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list3(array_test, 5);

    assert(test_list3.size() == 5);
}

// Checks to make sure insert array lst constructor works (put array list in
// perameter)
void Constructor4_works() {

    //Create a CharArraylist to do a deep copy of
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list3(array_test, 5);

    CharArrayList test_list5(test_list3);
    assert(test_list5.size() == 5);
}
// Checks to see if you can correctly copy different kinds of arrayslists
void CopyOperator_works() {
    
    //Create a CharArraylist to do a deep copy of
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);

    CharArrayList test_list('c');
    assert(test_list.size() == 1);
    
    test_list = test_list2;
    assert(test_list.size() == 5);
}

// Checks to see that size function works by checking an empty array 
// has a size of 0 and another of size 5
void size_works() {
    CharArrayList test_list;
    assert(test_list.size() == 0);


    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);
    assert(test_list2.size() == 5);
}

// Checks to see if you can determine if different lists are empty or not
// correctly using isEmpty function
void isEmpty_works() {
    CharArrayList test_list_full('g');
    CharArrayList test_list_empt;

    assert(not (test_list_full.isEmpty()));
    assert(test_list_empt.isEmpty());
}

// Checks to see if you can make an empty array using clear function
void clear_works() {
    CharArrayList test_list_full('g');
    test_list_full.clear();
    CharArrayList test_list_empt;

    assert(test_list_full.isEmpty());
    assert(test_list_empt.isEmpty());
}


// Check if you can use first function to get the first value or array
void first_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);

    assert(test_list2.first() == 'a');
    
    // The following code is to test firt() of an empty ArrayList
            
            // CharArrayList test_list_empt;
            // test_list_empt.first();
            
} 

// Check if you can use last function to get the last value or array
void last_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);

    assert(test_list2.last() == 'e');
    
    // The following code is to test firt() of an empty ArrayList
            
            // CharArrayList test_list_empt;
            // test_list_empt.last();
            
}

// Check if you can use elementAt function by trying to look in a full array
void elementAt_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);

    assert(test_list2.elementAt(2) == 'c');
    
    // The following code is to test firt() of an empty ArrayList
            
            // test_list2.elementAt(5);
            // test_list2.elementAt(7);
            // test_list2.elementAt(-3);
            
}

// Check if toString properly converts the array of characters to a string
void toString_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);
    CharArrayList test_list;
    
    assert(test_list2.toString() == "[CharArrayList of size 5 <<abcde>>]");
    assert(test_list.toString() == "[CharArrayList of size 0 <<>>]");
}

// Check if toReverseString properly converts the array of characters to a 
// reversal of the characters as a string
void toReverseString_works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);
    
    CharArrayList test_list;

    assert(test_list2.toReverseString() == 
           "[CharArrayList of size 5 <<edcba>>]");
    assert(test_list.toReverseString() == "[CharArrayList of size 0 <<>>]");

}

// Check if PushAtBack works by adding to empty and not empty arrays chars
// to one's that are full
void pushAtBack_Works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);
    
    CharArrayList test_list;

    test_list.pushAtBack('M');
    test_list2.pushAtBack('f');

    // Adding to full
    assert(test_list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
    assert(test_list2.last() == 'f');


    assert(test_list.toReverseString() == "[CharArrayList of size 1 <<M>>]");
    assert(test_list.last() == 'M');

    //Test after we expanded once
    test_list2.pushAtBack('g');

    assert(test_list2.toString() == "[CharArrayList of size 7 <<abcdefg>>]");
    assert(test_list2.last() == 'g');
}

// Check if PushAtFront works by adding to empty and not empty arrays and to
// some that are full
void pushAtFront_Works() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5);
    
    CharArrayList test_list;

    test_list.pushAtFront('M');
    test_list2.pushAtFront('x');

    // Adding to full
    assert(test_list2.toString() == "[CharArrayList of size 6 <<xabcde>>]");
    assert(test_list2.first() == 'x');

    // Adding to empty
    assert(test_list.toReverseString() == "[CharArrayList of size 1 <<M>>]");
    assert(test_list.first() == 'M');
}


// Check if insertAt works with empty and full arrays at the front, back, 
// and middle
void insertAt_works() {
    //Create a full and empty list
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list2(array_test, 5); 
    
    CharArrayList test_list;

    test_list.insertAt('M', 0);
    test_list2.insertAt('x', 0);

    //Test full list in middle
    assert(test_list2.toString() == "[CharArrayList of size 6 <<xabcde>>]");
    assert(test_list2.first() == 'x');

    //Test empty list
    assert(test_list.toReverseString() == "[CharArrayList of size 1 <<M>>]");
    assert(test_list.first() == 'M');

    //Test list at front and back
    test_list2.insertAt('x', 3);
    assert(test_list2.toString() == "[CharArrayList of size 7 <<xabxcde>>]");
    assert(test_list2.elementAt(3) == 'x');
    test_list2.insertAt('x', 7);
    assert(test_list2.toString() == "[CharArrayList of size 8 <<xabxcdex>>]");
    assert(test_list2.elementAt(7) == 'x');

    // Following code is to test failure of outside bounds
    // test_list2.insertAt('A', 10);
}


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {

    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
}

// Tests insertion into front, back, and middle of a larger list.
void insertAt_front_back_middle() {
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        // insertAt middle
        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() == 
        "[CharArrayList of size 9 <<abczdefgh>>]");

        // insertAt front
        test_list.insertAt('y', 0);

        assert(test_list.size() == 10);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() == 
        "[CharArrayList of size 10 <<yabczdefgh>>]");

        // insertAt back
        test_list.insertAt('x', 10);

        assert(test_list.size() == 11);
        assert(test_list.elementAt(10) == 'x');
        assert(test_list.toString() == 
        "[CharArrayList of size 11 <<yabczdefghx>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}




// Tests insertInOrder with empty, full, repeating letters, at first and 
// at last
void insertInOrder_empty(){
    CharArrayList empty;

    // Placing them in this order allows for each mentioned test case to be
    // hit
    empty.insertInOrder('a');
    empty.insertInOrder('d');
    empty.insertInOrder('e');
    empty.insertInOrder('c');
    empty.insertInOrder('b');
    empty.insertInOrder('b');
    empty.insertInOrder('e');

    assert(empty.toString() == "[CharArrayList of size 7 <<abbcdee>>]");
}



// Test popping front of an empty, full, array with only one, and multiple 
// times
void popFromFront_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    CharArrayList test_list2('A');
    test_list.popFromFront();
    test_list2.popFromFront();


    assert(test_list.toString() == "[CharArrayList of size 7 <<bcdefgh>>]");
    assert(test_list2.toString() == "[CharArrayList of size 0 <<>>]");
    
    test_list.popFromFront();
    test_list.popFromFront();
    assert(test_list.toString() == "[CharArrayList of size 5 <<defgh>>]");

    // The following code is to test error output of popping from empty array
    CharArrayList empty;
    // empty.popFromFront();
}

// Test popping back of an empty, full, array with only one, and multiple 
// times
void popFromBack_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    CharArrayList test_list2('A');
    test_list.popFromBack();
    test_list2.popFromBack();


    assert(test_list.toString() == "[CharArrayList of size 7 <<abcdefg>>]");
    assert(test_list2.toString() == "[CharArrayList of size 0 <<>>]");
    
    test_list.popFromBack();
    test_list.popFromBack();
    assert(test_list.toString() == "[CharArrayList of size 5 <<abcde>>]");

    // The following code is to test error output of popping from empty array
    CharArrayList empty;
    // empty.popFromBack();
}

// Testing remove at to make sure I can remove at the start, end, one element
// and fails correctly for an empoty array
void removeAt_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    CharArrayList test_list2('A');
    test_list.removeAt(2);
    test_list2.removeAt(0);


    assert(test_list.toString() == "[CharArrayList of size 7 <<abdefgh>>]");
    assert(test_list2.toString() == "[CharArrayList of size 0 <<>>]");
    
    test_list.removeAt(6);
    test_list.removeAt(0);
    assert(test_list.toString() == "[CharArrayList of size 5 <<bdefg>>]");

    // The following code is to test error output of popping from empty array
    CharArrayList empty;
    // empty.popFromBack();
}



// Testing replaceAt to replace an empty list, at the front, at the back, 
// and in the middle
void replaceAt_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    test_list.replaceAt('x', 0);
    test_list.replaceAt('y', 3);
    test_list.replaceAt('z', 7);
    assert(test_list.toString() == "[CharArrayList of size 8 <<xbcyefgz>>]");


    // This code has been commented out to test for a case where the index is
    // out of range
    //test_list.replaceAt('x', 19);
}

// Testing concatenate with empty lists, lists with itself, and different 
// orders
void concatenate_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    CharArrayList *test_list2 = new CharArrayList(test_arr, 8);
    CharArrayList *empty_to_be_coppied = new CharArrayList;
    CharArrayList empty_to_coppy;

    // test with full and empty
    test_list.concatenate(empty_to_be_coppied);
    assert(test_list.toString() == "[CharArrayList of size 8 <<abcdefgh>>]");
    
    // test with empty and empty
    empty_to_coppy.concatenate(empty_to_be_coppied);
    assert(empty_to_coppy.toString() == "[CharArrayList of size 0 <<>>]");
    
    // test with empty and full
    empty_to_coppy.concatenate(test_list2);
    assert(empty_to_coppy.toString() == 
           "[CharArrayList of size 8 <<abcdefgh>>]");

    // test with self
    test_list2->concatenate(test_list2);
    assert(test_list2->toString() == 
           "[CharArrayList of size 16 <<abcdefghabcdefgh>>]");

    delete test_list2;
    delete empty_to_be_coppied;
}

// Testing shrink with an empty list and full list and that after using shrink
// the contents don't change
void shrink_works() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);
    
    test_list.shrink();
    assert(test_list.toString() == "[CharArrayList of size 8 <<abcdefgh>>]");

    CharArrayList empty;
    empty.shrink();
    assert(empty.toString() == "[CharArrayList of size 0 <<>>]");
}    