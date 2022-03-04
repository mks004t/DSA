#include<bits/stdc++.h>
using namespace std;

//combination of balanced parentheses= Catalan (n)


int binomialCoff(int n,int r)
{	
	int ans=1;
	if(r>n-r)
		r=n-r;
	for(int i=0; i<r; i++)
	{
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}
int catalan(int n)
{
	long long int res=binomialCoff(2*n,n);

	return res/(n+1);
}
int main()
{
	int n=5;
	cout<<catalan(n);
	return 0;
}