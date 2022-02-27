#include<bits/stdc++.h>
using namespace std;

/* Function to check wheather the binary tree is balanced or not.
if not balanced return -1
if balanced return height
O(n) time complexity
*/
int isBalanced(Node *root)
{  
	if(root==NULL) return 0;

	int lh= isBalanced(root->left);
	if(lh==-1) return -1;

    int rh= isBalanced(root->right);
    if(rh==-1) return -1;

    if(abs(rh-lh)>1) return -1;
    else
       return max(lh,rh)+1; 

}