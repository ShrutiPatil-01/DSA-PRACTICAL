#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertNode(Node* &head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << newData << " at the beginning." << endl;
}

// Function to delete a node from the linked list by value
void deleteNode(Node* &head, int value) {
    Node* temp = head;
    Node* prev = nullptr;

    // If head node itself holds the value to be deleted
    if (temp != nullptr && temp->data == value) {
        head = temp->next;  // Changed head
        delete temp;        // Free old head
        cout << "Deleted " << value << " from the list." << endl;
        return;
    }

    // Search for the node to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == nullptr) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;  // Free memory
    cout << "Deleted " << value << " from the list." << endl;
}

// Function to display the linked list
void displayList(Node* head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete the entire linked list to free memory
void deleteList(Node* &head) {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    cout << "Deleted entire linked list." << endl;
}

int main() {
    Node* head = nullptr;  // Initialize empty list

    // Insert nodes
    insertNode(head, 3);
    insertNode(head, 7);
    insertNode(head, 12);
    insertNode(head, 9);

    // Display nodes
    displayList(head);

    // Delete nodes
    deleteNode(head, 7);
    deleteNode(head, 3);
    deleteNode(head, 20);  // Delete a value not in the list

    // Display nodes after deletion
    displayList(head);

    // Delete entire list
    deleteList(head);

    return 0;
}
