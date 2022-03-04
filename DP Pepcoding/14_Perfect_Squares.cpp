#include<bits/stdc++.h>
using namespace std;

//Application of LIS 

int Perfect_sq(int n)
{
	int LIS[n+1];
	LIS[0]=0;      // 
	LIS[1]=1;      //1^1=1 need only one elment

	for(int i=2; i<=n; i++)
	{
		LIS[i]=INT_MAX;
		for(int j=1; j*j<=i; j++)
		{
			int rem=i-j*j;
			LIS[i]=min(LIS[i],LIS[rem]+1);
		}
	}

	return LIS[n];
}

int main()
{  int n=12;
	cout<<Perfect_sq(n);

	return 0;
}