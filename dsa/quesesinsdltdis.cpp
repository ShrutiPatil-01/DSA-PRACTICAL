#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void insert(int value) {
        if (isFull()) {
            cout << "Queue is full. Insertion failed." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << "Inserted " << value << " into the queue." << endl;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Queue is empty. Deletion failed." << endl;
            return;
        }
        int removedValue = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << "Removed " << removedValue << " from the queue." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);

    queue.display();

    queue.remove();
    queue.remove();

    queue.display();

    return 0;
}
