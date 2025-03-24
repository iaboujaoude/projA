// IsolateData.cpp
// purpose:  To take a string and isolate needed datums
// No bugs

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Datum {
    string dataType;
    int position;
    string number;
};

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);
Datum isolate(string input);
string numberOut(Datum datumIn, string input);

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        cerr << "Usage: ./IsolateData inputDirectory outputFile_X outputFile_Y" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream outstream_x;
    open_or_fail(outstream_x, argv[2]);
    
    ofstream outstream_y;
    open_or_fail(outstream_y, argv[3]);
/*
    string test1 = "fkdfksjfd";
    string test2 = "<kakapip>hfhfh";

    string out1 = isolate(test1);
    string out2 = isolate(test2);

    outstream_x << out1 << endl;
    outstream_y << out2 << endl;

*/


    ifstream data_in;
    open_or_fail(data_in, argv[1]);
/*
    string test3;
    data_in >> test3;
    cout << isolate(test3);
    //cout << test3 << endl;
*/
    string line_in = "";

    // for (int i = 0; i < 10; i++) {
    //     line_in = "";
    //     data_in >> line_in;
    //     Datum test_datum = isolate(line_in);
    //     cout << numberOut(test_datum, line_in) << endl;
    // }



    while (not data_in.eof()) {
        line_in = "";
        data_in >> line_in;
        Datum test_datum = isolate(line_in);

        if (test_datum.dataType == "xvalue"){
            outstream_x << numberOut(test_datum, line_in) << endl;
        }

        else if (test_datum.dataType == "yvalue"){
            outstream_y << numberOut(test_datum, line_in) << endl;
        }
        
    }

    return 0;
}

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string){
    stream.open(file_string);
        if (not stream.is_open()) {
                cerr << "Could not build index, exiting." << endl;
                exit(EXIT_FAILURE);
        }
}

/* plural
* Parameters: The word to determine (word) and the corresponding number (n) to 
the word
* Purpose:    To determine if a word is plural or not
* Returns:    The word in it's correct form (singular or plural)
*/

Datum isolate(string input){
    Datum output;
    output.dataType = "";
    output.position = 0;

    for (unsigned int i = 0; i < input.length(); i++) {
        if (input[i] == '<') {
            for (unsigned int j = i+1; input[j] != '>'; j++) {
                output.dataType = output.dataType + input[j];
                output.position = j + 2;
            }
        return output;             
        }
    }

    return output; 
}

string numberOut(Datum datumIn, string input) {
    string output = "";
    cout << datumIn.dataType << endl;
    
    if ((datumIn.dataType == "yvalue") or (datumIn.dataType == "xvalue")) {
        for (unsigned int i = datumIn.position; input[i] != '<'; i++) {
            output = output + input[i];
            //cout << "here\n";
        }
    }

    return output;
}