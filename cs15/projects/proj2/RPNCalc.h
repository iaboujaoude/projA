/*
 *  RPNCalc.h
 *  Ian Abou-Jaoude
 *  Mar 6
 *
 *  COMP 15 Proj 2
 *
 *  The header file for RPNCalc, keeps track of all the functionn headers
 *  and their accessibility as well as variables
 *
 */

#ifndef RPNCALC
#define RPNCALC

#include <string>
#include "Datum.h"
#include "DatumStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class RPNCalc 
{
    public:
    
        RPNCalc();
        void run(istream &input);
        


    private: 
        void if_command();
        bool got_int(string s, int *resultp);
        void int_command(int int_in);
        void bool_command(string command);
        DatumStack stack;
        void bool_command();
        void not_command();
        void print_command();
        void drop_command();
        void dup_command();
        void swap_command();
        void quit_command();
        void opertation_command(string input);
        void div_0(int int1);
        void comparison_command(string input);
        string parseRString(istream &input);
        void string_command(string input);
        void exec_command();
        void file_command();


    
};

#endif
