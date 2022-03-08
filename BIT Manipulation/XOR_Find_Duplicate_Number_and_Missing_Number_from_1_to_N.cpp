#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[],int n)
{
	int xxor=0;

	for(int i=0; i<n; i++)
		xxor = xxor ^ arr[i];

	for(int i=1; i<=n; i++)
		xxor = xxor ^ i;

	int rsb =xxor &(-xxor);

	int x=0;   //missing no
	int y=0;  // repeating no

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

	cout<<x<<" "<<y;
}

int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}