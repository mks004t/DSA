#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{  int no;
	cout<<"Enter a no";
	cin>>no;
	
	
	if(no%2==0 && no>0)
		{
			cout<<"The No is even ";

		}
	else if (no%2!=0 && no>0)
		cout<<"The no is odd ";
	else
		cout<<"the input is wrong";


	return 0;
}