#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the doubly linked list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << data << " into the doubly linked list." << endl;
    }

    // Function to display the elements of the doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "Doubly linked list is empty." << endl;
            return;
        }
        cout << "Doubly linked list elements: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete the first occurrence of a given value from the doubly linked list
    void remove(int value) {
        if (head == nullptr) {
            cout << "Doubly linked list is empty. Deletion failed." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            cout << "Deleted " << value << " from the doubly linked list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Element " << value << " not found in the doubly linked list. Deletion failed." << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp;
        }
        delete toDelete;
        cout << "Deleted " << value << " from the doubly linked list." << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display();

    list.remove(20);
    list.remove(50);

    list.display();

    return 0;
}