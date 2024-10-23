#include <iostream>
using namespace std;
int main()
{
    int b;
    cout<<"Enter number of participants:";
    cin>>b;
    int a[b][5];          
    float sum[b]={0};  
    float max=0;       
    int maxParticipant=0;
    cout<<"\nEnter the scores of participants for 5 subjects:\n";

    for (int i=0;i<b;i++)
    {
        cout<<"\nParticipant"<<i+1<<":"<<endl;
        for (int j=0;j<5;j++)
        {
            cout<<"Subject"<<j+1<<":";
            cin>>a[i][j];      
            sum[i]=sum[i]+a[i][j];   
        }
        if (sum[i]>max)
        {
            max=sum[i];
            maxParticipant=i;
        }
    }
for (int i=0;i<b;i++)
{
        for (int j=i+1;j<b;j++)
        {
            if (sum[i]>sum[j])
            {
                float temp=sum[i];
                sum[j]=sum[i];
                sum[j]=temp;
            }
        }
    }
    cout<<"\nTotal score of each participant (sorted in ascending order):"<<endl;
    for (int i=0;i<b;i++)
    {
        cout<<"Participant"<<i+1<<":"<<sum[i]<<endl;
    }
    cout<<"\nThe participant with the highest score is Participant"<<maxParticipant+1 
         <<"with a score of"<<max<<endl;
    return 0;
}