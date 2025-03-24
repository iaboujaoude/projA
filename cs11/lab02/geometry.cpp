// geometry.cpp
// CS 11 Fall 2021
// Lab 02
//
// Purpose: Practice using functions to easily calculate various 
//          geometric equations.
// 
// Modified by: Ian Abou-Jaoude
// Date: September 22 2021
//

#include <iostream>
#include <math.h> 

using namespace std;

/* triangle_area
* Parameters: the sides of the triangle (base, height)
* Purpose:    Calculate the area of a triangle
* Returns:    The area of the triangle
*/

int triangle_area(int base, int height){

    return base * height * 0.5;
    
}

/* square_perimeter
* Parameters: the side length (side_length)
* Purpose:    Calculate the perimeter of a square
* Returns:    The perimeter of a square
*/

int square_perimeter(int side_length){
    
    return side_length * 4;
    
}

/* regular_length
* Parameters: the side length and number of sides
* Purpose:    Calculate the perimeter of a shape with equal side lengths
* Returns:    The perimeter of a shape
*/

int regular_length(int number_of_sides, int side_length){
    
    return number_of_sides * side_length;
    
}

/* area_greater_than
* Parameters: the base and height of a triangle and a minimum area
* Purpose:    Determine if a given area is greater than a given minimum
* Returns:    True or false if the area is it's greater or not
*/

bool area_greater_than(int base, int height, int minimum){
    
    int area = base * height * 0.5;
    bool greater;
    
    if (area > minimum){
        greater = true;
    }
    
    else {
        greater = false;
    }
    
    return greater;
    
}

int distance(int x, int y){
    
    return sqrt((x * x) + (y * y));
    
}

int main()
{
        
        int area;
        int squarePerimeter;
        int shapePerimeter;
        int area_greater;
        int area_greater2;
        int dist;

        
        area = triangle_area(4, 6);
        squarePerimeter = square_perimeter(5);
        shapePerimeter = regular_length(5, 6);
        area_greater = area_greater_than(2, 4, 5);
        area_greater2 = area_greater_than(4, 5, 9);
        dist = distance(5, 12);
        
       
       
        cout << area << endl;
        cout << squarePerimeter << endl;
        cout << shapePerimeter << endl;
        cout << area_greater << endl;
        cout << area_greater2 << endl;
        cout << dist << endl;

        
        return 0;
} 




