#include<bits/stdc++.h>
using namespace std;
//O(n)
const  int empty=-1;
int index=0;
Node *constructTree(vector<int > & arr)
{  if(index==arr.size()) return null;

	int val=arr[index];
	index++
	if(val==empty) return null;

	Node *root= new Node(val);
	root->left=constructTree(arr);
	root->right=constructTree(arr);


	return root;
}  