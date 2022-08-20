#include<bits/stdc++.h>
using namespace std;

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

/*
   Nive method use stack.
   Traverse through LL and put element in stack.
   Now traverse again through LL and match elements with stack one by one 

*/

Node *reverseLL(Node *head)
{
	if(head!=NULL)
		return head;
	Node *prev=NULL;
	Node *curr =head;
    
    while(curr!=NULL)
    {
    	Node *next=curr->next;
    	curr->next=prev;
    	prev=curr;
    	curr=next;
    }
   return prev;
}

bool isPalindrome(Node *head)
{
	if(head==NULL)
		return true;

	Node *slow =head,*fast=head;
	
	//find mid element.
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	Node *rev= reverseLL(slow->next);
	Node *curr=head;
	while(rev!=NULL)
	{
		if(rev->data!=curr->data)
			return false;
		
		rev =rev->next;
		curr=curr->next;
	} 
  return true;
}