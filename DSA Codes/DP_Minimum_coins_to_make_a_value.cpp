#include<bits/stdc++.h>
using namespace std;

//Minimum coins to make a value.
//we have to make the value with min coins.
//the supply of coins is infinite

//DP Solution    O(N*Value) 
int minCoins(int coins[],int n,int value)
{
	int dp[value+1]; 
	dp[0]=0;

	for(int i=1; i<=value; i++)  //sum up to value
	   dp[i]=INT_MAX;

	for(int i=1; i<=value; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(coins[j] <= i) // coins must me less then sum
			{
				int sub_res = dp[i-coins[j]];  //mean dp[value - coin]
				if(sub_res!=INT_MAX)
					dp[i]= min( dp[i], sub_res+1);
			}
		}     
	}

  return dp[value];
}

//Recursive Solution     O()
int minCoinsREC(int coins[],int n,int value)
{
	if(value==0) return 0;

	int result = INT_MAX;

	for(int i=0; i<n; i++)
	{
		if(coins[i]<=value)
		{
			int sub_res =minCoinsREC(coins,n,value-coins[i]);
			
			if(sub_res!= INT_MAX )   //if it give a currect solution
			result=min(result,sub_res+1);	
		}
	}
	return result;
}



int main ()
{   int n;
	cin>>n;
	
	int coins[n] ;
	for(int i=0; i<n; i++)
		cin>>coins[i];

	int value; cin>>value;

	//cout<<minCoinsREC(coins,n,value);
	cout<<minCoins(coins,n,value);
	
	return 0;
}


/*  input
3
25 10 5
30

//output
2

*/