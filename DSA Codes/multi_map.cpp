#include <bits/stdc++.h>

using namespace std;

// most of the function have O(log N) complexity bec it is a red black tree and also a self balancing tree 

multimap<int,string> m;

void add(int p,string s)
{
	m.insert({p,s});  // insert key value pair
}

void find(int p)
{
	auto it =m.equal_range(p);   // give two iterator 1st is  that given no and second is just greater no 
	for(auto itt =it.first; itt!=it.second; itt++)
	{
		cout<<itt->second<<" "<<itt->first<<" "<<endl;  // print map keys and value
	}
}

void printSort()
{
	for(auto x:m)
		cout<<x.second<<" "<<x.first<<endl;
}

void printGreater(int p)
{
	auto it=m.upper_bound(p);  //uperbound give iterator to the just greater nothen given no 
	while(it!=m.end())
	{
		cout<<it->second<<" "<<it->first<<endl; 
		it++;
	}
}

void printSmaller(int p)
{
	auto it =m.lower_bound(p);
	for(auto it1 =m.begin(); it1!=it; it1++)
	{
		cout<<it1->second<<" "<<it1->first<<endl;
	}
}


int main()
{ add(10,"abc");
  add(20,"bcd");
  add(5,"cde");
  add(10,"efg");.
  add(20,"ghi");
  cout<<"------------------"<<endl;
  printSort();
  cout<<"----------------"<<endl;
  printSmaller(20);
  cout<<"----------------"<<endl;
  printGreater(10);
  cout<<"----------------"<<endl;
  find(20);



	return 0;
}