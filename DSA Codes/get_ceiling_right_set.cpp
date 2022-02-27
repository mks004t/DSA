#include <bits/stdc++.h>

using namespace std;
//optimised method  // O(N log N) //space O(N);

void ceiling(int arr[],int n)
{  set<int>s;
	int result[n];
	for(int i=n-1;i>=0;i--)
	{
		auto it=s.lower_bound(arr[i]);

		if(it==s.end())
			result[i]=-1;
		else
			result[i]=*it; 
		
		s.insert(arr[i]);

	}
for(int i=0;i<n;i++)
	cout<<result[i]<<" ";

}


int main()
{int arr[]={10,100,200,30,120,120};
  int size=6;
  ceiling(arr,size);


	return 0;
}