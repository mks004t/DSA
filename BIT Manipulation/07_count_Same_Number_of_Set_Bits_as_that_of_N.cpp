#include <bits/stdc++.h>
using namespace std;

// this code works fine on online compiler
//       Question
//  find out the count of positive integers strictly less than N,
//   having same  number of set bits as that of N.
long csb(long n)  // Kernighan's Algo
{
	long res=0l;
	while(n>0)
	{	
		long rsb= n & (-n);
		n -= rsb;
		res++;
	}
	return res;
}

long ncr(long n, long r)
{  
 	if(n<r)
 	  return 0l;

	long res=1l;
	for(long i=0l; i<r; i++)
	{
		res=res*(n-i);
		res=res/(i+1);
	} 
	
	//cout<<res<<endl;
	return res;
}

long Count(long n,long k ,long i)
{
	if(i==0)
		return 0;

	long mask = 1l << i;
	long res=0;

	if((n & mask)==0)
	{
		res = Count(n,k,i-1);
	}
	else
	{
		long res1 = Count(n,k-1,i-1);
		long res0 = ncr(i,k);
		res = res1 + res0;
	}

return res;
}

int main()
{
	long  n = 12;
	long k = csb(n);
    cout<<Count(n,k,63);  // max bits in long is 63
  return 0;  
}

// for n = 12 
// output is 5