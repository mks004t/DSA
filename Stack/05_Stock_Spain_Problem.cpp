#include<bits/stdc++.h>
using namespace std;

// same as "nearest greater to left" but save index;
// print consicutive smaller or equal before it (consicutive)
void stockSpain(int arr[],int n)
{
	stack<pair<int,int>> s;
	int ans[n];

	for(int i=0; i<n; i++)
	{
		if(s.empty())
			ans[i] = 1 + i;   // here 1 bec we can hold that stock for 1 day
        
        else if(s.size()>0 && s.top().first > arr[i])
        	ans[i] = i - s.top().second;

        else
        {
        	while(s.size()>0 && s.top().first <= arr[i])
        		s.pop();

        	if(s.empty())
        		ans[i] = 1 + i;
        	
        	else
        		ans[i] = i - s.top().second;
        }

        s.push(make_pair(arr[i],i));
     }

     for(int i=0; i<n; i++)
     	cout<<ans[i]<<" ";
}

int main()
{
	int arr[]={15,13,12,14,16,8,6,4,10,30};  
	int n=sizeof(arr)/sizeof(arr[0]);
	
	stockSpain(arr,n);
	return 0;
}

// I/P : { 10, 4, 5, 90, 120, 80 }
// O/P :   1   1  2   4   5   1 