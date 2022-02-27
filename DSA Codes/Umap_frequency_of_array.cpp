#include <bits/stdc++.h>

using namespace std;

void printFreq(int arr[],int n)
{ 
	unordered_map<int ,int>m;
	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
	}

//print elements in any order
/*  for(auto x: m)
  {
  	cout<<x.first<<"   "<<x.second<<endl;
  }
*/

//print elements in order or the ocurence in array
	for(int i=0;i<n;i++)
	{
		if(m.find(arr[i])!=m.end())
			{   auto it =m.find(arr[i]);
		      cout<<(it->first)<<"   "<<(it->second)<<endl;
		      m.erase(it);
		    }
	}

}

int main()
{  int arr[]={10,5,20,5,10,5};
int size =6;
    printFreq(arr,size);

	return 0;
}