#include "WordInstance.h"
#include <iostream>

using namespace std;

int main()
{
	WordInstance list;
    WordInstance list_empty;

    Datum new_datum = list.make_datum("/ewesto03/cs15/proj3", 3, "cool cool cool cool cool, cool", 2, false);
    Datum new_datum1 = list.make_datum("/ewesto03/cs15/proj3/test", 37, "this sucks", 1, true);
    Datum new_datum2 = list.make_datum("/ewesto03/cs15", 97, "these acting like they tough", 3, true);
    Datum new_datum3 = list.make_datum("/ewesto03/cs15", 156, "no", 4, false);

    list.insert(new_datum);
    list.insert(new_datum1);
    list.insert(new_datum2);    
    list.insert(new_datum3);

    list.insensitive_print(cout);

    //tests 
    if (list.listSize() != 4) {
        cout << "Error in listSize function" << endl;
    }

    if ((list.isEmpty()) and (not (list_empty.isEmpty()))) {
        cout << "Error in isEmpty function\n";
    }


	return 0;
}