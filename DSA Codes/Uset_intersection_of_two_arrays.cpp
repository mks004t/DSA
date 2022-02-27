#include <bits/stdc++.h>
using namespace std;

//O(N+M) time comp
//In unordered map search() and find() and insert() all are O(1).

void cElement(int arr1[],int n1,int arr2[],int n2)
{
	unordered_set<int>s(arr2,arr2+n2);
	for(int i=0;i<n1;i++)
	{if(s.find(arr1[i])!=s.end())
		cout<<arr1[i]<<" ";

	}
}

int main()
{ int arr1[]={10,15,20,25,30,50};
int arr2[]={30,5,15,80};
int n1=6;
int n2 =4;
  cElement(arr1,n1,arr2,n2);

return 0;
}