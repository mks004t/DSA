#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k)
{
	if(n==1)
		return 0;
	int x = solve(n-1,k);
	int y = (x+k)%n;     // get the current position of person

	return y;
}


int main()
{
	int n=10;
	int k=3;
	cout<<solve(n,k);
	return 0;
}