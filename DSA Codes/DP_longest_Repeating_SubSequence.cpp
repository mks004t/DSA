#include<bits/stdc++.h>
using namespace std;

//Longest Repeating Subsequence 
int LRS(string s,int m )
{ int dp[m+1][m+1];
	for(int i=0;i<=m;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==s[j-1] && i!=j)
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}

	return dp[m][m];
}
int main()
{
	string s;
	cin>>s;
int m=s.length();
	cout<<LRS(s,m);
	return 0;
} 

/* INPUT:  -
AABEBCD
OUTPUT :  3    i.e(ABD)
*/