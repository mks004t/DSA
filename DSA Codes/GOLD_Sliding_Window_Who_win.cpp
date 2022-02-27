#include<bits/stdc++.h>
using namespace std;


string res(string color)
{ string s1="wendy";
  string s2="bob";
	int wcount=0;
	int bcount=0;

	for(int i=0; i<=color.length()-2; i++)
	{int bb=0;int ww=0;
		for(int j=i; j<i+3; j++)
		{ if(color[j]=='w')
			ww++;
		  else
			bb++;
	    }
	if(ww==3)
		wcount++;
	if(bb==3)
		bcount++;
	}
	
	if(wcount>=bcount+1)
	 return s1;
	else
	 return s2; 
}

int main()
{
	string color;
	getline(cin,color);

	string result =res(color);
	cout<<result<<endl;
	return 0 ;
}