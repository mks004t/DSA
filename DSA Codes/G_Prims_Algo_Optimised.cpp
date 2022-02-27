#include<bits/stdc++.h>
using namespace std;

//O((E+V)log V)   if only 1 graph then O(E log V)


int primsMST(vector<pair<int,int>> adj[],int V)
{   
	int parent[V];
	int key[V];
	bool mSet[V];
	int res=0;

	for(int i=0;i<V;i++)
	  key[i]=INT_MAX , mSet[i]=false;
   
  priority_queue< pair<int,int> ,vector< pair<int,int>> , greater<pair<int,int>> > pq;

   key[0]=0;
   parent[0]=-1;
   pq.push({0,0});

   while(!pq.empty())
   {
   		int u=pq.top().second;
   		pq.pop();

   		mSet[u]=true;
   		res= res +key[u];

   		for(auto it : adj[u])
   		{
   			int v=it.first;
   			int weight=it.second;

   			if(!mSet[v] && weight<key[v])
   			{
   				parent[v]=u;
   				key[v]=weight;
   				pq.push({key[v],v});
   			}
   		}

   }

for(int i=1;i<V;i++)
	cout<<parent[i]<<" - "<< i<<"\n";


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
