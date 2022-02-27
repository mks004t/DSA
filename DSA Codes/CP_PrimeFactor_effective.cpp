#include <bits/stdc++.h>

using namespace std;

//O(root(N)) when N is prime  else it is lessor 
void primeFactor(int n)
{
	if(n<=1)
		cout<<"Not a valid input";
	cout<<"The Prime Factors are : ";
	
	while(n%2==0)
	{  cout<<2<<" ";
       n=n/2;  
     }
     
     while(n%3==0)
     {
     	cout<<3<<" ";
     	n=n/3;
     }
    
     for(int i=5;i*i<=n;i+6)
     {
     	while(n/i==0)
     	{
     			cout<<i<<" ";
     			n=n/i;
     	}
         while(n/(i+2)==0)
         {
         	cout<<i+2<<" ";
         	n=n/(i+2);
         }
     }
   // n>3 print the largest prime explisitly for corner cases
     if(n>3)
     	cout<<n;
}


int main()
{ int num;
	cin>>num;
	primeFactor(num);
   return 0;
}