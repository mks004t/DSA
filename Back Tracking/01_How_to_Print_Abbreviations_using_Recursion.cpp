#include<bits/stdc++.h>
using namespace std;

void abbreviation(string s,string ans,int count, int pos)
{
	if(pos==s.length())  // Base case
	{
		       // if count == 0
		if(count == 0)
			cout<<ans;

		else       // if  count > 0
           cout<<ans+to_string(count);

      cout<<endl;
       return;
	}

// if char included -> 2 condition  
	if(count>0)
		abbreviation(s,ans+to_string(count)+s[pos],0,pos+1);
	else
		abbreviation(s,ans+s[pos],0,pos+1);

// if char non included  ->1 condition

	abbreviation(s,ans,count+1,pos+1);
}

int main()
{
	string str="PEP";
    abbreviation(str,"",0,0);
	return 0;
}
