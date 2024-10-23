#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
void insertNode(Node*&head,int value)
{
    Node*newNode=new Node();
    newNode->data=value;        
    newNode->next=nullptr;      
    if (head==nullptr)
    {        
        head=newNode;
    }
    else
    {
        Node*temp=head;        
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=newNode;     
    }
}
void deleteNode(Node*&head,int value)
{
    if (head==nullptr)
    {        
        cout<<"List is empty."<<endl;
        return;
    }
    if (head->data==value)
    {    
        Node*temp=head;
        head=head->next;        
        delete temp;              
        return;
    }
    Node*temp=head;
    while (temp->next!=nullptr&&temp->next->data!=value)
    {
        temp=temp->next;
    }
    if (temp->next!=nullptr)
    {
        Node*nodeToDelete=temp->next;
        temp->next=temp->next->next;
        delete nodeToDelete;
    }
    else
    {
        cout<<"Value not found."<<endl;
    }
}
void searchNode(Node*head,int value)
{
    Node*temp=head;
    while (temp!=nullptr)
    {
        if (temp->data==value)
        {
            cout<<"Value"<<value<<"found."<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"Value"<<value<<"not found."<<endl;
}
void displayList(Node*head)
{
    Node*temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node*head=nullptr;
    int value;
    cout<<"Enter 5 values to create a Linked List:"<<endl;
    for (int i=0;i<5;i++)
    {
        cin>>value;
        insertNode(head,value);
    }
    cout<<"Linked List:";
    displayList(head);
    cout<<"Enter a value to insert:";
    cin>>value;
    insertNode(head,value);
    cout<<"Linked List after insertion:";
    displayList(head);
    cout<<"Enter a value to delete:";
    cin>>value;
    deleteNode(head,value);
    cout<<"Linked List after deletion:";
    displayList(head);
    cout<<"Enter a value to search:";
    cin>>value;
    searchNode(head,value);
    return 0;
}