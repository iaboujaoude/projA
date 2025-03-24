/*
 *  stringProcessingTest.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 10, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Test file for the implementation of the stringProcessing class.
 *
 */

// #include "stringProcessing.h"
// #include <iostream>

// using namespace std;

// int main() {
//     //Initialize arrays with various edge cases as input and expected output
//     int length = 13;
//     string input[length] = {"Elijah", "elijah", "e", "E", 
//                             "*!@#$%^&*()**#j@%#^&*", "./*(Elijah",
//                             "elijah*/?", "@#$%^!&*()#(*&*#(?<>?<",
//                             "e*", "*e", "%^&#eli./@jah<>:", 
//                             "eli:>,:}j,.a./*h",
//                             "&%^eli./jah<>"};
//     string expectedOUT[length] = {"Elijah", "elijah", "e", "E", "j", 
//                                   "Elijah",
//                                   "elijah", "", "e", "e", "eli./@jah", 
//                                   "eli:>,:}j,.a./*h", "eli./jah"};
//     bool test = true;

//     //Traverse arrays, ensuring that the output of our implementation 
//     //of stringProcessing matches the expected output
//     for (int i = 0; i < length; i++) {
//         if (stripNonAlphaNum(input[i]) != expectedOUT[i]) {
//             test = false;
//             cout << "failed at: " << i;
//             cout << "it was: " << stripNonAlphaNum(input[i]) << endl;
//         }
//     }

//     //Print results of tests
//     if (test) {
//         cout << "PASSED!" << endl;
//     }

//     else {
//         cout << "Failed :(" << endl;
//     }
    
//     return 0;
// }