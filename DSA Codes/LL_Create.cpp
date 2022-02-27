#include<bits/stdc++.h>
using namespace std;
/*
1: Create LL
2: print LL
3: Insert at the begin
4: Insert at the end
5: Delete from the begin
6: Delete from the end
*/
struct Node
{
	int data;
	Node *next;
	Node (int x)
	{
		data=x;
		next= NULL;
	}
};

//print linked list.
void printLinkedList( Node * head )
{
	Node *curr= head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

//Insert At the Beginning of LL
Node * insert_in_begin(Node *head,int n)
{
	Node * temp= new Node(n);
	temp->next=head;
	return temp;

}

//Insert At the end of LL
Node *insert_at_end(Node * head ,int n)
{
	Node *temp =new Node(n);

	if(head ==NULL)
      return temp;
    Node *curr =head;
    while(curr->next!=NULL)
     {
     	curr=curr->next;
     } 	
     curr->next=temp;
     return head;
}

 // Delete First Node in Singly LL
Node * delHead(Node *head)
{
	if(head==NULL)
		return NULL;
	else
	{
		Node* temp=head->next;
		delete head;
		return temp;
	}
} 

// Delete last Node in Singhly LL
Node * delLast(Node * head)
{
	if(head==NULL)
		return NULL;
	else if(head->next==NULL)
	{
		delete head;
		return NULL;	
	}
	 
	Node *curr =head;
		while(curr->next->next!=NULL)
		{
			curr=curr->next;
		}
		delete (curr->next);
		curr->next=NULL;
		return head;
}


int main()
{ // create linked list
	Node *head = new Node(10);
	head -> next = new Node(20);
	head -> next ->next = new Node(30);
 
 //print linked list.
	printLinkedList(head);
 
 //insert at begin 
	head=insert_in_begin(head,5);
    printLinkedList(head);
 
 //insert at the end
    head=insert_at_end(head,100);
    printLinkedList(head);

 // Delete First Node in Singly LL;
    head= delHead(head);
    printLinkedList(head);
 
 // Delete Last Node in Singly LL;
    head= delLast(head);
    printLinkedList(head);
	return 0;
}