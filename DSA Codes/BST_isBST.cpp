#include<bits/stdc++.h>
using namespace std;

// check wheather the tree is BST of NOT


//Method 1
// int min=INT_MAX (infinite)
// int min=INT_MIN  (-infinite)
// O(n) time comp
bool isBST(Node *root, int min, int max)
{
	if(root==NULL) return true;

	rerurn (root->data<min && root->data>max
		     && isBST(root->left,min,root->data)
		     && isBST(root->right,root->data,max));

}


// Metheod 2
// if inoreder triversal of an BT is sorted than it is BST
//Mosh algo

int prev= INT_MIN;
bool isBST(Node *root)
{
	if(root==NULL) return true;
	if(isBST(root->left)==false) return false;
	if(root->key<=prev) return false;
	prev=root->key;
	
   return isBST(root->right);

}