#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int s,int e)
{
	int res=0;
	for(int i=s; i<=e; i++)
		res+=arr[i];
	return res;
}
//Recursice Solution   O(exponential)
int minPage(int arr[], int n, int k)
{
	if(k==1)
		return sum(arr,0,n-1);
	if(n==1)
		return arr[0];
	
	int res=INT_MAX;
	for(int i=0; i<n; i++)
		res=min(res, max( minPage(arr,i,k-1), sum(arr,i,n-1)) );
	                     //for   k-1 students , for current student
	return res;
}
int minPageDP(int arr[],int n,int k)
{
	int dp[k+1][k+1];
	
	for(int i=1; i<=n; i++)       //O(N^2)
		dp[1][i]=sum(arr,0,i-1);

	for(int i=1; i<=k; i++)       //O(K)
		dp[i][1]=arr[0];

	for(int i=2; i<=k; i++)       //O(N^3 *K)
	{
		for(int j=2; j<=n; j++)   
		{
			int res= INT_MAX;
			for(int p=1; p<j; p++)
			{
				res=min( res,max(dp[i-1][p], sum(arr,p,j-1) ));
			}
			dp[i][j]=res;
		}
	}
  return dp[k][n];
}

int main()
{
	int arr[]={10,20,30,40};
	int n=4;
	int k=2;  //No of students
	cout<<minPage(arr,n,k);
	cout<<minPageDP(arr,n,k);
	return 0;
}
