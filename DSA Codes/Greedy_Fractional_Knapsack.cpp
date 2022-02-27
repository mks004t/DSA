#include<bits/stdc++.h>
using namespace std;
bool mycomp(pair<int,int>a, pair<int,int>b)
{ 
	double r1=(double) a.first/a.second;
	double r2= (double) b.first/b.second;

	return r1>r2;
}
double fKnapS(vector<pair<int,int>> arr,int n,int weight)
{
	sort(arr.begin(),arr.end(),mycomp);
	double result=0.0;

	for(int i=0;i<n;i++)
	{
		if(weight>=arr[i].second)
		{	result+=arr[i].first;
		    weight=weight-arr[i].second;
		}

		else
		{
			result+=arr[i].first*(double)weight/arr[i].second;
			break;
		}

	}
	return result;
}

int main()
{
	 vector<pair<int,int>> p;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;   //price,weight
		cin>>a>>b;
		p.push_back({a,b});
	}
	int weight;
    cin>>weight;
	cout<<fKnapS(p,n,weight);

	return 0;
}


/*
3         //size
60 10
100 20
120 30
50       //weight of the knapsack

*/