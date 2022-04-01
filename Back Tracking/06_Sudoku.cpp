#include<bits/stdc++.h>
using namespace std;

void display(vector<vector <int>> grid)
{
	int N = grid.size();
 
    for(int i=0; i<N; i++)
    {  for(int j=0; j<N; j++)
   	 {  cout<<grid[i][j]<<" ";
   	  }
      cout<<endl;
    }
}

bool isvalid(vector<vector<int >> &grid,int x,int y,int val)
{
  for(int i=0; i<grid.size(); i++)  //row
  	{  if( grid[i][y]==val)
  		return false;
  	}
  	
  	for(int j=0; j<grid[0].size(); j++)  //column
  	{  if( grid[x][j]==val)
  		return false;
  	}

  	// 3*3 Grid
  	int ii =x/3 *3;
  	int jj= y/3 *3;

  	for(int i=0;i<3;i++)
  	{
  		for(int j=0;j<3;j++)
  		{
  			if(grid[ii+i][jj+j]==val)
  				return false;
  		}
  	}
  	return true;
}

void solveSudoku(vector<vector<int >> &grid,int i,int j)
{
	if(i==grid.size())
	{
		display(grid);
		return;
	}

	int ni=0;
	int nj=0;
	if(j==grid[0].size()-1)
	{
		ni=i+1;
		nj=0;
	}
	else
	{
		ni=i;
		nj=j+1;
	}

	if(grid[i][j]!=0)
		solveSudoku(grid,ni,nj);
	else
	{
		for(int po = 1;po<=9;po++)
		{
			if(isvalid(grid,i,j,po)==true)
			 {   grid[i][j]=po;
		     	 solveSudoku(grid,ni,nj);
			     grid[i][j]=0;
			     
			 }	
		}
	}
}

int main()
{  vector<vector<int>> grid = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

solveSudoku(grid,0,0);
	
	return 0;
}