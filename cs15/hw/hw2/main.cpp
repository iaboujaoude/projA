#include <iostream>
#include "CharLinkedList.h"
using namespace std;

int main() {
    char array_test[5] = {'a', 'b', 'c', 'd', 'e'};
    CharLinkedList test_list3(array_test, 5);

    test_list3.removeAt(2);

    cout << test_list3.toString() << endl;

    
    return 0;
}