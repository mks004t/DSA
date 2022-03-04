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

 void printLinkedList(Node * head)
 {
 	if(head==NULL)
 		return;
 	else
 	{  Node *curr=head;
 		while(curr!=NULL)
 		{
 			cout<<curr->data<<" ";
 			curr=curr->next;
 		}
 	}
 	cout<<endl;
 }
// find the middle node if even then 2nd one 
int find_middle(Node *head)
{
	
	if(head==NULL)
		return -1;
	Node *slow=head,*fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
    int middle= slow->data;
	return middle;
}

Node *insert_middle(Node *head,int data)
{
	Node *temp=new Node(data);
	if(head==NULL)
		return temp;
	Node *slow=head,*fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	//slow the middle element
	temp->next=slow->next;
	slow->next=temp;

	return head;
}



int main()
{   Node *head = new Node(10);
	head -> next = new Node(20);
	head -> next ->next = new Node(30);
	head -> next ->next ->next = new Node(40);
	head -> next ->next ->next ->next = new Node(50);
    printLinkedList(head);
   

   head=insert_middle(head,-100);
   printLinkedList(head);

   cout<<find_middle(head);
  
	return 0;
}