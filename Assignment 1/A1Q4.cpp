#include <iostream>
using namespace std;
int main()
{
    int arr[1000],n,pos=-1,target;
    cout<<"\n\tEnter the number of orders:";
    cin>>n;
    cout<<endl<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<"\tEnter the order"<<i+1<<"ID:";
        cin>>arr[i];
    }
    cout<<"\tEnter the order ID to search for:";
    cin>>target;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==target)
        {
            pos=i;
            break;
        }
    }
        if (pos!=-1)
    {
        cout<<"\n\tOrder ID found at position:"<<pos+1<<endl;
    }
    else
    {
        cout<<"\n\tOrder ID not found in the array."<<endl;
    }
    return 0;
}