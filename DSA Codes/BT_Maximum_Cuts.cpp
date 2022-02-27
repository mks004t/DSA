#include<bits/stdc++.h>
using namespace std;
//Maximum cuts of given lengths a,b,c.

// DP Solution           O(N)
int MaxCut(int n,int a,int b,int c)
{
	int dp[n+1];
	dp[0]=0;
	for(int i=1; i<=n; i++)  //i is the length of roads
	{    dp[i]=-1;
		if(i-a >=0)  dp[i] = max(dp[i], dp[i-1]);
		if(i-b >=0)  dp[i] = max(dp[i], dp[i-1]);
		if(i-c >=0)  dp[i] = max(dp[i], dp[i-1]);

		if(dp[i]!= -1)
			dp[i]++;
	}
	return dp[n];
}
 

//Recursive solution     O(3^N)
int MaxCutREC(int n,int a,int b,int c)
{
	if(n<0)  
		return -1;
	if(n==0)
		return 0;

    int result =max(max(MaxCutREC(n-a,a,b,c),
    	             MaxCutREC(n-b,a,b,c)),
                     MaxCutREC(n-c,a,b,c));
    if(result==-1)
    	return result;
    else
    	return result+1;
}


int main()
{
	int n=5,a=1,b=2,c=3;
//    cout<<MaxCutREC(n,a,b,c);
    cout<<MaxCut(n,a,b,c);
	return 0;

}