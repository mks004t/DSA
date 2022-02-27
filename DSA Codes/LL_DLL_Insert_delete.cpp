#include<bits/stdc++.h>
using namespace std;

// Doubly Linked List

struct Node
{
	int data;
	Node* prev;
	Node* next;
	Node(int x)
	{
		data =x;
		next=NULL;
		prev=NULL;
	}
};

//Print DLL
void printDLL(Node *head)
{
	if(head==NULL)
		return ;
   Node *curr= head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}

	cout<<endl;
}

//Insert at the begin
Node *insert_begin(Node *head,int data)
{ Node *temp=new Node(data);
	if(head==NULL)
		return temp;
	temp->next=head;
	head->prev=temp;

	return temp;
}

//Insert at the end
Node *insert_end(Node *head,int data)
{
	Node *temp =new Node(data);
	if(head==NULL)
		return temp;

	Node *curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=temp;
	temp->prev=curr;

 return head;
}

//Insert at any position x
Node *insert_at(Node *head,int pos,int data)
{ Node *temp=new Node(data);
	 
	 if(head==NULL)
		return temp;

	 if(pos==1) //insert at begin
	 {
	 	temp->next=head;
	 	head->prev=temp;
	 	return temp;
	 }

	 Node *curr=head;
	 for(int i=1;i<pos;i++)
	 {
	 	curr=curr->next;
	 }
	
	 if(curr==NULL)  //Position out of range
	 	 return head;

	 if(curr->next==NULL)
	 {
	 	   curr->next=temp;
	     temp->prev=curr;

      return head;
	 }
	 
	 temp->next=curr->next;      //   [temp]-->
	 temp->next->prev=temp;     //    [temp]<--
	 												   //     [temp] <==> (left comp)
	 curr->next=temp;         //  -->[temp]
	 temp->prev=curr;        //  <--[temp]
                          //  <==>[temp]<==>  (right and left both comp)
	 
	return head;
}

//Delete from begin
Node *delete_begin(Node *head)
{
	if(head==NULL)
		return NULL;

	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *curr = head->next;
	delete head;
	curr->prev=NULL;

return curr;
}

// Delete from the end
Node *delete_end(Node *head)
{
	if(head==NULL)
		return NULL;

	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node* curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}

	curr->prev->next=NULL;
	delete curr;

	return head;
}


// Reverse DLL
Node *reverseDLL(Node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node *temp=NULL,*curr=head;
	while(curr!=NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;

		curr=curr->prev;  //Now curr->prev is curr->next
	}

	return temp->prev;
}

int main()
{	Node *head =new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	
	head->next  = temp1;
	temp1->prev = head;
	temp1->next = temp2;
	temp2->prev = temp1;
    
    printDLL(head);

//Insert at the beginning    
    head=insert_begin(head,100);
    printDLL(head);

//Insert at the end;
    head=insert_end(head,500);
    printDLL(head);

//Insert at x=2 any position
   int x=2;
   head=insert_at(head,x,1000);
   printDLL(head);

//delete from the begin
  head=delete_begin(head);
  printDLL(head);

//delete from the end
  head=delete_end(head);
  printDLL(head);

//delete x= from the DLL 


//Reverse DLL
  head=reverseDLL(head);
  printDLL(head);

	return 0;
}
