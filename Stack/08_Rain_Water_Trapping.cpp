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
		//cout<<maxL[i-1]<<" ";
	}
    //cout<<endl;
	
	maxR[n-1]=arr[n-1];
	
	for(int i=n-2; i>=0; i--)
	{
		maxR[i]=max(maxR[i+1], arr[i]);
		//cout<<maxR[i+1]<<" ";
	}
	//cout<<endl;
	int water[n];
	int sum=0;
	for(int i=1; i<n-1; i++)  // since we can not hold any water in the corners
	{
		water[i]=min(maxL[i],maxR[i])-arr[i];
		sum+=water[i];
	}

	return sum;
}


int main()
{
    int arr[] = {5,0,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0;
}