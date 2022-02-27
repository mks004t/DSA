#include<bits/stdc++.h>
using namespace std;
//O(V+E)
// works for disconnected graph also
//Recursive in nature


void DFS(vector<int> adj[],int s,bool visited[])
{ 
	visited[s]=true;
	cout<<s<<" ";

	for(int v: adj[s])
	{
		if(visited[v]==false)
		{
			visited[v]=true;
			DFS(adj,v,visited);
		}
	}

}

void callDFS(vector<int>adj[],int v)
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
		visited[v]=false;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			BFS(adj,i,visited);
	}
}
