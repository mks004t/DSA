#include<bits/stdc++.h>
using namespace std;

// Iterative  code // accending order //O(log n)
int binarySearch(int arr[],int start,int end,int x)
{
  while(start<=end)
  {
  
  //	int mid =(start+end)/2;
  	// this do over folw infinite+infinite;

  	//no over folw
  	int mid =start + (end-start)/2;
  
  	if(arr[mid]==x)
  		return mid;

  	else if(arr[mid]<x)
  		start=mid+1;

  	else
  		end=mid-1;
  }

  return -1;
}



int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}