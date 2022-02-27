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


void printCLL(Node *head)
{
	if(head==NULL)
		return;
	Node *p=head;
	

	do{              //we have to print at least one node
		cout<<(p->data)<<" ";
		p=p->next;
	  
	  } while(p!=head);

	cout<<endl;
}

//Insert at the Begin O(1)
Node *insert_begin(Node *head,int data)
{
	Node *temp= new Node(data);
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}

//first we create a Node at the 2nd place.

	temp->next=head->next;
	head->next=temp;

// then swap the value with head.
	int t=head->data;
	head->data=temp->data;
	temp->data=t;

  return head;
}

Node *insert_end(Node *head,int data)
{
	Node *temp= new Node(data);
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}

//first we create a Node at the 2nd place.

	temp->next=head->next;
	head->next=temp;

// then swap the value with head.
	int t=head->data;
	head->data=temp->data;
	temp->data=t;
  
  return temp;
}

Node *delete_begin(Node *head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}

	Node *temp=head->next;
	head->data=head->next->data; //copy data of second in first
	head->next=head->next->next;
	delete temp;     //delete 2nd node
	
	return head;
}

//Delete Kth node from the beginning (K<=size of CLL)  
Node *delete_kth_node(Node *head,int k)
{
	if(head==NULL)
		return head;
	if(k==1)
		{
			delete head;
			return NULL;
		}
    
    Node *curr= head;
    for(int i=1;i<k-1;i++)
    {
    	curr=curr->next;
    }
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;

    return head;
}

int main()
{   Node *head=insert_end(NULL,10);
	head=insert_end(head,20);
	head=insert_end(head,30);
	head=insert_end(head,40);
	head=insert_end(head,50);
    printCLL(head);

    head=insert_begin(head,-100);
    printCLL(head);

    head=delete_begin(head);
    printCLL(head);

    //head=delete_end(head);
   // printCLL(head);

    head=delete_kth_node(head,4);  //delete 4th node
    printCLL(head);
	
	return 0;
}