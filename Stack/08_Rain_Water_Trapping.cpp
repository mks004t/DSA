#include<bits/stdc++.h>
using namespace std;

// In this question we calculate the absolute right and left max
// O(N*N)
int maxWater(int arr[],int n)
{
	int maxR[n];
	int maxL[n];
	
	maxL[0]=arr[0];
	
	for(int i=1; i<n; i++)
	{
		maxL[i]=max(maxL[i-1],arr[i]);
	}

	maxR[n-1]=arr[n-1];
	
	for(int i=n-2; i>=0; i--)
	{
		maxR[i]=max(maxR[i+1], arr[i]);
	}

	int water[n];
	int sum=0;
	for(int i=0; i<n; i++)
	{
		water[i]=min(maxL[i],maxR[i])-arr[i];
		sum+=water[i];
	}

	return sum;
}


int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0;
}