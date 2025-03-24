/*
 *  stringProcessing.h
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 10, 2022
 *
 *  COMP 15 - Proj 3
 *
 *  Interface for the stringProcessing class.
 *
 */

#ifndef STRING_PROCESSING_H
#define STRING_PROCESSING_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

    string stripNonAlphaNum(string input);

    int minIndex(string word);
    int maxIndex(string word);
         
#endif
