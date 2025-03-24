/*
 *  DatumStack.h
 *  Ian Abou-Jaoude
 *  Feb 27
 *
 *  COMP 15 Proj 2
 *
 *  Keeps track of all public and private functions for DatumStack
 *
 */

#ifndef DATUMSTACK
#define DATUMSTACK

#include <string>
#include "Datum.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class DatumStack 
{
    public:
    
        DatumStack();
        DatumStack(Datum arr[], int size);
        void clear();
        void pop();
        Datum top();
        bool isEmpty();
        void push(const Datum &dataIn);
        int size();

    private: 
    
        void runtime_helper();
        list<Datum> datum_stack;
        
};

#endif