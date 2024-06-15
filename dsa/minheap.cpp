#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to display the elements of the heap
    void display() {
        cout << "Min Heap Tree: ";
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;

    // Insert elements into the min heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(5);

    // Display the min heap
    minHeap.display();

    return 0;
}

