// guess.cpp
// purpose: A game for the user to guess a randomly generated number from 5-15
// by:  Ian Abou-Jaoude
// date:  September 27 2021
// No bugs
// No help
// iabouj01

#include <iostream>

#include <cstdlib>
#include <ctime>

using namespace std;

int determine(int random_num, int guess, int n);

int main()
{
        srand(time(nullptr));

        //Initialize the guess variable that the user will input
        
        int guess;

        //Generate the random number from 5-15
        
        int bigrand = rand();
        int boundedrand = bigrand % 11;
        int random_num = boundedrand + 5;
        
        //Declare the number of tries
        
        int tries = 0;
        
        //Ask for the guess from user
        
        cout << "Enter a guess: ";
        cin >> guess;
        
        //Determine the result from the guess
        
        determine(random_num, guess, tries);
        
        //Add to the number of tries
        
        tries++;
        
        //Repeat twice if the user did not get the answer right answer twice
        
        if(guess != random_num){
            cin >> guess;
            determine(random_num, guess, tries);
            tries++;
        }
        
        if(guess != random_num){
            cin >> guess;
            determine(random_num, guess, tries);
        }
        
        return 0;
}

/* determine
* Parameters: the random number generated (random_num), the user's guess 
(guess), and the number of attempts that the user has tried (tries)
* Purpose     To determine if the user got lower higher or guessed right
* Effects:    Print a message depending on the guess
*/

int determine(int random_num, int guess, int tries){
    
    /*Based on if the guess is higher, lower, or equal to the generated number
    or if the number of tries have surpassed 2 we print appropriate statements
    */
    
    if(tries != 2 and guess != random_num){
        if(guess > random_num){
            cout << "That was too high. Enter a guess: ";
        }
        
        else if(guess < random_num){
            cout << "That was too low. Enter a guess: ";
        }
    }
    
    else if(guess == random_num){
        cout << "You guessed it! Good job!" << endl;
    }
    
    else{
        cout << "The number was " << random_num << ". Better luck next time!"; 
        cout << endl;
    }
        
    return 0;
}