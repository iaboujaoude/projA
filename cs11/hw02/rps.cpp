// rps.cpp
// purpose:  To play rock paper scissors against the computer
// by:  Ian Abou-Jaoude
// date:  September 27 2021
// No bugs
// No help
// iabouj01

#include <iostream>

#include <cstdlib>
#include <ctime>

using namespace std;
 
int main()
{

        srand(time(nullptr));

        //Generate a number from 0-2

        int bigrand = rand();
        int computer_choice_num = bigrand % 3;
        
        /*Declare the variables that the user will initialize and we will use 
        determine the value of the input*/
        
        char user_choice;
        int user_choice_num;
        string computer_choice;
        
        /*Ask for user input and receive it and edit it to make it lowercase*/
        
        cout << "Enter rock (r), paper (p), or scissors (s): ";
        cin >> user_choice;
        
        user_choice = tolower(user_choice);
        
        /*Assign the choice of the computer a string value dependant on the 
        number generated*/
        
        if(computer_choice_num == 0){
            computer_choice = "rock";
        }
        
        else if(computer_choice_num == 1){
            computer_choice = "paper";
        } 
        
        else if(computer_choice_num == 2){
            computer_choice = "scissors";
        }
        
        //Assign a number to the users choice
                
        if(user_choice == 'r'){
            user_choice_num = 0;
        }
        
        else if(user_choice == 'p'){
            user_choice_num = 1;
        } 
        
        else if(user_choice == 's'){
            user_choice_num = 2;
        }
        
        /*Determine if the user won lost or tie and print the appropriate 
        statement*/
        
        if(user_choice_num == computer_choice_num){
            cout << "It's a tie. The computer also chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 0 and computer_choice_num == 1){
            cout << "You lost. The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 0 and computer_choice_num == 2){
            cout << "You won! The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 1 and computer_choice_num == 2){
            cout << "You lost. The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 1 and computer_choice_num == 0){
            cout << "You won! The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 2 and computer_choice_num == 0){
            cout << "You lost. The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        else if(user_choice_num == 2 and computer_choice_num == 1){
            cout << "You won! The computer chose " << computer_choice;
            cout << "." << endl;
        }
        
        return 0;
}
