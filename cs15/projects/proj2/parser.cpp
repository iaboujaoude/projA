/*
 *  parser.cpp
 *  Ian Abou-Jaoude
 *  Feb 27
 *
 *  CS 15 Project 2
 *
 *  Implementation of parser to help make blocks of strings that are enclosed
 *  in { }
 *
 */

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

using namespace std;

string parseRString(istream &input);

/*
int main() {
    
    ifstream instream;
    
    instream.open("parser_tester.txt");
    

    string string1 = parseRString(instream);

    string string2 = parseRString(instream);

    string string3 = parseRString(instream);

    if (string1 == "{ + - 1 2 { 2 3 4 } o p x }") {
        cout << "passing test 1" << endl;
    }

    if (string2 == "{ }") {
        cout << "passing test 2" << endl;
    }

    if (string3 == "{ + 9 - m 9 {} o p 9 l . { 9 m llll o } m 6 4 3 }") {
        cout << "passing test 3" << endl;
    }
    
    cout << "String1: " << string1 << endl;
    cout << "String2: " << string2 << endl;
    cout << "String3: " << string3 << endl;
    

    return 0;
}
*/

/*
 * name:      parseRString
 * purpose:   Encloses a string after { and before }
 * arguments: none
 * returns:   The full Rstring in brackets
 * effects:   none
 */
string parseRString(istream &input) {
    string string_return = "{";
    string temp = "";

    input >> temp;

    while ((temp != "}") and (not input.eof())) {
        
        if (temp == "{") {
            string_return = string_return + " " + parseRString(input);
        }

        else {
            string_return = string_return + " " + temp;
        }

        input >> temp;
    }

    return string_return + " }";
}