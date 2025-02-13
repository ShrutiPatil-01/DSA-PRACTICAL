#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < n && arr[1] > arr[largest])
	largest = l;
	
	if (r < n && arr[1] > arr[largest])
	largest = r;
	
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void buildMaxHeap(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n , i);
	
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	cout << arr[i] << " ";
	
	cout << "\n";
}

int main(){
	int arr[] = {4, 10, 3, 5, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << "original array: ";
	printArray(arr, n);
	
	buildMaxHeap(arr, n);
	
	cout << "Max Heap: ";
	printArray(arr, n);
	
	return 0;
}
