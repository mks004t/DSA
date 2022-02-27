#include <bits/stdc++.h>

using namespace std;
// Print distinct elements in array //O(N)
void printDist(int arr[],int n)
{
	unordered_set<int>s;
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i])==s.end())
		{
			cout<<arr[i]<<" ";
			s.insert(arr[i]);

		}
	}
}
//print repeting elements //O(N)
void printRepet(int arr[], int n)
{
	unordered_set<int> s;
	
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i])==s.end())
			s.insert(arr[i]);
		else
			cout<<arr[i]<<" ";
	}
}

int main()
{ int arr[]={10,8,10,10,7};
  int size= sizeof(arr)/sizeof(arr[0]);
  printDist(arr,size);

  cout<<"----------------"<<endl;
  printRepet(arr,size);

	return 0;
}