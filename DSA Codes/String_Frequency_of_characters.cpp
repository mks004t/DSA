#include<bits/stdc++.h>
using namespace std;
// Print Frequency of character (in Stored Order)
// in a string of lower case alphabets.
int main()
{
	string str="geeksforgeeks";
	int count[26]={0};
	
	for(int i=0; i<str.length(); i++)
		count[str[i]-'a']++;

	for(int i=0; i<26; i++)
		if(count[i] > 0)
			cout<<(char)(i+'a')<<" "<<count[i]<<endl;

return 0;
}