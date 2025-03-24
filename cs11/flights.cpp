/*
 * CS 11
 *
 * Solutions to flights problem from hw02 for use in hw03.
 *
 * Copyright Sam Guyer, Tufts University, Fall 2018
 *
 * Do not redistribute.
 *
 * Updated for Fall 2021 by: Sam Berman (sberma04)
 *
 */


#include <iostream>

using namespace std;

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
        int dep1 = h1 * 60 + m1;
        int arr1 = h2 * 60 + m2;
        int dep2 = h3 * 60 + m3;
        int arr2 = h4 * 60 + m4;

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
        int layover = dep2 - arr1;
        int total   = arr2 - dep1;

        // -- Now convert back into hours and minutes and print
        int layover_h = layover / 60;
        int layover_m = layover % 60;
        cout << "Layover: " << layover_h << " hr " 
             << layover_m << " min" << endl;

        int total_h = total / 60;
        int total_m = total % 60;
        cout << "Total: " << total_h << " hr " 
             << total_m << " min" << endl;

        return 0;
}
