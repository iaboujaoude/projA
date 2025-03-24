/* hello.cpp
 * A series of print statements about myself
 * Ian Abou-Jaoude
 * n/a
 * n/a
 */


 #include <iostream>
 using namespace std;
 int main() {
          
         double goal;
         
         double test = 0;
         bool debug;
         int n = 0;
         debug = n < 2147483600;
         
         cout << "What do you want to square root: ";
         cin >> goal;
         
         while ( !( ( (test * test) >= goal-0.0001) and 
                ((test * test) <= goal + 0.0001)) or !debug) {
                    test = test + 0.00001;
                    n++;
                    if ((n % 10000000) == 0)
                    {
                        cout << "100 million tries" << endl;
                    }
                }
                
          cout << "Answer is: " << test << endl;

         
         return 0;
 }
