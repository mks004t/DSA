#include<bits/stdc++.h>
using namespace std;

// return index// array must be sorted
int last_occuresnce(vector<int> arr,int x)
{
	int low=0;
	int high= arr.size()-1;

	while(high>=low)
	{
		int mid=(low+high)/2;

		if(arr[mid]>x)  // greater
			high=mid-1;

		else if(arr[mid]<x) //smaller
			low=mid+1;

		else
		{
			if(mid==arr.size()-1 ||arr[mid]!=arr[mid+1])
				return mid;
			else
				low=mid+1;

		}

	} 

	return -1;
}

int main()
{
	vector<int>v={5,10,10,15,20,20,20};
	cout<<last_occuresnce(v,20);
	
	return 0;
}