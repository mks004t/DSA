#include<bits/stdc++.h>
using namespace std;
#define N 4

bool isSafe(int maze[][N],int i,int j)
{
	return (i<N && j<N && maze[i][j]==1);
}

bool solveMazeRec(int maze[][N], int sol[][N], int i, int j)
{ 
    if(i==N-1 && j==N-1) { sol[i][j]=1; return true;}
    
    if(isSafe(maze,i,j)==true)
    {
    	sol[i][j]=1;
    	if(solveMazeRec(maze,sol,i+1,j)==true) return true;      //down move

    	 else if(solveMazeRec(maze,sol,i,j+1)==true) return true;  //left move

    	sol[i][j]=0;    //if not true then it mark as 0 again 

    }
 return false;
}

bool solveMaze(int maze[][N])
{   int sol[N][N];
	for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    	sol[i][j]=0;

	if(solveMazeRec(maze,sol,0,0)==false)
		return false;
	else
	{ for(int i=0;i<N;i++)
	   {for(int j=0;j<N;j++)
	    {cout<<sol[i][j];}
	    cout<<endl;
	 }

	    return true; 
	}
}

int main()
{   
	int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    
    cout<<solveMaze(maze);
    return 0;
}