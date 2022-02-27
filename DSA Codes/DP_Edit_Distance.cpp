#include<bits/stdc++.h>
using namespace std;

//Recursion

int editDist(string s1,string s2,int m,int n)
{
	if(m==0) return n;  //i.e s1 is empty, insert all remanin element from s2
	
	if(n==0) return m;  //i.e s2 is empty, delete all element from s1

	if(s1[m-1] == s2[n-1])
		return editDist(s1,s2,m-1,n-1);
	else                                     //min of all three
		return 1+ min(min(editDist(s1,s2,m,n-1),      // insert
			          editDist(s1,s2,m-1,n)),      // delete
			          editDist(s1,s2,m-1,n-1) );  // replace
   
}

// DP   O(m*n)

int editDistDP(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++)
		dp[i][0]=i;
	
	for(int i=0;i<=n;i++)
		dp[0][i]=i;

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=1+ min(min(dp[i-1][j], dp[i][j-1] ), dp[i-1][j-1]);
		}
  return dp[m][n];
}

int main()
{  string s1,s2;
	cin>>s1;
	cin>>s2;
	int m=s1.length();
	int n=s2.length();

	cout<<editDistDP(s1,s2,m,n);
	return 0;
}