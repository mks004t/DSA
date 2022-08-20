#include <bits/stdc++.h>
using namespace std;

// Nive method 
// divide the array into two half parts.

struct twoStacks{
	int *arr, cap,top1,top2;

	twoStacks(int n)
	{
		cap=n;
		top1=-1;
		top2=cap;
		arr=new int[n];
	}

	void push1(int x)
	{
		if(top1<top2-1)
		{
			top1++;
			arr[top1]=x;
		}
	}

	void push2(int x)
	{
		if(top1<top2-1)
		{
			top2--;
		    arr[top2]=x;
		}
	}

	int pop1()
	{
		if(top1>=0)
		{
			int x=arr[top1];
			top1--;
			return x;
		}

		else
		{	
			exit(1);  // return INT_MAX;
		}
	}

	int pop2()
	{
		if(top2<cap)
		{
			int x=arr[top2];
			top2++;
			return x;
		}
		else
		{
			return INT_MAX;
		}
	}

};


int main() 
{ 
    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2(); 
    return 0; 
}
