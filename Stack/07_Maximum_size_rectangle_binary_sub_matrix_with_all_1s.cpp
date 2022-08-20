#include<bits/stdc++.h>
using namespace std;

//Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s. 
// based on previous Question (Largest / Maximum area in Histogram)

// Time comp: O(R*C) & Space Comp: O(C)
int getMaxArea(int arr[],int n)
{
	stack<int> s;
	int res=0;
	int tp;     //  temp index, which is larger and removed from stack;
	int curr;   // it store the curr area.

	for(int i=0; i<n; i++)
	{
		while(s.empty()==false && arr[s.top()]>=arr[i])
		{
			tp=s.top();
			s.pop();

			curr= arr[tp]* (s.empty() ? i : (i-s.top()-1) );
			res=max(res, curr);
		}
		s.push(i);
	}

	// now we are remain with elements whose next smaler doesnot exist
	while(s.empty()==false)
	{
		tp=s.top();
		s.pop();

		curr=arr[tp]* (s.empty() ? n : n-s.top()-1);
		res=max(res,curr);
	}
	
	return res;
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