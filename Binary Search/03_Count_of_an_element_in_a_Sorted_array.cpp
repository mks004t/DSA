#include<bits/stdc++.h>
using namespace std;

// No Of Occurrence =last occurence - first occurence +1;

int CountOccerence(int arr[],int n,int x)
{
	//first occurence 
	int first =lower_bound(arr,arr+n,x)-arr;

	//Last occurrence 
	int last =upper_bound(arr,arr+n,x)-arr-1;

	if(first==n)
	   return 0;
	

		return last-first+1;
}

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 2;
    
    cout<<"Count No of "<<x<<" is "<<CountOccerence(arr,n,x);
    
    return 0;
}