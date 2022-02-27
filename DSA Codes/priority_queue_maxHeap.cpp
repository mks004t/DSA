#include <bits/stdc++.h>

using namespace std;
//BY Using Max heap
void mySort(int arr[], int n)
{
	priority_queue<int> pq(arr,arr+n);  // syntax of priority queue using MAX heap
	for(int i=n-1;i>=0;i--)
	{
		arr[i]=pq.top();
		pq.pop();
		cout<<arr[i]<<" ";
	}
}

// By using min heap
void mySortmin(int arr[],int n)
{
	priority_queue<int ,vector<int>,greater<int>> pq(arr,arr+n); // Syntax of priority queue using Min heap
   for(int i=0;i<n;i++)
   {arr[i]=pq.top();
   	pq.pop();
   	cout<<arr[i]<<" ";

   }
}


int main ()
{ int arr[]={12,5,8};
  //mySort(arr,3);
  mySortmin(arr,3);
	return 0;
}
// time complexity of this program is O(n log n).