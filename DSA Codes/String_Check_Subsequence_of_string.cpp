#include<bits/stdc++.h>
using namespace std;

//Check is a String is a Subsequence of other
// if yes return 1 else 0; 

// O(n+m) time complexity

bool SS(string &str1,string &str2,int n,int m)
{
	
	int j=0;

	for(int i=0; i<n &&j<m; i++)   //importent
	{
		if(str1[i]==str2[j])
			j++;
	}

	if(j==m)
		return 1;

  return 0;
}

//Recursive
bool SSrec(string s1,string s2,int n,int m)
{
	if(m==0) return true;
	if(n==0) return false;
	if(s1[n-1]==s2[m-1])
		return SSrec(s1,s2,n-1,m-1);
	else
		return SSrec(s1,s2,n-1,m);
}

int main()
{
	string str1,str2;
	getline(cin,str1);
    getline(cin,str2);
    int n=str1.length();      //this function give(length+1)
    int m=str2.length();
    //cout<<SS(str1,str2,n,m);
    cout<<SSrec(str1,str2,n,m);
	return 0;
}

/*  Input
  "ABCDEF"
  "ADF"
  1           //OUTPUT
*/