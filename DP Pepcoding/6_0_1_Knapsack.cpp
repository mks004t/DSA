#include<bits/stdc++.h>
using namespace std;
struct Pair
{
	int i;
	int j;
	string path;
};

int knapSackDP(int wt[],int val[],int W,int n)
{	
	int dp[n+1][W+1];
	for (int i=0;i<=n;i++)
		dp[i][0]=0;
	for(int j=0;j<=W;j++)
		dp[0][j]=0;

for(int i=1;i<=n;i++)
	{  for(int j=1;j<=W;j++)
		{
			if(wt[i-1]>j)
			  dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
		}
	}


//---------------Print Path-------------------------------
 
 Pair p={n,W,""};
 queue<Pair> Queue;
 Queue.push(p);
 while(Queue.size()>0)
 {  Pair temp=Queue.front();
 	Queue.pop();

 	if(temp.i==0||temp.j==0)
 	{
 		cout<<temp.path<<endl;
 		continue;
 	}
 	
 	int exc= dp[temp.i-1][temp.j];
 	int inc= val[temp.i-1]+dp[temp.i-1][temp.j-wt[temp.i-1]];
 	
 	if(dp[temp.i][temp.j]==exc)      //exclude
 	{
 		Pair p1={temp.i-1,temp.j,temp.path};
 		Queue.push(p1);
 	}

 	if(dp[temp.i][temp.j]==inc)      //include
 	{   
 		Pair p2={temp.i-1,temp.j-wt[temp.i-1],to_string(temp.i-1)+" "+temp.path};
 		Queue.push(p2);
 	}

 }

return dp[n][W]; 
}
int main()
{
	int val[]={10,40,30,50};
	int wt[]={5,4,6,3};
	int n= sizeof(val)/sizeof(val[0]);
	int W=10 ; 

	cout<<knapSackDP(wt,val,W,n);
	return 0;
}