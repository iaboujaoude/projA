/*
 * An exercise is using pointers and ordering pizza
 *
 * Mark A. Sheldon, Tufts University, Spring 2021
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int    m, n;
    int   *p1, *p2;

    p1 = &m;
    p2 = &n;
    *p1 = 8; // m=8
    *p2 = (*p1)++; // m=9 , n=8
    *p2 += *p2; // n=16

    cout << m << " " << n << " "
         << *p1 << " " << *p2 << endl;

    return 0;
}