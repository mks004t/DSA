#include<bits/stdc++.h>
using namespace std;

//Pattern Searching problem 
/*   txt : ABABABCD
     pat : ABAB
   OUTPUT: 0 2
*/

//O((N-M+1)*M)   
//Nive method
void pSearch1(string & txt, string & pat)
{
	int n=txt.length();
	int m=pat.length();
	for(int i=0; i<=n-m; i++)
	{
		int j;
		for(j=0; j<m; j++)
			if( pat[j] != txt[i+j] )
				break;
		if(j==m)
			cout<<i<<" ";
	}
}

//O(N)
//Improved Naiv Algo (when char are not repeated (only 1 answer))
void pSearch2(string & txt, string & pat)
{
	int n=txt.length();
	int m=pat.length();
	for(int i=0; i<=n-m;   )
	{
		int j;
		for(j=0; j<m; j++)
		{	if( pat[j] != txt[i+j] )
				break;
		}
		if(j==m)
			cout<<i<<" ";
		if(j==0)
			i++;
		else
			i=i+j;
	}
}

//

int main()
{
	string str1,str2;
	getline(cin,str1);
    getline(cin,str2);
    
    pSearch2(str1,str2);
	return 0;
}