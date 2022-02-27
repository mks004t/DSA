#include<bits/stdc++.h>
using namespace std;

// Time and space comp is theta(d) where d is no of digits

int sumDigit(int n)
{
	if(n==0)
		return 0;
else
	return sumDigit(n/10)+n%10;
}

int main()
{  int n;
	cin>>n;
	cout<<sumDigit(n);
	return 0;
}