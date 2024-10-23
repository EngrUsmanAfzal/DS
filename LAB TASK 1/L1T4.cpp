#include <iostream>
using namespace std;
void deleteElement(int array[],int& n,int index)
{
    if (index<0 || index>=n)
    {
        cout<<"Index out of bounds!"<<endl;
        return;
    }
    for (int i=index;i<n-1;i++)
    {
        array[i]=array[i+1];
    }
    n--;
}
void printArray(int array[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<array[i]<<"";
    }
    cout<<endl;
}
int main()
{
    int array[]={10,20,30,40,50};
    int n=sizeof(array)/sizeof(array[0]);
    int index;
    cout<<"Enter the index of the element to delete:";
    cin>>index;
    cout<<"Original array:";
    printArray(array,n);
    deleteElement(array,n,index);
    cout<<"Array after deletion:";
    printArray(array,n);
    return 0;
}