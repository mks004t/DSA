#include <bits/stdc++.h>

using namespace std;
int SumZero(int arr[],int n)
{ unordered_set<int>s;
	int psum=0;          // Prefix sum
	for(int i=0;i<n;i++)
	{
		psum+=arr[i];             // psum=psum+arr[i] 
		if(s.find(psum)!=s.end())
			return true;
		if(psum==0)               // corner case if (Psum==0) then the array have the set wuith sum zero
			return 0;
		s.insert(psum);
	}
	return 0;

}

int main()
{ int arr[]={1,4,13,-3,-10,5};
  int size=6;
  cout<<SumZero(arr,size);


	return 0;
}