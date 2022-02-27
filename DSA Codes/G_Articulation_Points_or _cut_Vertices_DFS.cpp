#include<bits/stdc++.h>
using namespace std;
/*
Step 1: increasing  discTime & lowValue by 1 each time.
        dfs
Step 2: Check if the subtree rooted with v has a connection to one of the ancestors of u.
Step 3: Update low value of u for parent function calls.
Step 4: If u is root of DFS tree and has two or more children than AP

O(V+E) time
*/

// AP() is just like DFS 
void AP(vector<int> adj[],int u,bool visited[],int discTime[],int lowValue[],int &time,int parent,bool isAP[])
{
	int child =0;
	visited[u]=true;
//Step 1
	discTime[u]=lowValue[u]= ++time;

	for(auto v :adj[u])
	{
		if(!visited[v])
		{
			child++;
			AP(adj,v,visited,discTime,lowValue,time,u,isAP);
//Step 2
			lowValue[u]= min(lowValue[u],lowValue[v]);

			if(parent!=-1 && lowValue[v]>=discTime[u])
				isAP[u] = true;
		}
//Step 3
		else if(v!= parent)
			lowValue[u]= min(lowValue[u],discTime[v]);
	}	
//Step 4
	if(parent==-1 && child >1)
			isAP[u]=true;
	
}

void atticulationPoint(vector<int> adj[],int V)
{
	int discTime[V];  //discovery times
	int lowValue[V];
	bool visited[V];
	bool isAP[V];

	for(int i=0;i<V;i++)
	{
		discTime[i]=0;
		visited[i]=false;
		isAP[i]=false;
	}

	int time = 0;
	int parent = -1;

// checking for unconnected graph
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		 AP(adj,i,visited,discTime,lowValue,time,parent,isAP);
	}

//print APs
	for(int i=0;i<V;i++)
		if(isAP[i])
			cout<<i<<" ";

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

	atticulationPoint(adj,V);

   return 0; 
}

/*   input
5 5
1 0
0 2
2 1
0 3
3 4
     output
0 3 
*/
