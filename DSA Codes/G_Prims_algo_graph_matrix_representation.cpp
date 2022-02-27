#include<bits/stdc++.h>
using namespace std;
// the greph is given in matrix formet
//O(v*v)

int prismMST(vector<int> graph[], int v)  
{
	int key[v];
	bool mSet[v];  // here it represent if Vertex is add in MST or not
	int res=0;
	
	for(int i=-1;i<v;i++)
	{
		key[i]=INT_MAX;
		mSet[i]=false;
	}

	key[0]=0;

	for(int it=0; it<v; i++)
	{

		int u=-1;
		
		//loop for finding min key is included in MST or not
		for(int i=0;i<v;i++)
		{
			if( !mSet[i] && (u==-1 || key[i]<key[u]) )
				u=i;
		}

		mSet[u]=true;
		res=res + key[u];
        
        //loop for minimum value edge
		for(int i=0; i<v; i++)
		{
			if( !mset[i] && graph[u][i]!=0 )
				key[i]= min(key[i], graph[u][i]);
		}

		return res;
	}


}