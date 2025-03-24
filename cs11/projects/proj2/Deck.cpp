//
//                          Deck.cpp
//
//  Methods to support the Deck class. A deck is an ordered
//  collection of cards. The first card may be drawn off the deck
//  or inspected (though for some purposes inspection won't be
//  used), and additional cards may be put on top of the deck,
//  obscuring the ones below.
//
//  Author: Noah Mendelsohn 
//
//  Tufts University, Fall 2021
//  CS 11: Project 2
//
//  Modified by:
//  Date:
// 
//  Anything else you would like to include:
//

/**********************************************************/
/***      Students: Fill in the TODO items below        ***/
/***  You may add additional private member functions   ***/
/**********************************************************/

#include <iostream>
#include "Deck.h"
#include "CardLinkedList.h"

using namespace std;

//
// Default Constructor
//
Deck::Deck(Card card)
{
    m_deck.add_card_at(0, card);
}

//
// Parameterized Constructor: Takes in the name of a file that will
//                            be used to read the data into the Deck
//
Deck::Deck(string filename)
{
    ifstream f;
    unsigned int card_count;
    
    // open the file
    f.open(filename);
    if (not f.is_open()) {
        cerr << "Deck.cpp: could not open file: "
             << filename << endl;
        exit(1);           // exit from program with error return
    }
    
    //Get the number of cards
    f >> card_count;
    int array_cards[card_count];
    
    //Create an array in reverse order of card values from file
    for (int i = (card_count - 1); i >= 0; --i) {
        f >> array_cards[i];
    }
    
    //Convert array to deck
    for (unsigned int i = 0; i < card_count; ++i) {
        Card card_temp(array_cards[i]);
        put_card_on_top(card_temp);
    }
    
    f.close();
}

//
// Destructor
//
Deck::~Deck()
{
    // TODO (if needed)
}

//
// Number of cards in deck
//
int Deck::number_of_cards()
{
    return m_deck.num_cards();
}

//
// Return a copy of the top card, leaving the original in place
// on the top of the deck.
//
Card Deck::inspect_top_card()
{
    if (m_deck.num_cards() <=0) {
        cerr << "ERROR: inspect_top_card called with deck list length: "
             << m_deck.num_cards()
             << endl;
        exit(1);
    }
    
    return m_deck.get_card_at(0);
}

//
// Remove top card from deck and return it
//
Card Deck::draw_top_card()
{
    if (m_deck.num_cards() <=0) {
        cerr << "ERROR: draw_top_card called with deck list length: "
             << m_deck.num_cards()
             << endl;
        exit(1);
    }
    Card top_card = m_deck.get_card_at(0);
    m_deck.remove_card_at(0);
    
    return top_card;
}

//
// Add a new card to the top of the deck (location 0 in the list)
// Others are pushed down in the stack.
//
void Deck::put_card_on_top(Card c)
{
    m_deck.add_card_at(0, c);
}

//
// debug_print
//
// The assumption is that most printing will be handled by
// users of this class, but being able to print in a standards
// way when debugging is handy.
//
void Deck::debug_print()
{
    m_deck.debug_print();
}

