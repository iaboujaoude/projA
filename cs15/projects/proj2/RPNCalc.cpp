/*
 *  RPNCalc.cpp
 *  Ian Abou-Jaoude
 *  March 6
 *
 *  COMP 15 Proj 2
 *
 *  Implementation of the RPN class, implemented all functions that the
 *  calculator needs in its system
 *
 */

#include "RPNCalc.h"
#include "DatumStack.h"
#include "Datum.h"
#include <stdexcept>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

/*
 * name:      got_int
 * purpose:   checks if theres an in as a string
 * arguments: string to analyze and pointer to an int to set
 * returns:   bool true if its an int
 * effects:   changes whats at the address of an int
 */
bool RPNCalc::got_int(string s, int *resultp)
{
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}

/*
 * name:      RPNCalc
 * purpose:   Initializes the RPNClalc
 * arguments: none
 * returns:   none
 * effects:   none
 */
 
 RPNCalc::RPNCalc() {
     
}

/*
 * name:      run
 * purpose:   To run the main part of RPNCalc
 * arguments: input stream
 * returns:   none
 * effects:   none
 */
 
void RPNCalc::run(istream &instream) {
    string command;
    int i_out = 0;
    instream >> command;
    do {
            
        if (got_int(command, &i_out)) {
            int_command(i_out);
        }
        else if ((command == "#t") or (command == "#f")) {
            bool_command(command);
        }
        else if (command == "not") {
            not_command();
        }
        else if (command == "print") {
            print_command();
        }
        else if (command == "clear") {
            stack.clear();
        }
        else if (command == "drop") {
            drop_command();
        }
        else if (command == "if") {
            if_command();
        }
        else if (command == "dup") {
            dup_command();
        }
        else if (command == "swap") {
            swap_command();
        }
        else if (command == "quit") {
        }
        else if ((command == "+") or (command == "-") or (command == "*")
                 or (command == "/") or (command == "mod")) {
            opertation_command(command);
        }
        else if ((command == ">=") or (command == "==") or (command == "<=")
                 or (command == ">") or (command == "<")) {
            comparison_command(command);
        }
        else if (command == "{") {
            string_command(parseRString(instream));
        }
        else if (command == "exec") {
            exec_command();
        }
        else if (command == "if") {
            if_command();
        }
        else if (command == "file") {
            file_command();
        }
        else if (command == "") {

        }
        else {
            cerr << command << ": unimplemented\n";
        }
    }
    while ((command != "quit") and (instream >> command));
    
    if (command == "quit") {
        cerr << "Thank you for using CalcYouLater.\n";
    }

    else if ((&instream == &cin) and (command != "quit")) {
        cerr << "Thank you for using CalcYouLater.\n";
    }
}

/*
 * name:      int_command
 * purpose:   adds an int to the stack of datums
 * arguments: input stream
 * returns:   none
 * effects:   none
 */
 
void RPNCalc::int_command(int int_in) {
    Datum to_add(int_in);
    stack.push(to_add);
}

/*
 * name:      bool_command
 * purpose:   adds a bool to the stack
 * arguments: inputed command by user
 * returns:   none
 * effects:   adds a bool to the datum stack
 */
void RPNCalc::bool_command(string command) {
    bool bool_in = false;

    if (command == "#t") {
        bool_in = true;
    }

    Datum data_bool(bool_in);

    stack.push(data_bool);
}

/*
 * name:      not_command
 * purpose:   changes the top bool stack to the oppoisite boolean
 * arguments: none
 * returns:   none
 * effects:   none
 */
void RPNCalc::not_command() {
    try {
        Datum to_pop = stack.top();
        stack.pop();
        bool to_add = true;
        if (to_pop.getBool()) {
            to_add = false;
        }
        
        Datum d_add(to_add);
        stack.push(d_add);
    }

    catch (runtime_error &e){
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      print_command
 * purpose:   print top of the stack
 * arguments: none
 * returns:   none
 * effects:   none
 */
void RPNCalc::print_command() {
    try {
        cout << stack.top().toString() << "\n";
    }

    catch (runtime_error &e){
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      drop_command
 * purpose:   pops top element
 * arguments: none
 * returns:   none
 * effects:   none
 */
void RPNCalc::drop_command() {
    try {
        stack.pop();
    }

    catch (runtime_error &e){
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      dup_command
 * purpose:   duplicate the top element
 * arguments: none
 * returns:   none
 * effects:   adds one more element to the stack
 */
void RPNCalc::dup_command() {
    try {
        Datum copy = stack.top();
        stack.push(copy);
    }

    catch (runtime_error &e){
        cerr << "Error: " << e.what() << "\n";
    }
}


/*
 * name:      swap_command
 * purpose:   duplicate the top element
 * arguments: none
 * returns:   none
 * effects:   adds one more element to the stack
 */
void RPNCalc::swap_command() {
    try {
        Datum copy1 = stack.top();
        stack.pop();
        Datum copy2 = stack.top();
        stack.pop();

        stack.push(copy1);
        stack.push(copy2);
    }

    catch (runtime_error &e){
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      opertation_command
 * purpose:   To use a given input as the operation for the top two numbners
 * arguments: Input operator
 * returns:   none
 * effects:   none
 */
void RPNCalc::opertation_command(string input) {
    try {
        Datum datum1 = stack.top();
        stack.pop();
        Datum datum2 = stack.top();
        stack.pop();
        int int1 = datum1.getInt();
        int int2 = datum2.getInt();

        if (input == "+") {
            Datum in(int2 + int1);
            stack.push(in);
        } else if (input == "-") {
            Datum in(int2 - int1);
            stack.push(in);
        } else if (input == "*") {
            Datum in(int2 * int1);
            stack.push(in);
        } else if (input == "/") {
            div_0(int1);
            Datum in(int2 / int1);
            stack.push(in);
        } else if (input == "mod") {
            div_0(int1);
            Datum in(int2 % int1);
            stack.push(in);
        }
    }
    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      comparison_command
 * purpose:   To use a given input as the operation for the top two numbners
 * arguments: Input operator
 * returns:   none
 * effects:   none
 */
void RPNCalc::comparison_command(string input) {
    try {
        Datum datum1 = stack.top();
        stack.pop();
        Datum datum2 = stack.top();
        stack.pop();
        int int1 = datum1.getInt();
        int int2 = datum2.getInt();
        if (input == ">") {
            Datum in(int2 > int1);
            stack.push(in);
        }
        else if (input == "<") {
            Datum in(int2 < int1);
            stack.push(in);
        }
        else if (input == "<=") {
            Datum in(int2 <= int1);
            stack.push(in);
        }
        else if (input == ">=") {
            Datum in(int2 >= int1);
            stack.push(in);
        }
        else if (input == "==") {
            Datum in(int2 == int1);
            stack.push(in);
        }
    }
    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      parseRString
 * purpose:   Encloses a string after { and before }
 * arguments: none
 * returns:   The full Rstring in brackets
 * effects:   none
 */
string RPNCalc::parseRString(istream &input) {
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

 /*
 * name:      string_command
 * purpose:   Push an rstring onto the 
 * arguments: the input string
 * returns:   none
 * effects:   Adds a new datum string on the stack
 */
 void RPNCalc::string_command(string input) {
    Datum stringIn(input);
    stack.push(stringIn);
}

 /*
 * name:      if_command
 * purpose:   Pops two r string off of a stack and executes one depending on
              the third element (a bool)
 * arguments: none
 * returns:   none
 * effects:   Pops top 3 elements off stack
 */
 void RPNCalc::if_command() {
    try {
        Datum false_string = stack.top();
        stack.pop();
        Datum true_string = stack.top();
        stack.pop();
        Datum boolDat = stack.top();
        stack.pop();

        if (not (boolDat.isBool())) {
            throw runtime_error("expected boolean in if test");
        }
        if (not (true_string.isRString() and false_string.isRString())) {
            throw runtime_error("expected rstring in if branch");
        }
        if (boolDat.getBool()) {
            stack.push(true_string);
        }
        else {
            stack.push(false_string);
        }

        exec_command();
    }

    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      exec_command
 * purpose:   executes the top string if the top is a string
 * arguments: none
 * returns:   none
 * effects:   pops the top string
 */
 void RPNCalc::exec_command() {
    try {
        if (not stack.top().isRString()) {
            stack.pop();
            throw runtime_error("cannot execute non rstring");
        }
        Datum top_dat = stack.top();
        stack.pop();
        string to_exec = top_dat.getRString();
        to_exec = to_exec.substr(1, to_exec.length() - 2);
        istringstream stream_to_exec(to_exec);
        run(stream_to_exec);
    }
    catch (runtime_error &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

/*
 * name:      file_command
 * purpose:   pops an rstring which is a name file to then use as input
 * arguments: none
 * returns:   none
 * effects:   pops the top string
 */
 void RPNCalc::file_command() {
    try {
        Datum stringDat = stack.top();
        if (not stringDat.isRString()) {
            stack.pop();
            throw runtime_error("file operand not string");
        }
        if (stringDat.getRString() == "{ }") {
            throw runtime_error("Unable to read ");
        }
        stack.pop();
        string file_string = stringDat.getRString().substr(
                           2, stringDat.getRString().length() - 4);
        ifstream  instream;
        instream.open(file_string);

        if (not instream.is_open()) {
            throw runtime_error("Unable to read " + file_string);
        }
        run(instream);
    }
    catch (runtime_error &e) {
        string err = e.what();
        if ((err == "file operand not string") 
            or (err == "empty_stack")) {
            cerr << "Error: " << e.what() << "\n";
        }
        else {
            cerr << e.what() << "\n";
        }
    }
}
 
 /*
 * name:      div_0
 * purpose:   helper for an error throw when dividing by 0
 * arguments: the integer to check
 * returns:   none
 * effects:   none
 */
 void RPNCalc::div_0(int int1) {
    if (int1 == 0) {
        throw runtime_error("division by 0.");
    }
}