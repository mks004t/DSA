#include<bits/stdc++.h>
using namespace std;
// O(h) time and space comp

// Recursive solution
bool searchBST(Node *root, int x)
{
	if(root==NULL) return 0;

	else if(root->val==x) return 1;

	else if(x<root->val) 
		searchBST(root->left,x);
	else               // (x>root->val)
		 searchBST(root->right,x);

}


//iterative

bool searchBST(Node *root ,int x)
{
	if(root==NULL) return 0;
	while(root!=NULL)
	{
		if(root->val==x)
			return true;
		else if(root->val<x)
			searchBST(root->left);
		else
			searchBST(root->right);
	}

	return false;
}

