// recursion.cpp
// CS 11 Fall 2021
// Lab 03
// Purpose: Practice using recursion
// Modified by: Ian Abou-Jaoude
// Date: September 22 2021
// iabouj01

#include <iostream>
#include <math.h> 

using namespace std;

int multiply(int x, int y);
int power(int x, int k);
int sum(int a, int b);
int double_digit(int n);
bool is_prime(int n, int z);

int main(){
    
    
    cout << multiply(4, 6) << endl;
    cout << power(2, 5) << endl;
    cout << sum(2, 6) << endl;
    cout << is_prime(11, 2) << endl;
    cout << is_prime(6, 2) << endl;
    
    return 0;
}

int multiply(int x, int y){
    if(y == 0){
        return 0;
    }
    else{
        return x + multiply(x, y-1);
    }
    
}

int power(int x, int k){
    if(k==0){
        return 1;
    }
    
    else{
        return x * power(x, k-1);
    }
    
}

int sum(int a, int b){
    if(a <= b){
        return a + sum(a + 1, b);
    }
    
    else{
        return 0;
    }
}

/* int double_digit(int n){
    //Come back to this
} */

bool is_prime(int n, int z){
    
    if(z == n){
        return true;
    }
    
    else{
        if((n % (z) == 0) ){
            return false;
        }
        else{
            return is_prime(n, z+1);
        }
    }
}