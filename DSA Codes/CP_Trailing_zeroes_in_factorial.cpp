#include <bits/stdc++.h>

using namespace std;

int CoutntZero(int num)
{
	int Nzero=0;
	for(int i=5;i<num;i=i*5)
	{
		Nzero=Nzero+num/i;
	}
	return Nzero;   // it will return no of zeroes in factorial of any Number ;
}

int main()
{   int num;
    cout<<"Enter the No {No of zeroes in factorial of that zero }";
	cin>>num;
	cout<<CoutntZero(num);


	return 0;
}  