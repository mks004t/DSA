#include<bits/stdc++.h>
using namespace std;
int largest_power_of2in_range(int num)
{
	int x=0;
	while((1 << x) <=num)
	{
		x++;
	}
	return x-1;           //return  2^x which is <= num
}

int count_Sum_bits1(int num)
{   if(num==0) return 0;     //Base case
	
	int x=largest_power_of2in_range(num);

	int bits_Till_2x = x*( 1<<(x-1));
	int msb_2x_to_n = num-( 1 << x )+1;
	int remain = num-(1<<x);
	int ans = bits_Till_2x + msb_2x_to_n + count_Sum_bits1(remain);
     
     return ans;
}

int main()
{
	int num;
	cin>>num;
	cout<<count_Sum_bits1(num);
	return 0;
}