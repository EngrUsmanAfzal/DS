#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insert(Node*& head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    if (!head)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void deleteNode(Node*& head, int value)
{
    if (!head) return;
    Node* curr = head;
    Node* prev = nullptr;
    if (head->data == value)
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }
    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == value)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
    }
    while (curr != head);
}
void display(Node* head)
{
    if (!head)
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
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    cout<<"Circular Linked List before deletion:";
    display(head);
    deleteNode(head, 3);
    cout<<"Circular Linked List after deletion:";
    display(head);
    return 0;
}