#include <bits/stdc++.h>

using namespace std;

bool mycomp(pair<int,int>p1,pair<int,int>p2)
{
	if(p1.second==p2.second)
		return p1.first<p2.first;

	return p1.second>p2.second;
}

void printKfrequent(int arr[],int size,int k)
{ // creating a unordered map , element with their frequenct //O(n)
	   unordered_map<int,int> m;
	     for(int i=0;i<size;i++)
		    m[arr[i]]++;
// copy this unordered map to vector of pair for sorting//O(n)

    vector<pair<int,int>> v(m.begin(),m.end());   //O(n log n)

 // Now sort the VOP according to second element
    sort(v.begin(),v.end(),mycomp);

  // print the result  // O(k log n)
    for(int i=0;i<k;i++)
    	cout<<v[i].first<<" ";

}


int main()
{  int arr[]={10,20,10,30,10};
    int size =sizeof(arr)/sizeof(arr[0]);
    int k=2;

    printKfrequent(arr,size,k);
	return 0;

}