#include "WordInstance.h"
#include <iostream>

using namespace std;

int main()
{
	WordInstance list;
    WordInstance list_empty;

    Datum new_datum = list.make_datum(1, 3, 3, false);
    Datum new_datum1 = list.make_datum(5, 37, 6, true);
    Datum new_datum2 = list.make_datum(2, 97, 5, true);
    Datum new_datum3 = list.make_datum(3, 156, 4, false);

    list.insert(new_datum);
    list.insert(new_datum1);
    list.insert(new_datum2);    
    list.insert(new_datum3);

    //list.insensitive_print(cout);

    //tests 
    if (list.listSize() != 4) {
        cout << "Error in listSize function" << endl;
    }

    if ((list.isEmpty()) and (not (list_empty.isEmpty()))) {
        cout << "Error in isEmpty function\n";
    }


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

    list.print_list(cout, lines, paths);


	return 0;
}