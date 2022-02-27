#include <bits/stdc++.h>

using namespace std;
// to find the difference b/w smallest and the largest packet having chocolate is minimum if if is distributed among "m" children,
// note there are many packet of chocolate but each child can get one bag only
//O(N log N)

int minDiff(int arr[],int n,int m)
{   if(m>n)
	return -1;

	sort(arr,arr+n);
	int result =arr[m-1]-arr[0]; 
	
	 for(int i=1;(i+m-1)<n;i++)
		result=min(result,(arr[i+m-1]-arr[i]));

	return result;
}

int main()
{  int arr[]={7,3,2,4,9,12,56};
   int size = sizeof(arr)/sizeof(arr[0]);
   int m=3;
   
   cout<<minDiff(arr,size,m);
	return 0;
}
