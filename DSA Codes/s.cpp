#include <iostream>
using namespace std;

int lcs(string s1,string s2, int m,int n)
{
int cost=0;	
int i=0;
int j=0;
while(i<=m-1)
{
  
   if(s2[j]!=s1[i])
     { 
        j=0;
     }
    else
    {   if(j==n-1)
        {
          cost+=i-n+2;
        }
           
        j++;
    }
    i++;
}
return cost;
}
int main() {
 string s1="hallohallohallo";
 string s2="allo";
 int m=s1.size();
 int n=s2.size();
	cout<<lcs(s1,s2,m,n);
	return 0;
}
