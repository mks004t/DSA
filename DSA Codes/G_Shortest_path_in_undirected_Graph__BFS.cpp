#include<bits/stdc++.h>
using namespace std;
//O(v+E+V)=)(V+E)
//the sortest path from starting node to all the given nodes of the graph.

void shortestPath(vector<int>adj[],int s,bool visited[],int dist[])
{
	queue<int >q;
	q.push(s);
	
	dist[s]=0;
	visited[s]=true;
	
	while(q.empty()==false)
	{   int u=q.front();
		   q.pop();

		for(int v: adj[u])
		{ 
			if(visited[v]==false)
			{  
			  dist[v]=dist[u]+1;
				visited[v]=true;
				q.push(v);

			}

		}
	}


}

void callBST(vector<int>adj[],int v)
{
	int dist[v];         //distance array
	int visited[v+1];    //visited array
  
  for(int i=0;i<v;i++)
    { dist[i]=INT_MAX; 
      visited[i]=false;
	}

// call the BST
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			shortestPath(adj,i,visited,dist);
	}

//print the distances fron the starting node
	for(int i=0;i<v;i++)
		cout<<dist[i]<<" ";


}