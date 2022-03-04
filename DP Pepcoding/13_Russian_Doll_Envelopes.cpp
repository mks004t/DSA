#include<bits/stdc++.h>
using namespace std;

//Application of LIS 

//Leet Code  O(N*N) TLE
// Binary search solution
// Input is in form of Leet code
int maxEnvelopes(vector<vector<int>>& en) {
      
    int n=en.size();
    sort(en.begin(),en.end());
    
    int LIS[n];
    LIS[0]=1;
    
    for(int i=1;i<n;i++)
    {
        LIS[i]=1;
        for(int j=0;j<i;j++)
        {
            if(en[i][0]>en[j][0] && en[i][1]>en[j][1] )
                LIS[i]=max(LIS[i],LIS[j]+1);
        }
    }
    
    int ans=-100000;
    for(int i=0;i<n;i++)
        ans=max(ans,LIS[i]);
    
    return ans;
    
}