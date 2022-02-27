#include<bits/stdc++.h>
using namespace std;
//Longest common Sub String .(Sub String must be continuous)

// Recursive solution 
/*
void LCSS(string s1,string s2,int m,int n,int &result,int sub_res)
{
	if(m==0||n==0)
		return ;
	
	if(s1[m-1]==s2[n-1])
		{sub_res++;
		 result=max(result,sub_res);
		 LCSS(s1,s2,m-1,n-1,result,sub_res);
		 }
	else
		{  sub_res=0;
			 LCSS(s1,s2,m-1,n,result,sub_res);
			 LCSS(s1,s2,m,n-1,result,sub_res);
		}

}*/

int LCSS(string s1,string s2, int m,int n)
{	
	int dp[m+1][n+1];
	
	for(int i=0;i<=n;i++)  {  dp[i][0]=0;  }
	for(int j=0;j<=n;j++)  {  dp[0][j]=0;  }

	for(int i=1;i<=m;i++)
	 for(int j=1;j<=n;j++)
	{
		if(s1[i-1]==s2[j-1])
			dp[i][j] = 1+dp[i-1][j-1];
		else
		    dp[i][j]=0;
	}


int max_res=0;
	for(int i=0;i<=m;i++)
	 for(int j=0;j<=n;j++)
      max_res=max(max_res,dp[i][j]);

return max_res;
	
}
int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;

	int m=s1.length();
	int n=s2.length();

  //   int result=0;
	cout<<LCSS(s1,s2,m,n);
//     cout<<result;
	
	return 0;
}