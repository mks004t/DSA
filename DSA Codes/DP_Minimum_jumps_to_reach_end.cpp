#include<bits/stdc++.h>
using namespace std;
//Recursive Solution   O(N*N)
int minJumps(int arr[],int n)
{
	int dp[n];
    dp[0]=0;
	for(int i=1;i<n;i++)
		dp[i]=INT_MAX;

	for(int i=1;i<n;i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]+j >=i)
			{
				if(dp[j]!=INT_MAX)
					dp[i]= min( dp[i], dp[j]+1);
			}
		}
	}
	return dp[n-1];
}


//Recursive Solution    
int minJumpsREC(int arr[] , int n)
{	
	if(n==1) return 0;

	int res=INT_MAX;

	for(int i=0; i<=n-2; i++)
	{
		if( i+arr[i]>=n-1 )// jis value se hum end tk ja sakte hai only include that.
		{
			int sub_res =minJumpsREC(arr,i+1);
			
			if(sub_res!=INT_MAX)
				res=min(res, sub_res+1);
		}
	}
   return res;
}


int main()
{   int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	
//	cout<<minJumpsREC(arr,n);
    cout<<minJumps(arr,n);

	return 0;
}

/* input
6
3 4 2 1 2 1

output
2
*/