#include<bits/stdc++.h>
using namespace std;

//Right to left (0 -> n-1)

void leftSmaller(int arr[],int n)
{
	stack<int> s;
	int ans[n];

	for( int i=0;i<n;i++)
	{
		if(s.empty())
			ans[i]=-1;

		else if(s.size()>0 && s.top() < arr[i])
			ans[i]=s.top();
		else
		{
			while(s.size()>0 && s.top() >= arr[i])
				s.pop();
			
			if(s.empty())
				ans[i]=-1;
			else
				ans[i]=s.top();
		}

		s.push(arr[i]);
	}


	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
}


int main()
{
	int arr[]={11, 13, 21, 3};
	int n=sizeof(arr)/sizeof(arr[0]);
	leftSmaller(arr,n);
	return 0;

}

// O/P: -1 11 13 -1