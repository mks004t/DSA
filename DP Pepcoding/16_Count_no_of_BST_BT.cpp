#include<bits/stdc++.h>
using namespace std;

//Application of LIS O(N*N)

//NO of BST =  Catalan_Numbers
//NO of BT = Catalan Number * n!;  

int catalan(int n)
{
	int LIS[n+1];
	LIS[0]=1;      // Given
	LIS[1]=1;      // Given 

	for(int i=2; i<=n; i++)
	{
		LIS[i]=0;
		for(int j=0; j<i; j++)
		{
			LIS[i]+= LIS[j] * LIS[i-j-1];	
		}
	}

	return LIS[n];
}

int factorial(int n)
{
	long long int ans=1;
	for(int i=1;i<=n;i++)
	{
		ans+=i;
	}
	return ans;
}
int main()
{  int n=5;
	cout<<"No of BST :"<<catalan(n)<<endl;
	cout<<"No of BT  :"<<catalan(n)*factorial(n);

	return 0;
}