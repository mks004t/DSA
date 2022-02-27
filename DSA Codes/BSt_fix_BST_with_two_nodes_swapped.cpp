#include<bits/stdc++.h>
using namespace std;

//Fix a BST with two Nodes Swaped


//Array 
void fixSort(int arr[],int n)
{
	int prev=INT_MIN;
	int first=NULL;
	int second=NULL;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<prev)
		{
			if(first==NULL)
			   first=prev;

			second=arr[i];
			
		}
		second=arr[i];
	}


//BST
Node *prev=NULL,*first=NULL,*second=NULL;

void fixBST(Node *root)
{
	if(root=NULL) return;
	fixBST(root->left);
	if(prev!=NULL && root->key<Prev->key)
	{
		if(first==NULL)
			first=prev;
		second=root;
	}

	prev=root;
	fixBST(root->right);

} 