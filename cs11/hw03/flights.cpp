// flights.cpp
// purpose:  To tell the flight timings of two planes
// by:  Ian Abou-Jaoude
// date:  October 2 2021
// No bugs
// No help
// iabouj01


#include <iostream>

using namespace std;

int toMinutes(int hour, int minute);
void printTimes(int time);
int timeElapsed(int time1, int time2);

int main()
{
        int h1, m1, h2, m2;

        cout << "Flight 1: ";
        cin >> h1;
        cin >> m1;
        cin >> h2;
        cin >> m2;

        int h3, m3, h4, m4;
        cout << "Flight 2: ";
        cin >> h3;
        cin >> m3;
        cin >> h4;
        cin >> m4;

        // -- Convert to minutes
        
        int dep1 = toMinutes(h1, m1);
        int arr1 = toMinutes(h2, m2);
        int dep2 = toMinutes(h3, m3);
        int arr2 = toMinutes(h4, m4);
 

        if (arr1 < dep1) {               // Arrival earlier than departure
                arr1 = arr1 + (60 * 24); // means that it's the next day
                dep2 = dep2 + (60 * 24); // add 24 hours onto it and all
                arr2 = arr2 + (60 * 24); // subsequent times
        }

        if (dep2 < arr1) {               // Departure of second flight earlier
                dep2 = dep2 + (60 * 24); // than arrival of first flight:
                arr2 = arr2 + (60 * 24); // do the same adjustment
        }

        if (arr2 < dep2) {               // Arrival of second flight
                arr2 = arr2 + (60 * 24); // is earlier than departure
        }

        // -- At this point we are guaranteed that dep1 < arr1 < dep2 < arr2
        //    Now we can compute the differences in minutes
        int layover = timeElapsed(arr1, dep2);
        int total   = timeElapsed(dep1, arr2);

        // -- Now convert back into hours and minutes and print
        
        cout << "Layover: ";
        printTimes(layover);
        
        cout << "Total: ";
        printTimes(total);

        return 0;
}

/* toMinutes
* Parameters: the hours (hour) and the minutes (minute)
* Purpose     To convert hours and minutes to minutes
* Effects:    Returns the total minutes
*/

int toMinutes(int hour, int minute){
    return hour * 60 + minute;
}


/* printTimes
* Parameters: the time in minutes (time)
* Purpose     To print in time and minutes
* Effects:    Calculates the minutes and hours and then prints them
*/

void printTimes(int time){
    
    //Calculate minutes and hours individually
    
    int total_h = time / 60;
    int total_m = time % 60;
    
    //Print the resultant hours and minutes
    
    cout << total_h << " hr " << total_m << " min" << endl;
}

/* timeElapsed
* Parameters: The starting time (time1) and ending (time2)
* Purpose     To find the elapsed time between time one and two
* Effects:    Calculates the difference between time one and two
*/

int timeElapsed(int time1, int time2){
    return time2 - time1;
}