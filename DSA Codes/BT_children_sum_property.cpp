#include<bits/stdc++.h>
using namespace std;

bool isCSum(Node *root)
{
	if(root == NULL) return True;
	if(root->left==NULL && root->right==NULL)
		rrturn true;

	int sun=0;
	if(root->left!=NULL) 
		sum+=root->left->key;
	if(root->right!=NULL)
		sum+=root->right->key;
	return (root->key ==sum &&  isCSum(root->left) && isCSum(root->right));

}


