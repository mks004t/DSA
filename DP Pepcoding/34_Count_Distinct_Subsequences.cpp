#include<bits/stdc++.h>
using namespace std;

int CountSub(string s)
{
	vector<int> last(256,-1);

	int n=s.length();
	int dp[n+1];
	dp[0]=1;

	for( int i=1; i<=n; i++)
	{
		dp[i] = 2*dp[i-1];

		if(last[s[i-1]]!=-1)
		   dp[i] = dp[i] - dp[last[s[i-1]]];

		last[s[i-1]]=(i-1);
	}
  return dp[n];
}
// pepcoding 
int countSub(string s)
{
	int n=s.length();
	
	int dp[n+1];
	dp[0]=1;

	unordered_map<char,int>mp;

	for(int i=1; i<=n; i++)
	{
		dp[i]=2*dp[i-1];

		char ch=s[i-1];

		if(mp.find(ch)!= mp.end())  // ch is present in map
		{   
			int j=mp[ch];
			dp[i]=dp[i]-dp[j-1];
		}
		mp[ch]=i;
	}

return dp[n];
}


int main()
{   string s="gfg";
    cout << CountSub(s)<<endl;
    cout << countSub(s);
    return 0;
}
// input : gfg
// output : 7 with empty string 
// without empty string 6 (return dp[n]-1 ;) 