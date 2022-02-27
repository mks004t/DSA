#include<bits/stdc++.h>
using namespace std;
//this is not a complete BSF algo 
// this doesnot work when starting node or graph is disconnected
void BFS(vector<int>adj[], int v, int s)  // v is the no of vertices && s is the starting vertex
{
	bool visited[v+1];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}

	queue<int> q;
	visited[s]=true;
	q.push(s);

	while(q.empty()==false)
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int v :adj[u])
		  {
		  	if(visited[v]==false)
		  	{
		  		visited[v]==true;
		  		q.push(v);
		  	}
		  }
	}

}