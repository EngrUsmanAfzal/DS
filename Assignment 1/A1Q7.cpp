#include <iostream>
using namespace std;
int main()
{
    int b,highestgrade=-1,lowestgrade=101,above_average=0,below_average=0;
    cout<<"Enter Number of Students:";
    cin>>b;
    float grades[b],sum=0,avg=0;
    for (int i=0;i<b;i++)
    {
        cout<<"Enter Grades of Student"<<i+1<<":";
        cin>>grades[i];      
        sum=sum+grades[i];  
        if (grades[i]>highestgrade)
        {
            highestgrade=grades[i];
        }
        if (grades[i]<lowestgrade)
        {
            lowestgrade=grades[i];
        } 
    }
    avg=sum/b;
    for (int i=0;i<b;i++)
    {
        if (grades[i]>avg)
        {
            above_average++;
        }
        else if (grades[i]<avg)
        {
            below_average++;
        }
    }
    cout<<"The average grade is:"<<avg<<endl;
    cout<<"Number of students who scored above the average:"<<above_average<<endl;
    cout<<"Number of students who scored below the average:"<<below_average<<endl;
    cout<<"Highest grade in the class:"<<highestgrade<<endl;
    cout<<"Lowest grade in the class:"<<lowestgrade<<endl;
    return 0;
}