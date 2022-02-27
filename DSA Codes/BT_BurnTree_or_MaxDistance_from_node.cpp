#include<bits/stdc++.h>
using namespace std;

int result=0;
int burnTime(Node* root,int leaf, int &dist)
{
	if(root==NULL) return 0;
	if(root->data==leaf)  {dist=0,  return 1;}
	
	int ldist=-1,rdist=-1;

	int lh =burnTime(root->left,leaf,ldist);
	int rh=burnTime(root->right,leaf,rdist);

	if(ldist!=-1)
	{
		dist=ldist+1;
		result=max(result,dist+rh);
	}
	else if(rdist!=-1)
	{
		dist=rdist+1;
		result=max(result,dist+lh);
	}

	return max(lh,rh)+1;
}