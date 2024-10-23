#include <iostream>
using namespace std;
int main()
{
    int array[10]={4,8,15,16,23,42,108,7,3,12};
    int numberToFind;
    bool found=false;
    int index=-1;
    cout<<"Enter the number you want to search for:";
    cin>>numberToFind;
    for (int i=0;i<10;i++)
    {
        if (array[i]==numberToFind)
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found)
    {
        cout<<"Number"<<numberToFind<<"found at index"<<index<<endl;
    }
    else
    {
        cout<<"Number"<<numberToFind<<"not found in the array."<<endl;
    }
    return 0;
}