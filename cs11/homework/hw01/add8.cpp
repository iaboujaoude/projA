// add8.cpp
// purpose:  adding 8 numbers as given by the user
// by:  Ian Abou-Jaoude
// date:  September 20 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int main() {
    
    /*Declaring all 8 float variables that we will ask to be initialized by the
    user and added together*/
    
    float num1;
    float num2;
    float num3;
    float num4;
    float num5;
    float num6;
    float num7;
    float num8;
    
    //Asking for all 8 variables to store them and then add them together after
    
    cout << "Enter a floating point number: ";
    cin >> num1;
    cout << "Enter a floating point number: ";
    cin >> num2;
    cout << "Enter a floating point number: ";
    cin >> num3;
    cout << "Enter a floating point number: ";
    cin >> num4;
    cout << "Enter a floating point number: ";
    cin >> num5;
    cout << "Enter a floating point number: ";
    cin >> num6;
    cout << "Enter a floating point number: ";
    cin >> num7;
    cout << "Enter a floating point number: ";
    cin >> num8;
    
    /*Printing the sum and the statement on the same line*/
    
    cout << "The sum is: " << num1+num2+num3+num4+num5+num6+num7+num8 << endl;
    
    return 0;
}