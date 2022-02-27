#include <bits/stdc++.h>

using namespace std;
// Method 1
// time complexity will be O(n + K log n)  , not a efficient solution
void Klargest1 (int arr[],int n,int k)
{   int array[k];
	priority_queue<int> pq(arr,arr+n);  // O(n)
	
// O(k log n)
	for(int i=k-1;i>=0;i--)            //O(K)
	{
		array[i]=pq.top();
		pq.pop();                        //O(log n)
		
	}
	for(int i=0;i<k;i++)              // O(k), ignore it
	cout<<array[i]<<" ";
}

// Method 2
// efficient solution by using min heap of K elements
// O ( k+(n-k)log k)
void Klargest2(int arr[],int n,int k)
{
	priority_queue<int,vector<int>,greater<int>> pq(arr,arr+k);  //O(k)
	for(int i=k;i<n;i++)    
	{
		if(arr[i]>=pq.top())
		{  pq.pop();             //O(K)
			pq.push(arr[i]);

		}
	}

   while(pq.empty()==false)
   	  {
   	  	cout<<pq.top()<<" ";
   	  	pq.pop();
   	  }
}

int main()
{  int arr[]={5,15,10,20,8};
    int size =sizeof(arr)/sizeof(arr[0]);
    int k=2;
    Klargest2(arr,size,k);
	return 0;

}