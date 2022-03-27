#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int n)
{
    if(n==1)
    {
        return {"0", "1"};
    }
    
    vector<string> recAns=solve(n-1);
    vector<string> ANS;
    
    for(int i=0;i<recAns.size();i++)
    {
        string s=recAns[i];
        ANS.push_back("0"+s);
    }
    
     for(int i=recAns.size()-1; i>=0; i--)
    {
        string s=recAns[i];
        ANS.push_back("1"+s);
    }
    
    return ANS;
}

void generateGray(int n)
{
    vector<string> arr;
    arr=solve(n);
    
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main() {
	int n=3;
	generateGray(n);
	
	return 0;
}
