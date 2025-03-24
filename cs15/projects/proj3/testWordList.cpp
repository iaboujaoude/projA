#include "WordList.h"
#include "WordInstance.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Make nodes to add
    WordInstance new_instance;

    Datum new_datum = new_instance.make_datum("/ewesto03/cs15/proj3", 3, 
                            "cool cool cool cool cool, cool", 2, false);
    Datum new_datum1 = new_instance.make_datum("/ewesto03/cs15/proj3/test", 
                                            37, "this sucks", 1, true);
    Datum new_datum2 = new_instance.make_datum("/ewesto03/cs15", 97, "these 
                                        acting like they tough", 3, true);
    Datum new_datum3 = new_instance.make_datum("/ewesto03/cs15", 156, "no", 
                                               4, false);

    new_instance.insert(new_datum);
    new_instance.insert(new_datum1);
    new_instance.insert(new_datum2);
    new_instance.insert(new_datum3);

    //Make another new node
    WordInstance two_instance;

    Datum new_datum4 = two_instance.make_datum("/ewesto03/cs15", 99, "please disinfect services", 3, true);
    Datum new_datum5 = two_instance.make_datum("/ewesto03/cs15/folder2/nose", 78, "ale mad cute", 1, false);

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

    list.print_list(cout);

    //Test sensitive print function
    cout << "Printing data belonging to IAN: \n";
    bool test = list.print_at("IAN", cout);
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

	return 0;
}