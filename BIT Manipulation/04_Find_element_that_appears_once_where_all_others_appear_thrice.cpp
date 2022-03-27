#include <bits/stdc++.h>
using namespace std;

//Find element that appears once where all others appear thrice | One Unique Rest Thrice

int getSingle(int arr[],int n)
{
  int t3n=INT_MAX, t3n1=0, t3n2=0;  // 3n,3n+1,3n+2

  for(int i=0; i<n; i++)
  {
  	int C3n  = arr[i] & t3n;    //common with t3n
  	int C3n1 = arr[i] & t3n1;  //common with t3n1
  	int C3n2 = arr[i] & t3n2;  //common with t3n2

  	t3n  = t3n & (~C3n);      // off in t3n common in 3n
  	t3n1 = t3n1 | C3n;      //on in t3n+1 common in 3n+2

  	t3n1 = t3n1 & (~C3n1);  // off in t3n+1 common in 3n+1
  	t3n2 = t3n2 | C3n1;     //on in t3n+2 common in 3n+1

  	t3n2 = t3n2 & (~C3n2);  // off in t3n+2 common in 3n+2
  	t3n  = t3n | C3n2;       //on in t3n common in 3n+2
  
  }
  return t3n1;
}

// method 2

int getsingle( int arr[],int n)
{
    int O = 0;   // One
    int T = 0;   // Two

    for(int i=0; i<n; i++)
    {
      int oo = ( (~T) & O & (~arr[i]) ) | ( (~T) & (~O) & arr[i] );
      int tt = ( T & (~O) & (~arr[i]) ) | ( (~T) & O & arr[i] );

      O = oo;
      T = tt;
    }

    return O;
}

int main()
{
    int arr[] = { 3, 3, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< getSingle(arr, n)<<endl;
    cout<< getsingle(arr, n);
    return 0;
}