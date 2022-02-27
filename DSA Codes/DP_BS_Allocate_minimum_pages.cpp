#include<bits/stdc++.h>
using namespace std;

bool isfeasible(int arr[], int n, int k, int ans)
{
	int req=1, sum =0;
	
	for(int i=0; i<n; i++)
	{
		if(sum+arr[i]>ans)
		{
			req++;
			sum=arr[i];
		}

		else
			sum+=arr[i];
	}
	return (req<=k);
}


int minPage(int arr[],int n,int k)
{
	int sum=0, mx=0;

	for(int i=0; i<n; i++)
	{	sum+=arr[i];
		mx=max(mx,arr[i]);
	}

	int low =mx, high=sum, res=0;
	while(high >= low)
	{
		int mid = (low+high)/2;
		if(isfeasible(arr,n,k,mid))
		{
			res=mid;
			high= mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return res;
}

int main()
{
	int arr[]={10,20,30,40};
	int n=4;
	int k=2;  //No of students
	cout<<minPage(arr,n,k);
	return 0;
}
