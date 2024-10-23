#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input() {
        cout << "Enter ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

class Node {
public:
    Person person;
    Node* next;

    Node(Person p) : person(p), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void addQueue(Person p) {
        Node* newNode = new Node(p);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Person added to queue.\n";
    }

    void removeQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (!front) {
            rear = nullptr;
        }
        cout << "Person removed from queue.\n";
    }

    void displayFront() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front Person: ";
            front->person.output();
        }
    }
};

int main() {
    Queue queue;
    Person person;
    int choice;

    do {
        cout << "\n1. Add Person to Queue\n";
        cout << "2. Remove Person from Queue\n";
        cout << "3. Check if Queue is Empty\n";
        cout << "4. Display Front Person\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            person.input();
            queue.addQueue(person);
            break;
        case 2:
            queue.removeQueue();
            break;
        case 3:
            cout << (queue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            queue.displayFront();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}