#include<bits/stdc++.h>
using namespace std;

// Recursice solution 1 (can not be convert int DP bec of large sum)

int solRec1(int arr[], int s, int e,int sum )
{
	if(e==s+1) 
		return max(arr[s],arr[e]);
	return max(sum-solRec1(arr,s+1,e,sum-arr[s]),
		       sum-solRec1(arr,s,e-1,sum-arr[e]));
}
int mainSol(int arr[],int n)
{
	int sum=0;
	for(int i=0; i<n; i++)  //Total sum of array
		sum+= arr[i];
	return solRec1(arr,0,n-1,sum);
}

//Recursive Solution 2(can be convert into DP)

int solRec2(int arr[], int s,int e)
{
	if(s+1==e)
	 return max(arr[s],arr[e]);

	return max(arr[s] + min(solRec2(arr,s+2,e), solRec2(arr,s+1,e-1)),
		        arr[e]+ min(solRec2(arr,s,e-2), solRec2(arr,s+1,e-1)) );
} 

//DP Solution       O(N*N)

int sol(int arr[],int n)
{
	int dp[n][n];
	for(int i=0; i<n-1; i++)
	   dp[i][i+1]=max(arr[i],arr[i+1]);

	for(int gap=3; gap<n; gap=gap+2)
	    for(int i=0; i+gap<n; i++)
	    {
	    	int j=i+gap;
	    	dp[i][j]=max( arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
	    		          arr[j] + min(dp[i+1][j-1], dp[i][j-2]) );
	    }

  return dp[0][n-1];
}

int main()
{   int arr[]={20,5,4,6,8,3};
    int size=6;
    cout<<mainSol(arr,size);
    cout<<endl;
    cout<<solRec2(arr,0,size-1);
    cout<<endl;
    cout<<sol(arr,size);

	return 0;
}