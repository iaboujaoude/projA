/*
 *  Passenger.cpp
 *  Ian Abou-Jaoude
 *  Febuary 14
 *
 *  COMP 15 Proj 1
 *
 *  The cpp file for Passenger
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/*
 * name:      print
 * purpose:   Print the important information of the Passenger
 * arguments: The output stream
 * returns:   none
 * effects:   none
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
