#include <iostream>
using namespace std;
int main()
{
    int seats[10][15];
    int row,seat;
    int choice;
        cout<<"\nCinema Seating System"<<endl;
    while (true)
    {
        cout<<"1.Display Seating Arrangement"<<endl;
        cout<<"2.Book a Seat"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nSeating Arrangement:"<<endl;
            for (int i=0;i<10;i++)
            {
                for (int j=0;j<15;j++)
                {
                    if (seats[i][j]==0)
                    {
                        cout<<"O";
                    }
                    else
                    {
                        cout<<"1";
                    }
                }
                cout<<endl;
            }
            break;
        case 2:
            cout<<"Enter row(1-10):";
            cin>>row;
            row--;
            cout<<"Enter seat(1-15):";
            cin>>seat;
            seat--;
            if (row<0||row>=10||seat<0||seat>=15)
            {
                cout<<"Invalid input.Please enter valid row and seat numbers."<<endl;
            }
            else
            {
                if (seats[row][seat]==0)
                {
                    seats[row][seat]=1;
                    cout<<"Seat booked successfully!"<<endl;
                }
                else
                {
                    cout<<"\nAlready occupied."<<endl;
                }
            }
            break;
        case 3:
            cout<<"Exiting the system.Thank you!"<<endl;
            return 0;
        default:
            cout<<"Invalid choice.Please enter a valid option."<<endl;
        }
    }
    return 0;
}