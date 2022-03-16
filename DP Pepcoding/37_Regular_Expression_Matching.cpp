#include<bits/stdc++.h>
using namespace std;

//  . can match to any one char 
//  * combile with previous char and form its multiple including null

bool regularExpr(string s, string p)
{
	int n = s.length();
	int m = p.length();
	bool dp[m+1][n+1];

	for(int i=0;i<m;i++)
	{
		for(int j=0; j<n; j++)
		{
			if( i==0 && j==0)  // (0,0)
				dp[i][j]=true;
			
			else if(i==0)
			{
				dp[i][j]=false;
			}
			else if(j==0)
			{
				if(p[i-1]=='*')  // go 2 rows back
					dp[i][j]=dp[i-2][j];
				
				else
					dp[i][j]=false;	
			}
			else
			{
				if(p[i-1]=='*')
				{
					dp[i][j]=dp[i-2][j];  // assume that 2 char
					
					char pslc = p[i-2];   // second last char of pattern

					if(pslc=='.' || pslc == s[j-1])
						dp[i][j] = dp[i][j] || dp[i][j-1];

				}
				else if(p[i-1]=='.')      // see diagonal
				{
					dp[i][j] = dp[i-1][j-1];
				}
				else if(p[i-1]==s[j-1])  // see diagonal
				{
					dp[i][j] = dp[i-1][j-1];
				}
				else
				{
					dp[i][j] = false;
				}
			}

		}
	}
	
	return dp[m][n];
}
int main()
{
	string str = "mississippi";
	string pattern ="mis*i.*p*i";
	cout<<regularExpr(str,pattern);
}