#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
    Node(int x):data(x),next(NULL) {}
};
Node*findMiddle(Node*head)
{
    Node*slow=head;
    Node*fast=head;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void appendNode(Node*&head,int data)
{
    Node*newNode=new Node(data);
    if (!head)
    {
        head=newNode;
    }
    else
    {
        Node*temp=head;
        while (temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
int main()
{
    Node*head=NULL;
    for (int i=1;i<=5;i++)
    {
        appendNode(head,i);
    }
        Node*middle=findMiddle(head);
    cout<<"Middle element:"<<middle->data<<endl;
    return 0;
}