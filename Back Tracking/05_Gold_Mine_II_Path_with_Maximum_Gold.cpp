#include<bits/stdc++.h>
using namespace std;

void collectGold(vector<vector<int>>v, int i,int j,vector<vector<bool>>& visited,vector<int>& bag)
{
	if( i<0 || j<0 || i>=v.size() || j>=v[0].size() || visited[i][j]==true || v[i][j]==0 )
	   return;

	visited[i][j]=true;
	bag.push_back(v[i][j]);

	collectGold(v,i-1,j,visited,bag);  //up
	collectGold(v,i,j+1,visited,bag);  //right
	collectGold(v,i+1,j,visited,bag);  //down
	collectGold(v,i,j-1,visited,bag);  //left 

}

int gold2(vector<vector<int>> v)
{
	int n =v.size();
	int m =v[0].size();

	int result=0;
	vector<vector<bool>> visited (n,vector<bool >(m,0));

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(v[i][j]!=0 && visited[i][j]==false)
			{
				vector<int> bag;
				collectGold(v,i,j,visited,bag);

				int sum=0;
				for(auto val: bag)
					sum+=val;
				
				result=max(result,sum);
			}
		}
	}
return result;
}

int main()
{
	int R,C;
	cin>>R>>C;
	vector<vector<int>> v;
	for(int i=0; i<R; i++)
	{   vector<int> vt;
		for(int j=0;j<C;j++)
		{
			int a;
			cin>>a;
			vt.push_back(a);
		}
		v.push_back(vt);
	}

	cout<<gold2(v);
}


/* Input

6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

*/
