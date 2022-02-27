#include<bits/stdc++.h>
using namespace std;

/*  Time Comp: O(N^1/2) & Space comp:O(1)

Approach: The idea is to represent N as a sequence of length L+1 as: 
N = a + (a+1) + (a+2) + .. + (a+L) 
=> N = (L+1)*a + (L*(L+1))/2 
=> a = (N- L*(L+1)/2)/(L+1) 
We substitute the values of L starting from 1 till L*(L+1)/2 < N 
If we get ‘a’ as a natural number then the solution should be counted.

"a" is the first element of series and "L" is the last element. */
int countWays(int n)
{
	int count=0;
	for(int L=1; (L*(L+1))/2 < n; L++)
	{
		double a =(1.0*n - ( L*(L+1))/2 ) / (L+1) ;
		if( a - (int)a == 0.0)
			count++;
	}
	return count;
}

void printNo(int n)
{
	int count=0;
	for(int L=1; (L*(L+1))/2 < n; L++)
	{
		double a =(1.0*n - ( L*(L+1))/2 ) / (L+1) ;
		if( a - (int)a == 0.0)
			{
				for(int i=0; i<=L; i++)
					cout<<a+i<<" ";
				cout<<endl;
			}

	}
	
}
int main()
{
	int n=15;
	//cout<<countWays(n);
	printNo(n);
	return 0;
}

/*
Output of countWays
3

Output of Print No
7 8
4 5 6
1 2 3 4 5

*/