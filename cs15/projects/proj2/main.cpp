/*
 *  main.cpp
 *  Ian Abou-Jaoude
 *  March 6
 *
 *  CS 15 Project 2
 *
 *  Use of the final RPNCalc Program through main
 *
 */

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"



using namespace std;

int main()
{
    RPNCalc calculator;

    calculator.run(cin);

    return 0;
}