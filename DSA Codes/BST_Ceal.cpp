#include<bits/stdc++.h>
using namespace std;
//O(h) time comp

Node *ceil(Node *root,int x)
{   Node *result=NULL;
	while(root!=NULL)
	{
		if(root==x)
			return root;
		else if(root->left>x)
		{
			result=root;
			root=root->left;
		}
		else
			root=root->right;
	}


	return result;
}
