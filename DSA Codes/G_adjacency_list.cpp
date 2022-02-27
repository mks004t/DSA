#include<bits/stdc++.h>
using namespace std;
// Graph in C++  * undiected

void addEdge(vector<int > adj[], int u, int v)
{  //undirected 
	adj[u].push_back(v); //forward
	adj[v].push_back(v);  //backward
}

void printGraph(vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(auto x: adj[i])
			cout<<x<<" ";
		cout<<endl;
	}
}

int main()
{  int v=4;
	vector<int> adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    
    printGraph(adj,4);

	return 0;
}

/*  output
1 2
1 2 3
2 2
3
*/