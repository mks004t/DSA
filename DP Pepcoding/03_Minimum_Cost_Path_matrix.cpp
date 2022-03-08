#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

struct Pair
{
  int x;
  int y;
  string path;
} ;

void printPath(int cost[R][C],int dp[R][C],int n,int m)
{
   queue<Pair> Queue;
   
   Pair p={0,0,""};
   
   Queue.push(p);

   while(Queue.size()>0)
   {
   		Pair temp= Queue.front();
   		Queue.pop();

   		if(temp.x==n-1 && temp.y==m-1)
   		{
   			cout<<temp.path<<endl;
   			continue;
   		}	
   		
   		else if(temp.x==n-1)     //last Row so can only move to Left/H
   		{    
   			Pair p1={temp.x,temp.y+1,temp.path+"H"+" "};
   			Queue.push(p1);
   		}
   		
   		else if(temp.y==m-1)    //last column so can only move to Down/V
   		{   Pair p2={temp.x+1,temp.y,temp.path+"V"+" "};
   			Queue.push(p2);
   		}
   		
   		else
   		{
   			if(dp[temp.x][temp.y+1] < dp[temp.x+1][temp.y])            //move to right/H
   			{
   				Pair p1={temp.x,temp.y+1,temp.path+"H"+" "};
   			    Queue.push(p1);
   			}
   			else if(dp[temp.x][temp.y+1] > dp[temp.x+1][temp.y])       //move to down/V
   			{
   				Pair p2={temp.x+1,temp.y,temp.path+"V"+" "};
   			    Queue.push(p2);
   			}
   			else                                   //can move both both right and down
   			{
   				Pair p1={temp.x,temp.y+1,temp.path+"H"+" "};
   			    Queue.push(p1);
   				
   				Pair p2={temp.x+1,temp.y,temp.path+"V"+" "};
   			    Queue.push(p2);
   			}
   		}
   	}
}
int minCost(int cost[R][C],int n,int m)
{
	int dp[R][C];
    
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
				dp[i][j]=cost[i][j];
			
			else if(i==0)
			{
				dp[i][j]=dp[i][j-1]+cost[i][j];
			}

			else if (j==0)
			{
				dp[i][j]=dp[i-1][j]+cost[i][j];
			}

			else
			{
				dp[i][j]= min(dp[i-1][j],dp[i][j-1]) +cost[i][j];
			}
		}
	}
    
    printPath(cost,dp,n,m);
	cout<<endl;
	return dp[n-1][m-1];
}

int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << minCost(cost, 3, 3);
   return 0;
}