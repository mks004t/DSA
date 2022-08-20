#include<bits/stdc++.h>
using namespace std;

//Time comp O(N) but need 3 triversal;
// Space complexity O(N) but need 2 arrays;
vector<int> getLeftSmaller(int arr[],int n)
{
	stack<pair<int,int>> s;
	vector<int> v(n);        //all element of 7

	for(int i=0; i<n; i++)
	{
		if(s.empty())
			v[i]= -1;          // 

		else if(!s.empty() && s.top().first <arr[i])
			v[i]=s.top().second;
		else
		{
			while(!s.empty() && s.top().first >= arr[i])
				s.pop();

			if(s.empty())
			   	v[i]= -1;
			  
			else
				v[i]=s.top().second;
		}

		s.push(make_pair(arr[i],i));
	}
    return v;
}

vector<int> getRightSmaller(int arr[],int n)
{
	stack<pair<int,int>> s;
	vector<int> v(n);

	for(int i=n-1; i>=0; i--)
	{
		if(s.empty())
			v[i]= n;

		else if(!s.empty() && s.top().first <arr[i])
			v[i]= s.top().second;
		else
		{
			while(!s.empty() && s.top().first >= arr[i])
				s.pop();

			if(s.empty())
			   	v[i]= n;
			  
			else
				v[i]= s.top().second;
		}

		s.push(make_pair(arr[i],i));
	}
    return v;
}

int getMaxArea(int arr[],int n)
{
	vector<int> NSL =getLeftSmaller(arr,n);
	vector<int> NSR =getRightSmaller(arr,n);

	int maxArea=0;
	for(int i=0; i<n; i++)
	{
	  cout<<NSR[i]<<" "<<NSL[i]<<endl;
		maxArea=max(maxArea, (arr[i]*(NSR[i]-NSL[i]-1)) );
	}
    cout<<endl;
	return maxArea;
}

int main()
{
	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n=sizeof(arr)/sizeof(arr[0]);
    
	cout<<getMaxArea(arr,n);
	return 0;
}