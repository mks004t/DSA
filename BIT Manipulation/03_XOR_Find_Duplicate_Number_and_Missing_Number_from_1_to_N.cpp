#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[],int n)
{
	int xxor=0;

	for(int i=0; i<n; i++)   // XOR of all element of array
		xxor = xxor ^ arr[i];

	for(int i=1; i<=n; i++)  // XOR of prev and 1 to n
		xxor = xxor ^ i;

	int rsb =xxor &(-xxor);

	int x=0;   // no
	int y=0;  //  no

	for(int i=0; i<n; i++)
	{
		if((arr[i] & rsb) == 0)
			x=x^arr[i];
		else
			y=y^arr[i];
	}
	for(int i=1; i<=n; i++)
	{
		if((i & rsb) == 0)
			x=x^i;
		else
			y=y^i;
	}

	
	for(int i=0; i<n; i++)
	{
		if(arr[i]==x)
		{
			cout<<"Missing  No is  : "<<y<<endl;
			cout<<"Repeating No is : "<<x<<endl;
			break;
		}

		else if (arr[i]==y)
		{
			cout<<"Missing  No is  : "<<x<<endl;
			cout<<"Repeating No is : "<<y<<endl;
			break;
		}
	}
}

int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}