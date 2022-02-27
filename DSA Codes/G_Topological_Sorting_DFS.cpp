#include<bits/stdc++.h>
using namespace std;

// copyed from gfg
//O(V+E) time and O(v) space

void topologicalSortUtil(int v, bool visited[], stack<int>& Stack,vector<int>adj[])
{
    
    visited[v] = true;

    for (auto i : adj[v])
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack,adj);

    Stack.push(v);
}

void topologicalSort(vector<int> adj[],int V)
{
    stack<int> Stack;

    
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack,adj);

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}