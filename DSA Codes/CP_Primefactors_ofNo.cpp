#include <bits/stdc++.h>

using namespace std;
// the Net Time complexity of this algo is O(N*N log N)

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

void primeFactor(int n)
{ cout<<"Prime factors of the given no are : ";
	for(int i=2;i<=n;i++)        //O(N)
	{
		if(isPrime(i))           //O(N)
		{  int x=i;
			while(n%x==0)        //O(log N)
			{
				cout<<i<<" ";
				x=x*i;              
			}
		}
	}
}

int main()
{ int num;
	cin>>num;
	primeFactor(num);
   return 0;
}