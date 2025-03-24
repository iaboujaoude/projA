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

        // YOUR CODE GOES HERE

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

int main(int argc, char *argv[])
{
        // If you have function arguments that aren't used yet
        // the g++ compiler complains. The following lines are
        // harmless and they suppress the complaint. You can remove
        // the (void) lines and this comment once you start using
        // the arguments

        (void)argc;             // DELETE THIS LINE
        (void)argv;             // DELETE THIS LINE

        //   =======================================================

        //           YOUR MAIN FUNCTION CODE HERE
        
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

        // YOUR CODE GOES HERE

        // ===================================================

        (void)input_file;      // DELETE THIS LINE
        House dummy;           // DELETE THIS LINE
        return dummy;          // CHANGE THIS TO RETURN THE HOUSE YOU'VE READ
}

// print information about a single house
void print_house(House h)  
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)h;       // DELETE THIS LINE
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

// given a lot code, return the column and row (respectively)
// in the all_houses array
int col_from_lot(string lot) 
{
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)lot; // DELETE THIS LINE
        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

int row_from_lot(string lot) 
{    
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)lot; // DELETE THIS LINE
        return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) 
{    
        // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
        // ===================================================

        // YOUR CODE GOES HERE

        // ===================================================

        (void)rows;             // DELETE THIS LINE
        (void)cols;             // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
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

        // YOUR CODE GOES HERE

        // ===================================================

        (void)filename;         // DELETE THIS LINE
        (void)all_houses;       // DELETE THIS LINE
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

