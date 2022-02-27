#include<bits/stdc++.h>
using namespace std;

// Kernighan's Algorithm | Count Set Bits in an Integer | 

int main()
{
	int n;
		cin>>n;
	int count=0;
	while(n)
	{
		int rsbm= n & -n;  // right most set bit mask
		n-=rsbm;            // subtract the right most setbit from the number
		count++;
	}
		cout<<count;
	return 0;
}