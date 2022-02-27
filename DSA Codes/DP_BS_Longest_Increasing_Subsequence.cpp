#include<bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence.
//Time Complexity : O( N*Log N )
//Auxiliary Space : O(N)

//Binary Search
int ceilIndex(int arr [],int L,int R,int X)
{                      
	while( R > L )    // L & R is the starting and ending position of arr.
	{
		int mid=L+(R-L)/2;   //or mid =(L+R)/2
		
		if(arr[mid] >= X)
			R=mid;
		else
			L=mid+1;
	}
	return R;
}


int LIS(int arr[] ,int n)
{
	int tail[n];
	int len=1;

	tail[0] = arr[0];

	for(int i=1; i<n; i++)
	{
		if(arr[i] > tail[len-1])
		{ 
			tail[len]= arr[i];
			len++;
		}
		else
		{
			int c = ceilIndex(tail,0,len-1,arr[i]);
			tail[c]=arr[i];
		}
	}
	return len;
}


int main()
{
	int arr[]={10,5,18,7,2,9};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}