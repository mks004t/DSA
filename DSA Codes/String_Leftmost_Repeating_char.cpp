#include<bits/stdc++.h>
using namespace std;

//print the index of "Left most Repeting character" if not -1
//O(N)
const int CHAR = 256;
int LRepeating(string & str)
{
	bool visited[CHAR];
	for(int i=0; i<CHAR;i++)
		visited[i]=false;

	int res=-1;
	for(int i=str.length(); i>=0 ;i--) //Reverse loop
	{
		if(visited[str[i]]==true)      // if visited res = latest value
			res = i;
		else
			visited[str[i]]=true;

	}

	return res;
}


int main()
{
	string str;
	getline(cin,str);

    cout<<LRepeating(str);
	return 0;
}