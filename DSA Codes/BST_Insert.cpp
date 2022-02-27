#include<bits/stdc++.h>
using namespace std;
// O(h) time and space comp

//Recursive
Node *insert(Node *root, int x)
{ 
	if(root==NULL)
		return new Node(x);
	else if(root->val>x)    // x is smaller than root so go to left
		root->left=insert(root->left,x);
	else if(root->val<x)
		root->right=insert(root->right,x);
    else
	    return root;

}

// note root->left= insert(...) is used to link the bst to new node

// Iterative

Node *insert(Node *root, int x)
{
	Node *temp=new Node(x);
	Node *parent=NULL, *curr=root;

	while(curr!=NULL)   //it is just a searching
	{
		parent=curr;
		if(curr->val>x)
			curr=curr->left;
		else if(curr->val<x)
			curr=curr->right;
		else
			return parent;
	}

	                 // Now insert x at its position
	if(parent==NULL)
		return temp;
	if(parent->val>x)
		parent->left=temp;
	else
		parent->right=temp;

	
	return root;

}