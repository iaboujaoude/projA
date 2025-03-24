// make_change.cpp
// purpose:  to receive a number and break it down into change
// by:  Ian Abou-Jaoude
// date:  September 20 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int main() {
    
    /*Declare variables to calculate with*/
    
    int change;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    /*Ask for and recieve user input for the change*/
    
    cout <<"Amount of change in cents: ";
    cin >> change;
    
    /*Determining how many of each coins will be needed by using division and 
    remainders*/
    
    if (change >= 25){
        quarters = change / 25;
        change = change % 25;
    }
    
    if (change >= 10){
        dimes = change / 10;
        change = change % 10;
    }
    
    if (change >= 5 ){
        nickels = change / 5;
        change = change % 5;
    }
    
    if (change <= 5){
        pennies = change;
    }
   
   //Printing the results
    
    cout << quarters << " quarters, " << dimes << " dimes, ";
    cout << nickels << " nickels, " << pennies << " pennies" << endl;
    
    return 0;
    
}