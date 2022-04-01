#include<bits/stdc++.h>
using namespace std;

void rec(int i,int n)
{
	if(i>n)
		return;
	cout<<i<<endl;
	for(int j=0; j<10; j++)
		rec(10*i+j,n);
}

int main()
{
	int n=100;

	for(int i=1; i<10; i++ )
		rec(i,n);

	return 0;
}