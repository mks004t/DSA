#include <bits/stdc++.h>

using namespace std;

int main()
{
/*	deque<int>dq={10,20,30};
	dq.push_front(5);
	dq.push_back(50);
	for(auto x:dq)
		cout<<x<<" ";
*/

deque<int>dq={10,15,30,5,12};
auto it =dq.begin();      // it point to 10
it++;                     // it increment to +1 and point to 15
dq.insert(it,20);
for(auto x: dq)
   cout<<x<<" ";
cout<<endl;
dq.pop_front();           // remove the first element
dq.pop_back();            // remove the last element
cout<<dq.size()<<endl;
for(auto x: dq)
   cout<<x<<" ";

	return 0;
}