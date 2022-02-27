#include <bits/stdc++.h>

using namespace std;

int main()
{ queue<int>q;
	/*q.push(10);
	q.push(20);
	q.push(30);
	cout<<q.front()<<" "<<q.back()<<endl;
	q.pop();
	cout<<q.front()<<" "<<q.back()<<endl;*/
queue<int> q2;
    q2.push(10);
	q2.push(20);
	q2.push(30);

while(q2.empty()==false)
{
	cout<<q2.front()<<" " <<q2.back()<<endl;
	cout<<"Size of queue ="<<q2.size()<<endl;
	q2.pop();
}

	return 0;
}