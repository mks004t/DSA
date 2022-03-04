#include<bits/stdc++.h>
using namespace std;

int MCM(int arr[],int n)
{
	int dp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{	
			if(gap==0)
				dp[i][j]=0;

			else if(gap==1)
				 dp[i][j]=arr[i]*arr[j]*arr[j+1];
			
			else
			{    for(int k=i; k<j; k++)
				{
					dp[i][j]=INT_MAX;

				    int left  = dp[i][k];
					int right = dp[k+1][j];
					int val   = arr[i]*arr[k+1]*arr[j+1];
					int total = left+right+val;

					dp[i][j]=min(dp[i][j], total); 
				}
			}
		}
	}

	return dp[0][n-1];
}

int main()
{
	int arr[]={1,2,3,4};
	int n=4;
	cout<<MCM(arr,n-1);  // n-1 must

	return 0;
}