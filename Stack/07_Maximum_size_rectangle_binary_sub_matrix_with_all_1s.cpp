#include<bits/stdc++.h>
using namespace std;

//Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s. 
// based on previous Question

// Time comp: O(R*C) & Space Comp: O(C)
vector<int> getLeftSmaller(int arr[],int n)
{
	stack<pair<int,int>> s;
	vector<int> v(n,-1);        //all element of 7

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
	vector<int> v(n,n);

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
	for(int i=0;i<n;i++)
	{
		maxArea=max(maxArea, (arr[i]*(NSR[i]-NSL[i]-1)) );
	}
	return maxArea;
}

int main()
{
	vector<vector<bool>> rect= {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
	int n= rect.size();
	int m= rect[0].size();

	int arr[m];
	memset(arr,0,sizeof arr);
    
    int maxres=0;
	for(int i=0; i<n; i++)
	{   
		for(int j=0; j<m; j++)
		{
			if(rect[i][j]==0)
				arr[j]=0;
			else
				arr[j]+=rect[i][j];
		}

		int ans=getMaxArea(arr,m);
		maxres=max(maxres,ans);
	}
    
	cout<<maxres;
	return 0;
}