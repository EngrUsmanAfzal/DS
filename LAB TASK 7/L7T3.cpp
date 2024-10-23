#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int count = 0;
            while (current != nullptr && count < position - 1) {
                current = current->next;
                count++;
            }
            if (current == nullptr) {
                cout << "Position " << position << " out of bounds\n";
                delete newNode;
            } else {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int count = 0;
            while (current->next != nullptr && count < position - 1) {
                current = current->next;
                count++;
            }
            if (current->next == nullptr) {
                cout << "Position " << position << " out of bounds\n";
            } else {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
    }

    void deleteAllNodes() {
        while (head != nullptr) {
            deleteAtPosition(0);
        }
        cout << "All nodes deleted\n";
    }

    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty\n";
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // Deleting from an empty list
    list.deleteAtPosition(0);

    // Inserting at a position greater than the length of the list
    list.insertAtPosition(10, 0);
    list.insertAtPosition(20, 2); // Out of bounds

    // Displaying list
    list.display();

    // Inserting more elements
    list.insertAtPosition(15, 1);
    list.insertAtPosition(25, 2);

    // Display updated list
    list.display();

    // Deleting all nodes
    list.deleteAllNodes();
    list.display();

    // Further deletion after list is empty
    list.deleteAtPosition(0);

    return 0;
}
