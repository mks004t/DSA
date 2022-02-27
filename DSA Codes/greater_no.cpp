#include <bits/stdc++.h>
using namespace std;

// not working code

void cGreaterNo(int arr[],int n)
{vector<int> v(arr,arr+n);
	sort(v.begin(),v.end());
for(auto it=v.begin();it!=v.end();it++)
    { auto itt =binary_search(v.begin,v.end,*it)
      int count =0;
      while(upperbound(it)!=v.end())
      {
      	
      	count++;

      }
      cout<<count<<" ";

    }


}


int main()
{
  int arr []={2,8,10,8,5};
  int size =5;
  cGreaterNo(arr,size);

	return 0;
}