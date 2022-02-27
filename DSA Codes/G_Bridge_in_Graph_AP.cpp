#include<bits/stdc++.h>
using namespace std;
/*
the whole algo is just like articulation point.
  the difference is that it have only 1 cheak.
  i.e if(low[current node (it)]>desc[parent(u)])
// input is same as AP.
  O(V+E)
*/
void bridge(int u,int parent,int &time,bool visited[],int desc[],int low[],vector<int>adj[])
{
	visited[u]=true;
	int child=0;
	desc[u]=low[u]=++time;

	for(auto it : adj[u])
	{
		if(!visited[it])
		{  
		   bridge(it,u,time,visited,desc,low,adj);
		   child++;

		   low[u]=min(low[u],low[it]);

		   if(low[it]>desc[u])
		   	cout<<u<<" "<<it<<endl;
		}

		else if(it!=parent)
			low[u]=min(low[u],desc[it]);

	}
}

int main()
{
	int V, m;
	cin>>V>>m;
	vector<int> adj[V];
	for(int i=0;i<m;i++)
	{   int u,v;
        cin>>u>>v;          // Graph is undirected;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


// we can make this as a function then call the above function 
	int disc[V]; // Discovery Time
	int low[V];  // Low Value
    bool visited[V];
    
    int parent =-1;
    int time =0;
   
    for(int i=0;i<V;i++)
    {
    	disc[i]=0;
    	visited[i]=false;
    }

   for(int i=0;i<V;i++)
   	for(auto it: adj[i])
	  if(visited[it]==false)
	     bridge(it,parent,time,visited,disc,low,adj);

   return 0; 
}