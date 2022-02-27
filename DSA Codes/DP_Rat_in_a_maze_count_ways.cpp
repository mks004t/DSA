#include<bits/stdc++.h>
using namespace std;
#define N 4

//DP solution
int countWaysDP(int maze[][N])
{ 
	int dp[N][N];
	for(int i=0;i<N;i++)
	{
		if(maze[N-1][i]==1)   dp[N-1][i]=1;
		else                dp[N-1][i]=0;

		if(maze[i][N-1]==1)   dp[i][N-1]=1;
		else                dp[i][N-1]=0;

	}
   
   for(int i=N-2; i>=0; i--)
   	for(int j=N-2; j>=0; j--)
   	{
   		if(maze[i][j]==1)
   		   dp[i][j] = dp[i+1][j] + dp[i][j+1];
   	    
   	    else
   	    	dp[i][j]=0;

   	}
   
//   	for(int i=0;i<N; i++)
//   	{  for(int j=0;j<N; j++)
//       { cout<<dp[i][j]<<" ";}
//        cout<<endl;
//   }
  
   
 return dp[0][0];
}

//Recursion
int countWays(int maze[][N],int i,int j)
{  	
	if(i==N-1 && j==N-1)
		return 1;
	if(maze[i][j]==1)
	{
		return countWays(maze,i+1,j)+countWays(maze,i,j+1);
	}

return 0;
	
}

//print the path
bool printPath(int maze[][N],int i,int j,vector<char> & path)
{  	
	if(i==N-1 && j==N-1)
	{ 
		return true;
	}
	if(maze[i][j]==1)
	{
		if(printPath(maze,i+1,j,path)) 
		 { path.push_back('D');
		    //path+='D';
		    return true ;
		} 
		 
		 if(printPath(maze,i,j+1,path))
			{
				path.push_back('L');
				// path+='L';
				 return true;
				}

	}

return false;
	
}


int main()
{   
	int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 1, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
/*   
   vector<char>path;
       printPath(maze,0,0,path);
  
    for(auto it=path.rbegin();it!=path.rend();it++)
   	    cout<<*it;
 */
     cout<<countWaysDP(maze);
   return 0;
}