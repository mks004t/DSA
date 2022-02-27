#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int x)
	{
		data =x;
		next=NULL;
	}
};

void printLinkedList(Node *head)
{
	Node *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}

Node *insertPos(Node *head, int pos,int data)
{
	Node *temp= new Node(data);
	if(pos==1)
	{
		temp->next=head;
		return temp;
	}
	Node *curr=head;
	for(int i=1; i<=pos-2 && curr!=NULL; i++)
		curr=curr->next;

	if(curr==NULL)  //handle if pos > then size of linked list
		return head;

	temp->next=curr->next;
	curr->next=temp;

	return head;
}

Node *deletePos(Node *head,int data)
{
	Node *curr=head; 
	
	if(curr==NULL)    //if head == Null
		return head;
	
	if(curr->data==data)   // delete first element
	{  Node *temp=curr->next;
		delete curr;
		return temp;
	}
 
    Node *prev;

	while(curr!=NULL && curr->data!=data)  
	{   prev=curr;
		curr=curr->next;
	}
   
   if(curr==NULL)  //no element found
   	return head;

  prev->next=curr->next;  // delete any element
  delete (curr);
  
  return head;
}
int main()
{ 
	Node *head = new Node(10);
	head -> next = new Node(20);
	head -> next ->next = new Node(30);
	head -> next ->next ->next = new Node(40);
	head -> next ->next ->next ->next = new Node(50);
    printLinkedList(head);

// Insert at any position Singly LL	
	head=insertPos(head,3,300);  //3:position,300 value
	printLinkedList(head);

// delete X=50 from the LL
	head=deletePos(head,50);
	printLinkedList(head);
	return 0;
}