/*
 * int_to_string.cpp
 * Program to test the int_to_string function, whose contract appears below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * by:  Ian Abou-Jaoude
 * date:  October 18 2021
 * No bugs
 * No help
 * iabouj01
 */

#include <iostream>

using namespace std;

string int_to_string(int num);

int main()
{
    //Declare all variables for testing
    
    int i = 0;
    int s = 11;
    
    int input[s];
    string output[s];
    
    //Assign test values and their results from the function
    
    input[0] = -3;        
    input[1] = -12;
    input[2] = 0;
    input[3] = 304045070;
    input[4] = -304045070;
    input[5] = 10101902;
    input[6] = 9999;
    input[7] = -9999;
    input[8] = 100000001;
    input[9] = -100000001;
    input[10] = 5;
    
    string correct[s] {"-3", "-12", "0", "304045070", "-304045070", 
    "10101902", "9999", "-9999", "100000001", "-100000001", "5"};
    
    while (i < s) {
        output[i] = int_to_string(input[i]);
        i++;
    }
    
    //Compare the outputs to our desired answers
    
    i = 0;
    
    while (i < s) {
        cout << "TESTING: " << input[i] << endl;
        if (output[i] == correct[i]) {
            cout << "SUCCESS: " << output[i] << endl;
        }
        else {
            cout << "FAILURE: " << output[i] << endl;
        }
        
        ++i;
    }
    
    return 0; 
}


/* int_to_string
* Parameters: The given number
* Purpose     To convert the number into a string
* Effects:    Takes a number and outputs a string
*/

string int_to_string(int num) {
    
    //Declare all variables being used in function to create the string
    
    int i;
    int p = 1;
    float power = 0.1;
    int number_of_digits = 0;
    int num_edited = num;
    bool negative = false;
    string output_string = "";
    
    //Determine if num is negative
    
    if (num < 0) {
        negative = true;
        num_edited = num_edited * -1;
    }
    
    /*Find the number of digits and take the power of 10 minus 1 of 
    that number and set it equal to p*/
    
    if (num_edited != 0) {
        
        for (i = 1; num_edited >= i;) {
            ++number_of_digits;
            i = i * 10;
            power = power * 10;
        }
        
    }
    
    else {
        number_of_digits = 1;
        power = 10;
    }
    
    p = power;
    
    /*Assign the variables used in the base cases depending on if the number
    is negative or not*/
    
    if (negative) {
        
        //Add an extra "digit" for the negative sign in front
        
        ++number_of_digits;
        i = 1;
    }
    
    else {
        i = 0;
    }
    
    char char_in_string[number_of_digits];
    
    if (negative) {
        
        //Add then negative sign to the front of the string for negative num's
        
        char_in_string[0] =  '-';
        output_string = char_in_string[0];
    }
    
    /*Traverse through the array of characters and add to the string each 
    character*/
    
    while (i < number_of_digits) {
        
        char_in_string[i] = (num_edited / p) + 48;
        output_string = output_string + char_in_string[i];
        
        num_edited = num_edited - ((num_edited / p) * p);
        p = p / 10;
        ++i;
    }
    
    return output_string;
}