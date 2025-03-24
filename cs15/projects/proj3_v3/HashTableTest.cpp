/*
 *  HashTableTest.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 26, 2022
 *
 *  COMP 15 - Proj 3
 *
 *  Program to test the implementation of the HashTable class.
 *
 */

#include "WordList.h"
#include "WordInstance.h"
#include "HashTable.h"
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
    lines.push_back("a");
    lines.push_back("b");
    lines.push_back("c");
    lines.push_back("d");
    lines.push_back("e");
    lines.push_back("f");
    lines.push_back("g");

    paths.push_back("/ewesto03/cs15/proj3/test");
    paths.push_back("/ewesto03/cs15/proj3");
    paths.push_back("/ewesto03/cs15/");
    paths.push_back("/ewesto03/cs15/proj3/conceited");
    paths.push_back("/ewesto03/cs15/proj1");
    paths.push_back("/ewesto03/cs15");
    paths.push_back("/ewesto03/cs15/test");
    paths.push_back("/ewesto03/cs15/proj3/test");
    paths.push_back("/ewesto03/cs15/proj3");
    paths.push_back("/ewesto03/cs15/");
    paths.push_back("/ewesto03/cs15/proj3/conceited");
    paths.push_back("/ewesto03/cs15/proj1");
    paths.push_back("/ewesto03/cs15");
    paths.push_back("/ewesto03/cs15/test");

    Datum new_datum = {1, 3, 1, true};
    Datum new_datum1 = {2, 37, 2, true};
    Datum new_datum2 = {3, 97, 3, true};
    Datum new_datum3 = {4, 156, 4, true};
    Datum new_datum4 = {5, 99, 5, true};
    Datum new_datum5 = {6, 78, 6, true};
    Datum new_datum6 = {7, 3, 7, true};
    Datum new_datum7 = {8, 37, 8, true};
    Datum new_datum8 = {9, 97, 9, true};
    Datum new_datum9 = {10, 156, 10, true};
    Datum new_datum10 = {11, 99, 11, true};
    Datum new_datum11 = {12, 78, 12, true};
    
    HashTable hash;

    hash.insert("ELIJAH", new_datum);
    hash.insert("elijah", new_datum1);

    hash.insert("iAn", new_datum3);
    hash.insert("ian", new_datum2);

    hash.insert("water", new_datum4);
    hash.insert("WATER", new_datum5);

    hash.insert("Kenya", new_datum10);
    hash.insert("KENYA", new_datum11);

    hash.insert("Joe", new_datum6);
    hash.insert("jOe", new_datum7);

    hash.insert("PEN", new_datum8);
    hash.insert("pen", new_datum9);
    


    cout << "num buckets is: " << hash.num_buckets() << endl;

    hash.print_at_caseInSen("elijah", cout, lines, paths);
    
    //Make nodes to add
    //WordInstance new_instance;

    

    // new_instance.insert(new_datum);
    // new_instance.insert(new_datum1);
    // new_instance.insert(new_datum2);
    // new_instance.insert(new_datum3);

    //Make another new node
    // WordInstance two_instance;

    

    // two_instance.insert(new_datum4);
    // two_instance.insert(new_datum5);

    // //Testing hash table functionality
    // HashTable new_table;

    // //Test helper functions
    // cout << new_table.get_lowercase("hello") << endl;

    // //test inserting node
    
    // new_table.insert("Ian", new_datum1);
    // new_table.insert("ian", new_datum2);
    // new_table.insert("ian", new_datum3);
    // new_table.insert("elijah", new_datum4);

    // cout << "\n\n---------------------------adding IAN---------------------------\n\n";
    // new_table.insert("IAN", new_datum5);
    

    // if (not new_table.containsBucket("ian")) {
    //     cout << "containsBucket failed\n\n";
    // }
    // else {
    //     cout << "containsBucket passed\n\n";
    // }

    // if (new_table.containsBucket("john")) {
    //     cout << "containsBucket failed 2\n\n";
    // }
    // else {
    //     cout << "containsBucket passed 2\n\n";
    // }

    // if (not new_table.containsBucket("Elijah")) {
    //     cout << "containsBucket failed 3\n\n";
    // }
    // else {
    //     cout << "containsBucket passed 3\n\n";
    // }

    // cout << "Printing ian WordList: " << endl;
    // new_table.element_at("ian").print_list(cout, lines, paths);
    // cout << endl;

    // cout << "Printing ian WordInstance: " << endl;
    // new_table.element_at("ian").print_at("ian", cout, lines, paths);
    // cout << endl;


    // cout << "Printing keys:\n";
    // new_table.print_keys();
    // cout << endl;

    // cout << "Printing case insensitive of ian:\n";
    // new_table.print_at_caseInSen("ian", cout, lines, paths);
    // cout << endl;
    

    // cout << "Print elijah case sensitive: " << endl;
    // new_table.print_at_caseSen("elijah", cout, lines, paths);
    // cout << endl;


    // cout << "Printing case sensitive of ian:\n";
    // new_table.print_at_caseSen("ian", cout, lines, paths);
    // cout << endl;

    // cout << "Printing case sensitive of Ian:\n";
    // new_table.print_at_caseSen("Ian", cout, lines, paths);
    // cout << endl;

    // cout << "Printing case sensitive of IAN:\n";
    // new_table.print_at_caseSen("IAN", cout, lines, paths);
    // cout << endl;
    

    // cout << "Print elijah case sensitive: " << endl;
    // new_table.print_at_caseInSen("elijah", cout, lines, paths);
    // cout << endl;


	return 0;
}