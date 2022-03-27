#include<bits/stdc++.h>
using namespace std;
struct Pair
{
	int index; //current Index
	string path;  //store the path so far
	int jumps;    //min jums to reach last from current index
};

   // DFS
void printPath(int arr[],int dp[],int n)
{
	queue<Pair> Queue;
	Pair p1 ={0,"0",dp[0]}; 
	Queue.push(p1);

	while(Queue.size()>0)
	{
		Pair temp=Queue.front();
		Queue.pop();

		if(temp.jumps == 0)
		{
			cout<<temp.path<<endl;
			continue;
		}
		for(int step=1; step<=arr[temp.index]; step++)
		{    if(temp.index+step<n && temp.jumps-1 == dp[temp.index+step])
				{
					string s1=temp.path+"->"+to_string((temp.index+step));

					Pair p2= {temp.index+step, s1, temp.jumps-1};

					Queue.push(p2);
				}
		}
	}		
}

// O(N*N) time comp & O(N) space // better solution in DSA CODE O(N)
int minJumps(int arr[],int n)
{   
	int dp[n];
	
	for(int i = 0; i < n; i++)
        dp[i] = INT_MAX;
	
	dp[n-1]=0;

	for(int i=n-2; i>=0; i--)
	{
		int steps=arr[i];
		int min=INT_MAX;

		for(int j=1; j<=steps && i+j<n; j++)
			if(dp[i+j]!=INT_MAX && dp[i+j]<min)
				min=dp[i+j];

		if(min!=INT_MAX)
			dp[i]=min+1;	
	}
    
    printPath(arr,dp,n);
	
	return dp[0];
}

int main()
{   int arr[]={ 3, 3, 0, 2, 1,2, 4, 2, 0, 0 };
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minJumps(arr,n);
	return 0;
}