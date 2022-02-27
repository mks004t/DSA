#include<bits/stdc++.h>
using namespace std;


//O(N*log N)

bool mycomp(pair<int,int>a,pair<int,int>b)
{
	return (a.second<b.second);
}

vector<pair<int,int>> actSel(vector<pair<int,int>> arr,int n)
{	sort(arr.begin(),arr.end(), mycomp );
	int prev=0;
	int res=0;
	
	vector<pair<int,int>> result;
    result.push_back(make_pair(arr[prev].first,arr[prev].second));

    res++;
	
	for(int curr=1;curr<n;curr++)
	{
		if(arr[curr].first>=arr[prev].second)
		{
			result.push_back(make_pair(arr[curr].first,arr[curr].second));
			res++;
			prev=curr;
		}
	}
    
   cout<<"NO of Activities"<<res<<endl;
	return result;
}


int main()
{
	 vector<pair<int,int>> p;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		p.push_back({a,b});
	}
 vector<pair<int,int>> res;
	res=actSel(p,n);
	
	for(auto i: res)
		cout<<i.first<<" "<<i.second<<endl;

	return 0;
}

	/*
Input
6
1 2
3 4
0 6
5 7
8 9
5 9
	*/