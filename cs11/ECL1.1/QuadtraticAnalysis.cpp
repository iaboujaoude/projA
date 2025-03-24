// IsolateData.cpp
// purpose:  To take x and y input and output strong contenders for quadratic estimations with vertices greater than 2000
// using pairs of 5
// date:  May 20 2023
// No bugs

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template<typename streamtype>
void open_or_fail(streamtype &stream, string file_string);

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        cerr << "Usage: ./QuadtraticAnalysis inputFile_X inputFile_Y outputFile" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream instream_x;
    open_or_fail(instream_x, argv[1]);
    
    ifstream instream_y;
    open_or_fail(instream_y, argv[2]);


    ofstream outstream;
    open_or_fail(outstream, argv[3]);
    cout << setprecision(14);
    cout.precision(14);
    outstream.precision(14);

    int num_elements = 17015;

    double arr[num_elements][2];

    for (int i = 0; i < num_elements; i++) {
        for (int j = 0; j < 2; j++) {
            double insert = 0;
            if (j == 0) {
                instream_x >> insert;
            }
            else if (j == 1) {
                instream_y >> insert;
            }
            arr[i][j] = insert;
        } 
    }

    int max_g = 0;
    for (int z = 0; z < 17008; z++) {
        if (arr[z][1] != 0) {
        int range = 0;
        double max = 0;
        int max_pos = 0;


        for (int p = 0; arr[z+p][1] != 0; p++) {
            range++;
            
            if (arr[z+p][1] > max)  {
                max = arr[z+p][1];
                max_pos = p;
            }

        }

        if (max >= 1850) {
            max_g++;
            outstream << "{";
            for (int i = z +max_pos - 2; i <= z + max_pos + 2; i++) {
                outstream << "{" << arr[i][0] << ", "<< arr[i][1] << "}";
                if (i != z + max_pos + 2) {
                    outstream << ",";
                }
            }
            outstream << "}\n";
        }
        
        z = z + range;
        
        }
    }
    cout << max_g << endl;
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

