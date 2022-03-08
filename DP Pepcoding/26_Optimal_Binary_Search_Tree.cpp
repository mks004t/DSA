#include<bits/stdc++.h>
using namespace std;

int optimalSearchTree(int keys[],int freq[],int n)
{
	int dp[n][n];

//-------------------------------------------
    int presum[n];
    presum[0]=freq[0];
    for(int i=1; i<n; i++)
    {
    	presum[i]=presum[i-1]+freq[i];
    }
//--------------------------------------------

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{
			if(gap==0)
			{
				dp[i][j]=freq[i];
			}
			
			else if (gap==1)
			{
				int f1=freq[i];
				int f2=freq[j];
				dp[i][j]=min(f1+2*f2, f2+2*f1);
			}
			else
			{
				int res=INT_MAX;
				       //if i==0 then fs= presum-0,else fs = presum[j]-presum[i]
				int fs= presum[j] - (i==0? 0 : presum[i]) ;  
				
				for(int k=i; k<=j; k++)
				{
					int left = (k==i)? 0 : dp[i][k-1];
					int right= (k==j)? 0 : dp[k+1][j];

					res=min(res,left+right+fs);	
				}
				dp[i][j]=res;
			}
		}
	}

	return dp[0][n-1];
}


int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "
         << optimalSearchTree(keys, freq, n);
    return 0;
}
//output 142