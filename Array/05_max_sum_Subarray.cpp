#include<bits/stdc++.h>
using namespace std;

// Max Sum sUB ARRAY ()

// O(N)
int maxSumEff(vector<int> arr)
{
	int n=arr.size();
	int res=0;
	int curr=0;
	for(int i=0; i<n; i++)
	{
		curr+=arr[i];
		if(curr<=0)
		{
			curr=0;
		}
		if(curr>0)
		res=max(res,curr);
	}
	return res;
}


// O(N*N)

int maxSum(vector<int> arr)
{
	int n=arr.size();
	int  res= arr[0];

	for(int i=0; i<n; i++)
	{
		int curr=0;
		for(int j=i;j<n;j++)
		{
			curr+=arr[j];
			res=max(res,curr);
		}
	}
	return res;
}



int main()
{
	vector<int> arr={2,3,-8,7,-1,2,3};
	cout<<maxSum(arr)<<endl;
	cout<<maxSumEff(arr);
	return 0;
}