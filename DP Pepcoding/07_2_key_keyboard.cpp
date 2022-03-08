#include<bits/stdc++.h>
using namespace std;

int solve (int n)
{
    int ans=0;
    
    for(int i=2; i*i<n;   )
    {
        if(n%i==0)
        {
            ans+=i;
            n/=i;
        }
        
        else
         {   i++;    }
    }
    
    if(n!=1)
       ans+=n;
    
    return ans;
}

int main() {
	int n=18;
	cout<<solve(n);
	return 0;
}