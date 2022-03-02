#include<bits/stdc++.h>
using namespace std;

struct Pair
{
	int i;
	int j;
	string path;
};

// Print function is incomplete 
/*
void printPath(vector<vector<int>> gold,int n,int m,vector<vector<int>> & dp,int ans)
{   queue<Pair> Queue;
	for(int i=0;i<n;i++)
	{
		if(dp[i][m-1]==ans)
		{
			Pair p={i,m-1,to_string(i)+"D"+to_string(j)};
			Queue.push(p);
		}

		while(Queue.size()>0)
		{
			Pair temp= Queue.front();
			Queue.pop();

			if(temp.j==0) //Reached to starting point
			{
				cout<<temp.path;
				continue;
			}
			else if(temp.i==0)   //front,down
			{
				if(dp[temp.i][temp.j-1] >dp[temp.i+1][temp.j-1]) //front>down
			     {       string p1=to_string(temp.i)+"D"+to_string(temp.j-1);
			     	pair p1={temp.i,temp.j-1,p1+temp.path};
			     }
			     else if( dp[temp.i][temp.j-1] < dp[temp.i+1][temp.j-1])  //front<down
			     {
			     	 string p2=to_string(temp.i+1)+"D"+to_string(temp.j-1);
			     	pair p2={temp.i+1,temp.j-1,p2+temp.path};
			     }
			     else														//front=down
			     { 
			     	string p1=to_string(temp.i)+"D"+to_string(temp.j-1);
			     	pair p1={temp.i,temp.j-1,p1+temp.path};

			     	 string p2=to_string(temp.i+1)+"D"+to_string(temp.j-1);
			     	pair p2={temp.i+1,temp.j-1,p2+temp.path};

			     }
			}
			else if(temp.i==n)   //front,up
			{
				if(dp[temp.i][temp.j-1] >dp[temp.i-1][temp.j-1]) //front>up
			     {       string p1=to_string(temp.i)+"D"+to_string(temp.j-1);
			     	pair p1={temp.i,temp.j-1,p1+temp.path};
			     }
			     else
			     {
			     	 string p2=to_string(temp.i-1)+"D"+to_string(temp.j-1);
			     	pair p2={temp.i-1,temp.j-1,p2+temp.path};
			     }
			}
			else           //front,up,down
			{
				if(dp[temp.i][temp.j-1] >dp[temp.i+1][temp.j-1] && dp[temp.i][temp.j-1] >dp[temp.i-1][temp.j-1]) //f>u,d
				{
					string p1=to_string(temp.i)+"D"+to_string(temp.j-1);
			     	pair p1={temp.i,temp.j-1,p1+temp.path};
				}
				else if()
			}
		}
	}
   

}
*/
int getMaxGold(vector<vector<int>> gold,int n,int m)
{
	vector<vector<int>> dp(n,vector<int> (m));
	for(int i=0;i<n;i++)
		dp[i][0]=gold[i][0];

	for(int j=1;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(i==0) 
			{
				dp[i][j]=max(dp[i][j-1],dp[i+1][j-1]) + gold[i][j];   // (middle, top)
			}
			
			else if(i==n-1)
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]) + gold[i][j];    //( middle, bottom)
			}
			
			else
			{
				dp[i][j]=max(max(dp[i-1][j-1], dp[i][j-1]),dp[i+1][j-1]) + gold[i][j] ;  //top , middle, bottom
			}
		}
	}

  int ans=0;
	for(int i=0; i<n; i++)
       ans=max(ans,dp[i][n-1]);
    
  // printPath(gold,n,m,dp,ans);
  return ans;
}

int main()
{
    vector<vector<int>> gold { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
   
    cout<<getMaxGold(gold, n, m);
    return 0;
}