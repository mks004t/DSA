#include<bits/stdc++.h>
using namespace std;

void rightSmaller(int arr[],int n)
{
	int ans[n];
	stack<int> s;

	for(int i=n-1; i>=0; i--)
	{
		if(s.empty())
			ans[i]=-1;
		
		else if(s.size()>0 && s.top()<arr[i])
			ans[i]=s.top();
		
		else
		{
			while(s.size()>0 && s.top()>=arr[i])
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
	rightSmaller(arr,n);
	return 0;

}

// O/P: 3 3 3 -1 (abolve)

// I/P: 4 5  2 10 8  
// O/P: 2 2 -1 8 -1