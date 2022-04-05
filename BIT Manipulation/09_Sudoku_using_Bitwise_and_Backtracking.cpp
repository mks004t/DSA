#include<bits/stdc++.h>
using namespace std;

void PrintGrid(vector<vector<int>> & grid)
{
	int R= grid.size();
	int C= grid[0].size();

	for(int i =0; i<R; i++)
   {
   	 for( int j=0; j<C; j++)
   	 {
   	 		cout<<grid[i][j]<<" ";
   	 }
   	 cout<<endl;
   }
}

void solve(vector<vector<int>> & grid,int rows[],int cols[],vector<vector<int>>TbyT,int i,int j, bool & flag)
{ 
	int R= grid.size();
	int C= grid[0].size();
	
	if(i==R )
		{flag=true;
		  PrintGrid(grid);
		    return;
		}

	if(grid[i][j]>0)
	{  // if last col then i=i+1,j=0,else i=i,j=j+1
		solve(grid,rows,cols,TbyT, j==C-1 ? i+1: i , j==C-1 ? 0: j+1 ,flag );
	}
	else
	{
		for(int num=1; num<=R; num++)
		{	int val= 1 << (num);
			if((rows[i] & val)==0 && (cols[j] & val)==0 && (TbyT[i/3][j/3] & val)==0 )
			{
				grid[i][j]=num;
				                  //on the bits
				rows[i] ^= val;
   	 		    cols[j] ^= val;
   	 		    TbyT[i/3][j/3] ^= val;     

				solve(grid,rows,cols,TbyT, j==C-1 ? i+1: i , j==C-1 ? 0: j+1 ,flag);
				
				grid[i][j]=0;  // back track so grid[i][j] =0
                                  // of the bits
				rows[i] ^= val;
   	 		    cols[j] ^= val;
   	 		    TbyT[i/3][j/3] ^= val;   
			}
		}
	}
}

bool solveSudoku(vector<vector<int>>grid)
{
   int rows[9];
   int cols[9];
   vector<vector<int>> TbyT(3,vector<int>(3,0));
   memset(rows,0,sizeof(rows));
   memset(cols,0,sizeof cols);

   for(int i =0; i<9; i++)
   {
   	 for( int j=0; j<9; j++)
   	 {
   	 		int val = 1 << (grid[i][j]);
   	 		rows[i]|=val;
   	 		cols[j]|=val;
   	 		TbyT[i/3][j/3]|= val;
   	 }
   }
      
      bool flag=0;
      solve(grid,rows,cols,TbyT,0,0,flag);
   	
   	if(flag==true)
   	 		return true;
   	 	else
   	 		return false;
   
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



if(solveSudoku(grid)!=true)
	cout<<"No Solution"<<endl;
	
	return 0;
}