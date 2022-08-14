#include<bits/stdc++.h>
using namespace std;

// find the first occurrence and last occurrence

int findFirst(int arr[],int start,int end,int x)
{  int res=-1;
	while(start<=end)
	{
		int mid =start+(end-start)/2;

		if(arr[mid]==x)
		{   res=mid;
			end=mid-1;
		}
		
		 if(arr[mid]<x)
			start=mid+1;
		
		else
			end=mid-1;
	}

	return res;
}

// Last occurrence 

int findLast(int arr[],int start,int end,int x)
{
	int res=-1;
	while(start<=end)
	{
		int mid = start+ (end-start)/2;

		if(arr[mid]==x)
		{   res=mid;
		    start=mid+1;
		}
		
		if(arr[mid]<x)
			start=mid+1;
		
		else
			end=mid-1; 

	}
}

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 8;
    
   cout<<"First Occurrence: "<<findFirst(arr,0, n-1, x)<<endl;
   cout<<"Last Occurence  : "<<findLast(arr,0, n-1, x);
    
    return 0;
}