#include<bits/stdc++.h>
using namespace std;
#define N 4

bool isSafe(int Queen[][N], int row, int column )
{
	//Same Row   //No need for same Column bec we already checked for it.
	for(int i=0; i<column; i++)
		if(Queen[row][i])
			return false;
	
	// Upper Diagonal
	
	for(int i=row,j=column; i>=0 && j>=0; i--,j--)
	      if(Queen[i][j])
				return false;

	//Lower diagonal
	
	for(int i=row,j=column ; i<N && j>=0; i++,j--)
          if(Queen[i][j])
              	false;
    
    return true;
}


bool solveRec(int Queen[][N], int column)
{
	if(column==N) return true;

	for(int i=0; i<N; i++)
	{
		if(isSafe(Queen,i,column))
		{   
			Queen[i][column]=1;

			if(solveRec(Queen, column+1))
				return true;

			Queen[i][column]=0;
		}	
	}
	return false;
}

bool solve()
{   int Queen[N][N];
	
	for(int i=0; i<N; i++)
	  	 for(int j=0; j<N; j++)
	  	 	Queen[i][j]=0;


	if(solveRec(Queen,0)==false)
	 return false;

	else
	  {  for(int i=0; i<N; i++)
	  	 {  for(int j=0; j<N; j++)
	  	   {	cout<<Queen[i][j]<<" ";  }
	         cout<<endl;
	     }

	  	return true;
	  }
}


int main()
{
	cout<<solve();
	return 0;
}