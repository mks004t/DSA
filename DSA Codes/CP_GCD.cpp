#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		gcd(b, a%b);
}


int main()
{  int a, b,result;
	cin>>a>>b;
/*	if(a>b)
		result =gcd(a,b);
	else
		result=gcd(b,a);
*/
	// No need of ef else statement bec GCD fun autometicaly replace the value in its first iteration 
	result= gcd(a,b)
	cout<<result;
	return 0;
}