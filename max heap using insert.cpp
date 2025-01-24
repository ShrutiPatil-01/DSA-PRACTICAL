//max heap using insert
#include<iostream>
using namespace std;
void max_heap(int *a , int m, int n)//*a-pointer array
{
	int j, t;
	t = a[m];
	j = 2 * m;//m-poisition index , left child calculate
	while(j<=n)//n-size of array
	{
		if(j<n && a[j+1] > a[j])
		   j = j + 1; //right child calculate
		if(t > a[j])
		   break;
		else if(t<=a[j])
		{
			a[j/2] = a[j];
			j = 2 * j;
		}
	}
	a[j/2] = t;//t-parent node
	return;
}
void build_maxheap(int *a, int n)
{
	int k;
	for(k = n/2; k>=1; k--)//traversing all non-leaf nodes
	{
		max_heap(a,k,n);
	}
}
int main()
{
	int n, i;
	cout<<"Enter the no of elements of array\n";
	cin>>n;
	int a[30];
	for(i=1;i<=n;i++)
	{
		cout<<"Enter elemets"<<" "<<(i)<<endl;
		cin>>a[i];
	}
	build_maxheap(a,n);
	cout<<"Max Heap\n";
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
}
