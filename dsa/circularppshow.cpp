#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the circular queue

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Circular queue is full. Push operation failed." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Pushed " << value << " into the circular queue." << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Circular queue is empty. Pop operation failed." << endl;
            return;
        }
        int removedValue = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Popped " << removedValue << " from the circular queue." << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Circular queue is empty." << endl;
            return;
        }
        cout << "Circular queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};
int main() {
    CircularQueue cq;
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.display();
    cq.pop();
    cq.pop();

    cq.display();
    return 0;
}
