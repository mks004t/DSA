#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<bool>>& matrix) {
        
	int n=matrix.size();
	int m=matrix[0].size();
	int ans=0;

	int dp[n][m];

	for(int i=0;i<n;i++) 
	{  (matrix[i][0] == true) ? dp[i][0]=1 : dp[i][0]=0;
	   ans=max(dp[i][0],ans);
	}

	for(int j=0; j<m; j++)    
	{    (matrix[0][j] == true) ? dp[0][j]=1 : dp[0][j]=0;
	     ans=max(dp[0][j],ans);
	}

	for(int i=1;i<n;i++)
	    for(int j=1;j<m;j++)
	    {
	        if(matrix[i][j]==false)
	            dp[i][j]=0;
	        else
	            dp[i][j]= 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
	        
	        
	            ans=max(dp[i][j],ans);
	    }

	return ans*ans;
}

int main ()
{
    vector<vector<bool>> Matrix{{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
                      
    cout<<maximalSquare(Matrix);
 
    return 0;
}