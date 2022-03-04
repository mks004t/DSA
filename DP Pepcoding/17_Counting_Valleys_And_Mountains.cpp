#include<bits/stdc++.h>
using namespace std;

//Application of LIS   O(N*N)
// No of Valleysans mountains = Catalan No
int count(int n)
{
	int LIS[n+1];
	LIS[0]=1;
	LIS[1]=1;

	for( int i=2;i<=n;i++)
	{
		LIS[i]=0;
		for(int j=0;j<i;j++)
		{
			LIS[i]+= LIS[j]* LIS[i-j-1];
					//Outside *Inside
		}
	}
	return LIS[n];
}
int main()
{
	int n=6;
	cout<<count(n);
	return 0;
}