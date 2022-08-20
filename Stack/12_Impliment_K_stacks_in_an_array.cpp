#include <bits/stdc++.h>
using namespace std;

// it is like array implimentation of Linked list

// sn: stack no =>( 0 to k-1)
// arr[] : is the array of size k
// next[]: it stores the index of next element  
// top[] : it stores the top element of every stack

struct kStacks{

	int *arr, *top, *next;
	int k, freeTop, cap;

	kStacks(int k1,int n)
	{
		k=k1;
		cap=n;
		arr= new int[cap];
		next= new int[cap];
		top= new int[cap];

		for(int i=0;i<k;i++)
		{
			top[i]=-1;  // no element in stacks
		}

		for(int i=0; i<cap-1; i++)
		{
			next[i]=i+1;
		} 
		next[cap-1]=-1;

		freeTop=0;  //next free top
 	}

// it shows that the array is full or not
 bool isFull() { return (freeTop==-1);}

// it shows that the array is empty
 bool isEmpty(int sn) {return (top[sn]==-1);}

// the order of the push code is important 
 	void push(int x,int sn)
 	{
 		if(isFull()) // overflow
 		{
 			cout<<"Stack is Full"<<endl;
 			return;
 		}

 		int i=freeTop;
 		freeTop=next[i];
 		next[i]=top[sn];
 		top[sn]=i;
 		arr[i]=x;
 	}
// the order of pop code is just reverse of push code
 	int pop(int sn)
 	{
 		if(isEmpty(sn)){
 			cout<<"stack is empty"<<endl;
 			return INT_MAX;
 		}

 		int i=top[sn];
 		top[sn]=next[i];
 		next[i]=freeTop;
 		freeTop=i;

 		return arr[i];
 	}

};

int main() 
{ 
    int k = 3, n = 10; 
    kStacks ks(k, n); 
  
    ks.push(15, 2); 
    ks.push(45, 2); 
   
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
   
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
}