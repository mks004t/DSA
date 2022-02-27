#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int i,int j)
{
	while(j>i)
	{	if(s[i]!=s[j])
		   return false;     
		i++;
		j--;
	}
	return true;
}
// Recursice solution
int pCut(string s,int i,int j)
{
	if(isPalindrome(s,i,j))
	   return 0;

	int res=INT_MAX;
	for(int k=i; k<j; k++)
	{
		res=min(res, 1+pCut(s,i,k) + pCut(s,k+1,j) );
	}
	return res;
}

//DP Solution  (N^3)
int pCutDP(string str)
{
	int n=str.length();
	int dp[n][n];

	for(int i=0; i<=n; i++)
		dp[i][i]=0;

	for(int gap=1; gap<n; gap++)
	{
		for(int i=0; i+gap<n; i++)
		{
			int j=i+gap;
			if(isPalindrome(str,i,j))
				dp[i][j]=0;

			else
			{
				dp[i][j]=INT_MAX;
				for(int k=i; k<j; k++)
				{
					dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	return dp[0][n-1];
}

//DP Solution Some Modification but time comp still same i.e O(N^3)
// We are just try to optimise isPalindrome Check.

int pCutDP_modification(string str)
{
	int n=str.length();
	int dp[n][n];
	bool isPal[n][n];

	for(int i=0; i<n; i++)
	{   dp[i][i]=0; 
		isPal[i][i]=true;  }
	
	for(int gap=1; gap<n; gap++)
	{
		for(int i=0; i+gap<n; i++)
		{
			int j = i+gap;

			if(str[i]==str[j] && (isPal[i+1][j-1] || gap==1))
			  {
				dp[i][j]=0;  
				isPal[i][j]=true;
			  }
			else
		   	{	isPal[i][j]=false;
		   		dp[i][j]=INT_MAX;

		   		for(int k=i; k<j; k++)
		   			dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
			}
		}
	}
	return dp[0][n-1];
}


int main()
{
	string s;
	getline(cin,s);
	int n= s.length();
	cout<<pCut(s,0,n-1);
	cout<<pCutDP(s);
	cout<<pCutDP_modification(s);
	return 0;
}