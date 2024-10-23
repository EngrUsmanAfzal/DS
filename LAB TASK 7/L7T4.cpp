#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
Node* incpp(Node* head)
{
    if (head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
    Node* middle = incpp(head);
    if (middle != nullptr)
    {
        cout<<"Middle element:"<<middle->data<<endl;
    }
    else
    {
        cout<<"List is empty."<<endl;
    }
    return 0;
}