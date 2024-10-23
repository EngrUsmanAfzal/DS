#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
using namespace std;
vector<int> generateRandomList(int size)
{
    vector<int>list(size);
    for (int i=0;i<size;++i)
    {
        list[i]=rand()%100000;
    }
    return list;
}
int linearSearch(const vector<int>&list,int target)
{
    for (int i=0;i<list.size();++i)
    {
        if (list[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(const vector<int>&list,int target)
{
    int left=0;
    int right=list.size()-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (list[mid]==target)
        {
            return mid;
        }
        if (list[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
template <typename Func>
double measureTime(Func searchFunc,const vector<int>&list,int target)
{
    auto start=chrono::high_resolution_clock::now();
    searchFunc(list,target);
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double>duration=end-start;
    return duration.count();
}
int main()
{
    vector<int>sizes={100,1000,10000,100000};
    int target=50000;
    cout<<"Array Size\tLinear Search\tBinary Search\n";
    for (int size:sizes)
    {
        vector<int>list=generateRandomList(size);
        sort(list.begin(),list.end());
        double linearTime=measureTime(linearSearch,list,target);
        double binaryTime=measureTime(binarySearch,list,target);
        cout<<size<<"\t\t"<<linearTime<<"\t\t"<<binaryTime<<"\n";
    }
    return 0;
}