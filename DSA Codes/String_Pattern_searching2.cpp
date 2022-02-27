#include<bits/stdc++.h>
using namespace std;
bool PatternMatch(string s1,string s2)
{
	int n=s1.length();
	int m=s2.length();

	int i=0,j=0;
	while(i<m)
	{
		if(j==n) return true;
		while(i<n)
		{
			if(s1[j]==s2[i])
			{
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}
	}

	return false;

}

int main()
{ string s1="AXY";
  string s2="ADXCPY";

  cout<<PatternMatch(s1,s2);
	return 0;
}