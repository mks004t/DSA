#include<bits/stdc++.h>
using namespace std;

//Time comp =O(n) and space comp =O(n),  T(n)=T(n-2)+O(1)


bool isPalindrome(string & s,int start,int end)
{  
  if(start>=end)
  	return 1;
  return (s[start]==s[end])&& isPalindrome(s,start+1,end-1);

}

int main()
{
	string s;
	cin>>s;
	int end=s.length();
	int start=0;
	cout<<isPalindrome(s,start,end-1);
	
}