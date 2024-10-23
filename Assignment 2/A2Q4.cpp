#include<iostream>
#include<cmath>
using namespace std;
class Progression
{
    public:
        double a;
        Progression() : a(65536) {}
        Progression(double start) : a(start) {}
        double getValue() const
        {
            return a;
        }
        void setValue(double value)
        {
            a = value;
        }
};
class FinalProgression : public Progression
{
    public:
        FinalProgression() : Progression() {}
        FinalProgression(double start) : Progression(start) {}
        void nextValue()
        {
            cout<<"Progressive sqrt series of"<<a<<":"<<endl;
            cout<<a<<",";
         while(a>1.9&&a!=2)
         {
            a=sqrt(a);
            cout<< a<<",";
        }
        }
};
int main()
{
    int c;
    FinalProgression p;
    cout<<"Initial value:"<<p.getValue()<<endl;
    p.nextValue();
    cout<<"Enter the value of which you want to find the progression"<<endl;  
    cin>>c;
    p.setValue(c);
    cout<<"Progression of:"<<p.getValue()<<endl;
    p.nextValue();
    return 0;
}