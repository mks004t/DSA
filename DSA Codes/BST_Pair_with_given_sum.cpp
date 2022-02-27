#include<bits/stdc++.h>
using namespace std;
//O(N) time comp and space comp
//it is also work for BT
bool isPairSum(Node *root,int sum, unordered_set<int> &s)
{
	if(root==NULL) return false;
	if(isPairSum(root->left,sum,s)==true) return true;
	if(s.find(sum-root->key)!=s.end())
		return true;            // if return the pair then, return root->key,sum-root->key 
	else
		s.insert(root->key);
	

	return isPairSum(root->right,sum,s);

}

// insertion and searching in hashtable(unoredered_set) is O(1) 