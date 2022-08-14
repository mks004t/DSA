#include<bits/stdc++.h>
using namespace std;

// Move all zeroes to right size of array
void solveEffective(int (&arr)[8],int n)
{
	int count =0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			swap(arr[i],arr[count]);
			count++;
		}
	}
}

// Or
void solve(int (&arr)[8],int n)
{
	int slow=0,fast=1;

	while(fast<n)
	{
		if(arr[slow]==0 && arr[fast]!=0)
		{
			swap(arr[slow],arr[fast]);
			slow++;
			fast++;
		}
		else if(arr[slow]==0 && arr[fast]==0)
		{
			fast++;
		}
		else
		{   slow++;
			fast++;
		}
	}
}


int main()
{
	int arr[]={10,5,0,0,8,0,9,0};
	int n= sizeof(arr)/sizeof(arr[0]);

	solveEffective(arr,n);
	for(int i=0;i<n;i++ )
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}