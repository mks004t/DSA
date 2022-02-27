#include <bits/stdc++.h>
//O(root N)
using namespace std;
void Factor(int n)
{ 
	int i;
	for(i=1;i*i<n;i++)
	{
		if(n%i==0)
			cout<<i<<" ";
	}
    for( ; i>=1;i--)     // here we dont initilize i so i have the value where the previous loop stop
    {
    	if(n%i==0)
    		cout<<n/i<<" ";
    }

}



int main()
{ int num;
	cin>>num;
	Factor(num);
   return 0;
}