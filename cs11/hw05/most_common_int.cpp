// most_common_int.cpp
// purpose:  Find the most common integer of an array
// by:  Ian Abou-Jaoude
// date:  October 4 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int most_common_int(int numbers[], int length);

int main(){
    
    //Declare all variables for testing
    
    int i = 0;
    int s = 6;
    int l = 8;
    int output[s];
    
    //Assign test values and their results from the function
    
    int input[s][l] = { 
        {3, 4, 4, 3, 2, 3, 4, 4}, 
        {-12, 3, 4, -2, -12, 3, -2, 0}, 
        {80, -74, 74, 80, 74, -74, 200, 200}, 
        {0, 0, -1, -1, 0, -1, 0, -1},
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {6, 1, 2, 3, 4, 5, 0, 7} 
    };

    int correct[s] {4, -12, -74, -1, 0, 0};
    
    while (i < s) {
        output[i] = most_common_int(input[i], l);
        i++;
    }
    
    //Compare the outputs to our desired answers
    
    i = 0;
    int n = 0;
    
    while (i < s) {
        
        cout << "TESTING: [";
        
        for (n = 0; n < l; ++n) {
            if (n < l-1) {
                cout << input[i][n] << ", ";
            }
            else {
                cout << input[i][n] << "]";
            }
        }
        
        cout << endl;
        
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

/* most_common_int
* Parameters: The given array and it's length
* Purpose     To find the most common number
* Effects:    Returns the number that appears the most often
*/

int most_common_int(int numbers[], int length){
    
    //Declare variables that will be used throughout the program
    
    int i = 0;
    int n = 0;
    bool unique = true;
    int p = 0;
    int a = 0;
    int greatest_i = 0;
    int count = 0;
    
    int unique_int1[length];
    
    //Create an array with all the unique numbers
    
    while (i < length) {
        n = i - 1;  
        unique = true;
      
        while (n >= 0) {
            if (numbers[n] == numbers[i]) {
                unique = false;
            }
            --n;
        }
        
        if (unique) {
            unique_int1[p] = numbers[i];
            ++a;
        }
        
        if (!unique) {
            --p;
        }
        
        p++;    
        i++;
    }
    
    int unique_int2[a];
    int num_count[a];
    i = 0;
    
    while (i < a) {
        unique_int2[i] = unique_int1[i];
        ++i;
    }
    
    //Count how many times the unique numbers are found
    
    i = 0;
    n = 0;
    
    while (i < a) {
        n = 0;
        count = 0;
        
        while (n < length) {
            if (unique_int2[i] == numbers[n]) {
                ++count;
            }
            
            ++n;
        }
        
        num_count[i] = count;
        ++i;
    }
    
    /*Determine the index with the highest count and return the corresponding 
    unique number*/
    
    n = 1;
    bool equal_co = false;
    bool less_val = false;
    
    while (n < a) {
        equal_co = false;
        less_val = false;
    
        if (num_count[greatest_i] == num_count[n]) {
            equal_co = true;
        }
        
        if (unique_int2[greatest_i] > unique_int2[n]) {
            less_val = true;
        }
        
        if ((num_count[greatest_i] < num_count[n]) or (equal_co and less_val)) {
            greatest_i = n;
        }
        
        ++n;
    }
    
    return unique_int2[greatest_i];
}