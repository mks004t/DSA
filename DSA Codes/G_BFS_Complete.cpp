#include<bits/stdc++.h>
using namespace std;

// the BFS function print the elements of a graph.
// where as callBFS take care if all the disconnected graph must traverse.
// O(V+E)  Time comp

void BFS(vector<int> adj[],int s,bool visited[])
{ 
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(q.empty()==false)  // while q is not empty
	{
		int u=q.front();
		q.pop();

		cout<<u<<" ";   //print all the elsements of graph in BFS order

		for(int v: adj[u])   //triversing  nodes of graph !
		{
			if(visited[v]==false)  //which are unvisited and than mark it as visited
			{
				visited[v]=true;
				q.push(v);
			}
		}

	}

}

void callBFS(vector<int> adj[],int v)
{
	bool visited[v+1];

	for(int i=0;i<v;i++)
		visited[v]==false;

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			BFS(adj,i,visited)
	}
}

// Question : calculate  the Number of Islands in the graph 
// just add count variable in the CALLBFS function
// eg
/*

	int callBFS(vector<int>adj[],int v)
	{   bool visited[v+1];
		int count = 0;
		for(int i=0;i<v;i++)
		   visited[i]=false;

		for(int i=0;i<v;i++)
		{  if(visited[i]==false)
			{ BFS(adj,i,visited);
				count++;
			}
		}

		return count;

	}

//Note the BFS function remain same

*/