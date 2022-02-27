#include <bits/stdc++.h>

using namespace std;
//O(N log N)

int meetMax(int arr1[],int arr2[],int n)
{
	sort(arr1,arr1+n);   //sort fist array 
	sort(arr2,arr2+n);   //sort second array
	int i=1, j=0,result =1,curr=1;
	while(i<n && j<n)
	{ 
		if (arr1[i]<=arr2[j])      // this work as merge sort
		{
			curr++;   i++;
		}
		else
		{
			curr--;   j++;
		}
		result=max(result,curr);

	}

	return result;
}

int main()
{     int arrival[]={900,600,700};     // arrival time 
      int departure[]={1000,800,730};  // departure time
      int size=3;
      cout<<meetMax(arrival,departure,size);

	return 0;
}