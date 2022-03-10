#include<bits/stdc++.h>
using namespace std;
//way 1 : find the lcs of s1,reverseof(s1), copy

//Way 2 : gap method
int lps(string s,int n)
{
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
					dp[i][j]=2;
				else
					dp[i][j]=1;
			}
			
			else
			{
				if(s[i]==s[j])
					dp[i][j] = 2 + dp[i+1][j-1];
				else
					dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][n-1];
}

int main()
{
    string seq = "GEEKS FOR GEEKS";
    int n = seq.size();
    
    cout << "The length of the LPS is "
         << lps(seq, n) << endl;
    return 0;
}

//OUTPUT : 7