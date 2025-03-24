//
//                         CardLinkedList.cpp
//
//           A class that manages a linked list of cards
//
//  The data are stored as a singly-linked sequence of nodes accessed
//  from a single pointer (in the data member 'm_front') to the first
//  node in the list (or the nullptr if the list is empty). Each node
//  has a Card instance named card.
//
//  Author: Noah Mendelsohn 
//
//  Tufts University, Fall 2021
//  CS 11: Project 2
//
//  Modified by: Ian Abou-Jaoude
//  Date: Nov 27
// 
//  Anything else you would like to include:
//

/**********************************************************/
/***      Students: Fill in the TODO items below        ***/
/***  You may add additional private member functions   ***/
/**********************************************************/

#include <iostream>
#include <iomanip>     // gets setw for debug printing
#include <string>

#include "CardLinkedList.h"

using namespace std;

/*------------------------------------------------------------------
 *                    Constructor(s) and Destructor
 *----------------------------------------------------------------*/

//
// Purpose:  Constructor initializes an empty list
//
CardLinkedList::CardLinkedList()
{
    m_front = nullptr;
    m_list_length = 0;
}

//
// Purpose:  Destructor recycles the space associated with all nodes
//           in the list
//
CardLinkedList::~CardLinkedList()
{
    while (m_front != nullptr)
    {
        remove_first_card();
    }
}

/*------------------------------------------------------------------
 *          Public functions to manipulate and query the list
 *----------------------------------------------------------------*/

//
// Purpose:  Return the current size of the list
//           i. e., the number of words/nodes in the list
//
unsigned int CardLinkedList::num_cards()
{
    return m_list_length;
}


//
// Purpose:  Add Card node to the list at the specified position. If index is
//           out of range then return quietly
//
//           Recycles the node containing the word (and its count)
//
void CardLinkedList::add_card_at(unsigned int index, Card c)
{
    if (m_list_length >= index) {
        //For adding at the first position
        if (index == 0) {
            add_to_front(c);
        }
        
        
        else {
            Node *previous;
            unsigned int n = 0;
            
            //Traversing the node pointers 
            for (previous = m_front; (previous != nullptr) and (n < (index-1));
                previous = previous->next) {
                    n++;
            }
            
            //Set a new node inside the card list for the new card as long as it
            //is not out of range
            if (previous != nullptr) {
                Node *tempNode = new Node{c, previous->next};
                previous->next = tempNode;
            }
            
        } 
        ++m_list_length;
    }
}

//
// Purpose:  Adds a card to the front, helper function for add_card_at
//
void CardLinkedList::add_to_front(Card c)
{
    m_front = new Node{c, m_front};
}

//
// Purpose:  Remove word from the list.  That is, it removes and
//           recycles the node containing the word (and its count)
//
void CardLinkedList::remove_card_at(unsigned int index)
{
    if (m_list_length > index) {
        //Removing the first card
        if (index == 0){
            remove_first_card();
            --m_list_length;
        }
        
        //Deleting at a not start or ending value
        else {
            Node *previous;
            unsigned int n = 0;
            
            //Traversing the node pointers 
            for (previous = m_front; (previous != nullptr) and (n < (index-1));
                previous = previous->next) {
                    n++;
            }
            
            //Take previous and point it to two down and delete the desired 
            //pointer
            if (previous != nullptr) {
                Node *tempNode = previous->next;
                previous->next = tempNode->next;
                delete tempNode;
                m_list_length--;
            }
        }
    }
}

//
// Purpose:  Removes the first card in the list helper for remove_card_at
//
void CardLinkedList::remove_first_card()
{
    Node *dispose_p = m_front;
    if (dispose_p != nullptr) {
        m_front = dispose_p -> next;
        delete dispose_p;
    }
}


//
// Purpose:  Return the index-th element of the list
// Params:   index must be in range [0 .. size) where
//           size is the number of words stored in the list
// Effects:  if index is out of range, prints error message and returns
//           NO_CARD_HERE
Card CardLinkedList::get_card_at(unsigned int index)
{
    if (m_list_length >= index) {
        Node *node_p;
        unsigned int n = 0;
        
        //Traverse through list until we get out index
        for (node_p = m_front; (node_p != nullptr) and (n < index); 
            node_p = node_p->next) {
                n++;
        }
            
        if (node_p == nullptr) {
            Card card_no_exist;
            return card_no_exist;
        }
        return node_p->card;
    }
    
    else {
        Card card_no_exist;
        return card_no_exist;
    }
}


//
// Purpose:  Print out the underlying list to cout
// Effects:  Prints to cout
// Notes:    This function is here for debugging purposes.
//           It will not be called in the final version of the program.
//           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
//
void CardLinkedList::debug_print()
{
    int index_num = 0;

    cout << "DEBUG: CardLinked List (num_cards = " << num_cards()
         << ") ["  << endl;
    cout <<  "  Index_num   Node Address  Face Value" << endl;
    for (Node *curr_p = m_front; curr_p != nullptr; curr_p = curr_p->next) {
        cout <<  setw(9) << index_num++;
        cout <<  setw(16) << curr_p;
        cout <<  "       ";
        curr_p->card.debug_print();
        cout << endl;
    }
    cout << "]" << endl;
}

