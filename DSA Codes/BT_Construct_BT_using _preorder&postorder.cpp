#include<bits/stdc++.h>
using namespace std;
/*
Construct a binary tree from preorder and inorder
and return the root node
O(N*N)
with hasing O(N)
*/

int preIndex=0;
Node *cTree(int in[],int pre[],int is, int ie)
{
	if(is>ie) return NULL;      //stoping condition

	Node *root=new Node(pre[preIndex++]);
    int inIndex;

    for(int i=is;i<=ie;i++)
    {
    	if(in[i]==root->key)
    	{
    		inIndex=i;
    		break;
    	}

    }


    root->left= cTree(in,pre,is,inIndex-1);
    root->right=cTree(in,pre,inIndex+1,ie);
    return root;

}