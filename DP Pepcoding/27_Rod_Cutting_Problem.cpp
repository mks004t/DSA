#include<bits/stdc++.h>
using namespace std;

// Check my notebook 

// Unbounded KnapSack Based Solution
//Time comp:O(N*N)  Space:O(N)
int cutRodK(int arr[],int n)
{
	int dp[n+1];

	for(int i=0; i<=n; i++)  // "i" is leangth array
	{
		dp[i]=0;
		for(int j=1; j<=n; j++)
		{
			if(i>=j)    
				dp[i]=max(dp[i],dp[i-j]+arr[j-1]);
		}
	}
	return dp[n];
}

//Left right solution

//Time comp:O(N*N)  Space:O(N)

int cutRod(int arr[],int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=arr[0];

	for(int i=2; i<=n; i++)
	{
		dp[i]=arr[i-1];

		int li=1;
		int ri=i-1;

		while(li <= ri)
		{
			dp[i]=max(dp[i],dp[li]+dp[ri]);
			li++;
			ri--;
		}
	}

	return dp[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout <<"Maximum Obtainable Value is "<<cutRod(arr, size)<<endl;
    cout<<cutRodK(arr, size);
    return 0;
}
// OutPut: 22