#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n)
{
	stack<int> s;
	int res=0;
	int tp;     //  temp index, which is larger and removed from stack;
	int curr;   // it store the curr area.

	for(int i=0; i<n; i++)
	{
		while(s.empty()==false && arr[s.top()]>=arr[i])
		{
			tp=s.top();
			s.pop();

			curr= arr[tp]* (s.empty() ? i : (i-s.top()-1) );
			res=max(res, curr);
		}
		s.push(i);
	}

	// now we are remain with elements whose next smaler doesnot exist
	while(s.empty()==false)
	{
		tp=s.top();
		s.pop();

		curr=arr[tp]* (s.empty() ? n : n-s.top()-1);
		res=max(res,curr);
	}
	
	return res;
}

int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}