#include<bits/stdc++.h>
using namespace std;
int firstoccurrence(string s,char ch)
{ 
	for(int i=0; i<s.length(); i++)
		if(s[i]==ch)
			return i+1;

	return -1;
}

int main()
{  string s;
	char ch;
	cout<<"enter String "<<endl;
	getline(cin,s);
	cout<<"enter char"<<endl;
	cin>>ch;
	cout<<firstoccurrence(s,ch);
	return 0;
}

/*input and output
enter String
My name is manish
enter char
i
9
*/