#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int t;
	int result =0;
	cin>>t;
	while(t--)
	{ 
	    int n;
	    cin>>n;
	    int arr[n];
	    vector<int>O;
	    vector<int>E;
	    int OO=0;
	    int EE=0;
	    for(int i=0;i<n;i++ )
	   { int temp;
	     cin>> temp;
	     if(temp/2==0)
	        { E.push_back(temp);
	        EE++;
	        }
	     else
	        { O.push_back(temp);
	        OO++;
	        }
	   }
	   sort(O.begin(),O.end());
	   sort(E.begin(),E.end());
	  
	   if(OO==EE)
	   {
	       for(int i=0;i<n/2;i++)
	       cout<<O[i]<<" "<<E[i]<<" ";
	   }      
	       
	   else
	   cout<<(-1);
	   
	   
	   
	  cout<<endl;
	 
	  
	} 
	    
	
	return 0;
}

