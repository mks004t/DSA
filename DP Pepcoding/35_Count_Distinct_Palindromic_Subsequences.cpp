#include<bits/stdc++.h>
using namespace std;

int countDistPalindrome(string s,int n)
{
	int dp[n][n];

	int next[n];
	int prev[n];

	unordered_map<char,int> mp;
//record of next 
	for(int i=0;i<n;i++)
	{
		char ch=s[i];

		if(mp.find(ch)==mp.end())
			prev[i]=-1;
		else
			prev[i]=mp[ch];

		mp[ch]=i;
	}

	mp.clear();

//record of previous
	for(int i=n;i>=0;i--)
	{
		char ch=s[i];

		if(mp.find(ch)==mp.end())
			next[i]=-1;
		else
			next[i]=mp[ch];

		mp[ch]=i;
	}
   
//DP solution
   for(int gap=0; gap<n; gap++)
   {
   		for(int i=0,j=gap; j<n; i++,j++)
   		{
   			if(gap==0)
   				dp[i][j]=1;

   			else if (gap==1)
   			    dp[i][j]=2;

   			else
   			{
   				if(s[i]==s[j])
   					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
   							  // suffix + prefix - middle(repeating)
   				else
   				{
   					int nnext=next[i];
   					int pprev=prev[j];

   					if(nnext > pprev)
   					{
   						dp[i][j] = 2*dp[i+1][j-1] + 2;  //twice of middle part + 2
   					}
   					else if(nnext == pprev)
   					{
   						dp[i][j] = 2*dp[i+1][j-1] + 1;  //twice of middle part + 1
   					}
   					else
   					{
   						dp[i][j] = 2*dp[i+1][j-1] - dp[nnext+1][pprev-1];   //twice of middle part - special middle part
   					}


   				}
   			}
   		}
   }

  return dp[0][n-1];
}

int main()
{
   string str="bccb";
   int n=str.length();
   cout<<countDistPalindrome(str,n);
}