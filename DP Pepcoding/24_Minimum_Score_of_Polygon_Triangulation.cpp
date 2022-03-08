#include<bits/stdc++.h>
using namespace std;

//Application of MCM (Gap Method) 
// find the min sum of all the the triangles formed by the given sides
int minSumtrangle(int arr[],int n) // n is size of array
{
	int dp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{
			if(gap==0 || gap==1)
				dp[i][j]=0;

			else if(gap==2)
				dp[i][j]=arr[i]*arr[i+1]*arr[i+2];

			else
			{
				dp[i][j]=INT_MAX;
				for(int k=i+1; k<j; k++)
				{
					int tri = arr[i]*arr[k]*arr[j];
					int left = dp[i][k];
					int right = dp[k][j];

					int total=tri+left+right;

					dp[i][j]=min(dp[i][j],total);
				}
			}
		}
	}
	return dp[0][n-1];
}

int main()
{
	int arr[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<minSumtrangle(arr,n);

	return 0;
}
