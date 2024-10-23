#include <iostream>
using namespace std;
int main()
{ 
    const int branches=12;
    double sales[branches];
    double totalSales=0.0;
    int highestBranch=0,lowestBranch=0;
    for (int i=0;i<branches;i++)
    {
        cout<<"Enter the sales for branch"<<(i+1)<<":";
        cin>>sales[i];
        totalSales+=sales[i];
        if (sales[i]>sales[highestBranch])
        {
            highestBranch=i;
        }
        if (sales[i]<sales[lowestBranch])
        {
            lowestBranch=i;
        }
    }
    cout<<"\nTotal Annual Sales:"<<totalSales<<endl;
    cout<<"Branch"<<(highestBranch+1)<<"had the highest sales:"<<sales[highestBranch]<<endl;
    cout<<"Branch"<<(lowestBranch+1)<<"had the lowest sales:"<<sales[lowestBranch]<<endl;
    return 0;
}