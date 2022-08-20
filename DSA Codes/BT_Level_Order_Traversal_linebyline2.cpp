#include<bits/stdc++.h>
using namespace std;


//method 2
void printLevelOrderLine(Node *root)
{
	if(root==NULL) return ;
	queue<Node *>q;
	q.push(root);

	while(q.empty()==false)
	{
		int count= q.size();

		for(int i=0; i<count; i++)
		{
			Node *curr=q.front();
			q.pop();
			cout<<curr->key<<" ";

			if(curr->left!==NULL)
		        q.push(curr->left);
	        if(curr->right!=NULL)
	            q.push(curr->right);
		}
		cout<<endl;
	}
}