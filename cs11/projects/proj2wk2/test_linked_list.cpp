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
//     Modified by: Ian Abou-Jaoude
//     Date: Dec 6

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
using namespace std;

int main()
{
    cout << "Making card: value 21" << endl;
    Card c21(21);
    c21.debug_print();
    cout << endl;
    int m = c21.value();
    cout << m;
    cout << endl;  // newline for viewing convenience

    cout << "----End_test1----"<< endl;
    CardLinkedList ll;
    
    Card c0(3);
    Card c1(5);
    Card c2(30);
    Card c3(20);
    Card c0_1(99);
    cout << "Making linked list" << endl;
    
    ll.add_card_at(0, c0);
    ll.add_card_at(1, c1);
    ll.add_card_at(2, c2);
    ll.add_card_at(3, c3);
    ll.add_card_at(0, c0_1);
    ll.add_card_at(6, c3); //This should not add anything
    
    ll.debug_print();
    
    cout << "----End_test2----"<< endl;

    cout << "Finding a node at some spot" << endl;
    
    Card c_2;
    Card c_4;
    Card c_error_5;
    Card c_0;
    
    c_4 = ll.get_card_at(4);
    c_2 = ll.get_card_at(2);
    c_error_5 = ll.get_card_at(5);
    c_0 = ll.get_card_at(0);

    
    if ((c_4.value() == c3.value()) and (c_2.value() == c1.value()) and 
        (c_0.value() == c0_1.value()) and (c_error_5.value() == -1)){
        cout << "Success, get card works." << endl;
    }
    
    else {
        cout << "error mate" << endl;
    }
    
    cout << "---Test 3---" << endl;
    
    cout << "Deleting => first" << endl;
    ll.remove_card_at(0);
    ll.debug_print();

    cout << "Deleting => last" << endl;
    ll.remove_card_at(4);
    ll.debug_print();
    
    cout << "Deleting => middle" << endl;
    ll.remove_card_at(1);
    ll.debug_print();
    
    cout << "Deleting => under" << endl;
    ll.remove_card_at(-2);
    ll.debug_print();
    
    cout << "Deleting => over by one" << endl;
    ll.remove_card_at(3);
    ll.debug_print();

    cout << "Deleting => over" << endl;
    ll.remove_card_at(5);
    ll.debug_print();

    return 0;
}

