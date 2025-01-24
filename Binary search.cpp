//Binary search 
#include <iostream>
#include <ctime>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) 
{
 while (l <= r) 
{
 int mid = l + (r - l) / 2;
 if (arr[mid] == x)
 return mid;
 if (arr[mid] < x)
 l = mid + 1;
 else
 r = mid - 1;
}
 return -1;
}
void measureExecutionTime(int n) 
{
 int arr[n];
 for (int i = 0; i < n; i++) 
{
 arr[i] = i; 
}
 int x = n - 1;
 clock_t start = clock(); 
 int result = binarySearch(arr, 0, n - 1, x);
 clock_t end = clock(); 
 double time_taken = double(end - start) / CLOCKS_PER_SEC;
 if (result != -1) 
{
 cout << "Element found at index " << result << " in array of size " << n << 
endl;
} 
else 
{
 cout << "Element not found in array of size " << n << endl;
}
 cout << "Time taken for binary search: " << time_taken << " seconds" << 
endl;
}
int main() 
{
 measureExecutionTime(1000);
 measureExecutionTime(2000);
 measureExecutionTime(3000);
 return 0;
}
 
