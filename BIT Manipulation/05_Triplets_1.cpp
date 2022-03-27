#include <bits/stdc++.h>
using namespace std;

/*
1. You are given an array(arr) of N numbers.
2. You have to select three indices i,j,k following this condition -> 
      0 <= i < j <= k < arr.length
3. Two numbers X and Y as defined as :
      X = arr[i] ^ arr[i+1] ^ ... ^ arr[j - 1]
      Y = arr[j] ^ arr[j+1] ^ ... ^ arr[k]
4. You have to print the number of triplets where X is equal to Y.
*/

int triplate(int arr[],int n)
{
	int count=0;

	for(int i=0; i<n; i++)
	{
		int val=arr[i];

		for(int k=i+1; k<n; k++)
		{
			val = val ^ arr[k];


			if(val==0)
				count+=(k-i);
		}
	}
	return count;
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< triplate(arr, n)<<endl;
    return 0;
}