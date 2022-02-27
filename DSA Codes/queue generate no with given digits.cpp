#include <bits/stdc++.h>

using namespace std;
int main()
{  queue<string>q;

	int n;
	cin>>n;
	q.push("5");
	q.push("6");
	for(int i=0; i<n; i++)
	{
		string curr = q.front();  // initilizing "curr to top of queue"  
		cout<<curr<<" ";
		
		q.pop();  // pop out the first element

		// add 5, 6 to allthe current element (curr =5 , new no are 55,56)
		q.push(curr+"5");
		q.push(curr+"6");


	}


	return 0;
}