#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
int mChain(int arr[],int i,int j) //i = starting add j is end-1 add.
{
	if(i+1 == j)
		return 0;

	int res=INT_MAX;

	for(int k=i+1; k<j; k++)
	{
		res = min(res, mChain(arr,i,k) + mChain(arr,k,j) + arr[i]*arr[k]*arr[j] );
	}
	return res;
}

//DP Solution			O(N*N*N)
int mChainDP(int arr[], int n)
{ int dp[n][n];

	for(int i=0; i<n-1; i++)
		dp[i][i+1]=0;

	for(int gap=2; gap<n; gap++)
	{
		for(int i=0; i+gap<n; i++)
		{
			int j=i+gap;
			dp[i][j]=INT_MAX;
			for(int k=i+1; k<j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j] );
			}
		}
	}
   return dp[0][n-1];
}

int main()
{
	int arr[]={1,2,3,4,3};
	int n= 5;
	cout<<mChain(arr,0,n-1)<<endl;
	cout<<mChainDP(arr,n);
	return 0;
}