#include <bits/stdc++.h>
using namespace std;

// Array implimentation of stack
struct myStack{
	int *arr;
	int cap;
	int top;

	myStack(int c)
	{
		cap =c;
		arr =new int[cap];
		top=-1;  // no element in stack	
	} 

	void push(int x)
	{  // corner case , overflow
		if(top==cap-1)     //CC
		{
			cout<<"stackisfull";
			 return;
		}  

		top++;
		arr[top]=x;
	}
	int pop()
	{
		// under flow
		if(top==-1) 
		{
			cout<<"stack is empty";
			return -1;
		}

		int res =arr[top];
		top--;
		return res;
	}
	int peek()
	{
		// under flow
		if(top==-1) 
		{
			cout<<"stack is empty";
			return -1;
		}

		return arr[top];
	}

	int size()
	{
		return (top+1);
	}

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
	s.push(20);
	cout<<s.size()<<endl;
	cout<<s.peek()<<endl;
	cout<<s.pop()<<endl;
	s.push(35);
	cout<<s.peek()<<endl;
	cout<<s.isEmpty()<<endl;

return 0;
}