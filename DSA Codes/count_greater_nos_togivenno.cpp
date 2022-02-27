#include <bits/stdc++.h>

using namespace std;

void cGreaterNo(int arr[],int n)
{  map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
	}
  int cum_freq=0;
  
  for(auto it=m.rbegin();it!=m.rend();it++)
  { int freq= it->second;
  	it->second =cum_freq;
  	cum_freq+=freq;
   }

   for(int i=0;i<n;i++)
   {
   	cout<<m[arr[i]]<<" ";
   }


}

int main()
{ int arr []={2,8,10,8,5};
  int size =5;
  cGreaterNo(arr,size);


	return 0;
}