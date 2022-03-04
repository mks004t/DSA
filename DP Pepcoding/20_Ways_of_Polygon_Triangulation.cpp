#include<bits/stdc++.h>
using namespace std;

//Ways of Polygon Triangulation= catalan(n-2);
 
long long int binomialCoff(int n,int r)
{
	long long int ans=1;
	if(r>n-r)
		r=n-r;

	for(int i=0;i<r;i++)
	{
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}

long long int catalan(int n)
{
	long long int res=binomialCoff(2*n,n);

	return res/(n+1); 
}

int main()
{
	int n=7;
	cout<<catalan(n-2);
	return 0;
}