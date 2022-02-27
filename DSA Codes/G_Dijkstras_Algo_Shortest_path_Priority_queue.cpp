#include<bits/stdc++.h>
using namespace std;

//O(ElogV)

void Dijkstra(vector<pair<int,int>>adj[],int V,int source)
{   // priority queue min heap i.e it gives the minimum from top
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;

	vector<int> dist(V+1,INT_MAX);
	vector<int> mSet(V,false);

	dist[source]=0;
	pq.push(make_pair(0,source));  //dist, from

	while(!pq.empty())
	{
		int prevdist=pq.top().first;
		int prev =pq.top().second;     //u
		pq.pop();

		mSet[prev]=true;

		for(auto it: adj[prev])        //adj[u] 
		{
			int next =it.first;        //from
			int nextDist=it.second;    // dist/ weight , get from adj list

			if( !mSet[next] && dist[next] > dist[prev] + nextDist)
			{
				dist[next] = dist[prev] + nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	for(int i=0;i<V;i++)
	{
		cout<<source<<"-"<<i<<" -- "<<dist[i]<<endl;;
	}



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
int source;
cin>>source;
	Dijkstra(adj,V,source);

	return 0;
}
