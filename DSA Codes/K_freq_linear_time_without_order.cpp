#include <bits/stdc++.h>

using namespace std;
//O(N) solution

void printKfrequent(int arr[],int n,int k)
{
	unordered_map<int,int>m;
	 for(int i=0;i<n;i++)
		    m[arr[i]]++;

	vector<int>freq[n+1];   // vector of array or array within an array
	for(auto x: m)
	freq[x.second].push_back(x.first);

//printing the most frequent elements //in any order if frequeny are same
	int count=0;
	for(int i=n;i>=0;i--)
	{
		for(auto x:freq[i])
		{
			cout<<x<<" ";
			count++;
			if(count==k)
				return ;
		}
	} 

	
}

int main()
{  int arr[]={10,20,10,30,10};
    int size =sizeof(arr)/sizeof(arr[0]);
    int k=2;

    printKfrequent(arr,size,k);
	return 0;

}