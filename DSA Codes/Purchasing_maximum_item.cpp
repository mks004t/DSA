#include <bits/stdc++.h>

using namespace std;

void MaxItem(int arr[],int size,int sum)
{   int noItem=0;
	priority_queue<int ,vector<int>, greater<int>> pq(arr,arr+size);
	for(int i=0;i<size;i++)
	{  
		if(sum-arr[i]>=0 && pq.empty()==false)
		{
			cout<<arr[i]<<" ";
			noItem++;
			sum-=arr[i];
			pq.pop();
		}
	}
	cout<<endl<<"No of Items Purchased "<<noItem;
}

int main()
{ int cost[]={1,12,5,111,20};
  int sum=10;
  int size =sizeof(cost)/sizeof(cost[0]);
  MaxItem(cost,size,sum);

	return 0;
}