#include "WordList.h"
#include "WordInstance.h"
#include "HashTable.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Make nodes to add
    WordInstance new_instance;

    Datum new_datum = new_instance.make_datum("/ewesto03/cs15/proj3", 3, "cool cool cool cool cool, cool, HERE IS *ELijah* ", 2, true);
    Datum new_datum1 = new_instance.make_datum("/ewesto03/cs15/proj3/test", 37, "this sucks HERE IS *Ian* ", 1, true);
    Datum new_datum2 = new_instance.make_datum("/ewesto03/cs15", 97, "these acting like they tough HERE IS *ian*", 3, true);
    Datum new_datum3 = new_instance.make_datum("/ewesto03/cs15", 156, "no HERE IS *ian* ", 4, false);


    //Make another new node
    WordInstance two_instance;

    Datum new_datum4 = two_instance.make_datum("/ewesto03/cs15", 99, "please disinfect services HERE IS *elijah* ", 3, true);
    Datum new_datum5 = two_instance.make_datum("/ewesto03/cs15/folder2/nose", 78, "ale mad cute HERE IS *IAN* ", 1, true);

    //Testing hash table functionality
    HashTable new_table;

    //Test helper functions
    cout << new_table.get_lowercase("hello") << endl;

    //test inserting node
    new_table.insert("ELijah", new_datum);
    new_table.insert("Ian", new_datum1);
    //cout << "1\n";
    new_table.insert("ian", new_datum2);
    //cout << "2\n";
    new_table.insert("ian", new_datum3);
    //cout << "3\n";
    new_table.insert("elijah", new_datum4);
    cout << "\n\n---------------------------adding IAN---------------------------\n\n";
    new_table.insert("IAN", new_datum5);
    

    if (not new_table.containsBucket("ian")) {
        cout << "containsBucket failed\n\n";
    }
    else {
        cout << "containsBucket passed\n\n";
    }

    if (new_table.containsBucket("john")) {
        cout << "containsBucket failed 2\n\n";
    }
    else {
        cout << "containsBucket passed 2\n\n";
    }

    if (not new_table.containsBucket("Elijah")) {
        cout << "containsBucket failed 3\n\n";
    }
    else {
        cout << "containsBucket passed 3\n\n";
    }

    cout << "Printing ian WordList: " << endl;
    new_table.element_at("ian").print_list(cout);
    cout << endl;

    cout << "Printing ian WordInstance: " << endl;
    new_table.element_at("ian").print_at("ian", cout);
    cout << endl;


    cout << "Printing keys:\n";
    new_table.print_keys();
    cout << endl;

    cout << "Printing case insensitive of ian:\n";
    new_table.print_at_caseInSen("ian", cout);
    cout << endl;
    

    cout << "Print elijah case sensitive: " << endl;
    new_table.print_at_caseSen("elijah", cout);
    cout << endl;


    cout << "Printing case sensitive of ian:\n";
    new_table.print_at_caseSen("ian", cout);
    cout << endl;

    cout << "Printing case sensitive of Ian:\n";
    new_table.print_at_caseSen("Ian", cout);
    cout << endl;

    cout << "Printing case sensitive of IAN:\n";
    new_table.print_at_caseSen("IAN", cout);
    cout << endl;
    

    cout << "Print elijah case sensitive: " << endl;
    new_table.print_at_caseInSen("elijah", cout);
    cout << endl;


	return 0;
}