#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

using namespace std;

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);

int main()
{
    int i, i2;
    
    cin >> i >> i2;
    
    cout << (i / i2) << endl;



    return 0;
}

/*
 * name:      open_or_fail
 * purpose:   Tries and makes sure you can open a file
 * arguments: the stream and name of the files
 * returns:   none
 * effects:   prints error message in case of failure
 */

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string)
{
        stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Unable to open: " << file_string << endl;
                exit(EXIT_FAILURE);
        }
}