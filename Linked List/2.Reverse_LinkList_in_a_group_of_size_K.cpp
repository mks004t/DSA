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

Node *reverse (Node *head, int k)
{ 
    Node *curr = head;
    Node *prevFirst = NULL;
    
    bool firstPass =true;
    
    while(curr!=NULL)
    {  
        Node *first = curr, *prev = NULL;
        int count=0;
        
        while(curr!=NULL && count< k)
        {
            Node* next =curr->next;
            curr->next =prev;
            prev=curr;
            
            curr=next;

            count++;
        }

        if(firstPass == true)
        {
            head = prev;
            firstPass=false;
        }
        else
        {
            prevFirst->next = prev;         
        }

        prevFirst = first;
    }
    
    return head;
}

