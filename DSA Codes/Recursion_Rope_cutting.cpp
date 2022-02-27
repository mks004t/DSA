#include<bits/stdc++.h>
using namespace std;
//you have to cut the rope into max pices of length a,b,c
//its better solution is in dynamic programming 
//Time compO(3^n)
int cutRope(int n,int a,int b,int c)
{
	if(n==0)
		return 0;
	if(n<0)
		return -1;
	
	int result=max(cutRope(n-a,a,b,c), cutRope(n-b,a,b,c), cutRope(n-c,a,b,c));
	
	if (result == -1)
		return -1;
	
	return (result+1);
}

int main()
{  int n,a,b,c; 
	cin>>n>>a>>b>>c;

	cout<<cutRope(n,a,b,c);
	return 0;
}
