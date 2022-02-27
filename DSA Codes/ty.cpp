/*
write a Program to calculate the min Number added to the  given  Number so that all the digits equal to "d" will be remove
i.e
let No is 100 and d=0
so the new no is 111
and min no added to given no is 11

eg 2 
given no= 434356 d=3
new no is 440000
min no added to given no will be 5644 



*/
#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int n,int d)
{ int New= n;
	int count=0,ans=0;
	int rem;

	while(New>0)
	{ rem=New%10;
	  New=New/10;
	  count++;
	  if(rem==d)
	  {
	  	New=New*pow(10,count)+(rem+1)*pow(10,count-1);
	  	ans=New-n;
	  	count=0;
	  }
		
	}
	return ans;
}

int main()
{ int t;
	cin>>t;
	while(t--)
	{  int n,d;
		cin>>n>>d;
		cout<<getMinDiff(n,d)<<endl;
		
	}
	return 0;
}