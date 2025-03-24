// flights.cpp
// purpose:  To tell the flight timings of two planes
// by:  Ian Abou-Jaoude
// date:  September 27 2021
// No bugs
// No help
// iabouj01

#include <iostream>

using namespace std;

int main(){
    
    /*Declare variables that will be used to determine the flight times,
    allow us to calculate time in between flights, and consider residual 
    hours caused by the ending minute or hour time being less than the starting
    */
    
    int hour_departure_1, hour_departure_2, minute_departure_1, 
    minute_departure_2 = 0;
    
    int hour_arrival_1, hour_arrival_2, minute_arrival_1, 
    minute_arrival_2 = 0;
    
    int lay_hour, lay_minute, total_hour, total_minute = 0;
    
    int lay_n, total_n = 0;
    
    //Ask for input on flight times
    
    cout << "Flight 1: ";
    cin >> hour_departure_1 >> minute_departure_1 >> hour_arrival_1 >>
    minute_arrival_1;
    
    cout << "Flight 2: ";
    cin >> hour_departure_2 >> minute_departure_2 >> hour_arrival_2 >>
    minute_arrival_2;
    
    /*Calculate layover depending on if the starting minutes and hours are 
    less than the beginning, for hours that would make it an overnight flight
    */
    
    if(minute_departure_2 < minute_arrival_1){
        lay_minute =  60 - minute_arrival_1 + minute_departure_2;
        lay_n = -1;
    }
    
    else{
        lay_minute = minute_departure_2 - minute_arrival_1;
        lay_n = 0;
    }
    
    if(hour_arrival_1 <= hour_departure_2){
        lay_hour = hour_departure_2 - hour_arrival_1 + lay_n;
    }
    
    else{
        lay_hour = 24 - hour_arrival_1 + hour_departure_2 + lay_n;
    }
    
    //Same as the layover calculation but now for the total
    
    if(minute_departure_1 > minute_arrival_2){
        total_minute =  60 - minute_departure_1 + minute_arrival_2;
        total_n = -1;
    }
    
    else{
        total_minute = minute_arrival_2 - minute_departure_1;
        total_n = 0;
    }
    
    if(hour_departure_1 <= hour_arrival_2){
        total_hour = hour_arrival_2 - hour_departure_1 + total_n;
    }
    
    else{
        total_hour = 24 - hour_departure_1 + hour_arrival_2 + total_n;
    }
    
    //Print the calculations
    
    cout << "Layover: " << lay_hour << " hr " << lay_minute << " min" << endl;
    cout << "Total: " << total_hour << " hr " << total_minute << " min" << endl;
    
    return 0;
}