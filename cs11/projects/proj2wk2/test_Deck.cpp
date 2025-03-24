//
//                       test_linked_list.cpp
//
//     A testing program that creates a CardLinkedList object and
//     tries the basic operations on it, using debug_print to report
//     on the internal state of all objects as it goes.
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Modified by: Ian Abou-Jaoude
//

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
#include "Deck.h"
using namespace std;

int main()
{
    
    Card c_null(5);
    Card c_1(25);
    Card c_0(0);
    Deck test_deck(5);
    
    cout << "Testing initialization of deck" << endl;
    
    test_deck.debug_print();
    cout << "---End of test 1---" << endl;
    
    cout << "Adding two new cards: " << endl;
    
    test_deck.put_card_on_top(c_1);
    test_deck.put_card_on_top(c_0);
    test_deck.debug_print();
    cout << "---End of test 2---" << endl;
    
    Card top_card = test_deck.inspect_top_card();
    cout << "the value of the top card is and should be 5: " << 
         top_card.value() << endl;
    test_deck.debug_print();
    
    cout << "---End of test 3---" << endl;
    
    cout << "Testing input small deck file" << endl; 
    Deck test_deck2("shuffled_deck_small.txt");
    test_deck2.debug_print();
    
    cout << "---End of test 4---" << endl;
    cout << "Testing input large deck file" << endl; 
    Deck test_deck3("shuffled_deck_large.txt");
    test_deck3.debug_print();


    return 0;
}

