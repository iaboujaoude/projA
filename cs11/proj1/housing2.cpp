//===============================================================
// housing.cpp
// YOUR HEADER HERE
//
// IMPORTATNT NOTE: Only write where the starter indicates YOUR CODE GOES HERE. 
// Do not change anything unless comments tell you to do so, OR YOU MAY GET 
// NO CREDIT ON THIS ASSIGNMENT
//
//===============================================================

#include <iostream>
#include <fstream>

using namespace std;

// DO NOT CHANGE THE FOLLOWING CONSTANTS. WHEN YOU SUBMIT,
// THEY MUST HAVE THESE VALUES AND THEY MUST BE USED 
// AS THE DIMENSIONS FOR YOUR all_houses ARRAY.
const int ROWS = 50;
const int COLS = 20;

//===============================================================
//
//                             House
//
//     Each House struct records the information about one
//     house.  Three of the fields are declared for you and
//     you MUST use them as given.  You should declare below
//     them any additional members that you need.
//
//     Note that if the "no_house_here" member field is set
//     to true, then the other fields are not used.  Of course,
//     if no_house_here is false; then all the fields should
//     be set.
//
//===============================================================

struct House {
        bool   no_house_here;  // true if there is NO house on this location
        int    id;             // id from the data file, converted to int
        string lot_code;       // lot_code string from the data file

        // DO NOT CHANGE ANYTHING ABOVE THIS LINE
        // ===================================================

        float  price;
        int    index;
        int    bedroom_numbers;
        string color;
        string availability;
        

        // ===================================================

};


/*===============================================================
                   Required Function Prototypes

        DO NOT CHANGE ANYTHING IN THIS SECTION. YOUR CODE
        MUST ADHERE TO THESE FUNCTION DECLARATIONS OR YOU WILL
        RECEIVE NO CREDIT.
  ===============================================================*/

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
House read_one_house(ifstream& input_file);
void print_house(House h);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions for week 2 (ignore during week 1)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
// bool is_available(int house_id, House all_houses[ROWS][COLS]);
/* int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]); */
// int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
// int rent_house(int house_id, House all_houses[ROWS][COLS]);


/*===============================================================
                   Additional Function Prototypes
                   
        Write any additional function prototypes that you 
        define here. You may not need any, or you may choose 
        to write several
  ===============================================================*/

// YOUR FUNCTION PROTOTYPES HERE



//======================================================================
//                              main 
//======================================================================

// int argc, char *argv[]

int main()
{
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments

        //   =======================================================
        
        string filename = "medium.testdata";
        //  int num_test;
        
        ifstream input_file;
        input_file.open(filename);
        
        if (not input_file.is_open()) {
                cerr << "fileread.cpp: could not open file: "
                << filename << endl;
                return 1;
        }
        
        House all_houses[ROWS][COLS];
        
        //    input_file >> num_test;
        
        //    cout << "number from the test, should be 2: " << num_test << endl;


        // int user_row;
        // int user_column;
        
        // House test_house = read_one_house(input_file);
        
        /*
        test_house.no_house_here = false;
        test_house.price = 400.4;
        test_house.index = 32;
        test_house.lot_code = "A3";
        test_house.id = 7;
        test_house.bedroom_numbers = 4;
        test_house.color = "Blue"; 
        */
        
        // print_house(test_house);
        
        /*
        
        int row1 = row_from_lot("A21");
        int row2 = row_from_lot("L40");
        int row3 = row_from_lot("Z5");
        
        int column1 = col_from_lot("A21");
        int column2 = col_from_lot("L40");
        int column3 = col_from_lot("Z5");
        */
        
        
        /*
        cout << "Row1: " << row1 << " Column1: " << column1 << endl;
        cout << "Row2: " << row2 << " Column2: " << column2 << endl;
        cout << "Row3: " << row3 << " Column3: " << column3 << endl;
        */

        
        fill_with_no_houses(ROWS, COLS, all_houses);
        
        bool proceed_not = read_all_house_data(filename, all_houses);
        
        if (!proceed_not) {
                for (int i = 0; i < ROWS; i++) {
                        for (int j = 0; j < COLS; j++){
                                if (!all_houses[i][j].no_house_here){
                                        print_house(all_houses[i][j]);
                                    }
                                }
                            }
        }
        
        /*
        if (!proceed_not) {
                for (int i = 0; i < ROWS; i++) {
                        for (int j = 0; j < COLS; j++){
                                if (!all_houses[i][j].no_house_here){
                                        print_house(all_houses[i][j]);
                                        cout << "ROW: " << i << " COL: " << j
                                        << endl;
                                    }
                                }
                            }
        }
        */


        
        //   =======================================================

        return 0;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file) 
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================
        House output_house;
        
        input_file >> output_house.id; 
        input_file >> output_house.lot_code;
        input_file >> output_house.price;
        input_file >> output_house.bedroom_numbers;
        input_file >> output_house.color;
        input_file >> output_house.availability;
        
        output_house.no_house_here = false;

        // ===================================================

        return output_house;
        
}

// print information about a single house
void print_house(House h)  
{
        string available_YN;
        if (h.availability == "available") {
                available_YN = "Yes";
        }
        else {
                available_YN = "No";
        }
        
        
        cout << "Id: " << h.id << " Lot: " << h.lot_code
        << " Color: " << h.color << " Price: " << h.price 
        << " Bedrooms: " << h.bedroom_numbers << 
        " Available: " << available_YN << endl;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, return the column and row (respectively)
// in the all_houses array
int col_from_lot(string lot) 
{
        int column;
        char letter;
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        letter = lot[0];
        column = letter - 65;

        // ===================================================

        return column;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

int row_from_lot(string lot) 
{    
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        int lot_length = lot.length();
        int row;
        
        
        
        if (lot_length >= 3) {
                row = lot[2] - 48;
                row = row + 10 * (lot[1] - 48);
        }
        else {
                row = lot[1] - 48;
        }

        // ===================================================

        
        return row;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) 
{    
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++){
                        all_houses[i][j].no_house_here = true;
                }
        }
        // ===================================================


}

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]) 
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================
        
        int num_houses;
        
        ifstream input_file;
        input_file.open(filename);
        
        if (not input_file.is_open()) {
                cerr << "fileread.cpp: could not open file: "
                << filename << endl;
                return true;
        }
        
        input_file >> num_houses;
        House data_houses[num_houses];
        
        for (int i = 0; i < num_houses; i++) {
                data_houses[i] = read_one_house(input_file);
        }
        
        int lot_row;
        int lot_col;
        
        for (int j = 0; j < num_houses; j++) {
                lot_row = row_from_lot(data_houses[j].lot_code);
                lot_col = col_from_lot(data_houses[j].lot_code);
                
                all_houses[lot_row][lot_col] = data_houses[j];
        }
        
        
        

        // ===================================================

        return false;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}


// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions for week 2 (ignore during week 1)
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

/*
bool is_available(int house_id, House all_houses[ROWS][COLS])
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)house_id;         // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
        return false; // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
} 
*/


/*
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS])
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)max_price;        // DELETE THIS LINE
        (void)desired_color;    // DELETE THIS LINE
        (void)desired_bedrooms; // DELETE THIS LINE
        (void)house_id;         // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
        (void)results;          // DELETE THIS LINE
        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!   
}
*/


/*
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)house_id;         // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
*/


/*
int rent_house(int house_id, House all_houses[ROWS][COLS])
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================
        
        (void)house_id;         // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!   
}
*/

// ============================================================
//     INCLUDE COMP11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST COME 
//   BE THE LAST LINE OF CODE IN YOUR housing.cpp FILE
// ============================================================

#include "housing_hooks.hpp"