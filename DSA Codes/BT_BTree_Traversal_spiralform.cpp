#include<bits/stdc++.h>
using namespace std;

Node *printBTspiral(Node *root)
{
	stack<Node *>s1;
	stack<Node *>s2;

	if(root==NULL) return ;
    
    s1.push(root);
    while(s1.size()!=NULL || s2.size()!=NULL)
    {
    	Node* curr =s1.top();
    	while(s1.size!=NULL)
    	{  
    		Node* curr =s1.top();
    		s1.pop();
    		cout<<curr->key<<" ";
    		if(curr->left!=NULL)  s2.push(curr->left);
    		if(curr->right!=NULL) s2.push(curr->right);
    	}

    	while(s2.size()!=NULL)
    	{
    		Node* curr =s2.top();
    		s2.pop();
    		cout<<curr->key<<" ";
    		if(curr->right!=NULL) s1.push(curr->right);
    		if(curr->left!=NULL)  s1.push(curr->left);
    	}
    }
}