#include<bits/stdc++.h>
using namespace std;

//Egg dropping problem  f = no of floors, e = no of eggs.
//  res(f,e)=min(max(res(x-1,e-1), res(f-x,e) ))+1

/*
Base case
res(f,1)=f
res(1,e)=1
res(0,e)=0

*/
//DP Solution 
//Time comp : O(f*f*e) & Aux Space : O(f*e)
int eggDrop(int f,int e)
{
	int dp[f+1][e+1];  //note first coloum is empty(e=0).

	for(int i=0; i<=f; i++)  { dp[i][1]=i; } //column
	for(int j=1; j<=e; j++)  { dp[0][j]=0; } //row

	for(int i=2; i<=f; i++)
	 for(int j=2; j<=e; j++)
	{
		dp[i][j]=INT_MAX;
		for(int x=1; x<=i; x++)
			dp[i][j] = min(dp[i][j], 1+max( dp[x-1][j-1], dp[i-x][j]) );
	} 

return dp[f][e];
}

int main()
{ int f=5;
  int e=3;
  cout<<eggDrop(f,e);
return 0;
}