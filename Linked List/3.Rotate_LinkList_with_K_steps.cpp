#include<bits/stdc++.h>
using namespace std;

/*  Rotate a Linked List
  
    |10->20->30->40|->50->60
    k=4           
				  
    50->60->|10->20->30->40|

*/

struct Node
{
    int data ;
    Node* next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

Node *rotateLL(Node *head ,int k)
{
	if(head==NULL)
		return head;

	Node *curr =head;

	int  count=1;

	while(count<k && curr!=NULL)
	{
		curr=curr->next;
		count++;
	}

	if(curr==NULL)    // K= size of LL so the rotated LL is same as old
		return head;

	Node *KthNode = curr;

	while(curr->next!=NULL)
	{
		curr=curr->next;
	}

	curr->next=head;

	head=KthNode->next;  //new head is kth next element

	KthNode->next=NULL;

	return head;
} 