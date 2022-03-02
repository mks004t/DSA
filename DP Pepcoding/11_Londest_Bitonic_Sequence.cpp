#include<bits/stdc++.h>
using namespace std;
int LBS(int arr[], int n)
{	int dp[n];    //increasing
	int dpRev[n];  //decreasing
	dp[0]=1;
	dpRev[n-1]=1;

//Longest Increasing sequence 
	for(int i=1; i<n; i++)
	{	dp[i]=1;
		for(int j=0;j<i;j++)
		{	
			if(arr[i]>arr[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}	
//Longest Decreasing sequence 
	for(int i=n-2;i>=0;i--)
	{	dpRev[i]=1;
		for(int j=n-1;j>i;j--)
		{	
			if(arr[i]>arr[j])
				dpRev[i]=max(dpRev[i],dpRev[j]+1);
		}
	}
//Longest Bitonic Sequence= first increasing then decreasing
int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{   cout<<dp[i]<<" "<<dpRev[i]<<endl;
		
		ans=max(ans,dp[i]+dpRev[i]-1);
	}
	return ans;
}
int main()
{
	int arr[]={10,5,18,7,2,9};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<LBS(arr,n);
	return 0;
}