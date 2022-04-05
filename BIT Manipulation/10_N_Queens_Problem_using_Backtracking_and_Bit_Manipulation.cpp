#include<bits/stdc++.h>
using namespace std;

void solve (vector<vector<bool>> board,int row,int cols,int nd,int rd,string ans)
{
	int n=board.size();
    if(row == n)
    {
        cout<<ans<<endl;
        return;
    }
    
	for(int col =0; col<n; col++)
	{
		if ( ((cols & (1 << col)) ==0) &&
			 ((nd & (1 << (row + col))) ==0) &&
			 ((rd & (1 << (row - col + n - 1))) ==0)
		   )
		{            // mark true
			board[row][col]=true;
                      // togle the bits i.e on the bits of that position
			cols ^= (1 << col);
			nd ^= (1 << (row + col));
			rd ^= (1 << (row - col + n - 1));

			solve(board,row+1,cols,nd,rd,ans+to_string(row)+"-"+to_string(col)+",");
			         // undo every thing
			board[row][col]=false;
			cols ^= (1 << col);
			nd ^= (1 << (row + col));
			rd ^= (1 << (row - col + n - 1));
		}
	}
}

int main()
{	
	int n=4;
	vector<vector<bool>> board(n,vector<bool>(n,0));
	int cols=0;
	int ndiagonal=0;
	int rdiagonal=0;
	solve(board,0,cols,ndiagonal,rdiagonal,"");

	return 0;
}