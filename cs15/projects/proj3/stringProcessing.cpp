/*
 *  stringProcessing.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 10, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Implementation of the stringProcessing class which allows for a 
 *  string to be isolated from non-alphanumeric chars
 *  Important for the search of words.
 *
 */

#include "stringProcessing.h"
#include <iostream>
#include <string>

using namespace std;

/* strip alpha num
 *    Purpose: returns properly stripped string from a given array 
 *             of characters
 * Parameters: a string to strip
 *    Returns: a stripped string
 *    Effects: None
 */
string stripNonAlphaNum(string input) {
    //If there are no characters in the string
    if (minIndex(input) == -1) {
        return "";
    }

    //Return correct substring
    return input.substr(minIndex(input), maxIndex(input) - minIndex(input));
}

/* min index
 *    Purpose: get the index of the first alphanumeric 
 *             character in a given string
 * Parameters: a string to evaluate
 *    Returns: an interger serving as the index of the first 
 *             alphanumeric character in the given string
 *    Effects: None
 */
int minIndex(string word) {
    //traverse array until the first alphanumeric character
    int size = (int) word.size();

    for (int i = 0; i < size; i++) {
        if (isalnum(word[i])) {
            return i;
        }
    }

    //Return -1 if no alphanumeric characters are found
    return -1;
}

/* max index
 *    Purpose: get the index of the last alphanumeric 
 *             character in a given string
 * Parameters: a string to evaluate
 *    Returns: an interger serving as the index of the last 
 *             alphanumeric character in the given string
 *    Effects: None
 */
int maxIndex(string word) {

    //traverse array until the last alphanumeric character
    int maxI = minIndex(word);
    int size = (int) word.size();
    
    for (int i = minIndex(word) + 1; i < size; i ++) {
        if (isalnum(word[i])) {
            maxI = i;
        }
    }

    //Add 1 to the return value to include final character
    return maxI + 1;
}


