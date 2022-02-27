#include<bits/stdc++.h>
using namespace std;
// This algo is work for BT and as well as BST
void verticalTraversal(Node *root)
{
	map<int,vector<int>> mp;
	queue<pair<Node *,int>> q;
	q.push({root,0});
	while(q.empty()==false)
	{
		auto p=q.front();
		Node *curr=p.first;
		int hd=p.second;
		mp[hd].push_back(curr->val);
		q.pop();
		if(curr->left!=NULL)
			q.push({curr->left,hd-1});
		if(curr->right!=NULL)
			q.push({curr->right,hd+1});
	}

   //print mp line by line
	for(auto x: mp)
	{
		vector<int> v=p.second;
		for(int x: v)
			cout<<x<<" ";
		cout<<endl;
	}

}