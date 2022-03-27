#include <bits/stdc++.h>
using namespace std;
/*
1. You are given a word.
2. You have to generate all abbrevations of that word.
Note - Use bit manipulation
*/

void abbreviation(string str)
{   
	int n=str.length();
	

	for(int i=0; i<(1<<n); i++)
	{
		string s="";
		int count = 0;

		for(int j=0; j<n; j++)
		{
			char ch =str[j];
			int bit = n-1-j;
 
			if( (i & (1<<bit))==0)  // Ith bit is off 
			{  
				if(count==0)
 				   s+=(ch);
 				else
 				{
 					s+=(to_string(count));
				    s+=(ch);
				    count=0;
 				}
			}
			else     // ith bit is off
			{	
				count++;
			}	
		}
		if(count>0)
			s+=(to_string(count));

		cout<<s<<endl;
	}
}

int main()
{
	string s = "pep";
	abbreviation(s);

	return 0;
}

/*
Output

pep
pe1
p1p
p2
1ep
1e1
2p
3

*/