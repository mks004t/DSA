#include<bits/stdc++.h>
using namespace std;
//O(v+e)
//Detect cycle in an undirected Graph
// print TRUE if Graph have cycle else false

bool DFSRec(vector<int>adj[],int s,bool visited[],int parent)
{
	visited[s]=true;
	for(int v:adj[s])
	{
		if(visited[v]==false)
			if(DFSRec(adj,v,visited,s)==true)
				return true;
			else if (v!=parent)
				return true;
	}
	return false;
}

bool callDFS(vector<int >adj[],int v)
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[i]=false;

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			if(DFSRec(adj,i,visited,-1)==true)
				return true;

	}
	return false;
}

void addEdge(vector<int > adj[], int u, int v)
{  //undirected 
	adj[u].push_back(v); //forward
	adj[v].push_back(u);  //backward
}



int main()
{  int v=4;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    
    cout<<callDFS(adj,v);

	return 0;
}