#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop element." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    return 0;
}

