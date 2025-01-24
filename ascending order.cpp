#include <iostream>    
#include <cstdlib>   
#include <ctime> 
using namespace std;
void merge(int arr[], int left, int mid, int right) 
{
 int n1 = mid - left + 1; 
 int n2 = right - mid;
 int L[n1], R[n2]; 
 for (int i = 0; i < n1; i++)
 L[i] = arr[left + i];
 for (int j= 0; j < n2; j++)
 R[j] = arr[mid + 1 + j];
 int i = 0;  
 int j = 0;  
 int k = left; 
 while (i < n1 && j < n2) 
{
 if (L[i] <= R[j]) 
{
 arr[k] = L[i];   
 i++;
} 
else 
{ 
 arr[k] = R[j];
 j++;   
}
 k++; 
}
 while (i < n1) 
{
 arr[k] = L[i];
 i++; 
 k++; 
}
 while (j < n2) 
{
 arr[k] = R[j];
 j++; 
 k++; 
} 
}
void mergeSort(int arr[], int left, int right) 
{
 if (left < right) 
{
 int mid = left + (right - left) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, left, mid, right);
}
}
void measureExecutionTime(int n)
{
 int arr[n]; 
 for (int i = 0; i < n; i++)
{
 arr[i] = rand() % 10000;  
}
 clock_t start = clock(); 
 mergeSort(arr, 0, n - 1); 
 clock_t end = clock(); 
 double time_taken = double(end - start) / CLOCKS_PER_SEC; 
 cout << "Time taken for merge sort on array of size " << n << " in Ascending order: " << time_taken << " seconds" << endl;  }
int main() 
{
 srand(time(0)); 
 measureExecutionTime(1000); 
 measureExecutionTime(2000);
 measureExecutionTime(3000); 
  return 0; 
}
