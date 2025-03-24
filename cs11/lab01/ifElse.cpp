#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;
    if(age<10)
    {
        cout << "Your age is " << age;
        cout << ". You should go to lower campus." << endl;
    }
    else
    {
        cout << "Your age is " << age;
        cout << ". You should go to upper campus." << endl;
    }
    
    return 0;
}
        