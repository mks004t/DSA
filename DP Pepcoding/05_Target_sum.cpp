#include<bits/stdc++.h>
using namespace std;

struct Pair{
	int i;
	int j ;  //j=sum
	string path;
};

bool subsetsum( int arr[], int n, int sum)
{
	bool dp[n+1][sum+1];

	for(int i=0; i<=n; i++)    {  dp[i][0]=true; }
	for(int j=1; j<=sum; j++)  {  dp[0][j]=false; }

	for(int i=1; i<=n; i++)
	for(int j=1; j<=sum; j++)
	{
		if(j < arr[i-1])
			dp[i][j] = dp[i-1][j];
		else
			dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	}

//--------------Print Path------------------------------
   queue<Pair> Queue;
   Pair p1={n,sum,""};
   Queue.push(p1);

   while(Queue.size()>0)
   {
   	  Pair temp=Queue.front();
   	  Queue.pop();
   	 
   	  if(temp.i==0 ||temp.j==0)
   	  {
   	  	cout<<temp.path<<endl;
   	  	continue;
   	  }
   	  else
   	  { 
   	  	  bool exc=dp[temp.i-1][temp.j]; 
   	  	 
   	  	  if(exc)
   	  	  {  
   	  	     Pair p1={temp.i-1,temp.j,temp.path};
   	  		 Queue.push(p1);
   	  	  }
   	  	 
   	  	 if(temp.j>=arr[temp.i-1])
   	  	 {
   	  		bool inc=dp[temp.i-1][temp.j-arr[temp.i-1]];
   	  	 	
   	  	 	if(inc)
   	  	    {
   	  		  Pair p1={temp.i-1,temp.j-arr[temp.i-1],to_string(temp.i-1)+" "+temp.path};
   	  		  Queue.push(p1);
   	  	    }
   	  	 } 

      }
   }
	
	return dp[n][sum];
}
