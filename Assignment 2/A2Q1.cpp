#include <iostream>
using namespace std;
void unreachableCodeExample(int x)
{
    if (x<0)
    {
        cout<<"Negative number"<<endl;
    }
    else if (x>=0)
    {
        cout<<"Positive number"<<endl;
    }
    else
    {
        cout<<"This code is unreachable"<<endl;
    }
}