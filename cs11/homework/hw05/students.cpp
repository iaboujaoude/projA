/*
* COMP11
* Spring 2021
* students.cpp
* by:  Ian Abou-Jaoude
* date:  October 18 2021
* No bugs
* No help
* iabouj01
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
    
    /*Declare and recieve the student's id and declare the index we will find 
    for the student*/
    
    int user_input;
    cin >> user_input;
    int student_index;
    
    //Initialize the Student struct we will be finding
    
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
    
    //Call functions based on the user's input
    
    student_index = find_student(user_input, students, TOTAL_STUDENTS);
    
    print_student(student_index, students);

    return 0;
}

/* find_student
* Parameters: users entered id, the created Student struct, the number of 
students in the struct
* Purpose:    To find the student index from the users id input
* Effects:    Returnst the index of the desired student
*/

int  find_student(int id, Student students[], int num_students) {
    int i;
    int student_i;
    bool found = false;

    //Find the correct student and take their index in the struct

    for (i = 0; i < num_students; ++i) {
        
        if (id == students[i].id) {
            student_i = i;
            found = true;
        }
        
    }
    
    //If the loop runs without finding a match set the index to -1
    
    if (!found) {
        student_i = -1;
    }
    
    return student_i;
}

/* print_student
* Parameters: The index of the student that was found, the student struct
* Purpose:    Print the student's info that the user is looking for
* Effects:    Prints the first name, last initial, and gpa of the student
*/

void print_student(int index, Student students[]) {
    
    //Print the students information based on the index found
    
    cout << "Name: " << students[index].firstName << " " << 
    students[index].lastInitial << endl;
    
    cout << "GPA: " << students[index].gpa << endl;
} 