#include<bits/stdc++.h>
using namespace std;
//time comp is O(log n)
int countOne(int arr[],int size)
{ int low=0,high=size-1;
	while(low<=high)
	{   int mid=(low+high)/2;
		if(arr[mid]==0)
			low=mid+1;
		else
		{
			if(mid==0||arr[mid-1]!=arr[mid])
				return size-mid;
			else
				high=mid-1;

		}
	}
 return 0;
}
int main()
{ int arr[]={0,0,0,1,1,1,1,1,1,1};

	int size =sizeof(arr)/sizeof(arr[0]);
	cout<<countOne(arr, size);
	return 0;
}