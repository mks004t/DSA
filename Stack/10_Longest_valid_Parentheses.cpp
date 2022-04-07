#include<bits/stdc++.h>
using namespace std;

// We have to find the max length valid parenthesis among the string

int maxLength(string S){
    stack<int>s;
    
    int ans=0;
    for(int i=0; i<S.length(); i++)
    {
        if(s.empty())
           s.push(i);
      
       else if(!s.empty() && S[i]==')' && S[s.top()]=='(')
       {
           s.pop();
           
           if(s.empty())
           ans=max(ans,i+1);
           
           else
           ans=max(ans,i-s.top());
       }
       
       else
         s.push(i);
    }
    
    return ans;
}

int main()
{
   string S=")()())";
   cout<<maxLength(S);

   return 0;
}