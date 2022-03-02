#include<bits/stdc++.h>
using namespace std;

struct Pair
{ //length,index,val;
	int sum;
	int i;
	int val;
	string path;
};

int LIS(int arr[],int n)
{
	int dp[n];
	dp[0]=arr[0];

	for(int i=1;i<n;i++)
	{	
		dp[i]=arr[i];
		for( int j=0;j<i;j++)
		{   
			if(arr[i] > arr[j])
				dp[i]=max(dp[i], dp[j]+arr[i]);
		}
	}
  
int ans=dp[0];
int pos=0;
  for(int i=1;i<n;i++)
  { 
  	if(dp[i]>ans)
  	{
  		ans=dp[i];
  		pos=i;
  	}
  }
//__________________Print_Path___________________

	Pair p={ans-arr[pos],pos,arr[pos],to_string(arr[pos])+""};
	queue <Pair> Queue;

	Queue.push(p);

	while(Queue.size()>0)
	{
		Pair temp =Queue.front();
		Queue.pop();
		
		if(temp.sum==0)
		{
			cout<<temp.path<<endl;
			continue;
		}

		for(int j=0;j<temp.i;j++)
		{
			if(dp[j]==temp.sum && arr[j]<=temp.val)  //length will be 1 less and val of that is also less
			   {  
			   	    Pair p1={ temp.sum-arr[j], j, arr[j], to_string(arr[j])+"->"+temp.path };
			   	    Queue.push(p1)	;
			   }
		}
	}

	return ans;
}

int main()
{
	int arr[]={10,5,18,7,2,9};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}