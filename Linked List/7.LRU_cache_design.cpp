#include<bits/stdc++.h>
using namespace std;

// LRU:leaset resecently used
// miss: if some this you want to access is not in the cache
// hit : if some thing you wanted to access is in cache.


// doubly linked list with two variable
// key and data, key is uesed as a reference 
// it helps us finding any element in O(1).
class Node
{
    public:
	int key;
	int data;
	
	Node *next;
	Node *pre;
	Node (int k,int d)
	{
		key = k;
		data = d;
		next = NULL;
		pre = NULL;
	}
};

class LRUcache{
public:
unordered_map<int, Node*>map;
int capacity,count;
Node *head, *tail;

LRUcache(int c)
{
   capacity =c;
   head = new Node(0,0);
   tail = new Node(0,0);

   head->next=tail;
   tail->pre = head;

   head->pre=NULL;
   tail->next=NULL;

   count=0;
}

void addToHead(Node *node)
{
	node->next=head->next;
	node->next->pre=node;

	node->pre=head;
	head->next=node;
}

void deleteNode(Node *node)
{
	node->pre->next=node->next;
	node->next->pre=node->pre;
}

int get(int key)
{
	if(map[key]!=NULL)
	{
		Node *node =map[key];

		int result =node->data;
		deleteNode(node);  // delete the node from the given pposition.
		addToHead(node);   // and add to the front.

		return result;
	}

	return -1;  // the value is not present
}

void set(int key, int value)
{
	if(map[key]!=NULL)
	{
		Node *node =map[key];
		node->data=value;
		deleteNode(node);
		addToHead(node);
	}
	else
	{
		Node *node =new Node(key,value);
		map[key]=node;  // insert key & value in map
		
		if(count<capacity)
		{
			count++;
			addToHead(node);
		}
		else
		{
			map.erase(tail->pre->key); // delete element from map
			deleteNode(tail->pre);   // delete last node
			addToHead(node);

		}
	}
}

};

int main()
{
	LRUcache cache(2);
	cache.set(1,10);
	cache.set(2,20);
	cache.set(3,30);
	cout<<cache.get(2)<<endl;
	cache.set(4,40);
	cout<<cache.get(1)<<endl;
	cout<<cache.get(3)<<endl;
	cout<<cache.get(4)<<endl;

	return 0;
}

