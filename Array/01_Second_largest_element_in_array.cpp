#include<bits/stdc++.h>
using namespace std;

//finding the largest element in one traversal O(N)

int main()
{
	int arr[]={5,8,6,9,10,2,8};

	int n=sizeof(arr)/sizeof(arr[0]);

	int result =-1,large=0;
	for(int i=1; i<n; i++)
	{
		if(arr[i]>arr[large])
		{
			result=large;   // Now result have the value of largest element
			large=i;       //we changed the index of largest element
		}
      
		else      // arr[i]<arr[large]  
		{   // result ==-1 mean NO second largest element found yet
			
			if(result==-1 || arr[i]> arr[result])  //here we changed the second largest element
			    	result = i;
		}
	}

	cout<<"The second largest element is : "<<arr[result];

	return 0;
}