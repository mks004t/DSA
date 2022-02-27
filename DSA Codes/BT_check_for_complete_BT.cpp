#include<bits/stdc++.h>
using namespace std;
// O(h) best case
//O(log(n)*log(n))
int countNode(Node *Node)
{
	int lh=0,rh=0;
	Node *curr=root;
	while(curr!=NULL)
	{
		lh++;
		curr=curr->left;
	}
	curr=root;
	while(curr!=NULL)
	{
		rh++;
		curr=curr->right;
	}

	if(lh==rh)
	{
		return pow(2,lh)-1;
	}

	return 1+countNode(root->left)+countNode(root->right);
}