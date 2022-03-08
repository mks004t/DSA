#include <bits/stdc++.h>
using namespace std;

int appearOnce(int arr[],int n)
{ 
	int ans=0;
	
	for(int i=0; i<n; i++)
	{	
		ans=ans^arr[i];	
	}
	
	return ans;
}

int main()
{
	int arr[]={12, 1, 12, 3, 1, 2, 3} ;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<appearOnce(arr,n);
	return 0;
}