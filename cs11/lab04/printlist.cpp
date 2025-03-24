/*
 * CS 11 Lab 04
 * 
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *      1. read in data
 *      2. then prints out the list with line numbers using another loop
 *
 *   Exercises:
 *    [a] print the list in reverse
 *    [b] change loop to print out only the birthdays in October
 *    [c] after printing out the October bdays, print a count of how many
 *    [d] change to print the count for each month, not the actual bdays
 *    [e] use a function to do [c]
 *    [f] EXTRA: print which month has the MOST birthdays
 * 
 * Modified by:
 *
 */
#include <iostream>

using namespace std;

const int CAPACITY = 999;         // change as needed

int main() 
{
        int bdays[CAPACITY];    // birthday data
        //int used;               // number of spaces used so far
        int pos;                // position in array

        // read in CAPACITY values
        pos = 0;
        while (pos <= CAPACITY) {
                cin >> bdays[pos];
                pos++;
        }
        //used = pos;             // position is how far we got

        // now to print out the list
        // you can switch to a for loop if you know about those
        pos = CAPACITY;
        int count = 0;
        int monthGet = 100;
        string months[12] = {"January", "Febuary", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", 
        "Decembers"};
        int monthsCount = 0;

        while (monthsCount <= 12){
        
            count = 0;
            
            pos = CAPACITY;
            
            while (pos >= 0) {
                    if (bdays[pos] >= monthGet and (bdays[pos]) < monthGet 
                    + 100){
                        count++;
                    }
                    
                    --pos;
                }
                
            cout << "The number of " << months[monthsCount];
            cout << " birthdays are: " << count; 
            cout << endl;
            
            monthGet = monthGet + 100;
            monthsCount++;
            
        }
        
        return 0;
}
