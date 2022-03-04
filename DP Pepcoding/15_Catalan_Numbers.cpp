#include<bits/stdc++.h>
using namespace std;

//Application of LIS 

int catalan(int n)  //O(N*N)
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
//___________________O(N) Solution____________
 
 int binomialCoff(int n,int r)
 {
 	long long int res=1;
 	if(r > n-r)
 		r=n-r;
 	for(int i=0;i<r;i++)
 	{
 		res*=(n-i);
 		res/=(i+1);
 	}

 	return res;
 }

int catalanN(int n)
{
	long long int res= binomialCoff(2*n,n);  //nCr 

	return res/(n+1); 
}
//___________________________________________________

int main()
{  int n=6;
	cout<<catalan(n)<<endl;
	cout<<catalanN(n);
	return 0;
}