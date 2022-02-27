#include<bits/stdc++.h>
using namespace std;
//O(h) time comp
Node *floor(Node *root,int x)
{
	if(root==NULL) return 0;
	Node *result=NULL;
	while(root!=NULL)
	{
		if(root->val==x)
			return root;
		
		else if(root->val>x )
			root=root->left;
		
		else 
		{   reslut=root;     // bec floor is always equal or less then given number
			root=root->right;
		}
  
	}

	return result;
}