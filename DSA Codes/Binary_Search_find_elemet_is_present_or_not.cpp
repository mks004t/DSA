#include<bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> arr,int x)
{
	int low=0;
	int high= arr.size()-1;

	while(high>=low)
	{
		int mid =(low+high)/2;
		
		if(arr[mid]==x)
			return mid;

		else if( arr[mid]>x) //x < arr[mid]
		{
			high=mid-1;	
		}
		else
		{
			low=mid+1;
		}
	}
	
	return -1;

}

int main()
{
	vector<int> arr={10, 20, 30, 40, 50, 60, 70};
	int x=35;

	cout<<Binary_Search(arr,x);

	return 0;
}