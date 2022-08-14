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

// Nive Method  O(N) but need 2 traverseal;
/*   step1 : traverse the while linklist and store the last pointer.
     step2 : traverse the LL and put all the odd in last 
  
   Input: 10-> 21-> 30-> 41-> 50-> 61-> 70-> 81-> 90->
  OutPut: 10-> 30-> 50-> 70-> 90-> 21-> 41-> 61-> 81->
*/

Node* segrigate(Node *head)
{
   Node *eS=NULL,*eE=NULL,*oS=NULL,*oE=NULL;
   for( Node *curr=head; curr!=NULL; curr=curr->next)
   {
   	int x= curr->data;
   	if(x%2==0)
   	{
   		if(eS==NULL)
   		{
   		   eS=curr;
   		   eE=eS;
   		}
   		else
   		{
   		   eE->next=curr;  //append
   		   eE=eE->next;    // move next;
   		}
   	}
   	else
   	{
   		if(oS==NULL)
   		{
   			oS=curr;
   			oE=oS;
   		}
   		else
   		{
   			oE->next=curr;
   			oE=oE->next;
   		}

   	}
   }

   if(oS==NULL ||eS==NULL)
   	return head;
  
   eE->next=oS;
   oE->next=NULL;
   
   return eS;

}