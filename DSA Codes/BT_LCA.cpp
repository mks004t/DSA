#include<bits/stdc++.h>
using namespace std;
// LCA: Lowest Common ansister.
// Nive solution: Just store the path from root to the given Node
// then compair both with each other ,the result will be the last common element .

bool findPath(Node *root,vector<Node*> &p, int n)
{
	if(root==NULL) return false;

	p.push_back(root);  // push the element into the vector

	if(root->key==n)
		return true;
// call for left and right subtree
	if(findPath(root->left,p,n) || findPath(root->right,p,n))
		  return true;

// if we reach to wrong path it pop out the element
	p.pop_back();

	return false;
}

Node* LCA(Node *root,int n1,int n2)
{
	vector<Node*>path1,path2;

	if(findPath(root,path1,n1)==false ||
		findPath(root,path2,n2)==false)
		return NULL;
   // Now find the last common element 
   for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
   {
   		if(path[i+1]!=path2[i+1])
   			return path1[i];
   }
   return NULL;
}


//O(N) time comp and O(h) space comp
// our assumption is that both the keys are present in  tree.
// otherwise the function will return wrong result.
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