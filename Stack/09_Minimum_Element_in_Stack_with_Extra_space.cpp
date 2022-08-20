#include<bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss; 

// get min in O(1)

void push(int a)
{
	s.push(a);
	if(ss.size()==0 || ss.top()>=a)
		ss.push(a);
}

int pop()
{
	if(s.size()==0)
		return -1;

	int ans= s.top();
	s.pop();

	if(ss.top()==ans)
		ss.pop();

	return ans;
}

int getMin()
{
	if(ss.empty())
		return -1;
	return ss.top();
}

int main()
{
    push(10);
    push(20);
    push(30);
    cout << getMin() << endl;
    push(5);
    cout << getMin();
    return 0;
}