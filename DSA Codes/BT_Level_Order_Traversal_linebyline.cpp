#include<bits/stdc++.h>
using namespace std;


void printLevelOrderLine(Node *root)
{
	if(root==NULL) return ;
	queue<Node *>q;
	q.push(root);
	q.push(NULL);

	while(q.size()>1)
	{
		node *curr=q.front();
		q.pop();
		if(curr==NULL)
		{
			cout<<" \n";
			q.push(NULL);
			continue;

	}


		cout<<(curr-> key)<<" ";

		
		if(curr->left!==NULL)
			 q.push(curr->left);
		if(curr->right!=NULL)
		     q.push(curr->right);


	}
}