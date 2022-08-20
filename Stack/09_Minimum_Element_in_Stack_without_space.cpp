#include<bits/stdc++.h>
using namespace std;

stack<int >s;   // globle stack
int minEle;     // Minimum variable

void Push(int x)
{
  if( s.empty()==true)
  {
  	s.push(x);
  	minEle=x;
  }

  else if (minEle >= x)
  {
  	s.push(2*x-minEle);
  	minEle=x;
  }

  else
  {
  	s.push(x);
  }
}

void Pop()
{
   if(s.empty())
   	{
       cout<<"Stack is Empty "<<endl;
    }

   else if(s.top()<= minEle)
   {
   	 minEle=2*minEle-s.top();
   	 //cout<<minEle<<endl;
   	 s.pop();
   }

   else
   {
   	 //cout<<s.top()<<endl;
   	 s.pop();
   }

}

void Peek()
{
  if(s.empty())
     cout<<"-1";
 else
    { if(s.top()>minEle)
        cout<<s.top()<<endl;
    
      else
        cout<<minEle<<endl;
  }
}

void getMin()
{
   if(s.empty())
      cout<<"STACK IS EMPTY"<<endl;
 else
 {
  cout<<minEle<<endl;
 }
 
}

int main()
{
    Push(3);
    Push(5);
    getMin();
    Push(2);
    Push(1);
    getMin();
    Pop();
    getMin();
    Pop();
    Peek();
  
    return 0;
}

