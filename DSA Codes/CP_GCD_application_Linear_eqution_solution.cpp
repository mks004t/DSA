#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{  // base case of gcd
	if(b==0)
	{    x=1;
		 y=0;

		return a;
	}
	else
	{	int x1,y2;
		int d=gcd(b, a%b, x1,x2);
		// this eq is derived by gcd algo
		x=y1;
		y=x1-y1*(a/b);

		return d;

	}
}


int main()
{  int a, b,result;
	cin>>a>>b>>c;
	if(a>b)
		result =gcd(a,b);
	else
		result=gcd(b,a);

	cout<<result;
	return 0;
}