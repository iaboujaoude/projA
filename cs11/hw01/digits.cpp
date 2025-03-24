// digits.cpp
// purpose: report number of digits in an integer
// modified by: Ian Abou-Jaoude
// date: September 19 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int main() {
        
        //Declare our int variable that will be initialized by the user input
        
        int input;

        //Recieve from the user input a number
        
        cout << "Enter a number: ";
        cin  >> input;
        
        /*An if statement to diiferentiate between positive and negative 
        values, 0 is included in the first if statement because the
        output for 0 is the same as any positive digit less than 10*/

        if (input >= 0) {
                
                /*Determine the number of digits and print them*/
                
                if (input >= 100) {
                        cout << "input has three or more digits" << endl;
                } else if (input >= 10 and input < 100) {
                        cout << "input has two digits" << endl;
                } else {
                        cout << "input has one digit" << endl;
                }
                
        } else if (input < 0) {
                
                /*Determine how many digits in the number and print them with 
                its sign*/
                
                if (input <= -100) {
                        cout << "input has three or more digits" << endl;
                        cout << "and input is negative" << endl;
                } else if ( input <= -10 and input > -100) {
                        cout << "input has two digits" << endl;
                        cout << "and input is negative" << endl;
                } else {
                        cout << "input has one digit" << endl;
                        cout << "and input is negative" << endl;
                }
        }

        return 0;
}
