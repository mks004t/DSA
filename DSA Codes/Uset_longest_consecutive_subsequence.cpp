#include <bits/stdc++.h>

using namespace std;

int getLongest(int arr[],int n)
{ unordered_set<int>s(arr,arr+n);
	
int result=1;
	for(int i=0;i<n;i++)
	{
		if(s.find(arr[i]-1)!=s.end())
		{
			int curr=1;
			while(s.find(arr[i]+curr)!=s.end())
				  curr++;


			result=max(result,curr);

		}
	}
return result;
}

int main()
{ int arr[]={3,8,4,5,7};
  int n=5;
  cout<<getLongest(arr,n);
	return 0;
}

