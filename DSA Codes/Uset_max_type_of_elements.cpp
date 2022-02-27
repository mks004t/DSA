#include <bits/stdc++.h>
using namespace std;

int maxTypEle(int arr[],int n,int k)
{ unordered_set<int>s(arr,arr+n);
	int count =s.size();
	if(count>=n/k)
		return n/k;
	else
		return count;
}

int main()
{ 
int arr[]={10,15,20,25,20,10};
int n =6;
int k=2;
cout<<maxTypEle(arr,n,k);
 
return 0;
}