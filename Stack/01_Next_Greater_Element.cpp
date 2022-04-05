#include<bits/stdc++.h>
using namespace std;

// left to right(n-1 to 0)

void nextGreatest(int arr[],int n)
{
	int ans[n];
	stack<int>s;

	for(int i=n-1;i>=0;i--)
	{
		if(s.empty())
			ans[i]=-1;

		else if(s.size()>0 && s.top()> arr[i])
			ans[i]=s.top();

		else  //(s.top()<=arr[i])
			{  
				while(s.size()>0 && s.top()<=arr[i])
				  {
				  	  s.pop();
				  }
				  if(s.empty())
				  	ans[i]=-1;
				  else
				  	ans[i]=s.top();
			}

			s.push(arr[i]);
	}
   
   for(int i=0; i<n; i++)
   	cout<<ans[i]<<" ";
}

int main()
{
	int arr[]={11, 13, 21, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	nextGreatest(arr,n);
	return 0;
}