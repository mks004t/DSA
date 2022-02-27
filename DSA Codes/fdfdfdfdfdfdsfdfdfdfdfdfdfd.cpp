#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	while(1){
		cout<<"Input Binary String: ";
		string bin;cin>>bin;
		int n=bin.length();
		int f=0;
		for(int i=n-1;i>=0;i--){
			if(bin[i]=='0'&&f==0){
				f=1;
				bin[i]='1';
			}
			if(f==0)
				(bin[i]=='1')?(bin[i]='0'):(bin[i]='1');
		}
		if(f)
			cout<<"Binary Number after adding 1: "<<bin<<endl;
		else
			cout<<"Binary Number after adding 1: 1"<<bin<<endl;

	}
    return 0;
}
