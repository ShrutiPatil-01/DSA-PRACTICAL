#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the linked list
    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << data << " into the linked list." << endl;
    }

    // Function to display the elements of the linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }
        cout << "Linked list elements: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for an element in the linked list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Function to calculate the sum of all elements in the linked list
    int sum() {
        int sum = 0;
        Node* temp = head;
        while (temp != nullptr) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display();

    int searchValue = 30;
    if (list.search(searchValue)) {
        cout << "Element " << searchValue << " is present in the linked list." << endl;
    } else {
        cout << "Element " << searchValue << " is not present in the linked list." << endl;
    }

    cout << "Sum of all elements in the linked list: " << list.sum() << endl;

    return 0;
}