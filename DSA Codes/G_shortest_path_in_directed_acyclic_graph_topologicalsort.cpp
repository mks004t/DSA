#include<bits/stdc++.h>
using namespace std;

// s is the source(given) , valid for directed acyclic graph ,with -ve weight also
// O(V+E)

void topologicalsort(vector<pair<int,int>> adj[],int s, bool visited[], stack<int> &st)
{
	visited[s]=true;
	for(auto i: adj[s])
	{
		if(visited[i.first]==false)
			topologicalsort(adj,i.first,visited,st);

	}

	st.push(s);
}

void shortestPath(vector<pair<int,int>> adj[],int v,int source)
{
	stack<int>st;
	int dist[v];
	bool visited[v];

	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		dist[i]=INT_MAX;
	}
// calling topological sort;
	
	for(int i=0;i<v;i++)
	{
		if(visited[i]== false)
			topologicalsort(adj,i,visited,st);
	}


// initilizing source vertes as 0 
	dist[source]=0;

    while(st.empty()==false)
    {
    	int u= st.top();
    	st.pop();

    	if(dist[u]!=INT_MAX)
    	{
    		for(auto i: adj[u])
    		{
    			if( dist[i.first] > dist[u] + i.second )
    				dist[i.first] = dist[u] + i.second ;
    		}
    	}

    }

    for(int i=0; i<v; i++)
    	(dist[i]==INT_MAX) ? cout<<"INT_MAX"<<" " : cout<< dist[i] <<" ";


}


void addEdge(vector<pair<int,int>> adj[], int u, int v,int wt)
{  //undirected  weighted
	adj[u].push_back({v,wt}); 
}



int main()
{  int v=6;
	vector<pair<int,int>> adj[v];
	addEdge(adj,0,1,5);
    addEdge(adj,0,2, 3);
    addEdge(adj,1,3,6);
    addEdge(adj,1,2,2);
    addEdge(adj,2,4,4);
    addEdge(adj,2,5,2);
    addEdge(adj,2,3,7);
    addEdge(adj,3,4,-1);
    addEdge(adj,4,5,-2);
    
    int source=1;
    shortestPath(adj,v,source);

	return 0;
}