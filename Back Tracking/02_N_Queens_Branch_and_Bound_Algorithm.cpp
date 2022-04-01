#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<bool>> & board,int row,vector<bool> cols,vector<bool> d1,vector<bool> d2,string ans)
{
	int n=board[0].size();
	int m=board.size();

	if(row==m)
	{   cout<<ans<<endl;
	     return;
	}
	for(int col=0; col<n; col++ )
	{
		if(cols[col]==false && d1[row+col]==false && d2[row-col+m-1] ==false)
			{
				board[row][col]=true;
				cols[col]=true;
				d1[row+col]=true;
				d2[row-col+m-1]=true;
				
				solve(board,row+1,cols,d1,d2,ans+to_string(row)+" - "+to_string(col)+" , ");
				board[row][col]=false;
				cols[col]=false;
				d1[row+col]=false;
				d2[row-col+m-1]=false;
			}
	}
}


int main()
{
	int n=4;
	vector<vector<bool>> board(n,vector<bool>(n));

	vector<bool> cols(n);
	vector<bool> d1(2*n-1);  //
	vector<bool> d2(2*n-1);
    
    solve(board,0,cols,d1,d2,"");

	return 0;
}