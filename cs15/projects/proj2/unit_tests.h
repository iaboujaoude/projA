/*
 *  unit_tests.h
 *  Ian Abou-Jaoude
 *  Feb 27
 *
 *  CS 15 Project 2
 *
 *  Testing the implementation of helper classes for RPNCalc (DatumStack)
 *
 */

#include "DatumStack.h"
#include "Datum.h"
#include "RPNCalc.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

// Testing the default constructor
void default_constructor_works() {
    DatumStack empty_stack;

    assert(empty_stack.isEmpty());
    assert(empty_stack.size() == 0);

    Datum data(1);
    empty_stack.push(data);
    assert(empty_stack.top().getInt() == 1);
}

// Testing the array constructor
void array_constructor_works() {
    Datum data1(1);
    Datum data2(2);
    Datum data3(3);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack (array ,3);

    assert(not arr_stack.isEmpty());
    assert(arr_stack.size() == 3);
    assert(arr_stack.top().getInt() == 3);
    arr_stack.pop();
    assert(arr_stack.top().getInt() == 2);
    arr_stack.pop();
    assert(arr_stack.top().getInt() == 1);
    arr_stack.pop();
    assert(arr_stack.isEmpty());
}

// Testing the array constructor with empty array
void arrayEmpty_constructor_works() {
    Datum arr[0] = {};
    
    DatumStack empty_stack(arr, 0);

    assert(empty_stack.isEmpty());
}


// Testing clear function with empty stack
void clear_works() {
    //testing clear with empty stack
    Datum arr[0] = {};
    
    DatumStack empty_stack(arr, 0);

    assert(empty_stack.isEmpty());
    empty_stack.clear();
    assert(empty_stack.isEmpty());


    //Test with a full stack
    Datum data1(1);
    Datum data2(2);
    Datum data3(3);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack (array ,3);
    empty_stack.clear();
    assert(empty_stack.isEmpty());
}

// Testing top function
void top_works() {
    Datum data1(4);
    Datum data2(5);
    Datum data3(6);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack(array ,3);

    // Testing top for each part of the data ints
    assert(not arr_stack.isEmpty());
    assert(arr_stack.size() == 3);
    assert(arr_stack.top().getInt() == 6);
    arr_stack.pop();
    assert(arr_stack.top().getInt() == 5);
    arr_stack.pop();
    assert(arr_stack.top().getInt() == 4);
}

// checks errors for top func
void top_emptyErr_works() {
    DatumStack empty_stack;
    string error_message;
    bool runtime_error_thrown = false;

    try {
        empty_stack.top();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "empty_stack"); 
}

// tests size function
void size_works() {
    Datum data1(4);
    Datum data2(5);
    Datum data3(6);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack(array ,3);

    DatumStack empty_stack;

    assert(arr_stack.size() == 3);
    assert(empty_stack.size() == 0);

}

// tests pop function on full stack
void pop_works() {
    Datum data1(4);
    Datum data2(5);
    Datum data3(6);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack(array ,3);

    arr_stack.pop();

    assert(arr_stack.top().getInt() == 5);
}

// tests pop function with error of empty stack
void pop_error_works() {
    DatumStack empty_stack;
    string error_message;
    bool runtime_error_thrown = false;

    try {
        empty_stack.pop();
    }

    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "empty_stack"); 
}

// tests push function on empty stack
void push_empty_workds() {
    DatumStack empty_stack;
    Datum data(8);

    empty_stack.push(data);

    assert(empty_stack.top().getInt() == 8);
    assert(empty_stack.size() == 1);
}


// tests push function on full stack
void push_full_workds() {
    Datum data1(4);
    Datum data2(5);
    Datum data3(6);

    Datum array[] = {data1, data2, data3};
    
    DatumStack arr_stack(array ,3);

    Datum data(8);

    arr_stack.push(data);
    assert(arr_stack.top().getInt() == 8);
    assert(arr_stack.size() == 4);
}
