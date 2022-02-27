#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>arr;
	    for(int i=0;i<n;i++ )
	    cin>>arr[i];
	   sort(arr.begin(),arr.end());
	   for(int i=0;i<n-1;i+2)
	   {
	       if(arr[i]%2!=0&&arr[i+1]%2!=0||arr[i]%2==0&&arr[i+1]%2==0)
	       {
	           cout<<"-1"<<endl;
	           break;
	       }
	       if(arr[i]%2==0&&arr[i+1]%2!=0)
	       {
	           swap(arr[i],arr[i+1]);
	       }
	   }
	   for(auto x: arr)
	    cout<<x<<" ";
	    
	    
	    
	    
	}
	return 0;
}

