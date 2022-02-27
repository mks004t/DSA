#include<bits/stdc++.h>
using namespace std;

// O(n)
//O(log n) by matrix multiplication
//All function are currect
/*

vector<int > memoG(n+1,-1);
int fib(int n)
{
	if(momoG[n]==-1)
	{
		int result;
		if(n==0||n==1)
			result=n;
		else
			result=fib(n-1)+fib(n-2);

		memoG[n]=result;
	}
	return memoG[n];
}

*/

//Memoization
int fib( int n, vector<int> memo)
{
	if(memo[n]==-1)
	{
		int result;
		if(n==0 || n==1)
			result=n;
		else
			result=fib(n-1,memo)+fib(n-2,memo);

		memo[n]=result;
	}
	return memo[n];
}

//Tabulation
 int fib1(int n)
 {
 	int f[n+1];
 	f[0]=0,f[1]=1;

 	for(int i=2;i<=n;i++)
 		f[i]=f[i-1]+f[i-2];
 	return f[n];

 }



int main()
{   int n;
	cin>>n;
    vector<int> memo(n+1,-1);

	cout<<fib(n,memo)<<endl;
   cout<<fib1(n);
	return 0;
}