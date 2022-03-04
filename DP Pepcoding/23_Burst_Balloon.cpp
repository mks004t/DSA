#include<bits/stdc++.h>
using namespace std;

//Application of matrix chain multiplication ( Gap )

int maxCoins(vector<int>& nums) {
  int n=nums.size();
  int dp[n][n];

  for(int gap=0; gap<n; gap++)
  {   
     for(int i=0,j=gap; j<n; i++,j++)
     {   
        dp[i][j]=INT_MIN;
        for(int k=i; k<=j; k++)
        {
            int left= k==i ? 0:dp[i][k-1];
            int right= k==j? 0:dp[k+1][j];
            int val= (i==0? 1: nums[i-1])*nums[k]*(j==n-1 ? 1: nums[j+1]);
                
            int total=left+right+val;
          dp[i][j]=max(dp[i][j],total);  
        }
    }
  }

return dp[0][n-1];
}