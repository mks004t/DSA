#include<bits/stdc++.h>
using namespace std;
//must watch video to understand.

//Recursive solution 
int getCount(int coins[],int n,int sum)
{
	if(sum==0)  return 1;
	if(n==0)   return 0;

	int result=getCount(coins,n-1,sum);
	if(coins[n-1] <= sum)
		result=result + getCount(coins,n,sum-coins[n-1]);

	return result;
}

// dp solution O(sum*n) time and space comp.
// cam be optimised further
int getCountDP(int coins[],int n,int sum)
{
	int dp[sum+1][n+1];
	
	for(int i=0;i<=n;i++)
		dp[0][i]=1;
	
	for(int i=1;i<=sum;i++)
		dp[i][0]=0;
	
	for(int i=1; i<=sum; i++)   //sum 
	  for(int j=1; j<=n; j++)   //coins
	  {
	  	dp[i][j]=dp[i][j-1];
	  	
	  	if(coins[j-1] <= i)
	  	   dp[i][j] += dp[i-coins[j-1] ][j];
	  }
  return dp[sum][n];
}

int main()
{
	int coins[]={2,5,3,6};
    int sum=10;
    int n=sizeof(coins)/sizeof(coins[0]);
    cout<<getCountDP(coins,n,sum);

    return 0;
}