#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool isPalindrome(string ss,int s,int e)
  {
      while(e>=s)
      {
          if(ss[s]!=ss[e])
           return false;
           
           s++;
           e--;
      }
      
      return true;
  }
   void solve(string s,int index, vector<string>& sTill, vector<vector<string>>& res)
   {
       if(index==s.size())
       {
           res.push_back(sTill);
           return;
       }
       
       for(int i=index;i<s.size();i++)
       {
           if(isPalindrome(s,index,i))
           {   
               string prefix=s.substr(index,i-index+1);   //prifix i.e palindrome
               sTill.push_back(prefix);  
               
               solve(s,i+1,sTill,res);                    
              
               sTill.pop_back();           // back Track
           }
       }
   }
   
 vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> res;
        vector<string> sTill;
        solve(S,0,sTill,res);
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  