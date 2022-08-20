#include <bits/stdc++.h>
using namespace std;

// time comp: O(1)

// Struct of LinkedList
struct Node{
	int data;
	Node *next;
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

struct myStack{
	Node *head;
	int sz;   // sz is the size of Stack 

	myStack()
	{
		head =NULL;
		sz=0;
	}

	void push(int x)
	{
		Node *temp =new Node(x);
		temp->next=head;
		head=temp;
		sz++;
	}
	int pop()
	{
		if(head==NULL)    // stact is empty
			return INT_MAX;

		int res =head->data;
		Node *temp =head;
		head=head->next;

		delete(temp);
		sz--;

		return res;
	}

	int size()
	{
		return sz;
	}

	int peek()
	{
		if(head==NULL)
			return INT_MAX;

		return head->data;
	}
	bool isEmpty()
	{
		return (sz==0);
	}

};


int main()
{
	myStack s;
	s.push(5);
	s.push(15);
	s.push(20);
	cout<<s.size()<<endl;
	cout<<s.peek()<<endl;
	cout<<s.pop()<<endl;
	s.push(35);
	cout<<s.peek()<<endl;
	cout<<s.isEmpty()<<endl;

return 0;
}