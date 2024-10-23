#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements (1-20): ";
    cin >> n;
    if (n<1 || n>20)
    {
        cout << "Invalid number of elements.Please enter a number between 1 and 20."<<endl;
        return 0;
    }
    int* a=new int[n];
    cout<<"Enter"<<n<<"values(0-12):"<< endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i] < 0 || a[i] > 12)
        {
            cout<<"Invalid input.Please enter values between 0 and 12."<<endl;
            delete[] a;
            return 0;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    float avg=sum/n;
    cout<<"Average:"<<avg<<endl;
    cout<<"Factorials:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Factorial of"<<a[i]<<"is"<<factorial(a[i])<<endl;
    }
    delete[] a;
    return 0;
}