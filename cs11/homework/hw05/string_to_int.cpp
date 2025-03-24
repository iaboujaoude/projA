/*
 * string_to_int.cpp
 * Program to test the string_to_int function, whose contract appears below
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * by:  Ian Abou-Jaoude
 * date:  October 18 2021
 * No bugs
 * No help
 * iabouj01
 */

#include <iostream>

using namespace std;

int string_to_int(string s);

int main()
{
    
    //Declare all variables for testing
    
    int i = 0;
    int s = 7;
    string input[s];
    int output[s];
    int correct[s] = {1236, 1100, 8, 15, 0, 90400810, 123};
    
    //Assign test values and their results from the function
            
    input[0] = "123ab6";
    input[1] = "cs11issoc00L";
    input[2] = "ericmetajisgr8";
    input[3] = "cann0L15";
    input[4] = "";
    input[5] = " 9 C0k4so00KL81L0";
    input[6] = "123";
    
    while (i < s) {
        output[i] = string_to_int(input[i]);
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


/*
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * Examples:  "123abc56"   => 12356
 *            "   2times3" => 23
 *            "help me!"   => 0
 *            ""           => 0
 */
 int string_to_int(string s){

    //Declare indexes and sizes for base cases of the loops

    int i = 0;
    int n = 0;
    int p = 0;
    int output_number = 0;
    int digit_index = 1;
    int string_size = s.length();
    int num_digits = -1;
    
    //Determine the number of digits
    
    while ( n < string_size ) {
        
        if ((s[n]) <= 58 and (s[n] >= 48)) {
            ++num_digits;
        }
        
        ++n;
    }
    
    /*Create an index for number of digits (if the int is 345 the digit 
    index would be 100)*/
    
    while ( p < num_digits ) {
        digit_index = digit_index * 10;
        p++;
    }
    
    //Create the number from the string
        
    while ( i <= string_size ) {
     
        if ((s[i]) <= 58 and (s[i] > 48)) {
            output_number = output_number + ((s[i] - 48) * digit_index);
            digit_index = digit_index / 10;
        }

        else if (s[i] == 48) {
            digit_index = digit_index / 10;
        }
             
     
        ++i;
     
    }
     
     return output_number;
 }