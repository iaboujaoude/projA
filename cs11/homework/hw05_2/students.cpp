/*
* COMP11
* Spring 2021
* students.cpp
*
* [ Fill in the header per the style guide ]
*/

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;


// Function Prototypes
int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);


int main() {

    // declare and initialize array of 
    // student structs of size TOTAL_STUDENTS
    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };

    // YOUR CODE GOES HERE

    return 0;
}

// REMOVE THESE COMMENT LINES AND REPLACE WITH
// YOUR FUNCTION CONTRACTS AND IMPLEMENTATIONS
// FOR  find_student AND print_student
