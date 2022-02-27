#include<bits/stdc++.h>
using namespace std;

int findMajEle(int arr[],int n)
{ int count=1,res=0;
 for(int i=1;i<n;i++)
 { if(arr[i-1]==arr[i])
 	   count++;
 	else
 		count--;

 	if(count==0)
 		{   res=i;
 			count=1;
         }

 }

count=0;
for(int i=0;i<n;i++)
  if(arr[i]==arr[res])
  	count++;
  cout<<"The Majority Element is ";
  if(count>=n/2)
  	return arr[res];
  else
  	return -1;
}


int main()
{ int arr[]={10,5,5,8,10,5,5,6,5};
	int n=9;

	cout<<findMajEle(arr,n);
	return 0;
}