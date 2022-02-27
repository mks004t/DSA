#include<bits/stdc++.h>
using namespace std;
/*   longest common subsequence (LCS)
Step 1: Base case when one of the string is empty, return 0;
step 2: if last Latter is same return 1+fun(),by removing that character.
Step 3: else call for max of both fun() with removing 1 char from each other

*/

//Recursive Solution not DP  O(2^n)
int LCS(string s1,string s2 ,int m,int n)
{
	if(m==0 || n==0)
		return 0;
	if(s1[m-1] == s2[n-1])
		return 1 + LCS(s1,s2,m-1,n-1);
	else
		return max(LCS(s1,s2,m-1,n), LCS(s1,s2,m,n-1));

	
}
// DP Recursive Solution
int  memo[1000][1000];

int lcs(string s1,string s2, int m,int n)
{
	if(memo[m][n]!=-1)
		return memo[m][n];
	if(m==0 ||n==0)
		 memo[m][n]=0;
	else
	{
		if(s1[m-1] == s2[n-1])
			memo[m][n]=1+lcs(s1,s2,m-1,n-1);
		else
			memo[m][n]=max( lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
	}

	return memo[m][n];

}



int main()
{   string s1,s2;
	cin>>s1;
	cin>>s2;
	int m=s1.size();
	int n=s2.size();
	//cout<<LCS(s1,s2,m,n); // recursive solution

     
    for(int i=0;i<=m;i++)
    	for(int j=0;j<=n;j++)
    		memo[i][j]=-1;

   cout<<lcs(s1,s2,m,n); // DP rec
    
	return 0;
}