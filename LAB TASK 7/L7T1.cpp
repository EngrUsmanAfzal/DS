#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value)
    {
        data = value;
        prev = next = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
        printList();
    }
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        printList();
    }
    void insertAtPosition(int value, int position)
    {
        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i=1;i<position-1&&temp!=nullptr;i++)
            temp = temp->next;
        if (temp == nullptr)
        {
            cout<<"Position out of bounds!"<<endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        printList();
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        printList();
    }
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp = head;
        if (temp->next == nullptr)
        {
            delete temp;
            head = nullptr;
        }
        else
        {
            while (temp->next != nullptr)
                temp = temp->next;
            temp->prev->next = nullptr;
            delete temp;
        }
        printList();
    }
    void deleteFromPosition(int position)
    {
        if (head == nullptr)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i=1;i<position&&temp!=nullptr;i++)
            temp = temp->next;
        if (temp == nullptr)
        {
            cout<<"Position out of bounds!"<<endl;
            return;
        }
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        delete temp;
        printList();
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout<<"List is empty!"<<endl;
            return;
        }
        Node* temp = head;
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
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtPosition(15, 2);
    dll.insertAtEnd(25);
    dll.insertAtPosition(5, 1);
    dll.insertAtPosition(30, 6);
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteFromPosition(3);
    return 0;
}