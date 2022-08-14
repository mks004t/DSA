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

/*  //Nive Method , need to the swap data value

   if the data is large then it is very complex.
-->   thus best method is to swap pointers.

Input: 10-> 21-> 30-> 41-> 50-> 61-> 70-> 81-> 90->
Output:21-> 10-> 41-> 30-> 61-> 50-> 81-> 70-> 90->

*/
//Nive Method    O(N) need to the swap data value
void swapPairWise(Node * head)
{
	Node *curr = head;
	while(curr!=NULL && curr->next!=NULL)
	{
		swap(curr->data, curr->next->data);
		curr=curr->next->next;
	}
}

// Methd 2 , O(N) Changing Pointers

Node *pairWiseSwap(Node *head)
{
	// first swap first 2 nodes

	if(head==NULL || head->next==NULL)
		return head;
	Node *curr =head->next->next;  // 3rd element, Move 2 elements 
	Node *prev =head;

	head=head->next;
	head->next=prev;

	while(curr!=NULL && curr->next!=NULL)
	{
		// move next
		prev->next=curr->next;
		prev =curr;

		// join nodes
		Node *Next =curr->next->next;
		curr->next->next= curr;
		curr=Next;
	}
	
	prev->next=curr;
	
	return head;
}
