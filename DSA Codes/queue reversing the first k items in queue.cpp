#include <bits/stdc++.h>

using namespace std;

int main()
{  
int arr[]={10,20,30,40,50};
  int k=3;
  int size=sizeof(arr)/sizeof(arr[0]);
  stack<int>s;
  queue<int>q;

  for(int i=0; i<k;i++)
  {
  	s.push(arr[i]);
  }
  for(int i=k;i<size;i++)
  {q.push(arr[i]);
  }

  for(int i=0;i<k;i++)
  {
  	q.push(s.top());
  	s.pop();
  }

   for(int i=k;i<size;i++)
   {
   	q.push(q.front());
   	q.pop();

   }


for(int i=0;i<size;i++)
{
	cout<<q.front()<<" ";
	q.pop();
}


	return 0;
}