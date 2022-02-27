#include<bits/stdc++.h>
using namespace std;

// print TRUE if Graph have cycle else false
//O(V+E)

bool DFSRec(vector<int> adj[],int s,bool visited[],bool recSt[])
{
	visited[s]=true;
	recSt[s]=true;           //recst is used to conform the cycle.

	for(int u: adj[s])
	{
		if(visited[u]==false && DFSRec(adj,u,visited,recSt))
			return true;
		else if(recSt[u]==true)
			return true;
	}
	
	recSt[s]=false;

	return false;

}

bool callDFS(vector<int> adj[],int v)
{
	bool visited[v];
	bool recSt[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		recSt[i]=false;
	}

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			if (DFSRec(adj,i,visited,recSt)==true)
				return true;

	}

	return false;
}