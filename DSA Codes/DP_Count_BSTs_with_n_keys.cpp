#include<bits/stdc++.h>
using namespace std;

//Given N, Find the total number of unique BSTs that can be made using values from 1 to N. 
// res(n) = res(0)*res(n-1) + res(1)*(resn-2) +...+ res(n-1)*res(0)
// Base case : res(0)=1 ;

int countBSTs(int n){
int dp[n+1];
dp[0]=1;
for(int i=1; i<=n;i++)
 {
	dp[i]=0;
	for(int j=0; j<i; j++)
		dp[i]+= dp[j] * dp[i-j-1];
 }

return dp[n];
}
int main()
{ int n=4;
	cout<<countBSTs(n);

	return 0;
}