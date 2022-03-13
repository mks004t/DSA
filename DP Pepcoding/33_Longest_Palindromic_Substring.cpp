#include<bits/stdc++.h>
using namespace std;

/* same as count Plaindromic substring(32)
  but in this question result is length of the true value in the highest value of gap;
     
     if(dp[i][j]=true)
       res = gap+1;
*/

int longestPS(char s[],int n)
{
    bool dp[n][n];
    int res=0;
    for(int gap=0; gap<n; gap++)
    {
        for(int i=0,j=gap; j<n; i++,j++)
        {
            if(gap==0)
                dp[i][j]=true;

            else if(gap==1)
            {
                if(s[i]==s[j])
                    dp[i][j]=true;
                else
                    dp[i][j]=false;
            }

            else
            {
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                    dp[i][j]=true;
                else
                    dp[i][j]=false;
            }

            if(dp[i][j]==true)
                res=gap+1;
        }
    }

    return res;
}


int main()
{
    char str[] = "abaab";
    int n = strlen(str);
    cout << longestPS(str, n) << endl;
    return 0;
}