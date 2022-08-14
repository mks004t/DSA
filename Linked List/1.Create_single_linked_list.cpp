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

// Print LL
void print(Node * head)
{
	Node* curr=head;

	while(curr!=NULL)
	{
		cout<<curr->data<<"->"<<" ";
		curr=curr->next;
	}
}

// Insert at the beginning 

Node* insert_at_begin(Node* head, int x )
{
   Node* temp =new Node(x);
   temp->next =head;

   return temp;
}

// Insert at the end of LL  O(N)
Node * insert_at_end(Node * head, int x)
{
	Node * temp =new Node(x);

	if(head==NULL)
    	return temp;

	Node * curr =head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=temp;
   
   return head;
}
// Insert at a given position
Node* insertPos(Node * head,int pos,int x)
{
	Node* temp =new Node(x);
	if(head==NULL)
		return temp;
	if(pos==1)
	{
		temp->next=head;
		return temp;
	}

	Node *curr =head;
	// start i=1 to <= (pos-2)
	for(int i=1 ; i<=pos-2 && curr!=NULL ;i++)
	{
		curr=curr->next;
	}
	if(curr==NULL)    // we are adding after out of bound
		 return head;

	//******* main code **********
   temp->next=curr->next;
   curr->next=temp;

   return head;
}


// Delete at the begin
Node * delete_begin(Node *head)
{
	if(head==NULL)
		return head;

	Node* temp= head->next;
	delete head;

	return temp;

} 

// Delete at the end
Node* delete_end(Node *head)
{
	if(head==NULL)
		return head;

	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	Node* curr= head;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
	}
	delete (curr->next);
	curr->next=NULL;

	return head;
}

//  Reverse a LinkList 
Node * reverseLL(Node* head)
{
	Node * prev = NULL;
   Node * curr=head;
  
   while(curr!=NULL)
   {
       Node * next =curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
   }
  
  return prev;
}

// reversea a LinkList recursive;
Node* recRevLL(Node * head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Node* rest_head = recRevLL(head->next);
	
	//Node* rest_tail = head->next;
	//      rest->next = head;
	//          or 
	     head->next->next=head;
	     
	      head->next=NULL;
	      return rest_head;
}

int main()
{
	Node *head = new Node(10);
	Node *temp1 =new Node(20);
	Node *temp2 = new Node(30);

	head->next = temp1;
	temp1->next = temp2;
    
	print(head);
	cout<<endl;

    head=insert_at_begin(head,50);
    print(head);
    cout<<endl;

    head=insert_at_end(head,60);
    print(head);
    cout<<endl;

    head=insertPos(head,2,800);
    print(head);
    cout<<endl;

    head= delete_begin(head);
    print(head);
    cout<<endl;

    head= delete_end(head);
    print(head);
    cout<<endl;

    head= reverseLL(head);
    print(head);
    cout<<endl;
                                                                                                                          
    head= recRevLL(head);
    print(head);
    cout<<endl;


	return 0;
}