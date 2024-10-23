#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtEnd(Node*& head, int value)
{
    Node* newNode = new Node();
    newNode->data = value;    
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void traverse(Node* head)
{
    if (head == nullptr)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp = head;
    do
    {
        cout<<temp->data<<"";
        temp = temp->next;
    }
    while (temp != head);
    cout<<endl;
}
int main()
{
    Node* head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    traverse(head);
    return 0;
}