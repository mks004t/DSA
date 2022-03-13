#include<bits/stdc++.h>
using namespace std;


int countPS(string s)
{
	int n=s.length();
	int dp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{
			if(gap==0)
				dp[i][j]=1;

			else if(gap==1)
			{
				if(s[i]==s[j])
					dp[i][j]=3;
				else
					dp[i][j]=2;
			}

			else
			{
				if(s[i]==s[j])
				{
					dp[i][j] = 1+dp[i][j-1]+dp[i+1][j];  //  prefix + suffix +1
				}
				else
				{
					dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];  // prefix + suffix - diagonal(middle part)
				}
			}
		}
	}

	return dp[0][n-1];
}


int main()
{
    string str = "abcb";
    cout << "Total palindromic subsequence are : "
         << countPS(str) << endl;
    return 0;
}

//OUTPUT : 6