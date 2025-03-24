//===============================================================
// housing.cpp
// purpose:  Create an array to represent a lot
// by:  Ian Abou-Jaoude
// date:  October 26 2021
// No bugs
// No help
// iabouj01
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

int repeat_print (House all_houses[ROWS][COLS]);

int main(int argc, char *argv[])
{       
        // Must take two arguments when executing code, execute and file name
        
        if (argc != 2){
                cerr << "ERROR: Please enter one data file address" << endl;
                return 1;
        }
        
        string filename;
        filename = argv[1];
        
        // Call all functions and declare the empty 2D array
        
        House all_houses[ROWS][COLS];
        
        fill_with_no_houses(ROWS, COLS, all_houses);
        
        bool proceed = read_all_house_data(filename, all_houses);
        
        if (proceed) {
                repeat_print(all_houses);
        }
        else {
                return 1;
        }

        return 0;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions operating on a single house
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

/* read_one_house
* Parameters: The input file
* Purpose:    To read one house and set each House variable from one line of 
input
* Effects:    Returns a house with the filled variables
*/

House read_one_house(ifstream& input_file) 
{

        //Reads in one line of sample data for each variable of a House struct
        
        House output_house;
        
        input_file >> output_house.id; 
        input_file >> output_house.lot_code;
        input_file >> output_house.price;
        input_file >> output_house.bedroom_numbers;
        input_file >> output_house.color;
        input_file >> output_house.availability;
        
        output_house.no_house_here = false;

        return output_house;
        
}

/* print_house
* Parameters: The house to print
* Purpose:    Print all the House variables in the correct format
* Effects:    Prints all the variables in the house
*/

void print_house(House h)  
{
        //Turn availability into a yes or no
        
        string available_YN;
        if (h.availability == "available") {
                available_YN = "Yes";
        }
        else {
                available_YN = "No";
        }
        
        //Print all variables in correct format
        
        cout << "Id: " << h.id << " Lot: " << h.lot_code
        << " Color: " << h.color << " Price: " << h.price 
        << " Bedrooms: " << h.bedroom_numbers << 
        " Available: " << available_YN << endl;
}

// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 
//   Functions relating to the array of houses
// - -  - - - - - - - - - - - - -  - - - - - - - - - - - 

/* col_from_lot
* Parameters: Lot code
* Purpose:     To convert the lot code to the column
* Effects:    Takes in a string and returns a number
*/
int col_from_lot(string lot) 
{
        int column;
        char letter;

        letter = lot[0];
        column = letter - 65;

        return column;
}

/* row_from_lot
* Parameters: The lot code
* Purpose:     To find the row number from the lot code
* Effects:    Takes a string and returns a number
*/

int row_from_lot(string lot) 
{    
        int lot_length = lot.length();
        int row;
        
        if (lot_length >= 3) {
                row = lot[2] - 48;
                row = row + 10 * (lot[1] - 48);
        }
        else {
                row = lot[1] - 48;
        }
        
        return row - 1;
}

/* fill_with_no_houses
* Parameters: the rows, the columns, and the empty house array
* Purpose:    Cretae a house array that's full of empty houses
* Effects:    Returns a house array that's empty to be populated
*/

void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]) 
{    
        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++){
                        all_houses[i][j].no_house_here = true;
                }
        }
}

/* read_all_house_data
* Parameters: the name of the file, the empty house array
* Purpose:    Read all the houses from the file and fill them in the right 
slots, if it could not read file an error statement prints
* Effects:    Returns the populated houses with a true or false if the file 
worked or not
*/
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]) 
{
        int num_houses;
        ifstream input_file;
        input_file.open(filename);
        int lot_row;
        int lot_col;
        // Ensure that the file was found and was successfully opened
        if (not input_file.is_open()) {
                cerr << "fileread.cpp: could not open file: "
                << filename << endl;
                return false;
        }
        // Create a new array of houses from the file
        input_file >> num_houses;
        House data_houses[num_houses];
        
        for (int i = 0; i < num_houses; i++) {
                data_houses[i] = read_one_house(input_file);
        }
        // Populate the empty lot with only the slots that have houses from 
        // array above
        for (int j = 0; j < num_houses; j++) {
                lot_row = row_from_lot(data_houses[j].lot_code);
                lot_col = col_from_lot(data_houses[j].lot_code);
                
                all_houses[lot_row][lot_col] = data_houses[j];
        }

        return true;
}

/* repeat_print
* Parameters: The house array lots
* Purpose:    Asks for the row and columns from the user and prints the correct
house if it exists in that position
* Effects:    Ends if the row is -1 (Doesn't exist)
*/
int repeat_print(House all_houses[ROWS][COLS])
{
        
        int user_row, user_col = 0;
        
        //Ask for the row and only ask for col if the user entered a non
        //negative row
        
        cout << "Enter row: ";
        cin >> user_row;
        if (user_row >= 0) {
                cout << "Enter col: ";
                cin >> user_col;
            
                //Print the house variables if it exists if not print no house
            
                if (!all_houses[user_row][user_col].no_house_here){
                        print_house(all_houses[user_row][user_col]); 
                }
            
                else {
                        cout << "No house" << endl;
                }
                // Use recursion to ask for another lot if a valid lot code 
                // was entered
                return repeat_print(all_houses);
        }
        else {
                return 0;
        }
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