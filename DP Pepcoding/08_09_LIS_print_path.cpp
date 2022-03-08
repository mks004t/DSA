#include<bits/stdc++.h>
using namespace std;
//Longest increasing Subsequence(LIS)

struct Pair
{ //length,index,val;
	int l;
	int i;
	int val;
	string path;
	Pair(int ll,int ii,int Val,string Path)
	{
	   l=ll;
	   i=ii;
	   val=Val;
	   path=Path;
	}

};

int LIS(int arr[], int n)
{
	int lis[n];
	lis[0]=1;

//built LIS array	
	for(int i=1; i<n; i++)
	{
		lis[i]=1;
		for(int j=0; j<i; j++)
		   {                
		      if(arr[i] > arr[j])      
		    	lis[i]= max(lis[i], lis[j]+1); 
		   }
	}

//Find the max of LIS value	
	int result =lis[0];
	int pos=0;
	for(int i=1; i<n; i++)
		{
			if(lis[i]>=result)
			{
				result=lis[i];
				pos=i;
			}
		}

//_______________________Print Path___________________  
    
	Pair p={result,pos,arr[pos],to_string(arr[pos])+""};
	queue <Pair> Queue;

	Queue.push(p);

	while(Queue.size()>0)
	{
		Pair temp =Queue.front();
		Queue.pop();
		
		if(temp.l==1)
		{
			cout<<temp.path<<endl;
			continue;
		}

		for(int j=0;j<temp.i;j++)
		{
			if(lis[j]==temp.l-1 && arr[j]<=temp.val)  //length will be 1 less and val of that is also less
			   {  
			   	    Pair p1={ lis[j], j, arr[j], to_string(arr[j])+"->"+temp.path };
			   	    Queue.push(p1)	;
			   }
		}
	}

    return result;
}

int main()
{
	int arr[]={10,5,18,7,2,9};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<LIS(arr,n);
	return 0;
}