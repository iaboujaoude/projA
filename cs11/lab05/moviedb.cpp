/*
 * CS 11: Lab 05
 * moviedb.cpp
 *
 * Purpose: Interact with arrays of structs by manipulating
 *          and searching a movie database
 *
 * Written by: Keisha Mukasa, Spring 2021
 * With updates by: Sam Berman (sberma04) and 
 *                  Jackson Parsells (jparse01), Fall 2021
 *
 * Modified by:
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

const int NUM_MOVIES = 450;
const int NUM_ACTORS = 5;

struct Movie
{
    string title;
    int year;
    double gross;
    string director;
    string actors[NUM_ACTORS];
};

void read_movie_data(Movie movies[NUM_MOVIES]);

int main()
{
    // This line of code declares a list of 450 movies obje
    Movie movie_list[NUM_MOVIES];

    // This function call is populating the movie list with all
    // the movies in the file. Do not worry about its implementation.
    read_movie_data(movie_list);

    /* TODO: Your lab code goes here */
    
    string movieName;
    
    int movieIndex;
    
    int i = NUM_MOVIES;
    
    bool movieLocated = false;
    
    
    cout << "What is your movie called?" << endl;
    
    getline(cin, movieName);
    
    while (i > -1) {
        if (movie_list[i].title == movieName) {
            movieLocated = true;
            movieIndex = i;
        }
        --i;
    }
    
    if (movieLocated){
        
        int n = NUM_ACTORS - 1;
        
        cout << movie_list[movieIndex].title << endl;
        cout << movie_list[movieIndex].year;
        cout << endl << movie_list[movieIndex].gross << endl;
        cout << movie_list[movieIndex].director << endl;
        
        while (n >= 0){
            if (n == 0){
                cout << movie_list[movieIndex].actors[n] << ".";
                --n;
            }
            
            else {
                cout << movie_list[movieIndex].actors[n] << ", ";
                --n;
            }
        }
        
        cout << endl;
    }
    
    else {
        cout << movieName << " was not found in the movie database" << endl;
    }
    
    int user_movie_year = 0;
    
    cout << "Enter the search year: ";
    cin >> user_movie_year;
    
    int yearCount;
    
    i = NUM_MOVIES;
    
    while (i > -1) {
        if (movie_list[i].year == user_movie_year) {
            ++yearCount;
        }
        --i;
    }
    
    i = NUM_MOVIES;
    string yearList[yearCount];
    
    int yearIndex = 0;
    
    while (i > -1) {
        if (movie_list[i].year == user_movie_year) {
            yearList[yearIndex] = movie_list[i].title;
            ++yearIndex;
        }
        
        --i;
    }
    
    while ()
    
    
    
    
    

    return 0;
}

/* 
 * TODO: YOUR FUNCTIONS GO HERE 
 */

/****************************************************************
 *                         NOTE                               
 * The functions below are part of the starter code that enable
 * you to read in from a file. You do not need to understand
 * the code below to complete the lab and we encourage you to
 * ignore this code. This implementation will be covered in the
 * future but is not currently required for lab or homework.
****************************************************************/

/*  
*   READ_MOVIE_DATA
*   Parameters: Empty movie array
*   Purpose: Read lists of movies data from a file and store in array
*   Returns: Does not return anything
*/
void read_movie_data(Movie movies[NUM_MOVIES])
{
    // ifstream object declaration in order to open and read
    // from a file
    ifstream infile;
    string filename = "moviedata.txt";

    // open file
    infile.open(filename);

    // check if file successfully opened if it isn't the program is
    // exited immediately
    if (infile.fail())
    {
        cerr << "ERROR: Error opening file, please check file name: "
             << filename << endl;
        exit(EXIT_FAILURE);
    }

    // read through file
    for (int i = 0; i < NUM_MOVIES; i++)
    {
        getline(infile, movies[i].title);
        infile >> movies[i].year;
        infile >> movies[i].gross;
        infile.ignore();
        getline(infile, movies[i].director);

        // reads in each actors name
        for (int j = 0; j < NUM_ACTORS; j++)
        {
            getline(infile, movies[i].actors[j]);
        }
    }
}
