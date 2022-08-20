#include<bits/stdc++.h>
using namespace std;
/* convert Binary tree to Doubly linked list
Without using extra space
inorder triversal space complexity is 0(h)
O(n)
*/ 
Node *prev=NULL;

Node *BTtoDLL(Node *root)
{
	if(root==NULL) return root;

	Node *head=BTtoDLL(root->left);
	if(prev==NULL) head=root;

	else
	{
		root->left=prev;  // backword pointer /linking
		prev->right=root; //forword linking
	}

	prev=root;
	BTtoDLL(root->right);
	
	return head;
}
