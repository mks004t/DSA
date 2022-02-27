#include<bits/stdc++.h>
using namespace std;
//0(N) time
//O(N) space
void iterativeInorder(Node *root)
{
	stack<Node *>s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{  
		while(curr!=NULL)
           {  s.push(curr);
              curr=curr->left;
           }
        curr=s.top();
        s.pop();

        cout<<curr->val<<"  ";
        curr=curr->right;

	}

}