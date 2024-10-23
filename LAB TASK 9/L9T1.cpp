#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int reg_no;
    string st_name;
    float cgpa;
public:
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}
    void input()
    {
        cout<<"Enter Registration Number:";
        cin>>reg_no;
        cin.ignore();
        cout<<"Enter Student Name:";
        getline(cin, st_name);
        cout<<"Enter CGPA:";
        cin>>cgpa;
    }
    void display() const
    {
        cout<<"Reg No:"<<reg_no<<",Name:"<<st_name<<",CGPA:"<<cgpa<<endl;
    }
};
class Stack
{
private:
    Student* stackArray;
    int top;
    int maxSize;
public:
    Stack(int size) : maxSize(size), top(-1)
    {
        stackArray = new Student[maxSize];
    }
    ~Stack()
    {
        delete[] stackArray;
    }
    void push()
    {
        if (top == maxSize - 1)
        {
            cout<<"Stack is full!"<<endl;
        }
        else
        {
            Student student;
            student.input();
            stackArray[++top] = student;
            cout<<"Student added to stack."<<endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout<<"Stack is empty!"<<endl;
        }
        else
        {
            cout<<"Popped Student:";
            stackArray[top--].display();
        }
    }
};
int main()
{
    int stackSize;
    cout<<"Enter the size of the stack:";
    cin>>stackSize;
    Stack studentStack(stackSize);
    int choice;
    do
    {
        cout<<"\n1.Push Student\n2.Pop Student\n3.Exit\nChoose an option:";
        cin>>choice;
        switch (choice)
        {
            case 1:
                studentStack.push();
                break;
            case 2:
                studentStack.pop();
                break;
            case 3:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice!Please choose again."<<endl;
        }
    }
    while (choice != 3);
    return 0;
}