#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli getMask(string s)
{
	lli mask=0;
	for(int i=0;i<s.size();i++)
	{	
		int bit =s[i]-'a';
		mask = mask| (1<< bit);
	}

	return mask;
}

vector<int>findNumOfValidWords(vector<string> &w, vector<string> &p)
{
	vector<int > ans;
	map<lli,lli> m;

	for(int i=0; i<w.size(); i++)
	{
		string word=w[i];
		lli mask=0;

		for(int j=0; j<word.size(); j++)
			mask = mask| getMask(w[i]);

		m[mask]++;
	}	

	for(int i=0; i<p.size(); i++)
	{
		string word=p[i];
		lli mask=getMask(word);

		lli first = 1<<(word[0]-'a');

		lli curr= mask;
		lli temp=0;

		while(curr > 0)
		{
			if(curr & first)
				temp+=m[curr];

			curr=(curr-1) & mask;
		}

		ans.push_back(temp);
	}

	return ans;
}


//_______________________________________________________________

void print_vector(vector<int> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}

main()
{
   vector<string> v = {"aaaa","asas","able","ability","actt","actor","access"};
   vector<string> v1 = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
   print_vector(findNumOfValidWords(v,v1));
}