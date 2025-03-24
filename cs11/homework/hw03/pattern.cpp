// pattern.cpp
// purpose:  Print a pattern using recursion
// by:  Ian Abou-Jaoude
// date:  October 4 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

void horizontalPattern(string st1, string st2, int i);
void verticalPattern(string st1, string st2, int i);

int main(){
    
    /*Declare the variables that we will be taking from the user*/
    
    string st1, st2;
    int i = 0;
    
    /*Receive and assing the variables the user input*/
    
    cin >> st1 >> st2 >> i;
    
    /*Call the pattern function with the variables given by the user*/
    
    verticalPattern(st1, st2, i);
    
    return 0;
}

/* horizontalPattern
* Parameters: The first string entered by the user (st1), the second string 
entered by the user (st2), i which is 0 everytime
* Purpose     To repeat the strings entered by the user in only one line
* Effects:    It prints the strings each 5 times back to back
*/

void horizontalPattern(string st1, string st2, int i){
    
    /*Call the function over and over as long as i is greater than -5 and 
    decrement i by one each time to print the strings 5 times*/
    
    if(i > -5){
        cout << st1 << st2;
        i--;
        horizontalPattern(st1, st2, i);
    }
    
    //When we no longer want to print the strings we create a new line
    
    else{
        cout << endl;
    }
}

/* verticalPattern
* Parameters: The first string entered by the user (st1), the second string 
entered by the user (st2), and the number of lines we want to print(i)
* Purpose     To repeat the horizontalPattern multiple times to make it on 
more than one line
* Effects:    It prints the strings each 5 times back to back in as many lines 
as the user entered
*/

void verticalPattern(string st1, string st2, int i){
    
    //Repeat the function over for as many times as the number i
    
    if(i > 0){
        
        //Print the lines horizontally first
        
        horizontalPattern(st1, st2, 0);
        
        /*Decrement i by one to compare to the base case to reach the right 
        number of lines*/
        
        i--;
        
        //Call the same function we're defining in a new output line
        
        verticalPattern(st2, st1, i);
    }
}   