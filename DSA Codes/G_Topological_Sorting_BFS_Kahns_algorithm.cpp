#include<bits/stdc++.h>
using namespace std;
//Topological sorting using BFS
//Kahn’s algorithm for Topological Sorting
//O(V+E) time and Auxiliary Space: O(V) 

/* to find the graph have a cycle or not
    use a count variable inside while loop
    if (count > v) return graph have a cycle 
*/
void tpSortBFS(vector<int> adj[], int v)
{
    vector<int > indegree(v,0);
	queue<int> q;

// counting indegree of nodes.

	for(int i=0;i<v;i++)
	   for(int it : adj[i])
	      indegree[it]++;	

//inderting all zero indree nodes into queue.
	
	for(int i=0;i<v;i++)
	   if(indegree[i]==0)
	     q.push(i);
  
  //int count=0;
// triversing 
	while(q.empty()==false)
	{  	
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int itt :adj[u])
		 {   
		    indegree[itt]--;
			if(indegree[itt]==0)   
    
    // combining both upper code we get this , if(--indegree[itt]==0)
				
				q.push(itt);

    		}

    //count++;

	}
	
	/*
	  if(count>v) return true;
	  
	  else return false;
	  
     */

}

void addEdge(vector<int > adj[], int u, int v)
{  //undirected 
	adj[u].push_back(v); //forward

}



int main()
{   int v=6;
	vector<int> adj[v];
	addEdge(adj,5,2);
	addEdge(adj,5,0);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    
    tpSortBFS(adj,v);

	return 0;
}