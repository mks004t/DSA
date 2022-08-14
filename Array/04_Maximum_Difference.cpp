#include<bits/stdc++.h>
using namespace std;

// MAximum value difference i.e ans= maximum arr[i]-arr[j]  where j>i .

// O(N)

int maxdiff(int arr[],int n)
{
	int res = arr[1]-arr[0];
	int minVal = arr[0];

	for(int i=0; i<n; i++)
	{
		res = max(res, arr[i]- minVal);
		
		minVal=min(minVal, arr[i]);
	}
	return res;
}

int main()
{
	int arr[]= {2,3,10,6,4,8,1};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<maxdiff(arr,n);

	return 0;
}