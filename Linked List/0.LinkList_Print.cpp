#include<bits/stdc++.h>
#include"6.Palindrome_LinkedList.cpp"
using namespace std;


// Print LL
void print(Node *head)
{
	Node* curr=head;

	while(curr!=NULL)
	{
		cout<<curr->data<<"->"<<" ";
		curr=curr->next;
	}
}

int main()
{
	Node *head = new Node(10);
	Node *temp1 =new Node(20);
	Node *temp2 =new Node(30);
	Node *temp3 =new Node(40);
	Node *temp4 =new Node(50);
	Node *temp5 =new Node(60);
	Node *temp6 =new Node(70);
	Node *temp7 =new Node(80);
	Node *temp8 =new Node(90);

	head->next = temp1;
	temp1->next = temp2;
	temp2->next = temp3;
	temp3->next = temp4;
	temp4->next = temp5;
	temp5->next = temp6;
	temp6->next = temp7;
	temp7->next = temp8;

    print(head);
	cout<<endl;

// Segregate even and odd LinkedList.
   
  // head=segrigate(head);
// Reverse_LinkList_in_a_group_of_size_K_
    //head=reverse(head,7);  // K = 3;   

// Rotate Linklist
//	head =rotateLL(head,6);	

// Pairwise Swap	
//	head= pairWiseSwap(head);
	
// isPalindrome
	cout<<isPalindrome(head)<<endl;

	print(head);
	cout<<endl;
    
	return 0;
}