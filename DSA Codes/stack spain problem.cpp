#include <bits/stdc++.h>

using namespace std;

int main()
{ int arr[]={15,13,12,14,16,8,6,4,10,30};
  int size=sizeof(arr)/sizeof(arr[0]);

   stack<int> s;
	s.push(0);
	for(int i=1;i<size;i++)
	{
		while(s.empty()==false && arr[s.top()]<=arr[i] )   //if a bigger no come we have to remove all elementes of stack 
			s.pop();
		
		int span =(s.empty())?(i+1):(i-s.top());  // if stack is empty spain is "i+1" else "i-position of bigger no"
		cout<<span<<" ";

		s.push(i);

	}




	return 0;
}