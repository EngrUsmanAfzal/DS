#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtBeginning(Node*& head, int data)
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
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void printList(Node* head)
{
    if (!head) return;
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
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    printList(head);
    return 0;
}