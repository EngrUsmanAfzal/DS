#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;    
    Node(int val):data(val),next(nullptr) {}
};
Node*reverseList(Node*head)
{
    Node*prev=nullptr;
    Node*current=head;
    while (current)
    {
        Node*nextNode=current->next;  
        current->next=prev;            
        prev=current;                  
        current=nextNode;              
    }
    return prev;
}
void insert(Node*&head,int data)
{
    if (!head)
    {
        head=new Node(data);
    }
    else
    {
        Node*temp=head;
        while (temp->next) temp=temp->next;
        temp->next=new Node(data);
    }
}
void printList(Node*head)
{
    while (head)
    {
        cout<<head->data<<"";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node*head=nullptr;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    cout<<"Original List:";
    printList(head);
        head=reverseList(head);
    cout<<"Reversed List:";
    printList(head);
    return 0;
}