#include <iostream>
using namespace std;
int main()
{
    string name;
    string emotion;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "Enter an emotion your feeling." << endl;
    cin >> emotion;
    cout << "Hello, " << name << "! Welcome to camp! You are feeling "; 
    cout << emotion << " today.";
    
    
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;
    if(age<10)
    {
        cout << "Your age is " << age;
        cout << ". You should go to lower campus." << endl;
    }
    
    if(age>10)
    {
        cout << "Your age is " << age;
        cout << ". You should go to upper campus." << endl;
    }
    
    
    
    int age2;
    cout << "Enter your age: " << endl;
    cin >> age2;
    if(age<10)
    {
        cout << "Your age is " << age2;
        cout << ". You should go to lower campus." << endl;
    }
    else
    {
        cout << "Your age is " << age2;
        cout << ". You should go to upper campus." << endl;
    }
    
    
    
    float num1;
    float num2;
    float num3;
    
    cout << "Enter a number: " << endl;
    cin >> num1;
    cout << "Enter another number: " << endl;
    cin >> num2;
    num3 = num1 * num2;
    cout << "Your new ID number is: " << endl;
    cout << num3 << endl;
    
    return 0;
}