#include<bits/stdc++.h>
using namespace std;

//O(V*V)


int primsMST(vector<pair<int,int> > adj[], int V)
{	
	int parent[V];
	int key[V];
	bool mSet[V];
	int res=0;

	for(int i=0;i<V;i++)
	{
		
		key[i]=INT_MAX;
		mSet[i]=false;
	}

	key[0]=0;
	parent[0]=-1;

	for(int count=0; count<V; count++)  // loop can be run untill V-1 for MST 
	{							     // but to find min sum we run it to V
		int mini =INT_MAX, u;
		for(int v=0; v<V; v++)
		{
			if(!mSet[v] && key[v]<mini)
				mini=key[v],u=v;	
		}

		mSet[u]=true;
		res=res + key[u];

		for(auto it: adj[u])
		{
			int v=it.first;
			int weight=it.second;

			if(!mSet[v] && weight<key[v])
				parent[v]=u, key[v]=weight;
		}
	}

	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<" - "<<i<<"\n";
	}

	return res;

}

int main()
{
	int V,m;
	cin>>V>>m;

    vector<pair<int,int>> adj[V];
	int a,b,wt;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));

	}

	cout<<primsMST(adj,V);

	return 0;
}


 
/*

        Input
6 7        
0 1 5 
0 2 10 
0 3 100 
1 3 50 
1 4 200
3 4 250
4 5 50 

		Output
0 - 1
0 - 2
1 - 3
1 - 4
4 - 5
315     // this is the minimum sum MST

*/