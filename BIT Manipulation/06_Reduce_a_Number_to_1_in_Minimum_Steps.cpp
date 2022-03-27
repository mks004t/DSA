#include <bits/stdc++.h>
using namespace std;

//Reduce a Number to 1 in Minimum Steps | Reduce N to 1

// find the min no of steps to make the number 1;
/*
   if N == even N->N/2
   if N == odd
         1) 4x+1 =   -
         2) 4x+3 =   +

         exception for 3 we do (-) substraction
*/

int reduceto1(int n)
{
	int result=0;

	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
		}

		else
		{
			if(n==3)
			{
				n=n-1;
			}
			else if(n%4 == 1)
			{
				n=n-1;
			}

			else if(n%4 == 3)
			{
				n=n+1;
			}
		}

		result++;
	}

	return result;
}

int main()
{
	int n=5;
	cout<<reduceto1(n);
	return 0;
}