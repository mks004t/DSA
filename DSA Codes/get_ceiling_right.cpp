#include <bits/stdc++.h>

using namespace std;
//Nive Method or Not optimised method//O(n*n)

void ceiling(int arr[],int n)
{  
	for(int i=0;i<n;i++)
	{ int diff=INT_MAX;
		for(int j=i+1;j<n;j++)
			if(arr[j]>=arr[i])
				diff=min(diff,arr[j]-arr[i]);
		if(diff==INT_MAX)
			cout<<"-1"<<" ";
		else
			cout<<(arr[i]+diff)<<" " ;

	}

}


int main()
{int arr[]={10,100,200,30,120,120};
  int size=6;
  ceiling(arr,size);


	return 0;
}