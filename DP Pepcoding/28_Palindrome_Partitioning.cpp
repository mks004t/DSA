#include<bits/stdc++.h>
using namespace std;

// O(N^3)
int minPalPartion( string str)
{
	int n=str.length();
	bool dp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++, j++)
		{
			if(gap==0)
				dp[i][j]=true;
			
			else if(gap==1)
				{
					dp[i][j]=str[i]==str[j];
				}
			else
			{
				if(str[i]==str[j] && dp[i+1][j-1]==true)
					dp[i][j]=true;
				else
					dp[i][j]=false;
			}
		}

	}


	int dpp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{
			if(gap==0)
				dpp[i][j]=0;
			
			else if(gap==1)
				{
					if(str[i]==str[j])
						dpp[i][j]=0;
					else
						dpp[i][j]=1;
				}

			else
			{
				if(dp[i][j]==true)
					dpp[i][j]=0;

				else
				{	
					int mini=INT_MAX;
					for(int k=i; k<j; k++)
				    {
					    int left=dpp[i][k];
					    int right=dpp[k+1][j];

					    mini=min(mini,left+right+1);
				    }

				    dpp[i][j]=mini;
				}
			}
		}
	}
	return dpp[0][n-1];
}

//O(N^2)

// suffix 

int MinPalPartion( string str)
{
	int n=str.length();
	bool dp[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++, j++)
		{
			if(gap==0)
				dp[i][j]=true;
			
			else if(gap==1)
				{
					dp[i][j]=str[i]==str[j];
				}
			else
			{
				if(str[i]==str[j] && dp[i+1][j-1]==true)
					dp[i][j]=true;
				else
					dp[i][j]=false;
			}
		}

	}

	int dpp[n];
	dpp[0]=0;

	for(int j=1; j<n; j++)
	{
		if(dp[0][j]==true)
			dpp[j]=0;

		else
		{
			dpp[j]=INT_MAX;
			for(int i=j; i>=1; i--)
			{
				if(dp[i][j]==true)
					dpp[j]=min(dpp[j], dpp[i-1])+1;
			}
		}
	}
	return dpp[n-1];
}



int main()
{
    string str = "ababbbabbababa";
    
    cout<< minPalPartion(str)<<endl;
    cout<< MinPalPartion(str);
    return 0;
}

// OutPut : 3