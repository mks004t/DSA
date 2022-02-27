#include<bits/stdc++.h>
using namespace std;
//O(N)
int height(Node *root)
{
	if(root==NULL) return 0;
	else
		return 1+max(height(Node->left),height(Node->right));
}

//the given below two solution are for diameter of binary tree

//O(N*N)
int diameterBT(Node *root)
{
	if(root==NULL) return 0;
    
    int d1=1+max(height(Node->left),height(Node->right));

    int d2=diameterBT(root->left);
    int d3=diameterBT(root->right);
    return max(d1,max(d2,d3));

	
}

//O(N)
int result=0;
int diameter(Node *root)
{
	if(root==NULL) return 0;

	int lh= diameter(root->left);   //it is just a height of left sub tree
	int rh= diameter(root->right);  //  ;; right

	result=max(result,lh+rh) ;   //it is the diameter
	return 1+max(lh,rh);
}