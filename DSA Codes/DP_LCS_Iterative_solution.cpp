#include<bits/stdc++.h>
using namespace std;
//O(m*n)
// LCS and PRINT LCS
int lcs(string s1,string s2)
{
	int m=s1.length();
	int n=s2.length();
    
    int dp[m+1][n+1];

	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;

	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
//	return dp[m][n];   // 

	//print LCS

	int index = dp[m][n];

	char LCS[index+1];
	LCS[index]='\0';

	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			LCS[index-1]=s1[i-1]; //it can be s1 or s2
			i--;
			j--;
			index--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}

	cout<<"LCS of"<<s1<<" and "<<s2<<" is "<<LCS<<endl;
	
	return dp[m][n]; 
}

int main()
{   string s1,s2;
	cin>>s1;
	cin>>s2;
    cout<<lcs(s1,s2);

	return 0;
}