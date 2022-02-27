#include<bits/stdc++.h>
using namespace std;
//0(N) time
//O(h) space

void iterativePreorder(Node *root)
{
	stack<Node *>s;
	Node *curr=root;
	while(s.empty()==false||curr!=NULL)
	{
		while(curr!=NULL) // it just say got to left left left and push right of every left
		{
			cout<<curr->val<<" ";      //print root or left
			if(!curr->right)
				s.push(curr->right);   //if right isnot NULL push right
			
			curr=curr->left;           //go left        
		}
		if(s.empty()==false)    //if stack is not empty now process right elements 
		{
			curr=s.top();       // curr=top
			s.pop();            //pop top item from stack
		}
	}


}