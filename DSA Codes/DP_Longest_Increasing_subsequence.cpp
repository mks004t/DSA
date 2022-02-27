#include<bits/stdc++.h>
using namespace std;

//Longest increasing Subsequence(LIS)
// Time cpmlexity O(N*N) for DP

//DP solution

int LIS(int arr[], int n)
{
	int lis[n];
	lis[0]=1;

//built LIS array	
	for(int i=1; i<n; i++)
	{
		lis[i]=1;
		for(int j=0; j<i; j++)
		   {                
		      if(arr[i] > arr[j])      
		    	lis[i]= max(lis[i], lis[j]+1); 
		   }
	}

//Find the max of LIS value	
	int result =lis[0];
	for(int i=1; i<n; i++)
		result = max(result , lis[i]);
  
    return result;
}

int main()
{
	int arr[]={10,5,18,7,2,9};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}