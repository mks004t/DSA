#include<bits/stdc++.h>
using namespace std;
//Print Shortest Common Super Sequence
void printSCS(string s1,string s2,int m,int n)
{
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++) { dp[i][0]=0; }
	for(int i=0;i<=n;i++) { dp[0][i]=0; }

	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(s1[i-1]==s2[j-1])
			dp[i][j] = 1 + dp[i-1][j-1];
		else
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
	}

	int l_SCS=m+n-dp[m][n];

	char SCS[l_SCS+1];
    SCS[l_SCS]='\0';

    int i=m,j=n;
    while(i>0 && j>0)
    {
    	if(s1[i-1]==s2[j-1])
    	{
    		SCS[l_SCS-1]=s1[i-1];
    		i--;
    		j--;
    	}
    	
    	else if(dp[i-1][j] > dp[i][j-1])
    	{
    		SCS[l_SCS-1] = s1[i-1];
    		i--;
    	}

    	else
    	{
    		SCS[l_SCS-1] = s2[j-1];
    		j--;
    	}

    	l_SCS--;
    }

    while(i>0)
    {
    	SCS[l_SCS-1]=s1[i-1];
    	i--;
    	l_SCS--;
    }

    while(j>0)
    {
    	SCS[l_SCS-1]=s2[j-1];
    	j--;
    	l_SCS--;
    }
    cout<<SCS;
}

int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
int m=s1.length();
int n=s2.length();
	printSCS(s1,s2,m,n);
return 0;
}

/*

Input

acbcf
abcdaf

output

acbcdaf

*/