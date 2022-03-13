#include <bits/stdc++.h>
using namespace std;
// Function to print all sub strings
vector<int> subString(vector<int> v, int n,int pos)
{  vector<int>res;
    int count =1;
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            
            //  Print characters from current
            // starting point to current ending
            // point. 
             count++;
            int j = i + len - 1;           
            for (int k = i; k <= j; k++)
                {  
                 if(count==pos)
                   { //cout << v[k];
                     res.push_back(v[k]);
                   }
                    
                }
               // cout<<endl;
        }
    }
    
    return res;
}
 
// Driver program to test above function
int main()
{   unordered_map<int,string> mp;
   int vvv;
   cin>>vvv;
    
    int pos;
    cin>>pos;
 
   string str ;
    cin>>str;
    int n=str.length();
   
    int c=0;
    int start=0;
    for(int i=0; i<n; i++)
    { 
        if(str[i]==',')
         {  
             //cout<<start<<" "<<i<<endl;
           string rx = str.substr(start,i-start);
           mp[c]=rx;
           
           start=i+1;
           c++;
         }
        
    }
    //cout<<start<<" "<<n<<endl;
    mp[c]=str.substr(start,n);
    
 /*   for(int i=0;i<mp.size();i++)
    {
        cout<<mp[i]<<" "<<i<<endl;
    }*/
    
    vector<int> v;
    for(int i=0;i<=c;i++)
    {
        v.push_back(i);
    }
    vector<int> r;
    r=subString(v,v.size(),pos);
    //cout<<r.size()<<endl;
     int mmm=r.size();
    if(pos==1)
       cout<<"";
   if(r.size()==1)
    {
        cout<<mp[r[0]];

    }
    else
    {   string zz;
        for(int i=0;i<r.size();i++)
        {    
            if(i<r.size()-1)
              { zz=zz+mp[r[i]];
                 zz=zz+","; 
                  
              }
            else
             zz=zz+mp[r[i]];
        }
        cout<<zz;
    }
    
    
    return 0;
}