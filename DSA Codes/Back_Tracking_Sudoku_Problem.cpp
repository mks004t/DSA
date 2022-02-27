#include<bits/stdc++.h>
using namespace std;

#define N 9

bool isSafe(int grid[N][N],int i,int j,int n)
{
	for(int k=0; k<N; k++)
	{
		if(grid[k][j]==n||grid[i][k]==n) //check for row or column
			return false;
	}

	int s=sqrt(N);
	int rs=i-i%s;  //starting index of row
	int cs=j-j%s;  //starting indexof column
                      
	for(int ii=0; ii<s; ii++)
	for(int jj=0; jj<s; jj++)       
		if(grid[ii+rs][jj+cs]==n)  //check for sub matrix
			return false;

	return true;
}


bool solve(int grid[N][N] )
{
	int i,j;

	for( i=0; i<N; i++)
	 for( j=0; j<N; j++)
	 	if(grid[i][j]==0)  //if the cell is empty
	 		break;
	
	if(i==N && j==N)   // if completed
		return true;

	for(int n=1; n<=N; n++)
	{
		if(isSafe(grid,i,j,n))
		{
			grid[i][j]=n;
			if(solve(grid))
				return true;
			grid[i][j]=0;
		}
	}
  return false;
}

int main()
{  int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if(solve(grid)==true)
	{ for(int i=0; i<N; i++)
	   {  for(int j=0; j<N; j++)
	   	 {  cout<<grid[i][j]<<" ";
	   	  }
	      cout<<endl;
	    }
	}
	else
		cout<<"-1";
	return 0;
}