#include<bits/stdc++.h>
using namespace std;
/*
Step 1: Relax all edges V-1 times.
Step 2: Check for negative weight cycle.
Step 3: print shortest path if not cycle

O((V*E) Time complexity
*/

// Structure is used to store the edges 
struct node {
	int u;
	int v;
	int wt;

	node(int first,int second,int weight)
	{
		u=first;
		v=second;
		wt=weight;
	}
};


void bellmanFord(vector<node>edge ,int V,int source)
{
	vector<int> dist(V,INT_MAX); //if we replace INT_MAX with a big no like 1000000                             
	dist[source]=0;              //then we dont need the INT_MAX check bec.	                         
                                 //INT_MAX is -ve & it cause negative cycle
//Step 1                         // result in wrong answer eg. dist(V,10000)

	for(int count=0; count<=V-1; count++)  //can start from 1 to V-1
	{
		for(auto it: edge)
		{
			if(dist[it.u]!=INT_MAX && dist[it.v] > dist[it.u] + it.wt  )
				dist[it.v] = dist[it.u] + it.wt ;
		}

	}
//Step 2

	int flag=0;
	for(auto it: edge)
	{
		if(dist[it.u]!=INT_MAX && dist[it.v] > dist[it.u] + it.wt)
		{
			cout<<"Negative Weight Cycle";
			flag=1;
			break;    
		}
	}
//Step 3

	if(!flag)
	{
		for(int i=0;i<V;i++)
			cout<<source<<"--"<<i<<" "<<dist[i]<<endl;
	}

}


int main()
{  int V,m;
	cin>>V>>m;
	vector<node> edge;
	for(int i=0;i<m;i++)
	{  int u,v,wt;
		cin>>u>>v>>wt;
		edge.push_back(node(u,v,wt));
	}

	int source;
	cin>>source;

	bellmanFord(edge,V,source);


	return 0;
}

/*  input
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0

output
source--edge  min weight

0--0 0
0--1 5
0--2 3
0--3 3
0--4 1
0--5 2
*/