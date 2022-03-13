#include<bits/stdc++.h>
using namespace std;

int CountPS(char s[], int n)
{
	bool dp[n][n];
    int count=0;

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
					dp[i][j] = true;
				
				else
					dp[i][j] = false;
			}

			if(dp[i][j]==true)
				count++;
		}
	}

return count;
}

int main()
{
    char str[] = "abaab";
    int n = strlen(str);
    cout << CountPS(str, n) << endl;
    return 0;
}

/*  OUTPUT  : 8
 All Palindromic substring including single char also
e.g 
    "a", "b", "a", "a", "b", "aba" , "aa" , "baab"
 
 if you have to count Palindromic Substring size greater then zero,
   condition :
              if(dp[i][j]==true && gap>0)
                  count++;
             
          e.g        
               "aba" , "aa" , "baab"
*/
