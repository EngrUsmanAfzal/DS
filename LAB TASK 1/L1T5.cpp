#include<iostream>
using namespace std;
int main()
{
  int arr[6],n;
  cout<<"Enter the size of the array:";
  cin>>n;
  cout<<"Enter the values in the array:"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  bool palindrome=false;
  for(int i=0;i<5;i++)
  {
    if (arr[i]==arr[n-1])
    {
        palindrome=true;
        break;
    }
    else 
    palindrome=false;
  }
  if(palindrome)
  {
    cout<<"The array is a palindrome.";
  if(!palindrome)
  {
    cout<<"The array is not a palindrome.";
    }
    return 0;
  }
}