#include<bits/stdc++.h>
using namespace std;

// dp[][][]
//Number of ways of scoring R runs in B balls with at most W wickets
#define mod 1000000007
#define RUNMAX 300
#define BALLMAX 50
#define WICKETMAX 10

int CountWays(int r, int b, int l, int R,int B,int W,int dp[RUNMAX][BALLMAX][WICKETMAX])
{
	if(l>W)         //if wicket lost are more
		return 0;
	
	if(r>R)         //if run score are more
		return 0;
	
	if(b==B && r==R)  //if condition meet
		return 1;
	
	if(b==B)            // if no nun got scored
		return 0;
	
	if(dp[r][b][l]!=-1)      // if Already visited%
		return dp[r][b][l];
	
	int ans=0;

	ans+=CountWays(r,b+1,l,R,B,W,dp);  // 0 run score but ball +1
	 //ans=ans%mod;                    //this is just to minimize the constrains //no need for small value
   
   ans+=CountWays(r+1,b+1,l,R,B,W,dp);   //1 run score & 1 ball
   // ans=ans%mod;

    ans+=CountWays(r+2,b+1,l,R,B,W,dp);  // 2run & 1ball
  //  ans=ans%mod;

    ans+=CountWays(r+3,b+1,l,R,B,W,dp);  // 3 run
  //  ans=ans%mod;

     ans+=CountWays(r+4,b+1,l,R,B,W,dp); //4 ball
  //  ans=ans%mod;
    
     ans+=CountWays(r+6,b+1,l,R,B,W,dp); //5 ball
  //  ans=ans%mod;

    ans+=CountWays(r,b+1,l+1,R,B,W,dp);  //6 ball
   // ans=ans%mod;

  // Memoize and return  
return dp[r][b][l]=ans;

}
int main()
{
	int R =40, B=10, W=4;

	int dp[RUNMAX][BALLMAX][WICKETMAX];  //dp[][][]
	
	memset(dp,-1, sizeof dp);  //dp of -1 elements
	
	cout<<CountWays(0,0,0,R,B,W,dp);
   
return 0;
}