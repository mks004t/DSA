#include<bits/stdc++.h>
using namespace std;

struct Node
 {
 	int key ;
 	struct Node *left , *right;
 }; 

typedef struct btree Node;
int crt;
Node *btree[100];

node *newNode()
{
    int data ;
    cin>>data ;
	Node* temp = new Node;
	temp->data=data ;
	temp->left=temp->right=NULL;
    return temp;
}



void createBtree()
{
	int i=0,j;
	cout<<"How many nodes you want"<<endl;
	cin>>crt;
    btree[0]=newNode();
    j=ctr;

    while(j)
    {
    	if(j>0)
    	{
    		btree[i*2+1]=newNode();
    		btree[i]->left=btree[i*2+1];
    		j--;

    	}

    	if(j>0)
    	{
    		btree[i*2+2]=newNode();
    		btree[i]->right=btree[i*2+2];
    		j--;

    	}

    	i++;
    }
}





void inOrder( struct Node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<(root->key)<<" ";
		inOrder(root->right);
	}
}

void postOrder(struct Node *root)
{
	if(root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<(root->key)<<" ";
	}
}

void preOrder(struct Node *root)
{ 
	if (root!=NULL)
	{
		cout<<(root->key)<<" ";
		preOrder(root->left);
		preOrder(root->right);

	}

}

void printlevel(Node *root)
{
	if(root==NULL) return ;
	queue<Node *> q;
	q.push(root);
	while(q.empty()==false)
	{
		Node *curr=q.front();
		q.pop();
		cout<<(curr->key)<<" ";
		if(curr->left!==NULL)
			  q.push(curr->left);
		if(curr->key!==NULL)
			q.push(curr->right);
		
	}
}

void height(node *root)
{
	if(root==NULL) return 0;
	else
	{
		return 1+max(height(root->left), height(root->right));
	}
}

void heightDFS(node *root)
{
	int height=0;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{  Node *curr=q.frunt();
		q.pop();

		if(curr==NULL)
			height++;
		else
		   {

		    if((root->left)!=NULL) q.push(root->left);
		    if((root->right)!=NULL) q.push(root->right);
         }
		q.push(NULL);

	}
}


int main()
{  createBtree();
   cout<<"Inorder"<<inOrder(btree[0])<<endl;
   cout<<"Postorder"<<postOrder(btree[0])<<endl;
   cout<<"Preorder"<<preOrder(btree[0])<<endl;

	return 0;
}