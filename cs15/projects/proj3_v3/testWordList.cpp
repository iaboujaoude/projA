/*
 *  testWordList.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 26, 2022
 *
 *  COMP 15 Proj 3
 *
 *  Program to test the functionality of the WordList class
 *
 */

#include "WordList.h"
#include "WordInstance.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    vector<string> lines;
    vector<string> paths;

    lines.push_back("hello my name is elijah");
    lines.push_back("i said yea i got it");
    lines.push_back("don't put that, dude, actually stop");
    lines.push_back("i hope whoever grades that has a good laugh outa this");
    lines.push_back("hello my name is ian");
    lines.push_back("ian making some weird ass noises");
    lines.push_back("in the whats it called i think I put like");

    paths.push_back("/ewesto03/cs15/proj3/test");
    paths.push_back("/ewesto03/cs15/proj3");
    paths.push_back("/ewesto03/cs15/");
    paths.push_back("/ewesto03/cs15/proj3/conceited");
    paths.push_back("/ewesto03/cs15/proj1");
    paths.push_back("/ewesto03/cs15");
    paths.push_back("/ewesto03/cs15/test");
    
    //Make nodes to add
    WordInstance new_instance;

    Datum new_datum = new_instance.make_datum(1, 3, 3, false);
    Datum new_datum1 = new_instance.make_datum(5, 37, 6, true);
    Datum new_datum2 = new_instance.make_datum(2, 97, 5, true);
    Datum new_datum3 = new_instance.make_datum(3, 156, 4, false);

    new_instance.insert(new_datum);
    new_instance.insert(new_datum1);
    new_instance.insert(new_datum2);
    new_instance.insert(new_datum3);

    //Make another new node
    WordInstance two_instance;

    Datum new_datum4 = two_instance.make_datum(4, 99, 1, true);
    Datum new_datum5 = two_instance.make_datum(6, 78, 2, false);

    two_instance.insert(new_datum4);
    two_instance.insert(new_datum5);

    //Initialize instance of a WordList
    WordList list("ian");

    //Test isEmpty
    bool empty_test = false;
    if (list.isEmpty()) {
        empty_test = true;
    }
    //Tests insert
    list.insert("Ian", new_datum);
    list.insert("ian", new_datum1);
    list.insert("Ian", new_datum2);
    list.insert("ian", new_datum3);
    list.insert("IAN", new_datum4);
    list.insert("ian", new_datum5);

    //test listSize function
    cout << "List size should be: 3\n";
    cout << "List size is: " << list.listSize() << endl;

    if (list.isEmpty()) {
        empty_test = false;
    }

    if (empty_test) {
        cout << "isEmpty function working" << endl;
    } else {
        cout << "isEmpty function failed\n";
    }

    list.print_list(cout, lines, paths);

    WordList listCopy = list;

    cout << "above and below should be the same (testing copy constructor)\n";

    listCopy.print_list(cout, lines, paths);

    //Test sensitive print function
    cout << "Printing data belonging to IAN: \n";
    bool test = list.print_at("IAN", cout, lines, paths);
    cout << endl;

    if (not test) {
        cout << "print_at fail\n";
    }

    //test contains function
    bool contains_t3 = list.contains("Ian");

    bool contains_t1 = list.contains("ian");
    bool contains_t2 = list.contains("IAN");
    bool contains_f = list.contains("iAn");

    if ((contains_t3) and (contains_t1) and (contains_t2) and (not contains_f)) {
        cout << "contains function successful" << endl;
    }
    else {
        cout << "contains function failed" << endl;
    }

    cout << "name should be: ian" << endl;
    cout << "       name is: " << list.return_name() << endl;

	return 0;
}