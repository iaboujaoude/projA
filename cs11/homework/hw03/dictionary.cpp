// dictionary.cpp
// purpose:  Print a definition for a set of words
// by:  Ian Abou-Jaoude
// date:  October 4 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

void variableDef();
void functionDef();
void parameterDef();
void recursionDef();
void pseudocodeDef();
void conditionalDef();
void cs11Def();
void define();

int main()
{
    define();
    
    return 0;
}


/* variableDef
* Parameters: none
* Purpose     To define Variable
* Effects:    Print the definition
*/

void variableDef(){
        cout << "A location in the computer's memory that can store a value";
        cout << endl;
}

/* functionDef
* Parameters: none
* Purpose     To define Function
* Effects:    Print the definition
*/

void functionDef(){
        cout << "A named block of code that can be invoked as a statement or "; 
        cout << "within an expression";
        cout << endl;
}

/* parameterDef
* Parameters: none
* Purpose     To define Parameter
* Effects:    Print the definition
*/

void parameterDef(){
        cout << "Variables that are initialized in a function definition";
        cout << endl;
}

/* recursionDef
* Parameters: none
* Purpose     To define Recursion
* Effects:    Print the definition
*/

void recursionDef(){
        cout << "A situation in which a definition refers to the term it is ";
        cout << "defining";
        cout << endl;
}

/* pseudocodeDef
* Parameters: none
* Purpose     To define Pseudocode
* Effects:    Print the definition
*/

void pseudocodeDef(){
        cout << "A way of outlining code using simple language without ";
        cout << "writing any actual code";
        cout << endl;
}

/* conditionalDef
* Parameters: none
* Purpose     To define Conditional
* Effects:    Print the definition
*/

void conditionalDef(){
        cout << "A method to execute a block of code depending on the outcome"; 
        cout << " of an expression";
        cout << endl;
}

/* cs11
* Parameters: none
* Purpose     To define CS11
* Effects:    Print the definition
*/

void cs11Def(){
    cout << "A university class that teaches you the fundementals of code and ";
    cout << "computer science in C++";
    cout << endl;
}


/* define
* Parameters: none
* Purpose     To receive an input and determine which word it is to difine it
* Effects:    Print the definition of the entered word
*/

void define(){
    
    //Declare the string "word" and receive user input to define "word"
    
    string word;
    cin >> word;
    
    /*Compare the user's input to the words in our dictionary and call
    the print functions if that is the word*/
    
    if (word == "Variable"){
        variableDef();
    }
    
    else if (word == "Function"){
        functionDef();
    }
    
    else if (word == "Pseudocode"){
        pseudocodeDef();
    }
    
    else if (word == "Recursion"){
        recursionDef();
    }
    
    else if (word == "Parameter"){
        parameterDef();
    }
    
    else if (word == "Conditional"){
        conditionalDef();
    }
    
    else if(word == "CS11"){
        cs11Def();
    }
    
    //A statement if none of the words were entered
    
    else{
        cout << "Definition Not Found" << endl;
    }
    
}