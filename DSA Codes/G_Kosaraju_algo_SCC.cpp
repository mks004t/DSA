#include<bits/stdc++.h>
using namespace std;

/* used to find Strongly Connected Components (SCC)
Step 1 : store the nodes of graph in a stack by DFS
         according to there finish time.(Just DFS and stack).
Step 2 : transpose of matrix or adjacency list and mark visited as false.
Step 3 : traverse the graph according to the stack (max time first i.e top of stack)
         if visited is falseand pop stack 1by1.
*/

//O(V+E) time 

void dfs(vector<int>adj[],int v,vector<bool>& visited, stack<int>& st )
{
	visited[v]=true;
	for(int it :adj[v])
	{  if(!visited[it])
		  dfs(adj,it,visited,st);
	 }  
	st.push(v);

}

void revDFS(vector<int>transpose[],int v,vector<bool>& visited)
{   
	cout<<v<<" ";
	visited[v]=true;
	for(int i: transpose[v])
	{
		if(!visited[i])
			revDFS(transpose,i,visited);
	}

}

void Kosaraju(vector<int>adj[],int V)
{   stack<int> st;
	vector<bool> visited(V,0);

	for(int i=0;i<V;i++)
	  {   if(!visited[i])
	  	   dfs(adj,i,visited,st);
	  }

	// Step 2
	 
	 vector<int> transpose[V];

	 for(int i=0;i<V;i++)
	 {  visited[i]=false;
	 	for(int it: adj[i])
	 		transpose[it].push_back(i);
	 }

	 //Step 3

	 while(!st.empty())
	 {
	 	int u=st.top();
	 	st.pop();
	 	if(!visited[u])
	 	{
	 		cout<<"SCC: ";
	 		revDFS(transpose,u,visited);
	 		cout<<endl;
	 	}
	 }


}


int main()
{   int n,m;
	cin>>n>>m;
	vector<int>adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

   Kosaraju(adj,n);

	return 0;
}

/* input
5 5 
0 1 
1 2 
2 0 
1 3 
3 4
*/