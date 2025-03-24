// bicycles.cpp
// purpose:  Taking the parts of a bicycles and seeing how many can be made
// by:  Ian Abou-Jaoude
// date:  September 27 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

string plural(int n, string word);

int main() {
    
    //Declare the integer variable for each part that will be received by user
    
    int wheels_num, frames_num, links_num;
    
    /*Declare the integer variable for the number of bikes that will be 
    calculated*/
    
    int bikes;
    
    /*Declare the number of sets for each part that will be calculated from 
    the number of parts*/
    
    int wheels_set, frames_set, links_set;
    
    //Ask for the number of parts from user
    
    cout << "Enter the number of wheels: ";
    cin >> wheels_num;
    
    cout << "Enter the number of frames: ";
    cin >> frames_num;
    
    cout << "Enter the number of links: ";
    cin >> links_num;
    
    /*Calculate the number of sets of each part and the remaining number of 
    parts*/
    
    wheels_set = wheels_num / 2;
    frames_set = frames_num;
    links_set = links_num / 50;
    
    if (wheels_set <= frames_set and wheels_set <= links_set){
        bikes = wheels_set;
        wheels_num = wheels_num - (bikes * 2);
        frames_num = frames_num - bikes;
        links_num = links_num - (bikes * 50);
    }
    
    else if (frames_set <= wheels_set and frames_set <= links_set){
        bikes = frames_set;
        wheels_num = wheels_num - (bikes * 2);
        frames_num = frames_num - bikes;
        links_num = links_num - (bikes * 50);
    }
    
    else if (links_set <= wheels_set and links_set <= frames_set){
        bikes = links_set;
        wheels_num = wheels_num - (bikes * 2);
        frames_num = frames_num - bikes;
        links_num = links_num - (bikes * 50);
    }
    
    /*Print the number of bikes and remaining parts*/
    
    cout << "You can make " << bikes << " " << plural(bikes, "bike"); 
    cout << ". There are " << wheels_num << " " << plural(wheels_num, "wheel");
    cout << ", " << frames_num << " " << plural(frames_num, "frame");
    cout << ", " << links_num << " " << plural(links_num, "link");
    cout << " leftover." << endl;
    
    return 0;
}

/* plural
* Parameters: The word to determine (word) and the corresponding number (n) to 
the word
* Purpose:    To determine if a word is plural or not
* Returns:    The word in it's correct form (singular or plural)
*/

string plural(int n, string word){
    
    string word_out;
    
    if (n == 1){
        word_out = word;
    }
    
    else{
        word_out = word + "s";
    }
    
    return word_out;
}