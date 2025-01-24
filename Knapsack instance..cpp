//write a program to fractional Knapsack instance.
#include <iostream>
#include <algorithm>
using namespace std;
struct Item 
{
 int weight;
 int profit;
};
double fractionalKnapsack(int capacity, Item items[], int n) 
{
 double ratio[n];
 for (int i = 0; i < n; i++) 
 {
   ratio[i] = (double)items[i].profit / items[i].weight;
 }
  for (int i = 0; i < n - 1; i++) 
  {
    for (int j = i + 1; j < n; j++) 
	{
      if (ratio[i] < ratio[j]) 
	  {
        swap(ratio[i], ratio[j]);
		swap(items[i], items[j]);
      }
    }
  }
 double maxProfit = 0.0; 
 int currentWeight = 0; 
 for (int i = 0; i < n; i++) 
{
 if (currentWeight + items[i].weight <= capacity) 
 {
   currentWeight += items[i].weight;
   maxProfit += items[i].profit;
 } 
 else 
 {
   int remainingCapacity = capacity - currentWeight;
   maxProfit += ratio[i] * remainingCapacity; 
   break;
 }
}
 return maxProfit; 
}
int main() 
{
 int n, capacity; 
 cout << "Enter the number of items: ";
 cin >> n;
 cout << "Enter the capacity of the knapsack: ";
 cin >> capacity;
 Item items[n];
 for (int i = 0; i < n; i++) 
 {
   cout << "Enter weight and profit for item " << i + 1 << ": ";
   cin >> items[i].weight >> items[i].profit;
 }
 double maxProfit = fractionalKnapsack(capacity, items, n);
 cout << "Maximum profit: " << maxProfit << endl;
 return 0;  
}
