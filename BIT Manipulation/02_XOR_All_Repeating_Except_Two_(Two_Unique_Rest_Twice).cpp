#include <bits/stdc++.h>
using namespace std;

void twoUnique(int arr[],int n)
{ 
	int XxorY=0;  //(X^Y)
	
	for(int i=0; i<n; i++)
	{	
		XxorY = XxorY ^ arr[i];	
	}

	int rsb = XxorY &(-XxorY);  //Right most set bit mast of x^y

	int X=0;  // no
	int Y=0;  // no

	for(int i=0; i<n; i++)
	{
		if((arr[i] & rsb) == 0)   // different
		{
			X = X^ arr[i];
		}

		else  //(if(arr[i] & rsb)==rsb)  //same
		{
			Y = Y ^arr[i];
		}
	}
   
   if(X<Y)
	cout<<X<<" "<<Y;
   else
   	cout<<Y<<" "<<X;
}

int main()
{
	int arr[]={12, 1, 12, 3, 1, 2, 3, 5} ;
	int n=sizeof(arr)/sizeof(arr[0]);
	twoUnique(arr,n);
	return 0;
}