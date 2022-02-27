#include<bits/stdc++.h>
using namespace std;

//O(N) time comp and O(h) space comp

Node *LCA(Node *root,int n1,int n2)
{
	if(root==NULL) return NULL;
	if(root->left==n1 ||root->right==n2)
		return root;
	Node *lca1=LCA(root->left,n1,n2);
	Node *lca2=LCA(root->right,n1,n2);

	if(lca1!=NULL && lca2!=NULL)
	   return root;

	if(lca1!=NULL)
		return lca1;
	else
		return lca2;
}