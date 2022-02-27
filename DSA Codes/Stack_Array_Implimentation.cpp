#include<bits/stdc++.h>
using namespace std;

struct myStack
{
	  int * arr;
	  int cap;
	  int top;
	  
	  myStack(int n)
	  {
	  	cap=n;
	  	arr=new int [cap];
	  	top=-1;
	  }
//
	  void push(int x)
	  {
	     if(top==cap-1) 
	  	  {
	  	  	 cout<<"Stack FULL"<<endl;
	  	     return;
	  	  }

	  	top++;
	  	arr[top]=x;
	  }
//
	  int pop()
	  { 
	  	 if(top==-1)
	  	 {   cout<<"The Stack is empty"<<endl;
	  		 return INT_MAX;
	     }

	  	int res=arr[top];
	  	top--;
	  	return res;
	  }
//
	  int peek()
	  {   
	  	if(top==-1)
	      {	cout<<"The Stack is empty"<<endl;
	      	return INT_MAX;
	      }
	  	  
	  	  return arr[top];
	  }
//
	  int size()
	  {
	  	return top+1;
	  }
//
	  bool isEmpty()
	  {
	  	return (top==-1);
	  }
};


int main()
{
	myStack s(10);
	s.push(5);
	s.push(15);
	s.push(25);
	cout<<s.size()<<endl;
	cout<<s.peek()<<endl;
	s.push(35);
	cout<<s.peek()<<endl;

	return 0;
}