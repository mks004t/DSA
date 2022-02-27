#include<bits/stdc++.h>
using namespace std;
// O(h) time and space comp

//this fun return the root if we delete any node having left and right leaf
//O(h) time comp and space comp

  Node *getSuccessor(Node *curr)  
  {
  	curr=curr->right;
  	while(curr!=NULL &&curr->left!=NULL)
  		curr=curr->left;
  	return curr;
  }
   

Node *deleteNode(Node *root,int x)
{
	if(root=NULL) return NULL;

	if(root->val>x)
		root->left=deleteNode(root->left,x);
	else if(root->val<x)
		root->right=deleteNode(root->right,x);
	else   //now we reached to the node to be deleted what to do next
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			delete root;
			return temp;
		}

		else if(root->right==NULL)
		{
			Node *temp=root->left;
			delete root;
			return temp;
		}

		else 
		{
			Node *succ=getSuccessor(root);
			root->val=succ->val;
			root->right=deleteNode(root->right, succ->val);

		}
		return root;

	}
}