#include<bits/stdc++.h>
using namespace std;

//Note:- array must be sorted

int first_occuresnce(vector<int>arr,int x)
{
	int low=0;
	int high=arr.size()-1;

	while(high>=low)
	{
		int mid=(low+high)/2;

		if(arr[mid]>x)
			high=mid-1;

		else if(arr[mid]<x)
			low=mid+1;
		else
		{
			if(mid==0 || arr[mid-1]!=arr[mid])
				return mid;
			else
				high= mid-1;
		}
	}
	return -1;
}

int main()
{
	vector<int>v={5,5,10,10,15,20,20,20};
	cout<<first_occuresnce(v,5);
	
	return 0;
}