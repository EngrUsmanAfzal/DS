#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class Queue
{
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;
public:
    Queue(int cap)
    {
        front = rear = nullptr;
        size = 0;
        capacity = cap;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            cout<<"Queue overflow.Cannot enqueue"<<value<<endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout<<"Enqueued"<<value<<"to the queue."<<endl;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout<<"Queue underflow.Cannot dequeue."<<endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        size--;
        return value;
    }
    void display()
    {
        if (isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr)
        {
            cout<<temp->data<<"";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q1(5);
    Queue q2(5);
    int choice, value;
    while (true)
    {
        cout<<"\n1.Enqueue to Queue 1\n";
        cout<<"2.Dequeue from Queue 1 and Enqueue to Queue 2\n";
        cout<<"3.Dequeue from Queue 2\n";
        cout<<"4.Display Queue 1\n";
        cout<<"5.Display Queue 2\n";
        cout<<"6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter value to enqueue to Queue 1:";
                cin>>value;
                q1.enqueue(value);
                break;
            case 2:
                value = q1.dequeue();
                if (value != -1)
                {
                    q2.enqueue(value);
                }
                break;
            case 3:
                q2.dequeue();
                break;
            case 4:
                cout<<"Queue 1:";
                q1.display();
                break;
            case 5:
                cout<<"Queue 2:";
                q2.display();
                break;
            case 6:
                return 0;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }
}