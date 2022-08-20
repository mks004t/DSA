#include<bits/stdc++.h>
using namespace std;
//print top view of BT or BST
void printTopView(Node *root)
{
	unoreder_map<int,int> mp;
	queue<pair<*Node,int>>q;
	q.push({root,0});
	while(q.empty()!=false)
	{
		auto p=q.front();
		Node *curr=p.first;
		int hd=p.second;
		if(mp.count(hd)=0)     // for bottom view no need to write this if condition,  so the value changed to bottom
			mp[hd]=root->val;
		if(curr->left!=false)
			q.push(curr->left,hd-1);
		if(curr->right!=false)
			q.push(curr->right,hd+1);
		q.pop();


       //print top view
      for(auto x :mp)
      	cout<<x.second<<endl;

	}
}