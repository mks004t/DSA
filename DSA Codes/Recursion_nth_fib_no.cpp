// this program will give the nth fibonacci no  

#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{  if (n==0)
	return 0;

	if(n==1)
	return 1;


return fib(n-1)+fib(n-2);


}

int main()
{  int n;
	cout<<"enter the posion whose fibonacci no you want to find  ";
	cin>>n;
	cout<<"fibonacci no is "<<endl;
	cout<<fib(n);
	return 0;

}