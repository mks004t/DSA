#include<bits/stdc++.h>
using namespace std;
//  * can be any one character 
//  ? can be any char/ string  

bool wildcard( string str, string pattern )
{
	int n = str.length();
	int m = pattern.length();
    
    bool dp[m+1][n+1];

	for(int i=m; i>=0; i--)
	{
		for(int j=n; j>=0; j--)
		{
			if( i==m && j==n) //  (0,0)last row and last column
			{
				dp[i][j]=true;
			}
			
			else if( i == m)
			{
				dp[i][j]=false; // last column
			}
			
			else if(j == n)
			{
				if(pattern[i]=='*')
					dp[i][j] = dp[i+1][j];
				
				else
					dp[i][j]=false;
			}

			else
			{
				if(pattern[i]=='?')  //see diagonal
				{
					dp[i][j] = dp[i+1][j+1];
				}
				else if(pattern[i]=='*')  // see or of vertical , horizontal
				{
					dp[i][j] = dp[i+1][j] || dp[i][j+1] ;
				}
			    else if(pattern[i]==str[j])  //see diagonal
			    {
			    	dp[i][j] = dp[i+1][j+1];
			    }
			    else   // pattern not matched with string 
			    {
			    	dp[i][j] = false;
			    }

			}
		}
	}

	return dp[0][0];
}

int main()
{
	string str = "baaabab";
	string pattern ="ba*a?";
	cout<<wildcard(str,pattern);
}