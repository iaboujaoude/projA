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
        bool   availability_TF;
        

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
bool is_available(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS]);
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
int rent_house(int house_id, House all_houses[ROWS][COLS]);

// My functions

int repeat_print (House all_houses[ROWS][COLS]);
bool is_neighbor(int row, int col, House all_houses[ROWS][COLS], 
                 bool same_pos);
int count_neighbors(int row, int col, House all_houses[ROWS][COLS]);
void command_loop(House all_houses[ROWS][COLS]);
void command_m(House all_houses[ROWS][COLS], House results[ROWS * COLS]);
void command_a(House all_houses[ROWS][COLS]);
void command_n(House all_houses[ROWS][COLS]);
void command_r(House all_houses[ROWS][COLS]);

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
                command_loop(all_houses);
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

        //Reads in one line of sample data for each variable of a House 
        //struct
        
        House output_house;
        
        input_file >> output_house.id; 
        input_file >> output_house.lot_code;
        input_file >> output_house.price;
        input_file >> output_house.bedroom_numbers;
        input_file >> output_house.color;
        input_file >> output_house.availability;
        
        
        
        if (output_house.availability == "available") {
                output_house.availability_TF = true;
        }
        else {
                output_house.availability_TF = false;
        }
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
        if (h.availability_TF) {
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
* Purpose:    To convert the lot code to the column
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
        
        //If there are two digits after the letter, make a two digit number
        
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
        ifstream input_file;
        input_file.open(filename);
        int lot_row, lot_col, num_houses;
       
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
* Purpose:    Asks for the row and columns from the user and prints the 
correct house if it exists in that position
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
            
                //Print the house variables if it exists if not print no 
                //house
            
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

/* is_available
* Parameters: house id entered and the house lot
* Purpose:    Determine if the house is available or not
* Effects:    returns true or false for availability
*/
bool is_available(int house_id, House all_houses[ROWS][COLS])
{
        //Traverse and the house with the given id and determine 
        //availablity_TF
        
        for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                        if ((all_houses[i][j].id == house_id) and 
                            (all_houses[i][j].availability_TF)) {
                                return true;
                        }
                }
        }

        return false;
} 


/* matching_houses
* Parameters: maximum price, wanted color, desired number of bedrooms, 
array of all full houses
* Purpose:    Find all houses that meet the requirements
* Effects:    Prints all the houses that met the requirements
*/
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS])
{       
        int house_count = 0;
        
        //Traverse through array and compare to all inputs, if it matches
        //add it to the results array and increase the number of houses by 1
        
        for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                        if ((all_houses[i][j].price <= max_price) and 
                            (all_houses[i][j].color == desired_color) and 
                            (all_houses[i][j].bedroom_numbers >= 
                            desired_bedrooms)) {
                                    results[house_count] = all_houses[i][j];
                                    ++house_count;
                        }
                }
        } 

        return house_count; 
}



/* num_neighbors
* Parameters: house id, array of filled houses
* Purpose:    Find all taken houses one house away from a given house
* Effects:    Returns the number of neighbors
*/
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
        int neighbors_count = 0;
        int row_check, col_check = -1;
        
        //Find the house id in question by traversing through array and take 
        //the row and column
        
        for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                        if ((all_houses[i][j].id == house_id)) {
                                row_check = i;
                                col_check = j;
                        }
                }
        }
        
        //If the house does't exist, return 0 neighbors
        
        if (all_houses[row_check][col_check].no_house_here) {
                return 0;
        }
        
        //Call function count_neighbors to get the number of neighbors using
        //the row and col found
        
        neighbors_count = count_neighbors(row_check, col_check, all_houses);
        
        return neighbors_count;
}


/* rent_house
* Parameters: house id, array of filled houses
* Purpose:    Determine if a house is available or not and rent it out if it's
not
* Effects:    Returns a number depending on if it was found, taken, or doesn't
exists and makes it unavailable if it is rented
*/
int rent_house(int house_id, House all_houses[ROWS][COLS])
{       
    
        // Traverse through all_houses and find house to see if it's available
        // to rent
        
        for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; j++){
                        if ((all_houses[i][j].id == house_id) and 
                            (!all_houses[i][j].availability_TF)) {
                                return 2;
                            }
                        else if ((all_houses[i][j].id == house_id) and 
                                 (all_houses[i][j].availability_TF)) {
                                
                                //If available rent, and change availability
                                     
                                all_houses[i][j].availability_TF = false;
                                return 1;
                        }
                }
        }
        
        return 0;
        
}

/* command_loop
* Parameters: array of filled houses
* Purpose:    Allow user to continue to change commands
* Effects:    Executes all comands depending on input
*/
void command_loop(House all_houses[ROWS][COLS])
{
        string input_command;
        House results[ROWS * COLS];
        
        //continue to ask for input command until quit is input
        
        do {
                cout << "query-> ";
                cin >> input_command;
                
                if (input_command == "m") {
                        command_m(all_houses, results);
                }
                
                else if (input_command == "a") {
                        command_a(all_houses);
                }
                
                else if (input_command == "n") {
                        command_n(all_houses);
                }
                
                else if (input_command == "r") {
                        command_r(all_houses);
                }
                
                else if (input_command != "q"){
                        cout << "Unkown command " << input_command << endl;
                }
        } while (input_command != "q");
                
    
}

/* is_neighbor
* Parameters: row and col in question, array of filled houses, boolean if the
row and column is the same as the house in question
* Purpose:    Determine if a house is a neighbor
* Effects:    Returns true for neighbor
*/
bool is_neighbor(int row, int col, House all_houses[ROWS][COLS], bool same_pos)
{
        bool neighbor = false;
        
        // Determine if this house one slot away is available and exists
        // Returns true if it exisits and is taken
        
        if ((row >= 0) and (row < 50) and (col >= 0) and (col < 20)) {
                if ((!all_houses[row][col].availability_TF) and 
                    (!all_houses[row][col].no_house_here) and 
                    (!same_pos)) {
                        neighbor = true;
                    }
        }
        
    return neighbor;
}

/* count_neighbors
* Parameters: row and col in question, array of filled houses
* Purpose:    Counts the number of neighbors in all directions
* Effects:    Returns the number of neighbors
*/
int count_neighbors(int row, int col, House all_houses[ROWS][COLS])
{
        bool same_pos = false;
        int neighbors_count = 0;
        bool neighbor = false;
        
        //Traverse through each house one position away from the house in 
        //question
        
        for (int a = -1; a < 2; ++a) {
                for (int b = -1; b < 2; ++b) {
                        same_pos = false;
                        if ((a == b) and (b == 0)) {
                                same_pos = true;
                        }
                        
                        //Determine if this house is a neighbor, by calling
                        //is_neighbor
                        
                        neighbor = is_neighbor((row + a), (col + b), 
                                                all_houses, same_pos);
                        if (neighbor) {
                                
                                //Increment the count if it is a neighbor
                                
                                ++neighbors_count;
                        }
               }
        }
        
        return neighbors_count;
}

/* command_m
* Parameters: array of filled houses, empty of array for the results found
* Purpose:    To execute command m, find match, and print what's appropriate
* Effects:    Prints all the matched houses
*/
void command_m(House all_houses[ROWS][COLS], House results[ROWS * COLS])
{
        float input_price;
        string input_color; 
        int input_bedrooms; 
        int num_houses;
        
        cin >> input_price >> input_color >> input_bedrooms;
        cout << "Matching Houses:" << endl;
        
        //Find the number of matching houses
        
        num_houses = matching_houses(input_price, 
                                     input_color, 
                                     input_bedrooms, 
                                     all_houses, results);
        
        //Traverse through array of matched houses and print each
        
        for (int i = 0; i < num_houses; ++i) {
                print_house(results[i]);
        }
}

/* command_a
* Parameters: array of filled houses
* Purpose:    To execute command a, is available, and print what's 
appropriate
* Effects:    Prints if the house is available or not
*/
void command_a(House all_houses[ROWS][COLS]){
        int house_id;
        bool available;
        
        cin >> house_id;
        
        //Find if available by calling on is_available
        
        available = is_available(house_id, all_houses);
        
        //Print appropriate statement
        
        if (available){
                cout << "House " << house_id << " is available"
                << endl;
        }
        else {
                cout << "House " << house_id << 
                " is not available" << endl;
        }
}

/* command_n
* Parameters: array of filled houses
* Purpose:    To execute command n, number of neighbors, and print what's 
appropriate
* Effects:    Prints the number of neighbors, or prints no neighbors
*/
void command_n(House all_houses[ROWS][COLS]){
        int house_id, n_neighbors;
        string no_neighbors = "You have no neighbors, practice your drums!";
        
        cin >> house_id;
        
        //Find the number of neighbors by calling function num_neighbors
        
        n_neighbors = num_neighbors(house_id, all_houses);
        
        //Print appropriate statement depending on the number found
        
        if (n_neighbors == 0) {
                cout << no_neighbors << endl;
        }
        
        else if (n_neighbors > 0) {
                cout << "You have " << n_neighbors 
                << " neighbors!" << endl;
        }
}

/* command_r
* Parameters: array of filled houses
* Purpose:    To execute command r, rent house, and print what's appropriate
* Effects:    Prints what happened when you tried to rent the house
*/
void command_r(House all_houses[ROWS][COLS]){
        int house_id, rent_result;

        cin >> house_id;
        
        //Execute rent house, and find the resulting integer
        
        rent_result = rent_house(house_id, all_houses);
        
        //Print the appropriate statement depending on the result int
        
        if (rent_result == 2) {
                cout << "Too late...i hear the dumpster ";
                cout << "behind hill has some spaces open";
                cout << endl;

        }
        
        else if(rent_result == 1) {
                cout << "Congrats, you rented a house! Hope ";
                cout << "your door knobs don't fall off";
                cout << endl;
        }
        
        else if(rent_result == 0) {
                cout << "You can't rent a house that doesn't ";
                cout << "exist, but good try" << endl;
        }
}



// ============================================================
//     INCLUDE COMP11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST COME 
//   BE THE LAST LINE OF CODE IN YOUR housing.cpp FILE
// ============================================================

#include "housing_hooks.hpp"