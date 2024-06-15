#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // Return the index of the element if found
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    int result = linearSearch(arr, n, x);

    if (result == -1)
        cout << "Element " << x << " is not present in the array" << endl;
    else
        cout << "Element " << x << " is present at index " << result << endl;

    return 0;
}
