//*********************************************************************
//
//                       Animal_Array_list.cpp
//       
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//
//  Author:Ian Abou-Jaoude
//  Date:Nov 16
//
//  Purpose: To create an array of animals from database
//
//  Known bugs:na
//
//  Testing performed: Tested multiple of the functions individually and then
//                     all together to ensure step by step each component works
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"


// *****************************************************************
//         STARTER CODE PROVIDES EMPTY FUNCTION BODIES
// *****************************************************************

//                  ****STUDENT CODE NEEDED HERE***             //

//   
//   FILL IN THE REMAINDER OF THIS FILE WITH DEFINITIONS OF 
//   ALL THE MEMBER FUNCTIONS REQUIRED FOR THE AnimalArrayList
//   TYPE.
//
//   You do not need to update the function contracts.  We have not
//   provided full contracts according to the style guide, but
//   we believe the abbreviated contracts are sufficient here.
//   Just complete the functions.
//

//
// Default constructor
//
Animal_Array_List::Animal_Array_List()
{
        animals = new Animal[INITIAL_CAPACITY];
        m_capacity = INITIAL_CAPACITY;
        m_num_animals = 0;
}

//
// Destructor: Frees heap-allocated memory associated with arraylist
//
Animal_Array_List::~Animal_Array_List()
{        
        delete [] animals;
}

//
// Adds a to the back of the list.
// Effects: may expand if necessary
//
void 
Animal_Array_List::add(Animal a)
{       
        //If the capacity of the array is less than the additional number of 
        //animals it will make the array larger using expand
        if (m_num_animals == m_capacity) {
                expand();
        }
        
        animals[m_num_animals] = a;
        m_num_animals++;
}

//
// Returns the number of Animals currently stored
//
int
Animal_Array_List::num_animals()
{
        return m_num_animals;
}

//
// Returns the Animal located at position index  
// 
Animal 
Animal_Array_List::animal_at(int index)
{
        Animal output_animal = animals[index];
         
        return output_animal;
}

//
// Doubles the capacity of the animals array
//
void
Animal_Array_List::expand()
{
        Animal *animals1 = new Animal[m_capacity * 2];
        
        //Set animals1 to all the same elements as animals
        for (int i = 0; i < m_num_animals; i++){
                animals1[i] = animals[i];
        }
    
        m_capacity = m_capacity * 2;
    
        delete [] animals;
    
        animals = animals1;
}


//
//                       print
//
//       Ask all the Animals in the list to print themselves
//
void
Animal_Array_List::print()
{
        for (int i = 0; i < m_num_animals; i++){
                animals[i].print();
        }
}
